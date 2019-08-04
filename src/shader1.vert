uniform mat4 modelViewProjectionMatrix
in Vec4 pos;

void main() {

gl_Position = modelViewProjectionMatrix * pos;

}
