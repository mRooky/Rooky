#version 450

layout (set = 0, binding = 0) uniform sampler2D deferred;

layout (location = 0) in vec2 inUV;

layout (location = 0) out vec4 outColor;

void main() 
{
	vec4 color = vec4(1.0, 1.0, 1.0, 1.0);
	//outColor = color;
	outColor = color * texture(deferred, inUV);
}