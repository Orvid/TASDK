#pragma once
namespace UnrealScript
{
	struct SkeletalMeshActor__CheckpointRecord;
}
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
	struct SkeletalMeshActor__CheckpointRecord
	{
	public:
		ADD_STRUCT(Rotator, Rotation, 16)
		ADD_STRUCT(Vector, Location, 4)
		ADD_BOOL(bSavedPosition, 0, 0x4)
		ADD_BOOL(bHidden, 0, 0x2)
		ADD_BOOL(bReplicated, 0, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
