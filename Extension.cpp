/* irrKlang object
@nasirfoxx on Clickteam Community Forums */

#include "Common.hpp"
#include "ikSystem.h"

///
/// EXTENSION CONSTRUCTOR/DESTRUCTOR
///

Extension::Extension(RunObject* const _rdPtr, const EDITDATA* const edPtr, const CreateObjectInfo* const cobPtr) :
	rdPtr(_rdPtr), rhPtr(_rdPtr->get_rHo()->get_AdRunHeader()), Runtime(this), FusionDebugger(this)
{
	/*
		Link all your action/condition/expression functions to their IDs to match the
		IDs in the JSON here
	*/

	// Actions linking

	LinkAction(0, PlaySound);
	LinkAction(1, PlayLoopingSound);
	LinkAction(2, StopSound);

	LinkAction(3, Play3DSound);
	LinkAction(4, PlayLooping3DSound);
	LinkAction(5, SetListenerPos);
	LinkAction(6, SetSoundPos);
	LinkAction(7, SetMinDis);
	LinkAction(8, SetMaxDis);
	LinkAction(9, SetRolloff);
	LinkAction(10, SetDopplerParams);
	LinkAction(11, SetSoundVel);
	
	LinkAction(12, SetMasterVol);
	LinkAction(13, SetSoundVol);
	LinkAction(14, PauseSound);
	LinkAction(15, UnpauseSound);
	LinkAction(16, PauseAll);
	LinkAction(17, UnpauseAll);
	LinkAction(18, SetPlaybackPos);
	LinkAction(19, SetPlaybackSpeed);
	LinkAction(20, SetSoundPan);
	
	LinkAction(21, StopSoundID);

	LinkAction(22, SetSoundPosID);
	LinkAction(23, SetMinDisID);
	LinkAction(24, SetMaxDisID);
	LinkAction(25, SetSoundVelID);

	LinkAction(26, PauseSoundID);
	LinkAction(27, UnpauseSoundID);
	LinkAction(28, SetPlaybackPosID);
	LinkAction(29, SetPlaybackSpeedID);
	LinkAction(30, SetSoundPanID);
	LinkAction(31, SetSoundVolID);

	LinkAction(32, SetChorus);
	LinkAction(33, SetChorusParams);
	LinkAction(34, SetCompressor);
	LinkAction(35, SetCompressorParams);
	LinkAction(36, SetEcho);
	LinkAction(37, SetEchoParams);
	LinkAction(38, SetDistortion);
	LinkAction(39, SetDistortionParams);
	LinkAction(40, SetFlanger);
	LinkAction(41, SetFlangerParams);
	LinkAction(42, SetGargle);
	LinkAction(43, SetGargleParams);
	LinkAction(44, SetI3DL2);
	LinkAction(45, SetI3DL2Params);
	LinkAction(46, SetParamEq);
	LinkAction(47, SetParamEqParams);
	LinkAction(48, SetWaves);
	LinkAction(49, SetWavesParams);

	LinkAction(50, SetChorusID);
	LinkAction(51, SetChorusParamsID);
	LinkAction(52, SetCompressorID);
	LinkAction(53, SetCompressorParamsID);
	LinkAction(54, SetEchoID);
	LinkAction(55, SetEchoParamsID);
	LinkAction(56, SetDistortionID);
	LinkAction(57, SetDistortionParamsID);
	LinkAction(58, SetFlangerID);
	LinkAction(59, SetFlangerParamsID);
	LinkAction(60, SetGargleID);
	LinkAction(61, SetGargleParamsID);
	LinkAction(62, SetI3DL2ID);
	LinkAction(63, SetI3DL2ParamsID);
	LinkAction(64, SetParamEqID);
	LinkAction(65, SetParamEqParamsID);
	LinkAction(66, SetWavesID);
	LinkAction(67, SetWavesParamsID);

	LinkAction(68, CreateRecorder);
	
	LinkAction(69, CreateIrrKDevice);

	LinkAction(70, StartRecording);
	LinkAction(71, StopRecording);
	LinkAction(72, SaveToWAV);
	LinkAction(73, LoadPlugins);

	// Conditions linking

	LinkCondition(0, IsIrrKlangCreated);
	
	LinkCondition(1, IsSoundPlaying);
	LinkCondition(2, IsSoundPaused);

	LinkCondition(3, IsSoundPlayingID);
	LinkCondition(4, IsSoundPausedID);

	LinkCondition(5, IsMicRecorderCreated);

	// Expressions linking

	LinkExpression(0, GetListenerX);
	LinkExpression(1, GetListenerY);
	LinkExpression(2, GetListenerZ);
	
	LinkExpression(3, GetListenerXR);
	LinkExpression(4, GetListenerYR);
	LinkExpression(5, GetListenerZR);
	
	LinkExpression(6, GetSoundX);
	LinkExpression(7, GetSoundY);
	LinkExpression(8, GetSoundZ);

	LinkExpression(9, GetSoundMinD);
	LinkExpression(10, GetSoundMaxD);

	LinkExpression(11, GetSoundXV);
	LinkExpression(12, GetSoundYV);
	LinkExpression(13, GetSoundZV);

	LinkExpression(14, GetMasterVol);

	LinkExpression(15, GetListenerXV);
	LinkExpression(16, GetListenerYV);
	LinkExpression(17, GetListenerZV);

	LinkExpression(18, GetSoundVol);
	LinkExpression(19, GetPlaybackPos);
	LinkExpression(20, GetSoundLen);
	LinkExpression(21, GetPlaybackSpd);
	LinkExpression(22, GetSoundPan);

	LinkExpression(23, GetSoundXID);
	LinkExpression(24, GetSoundYID);
	LinkExpression(25, GetSoundZID);
	
	LinkExpression(26, GetSoundMinDID);
	LinkExpression(27, GetSoundMaxDID);
	
	LinkExpression(28, GetSoundXVID);
	LinkExpression(29, GetSoundYVID);
	LinkExpression(30, GetSoundZVID);

	LinkExpression(31, GetSoundVolID);
	LinkExpression(32, GetPlaybackPosID);
	LinkExpression(33, GetSoundLenID);
	LinkExpression(34, GetPlaybackSpdID);
	LinkExpression(35, GetSoundPanID);

	LinkExpression(36, GetMicCount);
	LinkExpression(37, GetMicDesc);
	LinkExpression(38, GetMicID);

	LinkExpression(39, GetSoundDevCount);
	LinkExpression(40, GetSoundDevDesc);
	LinkExpression(41, GetSoundDevID);

	LinkExpression(42, GetDriver);

	driver = DarkEdif::TStringToUTF8(edPtr->Props.GetPropertyStr("Device Driver"));

	autoIrrKlang = edPtr->Props.IsPropChecked("Automatically create irrKlang device");
	autoRecorder = edPtr->Props.IsPropChecked("Automatically create microphone recorder");
	use3D = edPtr->Props.IsPropChecked("Use 3D buffers");

	if (driver == "Automatic")
		driverChoice = irrklang::ESOD_AUTO_DETECT;
	else if (driver == "DirectSound")
		driverChoice = irrklang::ESOD_DIRECT_SOUND;
	else if (driver == "DirectSound8")
		driverChoice = irrklang::ESOD_DIRECT_SOUND_8;
	else if (driver == "WinMM")
		driverChoice = irrklang::ESOD_WIN_MM;
	else
		driverChoice = irrklang::ESOD_AUTO_DETECT;

	mList = irrklang::createAudioRecorderDeviceList(driverChoice);
	sList = irrklang::createSoundDeviceList(driverChoice);

	if (autoIrrKlang)
	{
		if (!audio)
		{
			if (use3D)
				audio = irrklang::createIrrKlangDevice(driverChoice, irrklang::ESEO_USE_3D_BUFFERS);
			else
				audio = irrklang::createIrrKlangDevice(driverChoice, irrklang::ESEO_DEFAULT_OPTIONS);
		}

		if (audio)
			audio->setListenerPosition(irrklang::vec3df(0, 0, 0), irrklang::vec3df(0, 0, 0), irrklang::vec3df(0, 0, 0), irrklang::vec3df(0, 1, 0));
	}

	if (autoRecorder && !recorder && audio)
		recorder = irrklang::createIrrKlangAudioRecorder(audio, driverChoice);

	/*
		This is where you'd do anything you'd do in CreateRunObject in the original SDK

		It's the only place you'll get access to edPtr at runtime, so you should transfer
		anything from edPtr to the extension class here.

	*/

	// Don't use "this" inside these lambda functions, always ext.
	// There can be nothing in the [] section of the lambda.
	// If you're not sure about lambdas, you can remove this debugger stuff without any side effects;
	// it's just an example of how to use the debugger. You can view it in Fusion itself to see.
	/*
	FusionDebugger.AddItemToDebugger(
		// reader function for your debug item
		[](Extension *ext, std::tstring &writeTo) {
			writeTo = _T("My text is: ") + ext->exampleDebuggerTextItem;
		},
		// writer function (can be null if you don't want user to be able to edit it in debugger)
		[](Extension *ext, std::tstring &newText)
		{
			ext->exampleDebuggerTextItem = newText;
			return true; // accept the changes
		}, 500, NULL
	);
	*/

}

Extension::~Extension()
{
	for (auto p : ikData.pSoundDatas) 
	{
		p.pSound->drop();
		p.pSound = 0;
	}

	if (recorder)
		recorder->drop();

	if (audio)
		audio->drop();
}


REFLAG Extension::Handle()
{
	/*
		If your extension will draw to the MMF window you should first
		check if anything about its display has changed :

			if (rdPtr->roc.rcChanged)
			  return REFLAG::DISPLAY;
			else
			  return REFLAG::NONE;

		You will also need to make sure you change this flag yourself
		to 1 whenever you want to redraw your object

		If your extension won't draw to the window, but it still needs
		to do something every MMF loop use :

			return REFLAG::NONE;

		If you don't need to do something every loop, use :

			return REFLAG::ONE_SHOT;

		This doesn't mean this function can never run again. If you want MMF
		to handle your object again (causing this code to run) use this function:

			Runtime.Rehandle();

		At the end of the loop this code will run

	*/

	// Must update irrKlang manually if Use 3D buffers is enabled
	if (audio && use3D) audio->update();

	// WILL be called next loop
	return REFLAG::NONE;
}


REFLAG Extension::Display()
{
	/*
		If you return REFLAG_DISPLAY in Handle() this routine will run.
	*/

	// Ok
	return REFLAG::DISPLAY;
}

short Extension::FusionRuntimePaused()
{

	// Ok
	return 0;
}

short Extension::FusionRuntimeContinued()
{

	// Ok
	return 0;
}


// These are called if there's no function linked to an ID

void Extension::UnlinkedAction(int ID)
{
	DarkEdif::MsgBox::Error(_T("Extension::UnlinkedAction() called"), _T("Running a fallback for action ID %d. Make sure you ran LinkAction()."), ID);
}

long Extension::UnlinkedCondition(int ID)
{
	DarkEdif::MsgBox::Error(_T("Extension::UnlinkedCondition() called"), _T("Running a fallback for condition ID %d. Make sure you ran LinkCondition()."), ID);
	return 0;
}

long Extension::UnlinkedExpression(int ID)
{
	DarkEdif::MsgBox::Error(_T("Extension::UnlinkedExpression() called"), _T("Running a fallback for expression ID %d. Make sure you ran LinkExpression()."), ID);
	// Unlinked A/C/E is fatal error , but try not to return null string and definitely crash it
	if ((size_t)ID < ::Edif::SDK->ExpressionInfos.size() && ::Edif::SDK->ExpressionInfos[ID]->Flags.ef == ExpReturnType::String)
		return (long)Runtime.CopyString(_T(""));
	return 0;
}
