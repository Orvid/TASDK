#pragma once
namespace UnrealScript
{
	struct AnimSequence__AnimTag;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimSequence__AnimTag
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, Contains, 12)
		ADD_STRUCT(ScriptString*, Tag, 0)
	};
}
#undef ADD_STRUCT
