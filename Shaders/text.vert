#version 450 core

layout (location = 0) in vec2 inPos;
layout (location = 1) in vec2 inUV;

layout (push_constant) uniform PC
{
	vec2 size;
}pushConsts;

layout (location = 0) out vec2 outUV;

out gl_PerVertex 
{
	vec4 gl_Position;   
};

void main(void)
{
	gl_Position = vec4(inPos.x / pushConsts.size.x - 0.5, inPos.y / pushConsts.size.y - 0.5, 1.0, 1.0);
	outUV = inUV;
}
