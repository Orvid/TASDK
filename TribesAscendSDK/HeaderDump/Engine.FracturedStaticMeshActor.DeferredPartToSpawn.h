#pragma once
namespace UnrealScript
{
	struct FracturedStaticMeshActor__DeferredPartToSpawn;
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
	struct FracturedStaticMeshActor__DeferredPartToSpawn
	{
	public:
		ADD_BOOL(bExplosion, 32, 0x1)
		ADD_STRUCT(float, RelativeScale, 28)
		ADD_STRUCT(Vector, InitialAngVel, 16)
		ADD_STRUCT(Vector, InitialVel, 4)
		ADD_STRUCT(int, ChunkIndex, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
