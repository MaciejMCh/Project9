#version 330

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 normalMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ModelMatrix;


layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec3 inColor;
layout (location = 2) in vec3 inNormal;
layout (location = 3) in vec3 inTexCoord;


out vec3 vNormal;
out vec3 vPosition;
out vec4 kolorek;
out vec2 texCoord;


out vec3 vLight;
out vec3 mPosition;


void main()
{	


	mPosition = (ModelMatrix*vec4(inPosition, 1.0)).xyz;


	//vec4 light = ModelMatrix*vec4(vec3(10.0, 1.0, 1.0), 1.0);
	//vec4 light = vec4(vec3(10.0, 1.0, 1.0), 1.0);
	//vec4 pos = ModelMatrix*vec4(inPosition, 1.0);
	//vLight = light.xyz-pos.xyz;


	gl_Position = projectionMatrix*modelViewMatrix*vec4(inPosition, 1.0);
	vec4 vRes = normalMatrix*vec4(inNormal, 0.0);
	vNormal = vRes.xyz;	
	vPosition = gl_Position.xyz;
	kolorek = vec4(inColor,1.0);	
	texCoord = vec2(inTexCoord[0],inTexCoord[1]);	
}