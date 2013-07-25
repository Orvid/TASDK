#pragma once
#include "Engine__PhysicsVolume.h"
#include "Engine__Pawn.h"
#include "Engine__Ladder.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LadderVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LadderVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LadderVolume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LadderVolume : public PhysicsVolume
	{
	public:
		ADD_STRUCT(::VectorProperty, ClimbDir, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bAllowLadderStrafing, 0x4)
		ADD_OBJECT(Pawn, PendingClimber)
		ADD_VAR(::BoolProperty, bAutoPath, 0x2)
		ADD_VAR(::BoolProperty, bNoPhysicalLadder, 0x1)
		ADD_OBJECT(Ladder, LadderList)
		ADD_STRUCT(::VectorProperty, LookDir, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, WallDir, 0xFFFFFFFF
		// Here lies the not-yet-implemented method 'InUse'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PawnEnteredVolume'
		// Here lies the not-yet-implemented method 'PawnLeavingVolume'
		// Here lies the not-yet-implemented method 'PhysicsChangedFor'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
