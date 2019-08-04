out vec4 col;

vec4 ray_march(in vec3 o,in vec3 d) {

float dt = 0;

for(int i = 0; i <= 64; ++i) {

float p = o + d * dt;
float df =  map(p);
 
    if(df < 0.001) {
    return vec3(1.0,0.0,0.0);
    } else {
    break;
    }

dt += df;

}
return vec3(0.0);
}

float map(in vec3f p) {
float s0 = sphere(p,vec3(0.0),1.0);
return s0;
}

float sphere(in vec3f p,in vec3f c,float r) {
return length(p-c)-r;
}

void main() {

vec2 uv;
vec3 cam_pos = vec3(0.0,0.0,-5.0);
vec3 o = cam_pos;
vec3 d = vec3(uv,1.0);

vec3 shader_col = ray_march(o,d);
col = vec4(shader_col,1.0);
}
