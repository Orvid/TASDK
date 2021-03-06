#pragma once
namespace UnrealScript
{
	class TestSplittingVolume;
}
#include "Core.Object.Pointer.h"
#include "Engine.Volume.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TestSplittingVolume : public Volume
	{
	public:
		ADD_STRUCT(Object__Pointer, VfTable_IInterface_NavMeshPathObject, 520)
	};
}
#undef ADD_STRUCT
