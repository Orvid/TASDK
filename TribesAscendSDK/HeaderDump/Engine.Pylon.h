#pragma once
namespace UnrealScript
{
	class Pylon;
}
#include "Core.Object.OctreeElementId.h"
#include "Core.Object.Pointer.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.NavigationPoint.h"
#include "Engine.Pylon.ENavMeshEdgeType.h"
#include "Engine.Pylon.PolyReference.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.Volume.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Pylon : public NavigationPoint
	{
	public:
		typedef Pylon__ENavMeshEdgeType ENavMeshEdgeType;
		typedef Pylon__PolyReference PolyReference;
		ADD_STRUCT(ScriptArray<Vector>, NextPassSeedList, 716)
		ADD_STRUCT(ScriptArray<class Volume*>, ExpansionVolumes, 744)
		ADD_STRUCT(ScriptArray<class Pylon*>, ImposterPylons, 792)
		ADD_STRUCT(ScriptArray<class Actor*>, OnBuild_DisableCollisionForThese, 804)
		ADD_STRUCT(ScriptArray<class Actor*>, OnBuild_EnableCollisionForThese, 816)
		ADD_STRUCT(int, DebugEdgeCount, 828)
		ADD_STRUCT(Vector, ExpansionSphereCenter, 772)
		ADD_BOOL(bForceObstacleMeshCollision, 768, 0x400)
		ADD_BOOL(bDisabled, 768, 0x200)
		ADD_BOOL(bBuildThisPylon, 768, 0x100)
		ADD_BOOL(bDrawObstacleSurface, 768, 0x80)
		ADD_BOOL(bDrawWalkableSurface, 768, 0x40)
		ADD_BOOL(bRenderInShowPaths, 768, 0x20)
		ADD_BOOL(bDrawPolyBounds, 768, 0x10)
		ADD_BOOL(bDrawEdgePolys, 768, 0x8)
		ADD_BOOL(bNeedsCostCheck, 768, 0x4)
		ADD_BOOL(bUseExpansionSphereOverride, 768, 0x2)
		ADD_BOOL(bImportedMesh, 768, 0x1)
		ADD_STRUCT(float, MaxExpansionRadius, 760)
		ADD_STRUCT(float, ExpansionRadius, 756)
		ADD_OBJECT(Pylon, NextPylon, 740)
		ADD_STRUCT(Object__Pointer, OctreeIWasAddedTo, 736)
		ADD_STRUCT(Object__OctreeElementId, OctreeId, 728)
		ADD_STRUCT(Object__Pointer, PathObjectsThatAffectThisPylon, 712)
		ADD_STRUCT(Object__Pointer, WorkingSetPtr, 708)
		ADD_STRUCT(Object__Pointer, DynamicObstacleMesh, 704)
		ADD_STRUCT(Object__Pointer, ObstacleMesh, 700)
		ADD_STRUCT(Object__Pointer, NavMeshPtr, 696)
		ADD_STRUCT(Object__Pointer, VfTable_IEditorLinkSelectionInterface, 692)
		void OnPylonStatusChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9967);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9968);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetEnabled(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9969);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsEnabled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9971);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9973);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanReachPylon(class Pylon* DestPylon, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9975);
			byte params[12] = { NULL };
			*(class Pylon**)params = DestPylon;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
