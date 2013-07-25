#pragma once
#include "Engine__MorphNodeWeightBase.h"
#include "Engine__MaterialInstanceConstant.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MorphNodeWeightByBoneAngle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MorphNodeWeightByBoneAngle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MorphNodeWeightByBoneAngle : public MorphNodeWeightBase
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, MaterialInstanceConstant)
		ADD_VAR(::NameProperty, ScalarParameterName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaterialSlotId, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AngleBoneName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bControlMaterialParameter, 0x4)
		ADD_VAR(::BoolProperty, bInvertAngleBoneAxis, 0x2)
		ADD_VAR(::BoolProperty, bInvertBaseBoneAxis, 0x1)
		ADD_VAR(::ByteProperty, AngleBoneAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, BaseBoneAxis, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BaseBoneName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NodeWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Angle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
