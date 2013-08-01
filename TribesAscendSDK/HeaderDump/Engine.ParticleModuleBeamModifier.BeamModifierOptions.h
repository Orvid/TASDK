#pragma once
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
namespace UnrealScript
{
	struct ParticleModuleBeamModifier__BeamModifierOptions
	{
	public:
		ADD_BOOL(Block, 0, 0x4)
		ADD_BOOL(bScale, 0, 0x2)
		ADD_BOOL(bModify, 0, 0x1)
	};
}
#undef ADD_BOOL
