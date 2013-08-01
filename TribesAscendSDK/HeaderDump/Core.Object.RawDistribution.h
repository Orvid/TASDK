#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__RawDistribution
	{
	public:
		ADD_STRUCT(byte, Type, 0)
		ADD_STRUCT(byte, Op, 1)
		ADD_STRUCT(byte, LookupTableNumElements, 2)
		ADD_STRUCT(byte, LookupTableChunkSize, 3)
		ADD_STRUCT(ScriptArray<float>, LookupTable, 4)
		ADD_STRUCT(float, LookupTableTimeScale, 16)
		ADD_STRUCT(float, LookupTableStartTime, 20)
	};
}
#undef ADD_STRUCT
