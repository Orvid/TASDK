#pragma once
namespace UnrealScript
{
	enum LightComponent__ELightAffectsClassification : byte
	{
		LAC_USER_SELECTED = 0,
		LAC_DYNAMIC_AFFECTING = 1,
		LAC_STATIC_AFFECTING = 2,
		LAC_DYNAMIC_AND_STATIC_AFFECTING = 3,
		LAC_MAX = 4,
	};
}
