#pragma once
#include "Engine.SkelControlBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControlLookAt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SkelControlLookAt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControlLookAt : public SkelControlBase
	{
	public:
		ADD_VAR(::IntProperty, ControlBoneIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCalcTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, BaseBonePos, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, BaseLookDir, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LimitLookDir, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookAtAlphaBlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookAtAlphaTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookAtAlpha, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AllowRotationOtherBoneName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeadZoneAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OuterMaxAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxAngle, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ActorSpaceLookAtTarget, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, DesiredTargetLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetLocationInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAllowRotationZ, 0x400)
		ADD_VAR(::BoolProperty, bAllowRotationY, 0x200)
		ADD_VAR(::BoolProperty, bAllowRotationX, 0x100)
		ADD_VAR(::BoolProperty, bShowLimit, 0x80)
		ADD_VAR(::BoolProperty, bNotifyBeyondLimit, 0x40)
		ADD_VAR(::BoolProperty, bDisableBeyondLimit, 0x20)
		ADD_VAR(::BoolProperty, bLimitBasedOnRefPose, 0x10)
		ADD_VAR(::BoolProperty, bEnableLimit, 0x8)
		ADD_VAR(::BoolProperty, bInvertUpAxis, 0x4)
		ADD_VAR(::BoolProperty, bDefineUpAxis, 0x2)
		ADD_VAR(::BoolProperty, bInvertLookAtAxis, 0x1)
		ADD_VAR(::NameProperty, TargetSpaceBoneName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AllowRotationSpace, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, UpAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LookAtAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TargetLocationSpace, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetLocation, 0xFFFFFFFF)
		void SetTargetLocation(Vector NewTargetLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlLookAt.SetTargetLocation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewTargetLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InterpolateTargetLocation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlLookAt.InterpolateTargetLocation");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLookAtAlpha(float DesiredAlpha, float DesiredBlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlLookAt.SetLookAtAlpha");
			byte* params = (byte*)malloc(8);
			*(float*)params = DesiredAlpha;
			*(float*)(params + 4) = DesiredBlendTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanLookAtPoint(Vector PointLoc, bool bDrawDebugInfo, bool bDebugUsePersistentLines, bool bDebugFlushLinesFirst)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlLookAt.CanLookAtPoint");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = PointLoc;
			*(bool*)(params + 12) = bDrawDebugInfo;
			*(bool*)(params + 16) = bDebugUsePersistentLines;
			*(bool*)(params + 20) = bDebugFlushLinesFirst;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
