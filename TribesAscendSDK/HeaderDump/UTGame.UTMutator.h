#pragma once
namespace UnrealScript
{
	class UTMutator;
}
#include "Engine.Actor.h"
#include "Engine.Mutator.h"
#include "Engine.OnlineSubsystem.SpeechRecognizedWord.h"
#include "UTGame.UTPlayerController.h"
namespace UnrealScript
{
	class UTMutator : public Mutator
	{
	public:
		class UTMutator* GetNextUTMutator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44841);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTMutator**)params;
		}
		bool MutatorIsAllowed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48551);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ReplaceWith(class Actor* Other, ScriptString* aClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48555);
			byte params[20] = { NULL };
			*(class Actor**)params = Other;
			*(ScriptString**)&params[4] = aClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ProcessSpeechRecognition(class UTPlayerController* Speaker, ScriptArray<OnlineSubsystem__SpeechRecognizedWord>& Words)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48563);
			byte params[16] = { NULL };
			*(class UTPlayerController**)params = Speaker;
			*(ScriptArray<OnlineSubsystem__SpeechRecognizedWord>*)&params[4] = Words;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem__SpeechRecognizedWord>*)&params[4];
		}
	};
}
