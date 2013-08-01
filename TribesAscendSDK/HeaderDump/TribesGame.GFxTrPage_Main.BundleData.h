#pragma once
#include "TribesGame.TrObject.EContentDataType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GFxTrPage_Main__BundleData
	{
	public:
		ADD_STRUCT(TrObject__EContentDataType, Model, 4)
		ADD_STRUCT(int, LootId, 0)
	};
}
#undef ADD_STRUCT
