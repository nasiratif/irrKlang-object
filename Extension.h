#pragma once
#include "DarkEdif.h"
#include <IrrKlang\irrKlang.h>

#pragma comment (lib, "..\\Lib\\Windows\\irrKlang.lib")

class Extension
{
public:
	irrklang::ISoundEngine* audio = NULL;
	irrklang::IAudioRecorder* recorder = NULL;
	irrklang::ISoundDeviceList* mList;
	irrklang::ISoundDeviceList* sList;
	irrklang::vec3df listenerPos = irrklang::vec3df(0, 0, 0);
	irrklang::vec3df listenerRot = irrklang::vec3df(0, 0, 0);
	irrklang::vec3df listenerVel = irrklang::vec3df(0, 0, 0);
	bool autoIrrKlang;
	bool autoRecorder;
	bool use3D;
	std::string driver;
	irrklang::E_SOUND_OUTPUT_DRIVER driverChoice;

#ifdef _WIN32
	RUNDATA * rdPtr;
	RunHeader * rhPtr;
#elif defined(__ANDROID__)
	RuntimeFunctions & runFuncs;
	global<jobject> javaExtPtr;
#else
	RuntimeFunctions & runFuncs;
	void * objCExtPtr;
#endif

	Edif::Runtime Runtime;

	static const int MinimumBuild = 254;
	static const int Version = 1;

	// If you change OEFLAGS, make sure you modify RUNDATA so the data is available, or you'll get crashes!
	// For example, OEFLAGS::VALUES makes use of the AltVals rv struct.
	static const OEFLAGS OEFLAGS = OEFLAGS::NONE;
	static const OEPREFS OEPREFS = OEPREFS::NONE;

	static const int WindowProcPriority = 100;

#ifdef _WIN32
	Extension(RUNDATA * rdPtr, EDITDATA * edPtr, CreateObjectInfo * cobPtr);
#elif defined(__ANDROID__)
	Extension(RuntimeFunctions & runFuncs, EDITDATA * edPtr, jobject javaExtPtr);
#else
	Extension(RuntimeFunctions & runFuncs, EDITDATA * edPtr, void * objCExtPtr);
#endif
	~Extension();

	// To add items to the Fusion Debugger, just uncomment this line.
	DarkEdif::FusionDebugger FusionDebugger;
	// After enabling it, you run FusionDebugger.AddItemToDebugger() inside Extension's constructor
	// As an example:
	std::tstring exampleDebuggerTextItem;

	/*  Add any data you want to store in your extension to this class
		(eg. what you'd normally store in rdPtr in old SDKs).

		Unlike rdPtr, you can store real C++ objects with constructors
		and destructors, without having to call them manually or store
		a pointer.
	*/





	// int MyVariable;




	/*  Add your actions, conditions and expressions as real class member
		functions here. The arguments (and return type for expressions) must
		match EXACTLY what you defined in the JSON.

		Remember to link the actions, conditions and expressions to their
		numeric IDs in the class constructor (Extension.cpp)
	*/

	/// Actions

		void PlaySound(const TCHAR* pathToSound, int id, int SFX);
		void PlayLoopingSound(const TCHAR* pathToSound, int id, int SFX);
		void StopSound(const TCHAR* pathToSound);

		void Play3DSound(const TCHAR* pathToSound, float xPos, float yPos, float zPos, int id, int SFX);
		void PlayLooping3DSound(const TCHAR* pathToSound, float xPos, float yPos, float zPos, int id, int SFX);
		void SetListenerPos(float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, float xVel, float yVel, float zVel);
		void SetSoundPos(const TCHAR* pathToSound, float xPos, float yPos, float zPos);
		void SetMinDis(const TCHAR* pathToSound, float dis);
		void SetMaxDis(const TCHAR* pathToSound, float dis);
		void SetRolloff(float rolloff);
		void SetDopplerParams(float dopplerFactor, float distanceFactor);
		void SetSoundVel(const TCHAR* pathToSound, float xVel, float yVel, float zVel);

		void SetMasterVol(float vol);
		void SetSoundVol(const TCHAR* pathToSound, float vol);
		void PauseSound(const TCHAR* pathToSound);
		void UnpauseSound(const TCHAR* pathToSound);
		void PauseAll();
		void UnpauseAll();
		void SetPlaybackPos(const TCHAR* pathToSound, int pos);
		void SetPlaybackSpeed(const TCHAR* pathToSound, float spd);
		void SetSoundPan(const TCHAR* pathToSound, float pan);
		
		void StopSoundID(int id);
		
		void SetSoundPosID(int id, float xPos, float yPos, float zPos);
		void SetMinDisID(int id, float dis);
		void SetMaxDisID(int id, float dis);
		void SetSoundVelID(int id, float xVel, float yVel, float zVel);

		void PauseSoundID(int id);
		void UnpauseSoundID(int id);
		void SetPlaybackPosID(int id, int pos);
		void SetPlaybackSpeedID(int id, float spd);
		void SetSoundPanID(int id, float pan);
		void SetSoundVolID(int id, float vol);

		void SetChorus(const TCHAR* pathToSound, int enable);
		void SetChorusParams(const TCHAR* pathToSound, float fWetDryMix, float fDepth, float fFeedback, float fFrequency, int sinusWaveForm, float fDelay, int IPhase);
		void SetCompressor(const TCHAR* pathToSound, int enable);
		void SetCompressorParams(const TCHAR* pathToSound, float fGain, float fAttack, float fRelease, float fThreshold, float fRatio, float fPredelay);
		void SetEcho(const TCHAR* pathToSound, int enable);
		void SetEchoParams(const TCHAR* pathToSound, float fWetDryMix, float fFeedback, float fLeftDelay, float fRightDelay, int IPanDelay);
		void SetDistortion(const TCHAR* pathToSound, int enable);
		void SetDistortionParams(const TCHAR* pathToSound, float fGain, float fEdge, float fPostEQCenterFrequency, float fPostEQBandwidth, float fPreLowpassCutoff);
		void SetFlanger(const TCHAR* pathToSound, int enable);
		void SetFlangerParams(const TCHAR* pathToSound, float fWetDryMix, float fDepth, float fFeedback, float fFrequency, int triangleWaveForm, float fDelay, int IPhase);
		void SetGargle(const TCHAR* pathToSound, int enable);
		void SetGargleParams(const TCHAR* pathToSound, int rateHz, int sinusWaveForm);
		void SetI3DL2(const TCHAR* pathToSound, int enable);
		void SetI3DL2Params(const TCHAR* pathToSound, int IRoom, int IRoomHF, float fIRoomRolloffFactor, float fIDecayTime, float fIDecayHFRatio, int IReflections, float fIReflectionsDelay, int IReverb, float fIReverbDelay, float fIDiffusion, float fIDensity, float fIHFReference);
		void SetParamEq(const TCHAR* pathToSound, int enable);
		void SetParamEqParams(const TCHAR* pathToSound, float fCenter, float fBandwidth, float fGain);
		void SetWaves(const TCHAR* pathToSound, int enable);
		void SetWavesParams(const TCHAR* pathToSound, float fInGain, float fReverbMix, float fReverbTime, float fHighFreqRTRatio);

		void SetChorusID(int id, int enable);
		void SetChorusParamsID(int id, float fWetDryMix, float fDepth, float fFeedback, float fFrequency, int sinusWaveForm, float fDelay, int IPhase);
		void SetCompressorID(int id, int enable);
		void SetCompressorParamsID(int id, float fGain, float fAttack, float fRelease, float fThreshold, float fRatio, float fPredelay);
		void SetEchoID(int id, int enable);
		void SetEchoParamsID(int id, float fWetDryMix, float fFeedback, float fLeftDelay, float fRightDelay, int IPanDelay);
		void SetDistortionID(int id, int enable);
		void SetDistortionParamsID(int id, float fGain, float fEdge, float fPostEQCenterFrequency, float fPostEQBandwidth, float fPreLowpassCutoff);
		void SetFlangerID(int id, int enable);
		void SetFlangerParamsID(int id, float fWetDryMix, float fDepth, float fFeedback, float fFrequency, int triangleWaveForm, float fDelay, int IPhase);
		void SetGargleID(int id, int enable);
		void SetGargleParamsID(int id, int rateHz, int sinusWaveForm);
		void SetI3DL2ID(int id, int enable);
		void SetI3DL2ParamsID(int id, int IRoom, int IRoomHF, float fIRoomRolloffFactor, float fIDecayTime, float fIDecayHFRatio, int IReflections, float fIReflectionsDelay, int IReverb, float fIReverbDelay, float fIDiffusion, float fIDensity, float fIHFReference);
		void SetParamEqID(int id, int enable);
		void SetParamEqParamsID(int id, float fCenter, float fBandwidth, float fGain);
		void SetWavesID(int id, int enable);
		void SetWavesParamsID(int id, float fInGain, float fReverbMix, float fReverbTime, float fHighFreqRTRatio);
		
		void CreateRecorder(const TCHAR* dID);

		void CreateIrrKDevice(const TCHAR* driver, const TCHAR* dID);

		void StartRecording(int sRate);
		void StopRecording(const TCHAR* name);
		void SaveToWAV(const TCHAR* path);
		void LoadPlugins(const TCHAR* path);

	/// Conditions

		bool IsIrrKlangCreated();

		bool IsSoundPlaying(const TCHAR* pathToSound);
		bool IsSoundPaused(const TCHAR* pathToSound);

		bool IsSoundPlayingID(int id);
		bool IsSoundPausedID(int id);

		bool IsMicRecorderCreated();

	/// Expressions

		float GetListenerX();
		float GetListenerY();
		float GetListenerZ();
		
		float GetListenerXR();
		float GetListenerYR();
		float GetListenerZR();

		float GetSoundX(const TCHAR* pathToSound);
		float GetSoundY(const TCHAR* pathToSound);
		float GetSoundZ(const TCHAR* pathToSound);
		
		float GetSoundMinD(const TCHAR* pathToSound);
		float GetSoundMaxD(const TCHAR* pathToSound);

		float GetSoundXV(const TCHAR* pathToSound);
		float GetSoundYV(const TCHAR* pathToSound);
		float GetSoundZV(const TCHAR* pathToSound);

		float GetMasterVol();

		float GetListenerXV();
		float GetListenerYV();
		float GetListenerZV();

		float GetSoundVol(const TCHAR* pathToSound);
		int GetPlaybackPos(const TCHAR* pathToSound);
		int GetSoundLen(const TCHAR* pathToSound);
		float GetPlaybackSpd(const TCHAR* pathToSound);
		float GetSoundPan(const TCHAR* pathToSound);
		
		float GetSoundXID(int id);
		float GetSoundYID(int id);
		float GetSoundZID(int id);
		float GetSoundMinDID(int id);
		float GetSoundMaxDID(int id);
		float GetSoundXVID(int id);
		float GetSoundYVID(int id);
		float GetSoundZVID(int id);

		float GetSoundVolID(int id);
		int GetPlaybackPosID(int id);
		int GetSoundLenID(int id);
		float GetPlaybackSpdID(int id);
		float GetSoundPanID(int id);

		int GetMicCount();
		const TCHAR* GetMicDesc(int index);
		const TCHAR* GetMicID(int index);

		int GetSoundDevCount();
		const TCHAR* GetSoundDevDesc(int index);
		const TCHAR* GetSoundDevID(int index);

		const TCHAR* GetDriver();

	/* These are called if there's no function linked to an ID */

	void UnlinkedAction(int ID);
	long UnlinkedCondition(int ID);
	long UnlinkedExpression(int ID);




	/*  These replace the functions like HandleRunObject that used to be
		implemented in Runtime.cpp. They work exactly the same, but they're
		inside the extension class.
	*/

	REFLAG Handle();
	REFLAG Display();

	short FusionRuntimePaused();
	short FusionRuntimeContinued();
};
