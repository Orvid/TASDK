#pragma once
#include "Engine__ParticleModuleTypeDataBase.h"
#include "Engine__ApexGenericAsset.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ParticleModuleTypeDataApex." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ParticleModuleTypeDataApex : public ParticleModuleTypeDataBase
	{
	public:
		ADD_OBJECT(ApexGenericAsset, ApexEmitter)
		ADD_OBJECT(ApexGenericAsset, ApexIOFX)
	};
}
#undef ADD_OBJECT
