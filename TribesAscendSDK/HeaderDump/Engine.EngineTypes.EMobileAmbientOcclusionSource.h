#pragma once
namespace UnrealScript
{
	enum EngineTypes__EMobileAmbientOcclusionSource : byte
	{
		MAOS_Disabled = 0,
		MAOS_VertexColorRed = 1,
		MAOS_VertexColorGreen = 2,
		MAOS_VertexColorBlue = 3,
		MAOS_VertexColorAlpha = 4,
		MAOS_MAX = 5,
	};
}
