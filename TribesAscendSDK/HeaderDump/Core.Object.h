#pragma once
namespace UnrealScript
{
	class Object;
}
#include "Core.Object.AlphaBlendType.h"
#include "Core.Object.Array_Mirror.h"
#include "Core.Object.BitArray_Mirror.h"
#include "Core.Object.BoneAtom.h"
#include "Core.Object.Box.h"
#include "Core.Object.BoxSphereBounds.h"
#include "Core.Object.Color.h"
#include "Core.Object.Cylinder.h"
#include "Core.Object.Double.h"
#include "Core.Object.EAspectRatioAxisConstraint.h"
#include "Core.Object.EAutomatedRunResult.h"
#include "Core.Object.EAxis.h"
#include "Core.Object.EDebugBreakType.h"
#include "Core.Object.EInputEvent.h"
#include "Core.Object.EInterpCurveMode.h"
#include "Core.Object.EInterpMethodType.h"
#include "Core.Object.ETickingGroup.h"
#include "Core.Object.FColorVertexBuffer_Mirror.h"
#include "Core.Object.Guid.h"
#include "Core.Object.IndirectArray_Mirror.h"
#include "Core.Object.InlinePointerArray_Mirror.h"
#include "Core.Object.IntPoint.h"
#include "Core.Object.InterpCurveFloat.h"
#include "Core.Object.InterpCurveLinearColor.h"
#include "Core.Object.InterpCurvePointFloat.h"
#include "Core.Object.InterpCurvePointLinearColor.h"
#include "Core.Object.InterpCurvePointQuat.h"
#include "Core.Object.InterpCurvePointTwoVectors.h"
#include "Core.Object.InterpCurvePointVector.h"
#include "Core.Object.InterpCurvePointVector2D.h"
#include "Core.Object.InterpCurveQuat.h"
#include "Core.Object.InterpCurveTwoVectors.h"
#include "Core.Object.InterpCurveVector.h"
#include "Core.Object.InterpCurveVector2D.h"
#include "Core.Object.LinearColor.h"
#include "Core.Object.Map_Mirror.h"
#include "Core.Object.Matrix.h"
#include "Core.Object.MultiMap_Mirror.h"
#include "Core.Object.OctreeElementId.h"
#include "Core.Object.Plane.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.Quat.h"
#include "Core.Object.RawDistribution.h"
#include "Core.Object.RenderCommandFence.h"
#include "Core.Object.RenderCommandFence_Mirror.h"
#include "Core.Object.SHVector.h"
#include "Core.Object.SHVectorRGB.h"
#include "Core.Object.Set_Mirror.h"
#include "Core.Object.SparseArray_Mirror.h"
#include "Core.Object.TAlphaBlend.h"
#include "Core.Object.TPOV.h"
#include "Core.Object.ThreadSafeCounter.h"
#include "Core.Object.TwoVectors.h"
#include "Core.Object.UntypedBulkData_Mirror.h"
#include "Core.Object.Vector2D.h"
#include "Core.Object.Vector4.h"
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
	class Object
	{
	public:
		typedef Object__EDebugBreakType EDebugBreakType;
		typedef Object__EAutomatedRunResult EAutomatedRunResult;
		typedef Object__EAspectRatioAxisConstraint EAspectRatioAxisConstraint;
		typedef Object__EInterpCurveMode EInterpCurveMode;
		typedef Object__EInterpMethodType EInterpMethodType;
		typedef Object__EAxis EAxis;
		typedef Object__ETickingGroup ETickingGroup;
		typedef Object__EInputEvent EInputEvent;
		typedef Object__AlphaBlendType AlphaBlendType;
		typedef Rotator Rotator;
		typedef Object__Plane Plane;
		typedef Vector Vector;
		typedef Object__Guid Guid;
		typedef Object__Vector2D Vector2D;
		typedef Object__Vector4 Vector4;
		typedef Object__LinearColor LinearColor;
		typedef Object__Color Color;
		typedef Object__InterpCurveVector2D InterpCurveVector2D;
		typedef Object__InterpCurvePointVector2D InterpCurvePointVector2D;
		typedef Object__InterpCurveFloat InterpCurveFloat;
		typedef Object__Cylinder Cylinder;
		typedef Object__InterpCurveVector InterpCurveVector;
		typedef Object__InterpCurvePointVector InterpCurvePointVector;
		typedef Object__InterpCurvePointFloat InterpCurvePointFloat;
		typedef Object__Quat Quat;
		typedef Object__Matrix Matrix;
		typedef Object__BoxSphereBounds BoxSphereBounds;
		typedef Object__TwoVectors TwoVectors;
		typedef Object__TAlphaBlend TAlphaBlend;
		typedef Object__BoneAtom BoneAtom;
		typedef Object__OctreeElementId OctreeElementId;
		typedef Object__RenderCommandFence RenderCommandFence;
		typedef Object__Pointer Pointer;
		typedef Object__RawDistribution RawDistribution;
		typedef Object__InterpCurveLinearColor InterpCurveLinearColor;
		typedef Object__InterpCurvePointLinearColor InterpCurvePointLinearColor;
		typedef Object__InterpCurveQuat InterpCurveQuat;
		typedef Object__InterpCurvePointQuat InterpCurvePointQuat;
		typedef Object__InterpCurveTwoVectors InterpCurveTwoVectors;
		typedef Object__InterpCurvePointTwoVectors InterpCurvePointTwoVectors;
		typedef Object__Box Box;
		typedef Object__TPOV TPOV;
		typedef Object__SHVectorRGB SHVectorRGB;
		typedef Object__SHVector SHVector;
		typedef Object__IntPoint IntPoint;
		typedef Object__InlinePointerArray_Mirror InlinePointerArray_Mirror;
		typedef Object__Array_Mirror Array_Mirror;
		typedef Object__IndirectArray_Mirror IndirectArray_Mirror;
		typedef Object__FColorVertexBuffer_Mirror FColorVertexBuffer_Mirror;
		typedef Object__RenderCommandFence_Mirror RenderCommandFence_Mirror;
		typedef Object__UntypedBulkData_Mirror UntypedBulkData_Mirror;
		typedef Object__MultiMap_Mirror MultiMap_Mirror;
		typedef Object__Map_Mirror Map_Mirror;
		typedef Object__Set_Mirror Set_Mirror;
		typedef Object__SparseArray_Mirror SparseArray_Mirror;
		typedef Object__BitArray_Mirror BitArray_Mirror;
		typedef Object__ThreadSafeCounter ThreadSafeCounter;
		typedef Object__Double Double;
		typedef QWord QWord;
		static const float InvAspectRatio16x9;
		static const float InvAspectRatio5x4;
		static const float InvAspectRatio4x3;
		static const float AspectRatio16x9;
		static const float AspectRatio5x4;
		static const float AspectRatio4x3;
		static const auto INDEX_NONE = -1;
		static const float UnrRotToDeg;
		static const float DegToUnrRot;
		static const float RadToUnrRot;
		static const float UnrRotToRad;
		static const float DegToRad;
		static const float RadToDeg;
		static const float Pi;
		static const auto MaxInt = 0x7fffffff;
		ADD_OBJECT(Object, Outer, 40)
		ADD_STRUCT(ScriptName, Name, 44)
		ADD_STRUCT(Object__Pointer, VfTableObject, 0)
		ADD_STRUCT(int, ObjectInternalInteger, 4)
		ADD_STRUCT(QWord, ObjectFlags, 8)
		ADD_STRUCT(Object__Pointer, HashNext, 16)
		ADD_STRUCT(Object__Pointer, HashOuterNext, 20)
		ADD_STRUCT(Object__Pointer, StateFrame, 24)
		ADD_OBJECT(Object, Linker, 28)
		ADD_STRUCT(Object__Pointer, LinkerIndex, 32)
		ADD_STRUCT(int, NetIndex, 36)
		ADD_OBJECT(ScriptClass, Class, 52)
		ADD_OBJECT(Object, ObjectArchetype, 56)
		int GetBuildChangelistNumber()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(1987);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetEngineVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(1988);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void GetSystemTime(int& Year, int& Month, int& DayOfWeek, int& Day, int& Hour, int& Min, int& Sec, int& MSec)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(1990);
			byte params[32] = { NULL };
			*(int*)params = Year;
			*(int*)&params[4] = Month;
			*(int*)&params[8] = DayOfWeek;
			*(int*)&params[12] = Day;
			*(int*)&params[16] = Hour;
			*(int*)&params[20] = Min;
			*(int*)&params[24] = Sec;
			*(int*)&params[28] = MSec;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Year = *(int*)params;
			Month = *(int*)&params[4];
			DayOfWeek = *(int*)&params[8];
			Day = *(int*)&params[12];
			Hour = *(int*)&params[16];
			Min = *(int*)&params[20];
			Sec = *(int*)&params[24];
			MSec = *(int*)&params[28];
		}
		ScriptString* TimeStamp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(1992);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		Vector TransformVectorByRotation(Rotator SourceRotation, Vector SourceVector, bool bInverse)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2001);
			byte params[40] = { NULL };
			*(Rotator*)params = SourceRotation;
			*(Vector*)&params[12] = SourceVector;
			*(bool*)&params[24] = bInverse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[28];
		}
		ScriptName GetPackageName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2003);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		bool IsPendingKill()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2018);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float ByteToFloat(byte inputByte, bool bSigned)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2023);
			byte params[9] = { NULL };
			*params = inputByte;
			*(bool*)&params[4] = bSigned;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		byte FloatToByte(float inputFloat, bool bSigned)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2025);
			byte params[9] = { NULL };
			*(float*)params = inputFloat;
			*(bool*)&params[4] = bSigned;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[8];
		}
		float UnwindHeading(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2029);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float FindDeltaAngle(float A1, float A2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2033);
			byte params[12] = { NULL };
			*(float*)params = A1;
			*(float*)&params[4] = A2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float GetHeadingAngle(Vector Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2036);
			byte params[16] = { NULL };
			*(Vector*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void GetAngularDegreesFromRadians(Object__Vector2D& OutFOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2041);
			byte params[8] = { NULL };
			*(Object__Vector2D*)params = OutFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutFOV = *(Object__Vector2D*)params;
		}
		float Acos(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2044);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void GetAngularFromDotDist(Object__Vector2D& OutAngDist, Object__Vector2D DotDist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2046);
			byte params[16] = { NULL };
			*(Object__Vector2D*)params = OutAngDist;
			*(Object__Vector2D*)&params[8] = DotDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutAngDist = *(Object__Vector2D*)params;
		}
		bool GetAngularDistance(Object__Vector2D& OutAngularDist, Vector Direction, Vector AxisX, Vector AxisY, Vector AxisZ)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2052);
			byte params[60] = { NULL };
			*(Object__Vector2D*)params = OutAngularDist;
			*(Vector*)&params[8] = Direction;
			*(Vector*)&params[20] = AxisX;
			*(Vector*)&params[32] = AxisY;
			*(Vector*)&params[44] = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutAngularDist = *(Object__Vector2D*)params;
			return *(bool*)&params[56];
		}
		bool GetDotDistance(Object__Vector2D& OutDotDist, Vector Direction, Vector AxisX, Vector AxisY, Vector AxisZ)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2055);
			byte params[60] = { NULL };
			*(Object__Vector2D*)params = OutDotDist;
			*(Vector*)&params[8] = Direction;
			*(Vector*)&params[20] = AxisX;
			*(Vector*)&params[32] = AxisY;
			*(Vector*)&params[44] = AxisZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutDotDist = *(Object__Vector2D*)params;
			return *(bool*)&params[56];
		}
		Vector PointProjectToPlane(Vector Point, Vector A, Vector B, Vector C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2062);
			byte params[60] = { NULL };
			*(Vector*)params = Point;
			*(Vector*)&params[12] = A;
			*(Vector*)&params[24] = B;
			*(Vector*)&params[36] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[48];
		}
		float PointDistToPlane(Vector Point, Rotator Orientation, Vector Origin, Vector& out_ClosestPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2069);
			byte params[52] = { NULL };
			*(Vector*)params = Point;
			*(Rotator*)&params[12] = Orientation;
			*(Vector*)&params[24] = Origin;
			*(Vector*)&params[36] = out_ClosestPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ClosestPoint = *(Vector*)&params[36];
			return *(float*)&params[48];
		}
		float PointDistToSegment(Vector Point, Vector StartPoint, Vector EndPoint, Vector& OutClosestPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2075);
			byte params[52] = { NULL };
			*(Vector*)params = Point;
			*(Vector*)&params[12] = StartPoint;
			*(Vector*)&params[24] = EndPoint;
			*(Vector*)&params[36] = OutClosestPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutClosestPoint = *(Vector*)&params[36];
			return *(float*)&params[48];
		}
		float PointDistToLine(Vector Point, Vector Line, Vector Origin, Vector& OutClosestPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2088);
			byte params[52] = { NULL };
			*(Vector*)params = Point;
			*(Vector*)&params[12] = Line;
			*(Vector*)&params[24] = Origin;
			*(Vector*)&params[36] = OutClosestPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutClosestPoint = *(Vector*)&params[36];
			return *(float*)&params[48];
		}
		bool GetPerObjectConfigSections(ScriptClass* SearchClass, ScriptArray<ScriptString*>& out_SectionNames, class Object* ObjectOuter, int MaxResults)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2094);
			byte params[28] = { NULL };
			*(ScriptClass**)params = SearchClass;
			*(ScriptArray<ScriptString*>*)&params[4] = out_SectionNames;
			*(class Object**)&params[16] = ObjectOuter;
			*(int*)&params[20] = MaxResults;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_SectionNames = *(ScriptArray<ScriptString*>*)&params[4];
			return *(bool*)&params[24];
		}
		void StaticSaveConfig()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2100);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SaveConfig()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2107);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Object* FindObject(ScriptString* ObjectName, ScriptClass* ObjectClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2108);
			byte params[20] = { NULL };
			*(ScriptString**)params = ObjectName;
			*(ScriptClass**)&params[12] = ObjectClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Object**)&params[16];
		}
		class Object* DynamicLoadObject(ScriptString* ObjectName, ScriptClass* ObjectClass, bool MayFail)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2109);
			byte params[24] = { NULL };
			*(ScriptString**)params = ObjectName;
			*(ScriptClass**)&params[12] = ObjectClass;
			*(bool*)&params[16] = MayFail;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Object**)&params[20];
		}
		ScriptName GetEnum(class Object* E, int I)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2113);
			byte params[16] = { NULL };
			*(class Object**)params = E;
			*(int*)&params[4] = I;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		void Disable(ScriptName ProbeFunc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2118);
			byte params[8] = { NULL };
			*(ScriptName*)params = ProbeFunc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Enable(ScriptName ProbeFunc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2122);
			byte params[8] = { NULL };
			*(ScriptName*)params = ProbeFunc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ContinuedState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2124);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PausedState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2126);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PoppedState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2127);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PushedState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2128);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndState(ScriptName NextStateName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2129);
			byte params[8] = { NULL };
			*(ScriptName*)params = NextStateName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginState(ScriptName PreviousStateName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2130);
			byte params[8] = { NULL };
			*(ScriptName*)params = PreviousStateName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DumpStateStack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2132);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopState(bool bPopAll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2134);
			byte params[4] = { NULL };
			*(bool*)params = bPopAll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PushState(ScriptName NewState, ScriptName NewLabel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2135);
			byte params[16] = { NULL };
			*(ScriptName*)params = NewState;
			*(ScriptName*)&params[8] = NewLabel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetStateName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2137);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		bool IsChildState(ScriptName TestState, ScriptName TestParentState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2140);
			byte params[20] = { NULL };
			*(ScriptName*)params = TestState;
			*(ScriptName*)&params[8] = TestParentState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsInState(ScriptName TestState, bool bTestStateStack)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2142);
			byte params[16] = { NULL };
			*(ScriptName*)params = TestState;
			*(bool*)&params[8] = bTestStateStack;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void GotoState(ScriptName NewState, ScriptName Label, bool bForceEvents, bool bKeepStack)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2146);
			byte params[24] = { NULL };
			*(ScriptName*)params = NewState;
			*(ScriptName*)&params[8] = Label;
			*(bool*)&params[16] = bForceEvents;
			*(bool*)&params[20] = bKeepStack;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsUTracing()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2150);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetUTracing(bool bShouldUTrace)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2155);
			byte params[4] = { NULL };
			*(bool*)params = bShouldUTrace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetFuncName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2157);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		void DebugBreak(int UserFlags, Object__EDebugBreakType DebuggerType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2159);
			byte params[5] = { NULL };
			*(int*)params = UserFlags;
			*(Object__EDebugBreakType*)&params[4] = DebuggerType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetScriptTrace()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2161);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void ScriptTrace()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2166);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* ParseLocalizedPropertyPath(ScriptString* PathName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2168);
			byte params[24] = { NULL };
			*(ScriptString**)params = PathName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* Localize(ScriptString* SectionName, ScriptString* KeyName, ScriptString* PackageName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2169);
			byte params[48] = { NULL };
			*(ScriptString**)params = SectionName;
			*(ScriptString**)&params[12] = KeyName;
			*(ScriptString**)&params[24] = PackageName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[36];
		}
		void ParseStringIntoArray(ScriptString* BaseString, ScriptArray<ScriptString*>& Pieces, ScriptString* delim, bool bCullEmpty)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2171);
			byte params[40] = { NULL };
			*(ScriptString**)params = BaseString;
			*(ScriptArray<ScriptString*>*)&params[12] = Pieces;
			*(ScriptString**)&params[24] = delim;
			*(bool*)&params[36] = bCullEmpty;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Pieces = *(ScriptArray<ScriptString*>*)&params[12];
		}
		void WarnInternal(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2175);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogInternal(ScriptString* S, ScriptName Tag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2180);
			byte params[20] = { NULL };
			*(ScriptString**)params = S;
			*(ScriptName*)&params[12] = Tag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object__LinearColor Subtract_LinearColorLinearColor(Object__LinearColor A, Object__LinearColor B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2182);
			byte params[48] = { NULL };
			*(Object__LinearColor*)params = A;
			*(Object__LinearColor*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__LinearColor*)&params[32];
		}
		Object__LinearColor Multiply_LinearColorFloat(Object__LinearColor LC, float Mult)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2185);
			byte params[36] = { NULL };
			*(Object__LinearColor*)params = LC;
			*(float*)&params[16] = Mult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__LinearColor*)&params[20];
		}
		Object__LinearColor ColorToLinearColor(Object__Color OldColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2195);
			byte params[20] = { NULL };
			*(Object__Color*)params = OldColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__LinearColor*)&params[4];
		}
		Object__LinearColor MakeLinearColor(float R, float G, float B, float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2199);
			byte params[32] = { NULL };
			*(float*)params = R;
			*(float*)&params[4] = G;
			*(float*)&params[8] = B;
			*(float*)&params[12] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__LinearColor*)&params[16];
		}
		Object__Color LerpColor(Object__Color A, Object__Color B, float Alpha)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2207);
			byte params[16] = { NULL };
			*(Object__Color*)params = A;
			*(Object__Color*)&params[4] = B;
			*(float*)&params[8] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Color*)&params[12];
		}
		Object__Color MakeColor(byte R, byte G, byte B, byte A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2214);
			byte params[8] = { NULL };
			*params = R;
			params[1] = G;
			params[2] = B;
			params[3] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Color*)&params[4];
		}
		Object__Color Add_ColorColor(Object__Color A, Object__Color B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2226);
			byte params[12] = { NULL };
			*(Object__Color*)params = A;
			*(Object__Color*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Color*)&params[8];
		}
		Object__Color Multiply_ColorFloat(Object__Color A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2233);
			byte params[12] = { NULL };
			*(Object__Color*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Color*)&params[8];
		}
		Object__Color Multiply_FloatColor(float A, Object__Color B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2237);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(Object__Color*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Color*)&params[8];
		}
		Object__Color Subtract_ColorColor(Object__Color A, Object__Color B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2241);
			byte params[12] = { NULL };
			*(Object__Color*)params = A;
			*(Object__Color*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Color*)&params[8];
		}
		Object__Vector2D EvalInterpCurveVector2D(Object__InterpCurveVector2D Vector2DCurve, float InVal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2245);
			byte params[28] = { NULL };
			*(Object__InterpCurveVector2D*)params = Vector2DCurve;
			*(float*)&params[16] = InVal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Vector2D*)&params[20];
		}
		Vector EvalInterpCurveVector(Object__InterpCurveVector VectorCurve, float InVal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2249);
			byte params[32] = { NULL };
			*(Object__InterpCurveVector*)params = VectorCurve;
			*(float*)&params[16] = InVal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[20];
		}
		float EvalInterpCurveFloat(Object__InterpCurveFloat FloatCurve, float InVal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2267);
			byte params[24] = { NULL };
			*(Object__InterpCurveFloat*)params = FloatCurve;
			*(float*)&params[16] = InVal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[20];
		}
		Object__Vector2D vect2d(float InX, float InY)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2281);
			byte params[16] = { NULL };
			*(float*)params = InX;
			*(float*)&params[4] = InY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Vector2D*)&params[8];
		}
		float GetMappedRangeValue(Object__Vector2D InputRange, Object__Vector2D OutputRange, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2294);
			byte params[24] = { NULL };
			*(Object__Vector2D*)params = InputRange;
			*(Object__Vector2D*)&params[8] = OutputRange;
			*(float*)&params[16] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[20];
		}
		float GetRangePctByValue(Object__Vector2D Range, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2299);
			byte params[16] = { NULL };
			*(Object__Vector2D*)params = Range;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float GetRangeValueByPct(Object__Vector2D Range, float Pct)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2304);
			byte params[16] = { NULL };
			*(Object__Vector2D*)params = Range;
			*(float*)&params[8] = Pct;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		Object__Vector2D SubtractEqual_Vector2DVector2D(Object__Vector2D& A, Object__Vector2D B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2308);
			byte params[24] = { NULL };
			*(Object__Vector2D*)params = A;
			*(Object__Vector2D*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object__Vector2D*)params;
			return *(Object__Vector2D*)&params[16];
		}
		Object__Vector2D AddEqual_Vector2DVector2D(Object__Vector2D& A, Object__Vector2D B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2312);
			byte params[24] = { NULL };
			*(Object__Vector2D*)params = A;
			*(Object__Vector2D*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object__Vector2D*)params;
			return *(Object__Vector2D*)&params[16];
		}
		Object__Vector2D DivideEqual_Vector2DFloat(Object__Vector2D& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2316);
			byte params[20] = { NULL };
			*(Object__Vector2D*)params = A;
			*(float*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object__Vector2D*)params;
			return *(Object__Vector2D*)&params[12];
		}
		Object__Vector2D MultiplyEqual_Vector2DFloat(Object__Vector2D& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2320);
			byte params[20] = { NULL };
			*(Object__Vector2D*)params = A;
			*(float*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Object__Vector2D*)params;
			return *(Object__Vector2D*)&params[12];
		}
		Object__Vector2D Divide_Vector2DFloat(Object__Vector2D A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2324);
			byte params[20] = { NULL };
			*(Object__Vector2D*)params = A;
			*(float*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Vector2D*)&params[12];
		}
		Object__Vector2D Multiply_Vector2DFloat(Object__Vector2D A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2328);
			byte params[20] = { NULL };
			*(Object__Vector2D*)params = A;
			*(float*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Vector2D*)&params[12];
		}
		Object__Vector2D Subtract_Vector2DVector2D(Object__Vector2D A, Object__Vector2D B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2332);
			byte params[24] = { NULL };
			*(Object__Vector2D*)params = A;
			*(Object__Vector2D*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Vector2D*)&params[16];
		}
		Object__Vector2D Add_Vector2DVector2D(Object__Vector2D A, Object__Vector2D B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2336);
			byte params[24] = { NULL };
			*(Object__Vector2D*)params = A;
			*(Object__Vector2D*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Vector2D*)&params[16];
		}
		Object__Quat Subtract_QuatQuat(Object__Quat A, Object__Quat B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2340);
			byte params[48] = { NULL };
			*(Object__Quat*)params = A;
			*(Object__Quat*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Quat*)&params[32];
		}
		Object__Quat Add_QuatQuat(Object__Quat A, Object__Quat B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2344);
			byte params[48] = { NULL };
			*(Object__Quat*)params = A;
			*(Object__Quat*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Quat*)&params[32];
		}
		Object__Quat QuatSlerp(Object__Quat A, Object__Quat B, float Alpha, bool bShortestPath)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2353);
			byte params[56] = { NULL };
			*(Object__Quat*)params = A;
			*(Object__Quat*)&params[16] = B;
			*(float*)&params[32] = Alpha;
			*(bool*)&params[36] = bShortestPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Quat*)&params[48];
		}
		Rotator QuatToRotator(Object__Quat A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2357);
			byte params[28] = { NULL };
			*(Object__Quat*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		Object__Quat QuatFromRotator(Rotator A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2363);
			byte params[28] = { NULL };
			*(Rotator*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Quat*)&params[16];
		}
		Object__Quat QuatFromAxisAndAngle(Vector Axis, float Angle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2366);
			byte params[32] = { NULL };
			*(Vector*)params = Axis;
			*(float*)&params[12] = Angle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Quat*)&params[16];
		}
		Object__Quat QuatFindBetween(Vector A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2369);
			byte params[40] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Quat*)&params[32];
		}
		Vector QuatRotateVector(Object__Quat A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2373);
			byte params[40] = { NULL };
			*(Object__Quat*)params = A;
			*(Vector*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[28];
		}
		Object__Quat QuatInvert(Object__Quat A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2377);
			byte params[32] = { NULL };
			*(Object__Quat*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Quat*)&params[16];
		}
		float QuatDot(Object__Quat A, Object__Quat B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2381);
			byte params[36] = { NULL };
			*(Object__Quat*)params = A;
			*(Object__Quat*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[32];
		}
		Object__Quat QuatProduct(Object__Quat A, Object__Quat B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2384);
			byte params[48] = { NULL };
			*(Object__Quat*)params = A;
			*(Object__Quat*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Quat*)&params[32];
		}
		Vector MatrixGetAxis(Object__Matrix TM, Object__EAxis Axis)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2388);
			byte params[77] = { NULL };
			*(Object__Matrix*)params = TM;
			*(Object__EAxis*)&params[64] = Axis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[68];
		}
		Vector MatrixGetOrigin(Object__Matrix TM)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2392);
			byte params[76] = { NULL };
			*(Object__Matrix*)params = TM;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[64];
		}
		Rotator MatrixGetRotator(Object__Matrix TM)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2406);
			byte params[76] = { NULL };
			*(Object__Matrix*)params = TM;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[64];
		}
		Object__Matrix MakeRotationMatrix(Rotator Rotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2409);
			byte params[76] = { NULL };
			*(Rotator*)params = Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Matrix*)&params[16];
		}
		Object__Matrix MakeRotationTranslationMatrix(Vector Translation, Rotator Rotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2412);
			byte params[88] = { NULL };
			*(Vector*)params = Translation;
			*(Rotator*)&params[12] = Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Matrix*)&params[32];
		}
		Vector InverseTransformNormal(Object__Matrix TM, Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2415);
			byte params[88] = { NULL };
			*(Object__Matrix*)params = TM;
			*(Vector*)&params[64] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[76];
		}
		Vector TransformNormal(Object__Matrix TM, Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2419);
			byte params[88] = { NULL };
			*(Object__Matrix*)params = TM;
			*(Vector*)&params[64] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[76];
		}
		Vector InverseTransformVector(Object__Matrix TM, Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2423);
			byte params[88] = { NULL };
			*(Object__Matrix*)params = TM;
			*(Vector*)&params[64] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[76];
		}
		Vector TransformVector(Object__Matrix TM, Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2427);
			byte params[88] = { NULL };
			*(Object__Matrix*)params = TM;
			*(Vector*)&params[64] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[76];
		}
		Object__Matrix Multiply_MatrixMatrix(Object__Matrix A, Object__Matrix B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2431);
			byte params[192] = { NULL };
			*(Object__Matrix*)params = A;
			*(Object__Matrix*)&params[64] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object__Matrix*)&params[128];
		}
		bool NotEqual_NameName(ScriptName A, ScriptName B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2435);
			byte params[20] = { NULL };
			*(ScriptName*)params = A;
			*(ScriptName*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool EqualEqual_NameName(ScriptName A, ScriptName B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2439);
			byte params[20] = { NULL };
			*(ScriptName*)params = A;
			*(ScriptName*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsA(ScriptName ClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2443);
			byte params[12] = { NULL };
			*(ScriptName*)params = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ClassIsChildOf(ScriptClass* TestClass, ScriptClass* ParentClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2447);
			byte params[12] = { NULL };
			*(ScriptClass**)params = TestClass;
			*(ScriptClass**)&params[4] = ParentClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool NotEqual_InterfaceInterface(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* A, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2450);
			byte params[20] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = A;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool EqualEqual_InterfaceInterface(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* A, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2454);
			byte params[20] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = A;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool NotEqual_ObjectObject(class Object* A, class Object* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2458);
			byte params[12] = { NULL };
			*(class Object**)params = A;
			*(class Object**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool EqualEqual_ObjectObject(class Object* A, class Object* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2462);
			byte params[12] = { NULL };
			*(class Object**)params = A;
			*(class Object**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* PathName(class Object* CheckObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2466);
			byte params[16] = { NULL };
			*(class Object**)params = CheckObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptArray<ScriptString*> SplitString(ScriptString* Source, ScriptString* Delimiter, bool bCullEmpty)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2470);
			byte params[40] = { NULL };
			*(ScriptString**)params = Source;
			*(ScriptString**)&params[12] = Delimiter;
			*(bool*)&params[24] = bCullEmpty;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<ScriptString*>*)&params[28];
		}
		void JoinArray(ScriptArray<ScriptString*> StringArray, ScriptString*& out_Result, ScriptString* delim, bool bIgnoreBlanks)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2480);
			byte params[40] = { NULL };
			*(ScriptArray<ScriptString*>*)params = StringArray;
			*(ScriptString**)&params[12] = out_Result;
			*(ScriptString**)&params[24] = delim;
			*(bool*)&params[36] = bIgnoreBlanks;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Result = *(ScriptString**)&params[12];
		}
		ScriptString* GetRightMost(ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2486);
			byte params[24] = { NULL };
			*(ScriptString**)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* ConcatEqual_StrStr(ScriptString*& A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2491);
			byte params[36] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(ScriptString**)params;
			return *(ScriptString**)&params[24];
		}
		ScriptString* Split(ScriptString* Text, ScriptString* SplitStr, bool bOmitSplitStr)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2495);
			byte params[40] = { NULL };
			*(ScriptString**)params = Text;
			*(ScriptString**)&params[12] = SplitStr;
			*(bool*)&params[24] = bOmitSplitStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[28];
		}
		ScriptString* Repl(ScriptString* Src, ScriptString* Match, ScriptString* With, bool bCaseSensitive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2499);
			byte params[52] = { NULL };
			*(ScriptString**)params = Src;
			*(ScriptString**)&params[12] = Match;
			*(ScriptString**)&params[24] = With;
			*(bool*)&params[36] = bCaseSensitive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[40];
		}
		int Asc(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2505);
			byte params[16] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		ScriptString* Chr(int I)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2511);
			byte params[16] = { NULL };
			*(int*)params = I;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Locs(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2514);
			byte params[24] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* Caps(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2517);
			byte params[24] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* Right(ScriptString* S, int I)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2520);
			byte params[28] = { NULL };
			*(ScriptString**)params = S;
			*(int*)&params[12] = I;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		ScriptString* Left(ScriptString* S, int I)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2523);
			byte params[28] = { NULL };
			*(ScriptString**)params = S;
			*(int*)&params[12] = I;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		ScriptString* Mid(ScriptString* S, int I, int J)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2527);
			byte params[32] = { NULL };
			*(ScriptString**)params = S;
			*(int*)&params[12] = I;
			*(int*)&params[16] = J;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		int InStr(ScriptString* S, ScriptString* T, bool bSearchFromRight, bool bIgnoreCase, int StartPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2531);
			byte params[40] = { NULL };
			*(ScriptString**)params = S;
			*(ScriptString**)&params[12] = T;
			*(bool*)&params[24] = bSearchFromRight;
			*(bool*)&params[28] = bIgnoreCase;
			*(int*)&params[32] = StartPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[36];
		}
		int Len(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2536);
			byte params[16] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		ScriptString* SubtractEqual_StrStr(ScriptString*& A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2543);
			byte params[36] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(ScriptString**)params;
			return *(ScriptString**)&params[24];
		}
		ScriptString* AtEqual_StrStr(ScriptString*& A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2546);
			byte params[36] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(ScriptString**)params;
			return *(ScriptString**)&params[24];
		}
		bool ComplementEqual_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2553);
			byte params[28] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool NotEqual_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2556);
			byte params[28] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool EqualEqual_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2560);
			byte params[28] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool GreaterEqual_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2564);
			byte params[28] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool LessEqual_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2568);
			byte params[28] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool Greater_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2572);
			byte params[28] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool Less_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2576);
			byte params[28] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		ScriptString* At_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2580);
			byte params[36] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		ScriptString* Concat_StrStr(ScriptString* A, ScriptString* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2584);
			byte params[36] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		Rotator MakeRotator(int Pitch, int Yaw, int Roll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2588);
			byte params[24] = { NULL };
			*(int*)params = Pitch;
			*(int*)&params[4] = Yaw;
			*(int*)&params[8] = Roll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		bool SClampRotAxis(float DeltaTime, int ViewAxis, int& out_DeltaViewAxis, int MaxLimit, int MinLimit, float InterpolationSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2592);
			byte params[28] = { NULL };
			*(float*)params = DeltaTime;
			*(int*)&params[4] = ViewAxis;
			*(int*)&params[8] = out_DeltaViewAxis;
			*(int*)&params[12] = MaxLimit;
			*(int*)&params[16] = MinLimit;
			*(float*)&params[20] = InterpolationSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_DeltaViewAxis = *(int*)&params[8];
			return *(bool*)&params[24];
		}
		int ClampRotAxisFromRange(int Current, int Min, int Max)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2598);
			byte params[16] = { NULL };
			*(int*)params = Current;
			*(int*)&params[4] = Min;
			*(int*)&params[8] = Max;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int NormalizeRotAxis(int Angle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2601);
			byte params[8] = { NULL };
			*(int*)params = Angle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		float FInterpTo(float Current, float Target, float DeltaTime, float InterpSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2605);
			byte params[20] = { NULL };
			*(float*)params = Current;
			*(float*)&params[4] = Target;
			*(float*)&params[8] = DeltaTime;
			*(float*)&params[12] = InterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		int ClampRotAxisFromBase(int Current, int Center, int MaxDelta)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2609);
			byte params[16] = { NULL };
			*(int*)params = Current;
			*(int*)&params[4] = Center;
			*(int*)&params[8] = MaxDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void ClampRotAxis(int ViewAxis, int& out_DeltaViewAxis, int MaxLimit, int MinLimit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2616);
			byte params[16] = { NULL };
			*(int*)params = ViewAxis;
			*(int*)&params[4] = out_DeltaViewAxis;
			*(int*)&params[8] = MaxLimit;
			*(int*)&params[12] = MinLimit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_DeltaViewAxis = *(int*)&params[4];
		}
		float RSize(Rotator R)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2622);
			byte params[16] = { NULL };
			*(Rotator*)params = R;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float RDiff(Rotator A, Rotator B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2628);
			byte params[28] = { NULL };
			*(Rotator*)params = A;
			*(Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[24];
		}
		Rotator RInterpTo(Rotator Current, Rotator Target, float DeltaTime, float InterpSpeed, bool bConstantInterpSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2634);
			byte params[48] = { NULL };
			*(Rotator*)params = Current;
			*(Rotator*)&params[12] = Target;
			*(float*)&params[24] = DeltaTime;
			*(float*)&params[28] = InterpSpeed;
			*(bool*)&params[32] = bConstantInterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[36];
		}
		Rotator RTransform(Rotator R, Rotator RBasis)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2637);
			byte params[36] = { NULL };
			*(Rotator*)params = R;
			*(Rotator*)&params[12] = RBasis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[24];
		}
		Rotator RSmerp(Rotator A, Rotator B, float Alpha, bool bShortestPath)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2644);
			byte params[44] = { NULL };
			*(Rotator*)params = A;
			*(Rotator*)&params[12] = B;
			*(float*)&params[24] = Alpha;
			*(bool*)&params[28] = bShortestPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[32];
		}
		Rotator RLerp(Rotator A, Rotator B, float Alpha, bool bShortestPath)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2648);
			byte params[44] = { NULL };
			*(Rotator*)params = A;
			*(Rotator*)&params[12] = B;
			*(float*)&params[24] = Alpha;
			*(bool*)&params[28] = bShortestPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[32];
		}
		Rotator Normalize(Rotator Rot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2654);
			byte params[24] = { NULL };
			*(Rotator*)params = Rot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		Rotator OrthoRotation(Vector X, Vector Y, Vector Z)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2660);
			byte params[48] = { NULL };
			*(Vector*)params = X;
			*(Vector*)&params[12] = Y;
			*(Vector*)&params[24] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[36];
		}
		Rotator RotRand(bool bRoll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2663);
			byte params[16] = { NULL };
			*(bool*)params = bRoll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[4];
		}
		Vector GetRotatorAxis(Rotator A, int Axis)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2668);
			byte params[28] = { NULL };
			*(Rotator*)params = A;
			*(int*)&params[12] = Axis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[16];
		}
		void GetUnAxes(Rotator A, Vector& X, Vector& Y, Vector& Z)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2671);
			byte params[48] = { NULL };
			*(Rotator*)params = A;
			*(Vector*)&params[12] = X;
			*(Vector*)&params[24] = Y;
			*(Vector*)&params[36] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			X = *(Vector*)&params[12];
			Y = *(Vector*)&params[24];
			Z = *(Vector*)&params[36];
		}
		void GetAxes(Rotator A, Vector& X, Vector& Y, Vector& Z)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2675);
			byte params[48] = { NULL };
			*(Rotator*)params = A;
			*(Vector*)&params[12] = X;
			*(Vector*)&params[24] = Y;
			*(Vector*)&params[36] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			X = *(Vector*)&params[12];
			Y = *(Vector*)&params[24];
			Z = *(Vector*)&params[36];
		}
		bool ClockwiseFrom_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2680);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		Rotator SubtractEqual_RotatorRotator(Rotator& A, Rotator B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2685);
			byte params[36] = { NULL };
			*(Rotator*)params = A;
			*(Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Rotator*)params;
			return *(Rotator*)&params[24];
		}
		Rotator AddEqual_RotatorRotator(Rotator& A, Rotator B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2689);
			byte params[36] = { NULL };
			*(Rotator*)params = A;
			*(Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Rotator*)params;
			return *(Rotator*)&params[24];
		}
		Rotator Subtract_RotatorRotator(Rotator A, Rotator B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2693);
			byte params[36] = { NULL };
			*(Rotator*)params = A;
			*(Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[24];
		}
		Rotator Add_RotatorRotator(Rotator A, Rotator B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2697);
			byte params[36] = { NULL };
			*(Rotator*)params = A;
			*(Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[24];
		}
		Rotator DivideEqual_RotatorFloat(Rotator& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2701);
			byte params[28] = { NULL };
			*(Rotator*)params = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Rotator*)params;
			return *(Rotator*)&params[16];
		}
		Rotator MultiplyEqual_RotatorFloat(Rotator& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2705);
			byte params[28] = { NULL };
			*(Rotator*)params = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Rotator*)params;
			return *(Rotator*)&params[16];
		}
		Rotator Divide_RotatorFloat(Rotator A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2709);
			byte params[28] = { NULL };
			*(Rotator*)params = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		Rotator Multiply_FloatRotator(float A, Rotator B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2713);
			byte params[28] = { NULL };
			*(float*)params = A;
			*(Rotator*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		Rotator Multiply_RotatorFloat(Rotator A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2717);
			byte params[28] = { NULL };
			*(Rotator*)params = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		bool NotEqual_RotatorRotator(Rotator A, Rotator B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2721);
			byte params[28] = { NULL };
			*(Rotator*)params = A;
			*(Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool EqualEqual_RotatorRotator(Rotator A, Rotator B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2725);
			byte params[28] = { NULL };
			*(Rotator*)params = A;
			*(Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool InCylinder(Vector Origin, Rotator Dir, float Width, Vector A, bool bIgnoreZ)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2729);
			byte params[48] = { NULL };
			*(Vector*)params = Origin;
			*(Rotator*)&params[12] = Dir;
			*(float*)&params[24] = Width;
			*(Vector*)&params[28] = A;
			*(bool*)&params[40] = bIgnoreZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[44];
		}
		float NoZDot(Vector A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2733);
			byte params[28] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[24];
		}
		Vector ClampLength(Vector V, float MaxLength)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2742);
			byte params[28] = { NULL };
			*(Vector*)params = V;
			*(float*)&params[12] = MaxLength;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[16];
		}
		Vector VInterpTo(Vector Current, Vector Target, float DeltaTime, float InterpSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2746);
			byte params[44] = { NULL };
			*(Vector*)params = Current;
			*(Vector*)&params[12] = Target;
			*(float*)&params[24] = DeltaTime;
			*(float*)&params[28] = InterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[32];
		}
		bool IsZero(Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2750);
			byte params[16] = { NULL };
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		Vector ProjectOnTo(Vector X, Vector Y)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2756);
			byte params[36] = { NULL };
			*(Vector*)params = X;
			*(Vector*)&params[12] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[24];
		}
		Vector MirrorVectorByNormal(Vector InVect, Vector InNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2759);
			byte params[36] = { NULL };
			*(Vector*)params = InVect;
			*(Vector*)&params[12] = InNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[24];
		}
		Vector VRandCone2(Vector Dir, float HorizontalConeHalfAngleRadians, float VerticalConeHalfAngleRadians)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2763);
			byte params[32] = { NULL };
			*(Vector*)params = Dir;
			*(float*)&params[12] = HorizontalConeHalfAngleRadians;
			*(float*)&params[16] = VerticalConeHalfAngleRadians;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[20];
		}
		Vector VRandCone(Vector Dir, float ConeHalfAngleRadians)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2767);
			byte params[28] = { NULL };
			*(Vector*)params = Dir;
			*(float*)&params[12] = ConeHalfAngleRadians;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[16];
		}
		Vector VRand()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2772);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		Vector VSmerp(Vector A, Vector B, float Alpha)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2776);
			byte params[40] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			*(float*)&params[24] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[28];
		}
		Vector VLerp(Vector A, Vector B, float Alpha)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2778);
			byte params[40] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			*(float*)&params[24] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[28];
		}
		Vector Normal(Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2783);
			byte params[24] = { NULL };
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		float VSizeSq2D(Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2788);
			byte params[16] = { NULL };
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float VSizeSq(Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2791);
			byte params[16] = { NULL };
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float VSize2D(Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2794);
			byte params[16] = { NULL };
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float VSize(Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2797);
			byte params[16] = { NULL };
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		Vector SubtractEqual_VectorVector(Vector& A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2800);
			byte params[36] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Vector*)params;
			return *(Vector*)&params[24];
		}
		Vector AddEqual_VectorVector(Vector& A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2803);
			byte params[36] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Vector*)params;
			return *(Vector*)&params[24];
		}
		Vector DivideEqual_VectorFloat(Vector& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2807);
			byte params[28] = { NULL };
			*(Vector*)params = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Vector*)params;
			return *(Vector*)&params[16];
		}
		Vector MultiplyEqual_VectorVector(Vector& A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2811);
			byte params[36] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Vector*)params;
			return *(Vector*)&params[24];
		}
		Vector MultiplyEqual_VectorFloat(Vector& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2815);
			byte params[28] = { NULL };
			*(Vector*)params = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(Vector*)params;
			return *(Vector*)&params[16];
		}
		Vector Cross_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2819);
			byte params[36] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[24];
		}
		float Dot_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2823);
			byte params[28] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[24];
		}
		bool NotEqual_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2827);
			byte params[28] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool EqualEqual_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2831);
			byte params[28] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		Vector GreaterGreater_VectorRotator(Vector A, Rotator B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2835);
			byte params[36] = { NULL };
			*(Vector*)params = A;
			*(Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[24];
		}
		Vector LessLess_VectorRotator(Vector A, Rotator B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2839);
			byte params[36] = { NULL };
			*(Vector*)params = A;
			*(Rotator*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[24];
		}
		Vector Subtract_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2843);
			byte params[36] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[24];
		}
		Vector Add_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2847);
			byte params[36] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[24];
		}
		Vector Divide_VectorFloat(Vector A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2851);
			byte params[28] = { NULL };
			*(Vector*)params = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[16];
		}
		Vector Multiply_VectorVector(Vector A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2855);
			byte params[36] = { NULL };
			*(Vector*)params = A;
			*(Vector*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[24];
		}
		Vector Multiply_FloatVector(float A, Vector B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2859);
			byte params[28] = { NULL };
			*(float*)params = A;
			*(Vector*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[16];
		}
		Vector Multiply_VectorFloat(Vector A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2863);
			byte params[28] = { NULL };
			*(Vector*)params = A;
			*(float*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[16];
		}
		Vector Subtract_PreVector(Vector A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2867);
			byte params[24] = { NULL };
			*(Vector*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		float FInterpConstantTo(float Current, float Target, float DeltaTime, float InterpSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2871);
			byte params[20] = { NULL };
			*(float*)params = Current;
			*(float*)&params[4] = Target;
			*(float*)&params[8] = DeltaTime;
			*(float*)&params[12] = InterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float FPctByRange(float Value, float InMin, float InMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2879);
			byte params[16] = { NULL };
			*(float*)params = Value;
			*(float*)&params[4] = InMin;
			*(float*)&params[8] = InMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float RandRange(float InMin, float InMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2885);
			byte params[12] = { NULL };
			*(float*)params = InMin;
			*(float*)&params[4] = InMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float FInterpEaseInOut(float A, float B, float Alpha, float Exp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2890);
			byte params[20] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			*(float*)&params[8] = Alpha;
			*(float*)&params[12] = Exp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float FInterpEaseOut(float A, float B, float Alpha, float Exp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2894);
			byte params[20] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			*(float*)&params[8] = Alpha;
			*(float*)&params[12] = Exp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float FInterpEaseIn(float A, float B, float Alpha, float Exp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2900);
			byte params[20] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			*(float*)&params[8] = Alpha;
			*(float*)&params[12] = Exp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float FCubicInterp(float P0, float T0, float P1, float T1, float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2906);
			byte params[24] = { NULL };
			*(float*)params = P0;
			*(float*)&params[4] = T0;
			*(float*)&params[8] = P1;
			*(float*)&params[12] = T1;
			*(float*)&params[16] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[20];
		}
		int FCeil(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2912);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int FFloor(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2919);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int Round(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2922);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		float Lerp(float A, float B, float Alpha)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2925);
			byte params[16] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			*(float*)&params[8] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float FClamp(float V, float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2928);
			byte params[16] = { NULL };
			*(float*)params = V;
			*(float*)&params[4] = A;
			*(float*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float FMax(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2933);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float FMin(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2938);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float FRand()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2942);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float Square(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2946);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Sqrt(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2948);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Loge(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2951);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Exp(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2954);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Atan2(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2957);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Atan(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2960);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Tan(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2964);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Cos(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2969);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Asin(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2972);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Sin(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2975);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Abs(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2978);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float SubtractEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2981);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(float*)params;
			return *(float*)&params[8];
		}
		float AddEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2984);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(float*)params;
			return *(float*)&params[8];
		}
		float DivideEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2988);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(float*)params;
			return *(float*)&params[8];
		}
		float MultiplyEqual_FloatFloat(float& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2992);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(float*)params;
			return *(float*)&params[8];
		}
		bool NotEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(2996);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ComplementEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3000);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool EqualEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3004);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GreaterEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3008);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool LessEqual_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3012);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Greater_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3016);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Less_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3020);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		float Subtract_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3024);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Add_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3028);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Percent_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3032);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Divide_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3036);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Multiply_FloatFloat(float A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3040);
			byte params[12] = { NULL };
			*(float*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float MultiplyMultiply_FloatFloat(float Base, float Exp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3044);
			byte params[12] = { NULL };
			*(float*)params = Base;
			*(float*)&params[4] = Exp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float Subtract_PreFloat(float A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3048);
			byte params[8] = { NULL };
			*(float*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		ScriptString* ToHex(int A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3052);
			byte params[16] = { NULL };
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		int Clamp(int V, int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3055);
			byte params[16] = { NULL };
			*(int*)params = V;
			*(int*)&params[4] = A;
			*(int*)&params[8] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int Max(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3058);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Min(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3063);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Rand(int Max)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3067);
			byte params[8] = { NULL };
			*(int*)params = Max;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int SubtractSubtract_Int(int& A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3071);
			byte params[8] = { NULL };
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)params;
			return *(int*)&params[4];
		}
		int AddAdd_Int(int& A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3074);
			byte params[8] = { NULL };
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)params;
			return *(int*)&params[4];
		}
		int SubtractSubtract_PreInt(int& A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3077);
			byte params[8] = { NULL };
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)params;
			return *(int*)&params[4];
		}
		int AddAdd_PreInt(int& A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3080);
			byte params[8] = { NULL };
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)params;
			return *(int*)&params[4];
		}
		int SubtractEqual_IntInt(int& A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3083);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)params;
			return *(int*)&params[8];
		}
		int AddEqual_IntInt(int& A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3086);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)params;
			return *(int*)&params[8];
		}
		int DivideEqual_IntFloat(int& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3090);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)params;
			return *(int*)&params[8];
		}
		int MultiplyEqual_IntFloat(int& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3094);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *(int*)params;
			return *(int*)&params[8];
		}
		int Or_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3098);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Xor_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3102);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int And_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3106);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool NotEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3110);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool EqualEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3114);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GreaterEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3118);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool LessEqual_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3122);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Greater_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3126);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Less_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3130);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GreaterGreaterGreater_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3134);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GreaterGreater_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3138);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int LessLess_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3142);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Subtract_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3146);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Add_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3150);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Percent_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3154);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Divide_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3158);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Multiply_IntInt(int A, int B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3162);
			byte params[12] = { NULL };
			*(int*)params = A;
			*(int*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int Subtract_PreInt(int A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3166);
			byte params[8] = { NULL };
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int Complement_PreInt(int A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3170);
			byte params[8] = { NULL };
			*(int*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		byte SubtractSubtract_Byte(byte& A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3173);
			byte params[2] = { NULL };
			*params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *params;
			return params[1];
		}
		byte AddAdd_Byte(byte& A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3176);
			byte params[2] = { NULL };
			*params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *params;
			return params[1];
		}
		byte SubtractSubtract_PreByte(byte& A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3179);
			byte params[2] = { NULL };
			*params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *params;
			return params[1];
		}
		byte AddAdd_PreByte(byte& A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3182);
			byte params[2] = { NULL };
			*params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *params;
			return params[1];
		}
		byte SubtractEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3185);
			byte params[3] = { NULL };
			*params = A;
			params[1] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *params;
			return params[2];
		}
		byte AddEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3188);
			byte params[3] = { NULL };
			*params = A;
			params[1] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *params;
			return params[2];
		}
		byte DivideEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3192);
			byte params[3] = { NULL };
			*params = A;
			params[1] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *params;
			return params[2];
		}
		byte MultiplyEqual_ByteFloat(byte& A, float B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3196);
			byte params[6] = { NULL };
			*params = A;
			*(float*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *params;
			return params[8];
		}
		byte MultiplyEqual_ByteByte(byte& A, byte B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3200);
			byte params[3] = { NULL };
			*params = A;
			params[1] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			A = *params;
			return params[2];
		}
		bool OrOr_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3204);
			byte params[12] = { NULL };
			*(bool*)params = A;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool XorXor_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3208);
			byte params[12] = { NULL };
			*(bool*)params = A;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AndAnd_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3212);
			byte params[12] = { NULL };
			*(bool*)params = A;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool NotEqual_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3216);
			byte params[12] = { NULL };
			*(bool*)params = A;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool EqualEqual_BoolBool(bool A, bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3220);
			byte params[12] = { NULL };
			*(bool*)params = A;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Not_PreBool(bool A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3224);
			byte params[8] = { NULL };
			*(bool*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
	const float Object::InvAspectRatio16x9 = 0.56249f;
	const float Object::InvAspectRatio5x4 = 0.8f;
	const float Object::InvAspectRatio4x3 = 0.75f;
	const float Object::AspectRatio16x9 = 1.77778f;
	const float Object::AspectRatio5x4 = 1.25f;
	const float Object::AspectRatio4x3 = 1.33333f;
	const float Object::UnrRotToDeg = 0.00549316540360483f;
	const float Object::DegToUnrRot = 182.0444f;
	const float Object::RadToUnrRot = 10430.3783504704527f;
	const float Object::UnrRotToRad = 0.00009587379924285f;
	const float Object::DegToRad = 0.017453292519943296f;
	const float Object::RadToDeg = 57.295779513082321600f;
	const float Object::Pi = 3.1415926535897932f;
}
#undef ADD_STRUCT
#undef ADD_OBJECT
