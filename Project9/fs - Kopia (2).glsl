#version 330

//uniform vec3 LightColor;
//uniform vec3 LightDirection;
//uniform float LightAmbient;
uniform sampler2D gSampler;

uniform vec3 DirLightColor;
uniform vec3 DirLightDir;
uniform float DirLightAmp;

uniform vec3 AmbLightColor;
uniform float AmbLightAmp;

uniform vec3 PntLightColor[10];
uniform vec2 PntLightFnc[10];


in vec4 kolorek;
in vec3 vNormal;
in vec3 vPosition;
in vec2 texCoord;

in vec3 oPntLightPos[10];

in vec3 vPL;

out vec4 outputColor;

void main()
{		
//	float DirLight_Diff = max(0.0, dot(normalize(vNormal), -LightDirection));		
//	vec4 DirLight_Vec = Vec4

	vec4 AmbLight = vec4(AmbLightColor*AmbLightAmp,1.0);
	vec4 DirLight = vec4(DirLightColor*DirLightAmp*max(0.0, dot(normalize(vNormal), -DirLightDir)),1.0);




	vec3 ltv = vPL-vPosition;
	float dist = length(ltv);
	ltv = normalize(ltv);
	float dif = max(0.0, dot(vNormal, -ltv)); 
	
	vec4 point = vec4(1.0, 0.0, 0.0, 1.0)*dif;




	
	vec4 LightSum = AmbLight+DirLight+point;
	LightSum = point;

	




	//float LightDiffuse = max(0.0, dot(normalize(vNormal), -LightDirection));		
	//outputColor = kolorek*texture2D(gSampler, texCoord)*vec4(LightColor*(LightAmbient+LightDiffuse),1.0);		
	outputColor = kolorek*texture2D(gSampler, texCoord)*LightSum;		
}