#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Engine.Pawn.h"
#include "Engine.AnimNode_MultiBlendPerBone.PerBoneMaskInfo.h"
#include "Engine.AnimNode_MultiBlendPerBone.EBlendType.h"
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
	class AnimNode_MultiBlendPerBone : public AnimNodeBlendBase
	{
	public:
		ADD_OBJECT(Pawn, PawnOwner, 244)
		ADD_STRUCT(ScriptArray<AnimNode_MultiBlendPerBone__PerBoneMaskInfo>, MaskList, 248)
		ADD_STRUCT(AnimNode_MultiBlendPerBone__EBlendType, RotationBlendType, 260)
		void SetMaskWeight(int MaskIndex, float DesiredWeight, float BlendTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10744);
			byte params[12] = { NULL };
			*(int*)params = MaskIndex;
			*(float*)&params[4] = DesiredWeight;
			*(float*)&params[8] = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
