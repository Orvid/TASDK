#pragma once
namespace UnrealScript
{
	struct EngineTypes__PrimitiveMaterialRef;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct EngineTypes__PrimitiveMaterialRef
	{
	public:
		ADD_STRUCT(int, MaterialIndex, 4)
	};
}
#undef ADD_STRUCT
