#pragma once
namespace UnrealScript
{
	class Route;
}
#include "Core.Object.Pointer.h"
#include "Engine.Actor.ActorReference.h"
#include "Engine.Info.h"
#include "Engine.Pawn.h"
#include "Engine.Route.ERouteDirection.h"
#include "Engine.Route.ERouteFillAction.h"
#include "Engine.Route.ERouteType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Route : public Info
	{
	public:
		typedef Route__ERouteDirection ERouteDirection;
		typedef Route__ERouteFillAction ERouteFillAction;
		typedef Route__ERouteType ERouteType;
		ADD_STRUCT(ScriptArray<Actor__ActorReference>, RouteList, 484)
		ADD_STRUCT(Route__ERouteType, RouteType, 480)
		ADD_STRUCT(Object__Pointer, VfTable_IEditorLinkSelectionInterface, 476)
		ADD_STRUCT(float, FudgeFactor, 496)
		ADD_STRUCT(int, RouteIndexOffset, 500)
		int ResolveRouteIndex(int Idx, Route__ERouteDirection RouteDirection, byte& out_bComplete, byte& out_bReverse)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25364);
			byte params[11] = { NULL };
			*(int*)params = Idx;
			*(Route__ERouteDirection*)&params[4] = RouteDirection;
			params[5] = out_bComplete;
			params[6] = out_bReverse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_bComplete = params[5];
			out_bReverse = params[6];
			return *(int*)&params[8];
		}
		int MoveOntoRoutePath(class Pawn* P, Route__ERouteDirection RouteDirection, float DistFudgeFactor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25370);
			byte params[13] = { NULL };
			*(class Pawn**)params = P;
			*(Route__ERouteDirection*)&params[4] = RouteDirection;
			*(float*)&params[8] = DistFudgeFactor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
	};
}
#undef ADD_STRUCT
