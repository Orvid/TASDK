#pragma once
namespace UnrealScript
{
	class ParticleModuleTypeDataMesh;
}
#include "Engine.ParticleModuleOrientationAxisLock.EParticleAxisLock.h"
#include "Engine.ParticleModuleTypeDataBase.h"
#include "Engine.ParticleModuleTypeDataMesh.EMeshCameraFacingOptions.h"
#include "Engine.ParticleModuleTypeDataMesh.EMeshCameraFacingUpAxis.h"
#include "Engine.ParticleModuleTypeDataMesh.EMeshScreenAlignment.h"
#include "Engine.StaticMesh.h"
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
	class ParticleModuleTypeDataMesh : public ParticleModuleTypeDataBase
	{
	public:
		typedef ParticleModuleTypeDataMesh__EMeshCameraFacingOptions EMeshCameraFacingOptions;
		typedef ParticleModuleTypeDataMesh__EMeshCameraFacingUpAxis EMeshCameraFacingUpAxis;
		typedef ParticleModuleTypeDataMesh__EMeshScreenAlignment EMeshScreenAlignment;
		ADD_STRUCT(float, Yaw, 92)
		ADD_STRUCT(float, Roll, 88)
		ADD_STRUCT(float, Pitch, 84)
		ADD_STRUCT(ParticleModuleTypeDataMesh__EMeshCameraFacingOptions, CameraFacingOption, 83)
		ADD_STRUCT(ParticleModuleTypeDataMesh__EMeshCameraFacingUpAxis, CameraFacingUpAxisOption, 82)
		ADD_STRUCT(ParticleModuleOrientationAxisLock__EParticleAxisLock, AxisLockOption, 81)
		ADD_STRUCT(ParticleModuleTypeDataMesh__EMeshScreenAlignment, MeshAlignment, 80)
		ADD_OBJECT(StaticMesh, Mesh, 72)
		ADD_BOOL(bApplyParticleRotationAsSpin, 76, 0x20)
		ADD_BOOL(bCameraFacing, 76, 0x10)
		ADD_BOOL(bOverrideMaterial, 76, 0x8)
		ADD_BOOL(bAllowMotionBlur, 76, 0x4)
		ADD_BOOL(DoCollisions, 76, 0x2)
		ADD_BOOL(CastShadows, 76, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
