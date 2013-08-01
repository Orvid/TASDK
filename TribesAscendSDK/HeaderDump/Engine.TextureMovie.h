#pragma once
#include "Core.Object.UntypedBulkData_Mirror.h"
#include "Engine.Texture.h"
#include "Core.Object.Pointer.h"
#include "Engine.Texture.TextureAddress.h"
#include "Engine.CodecMovie.h"
#include "Engine.TextureMovie.EMovieStreamSource.h"
#include "Engine.Texture.EPixelFormat.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TextureMovie : public Texture
	{
	public:
		ADD_STRUCT(Object__Pointer, ReleaseCodecFence, 312)
		ADD_STRUCT(Object__UntypedBulkData_Mirror, Data, 260)
		ADD_BOOL(AutoPlay, 256, 0x8)
		ADD_BOOL(Looping, 256, 0x4)
		ADD_BOOL(Stopped, 256, 0x2)
		ADD_BOOL(Paused, 256, 0x1)
		ADD_OBJECT(CodecMovie, Decoder, 252)
		ADD_OBJECT(ScriptClass, DecoderClass, 248)
		ADD_STRUCT(TextureMovie__EMovieStreamSource, MovieStreamSource, 247)
		ADD_STRUCT(int, SizeX, 236)
		ADD_STRUCT(Texture__TextureAddress, AddressY, 246)
		ADD_STRUCT(Texture__TextureAddress, AddressX, 245)
		ADD_STRUCT(Texture__EPixelFormat, Format, 244)
		ADD_STRUCT(int, SizeY, 240)
		void Play()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28005);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Pause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28006);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Stop()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28007);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
