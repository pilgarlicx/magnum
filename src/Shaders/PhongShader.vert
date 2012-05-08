#version 330

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform vec3 light;

in vec4 vertex;
in vec3 normal;

out vec3 transformedNormal;
out vec3 lightDirection;

void main() {
    /* Transformed vertex position */
    vec4 transformedVertex4 = transformationMatrix*vertex;
    vec3 transformedVertex = transformedVertex4.xyz/transformedVertex4.w;

    /* Transformed normal vector */
    transformedNormal = normalize(mat3x3(transformationMatrix)*normal);

    /* Direction to the light */
    lightDirection = normalize(light - transformedVertex);

    /* Transform the vertex */
    gl_Position = projectionMatrix*transformedVertex4;
}
