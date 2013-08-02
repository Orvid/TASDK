#pragma once
namespace UnrealScript
{
	struct InterpTrackFaceFX__FaceFXTrackKey;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InterpTrackFaceFX__FaceFXTrackKey
	{
	public:
		ADD_STRUCT(ScriptString*, FaceFXSeqName, 16)
		ADD_STRUCT(ScriptString*, FaceFXGroupName, 4)
		ADD_STRUCT(float, StartTime, 0)
	};
}
#undef ADD_STRUCT
