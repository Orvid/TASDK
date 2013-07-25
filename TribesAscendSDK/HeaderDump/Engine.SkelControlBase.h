#pragma once
#include "Engine.AnimObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControlBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SkelControlBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SkelControlBase : public AnimObject
	{
	public:
		ADD_VAR(::IntProperty, ControlPosY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ControlPosX, 0xFFFFFFFF)
		ADD_OBJECT(SkelControlBase, NextControl)
		ADD_VAR(::IntProperty, IgnoreAtOrAboveLOD, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ControlTickTag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoneScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AnimMetaDataUpdateTag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimMetadataWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StrengthTarget, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableEaseInOut, 0x80)
		ADD_VAR(::BoolProperty, bShouldTickInScript, 0x40)
		ADD_VAR(::BoolProperty, bIgnoreWhenNotRendered, 0x20)
		ADD_VAR(::BoolProperty, bPropagateSetActive, 0x10)
		ADD_VAR(::BoolProperty, bControlledByAnimMetada, 0x8)
		ADD_VAR(::BoolProperty, bInitializedCachedNodeList, 0x4)
		ADD_VAR(::BoolProperty, bSetStrengthFromAnimNode, 0x2)
		ADD_VAR(::BoolProperty, bPostPhysicsController, 0x1)
		ADD_VAR(::ByteProperty, BlendType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ControlStrength, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ControlName, 0xFFFFFFFF)
		void SetSkelControlActive(bool bInActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlBase.SetSkelControlActive");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSkelControlStrength(float NewStrength, float InBlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlBase.SetSkelControlStrength");
			byte* params = (byte*)malloc(8);
			*(float*)params = NewStrength;
			*(float*)(params + 4) = InBlendTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TickSkelControl(float DeltaTime, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlBase.TickSkelControl");
			byte* params = (byte*)malloc(8);
			*(float*)params = DeltaTime;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
