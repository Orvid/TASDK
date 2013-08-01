#pragma once
namespace UnrealScript
{
	enum MaterialExpressionTransform__EMaterialVectorCoordTransform : byte
	{
		TRANSFORM_World = 0,
		TRANSFORM_View = 1,
		TRANSFORM_Local = 2,
		TRANSFORM_Tangent = 3,
		TRANSFORM_MAX = 4,
	};
}
