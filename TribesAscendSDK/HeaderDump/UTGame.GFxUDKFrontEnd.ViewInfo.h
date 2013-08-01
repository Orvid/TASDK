#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GFxUDKFrontEnd__ViewInfo
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, DependantViews, 20)
		ADD_STRUCT(ScriptString*, SWFName, 8)
		ADD_STRUCT(ScriptName, ViewName, 0)
	};
}
#undef ADD_STRUCT
