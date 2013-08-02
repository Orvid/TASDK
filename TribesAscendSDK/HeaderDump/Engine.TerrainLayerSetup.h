#pragma once
namespace UnrealScript
{
	class TerrainLayerSetup;
}
#include "Core.Object.h"
#include "Engine.TerrainLayerSetup.FilterLimit.h"
#include "Engine.TerrainLayerSetup.TerrainFilteredMaterial.h"
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
	class TerrainLayerSetup : public Object
	{
	public:
		typedef TerrainLayerSetup__TerrainFilteredMaterial TerrainFilteredMaterial;
		typedef TerrainLayerSetup__FilterLimit FilterLimit;
		ADD_STRUCT(ScriptArray<TerrainLayerSetup__TerrainFilteredMaterial>, Materials, 60)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27917);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
