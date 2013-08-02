#pragma once
namespace UnrealScript
{
	class PrimitiveComponent;
}
#include "Core.Object.BoxSphereBounds.h"
#include "Core.Object.Matrix.h"
#include "Core.Object.Pointer.h"
#include "Engine.ActorComponent.h"
#include "Engine.LightComponent.LightingChannelContainer.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.PrimitiveComponent.ERBCollisionChannel.h"
#include "Engine.PrimitiveComponent.ERadialImpulseFalloff.h"
#include "Engine.PrimitiveComponent.GJKResult.h"
#include "Engine.PrimitiveComponent.MaterialViewRelevance.h"
#include "Engine.PrimitiveComponent.RBCollisionChannelContainer.h"
#include "Engine.RB_BodyInstance.h"
#include "Engine.Scene.EDetailMode.h"
#include "Engine.Scene.ESceneDepthPriorityGroup.h"
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
	class PrimitiveComponent : public ActorComponent
	{
	public:
		typedef PrimitiveComponent__GJKResult GJKResult;
		typedef PrimitiveComponent__ERBCollisionChannel ERBCollisionChannel;
		typedef PrimitiveComponent__ERadialImpulseFalloff ERadialImpulseFalloff;
		typedef PrimitiveComponent__RBCollisionChannelContainer RBCollisionChannelContainer;
		typedef PrimitiveComponent__MaterialViewRelevance MaterialViewRelevance;
		ADD_STRUCT(int, Tag, 88)
		ADD_STRUCT(Object__Matrix, LocalToWorld, 160)
		ADD_STRUCT(int, ThreadTag, 92)
		ADD_STRUCT(Object__BoxSphereBounds, Bounds, 120)
		ADD_STRUCT(Object__Pointer, SceneInfo, 148)
		ADD_STRUCT(int, DetachFence, 152)
		ADD_STRUCT(float, LocalToWorldDeterminant, 156)
		ADD_STRUCT(int, MotionBlurInfoIndex, 224)
		ADD_STRUCT(ScriptArray<Object__Pointer>, DecalList, 228)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, DecalsToReattach, 240)
		ADD_STRUCT(float, MinDrawDistance, 276)
		ADD_STRUCT(float, MassiveLODDistance, 280)
		ADD_STRUCT(float, MaxDrawDistance, 284)
		ADD_STRUCT(float, CachedMaxDrawDistance, 288)
		ADD_STRUCT(float, CullDistance, 292)
		ADD_STRUCT(float, CachedCullDistance, 296)
		ADD_STRUCT(Scene__ESceneDepthPriorityGroup, DepthPriorityGroup, 300)
		ADD_STRUCT(Scene__ESceneDepthPriorityGroup, ViewOwnerDepthPriorityGroup, 301)
		ADD_STRUCT(Scene__EDetailMode, DetailMode, 302)
		ADD_STRUCT(PrimitiveComponent__ERBCollisionChannel, RBChannel, 303)
		ADD_STRUCT(byte, RBDominanceGroup, 304)
		ADD_STRUCT(byte, PreviewEnvironmentShadowing, 305)
		ADD_STRUCT(float, MotionBlurScale, 308)
		ADD_BOOL(bUseViewOwnerDepthPriorityGroup, 312, 0x1)
		ADD_BOOL(bAllowCullDistanceVolume, 312, 0x2)
		ADD_BOOL(HiddenGame, 312, 0x4)
		ADD_BOOL(HiddenEditor, 312, 0x8)
		ADD_BOOL(bOwnerNoSee, 312, 0x10)
		ADD_BOOL(bOnlyOwnerSee, 312, 0x20)
		ADD_BOOL(bIgnoreOwnerHidden, 312, 0x40)
		ADD_BOOL(bUseAsOccluder, 312, 0x80)
		ADD_BOOL(bAllowApproximateOcclusion, 312, 0x100)
		ADD_BOOL(bFirstFrameOcclusion, 312, 0x200)
		ADD_BOOL(bIgnoreNearPlaneIntersection, 312, 0x400)
		ADD_BOOL(bSelectable, 312, 0x800)
		ADD_BOOL(bForceMipStreaming, 312, 0x1000)
		ADD_BOOL(bAcceptsDecals, 312, 0x2000)
		ADD_BOOL(bAcceptsDecalsDuringGameplay, 312, 0x4000)
		ADD_BOOL(bAcceptsStaticDecals, 312, 0x8000)
		ADD_BOOL(bAcceptsDynamicDecals, 312, 0x10000)
		ADD_BOOL(bIsRefreshingDecals, 312, 0x20000)
		ADD_BOOL(bAllowDecalAutomaticReAttach, 312, 0x40000)
		ADD_BOOL(CastShadow, 312, 0x80000)
		ADD_BOOL(bForceDirectLightMap, 312, 0x100000)
		ADD_BOOL(bCastDynamicShadow, 312, 0x200000)
		ADD_BOOL(bUsesPlayerShadowFadeResolution, 312, 0x400000)
		ADD_BOOL(bSelfShadowOnly, 312, 0x800000)
		ADD_BOOL(bAcceptsDynamicDominantLightShadows, 312, 0x1000000)
		ADD_BOOL(bCastHiddenShadow, 312, 0x2000000)
		ADD_BOOL(bCastShadowAsTwoSided, 312, 0x4000000)
		ADD_BOOL(bAcceptsLights, 312, 0x8000000)
		ADD_BOOL(bAcceptsDynamicLights, 312, 0x10000000)
		ADD_BOOL(bUseOnePassLightingOnTranslucency, 312, 0x20000000)
		ADD_BOOL(bUsePrecomputedShadows, 312, 0x40000000)
		ADD_BOOL(bHasExplicitShadowParent, 312, 0x80000000)
		ADD_BOOL(bCullModulatedShadowOnBackfaces, 316, 0x1)
		ADD_BOOL(bCullModulatedShadowOnEmissive, 316, 0x2)
		ADD_BOOL(bAllowAmbientOcclusion, 316, 0x4)
		ADD_BOOL(CollideActors, 316, 0x8)
		ADD_BOOL(AlwaysCheckCollision, 316, 0x10)
		ADD_BOOL(BlockActors, 316, 0x20)
		ADD_BOOL(BlockZeroExtent, 316, 0x40)
		ADD_BOOL(BlockNonZeroExtent, 316, 0x80)
		ADD_BOOL(CanBlockCamera, 316, 0x100)
		ADD_BOOL(BlockRigidBody, 316, 0x200)
		ADD_BOOL(bDisableAllRigidBody, 316, 0x400)
		ADD_BOOL(bSkipRBGeomCreation, 316, 0x800)
		ADD_BOOL(bNotifyRigidBodyCollision, 316, 0x1000)
		ADD_BOOL(bFluidDrain, 316, 0x2000)
		ADD_BOOL(bFluidTwoWay, 316, 0x4000)
		ADD_BOOL(bIgnoreRadialImpulse, 316, 0x8000)
		ADD_BOOL(bIgnoreRadialForce, 316, 0x10000)
		ADD_BOOL(bIgnoreForceField, 316, 0x20000)
		ADD_BOOL(bUseCompartment, 316, 0x40000)
		ADD_BOOL(AlwaysLoadOnClient, 316, 0x80000)
		ADD_BOOL(AlwaysLoadOnServer, 316, 0x100000)
		ADD_BOOL(bIgnoreHiddenActorsMembership, 316, 0x200000)
		ADD_BOOL(AbsoluteTranslation, 316, 0x400000)
		ADD_BOOL(AbsoluteRotation, 316, 0x800000)
		ADD_BOOL(AbsoluteScale, 316, 0x1000000)
		ADD_BOOL(bAllowShadowFade, 316, 0x2000000)
		ADD_BOOL(bWasSNFiltered, 316, 0x4000000)
		ADD_STRUCT(ScriptArray<int>, OctreeNodes, 320)
		ADD_STRUCT(int, TranslucencySortPriority, 332)
		ADD_STRUCT(int, VisibilityId, 336)
		ADD_STRUCT(LightComponent__LightingChannelContainer, LightingChannels, 340)
		ADD_STRUCT(PrimitiveComponent__RBCollisionChannelContainer, RBCollideWithChannels, 344)
		ADD_OBJECT(PhysicalMaterial, PhysMaterialOverride, 348)
		ADD_OBJECT(RB_BodyInstance, BodyInstance, 352)
		ADD_STRUCT(Object__Matrix, CachedParentToWorld, 368)
		ADD_STRUCT(Vector, Translation, 432)
		ADD_STRUCT(Rotator, Rotation, 444)
		ADD_STRUCT(float, Scale, 456)
		ADD_STRUCT(Vector, Scale3D, 460)
		ADD_STRUCT(float, BoundsScale, 472)
		ADD_STRUCT(float, LastSubmitTime, 476)
		ADD_STRUCT(float, LastRenderTime, 480)
		ADD_STRUCT(float, ScriptRigidBodyCollisionThreshold, 484)
		void SetBlockRigidBody(bool bNewBlockRigidBody)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4339);
			byte params[4] = { NULL };
			*(bool*)params = bNewBlockRigidBody;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBLinearVelocity(Vector NewVel, bool bAddToCurrent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4385);
			byte params[16] = { NULL };
			*(Vector*)params = NewVel;
			*(bool*)&params[12] = bAddToCurrent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddImpulse(Vector Impulse, Vector Position, ScriptName BoneName, bool bVelChange)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4749);
			byte params[36] = { NULL };
			*(Vector*)params = Impulse;
			*(Vector*)&params[12] = Position;
			*(ScriptName*)&params[24] = BoneName;
			*(bool*)&params[32] = bVelChange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRadialImpulse(Vector Origin, float Radius, float Strength, PrimitiveComponent__ERadialImpulseFalloff Falloff, bool bVelChange)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4754);
			byte params[25] = { NULL };
			*(Vector*)params = Origin;
			*(float*)&params[12] = Radius;
			*(float*)&params[16] = Strength;
			*(PrimitiveComponent__ERadialImpulseFalloff*)&params[20] = Falloff;
			*(bool*)&params[24] = bVelChange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddForce(Vector Force, Vector Position, ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4760);
			byte params[32] = { NULL };
			*(Vector*)params = Force;
			*(Vector*)&params[12] = Position;
			*(ScriptName*)&params[24] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRadialForce(Vector Origin, float Radius, float Strength, PrimitiveComponent__ERadialImpulseFalloff Falloff)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4764);
			byte params[21] = { NULL };
			*(Vector*)params = Origin;
			*(float*)&params[12] = Radius;
			*(float*)&params[16] = Strength;
			*(PrimitiveComponent__ERadialImpulseFalloff*)&params[20] = Falloff;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddTorque(Vector Torque, ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4769);
			byte params[20] = { NULL };
			*(Vector*)params = Torque;
			*(ScriptName*)&params[12] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBAngularVelocity(Vector NewAngVel, bool bAddToCurrent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4774);
			byte params[16] = { NULL };
			*(Vector*)params = NewAngVel;
			*(bool*)&params[12] = bAddToCurrent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RetardRBLinearVelocity(Vector RetardDir, float VelScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4777);
			byte params[16] = { NULL };
			*(Vector*)params = RetardDir;
			*(float*)&params[12] = VelScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBPosition(Vector NewPos, ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4780);
			byte params[20] = { NULL };
			*(Vector*)params = NewPos;
			*(ScriptName*)&params[12] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBRotation(Rotator NewRot, ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4783);
			byte params[20] = { NULL };
			*(Rotator*)params = NewRot;
			*(ScriptName*)&params[12] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WakeRigidBody(ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4786);
			byte params[8] = { NULL };
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PutRigidBodyToSleep(ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4788);
			byte params[8] = { NULL };
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RigidBodyIsAwake(ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4790);
			byte params[12] = { NULL };
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SetRBCollidesWithChannel(PrimitiveComponent__ERBCollisionChannel Channel, bool bNewCollides)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4794);
			byte params[5] = { NULL };
			*(PrimitiveComponent__ERBCollisionChannel*)params = Channel;
			*(bool*)&params[4] = bNewCollides;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBCollisionChannels(PrimitiveComponent__RBCollisionChannelContainer Channels)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4797);
			byte params[4] = { NULL };
			*(PrimitiveComponent__RBCollisionChannelContainer*)params = Channels;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBChannel(PrimitiveComponent__ERBCollisionChannel Channel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4818);
			byte params[1] = { NULL };
			*(PrimitiveComponent__ERBCollisionChannel*)params = Channel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetNotifyRigidBodyCollision(bool bNewNotifyRigidBodyCollision)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4820);
			byte params[4] = { NULL };
			*(bool*)params = bNewNotifyRigidBodyCollision;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitRBPhys()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4822);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPhysMaterialOverride(class PhysicalMaterial* NewPhysMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4823);
			byte params[4] = { NULL };
			*(class PhysicalMaterial**)params = NewPhysMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class RB_BodyInstance* GetRootBodyInstance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4825);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class RB_BodyInstance**)params;
		}
		void SetRBDominanceGroup(byte InDomGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4827);
			byte params[1] = { NULL };
			*params = InDomGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldComponentAddToScene()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4829);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetHidden(bool NewHidden)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4831);
			byte params[4] = { NULL };
			*(bool*)params = NewHidden;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOwnerNoSee(bool bNewOwnerNoSee)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4833);
			byte params[4] = { NULL };
			*(bool*)params = bNewOwnerNoSee;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOnlyOwnerSee(bool bNewOnlyOwnerSee)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4835);
			byte params[4] = { NULL };
			*(bool*)params = bNewOnlyOwnerSee;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetIgnoreOwnerHidden(bool bNewIgnoreOwnerHidden)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4837);
			byte params[4] = { NULL };
			*(bool*)params = bNewIgnoreOwnerHidden;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetShadowParent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewShadowParent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4839);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = NewShadowParent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLightEnvironment(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewLightEnvironment)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4841);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = NewLightEnvironment;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCullDistance(float NewCullDistance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4843);
			byte params[4] = { NULL };
			*(float*)params = NewCullDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLightingChannels(LightComponent__LightingChannelContainer NewLightingChannels)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4873);
			byte params[4] = { NULL };
			*(LightComponent__LightingChannelContainer*)params = NewLightingChannels;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDepthPriorityGroup(Scene__ESceneDepthPriorityGroup NewDepthPriorityGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4875);
			byte params[1] = { NULL };
			*(Scene__ESceneDepthPriorityGroup*)params = NewDepthPriorityGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetViewOwnerDepthPriorityGroup(bool bNewUseViewOwnerDepthPriorityGroup, Scene__ESceneDepthPriorityGroup NewViewOwnerDepthPriorityGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4877);
			byte params[5] = { NULL };
			*(bool*)params = bNewUseViewOwnerDepthPriorityGroup;
			*(Scene__ESceneDepthPriorityGroup*)&params[4] = NewViewOwnerDepthPriorityGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTraceBlocking(bool NewBlockZeroExtent, bool NewBlockNonZeroExtent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4880);
			byte params[8] = { NULL };
			*(bool*)params = NewBlockZeroExtent;
			*(bool*)&params[4] = NewBlockNonZeroExtent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActorCollision(bool NewCollideActors, bool NewBlockActors, bool NewAlwaysCheckCollision)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4883);
			byte params[12] = { NULL };
			*(bool*)params = NewCollideActors;
			*(bool*)&params[4] = NewBlockActors;
			*(bool*)&params[8] = NewAlwaysCheckCollision;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTranslation(Vector NewTranslation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4887);
			byte params[12] = { NULL };
			*(Vector*)params = NewTranslation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4889);
			byte params[12] = { NULL };
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScale(float NewScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4891);
			byte params[4] = { NULL };
			*(float*)params = NewScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScale3D(Vector NewScale3D)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4893);
			byte params[12] = { NULL };
			*(Vector*)params = NewScale3D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAbsolute(bool NewAbsoluteTranslation, bool NewAbsoluteRotation, bool NewAbsoluteScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4895);
			byte params[12] = { NULL };
			*(bool*)params = NewAbsoluteTranslation;
			*(bool*)&params[4] = NewAbsoluteRotation;
			*(bool*)&params[8] = NewAbsoluteScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetPosition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4899);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		Rotator GetRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4903);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)params;
		}
		PrimitiveComponent__GJKResult ClosestPointOnComponentToPoint(Vector& POI, Vector& Extent, Vector& OutPointA, Vector& OutPointB)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4905);
			byte params[49] = { NULL };
			*(Vector*)params = POI;
			*(Vector*)&params[12] = Extent;
			*(Vector*)&params[24] = OutPointA;
			*(Vector*)&params[36] = OutPointB;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			POI = *(Vector*)params;
			Extent = *(Vector*)&params[12];
			OutPointA = *(Vector*)&params[24];
			OutPointB = *(Vector*)&params[36];
			return *(PrimitiveComponent__GJKResult*)&params[48];
		}
		PrimitiveComponent__GJKResult ClosestPointOnComponentToComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*& OtherComponent, Vector& PointOnComponentA, Vector& PointOnComponentB)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4911);
			byte params[29] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = OtherComponent;
			*(Vector*)&params[4] = PointOnComponentA;
			*(Vector*)&params[16] = PointOnComponentB;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OtherComponent = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params;
			PointOnComponentA = *(Vector*)&params[4];
			PointOnComponentB = *(Vector*)&params[16];
			return *(PrimitiveComponent__GJKResult*)&params[28];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
