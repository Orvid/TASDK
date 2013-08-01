#pragma once
#include "Core.Object.QWord.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TerrainComponent__TerrainMaterialMask
	{
	public:
		ADD_STRUCT(int, NumBits, 8)
		ADD_STRUCT(QWord, BitMask, 0)
	};
}
#undef ADD_STRUCT
