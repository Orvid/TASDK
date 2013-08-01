#pragma once
namespace UnrealScript
{
	enum ReimportTextureFactory__LightingModel : byte
	{
		MLM_Phong = 0,
		MLM_NonDirectional = 1,
		MLM_Unlit = 2,
		MLM_Custom = 3,
		MLM_Anisotropic = 4,
		MLM_MAX = 5,
	};
}
