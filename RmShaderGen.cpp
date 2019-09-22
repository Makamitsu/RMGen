#include "RmShaderGen.h"


const std::unordered_map<RmShaderGen::ShaderFun, const char*> RmShaderGen::m_FunctionSources =
{
	{ ShaderFun::MIN,
		R"(min(d0,d);)"
	},
	{ ShaderFun::MAX,
		R"(max(d0,d);)"
	},
	{ ShaderFun::sMIN,
		R"(max(d0,d);)"
	},
	{ ShaderFun::sMAX,
		R"(max(d0,d);)"
	},
};


RmShaderGen::RmShaderGen()
{
}


RmShaderGen::~RmShaderGen()
{
}
