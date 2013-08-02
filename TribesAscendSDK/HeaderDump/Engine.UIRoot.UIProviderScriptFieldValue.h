#pragma once
namespace UnrealScript
{
	struct UIRoot__UIProviderScriptFieldValue;
}
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.Surface.h"
#include "Engine.UIRoot.EUIDataProviderFieldType.h"
#include "Engine.UIRoot.TextureCoordinates.h"
#include "Engine.UIRoot.UIRangeData.h"
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
	struct UIRoot__UIProviderScriptFieldValue
	{
	public:
		ADD_STRUCT(ScriptArray<int>, ArrayValue, 28)
		ADD_STRUCT(UIRoot__TextureCoordinates, AtlasCoordinates, 68)
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, NetIdValue, 60)
		ADD_STRUCT(UIRoot__UIRangeData, RangeValue, 40)
		ADD_OBJECT(Surface, ImageValue, 24)
		ADD_STRUCT(ScriptString*, StringValue, 12)
		ADD_STRUCT(UIRoot__EUIDataProviderFieldType, PropertyType, 8)
		ADD_STRUCT(ScriptName, PropertyTag, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
