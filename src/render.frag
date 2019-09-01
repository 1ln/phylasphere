#version 330
uniform vec2 u_resolution; 
uniform float u_time;
uniform vec3 u_cam_position;
uniform float u_random;

uniform vec3 u_cam_lookat;


const float PHI = 1.618033988749894; 

float phiHash(float h) {
return fract(PHI * h);
}

float rand2d(vec2 st) {
return fract(sin(dot(st.xy,vec2(12.9898,78.233))) * 43758.5453);
}

float rand3d(vec3 st) {
return fract(sin(dot(st.xyz,vec3(12.9898,78.233,144.7272))) * 43758.5453); 
}

float noise2d(in vec2 st_) {

vec2 i = floor(st_);
vec2 f = fract(st_);

float a = rand2d(i);
float b = rand2d(i + vec2(1.0,0.0));
float c = rand2d(i + vec2(0.0,1.0));
float d = rand2d(i + vec2(1.0,1.0));

vec2 u = f * f * (3.0 - 2.0 * f);

return mix(a,b,u.x) + 
          (c - a) * u.y * (1.0 - u.x) +
          (d - b) * u.x * u.y;
}

float fb2d(in vec2 st_) {

float value = 0.0; 
float amp = 0.5;
//vec2 shift = vec2(100.0);

//mat2 rot = mat2(cos(0.5),sin(0.5),-sin(0.5),cos(0.5);

for(int i = 0; i < 3; ++i) {
value += amp * noise2d(st_);
st_ *= 2.0; 
//st_ = rot * st_ * 2.0 + shift;
amp *= 0.5;

}
return value;
}

//3d Interpolated Noise
float interpolate(in float a,in float b,in float x) {
return a + smoothstep(0.0,1.0,x) * (b-a);
}

float interpolateRand3d(in float x,in float y,in float z) {

float int_x = x - fract(x);
float fract_x =  x - int_x;
 
float int_y = y - fract(x);
float fract_y = y - int_y;

float int_z = z - fract(z);
float fract_z = z - int_z;

float v1 = rand3d(vec3(int_x,int_y,int_z));
float v2 = rand3d(vec3(int_x + 1.0,int_y,int_z));
float v3 = rand3d(vec3(int_x,int_y + 1.0,int_z));
float v4 = rand3d(vec3(int_x + 1.0,int_y + 1.0,int_z));
float v5 = rand3d(vec3(int_x,int_y,int_z + 1.0));
float v6 = rand3d(vec3(int_x + 1.0,int_y,int_z + 1.0));
float v7 = rand3d(vec3(int_x,int_y + 1.0,int_z + 1.0));
float v8 = rand3d(vec3(int_x + 1.0,int_y + 1.0,int_z + 1.0));

float i1 = interpolate(v1,v5,fract_z);
float i2 = interpolate(v2,v6,fract_z);
float i3 = interpolate(v3,v7,fract_z);
float i4 = interpolate(v4,v8,fract_z);

float ii1 = interpolate(i1,i2,fract_x);
float ii2 = interpolate(i3,i4,fract_x);

return interpolate(ii1,ii2,fract_y);
}

float noiseLerp3d(in vec3 p,in float wavelength) {
return interpolateRand3d(p.x/wavelength,p.y/wavelength,p.z/wavelength);
}

float simplexNoise3d(vec3 p) {

float f3 = 1.0/3.0;
float s = (p.x+p.y+p.z) * f3;

int i = int(floor(p.x + s);
int j = int(floor(p.y + s);
int k = int(floor(p.z + s);

float g3 = 1.0/6.0;
float t = float(i+j+k)) * g3;

float x0 = float(i) - t;
float y0 = float(j) - t;
float z0 = float(k) - t;

x0 = p.x - x0;
y0 = p.y - y0;
z0 = p.z - z0;

int i1,j1,k1,i2,j2,k2;

if(x0 >= y0) { 

    if(y0 >= z0) {
    i1 = 0;
    j1 = 0;
    k1 = 0;
    i2 = 1;
    j2 = 1;
    k2 = 0;
    
    } else if (x0 >= z0) {
    i1 = 1;
    j1 = 0;
    k1 = 0;
    i2 = 1;
    j2 = 0;
    k2 = 1;

    } else {
    i1 = 0;
    j1 = 0;
    k1 = 1;
    i2 = 1;
    j2 = 0;
    k2 = 1;

    }

    } else {

    if(y0 < z0) {
    i1 = 0;
    j1 = 0;
    k1 = 1;
    i2 = 0;
    j2 = 1;
    k2 = 1;
    
    } else if (x0 < z0) {
    i1 = 0;
    j1 = 1;
    k1 = 0;
    i2 = 0;
    j2 = 1;
    k2 = 1;

    } else {
    i1 = 0;
    j1 = 1;
    k1 = 0;
    i2 = 1;
    j2 = 1;
    k2 = 0;

    }

}

float x1 = x0 - float(i1) + g3;
float y1 = y0 - float(j1) + g3;
float z1 = z0 - float(k1) + g3;

float x2 = x0 - float(i2) + 2.0 * g3;
float y2 = y0 - float(j2) + 2.0 * g3;
float z2 = z0 - float(k2) + 2.0 * g3;

float x3 = x0 - 1.0 + 3.0 * g3;
float y3 = y0 - 1.0 + 3.0 * g3;
float z3 = z0 - 1.0 + 3.0 * g3;

vec3 ijk0 = vec3(i,j,k);
vec3 ijk1 = vec3(i + i1,j + j1,k + k1);
vec3 ijk2 = vec3(i + i2,j + j2,k + k2);
vec3 ijk3 = vec3(i + 1,j + 1,k + 1);

vec3 gr0 = normalize(vec3(rand3d(ijk0),rand3d(ijk0) * 2.01),rand3d(ijk0) * 2.01 ));
vec3 gr1 = normalize(vec3(rand3d(ijk1),rand3d(ijk1) * 2.01),rand3d(ijk1) * 2.01 ));
vec3 gr2 = normalize(vec3(rand3d(ijk2),rand3d(ijk2) * 2.01),rand3d(ijk2) * 2.01 ));
vec3 gr3 = normalize(vec3(rand3d(ijk3),rand3d(ijk3) * 2.01),rand3d(ijk3) * 2.01 ));


float n0 = 0.0;
float n1 = 0.0;
float n2 = 0.0;
float n3 = 0.0;

float t0 = 0.5 - x0*x0 - y0*y0 - z0*z0;
float t1 = 0.5 - x1*x1 - y1*y1 - z1*z1;
float t2 = 0.5 - x2*x2 - y2*y2 - z2*z2;
float t3 = 0.5 - x3*x3 - y3*y3 - z3*z3;

if(t0 >= 0.0) {
t0 *= t0;
n0 = t0 * t0 * dot(gr0,vec3(x0,y0,z0);
}

if(t1 >= 0.0) {
t1 *= t1;
n1 = t1 * t1 * dot(gr1,vec3(x1,y1,z1);
}

if(t2 >= 0.0) {
t2 *= t2;
n2 = t2 * t2 * dot(gr2,vec3(x2,y2,z2);
}

if(t3 >= 0.0) {
t3 *= t3;
n3 = n3 * n3 * dot(gr3,vec3(x3,y3,z3);
}

return 96.0 * (n0 + n1 + n2 + n3);
}

//2d Shaping Functions
 
//3d Signed Distance Functions

float sphereSDF(vec3 p,float r) {
return length(p) - r;
}

float boxSDF(vec3 p,float s) {
vec3 d = abs(p) - s;
return length(max(d,0.0));
}

//Raymarching

float map(vec3 p) {
//return sphereSDF(p,50+fb2d(vec2(p.x,p.y)) ) ;
return sphereSDF(p,10*noiseLerp3d(vec3(p.x,p.y,p.z),8)); 
//return boxSDF(p,10.0);
}

float ray_march(vec3 cam_ray,vec3 marching_direction,float start,float end) {
//float ray_march(float distance_field,float start,float end) { 

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

mat4 viewMatrix(vec3 cam_ray,vec3 center,vec3 up) {
    vec3 f = normalize(center - cam_ray);
    vec3 s = normalize(cross(f,up));
    vec3 u = cross(s,f);

    return mat4(
           vec4(s,0.0),
           vec4(u,0.0),
           vec4(-f,0.0),
           vec4(0.0,0.0,0.0,1.0)
    );
}

void main() {

vec2 uv = -1.0 + 2.0 *  (gl_FragCoord.xy / u_resolution.xy)    ;
float r2 = fb2d(uv);

vec3 dir = rayDirection(60,u_resolution.xy,gl_FragCoord.xy);
//vec3 cam_ray = vec3(0.0,0.0,75.0);
//vec3 cam_ray = vec3(-25.0,-50.0,-25.0);
vec3 cam_ray =  vec3(u_cam_position)   ;

mat4 viewWorld = viewMatrix(cam_ray,vec3(0.0,0.0,0.0),vec3(0.0,1.0,0.0));
vec3 worldDir = (viewWorld * vec4(dir,0.0)).xyz; 

float dist = ray_march(cam_ray,worldDir,0.0,100.0);
//float dist = sphereSDf(cam_ray *    ,50.0)

   if(dist > 100.0 - 0.01) {
   gl_FragColor = vec4(0.0,1.0,0.0,1.0);
   return; 
  
   }
   
   //float sl = softLight(cam_ray,dir,0.0,10.0,8);

   vec3 p = vec3(cam_ray + dist * worldDir);
   vec3 ka = vec3(0.0,0.0,0.);
   vec3 kd = vec3(0.5,0.0,0.0);
   vec3 ks = vec3(1.0,1.0,1.0);
   float shininess = 10.0; 

   vec3 color = phongLight(ka,kd,ks,shininess,p,cam_ray);
   //vec3 color = vec3(1.0,0.0,0.0);
   gl_FragColor = vec4(color,1.0);
   //gl_FragColor = sl;

}
