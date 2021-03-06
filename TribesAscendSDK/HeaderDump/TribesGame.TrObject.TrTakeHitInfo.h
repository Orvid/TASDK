#pragma once
namespace UnrealScript
{
	struct TrObject__TrTakeHitInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct TrObject__TrTakeHitInfo
	{
	public:
		ADD_STRUCT(int, Damage, 0)
		ADD_STRUCT(Vector, HitLocation, 4)
		ADD_STRUCT(Vector, Momentum, 16)
		ADD_OBJECT(ScriptClass, DamageType, 28)
		ADD_STRUCT(ScriptName, HitBone, 32)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
