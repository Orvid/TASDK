#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrConsolePlayerController__ProfileSettingToUE3BindingDatum
	{
	public:
		ADD_STRUCT(ScriptName, UE3BindingName, 8)
		ADD_STRUCT(ScriptName, ProfileSettingName, 0)
	};
}
#undef ADD_STRUCT
