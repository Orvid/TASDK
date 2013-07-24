#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleTypeDataMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ParticleModuleTypeDataMesh." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ParticleModuleTypeDataMesh : public ParticleModuleTypeDataBase
	{
	public:
		ADD_VAR(::FloatProperty, Yaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Roll, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Pitch, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CameraFacingOption, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CameraFacingUpAxisOption, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AxisLockOption, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MeshAlignment, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, Mesh)
		ADD_VAR(::BoolProperty, bApplyParticleRotationAsSpin, 0x20)
		ADD_VAR(::BoolProperty, bCameraFacing, 0x10)
		ADD_VAR(::BoolProperty, bOverrideMaterial, 0x8)
		ADD_VAR(::BoolProperty, bAllowMotionBlur, 0x4)
		ADD_VAR(::BoolProperty, DoCollisions, 0x2)
		ADD_VAR(::BoolProperty, CastShadows, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
