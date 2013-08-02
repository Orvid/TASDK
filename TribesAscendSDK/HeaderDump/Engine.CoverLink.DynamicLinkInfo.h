#pragma once
namespace UnrealScript
{
	struct CoverLink__DynamicLinkInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct CoverLink__DynamicLinkInfo
	{
	public:
		ADD_STRUCT(Vector, LastSrcLocation, 12)
		ADD_STRUCT(Vector, LastTargetLocation, 0)
	};
}
#undef ADD_STRUCT
