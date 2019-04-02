#version 450

#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

layout (set = 0, binding = 1) uniform texture2D colorTexture;
layout (set = 0, binding = 2) uniform sampler textureSampler;

layout (location = 0) in vec2 inUV;

layout (location = 0) out vec4 outFragColor;

void main() 
{
  outFragColor = vec4(1.0, 1.0, 1.0, 1.0);
  //outFragColor = texture(sampler2D(colorTexture, textureSampler), inUV);
}