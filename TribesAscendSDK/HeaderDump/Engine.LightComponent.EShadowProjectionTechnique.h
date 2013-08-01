#pragma once
namespace UnrealScript
{
	enum LightComponent__EShadowProjectionTechnique : byte
	{
		ShadowProjTech_Default = 0,
		ShadowProjTech_PCF = 1,
		ShadowProjTech_VSM = 2,
		ShadowProjTech_BPCF_Low = 3,
		ShadowProjTech_BPCF_Medium = 4,
		ShadowProjTech_BPCF_High = 5,
		ShadowProjTech_MAX = 6,
	};
}
