#pragma once
namespace UnrealScript
{
	enum EngineTypes__EMaterialLightingModel : byte
	{
		MLM_Phong = 0,
		MLM_NonDirectional = 1,
		MLM_Unlit = 2,
		MLM_SHPRT = 3,
		MLM_Custom = 4,
		MLM_Anisotropic = 5,
		MLM_MAX = 6,
	};
}
