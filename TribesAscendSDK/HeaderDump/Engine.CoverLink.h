#pragma once
#include "Engine.CoverLink.CoverSlot.h"
#include "Engine.NavigationPoint.h"
#include "Engine.Pawn.h"
#include "Core.Object.Rotator.h"
#include "Engine.CoverLink.DynamicLinkInfo.h"
#include "Core.Object.Vector.h"
#include "Engine.CoverLink.ECoverLocationDescription.h"
#include "Engine.CoverLink.ECoverType.h"
#include "Engine.CoverLink.CoverInfo.h"
#include "Engine.CoverLink.EFireLinkID.h"
#include "Engine.CoverLink.ECoverAction.h"
#include "Engine.SeqAct_ModifyCover.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.NavigationPoint.CheckpointRecord.h"
#include "Engine.Scout.h"
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
	class CoverLink : public NavigationPoint
	{
	public:
		static const float COVERLINK_DangerDist;
		static const float COVERLINK_EdgeExposureDot;
		static const float COVERLINK_EdgeCheckDot;
		static const float COVERLINK_ExposureDot;
		ADD_STRUCT(ScriptArray<CoverLink__CoverSlot>, Slots, 700)
		ADD_BOOL(bClaimAllSlots, 692, 0x4)
		ADD_STRUCT(ScriptArray<class Pawn*>, Claims, 724)
		ADD_BOOL(bCircular, 692, 0x20)
		ADD_BOOL(bDisabled, 692, 0x2)
		ADD_BOOL(bFractureOnTouch, 692, 0x200)
		ADD_BOOL(GLOBAL_bUseSlotMarkers, 692, 0x1)
		ADD_BOOL(bAutoSort, 692, 0x8)
		ADD_BOOL(bAutoAdjust, 692, 0x10)
		ADD_BOOL(bLooped, 692, 0x40)
		ADD_BOOL(bPlayerOnly, 692, 0x80)
		ADD_BOOL(bDynamicCover, 692, 0x100)
		ADD_BOOL(bDebug_FireLinks, 692, 0x400)
		ADD_BOOL(bDebug_ExposedLinks, 692, 0x800)
		ADD_BOOL(bDebug_CoverGen, 692, 0x1000)
		ADD_BOOL(bDoAutoSlotDensityFixup, 692, 0x2000)
		ADD_STRUCT(float, LeanTraceDist, 696)
		ADD_STRUCT(ScriptArray<CoverLink__DynamicLinkInfo>, DynamicLinkInfos, 712)
		ADD_STRUCT(float, InvalidateDistance, 736)
		ADD_STRUCT(float, MaxFireLinkDist, 740)
		ADD_STRUCT(Vector, CircularOrigin, 744)
		ADD_STRUCT(float, CircularRadius, 756)
		ADD_STRUCT(float, AlignDist, 760)
		ADD_STRUCT(float, AutoCoverSlotInterval, 764)
		ADD_STRUCT(float, StandHeight, 768)
		ADD_STRUCT(float, MidHeight, 772)
		ADD_STRUCT(Vector, StandingLeanOffset, 776)
		ADD_STRUCT(Vector, CrouchLeanOffset, 788)
		ADD_STRUCT(Vector, PopupOffset, 800)
		ADD_STRUCT(float, SlipDist, 812)
		ADD_STRUCT(float, TurnDist, 816)
		ADD_STRUCT(float, DangerScale, 820)
		ADD_OBJECT(CoverLink, NextCoverLink, 824)
		ADD_STRUCT(CoverLink__ECoverLocationDescription, LocationDescription, 828)
		bool GetFireLinkTargetCoverInfo(int SlotIdx, int FireLinkIdx, CoverLink__CoverInfo& out_Info, CoverLink__EFireLinkID ArrayID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13204);
			byte params[21] = { NULL };
			*(int*)params = SlotIdx;
			*(int*)&params[4] = FireLinkIdx;
			*(CoverLink__CoverInfo*)&params[8] = out_Info;
			*(CoverLink__EFireLinkID*)&params[16] = ArrayID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Info = *(CoverLink__CoverInfo*)&params[8];
			return *(bool*)&params[20];
		}
		byte PackFireLinkInteractionInfo(CoverLink__ECoverType SrcType, CoverLink__ECoverAction SrcAction, CoverLink__ECoverType DestType, CoverLink__ECoverAction DestAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13210);
			byte params[5] = { NULL };
			*(CoverLink__ECoverType*)params = SrcType;
			*(CoverLink__ECoverAction*)&params[1] = SrcAction;
			*(CoverLink__ECoverType*)&params[2] = DestType;
			*(CoverLink__ECoverAction*)&params[3] = DestAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		void UnPackFireLinkInteractionInfo(byte PackedByte, CoverLink__ECoverType& SrcType, CoverLink__ECoverAction& SrcAction, CoverLink__ECoverType& DestType, CoverLink__ECoverAction& DestAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13216);
			byte params[5] = { NULL };
			*params = PackedByte;
			*(CoverLink__ECoverType*)&params[1] = SrcType;
			*(CoverLink__ECoverAction*)&params[2] = SrcAction;
			*(CoverLink__ECoverType*)&params[3] = DestType;
			*(CoverLink__ECoverAction*)&params[4] = DestAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SrcType = *(CoverLink__ECoverType*)&params[1];
			SrcAction = *(CoverLink__ECoverAction*)&params[2];
			DestType = *(CoverLink__ECoverType*)&params[3];
			DestAction = *(CoverLink__ECoverAction*)&params[4];
		}
		Vector GetSlotLocation(int SlotIdx, bool bForceUseOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13222);
			byte params[20] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bForceUseOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[8];
		}
		Rotator GetSlotRotation(int SlotIdx, bool bForceUseOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13226);
			byte params[20] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bForceUseOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[8];
		}
		Vector GetSlotViewPoint(int SlotIdx, CoverLink__ECoverType Type, CoverLink__ECoverAction Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13230);
			byte params[18] = { NULL };
			*(int*)params = SlotIdx;
			*(CoverLink__ECoverType*)&params[4] = Type;
			*(CoverLink__ECoverAction*)&params[5] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[8];
		}
		bool IsExposedTo(int SlotIdx, CoverLink__CoverInfo ChkSlot, float& out_ExposedScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13235);
			byte params[20] = { NULL };
			*(int*)params = SlotIdx;
			*(CoverLink__CoverInfo*)&params[4] = ChkSlot;
			*(float*)&params[12] = out_ExposedScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ExposedScale = *(float*)&params[12];
			return *(bool*)&params[16];
		}
		void SetInvalidUntil(int SlotIdx, float TimeToBecomeValid)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13240);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			*(float*)&params[4] = TimeToBecomeValid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Claim(class Pawn* NewClaim, int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13244);
			byte params[12] = { NULL };
			*(class Pawn**)params = NewClaim;
			*(int*)&params[4] = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnClaim(class Pawn* OldClaim, int SlotIdx, bool bUnclaimAll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13255);
			byte params[16] = { NULL };
			*(class Pawn**)params = OldClaim;
			*(int*)&params[4] = SlotIdx;
			*(bool*)&params[8] = bUnclaimAll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IsValidClaim(class Pawn* ChkClaim, int SlotIdx, bool bSkipTeamCheck, bool bSkipOverlapCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13263);
			byte params[20] = { NULL };
			*(class Pawn**)params = ChkClaim;
			*(int*)&params[4] = SlotIdx;
			*(bool*)&params[8] = bSkipTeamCheck;
			*(bool*)&params[12] = bSkipOverlapCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsValidClaimBetween(class Pawn* ChkClaim, int StartSlotIdx, int EndSlotIdx, bool bSkipTeamCheck, bool bSkipOverlapCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13269);
			byte params[24] = { NULL };
			*(class Pawn**)params = ChkClaim;
			*(int*)&params[4] = StartSlotIdx;
			*(int*)&params[8] = EndSlotIdx;
			*(bool*)&params[12] = bSkipTeamCheck;
			*(bool*)&params[16] = bSkipOverlapCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool IsStationarySlot(int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13276);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsEdgeSlot(int SlotIdx, bool bIgnoreLeans)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13280);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bIgnoreLeans;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool FindSlots(Vector CheckLocation, float MaxDistance, int& LeftSlotIdx, int& RightSlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13281);
			byte params[28] = { NULL };
			*(Vector*)params = CheckLocation;
			*(float*)&params[12] = MaxDistance;
			*(int*)&params[16] = LeftSlotIdx;
			*(int*)&params[20] = RightSlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			LeftSlotIdx = *(int*)&params[16];
			RightSlotIdx = *(int*)&params[20];
			return *(bool*)&params[24];
		}
		bool IsLeftEdgeSlot(int SlotIdx, bool bIgnoreLeans)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13290);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bIgnoreLeans;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsRightEdgeSlot(int SlotIdx, bool bIgnoreLeans)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13294);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bIgnoreLeans;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GetSlotIdxToLeft(int SlotIdx, int Cnt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13298);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(int*)&params[4] = Cnt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetSlotIdxToRight(int SlotIdx, int Cnt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13302);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(int*)&params[4] = Cnt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool AllowRightTransition(int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13306);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowLeftTransition(int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13310);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetFireLinkTo(int SlotIdx, CoverLink__CoverInfo ChkCover, CoverLink__ECoverAction ChkAction, CoverLink__ECoverType ChkType, int& out_FireLinkIdx, ScriptArray<int>& out_Items)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13314);
			byte params[34] = { NULL };
			*(int*)params = SlotIdx;
			*(CoverLink__CoverInfo*)&params[4] = ChkCover;
			*(CoverLink__ECoverAction*)&params[12] = ChkAction;
			*(CoverLink__ECoverType*)&params[13] = ChkType;
			*(int*)&params[16] = out_FireLinkIdx;
			*(ScriptArray<int>*)&params[20] = out_Items;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_FireLinkIdx = *(int*)&params[16];
			out_Items = *(ScriptArray<int>*)&params[20];
			return *(bool*)&params[32];
		}
		bool HasFireLinkTo(int SlotIdx, CoverLink__CoverInfo ChkCover, bool bAllowFallbackLinks)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13323);
			byte params[20] = { NULL };
			*(int*)params = SlotIdx;
			*(CoverLink__CoverInfo*)&params[4] = ChkCover;
			*(bool*)&params[12] = bAllowFallbackLinks;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void GetSlotActions(int SlotIdx, ScriptArray<CoverLink__ECoverAction>& Actions)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13328);
			byte params[16] = { NULL };
			*(int*)params = SlotIdx;
			*(ScriptArray<CoverLink__ECoverAction>*)&params[4] = Actions;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actions = *(ScriptArray<CoverLink__ECoverAction>*)&params[4];
		}
		void SetDisabled(bool bNewDisabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13332);
			byte params[4] = { NULL };
			*(bool*)params = bNewDisabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSlotEnabled(int SlotIdx, bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13339);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifySlotOwnerCoverDisabled(int SlotIdx, bool bAIOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13342);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bAIOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSlotPlayerOnly(int SlotIdx, bool bInPlayerOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13347);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bInPlayerOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnModifyCover(class SeqAct_ModifyCover* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13350);
			byte params[4] = { NULL };
			*(class SeqAct_ModifyCover**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AutoAdjustSlot(int SlotIdx, bool bOnlyCheckLeans)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13358);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bOnlyCheckLeans;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsEnabled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13364);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13366);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateCheckpointRecord(NavigationPoint__CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13369);
			byte params[4] = { NULL };
			*(NavigationPoint__CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(NavigationPoint__CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(NavigationPoint__CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13371);
			byte params[4] = { NULL };
			*(NavigationPoint__CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(NavigationPoint__CheckpointRecord*)params;
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13374);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetSwatTurnTarget(int SlotIdx, int Direction, CoverLink__CoverInfo& out_Info)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13375);
			byte params[20] = { NULL };
			*(int*)params = SlotIdx;
			*(int*)&params[4] = Direction;
			*(CoverLink__CoverInfo*)&params[8] = out_Info;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Info = *(CoverLink__CoverInfo*)&params[8];
			return *(bool*)&params[16];
		}
		void BreakFracturedMeshes(Vector Origin, float Radius, float RBStrength, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13380);
			byte params[24] = { NULL };
			*(Vector*)params = Origin;
			*(float*)&params[12] = Radius;
			*(float*)&params[16] = RBStrength;
			*(ScriptClass**)&params[20] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int AddCoverSlot(Vector SlotLocation, Rotator SlotRotation, int SlotIdx, bool bForceSlotUpdate, class Scout* Scout)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13392);
			byte params[40] = { NULL };
			*(Vector*)params = SlotLocation;
			*(Rotator*)&params[12] = SlotRotation;
			*(int*)&params[24] = SlotIdx;
			*(bool*)&params[28] = bForceSlotUpdate;
			*(class Scout**)&params[32] = Scout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[36];
		}
		ScriptString* GetDebugString(int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13399);
			byte params[16] = { NULL };
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		CoverLink__ECoverLocationDescription GetLocationDescription(int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13402);
			byte params[5] = { NULL };
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(CoverLink__ECoverLocationDescription*)&params[4];
		}
		ScriptString* GetDebugAbbrev()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13405);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
	const float CoverLink::COVERLINK_DangerDist = 1536.f;
	const float CoverLink::COVERLINK_EdgeExposureDot = 0.85f;
	const float CoverLink::COVERLINK_EdgeCheckDot = 0.25f;
	const float CoverLink::COVERLINK_ExposureDot = 0.4f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
