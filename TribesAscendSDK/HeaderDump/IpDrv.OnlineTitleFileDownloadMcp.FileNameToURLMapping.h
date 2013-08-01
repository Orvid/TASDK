#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineTitleFileDownloadMcp__FileNameToURLMapping
	{
	public:
		ADD_STRUCT(ScriptName, UrlMapping, 8)
		ADD_STRUCT(ScriptName, Filename, 0)
	};
}
#undef ADD_STRUCT
