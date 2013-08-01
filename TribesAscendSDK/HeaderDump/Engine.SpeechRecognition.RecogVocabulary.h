#pragma once
#include "Engine.SpeechRecognition.RecognisableWord.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SpeechRecognition__RecogVocabulary
	{
	public:
		ADD_STRUCT(ScriptArray<SpeechRecognition__RecognisableWord>, WhoDictionary, 0)
		ADD_STRUCT(ScriptArray<SpeechRecognition__RecognisableWord>, WhatDictionary, 12)
		ADD_STRUCT(ScriptArray<SpeechRecognition__RecognisableWord>, WhereDictionary, 24)
		ADD_STRUCT(ScriptArray<byte>, VocabData, 48)
		ADD_STRUCT(ScriptArray<byte>, WorkingVocabData, 60)
		ADD_STRUCT(ScriptString*, VocabName, 36)
	};
}
#undef ADD_STRUCT
