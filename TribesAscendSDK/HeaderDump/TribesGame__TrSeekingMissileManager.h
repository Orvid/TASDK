#pragma once
#include "Engine__Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSeekingMissileManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSeekingMissileManager : public Info
	{
	public:
		ADD_VAR(::IntProperty, RepCounter, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
