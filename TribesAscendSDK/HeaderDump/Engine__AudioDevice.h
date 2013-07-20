#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AudioDevice." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AudioDevice." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AudioDevice." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AudioDevice : public Subsystem
	{
	public:
			bool SetSoundMode( ScriptName NewMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AudioDevice.SetSoundMode" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, LastUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TransientMasterVolume, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, DebugState, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExteriorLPFInterp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExteriorVolumeInterp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InteriorLPFInterp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InteriorVolumeInterp, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ListenerVolumeIndex, 0xFFFFFFFF )
			ADD_OBJECT( SoundMode, CurrentMode )
			ADD_VAR( ::NameProperty, BaseSoundModeName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CommonAudioPoolFreeBytes, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bGameWasTicking, 0x2 )
			ADD_VAR( ::BoolProperty, m_bEnableBassBoost, 0x1 )
			ADD_OBJECT( SoundNodeWave, ChirpOutSoundNodeWave )
			ADD_VAR( ::StrProperty, ChirpOutSoundNodeWaveName, 0xFFFFFFFF )
			ADD_OBJECT( SoundNodeWave, ChirpInSoundNodeWave )
			ADD_VAR( ::StrProperty, ChirpInSoundNodeWaveName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinCompressedDurationGame, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinCompressedDurationEditor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LowPassFilterResonance, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CommonAudioPoolSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxChannels, 0xFFFFFFFF )
			class SoundClass* FindSoundClass( ScriptName SoundClassName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AudioDevice.FindSoundClass" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SoundClassName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundClass** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
