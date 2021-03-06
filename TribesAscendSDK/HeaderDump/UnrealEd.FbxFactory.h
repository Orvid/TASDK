#pragma once
namespace UnrealScript
{
	class FbxFactory;
}
#include "Core.Factory.h"
#include "UnrealEd.FbxImportUI.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class FbxFactory : public Factory
	{
	public:
		ADD_OBJECT(FbxImportUI, Import Options, 112)
	};
}
#undef ADD_OBJECT
