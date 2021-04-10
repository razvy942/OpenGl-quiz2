#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL\glew.h>

#include "DirectionalLight.h"
#include "PointLight.h"
#include "CommonValues.h"

class Shader
{
public:
	Shader();

	void CreateFromString(const char* vertexCode, const char* fragmentCode);
	void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);

	std::string ReadFile(const char* fileLocation);

	GLuint GetProjectionLocation();
	GLuint GetModelLocation();
	GLuint GetViewLocation();
	GLuint GetAmbientIntensityLocation();
	GLuint GetAmbientColourLocation();
	GLuint GetDiffuseIntensityLocation();
	GLuint GetDirectionLocation();
	GLuint GetSpecularIntensityLocation();
	GLuint GetShininessLocation();
	GLuint GetEyePositionLocation();

	void SetDirectionalLight(DirectionalLight* dLight);
	void SetPointLight(PointLight* pLight, unsigned int lightCount);

	void UseShader();
	void ClearShader();

	~Shader();

private:
	int pointLightCount;

	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
		uniformSpecularIntensity, uniformShininess;

	struct {
		unsigned int uniformColour;
		unsigned int uniformAmbientIntensity;
		unsigned int uniformDiffuseIntensity;

		unsigned int uniformDirection;
	} uniformDirectionalLight;

	unsigned int uniformPointLightCount;

	struct {
		unsigned int uniformColour;
		unsigned int uniformAmbientIntensity;
		unsigned int uniformDiffuseIntensity;

		unsigned int uniformPosition;
		unsigned int uniformConstant;
		unsigned int uniformLinear;
		unsigned int uniformExponent;
	} uniformPointLight[MAX_POINT_LIGHTS];

	void CompileShader(const char* vertexCode, const char* fragmentCode);
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};

