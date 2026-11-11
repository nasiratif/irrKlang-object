#include "Common.hpp"
#include "irrExtension.hpp"

float Extension::GetListenerX()
{
	return listenerPos.X;
}

float Extension::GetListenerY()
{
	return listenerPos.Y;
}

float Extension::GetListenerZ()
{
	return listenerPos.Z;
}

float Extension::GetListenerXR()
{
	return listenerRot.X;
}

float Extension::GetListenerYR()
{
	return listenerRot.Y;
}

float Extension::GetListenerZR()
{
	return listenerRot.Z;
}

float Extension::GetSoundX(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getPosition().X;
	}

	return 0.0f;
}

float Extension::GetSoundY(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getPosition().Y;
	}

	return 0.0f;
}

float Extension::GetSoundZ(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getPosition().Z;
	}

	return 0.0f;
}

float Extension::GetSoundMinD(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getMinDistance();
	}

	return 0.0f;
}

float Extension::GetSoundMaxD(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getMaxDistance();
	}

	return 0.0f;
}

float Extension::GetSoundXV(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getVelocity().X;
	}

	return 0.0f;
}

float Extension::GetSoundYV(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getVelocity().Y;
	}

	return 0.0f;
}

float Extension::GetSoundZV(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getVelocity().Z;
	}

	return 0.0f;
}

float Extension::GetMasterVol()
{
	if (audio)
		return audio->getSoundVolume();

	return 0.0f;
}

float Extension::GetListenerXV()
{
	return listenerVel.X;
}

float Extension::GetListenerYV()
{
	return listenerVel.Y;
}

float Extension::GetListenerZV()
{
	return listenerVel.Z;
}

float Extension::GetSoundVol(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getVolume();
	}

	return 0.0f;
}

int Extension::GetPlaybackPos(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getPlayPosition();
	}

	return 0;
}

int Extension::GetSoundLen(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getPlayLength();
	}

	return 0;
}

float Extension::GetPlaybackSpd(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getPlaybackSpeed();
	}

	return 0.0f;
}

float Extension::GetSoundPan(const TCHAR* pathToSound)
{
	for (auto p : currentSounds)
	{
		if (p.fileName != DarkEdif::TStringToWide(pathToSound))
			continue;
		return p.pSound->getPan();
	}

	return 0.0f;
}

float Extension::GetSoundXID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getPosition().X;
	}

	return 0.0f;
}

float Extension::GetSoundYID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getPosition().Y;
	}

	return 0.0f;
}

float Extension::GetSoundZID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getPosition().Z;
	}

	return 0.0f;
}

float Extension::GetSoundMinDID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getMinDistance();
	}

	return 0.0f;
}

float Extension::GetSoundMaxDID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getMaxDistance();
	}

	return 0.0f;
}

float Extension::GetSoundXVID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getVelocity().X;
	}

	return 0.0f;
}

float Extension::GetSoundYVID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getVelocity().Y;
	}

	return 0.0f;
}

float Extension::GetSoundZVID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getVelocity().Z;
	}

	return 0.0f;
}

float Extension::GetSoundVolID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getVolume();
	}

	return 0.0f;
}

int Extension::GetPlaybackPosID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getPlayPosition();
	}

	return 0;
}

int Extension::GetSoundLenID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getPlayLength();
	}

	return 0;
}

float Extension::GetPlaybackSpdID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getPlaybackSpeed();
	}

	return 0.0f;
}

float Extension::GetSoundPanID(int id)
{
	for (auto p : currentSounds)
	{
		if (p.ID != id)
			continue;
		return p.pSound->getPan();
	}

	return 0.0f;
}

int Extension::GetMicCount()
{
	return micList->getDeviceCount();
}

const TCHAR* Extension::GetMicDesc(int index)
{
	auto micDesc = micList->getDeviceDescription(index);
	return micDesc ? Runtime.CopyString(DarkEdif::UTF8ToTString(micDesc).c_str()) : _T("");
}

const TCHAR* Extension::GetMicID(int index)
{
	auto micID = micList->getDeviceID(index);
	return micID ? Runtime.CopyString(DarkEdif::UTF8ToTString(micID).c_str()) : _T("");
}

int Extension::GetSoundDevCount()
{
	return sndDevList->getDeviceCount();
}

const TCHAR* Extension::GetSoundDevDesc(int index)
{
	auto devDesc = sndDevList->getDeviceDescription(index);
	return devDesc ? Runtime.CopyString(DarkEdif::UTF8ToTString(devDesc).c_str()) : _T("");
}

const TCHAR* Extension::GetSoundDevID(int index)
{
	auto devID = sndDevList->getDeviceID(index);
	return devID ? Runtime.CopyString(DarkEdif::UTF8ToTString(devID).c_str()) : _T("");
}

const TCHAR* Extension::GetDriver()
{
	if (!audio)
		return _T("");

	auto driver = audio->getDriverName();
	return driver ? Runtime.CopyString(DarkEdif::UTF8ToTString(driver).c_str()) : _T("");
}
