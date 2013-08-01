#pragma once
namespace UnrealScript
{
	enum MaterialExpressionTransform__EMaterialVectorCoordTransformSource : byte
	{
		TRANSFORMSOURCE_World = 0,
		TRANSFORMSOURCE_Local = 1,
		TRANSFORMSOURCE_Tangent = 2,
		TRANSFORMSOURCE_MAX = 3,
	};
}
