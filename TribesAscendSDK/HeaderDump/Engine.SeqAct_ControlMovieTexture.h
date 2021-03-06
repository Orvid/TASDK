#pragma once
namespace UnrealScript
{
	class SeqAct_ControlMovieTexture;
}
#include "Engine.SeqAct_ControlMovieTexture.EMovieControlType.h"
#include "Engine.SequenceAction.h"
#include "Engine.TextureMovie.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ControlMovieTexture : public SequenceAction
	{
	public:
		typedef SeqAct_ControlMovieTexture__EMovieControlType EMovieControlType;
		ADD_OBJECT(TextureMovie, MovieTexture, 232)
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6859);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
