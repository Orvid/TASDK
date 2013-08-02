#pragma once
namespace UnrealScript
{
	struct UDKBot__EnemyPosition;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UDKBot__EnemyPosition
	{
	public:
		ADD_STRUCT(float, Time, 24)
		ADD_STRUCT(Vector, Velocity, 12)
		ADD_STRUCT(Vector, Position, 0)
	};
}
#undef ADD_STRUCT
