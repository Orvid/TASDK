#pragma once
namespace UnrealScript
{
	class SpeechRecognition;
}
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Engine.SpeechRecognition.RecogUserData.h"
#include "Engine.SpeechRecognition.RecogVocabulary.h"
#include "Engine.SpeechRecognition.RecognisableWord.h"
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
	class SpeechRecognition : public Object
	{
	public:
		typedef SpeechRecognition__RecogVocabulary RecogVocabulary;
		typedef SpeechRecognition__RecognisableWord RecognisableWord;
		typedef SpeechRecognition__RecogUserData RecogUserData;
		ADD_STRUCT(ScriptArray<SpeechRecognition__RecogVocabulary>, Vocabularies, 76)
		ADD_STRUCT(ScriptArray<byte>, VoiceData, 88)
		ADD_STRUCT(ScriptArray<byte>, WorkingVoiceData, 100)
		ADD_STRUCT(ScriptArray<byte>, UserData, 112)
		ADD_STRUCT(Object__Pointer, FnxVoiceData, 192)
		ADD_BOOL(bInitialised, 188, 0x2)
		ADD_BOOL(bDirty, 188, 0x1)
		ADD_STRUCT(SpeechRecognition__RecogUserData, InstanceData, 124)
		ADD_STRUCT(float, ConfidenceThreshhold, 72)
		ADD_STRUCT(ScriptString*, Language, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
