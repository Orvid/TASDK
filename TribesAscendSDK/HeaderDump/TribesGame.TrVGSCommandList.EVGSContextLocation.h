#pragma once
namespace UnrealScript
{
	enum TrVGSCommandList__EVGSContextLocation : byte
	{
		VGSContext_None = 0,
		VGSContext_InsideBase = 1,
		VGSContext_AroundBase = 2,
		VGSContext_BehindBase = 3,
		VGSContext_Midfield = 4,
		VGSContext_NearGenerator = 5,
		VGSContext_NearFlag = 6,
		VGSContext_NearBaseTurret = 7,
		VGSContext_NearVehiclePad = 8,
		VGSContext_MAX = 9,
	};
}
