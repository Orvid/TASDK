#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIRoot.TextureCoordinates." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TextureCoordinates
	{
	public:
		ADD_VAR(::FloatProperty, VL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, V, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, U, 0xFFFFFFFF)
	};
}
#undef ADD_VAR