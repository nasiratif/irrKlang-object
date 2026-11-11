#pragma once

#include "DarkEdif.hpp"
#include <IrrKlang\irrKlang.h>

namespace irrExtension
{
	// Custom irrKlang sound management vector so we can modify sounds by pathname or ID within Fusion
	struct SoundData
	{
		irrklang::ISound* pSound = nullptr;
		std::wstring fileName;
		int ID = 0;
		bool sfxEnabled;
	};

	// Stop event receiver class to remove sounds from the internal list when they have stopped
	class SoundStopEventReceiver : public irrklang::ISoundStopEventReceiver
	{
	public:
		SoundStopEventReceiver(Extension* pExt);
		void OnSoundStopped(irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE eventCause, void* userData) override;
	private:
		Extension* pExt;
	};

	// Function for writing recorded mic to wave file
	// Via https://ambiera.com/forum.php?t=969
	void WriteWaveFile(const char* filename, irrklang::SAudioStreamFormat format, void* data);
}
