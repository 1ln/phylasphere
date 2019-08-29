#version 330
uniform vec2 u_resolution; 
uniform float u_time;
uniform vec3 u_cam_position;
uniform float u_random;

float r2 = u_time;

float rand(vec2 st) {
return fract(sin(dot(st.xy,vec2(12.9898,78.233))) * 43758.5453123);
} 

float noise(in vec2 st_) {

vec2 i = floor(st_);
vec2 f = fract(st_);

float a = rand(i);
float b = rand(i + vec2(1.0,0.0));
float c = rand(i + vec2(0.0,1.0));
float d = rand(i + vec2(1.0,1.0));

vec2 u = f * f * (3.0 - 2.0 * f);

return mix(a,b,u.x) + 
          (c - a) * u.y * (1.0 - u.x) +
          (d - b) * u.x * u.y;
}

float fbm(in vec2 st_) {

float value = 0.0; 
float amp = 0.5;
//vec2 shift = vec2(100.0);

//mat2 rot = mat2(cos(0.5),sin(0.5),-sin(0.5),cos(0.5);

for(int i = 0; i < 6; ++i) {
value += amp * noise(st_);
st_ *= 2.0; 
//st_ = rot * st_ * 2.0 + shift;
amp *= 0.5;

}
return value;
}

//2d Shaping Functions
 
//3d Signed Distance Functions

float sphereSDF(vec3 p) {
return length(p)- 150.0*fbm(gl_FragCoord.xy/u_resolution)*u_random;
}

float boxSDF(vec3 p) {
vec3 d = abs(p) - 1.0;
return length(max(d,0.0));
}

//Raymarching

float map(vec3 p) {
return sphereSDF(p);
//return boxSDF(p);
}

float ray_march(vec3 cam_ray,vec3 marching_direction,float start,float end) {

float depth = start;

for(int i = 0; i <= 64; i++) {
 
float distance_field =  map(cam_ray + depth * marching_direction);
 
    if(distance_field < 0.01) {
    return depth;
    }
    depth += distance_field;
    if(depth >= end) {
    return end;
    }
}
return end;
}

vec3 rayDirection(float fov,vec2 size,vec2 fragCoord) {

vec2 xy = fragCoord - size / 2.0;
float z = size.y / tan(radians(fov)) / 2.0; 

return normalize(vec3(xy,-z)); 
}

vec3 calcNormal(vec3 p) {
return normalize(vec3(
       map(vec3(p.x + 0.001,p.y,p.z)) - map(vec3(p.x - 0.001,p.y,p.z)),
       map(vec3(p.x,p.y + 0.001,p.z)) - map(vec3(p.x,p.y - 0.001,p.z)),
       map(vec3(p.x,p.y,p.z + 0.001)) - map(vec3(p.x,p.y,p.z - 0.001))
));
}     

float softLight(in vec3 origin,in vec3 direction,float mint,float maxt,float k) {

float res = 1.0;
    for(float t = mint; t < maxt;) {
        float h = map(origin + direction * t);
         
            if(h < 0.001) {
            return 0.0;
            }
        
        res = min(res,k*h/t);
        t += h;
}
return res;
}

vec3 phongModel(vec3 kd,vec3 ks,float alpha,vec3 p,vec3 cam_ray,vec3 light_pos,vec3 intensity) {  

vec3 n = calcNormal(p);
vec3 l = normalize(light_pos - p);
vec3 v = normalize(cam_ray - p);
vec3 r = normalize(reflect(-l,n));

float ln = dot(l,n);
float rv = dot(r,v);

if(ln < 0.0) {
return vec3(0.0);
}

if(rv < 0.0) {
return intensity * (kd * ln);
}
return intensity * (kd * ln + ks * pow(rv,alpha));
}

vec3 phongLight(vec3 ka,vec3 kd,vec3 ks,float alpha,vec3 p,vec3 cam_ray) {

const vec3 ambient_light = 0.5  * vec3(1.0,1.0,1.0);
vec3 color = ka * ambient_light;  

vec3 light = vec3(100,100,100);
vec3 intensity = vec3(0.4,0.4,0.4);

color += phongModel(kd,ks,alpha,p,cam_ray,light,intensity); 
return color;

}

void main() {

vec2 uv = gl_FragCoord.xy / u_resolution;
float r = rand(uv);

vec3 dir = rayDirection(45,u_resolution.xy,gl_FragCoord.xy);
vec3 cam_ray = vec3(0.0,0.0,75.0);

//vec3 cam_ray = u_cam_position;

float dist = ray_march(cam_ray,dir,0.0,100.0);
  
   if(dist > 100.0 - 0.01) {
   gl_FragColor = vec4(0.0,1.0,0.0,1.0);
   return; 
  
   }
   
   float sl = softLight(cam_ray,dir,0.0,10.0,8);
   float r2 = fbm(uv );

   vec3 p = vec3(cam_ray + dist * dir);
   vec3 ka = vec3(0.2,0.2,0.2);
   vec3 kd = vec3(0.5,0.0,0.0);
   vec3 ks = vec3(1.0,1.0,1.0);
   float shininess = 10.0; 

   vec3 color = phongLight(ka,kd,ks,shininess,p,cam_ray);

   gl_FragColor = vec4(color,1.0);
   //gl_FragColor = sl;

}
