#pragma once
namespace UnrealScript
{
	enum UDKAnimBlendByFlying__EFlyingState : byte
	{
		Flying_NotFlying = 0,
		Flying_OpeningWings = 1,
		Flying_Flying = 2,
		Flying_ClosingWings = 3,
		Flying_MAX = 4,
	};
}
