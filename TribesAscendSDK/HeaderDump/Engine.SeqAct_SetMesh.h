#pragma once
namespace UnrealScript
{
	class SeqAct_SetMesh;
}
#include "Engine.SeqAct_SetMesh.EMeshType.h"
#include "Engine.SequenceAction.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.StaticMesh.h"
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
	class SeqAct_SetMesh : public SequenceAction
	{
	public:
		typedef SeqAct_SetMesh__EMeshType EMeshType;
		ADD_STRUCT(SeqAct_SetMesh__EMeshType, MeshType, 240)
		ADD_BOOL(bIsAllowedToMove, 244, 0x1)
		ADD_BOOL(bAllowDecalsToReattach, 244, 0x2)
		ADD_OBJECT(StaticMesh, NewStaticMesh, 236)
		ADD_OBJECT(SkeletalMesh, NewSkeletalMesh, 232)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
