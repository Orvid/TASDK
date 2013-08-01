#pragma once
#include "Core.Factory.h"
#include "UnrealEd.TextureMovieFactory.MovieStreamSource.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TextureMovieFactory : public Factory
	{
	public:
		ADD_STRUCT(TextureMovieFactory__MovieStreamSource, MovieStreamSource, 112)
	};
}
#undef ADD_STRUCT
