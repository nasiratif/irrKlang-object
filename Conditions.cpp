#include "Common.h"
#include "ikSystem.h"

bool Extension::IsIrrKlangCreated()
{
	if (audio)
		return true;
	else
		return false;
}

bool Extension::IsSoundPlaying(const TCHAR* pathToSound)
{
	if (audio && audio->isCurrentlyPlaying(DarkEdif::TStringToUTF8(pathToSound).c_str()))
		return true;
	else
		return false;
}

bool Extension::IsSoundPaused(const TCHAR* pathToSound)
{
	for (auto p : ikData.pSoundDatas)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		if (p.pSound->getIsPaused())
			return true;
	}

	return false;
}

// irrKlang seemingly doesn't have any functions for checking if an ISound is playing or not, only by filename :|
bool Extension::IsSoundPlayingID(int id)
{
	for (auto p : ikData.pSoundDatas)
	{
		if (p.ID != id)
			continue;
		if (audio && audio->isCurrentlyPlaying(DarkEdif::TStringToUTF8(p.fileName).c_str()) && p.pSound)
			return true;
	}

	return false;
}

bool Extension::IsSoundPausedID(int id)
{
	for (auto p : ikData.pSoundDatas)
	{
		if (p.ID != id)
			continue;
		if (p.pSound->getIsPaused())
			return true;
	}

	return false;
}

bool Extension::IsMicRecorderCreated()
{
	if (recorder)
		return true;
	else
		return false;
}