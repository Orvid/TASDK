#pragma once
namespace UnrealScript
{
	class SoundNodeWaveParam;
}
#include "Engine.SoundNode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SoundNodeWaveParam : public SoundNode
	{
	public:
		ADD_STRUCT(ScriptName, WaveParameterName, 76)
	};
}
#undef ADD_STRUCT
