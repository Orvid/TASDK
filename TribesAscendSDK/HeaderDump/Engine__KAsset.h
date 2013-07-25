#pragma once
#include "Engine__SeqAct_AttachToActor.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__PhysicsAsset.h"
#include "Engine__Controller.h"
#include "Engine__SeqAct_Teleport.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.KAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.KAsset." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class KAsset : public Actor
	{
	public:
		ADD_OBJECT(PhysicsAsset, ReplicatedPhysAsset)
		ADD_OBJECT(SkeletalMesh, ReplicatedMesh)
		ADD_VAR(::BoolProperty, bBlockPawns, 0x4)
		ADD_VAR(::BoolProperty, bWakeOnLevelStart, 0x2)
		ADD_VAR(::BoolProperty, bDamageAppliesImpulse, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KAsset.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMeshAndPhysAsset(class SkeletalMesh* NewMesh, class PhysicsAsset* NewPhysAsset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KAsset.SetMeshAndPhysAsset");
			byte* params = (byte*)malloc(8);
			*(class SkeletalMesh**)params = NewMesh;
			*(class PhysicsAsset**)(params + 4) = NewPhysAsset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KAsset.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KAsset.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KAsset.TakeRadiusDamage");
			byte* params = (byte*)malloc(44);
			*(class Controller**)params = InstigatedBy;
			*(float*)(params + 4) = BaseDamage;
			*(float*)(params + 8) = DamageRadius;
			*(ScriptClass**)(params + 12) = DamageType;
			*(float*)(params + 16) = Momentum;
			*(Vector*)(params + 20) = HurtOrigin;
			*(bool*)(params + 32) = bFullDamage;
			*(class Actor**)(params + 36) = DamageCauser;
			*(float*)(params + 40) = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KAsset.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnTeleport(class SeqAct_Teleport* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KAsset.OnTeleport");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Teleport**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoKismetAttachment(class Actor* Attachment, class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KAsset.DoKismetAttachment");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Attachment;
			*(class SeqAct_AttachToActor**)(params + 4) = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
