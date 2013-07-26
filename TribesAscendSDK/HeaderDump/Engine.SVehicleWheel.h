#pragma once
#include "Engine.SkelControlWheel.h"
#include "Core.Component.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Pointer.h"
#include "Engine.ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SVehicleWheel." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SVehicleWheel." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SVehicleWheel." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SVehicleWheel : public Component
	{
	public:
		ADD_OBJECT(SkelControlWheel, WheelControl)
		ADD_VAR(::NameProperty, SkelControlName, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, WheelPosition, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ContactForce, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LongSlipRatio, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LatSlipAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MotorTorque, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpinVel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LongImpulse, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LongDirection, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LatImpulse, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LatDirection, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SlipParticleParamName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, WheelPSCClass)
		ADD_VAR(::IntProperty, WheelMaterialIndex, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, WheelShape, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SuspensionPosition, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredSuspensionPosition, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ContactNormal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ParkedSlipFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HandbrakeLatSlipFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HandbrakeLongSlipFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LatSlipFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LongSlipFactor, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Side, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, WheelParticleSystem)
		ADD_VAR(::FloatProperty, SuspensionSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SuspensionTravel, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, BoneOffset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SteerFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWheelOnGround, 0x20)
		ADD_VAR(::BoolProperty, bIsSquealing, 0x10)
		ADD_VAR(::BoolProperty, bCollidesPawns, 0x8)
		ADD_VAR(::BoolProperty, bCollidesVehicles, 0x4)
		ADD_VAR(::BoolProperty, bHoverWheel, 0x2)
		ADD_VAR(::BoolProperty, bPoweredWheel, 0x1)
		ADD_VAR(::FloatProperty, ChassisTorque, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BrakeTorque, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Steer, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
