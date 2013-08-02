#pragma once
namespace UnrealScript
{
	struct Engine__DropNoteInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Engine__DropNoteInfo
	{
	public:
		ADD_STRUCT(ScriptString*, Comment, 24)
		ADD_STRUCT(Rotator, Rotation, 12)
		ADD_STRUCT(Vector, Location, 0)
	};
}
#undef ADD_STRUCT
