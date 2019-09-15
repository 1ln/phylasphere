#version 330

uniform vec2 u_resolution; 
uniform float u_time;
//uniform float u_mouse;

uniform vec3 u_cam_position;

//uniform float u_random_hash;
uniform float u_random;

const float PHI = 1.618033988749894; 
const float PI = 3.1415926535;

const float EPSILON = 0.001;
const int RAYMARCH_STEPS = 32;
const float TRACE_DISTANCE = 50.0;

float phiHash(float h) {
return fract(PHI * h);
}

float rand2d(vec2 st) {
return fract(sin(dot(st.xy,vec2(12.9898,78.233))) * 43758.5453123) * 2.0 - 1.0 ;
}

float rand3d(vec3 st) {
return fract(sin(dot(st.xyz,vec3(12.9898,78.233,128.852))) * 43758.5453) * 2.0 - 1.0; 
}

float hash(float n) { return fract(sin(n) * 753.5453123); }

float sin3(vec3 p,float n,float l) {
return sin(p.x * n) * sin(p.y * n) * sin(p.z * n) * l;  
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

for(int i = 0; i < 6; ++i) {
value += amp * noise2d(st_);
st_ *= 2.0; 
//st_ = rot * st_ * 2.0 + shift;
amp *= 0.5;

}
return value;
}

float noise3d(vec3 x,float r) {

vec3 p = floor(x);
vec3 f = fract(x);

f = f * f * (3.0 - 2.0 * f); 
float n = p.x + p.y * 157.0 + 113.0 * p.z + r;

return mix(mix(mix(hash(n + 0.0),hash(n + 1.0),f.x), 
               mix(hash(n + 157.0),hash(n + 158.0),f.x),f.y),
           mix(mix(hash(n + 113.0),hash(n + 114.0),f.x),
               mix(hash(n + 270.0),hash(n + 271.0),f.x),f.y),f.z);
} 


#define FB3D_OCTAVES 4
float fb3d(vec3 x,float r) {

float value = 0.0;
float amp = 0.5;

for(int i = 0; i < FB3D_OCTAVES; ++i) {

value += amp * noise3d(x,r);
x *= 2.0;
amp *= 0.5;
}
return value;
}

//2d Shaping Functions

float linear(float x) {
return x;
}

float power(float x,float f) {
return pow(x,f);
}

float envImpulse(float x,float k) {
float h = k * x;
return h * exp(1.0 - h);
}

float envStep(float x,float k,float n) {
return exp(-k * pow(x,n));
}

float cubicImpulse(float x,float c,float w) {
x = abs(x - c);
    if( x > w) { return 0.0; }

x /= w;
return 1.0 - x * x  * (3.0 - 2.0 * x);

}

float sincPhase(float x,float k) {
float a = PI * (k * x - 1.0);
return sin(a)/a;
}

//Rotations

mat4 rotY(float theta) {
float c = cos(theta);
float s = sin(theta);

return mat4( 
    vec4(c,0,s,0),
    vec4(0,1,0,0),
    vec4(-s,0,c,0),
    vec4(0,0,0,1)
);
}

mat4 rotX(float theta) {
float c = cos(theta);
float s = sin(theta);

return mat4( 
    vec4(s,0,c,0),
    vec4(0,1,0,0),
    vec4(-c,0,s,0),
    vec4(0,0,0,1)
);
}

mat2  rotate(in float theta) {
float c = cos(theta);
float s = sin(theta);

return mat2(c,-s,s,c);
}

//Signed Distance Functions

float sphereSDF(vec3 p,float r) { 
return length(p) - r;
}

float coneSDF(vec3 p,vec2 c) {
float q = length(p.xy);
return dot(c,vec2(q,p.z));
}

float planeSDF(vec3 p,vec4 n) {
return dot(p,n.xyz) + n.w;
}

float capsuleSDF(vec3 p,vec3 a,vec3 b,float r) {

vec3 pa = p - a;
vec3 ba = b - a;

float h = clamp(dot(pa,ba)/dot(ba,ba),0.0,1.0);

return length(pa - ba * h) - r;
} 

float triangularPrismSDF(vec3 p,vec2 h) {
vec3 q = abs(p);
return max(q.z - h.y,max(q.x * 0.866025 + p.y * 0.5,-p.y) - h.x * 0.5); 
}

float boxSDF(vec3 p,vec3 b) {
vec3 d = abs(p) - b;
return length(max(d,0.0)) + min(max(d.x,max(d.y,d.z)),0.0);
}

float torusSDF(vec3 p,vec2 t) {
vec2 q = vec2(length(vec2(p.x,p.z)) - t.x,p.y);
return length(q) - t.y; 
}

float cylinderSDF(vec3 p,float h,float r) {
vec2 d = abs(vec2(length(vec2(p.x,p.z)),p.y) - vec2(h,r));
return min(max(d.x,d.y),0.0) + length(max(d,0.0));
}

float hexPrismSDF(vec3 p,vec2 h) {

const vec3 k = vec3(-0.8660254,0.5,0.57735);
p = abs(p);
p.xy -= 2.0 * min(dot(k.xy,p.xy),0.0) * k.xy;

vec2 d = vec2(length(p.xy - vec2(clamp(p.x,-k.z * h.x,k.z * h.x),h.x)) * sign(p.x-h.x),p.z-h.x);
return min(max(d.x,d.y),0.0) + length(max(d,0.0));
}

vec2 opU(in vec2 d1,in vec2 d2) {
return d1.x < d2.x ? d1 : d2;
}

//Raymarching

vec2 map(in vec3 p) {
    
vec2 res = vec2(1.0,0.0);

//float n = sin3(p,5.0,.25);

float n = fb3d( p  ,u_random) ;

//vec3 rotating_point  = (rotY(u_time/100) * vec4(p,1.0)).xyz;
//float n = fb3d(vec3(rotating_point),u_random);
// p.xy *= rotate(u_time/100);

res = opU(res,vec2(sphereSDF(p - vec3(0.0,0.0,0.0)   ,2.0)+n,0.0));
//res = opU(res,vec2(boxSDF(p - vec3(0.0,0.0,0.0),vec3(1.0)),0.0));

return res;

}

vec2 rayMarch(in vec3 ro,in vec3 rd) {

float depth = 0.0;
float d = -1.0;

for(int i = 0; i < RAYMARCH_STEPS; ++i) {

vec3 position = ro + rd * depth;
vec2 distance = map(position);
 
    if(distance.x < EPSILON || TRACE_DISTANCE < distance.x) { break  ;} 

    depth += distance.x;
    d = distance.y;
    }
    
    if(TRACE_DISTANCE < depth) { d = -1.0; }
    return vec2(depth,d);
}

vec3 calcNormal(vec3 p) {

vec2 e = vec2(1.0,-1.0) * 0.00001;

return normalize(vec3(

                vec3(e.x,e.y,e.y) * map(p + vec3(e.x,e.y,e.y)).x + 
                vec3(e.y,e.x,e.y) * map(p + vec3(e.y,e.x,e.y)).x +
                vec3(e.y,e.y,e.x) * map(p + vec3(e.y,e.y,e.x)).x +
                vec3(e.x,e.x,e.x) * map(p + vec3(e.x,e.x,e.x)).x
));

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

vec3 light = vec3(10,10,10);
vec3 intensity = vec3(0.5,0.5,0.5);

color += phongModel(kd,ks,alpha,p,cam_ray,light,intensity); 
return color;

}

mat3 rayDirection(in vec3 camera_position,in vec3 camera_target,in float r) {

//vec3 rayCameraDirection(vec2 uv,vec3 cam_position,vec3 cam_target) {

vec3 camera_forward = normalize(camera_target - camera_position);
vec3 camera_up = vec3(sin(r),cos(r),0.0);
vec3 u = normalize(cross(camera_forward,camera_up));
vec3 v = normalize(cross(u,camera_forward));

return mat3(u,v,camera_forward);

}

vec3 render(vec3 ro,vec3 rd) {

vec2 rend = rayMarch(ro,rd);

//float distance = rayMarch(ro,rd);

float distance = rend.x;
float d = rend.y;

vec3 position =  ro + rd * distance;
vec3 normal = calcNormal(position);

vec3 light_position = vec3(-250.0);
vec3 light_dir = normalize(light_position - position);

vec3 ka = vec3(0.0);
vec3 kd = vec3(0.5);
vec3 ks = vec3(1.0);
float shininess = 0.0;
 
//vec3 color;

//if(d < 0.0) { 
//color = vec3(0.0);
//} else {
vec3 color = phongLight(ka,kd,ks,shininess,position,ro);
//}


return color;

}

void main() {

vec3 camera_position = vec3(u_cam_position);
vec3 camera_target = vec3(0,0,0);

vec2 uv = (gl_FragCoord.xy - 0.5 * u_resolution.x) / (min (u_resolution.x,u_resolution.y) );

vec3 direction = rayDirection(camera_position,camera_target,0.0) * normalize(vec3(uv,1.0));

vec3 color = render(camera_position,direction);
   
gl_FragColor = vec4(color,1.0);

}
