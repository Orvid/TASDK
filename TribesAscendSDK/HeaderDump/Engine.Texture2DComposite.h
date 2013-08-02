#pragma once
namespace UnrealScript
{
	class Texture2DComposite;
}
#include "Engine.Texture.h"
#include "Engine.Texture2DComposite.SourceTexture2DRegion.h"
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
	class Texture2DComposite : public Texture
	{
	public:
		typedef Texture2DComposite__SourceTexture2DRegion SourceTexture2DRegion;
		ADD_STRUCT(ScriptArray<Texture2DComposite__SourceTexture2DRegion>, SourceRegions, 236)
		ADD_STRUCT(int, MaxTextureSize, 248)
		bool SourceTexturesFullyStreamedIn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27943);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void UpdateCompositeTexture(int NumMipsToGenerate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27945);
			byte params[4] = { NULL };
			*(int*)params = NumMipsToGenerate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetSourceRegions()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27947);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
