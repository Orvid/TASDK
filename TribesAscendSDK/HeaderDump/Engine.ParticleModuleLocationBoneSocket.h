#pragma once
namespace UnrealScript
{
	class ParticleModuleLocationBoneSocket;
}
#include "Engine.ParticleModuleLocationBase.h"
#include "Engine.ParticleModuleLocationBoneSocket.ELocationBoneSocketSelectionMethod.h"
#include "Engine.ParticleModuleLocationBoneSocket.ELocationBoneSocketSource.h"
#include "Engine.ParticleModuleLocationBoneSocket.LocationBoneSocketInfo.h"
#include "Engine.SkeletalMesh.h"
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
	class ParticleModuleLocationBoneSocket : public ParticleModuleLocationBase
	{
	public:
		typedef ParticleModuleLocationBoneSocket__ELocationBoneSocketSource ELocationBoneSocketSource;
		typedef ParticleModuleLocationBoneSocket__ELocationBoneSocketSelectionMethod ELocationBoneSocketSelectionMethod;
		typedef ParticleModuleLocationBoneSocket__LocationBoneSocketInfo LocationBoneSocketInfo;
		ADD_STRUCT(ScriptArray<ParticleModuleLocationBoneSocket__LocationBoneSocketInfo>, SourceLocations, 88)
		ADD_OBJECT(SkeletalMesh, EditorSkelMesh, 112)
		ADD_STRUCT(ScriptName, SkelMeshActorParamName, 104)
		ADD_BOOL(bOrientMeshEmitters, 100, 0x2)
		ADD_BOOL(bUpdatePositionEachFrame, 100, 0x1)
		ADD_STRUCT(Vector, UniversalOffset, 76)
		ADD_STRUCT(ParticleModuleLocationBoneSocket__ELocationBoneSocketSelectionMethod, SelectionMethod, 73)
		ADD_STRUCT(ParticleModuleLocationBoneSocket__ELocationBoneSocketSource, SourceType, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
