#pragma once
namespace UnrealScript
{
	struct Brush__GeomSelection;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Brush__GeomSelection
	{
	public:
		ADD_STRUCT(int, SelectionIndex, 8)
		ADD_STRUCT(int, Index, 4)
		ADD_STRUCT(int, Type, 0)
	};
}
#undef ADD_STRUCT
