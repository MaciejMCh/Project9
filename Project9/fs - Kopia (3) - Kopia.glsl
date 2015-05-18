#version 330


uniform sampler2D gSampler;

uniform vec3 DirLightColor;
uniform vec3 DirLightDir;
uniform float DirLightAmp;
uniform float DirLightDiff;
uniform float DirLightSpec;


uniform vec3 AmbLightColor;
uniform float AmbLightAmp;


uniform vec3 PntLightCol[10];
uniform vec3 PntLightPos[10];
uniform vec3 PntLightFnc[10];
uniform float PntLightSpec[10];
uniform int PntLightCnt;

uniform vec3 CameraPos;

uniform float MaterialAmbient;
uniform float MaterialDiffuse;
uniform float MaterialSpecular;
uniform float MaterialShininess;

in vec4 kolorek;
in vec3 vNormal;
in vec2 texCoord;
in vec3 vPosition;
in vec3 mPosition;

in vec3 vLight;


out vec4 outputColor;

void main()
{		


	

	/////////////////////////////////////////////////////////////AMBIENT LIGHT///////////////////////////////////////////


	vec4 AmbLight = vec4(AmbLightColor*AmbLightAmp,1.0);


	/////////////////////////////////////////////////////////////DIRECTIONAL LIGHT///////////////////////////////////////


	vec4 DirLight = vec4(DirLightColor*DirLightAmp*max(0.0, dot(normalize(vNormal), -DirLightDir)),1.0);
	
	vec3 halfV = normalize(normalize(CameraPos-mPosition)+normalize(-DirLightDir));
	float NdotHV = max(dot(vNormal,halfV),0.0);
	
	vec3 diir = DirLightColor* 1.0 * 
pow(NdotHV, 10.0);
	vec4 DirLightSpec = vec4(diir,1.0);

	
	/////////////////////////////////////////////////////////////POINT LIGHT/////////////////////////////////////////////


	vec3 n = normalize(vNormal);
	vec3 ld;
	vec3 PntLightSum = vec3(0.0, 0.0, 0.0);
	float dst;
	float dotL;
	float pDiff;
	for(int i=0; i<=PntLightCnt-1; i++){
		ld = vec3(PntLightPos[i] - mPosition);
		dst = length(ld);
		dotL = max(dot(n,normalize(ld)),0.0);
		pDiff = dotL*(PntLightFnc[i].x/(dst*PntLightFnc[i].y));
		PntLightSum = PntLightSum +PntLightCol[i]*pDiff;
	}	
	PntLightSum = PntLightSum * MaterialDiffuse;

	vec3 PntLightSpecSum = vec3(0.0, 0.0, 0.0);
	for(int i=0; i<=PntLightCnt-1; i++){
		halfV = normalize(normalize(CameraPos-mPosition)+normalize(PntLightPos[i]-mPosition));
		NdotHV = max(dot(vNormal,halfV),0.0);
		PntLightSpecSum = PntLightSpecSum + PntLightCol[i] * MaterialSpecular 
* pow(NdotHV, MaterialShininess);
		
	}







	vec4 LightSum = AmbLight+DirLight+DirLightSpec+vec4(PntLightSum, 1.0)+ vec4(PntLightSpecSum, 1.0);
	//LightSum = DirLightSpec;
	LightSum = vec4(vec3(AmbLight.xyz+DirLight.xyz+DirLightSpec.xyz+PntLightSum+PntLightSpecSum), 1.0);
	//outputColor = kolorek*texture2D(gSampler, texCoord)*LightSum;
	outputColor = vec4(1.0,1.0,1.0,1.0)*texture2D(gSampler, texCoord)*LightSum;
	
}