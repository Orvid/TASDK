#pragma once
namespace UnrealScript
{
	struct AnimSequence__CompressedTrack;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimSequence__CompressedTrack
	{
	public:
		ADD_STRUCT(ScriptArray<byte>, ByteStream, 0)
		ADD_STRUCT(ScriptArray<float>, Times, 12)
		ADD_STRUCT(float, Ranges, 36)
		ADD_STRUCT(float, Mins, 24)
	};
}
#undef ADD_STRUCT
