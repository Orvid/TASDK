#pragma once
namespace UnrealScript
{
	struct SpeechRecognition__RecognisableWord;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SpeechRecognition__RecognisableWord
	{
	public:
		ADD_STRUCT(ScriptString*, PhoneticWord, 16)
		ADD_STRUCT(ScriptString*, ReferenceWord, 4)
		ADD_STRUCT(int, Id, 0)
	};
}
#undef ADD_STRUCT
