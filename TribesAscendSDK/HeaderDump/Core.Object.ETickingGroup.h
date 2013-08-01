#pragma once
namespace UnrealScript
{
	enum Object__ETickingGroup : byte
	{
		TG_PreAsyncWork = 0,
		TG_DuringAsyncWork = 1,
		TG_PostAsyncWork = 2,
		TG_PostUpdateWork = 3,
		TG_EffectsUpdateWork = 4,
		TG_MAX = 5,
	};
}
