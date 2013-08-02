#pragma once
namespace UnrealScript
{
	struct OnlineSubsystem__SpeechRecognizedWord;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineSubsystem__SpeechRecognizedWord
	{
	public:
		ADD_STRUCT(int, WordId, 0)
		ADD_STRUCT(ScriptString*, WordText, 4)
		ADD_STRUCT(float, Confidence, 16)
	};
}
#undef ADD_STRUCT
