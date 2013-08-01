#pragma once
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameInfo__GameTypePrefix
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, AdditionalGameTypes, 28)
		ADD_STRUCT(ScriptArray<ScriptString*>, ForcedObjects, 40)
		ADD_STRUCT(ScriptString*, GameType, 16)
		ADD_BOOL(bUsesCommonPackage, 12, 0x1)
		ADD_STRUCT(ScriptString*, Prefix, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
