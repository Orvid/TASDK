#pragma once
namespace UnrealScript
{
	class TrMainMenuMeshInfo;
}
#include "Core.Object.h"
#include "TribesGame.TrMainMenuMeshInfo.ParticleSystemInfo.h"
#include "TribesGame.TrObject.PaperDollInfo.h"
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
	class TrMainMenuMeshInfo : public Object
	{
	public:
		typedef TrMainMenuMeshInfo__ParticleSystemInfo ParticleSystemInfo;
		ADD_STRUCT(ScriptArray<class TrMainMenuMeshInfo*>, Children, 116)
		ADD_STRUCT(ScriptArray<TrMainMenuMeshInfo__ParticleSystemInfo>, AttachedParticleSystems, 136)
		ADD_STRUCT(ScriptName, ParentSocketName, 128)
		ADD_STRUCT(TrObject__PaperDollInfo, MeshInfo, 60)
		void PreloadTextures(float ForceDuration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98700);
			byte params[4] = { NULL };
			*(float*)params = ForceDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
