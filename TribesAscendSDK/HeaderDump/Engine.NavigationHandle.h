#pragma once
namespace UnrealScript
{
	class NavigationHandle;
}
#include "Core.Object.h"
#include "Core.Object.Color.h"
#include "Core.Object.Pointer.h"
#include "Engine.Actor.h"
#include "Engine.Actor.BasedPosition.h"
#include "Engine.Controller.h"
#include "Engine.CoverLink.CoverInfo.h"
#include "Engine.EngineTypes.EPathFindingError.h"
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Engine.NavigationHandle.EdgePointer.h"
#include "Engine.NavigationHandle.NavMeshPathParams.h"
#include "Engine.NavigationHandle.PathStore.h"
#include "Engine.NavigationHandle.PolySegmentSpan.h"
#include "Engine.Pylon.h"
#include "Engine.Pylon.ENavMeshEdgeType.h"
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
	class NavigationHandle : public Object
	{
	public:
		typedef NavigationHandle__PolySegmentSpan PolySegmentSpan;
		typedef NavigationHandle__NavMeshPathParams NavMeshPathParams;
		typedef NavigationHandle__PathStore PathStore;
		typedef NavigationHandle__EdgePointer EdgePointer;
		static const float LINECHECK_GRANULARITY;
		static const auto NUM_PATHFINDING_PARAMS = 9;
		ADD_STRUCT(float, LastPathFailTime, 208)
		ADD_STRUCT(EngineTypes__EPathFindingError, LastPathError, 204)
		ADD_STRUCT(NavigationHandle__NavMeshPathParams, CachedPathParams, 156)
		ADD_OBJECT(NavMeshPathGoalEvaluator, PathGoalList, 152)
		ADD_OBJECT(NavMeshPathConstraint, PathConstraintList, 148)
		ADD_BOOL(bUltraVerbosePathDebugging, 144, 0x8)
		ADD_BOOL(bDebugConstraintsAndGoalEvals, 144, 0x4)
		ADD_BOOL(bUseORforEvaluateGoal, 144, 0x2)
		ADD_BOOL(bSkipRouteCacheUpdates, 144, 0x1)
		ADD_STRUCT(Actor__BasedPosition, FinalDestination, 92)
		ADD_STRUCT(Object__Pointer, SubGoal_DestPoly, 88)
		ADD_STRUCT(Object__Pointer, CurrentEdge, 84)
		ADD_STRUCT(Object__Pointer, BestUnfinishedPathPoint, 80)
		ADD_STRUCT(NavigationHandle__PathStore, PathCache, 68)
		ADD_STRUCT(Object__Pointer, AnchorPoly, 64)
		ADD_OBJECT(Pylon, AnchorPylon, 60)
		void ClearConstraints()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20784);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPathConstraint(class NavMeshPathConstraint* Constraint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20785);
			byte params[4] = { NULL };
			*(class NavMeshPathConstraint**)params = Constraint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddGoalEvaluator(class NavMeshPathGoalEvaluator* Evaluator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20787);
			byte params[4] = { NULL };
			*(class NavMeshPathGoalEvaluator**)params = Evaluator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class NavMeshPathConstraint* CreatePathConstraint(ScriptClass* ConstraintClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20789);
			byte params[8] = { NULL };
			*(ScriptClass**)params = ConstraintClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavMeshPathConstraint**)&params[4];
		}
		class NavMeshPathGoalEvaluator* CreatePathGoalEvaluator(ScriptClass* GoalEvalClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20792);
			byte params[8] = { NULL };
			*(ScriptClass**)params = GoalEvalClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavMeshPathGoalEvaluator**)&params[4];
		}
		int GetPathCacheLength()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20795);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void PathCache_Empty()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20797);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector PathCache_GetGoalPoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20798);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void PathCache_RemoveIndex(int InIdx, int Count)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20800);
			byte params[8] = { NULL };
			*(int*)params = InIdx;
			*(int*)&params[4] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetBestUnfinishedPathPoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20803);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		bool FindPylon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20805);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class Pylon* GetPylonFromPos(Vector Position)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20807);
			byte params[16] = { NULL };
			*(Vector*)params = Position;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Pylon**)&params[12];
		}
		bool GetNextMoveLocation(Vector& out_MoveDest, float ArrivalDistance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20810);
			byte params[20] = { NULL };
			*(Vector*)params = out_MoveDest;
			*(float*)&params[12] = ArrivalDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_MoveDest = *(Vector*)params;
			return *(bool*)&params[16];
		}
		bool SetFinalDestination(Vector FinalDest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20814);
			byte params[16] = { NULL };
			*(Vector*)params = FinalDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ComputeValidFinalDestination(Vector& out_ComputedPosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20817);
			byte params[16] = { NULL };
			*(Vector*)params = out_ComputedPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ComputedPosition = *(Vector*)params;
			return *(bool*)&params[12];
		}
		bool FindPath(class Actor*& out_DestActor, int& out_DestItem)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20820);
			byte params[12] = { NULL };
			*(class Actor**)params = out_DestActor;
			*(int*)&params[4] = out_DestItem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_DestActor = *(class Actor**)params;
			out_DestItem = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		bool SuggestMovePreparation(Vector& MovePt, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20824);
			byte params[20] = { NULL };
			*(Vector*)params = MovePt;
			*(class Controller**)&params[12] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MovePt = *(Vector*)params;
			return *(bool*)&params[16];
		}
		bool ObstacleLineCheck(Vector Start, Vector End, Vector Extent, Vector& out_HitLoc, Vector& out_HitNorm)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20828);
			byte params[64] = { NULL };
			*(Vector*)params = Start;
			*(Vector*)&params[12] = End;
			*(Vector*)&params[24] = Extent;
			*(Vector*)&params[36] = out_HitLoc;
			*(Vector*)&params[48] = out_HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_HitLoc = *(Vector*)&params[36];
			out_HitNorm = *(Vector*)&params[48];
			return *(bool*)&params[60];
		}
		bool ObstaclePointCheck(Vector Pt, Vector Extent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20835);
			byte params[28] = { NULL };
			*(Vector*)params = Pt;
			*(Vector*)&params[12] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool LineCheck(Vector Start, Vector End, Vector Extent, Vector& out_HitLocation, Vector& out_HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20839);
			byte params[64] = { NULL };
			*(Vector*)params = Start;
			*(Vector*)&params[12] = End;
			*(Vector*)&params[24] = Extent;
			*(Vector*)&params[36] = out_HitLocation;
			*(Vector*)&params[48] = out_HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_HitLocation = *(Vector*)&params[36];
			out_HitNormal = *(Vector*)&params[48];
			return *(bool*)&params[60];
		}
		bool PointCheck(Vector Pt, Vector Extent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20846);
			byte params[28] = { NULL };
			*(Vector*)params = Pt;
			*(Vector*)&params[12] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool PointReachable(Vector Point, Vector OverrideStartPoint, bool bAllowHitsInEndCollisionBox)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20850);
			byte params[32] = { NULL };
			*(Vector*)params = Point;
			*(Vector*)&params[12] = OverrideStartPoint;
			*(bool*)&params[24] = bAllowHitsInEndCollisionBox;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool ActorReachable(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20855);
			byte params[8] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DrawPathCache(Vector DrawOffset, bool bPersistent, Object__Color DrawColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20858);
			byte params[20] = { NULL };
			*(Vector*)params = DrawOffset;
			*(bool*)&params[12] = bPersistent;
			*(Object__Color*)&params[16] = DrawColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetCurrentEdgeDebugText()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20862);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void ClearCurrentEdge()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20864);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Pylon__ENavMeshEdgeType GetCurrentEdgeType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20865);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Pylon__ENavMeshEdgeType*)params;
		}
		void GetAllPolyCentersWithinBounds(Vector pos, Vector Extent, ScriptArray<Vector>& out_PolyCtrs)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20867);
			byte params[36] = { NULL };
			*(Vector*)params = pos;
			*(Vector*)&params[12] = Extent;
			*(ScriptArray<Vector>*)&params[24] = out_PolyCtrs;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_PolyCtrs = *(ScriptArray<Vector>*)&params[24];
		}
		void GetValidPositionsForBox(Vector pos, float Radius, Vector Extent, bool bMustBeReachableFromStartPos, ScriptArray<Vector>& out_ValidPositions, int MaxPositions, float MinRadius, Vector ValidBoxAroundStartPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20872);
			byte params[64] = { NULL };
			*(Vector*)params = pos;
			*(float*)&params[12] = Radius;
			*(Vector*)&params[16] = Extent;
			*(bool*)&params[28] = bMustBeReachableFromStartPos;
			*(ScriptArray<Vector>*)&params[32] = out_ValidPositions;
			*(int*)&params[44] = MaxPositions;
			*(float*)&params[48] = MinRadius;
			*(Vector*)&params[52] = ValidBoxAroundStartPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ValidPositions = *(ScriptArray<Vector>*)&params[32];
		}
		void LimitPathCacheDistance(float MaxDist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20882);
			byte params[4] = { NULL };
			*(float*)params = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsAnchorInescapable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20884);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Vector GetFirstMoveLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20886);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		float CalculatePathDistance(Vector FinalDest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20888);
			byte params[16] = { NULL };
			*(Vector*)params = FinalDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		Vector MoveToDesiredHeightAboveMesh(Vector Point, float Height)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20891);
			byte params[28] = { NULL };
			*(Vector*)params = Point;
			*(float*)&params[12] = Height;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[16];
		}
		bool PopulatePathfindingParamCache()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20895);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool GetAllCoverSlotsInRadius(Vector FromLoc, float Radius, ScriptArray<CoverLink__CoverInfo>& out_CoverList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20897);
			byte params[32] = { NULL };
			*(Vector*)params = FromLoc;
			*(float*)&params[12] = Radius;
			*(ScriptArray<CoverLink__CoverInfo>*)&params[16] = out_CoverList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CoverList = *(ScriptArray<CoverLink__CoverInfo>*)&params[16];
			return *(bool*)&params[28];
		}
	};
	const float NavigationHandle::LINECHECK_GRANULARITY = 768.f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
