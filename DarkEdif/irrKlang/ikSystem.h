#pragma once

#include <Common.hpp>
#include <iostream>
#include <vector>
#include <functional>

// Custom irrKlang sound management vector so we can modify sounds by pathname or ID within Fusion
struct SoundData
{
    irrklang::ISound* pSound = nullptr;
    std::wstring fileName;
    int ID = 0;
    bool sfxEnabled;
};

struct IkData
{
    using SoundDataVec = std::vector<SoundData>;
    SoundDataVec pSoundDatas;
};

class SoundStopEventReceiver : public irrklang::ISoundStopEventReceiver
{
public:
	void OnSoundStopped(irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE eventCause, void* userData) override;
};

// Function for writing recorded mic to wave file
// Via https://ambiera.com/forum.php?t=969
void writeWaveFile(const char* filename, irrklang::SAudioStreamFormat format, void* data);


extern SoundData soundData;

extern IkData ikData;

extern SoundStopEventReceiver soundStopEventReceiver;
