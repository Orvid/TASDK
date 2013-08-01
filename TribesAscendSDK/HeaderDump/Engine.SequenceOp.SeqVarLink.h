#pragma once
#include "Engine.SequenceVariable.h"
#include "Core.Property.h"
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
	struct SequenceOp__SeqVarLink
	{
	public:
		ADD_STRUCT(ScriptArray<class SequenceVariable*>, LinkedVariables, 4)
		ADD_STRUCT(int, OverrideDelta, 68)
		ADD_BOOL(bClampedMin, 64, 0x8)
		ADD_BOOL(bClampedMax, 64, 0x4)
		ADD_BOOL(bMoving, 64, 0x2)
		ADD_BOOL(bAllowAnyType, 64, 0x1)
		ADD_OBJECT(Property, CachedProperty, 60)
		ADD_STRUCT(int, DrawX, 56)
		ADD_STRUCT(int, MaxVars, 52)
		ADD_STRUCT(int, MinVars, 48)
		ADD_BOOL(bHidden, 44, 0x8)
		ADD_BOOL(bModifiesLinkedObject, 44, 0x4)
		ADD_BOOL(bSequenceNeverReadsOnlyWritesToThisVar, 44, 0x2)
		ADD_BOOL(bWriteable, 44, 0x1)
		ADD_STRUCT(ScriptName, PropertyName, 36)
		ADD_STRUCT(ScriptName, LinkVar, 28)
		ADD_STRUCT(ScriptString*, LinkDesc, 16)
		ADD_OBJECT(ScriptClass, ExpectedType, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
