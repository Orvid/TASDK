#pragma once
#include "Engine__SeqAct_Latent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqAct_ControlGameMovie." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ControlGameMovie : public SeqAct_Latent
	{
	public:
		ADD_VAR(::IntProperty, EndOfRenderingMovieFrame, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StartOfRenderingMovieFrame, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MovieName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
