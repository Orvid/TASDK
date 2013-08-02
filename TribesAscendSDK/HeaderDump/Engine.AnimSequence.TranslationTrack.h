#pragma once
namespace UnrealScript
{
	struct AnimSequence__TranslationTrack;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimSequence__TranslationTrack
	{
	public:
		ADD_STRUCT(ScriptArray<Vector>, PosKeys, 0)
		ADD_STRUCT(ScriptArray<float>, Times, 12)
	};
}
#undef ADD_STRUCT
