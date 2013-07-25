#pragma once
#include "Engine__PhysicalMaterialPropertyBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPhysicalMaterialProperty." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTPhysicalMaterialProperty : public PhysicalMaterialPropertyBase
	{
	public:
		ADD_VAR(::NameProperty, MaterialType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
