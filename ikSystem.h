#pragma once

#include <Common.h>
#include <iostream>
#include <vector>
#include <functional>

// Custom irrKlang sound management vector so we can modify sounds by pathname or ID within Fusion
struct SoundData {
    irrklang::ISound* pSound = nullptr;
    std::wstring fileName;
    int ID = 0;
    bool sfxEnabled;
};

struct IkData {
    using SoundDataVec = std::vector<SoundData>;
    SoundDataVec pSoundDatas;
};

extern SoundData soundData;

extern IkData ikData;

class SoundStopEventReceiver : public irrklang::ISoundStopEventReceiver
{
public:
    virtual void OnSoundStopped(irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE eventCause, void* userData)
    {
        for (auto it = ikData.pSoundDatas.begin(); it != ikData.pSoundDatas.end(); ++it)
        {
            if (it->pSound == sound)
            {
                ikData.pSoundDatas.erase(it);
                break;
            }
        }
    }
};

void writeWaveFile(const char* filename, irrklang::SAudioStreamFormat format, void* data);

extern SoundStopEventReceiver soundStopEventReceiver;
