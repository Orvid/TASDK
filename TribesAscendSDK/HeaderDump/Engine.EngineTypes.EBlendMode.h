#pragma once
namespace UnrealScript
{
	enum EngineTypes__EBlendMode : byte
	{
		BLEND_Opaque = 0,
		BLEND_Masked = 1,
		BLEND_Translucent = 2,
		BLEND_Additive = 3,
		BLEND_Modulate = 4,
		BLEND_SoftMasked = 5,
		BLEND_AlphaComposite = 6,
		BLEND_DitheredTranslucent = 7,
		BLEND_MAX = 8,
	};
}
