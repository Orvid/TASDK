#pragma once
namespace UnrealScript
{
	class SeqVar_String;
}
#include "Engine.SequenceVariable.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqVar_String : public SequenceVariable
	{
	public:
		ADD_STRUCT(ScriptString*, StrValue, 148)
	};
}
#undef ADD_STRUCT
