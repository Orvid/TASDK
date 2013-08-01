#pragma once
namespace UnrealScript
{
	enum UTPlayerController__EAutoObjectivePreference : byte
	{
		AOP_Disabled = 0,
		AOP_NoPreference = 1,
		AOP_Attack = 2,
		AOP_Defend = 3,
		AOP_OrbRunner = 4,
		AOP_SpecialOps = 5,
		AOP_MAX = 6,
	};
}
