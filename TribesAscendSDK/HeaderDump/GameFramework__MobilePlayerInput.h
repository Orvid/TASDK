#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.MobilePlayerInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.MobilePlayerInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobilePlayerInput." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobilePlayerInput : public PlayerInput
	{
	public:
		ADD_STRUCT(::VectorProperty, DeviceAccelerometerRawData, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bDeviceHasGyroscope, 0x10)
		ADD_STRUCT(::VectorProperty, DeviceGyroRawData, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DeviceMotionAttitude, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DeviceMotionRotationRate, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DeviceMotionGravity, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DeviceMotionAcceleration, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobilePlayerInput.TouchData' for the property named 'Touches'!
		ADD_VAR(::FloatProperty, MobileYaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileYawCenter, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileYawMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobilePitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobilePitchCenter, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobilePitchMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileInactiveTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NativeDebugString, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZoneTimeout, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileTapRepeatTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileMinHoldForTap, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileDoubleTapTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileYawDeadzoneSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobilePitchDeadzoneSize, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDeviceHasAccelerometer, 0x20)
		ADD_VAR(::BoolProperty, bFakeMobileTouches, 0x8)
		ADD_VAR(::BoolProperty, bDisableTouchInput, 0x4)
		ADD_VAR(::BoolProperty, bAllowTouchesInCinematic, 0x2)
		ADD_VAR(::BoolProperty, bSupportsAccelerometer, 0x1)
		ADD_VAR(::IntProperty, CurrentMobileGroup, 0xFFFFFFFF)
		ADD_OBJECT(MobileMenuObject, InteractiveObject)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
