#pragma once

#include <unordered_map>
#include <string>

#include "RmCamera.h"
#include "RmMaterial.h"
#include "RmGraphNode.h"

const char* SHADER_BASE =
R"(// Generating distance to basic shapes default functions
@SHAPE_DST_FUNC

//Generating tooling functions (smoothing, onions, compute normals, shadow casting...)
@TOOLS_FUNC

// Generating distance to user objects default functions
@OBJ_DST_FUNC

// Generating world scene distance function
@WORLD_DST_FUNC

void mainImage( out vec4 fragColor, in vec2 fragCoord ){
@CAMERA_SETUP

@MARCHING_START

@COMPUTE_MATERIALS

@COMPUTE_COLOR

})";


class RmShaderGen
{
public:
	RmShaderGen();
	~RmShaderGen();

	std::string generateCam();

	std::string generateWorld();

private:
	Scalar m_defaultError;

	Scalar m_gammaCorrection;

	enum class ShaderFun
	{
		// Tooling functions
		TOOLS_MIN,			// Additive
		TOOLS_MAX,			// Subtractive
		TOOLS_SMOOTH_MIN,	// Smooth additive
		TOOLS_SMOOTH_sMAX,	// Smooth subtractive

		// Signed distance functions
		SHAPE_SPHERE,	
		SHAPE_ELIPSOID,
		SHAPE_STICK,


	};

	static const std::unordered_map<ShaderFun,const char*> m_FunctionSources;
};

