#pragma once
namespace UnrealScript
{
	class ApexGenericAsset;
}
#include "Core.Object.Pointer.h"
#include "Engine.ApexAsset.h"
#include "Engine.MaterialInterface.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ApexGenericAsset : public ApexAsset
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, Materials, 112)
		ADD_STRUCT(Object__Pointer, MApexAsset, 108)
	};
}
#undef ADD_STRUCT
