#pragma once
namespace UnrealScript
{
	struct CoverMeshComponent__CoverMeshes;
}
#include "Engine.StaticMesh.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct CoverMeshComponent__CoverMeshes
	{
	public:
		ADD_OBJECT(StaticMesh, PlayerOnly, 40)
		ADD_OBJECT(StaticMesh, PopUp, 36)
		ADD_OBJECT(StaticMesh, SwatRight, 32)
		ADD_OBJECT(StaticMesh, SwatLeft, 28)
		ADD_OBJECT(StaticMesh, SlipRight, 24)
		ADD_OBJECT(StaticMesh, SlipLeft, 20)
		ADD_OBJECT(StaticMesh, Mantle, 16)
		ADD_OBJECT(StaticMesh, Climb, 12)
		ADD_OBJECT(StaticMesh, LeanRight, 8)
		ADD_OBJECT(StaticMesh, LeanLeft, 4)
		ADD_OBJECT(StaticMesh, Base, 0)
	};
}
#undef ADD_OBJECT
