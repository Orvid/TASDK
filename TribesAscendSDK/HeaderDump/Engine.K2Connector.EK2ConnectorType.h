#pragma once
namespace UnrealScript
{
	enum K2Connector__EK2ConnectorType : byte
	{
		K2CT_Bool = 0,
		K2CT_Int = 1,
		K2CT_Float = 2,
		K2CT_Vector = 3,
		K2CT_Rotator = 4,
		K2CT_String = 5,
		K2CT_Object = 6,
		K2CT_Exec = 7,
		K2CT_Unsupported = 8,
		K2CT_MAX = 9,
	};
}
