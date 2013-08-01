#pragma once
#include "TribesGame.TrValueModifier.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct TrFamilyInfo__SkillNode
	{
	public:
		ADD_STRUCT(int, Cost, 24)
		ADD_STRUCT(int, ParentIndex, 20)
		ADD_STRUCT(int, IconId, 16)
		ADD_STRUCT(int, IconPosY, 12)
		ADD_STRUCT(int, IconPosX, 8)
		ADD_STRUCT(float, Value, 4)
		ADD_OBJECT(TrValueModifier, ValueModifier, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
