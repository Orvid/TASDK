#pragma once
#include "Core.Object.QWord.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineSubsystem__UniqueNetId
	{
	public:
		ADD_STRUCT(QWord, Uid, 0)
	};
}
#undef ADD_STRUCT