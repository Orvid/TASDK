#pragma once
namespace UnrealScript
{
	struct GameThirdPersonCamera__PenetrationAvoidanceFeeler;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameThirdPersonCamera__PenetrationAvoidanceFeeler
	{
	public:
		ADD_STRUCT(int, FramesUntilNextTrace, 36)
		ADD_STRUCT(int, TraceInterval, 32)
		ADD_STRUCT(Vector, Extent, 20)
		ADD_STRUCT(float, PawnWeight, 16)
		ADD_STRUCT(float, WorldWeight, 12)
		ADD_STRUCT(Rotator, AdjustmentRot, 0)
	};
}
#undef ADD_STRUCT
