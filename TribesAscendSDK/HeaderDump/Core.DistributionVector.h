#pragma once
namespace UnrealScript
{
	class DistributionVector;
}
#include "Core.Component.h"
#include "Core.DistributionVector.EDistributionVectorLockFlags.h"
#include "Core.DistributionVector.EDistributionVectorMirrorFlags.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Core.Object.Pointer.h"
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
namespace UnrealScript
{
	class DistributionVector : public Component
	{
	public:
		typedef DistributionVector__EDistributionVectorLockFlags EDistributionVectorLockFlags;
		typedef DistributionVector__EDistributionVectorMirrorFlags EDistributionVectorMirrorFlags;
		typedef DistributionVector__RawDistributionVector RawDistributionVector;
		ADD_BOOL(bIsDirty, 76, 0x2)
		ADD_BOOL(bCanBeBaked, 76, 0x1)
		ADD_STRUCT(Object__Pointer, VfTable_FCurveEdInterface, 72)
		Vector GetVectorValue(float F, int LastExtreme)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3442);
			byte params[20] = { NULL };
			*(float*)params = F;
			*(int*)&params[4] = LastExtreme;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
