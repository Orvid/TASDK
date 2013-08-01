#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UTPlayerController__PostProcessInfo
	{
	public:
		ADD_STRUCT(float, Desaturation, 12)
		ADD_STRUCT(float, HighLights, 8)
		ADD_STRUCT(float, MidTones, 4)
		ADD_STRUCT(float, Shadows, 0)
	};
}
#undef ADD_STRUCT
