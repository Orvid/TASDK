#pragma once
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxGenericForceFieldBox." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxGenericForceFieldBox : public NxGenericForceField
	{
	public:
		ADD_STRUCT(::VectorProperty, BoxExtent, 0xFFFFFFFF
	};
}
#undef ADD_STRUCT
