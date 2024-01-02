#include "Common.h"
#include <ikSystem.h>
#include <Expbool.h>

void Extension::PlaySound(const TCHAR* pathToSound, int id, int SFX)
{  
    soundData.sfxEnabled = TrueFalse(SFX);

    soundData.fileName = DarkEdif::TStringToWide(pathToSound);
    
    if (audio)
        soundData.pSound = audio->play2D(DarkEdif::TStringToUTF8(pathToSound).c_str(), false, false, true, irrklang::ESM_AUTO_DETECT, soundData.sfxEnabled);

    soundData.ID = id;
    
    if (soundData.pSound)
        soundData.pSound->setSoundStopEventReceiver(&soundStopEventReceiver);
        ikData.pSoundDatas.emplace_back(soundData);
}

void Extension::PlayLoopingSound(const TCHAR* pathToSound, int id, int SFX)
{
    soundData.sfxEnabled = TrueFalse(SFX);

    soundData.fileName = DarkEdif::TStringToWide(pathToSound);

    if (audio)
        soundData.pSound = audio->play2D(DarkEdif::TStringToUTF8(pathToSound).c_str(), true, false, true, irrklang::ESM_AUTO_DETECT, soundData.sfxEnabled);

    soundData.ID = id;

    if (soundData.pSound)
        soundData.pSound->setSoundStopEventReceiver(&soundStopEventReceiver);
        ikData.pSoundDatas.emplace_back(soundData);
}

void Extension::StopSound(const TCHAR* pathToSound)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->stop();
    }
}

void Extension::Play3DSound(const TCHAR* pathToSound, float xPos, float yPos, float zPos, int id, int SFX)
{ 
    soundData.sfxEnabled = TrueFalse(SFX);

    soundData.fileName = DarkEdif::TStringToWide(pathToSound);

    if (audio)
        soundData.pSound = audio->play3D(DarkEdif::TStringToUTF8(pathToSound).c_str(), irrklang::vec3df(xPos, yPos, zPos), false, false, true, irrklang::ESM_AUTO_DETECT, soundData.sfxEnabled);

    soundData.ID = id;

    if (soundData.pSound)
        soundData.pSound->setSoundStopEventReceiver(&soundStopEventReceiver);
        ikData.pSoundDatas.emplace_back(soundData);
}

void Extension::PlayLooping3DSound(const TCHAR* pathToSound, float xPos, float yPos, float zPos, int id, int SFX)
{
    soundData.sfxEnabled = TrueFalse(SFX);

    soundData.fileName = DarkEdif::TStringToWide(pathToSound);
    
    if (audio)
        soundData.pSound = audio->play3D(DarkEdif::TStringToUTF8(pathToSound).c_str(), irrklang::vec3df(xPos, yPos, zPos), true, false, true, irrklang::ESM_AUTO_DETECT, soundData.sfxEnabled);

    soundData.ID = id;

    if (soundData.pSound)
        soundData.pSound->setSoundStopEventReceiver(&soundStopEventReceiver);
        ikData.pSoundDatas.emplace_back(soundData);
}

void Extension::SetListenerPos(float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, float xVel, float yVel, float zVel)
{
    listenerPos = irrklang::vec3df(xPos, yPos, zPos);
    listenerRot = irrklang::vec3df(xRot, yRot, zRot);
    listenerVel = irrklang::vec3df(xVel, yVel, zVel);

    if (audio)
        audio->setListenerPosition(listenerPos, listenerRot, listenerVel);
}

void Extension::SetSoundPos(const TCHAR* pathToSound, float xPos, float yPos, float zPos)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->setPosition(irrklang::vec3df(xPos, yPos, zPos));
    }
}

void Extension::SetMinDis(const TCHAR* pathToSound, float dis)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->setMinDistance(dis);
    }
}

void Extension::SetMaxDis(const TCHAR* pathToSound, float dis)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->setMaxDistance(dis);
    }
}

void Extension::SetRolloff(float rolloff)
{
    if (audio)
        audio->setRolloffFactor(rolloff);
}

void Extension::SetDopplerParams(float dopplerFactor, float distanceFactor)
{
    if (audio)
        audio->setDopplerEffectParameters(dopplerFactor, distanceFactor);
}

void Extension::SetSoundVel(const TCHAR* pathToSound, float xVel, float yVel, float zVel)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->setVelocity(irrklang::vec3df(xVel, yVel, zVel));
    }
}

void Extension::SetMasterVol(float vol)
{
    if (audio)
        audio->setSoundVolume(vol);
}

void Extension::SetSoundVol(const TCHAR* pathToSound, float vol)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->setVolume(vol);
    }
}

void Extension::PauseSound(const TCHAR* pathToSound)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->setIsPaused(true);
    }
}

void Extension::UnpauseSound(const TCHAR* pathToSound)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->setIsPaused(false);
    }
}

void Extension::PauseAll()
{
    if (audio)
    {
        audio->setAllSoundsPaused(true);
    }
}

void Extension::UnpauseAll()
{
    if (audio)
    {
        audio->setAllSoundsPaused(false);
    }
}

void Extension::SetPlaybackPos(const TCHAR* pathToSound, int pos)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->setPlayPosition(pos);
    }
}

void Extension::SetPlaybackSpeed(const TCHAR* pathToSound, float spd)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->setPlaybackSpeed(spd);
    }
}

void Extension::SetSoundPan(const TCHAR* pathToSound, float pan)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        p.pSound->setPan(pan);
    }
}

void Extension::StopSoundID(int id)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->stop();
    }
}

void Extension::SetSoundPosID(int id, float xPos, float yPos, float zPos)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->setPosition(irrklang::vec3df(xPos, yPos, zPos));
    }
}

void Extension::SetMinDisID(int id, float dis)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->setMinDistance(dis);
    }
}

void Extension::SetMaxDisID(int id, float dis)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->setMaxDistance(dis);
    }
}

void Extension::SetSoundVelID(int id, float xVel, float yVel, float zVel)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->setVelocity(irrklang::vec3df(xVel, yVel, zVel));
    }
}

void Extension::PauseSoundID(int id)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->setIsPaused(true);
    }
}

void Extension::UnpauseSoundID(int id)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->setIsPaused(false);
    }
}

void Extension::SetPlaybackPosID(int id, int pos)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->setPlayPosition(pos);
    }
}

void Extension::SetPlaybackSpeedID(int id, float spd)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->setPlaybackSpeed(spd);
    }
}

void Extension::SetSoundPanID(int id, float pan)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->setPan(pan);
    }
}

void Extension::SetSoundVolID(int id, float vol)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        p.pSound->setVolume(vol);
    }
}

void Extension::SetChorus(const TCHAR* pathToSound, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableChorusSoundEffect();
                }
                else
                {
                    sfx->disableChorusSoundEffect();
                }
            }
        }
    }
}

void Extension::SetChorusParams(const TCHAR* pathToSound, float fWetDryMix, float fDepth, float fFeedback, float fFrequency, int sinusWaveForm, float fDelay, int IPhase)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableChorusSoundEffect(fWetDryMix, fDepth, fFeedback, fFrequency, TrueFalse(sinusWaveForm), fDelay, IPhase);
            }
        }
    }
}

void Extension::SetCompressor(const TCHAR* pathToSound, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableCompressorSoundEffect();
                }
                else
                {
                    sfx->disableCompressorSoundEffect();
                }
            }
        }
    }
}

void Extension::SetCompressorParams(const TCHAR* pathToSound, float fGain, float fAttack, float fRelease, float fThreshold, float fRatio, float fPredelay)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableCompressorSoundEffect(fGain, fAttack, fRelease, fThreshold, fRatio, fPredelay);
            }
        }
    }
}

void Extension::SetEcho(const TCHAR* pathToSound, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableEchoSoundEffect();
                }
                else
                {
                    sfx->disableEchoSoundEffect();
                }
            }
        }
    }
}

void Extension::SetEchoParams(const TCHAR* pathToSound, float fWetDryMix, float fFeedback, float fLeftDelay, float fRightDelay, int IPanDelay)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableEchoSoundEffect(fWetDryMix, fFeedback, fLeftDelay, fRightDelay, IPanDelay);
            }
        }
    }
}

void Extension::SetDistortion(const TCHAR* pathToSound, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableDistortionSoundEffect();
                }
                else
                {
                    sfx->disableDistortionSoundEffect();
                }
            }
        }
    }
}

void Extension::SetDistortionParams(const TCHAR* pathToSound, float fGain, float fEdge, float fPostEQCenterFrequency, float fPostEQBandwidth, float fPreLowpassCutoff)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableDistortionSoundEffect(fGain, fEdge, fPostEQCenterFrequency, fPostEQBandwidth, fPreLowpassCutoff);
            }
        }
    }
}

void Extension::SetFlanger(const TCHAR* pathToSound, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableFlangerSoundEffect();
                }
                else
                {
                    sfx->disableFlangerSoundEffect();
                }
            }
        }
    }
}

void Extension::SetFlangerParams(const TCHAR* pathToSound, float fWetDryMix, float fDepth, float fFeedback, float fFrequency, int triangleWaveForm, float fDelay, int IPhase)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableFlangerSoundEffect(fWetDryMix, fDepth, fFeedback, fFrequency, TrueFalse(triangleWaveForm), fDelay, IPhase);
            }
        }
    }
}

void Extension::SetGargle(const TCHAR* pathToSound, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableGargleSoundEffect();
                }
                else
                {
                    sfx->disableGargleSoundEffect();
                }
            }
        }
    }
}

void Extension::SetGargleParams(const TCHAR* pathToSound, int rateHz, int sinusWaveForm)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableGargleSoundEffect(rateHz, TrueFalse(sinusWaveForm));
            }
        }
    }
}

void Extension::SetI3DL2(const TCHAR* pathToSound, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableI3DL2ReverbSoundEffect();
                }
                else
                {
                    sfx->disableI3DL2ReverbSoundEffect();
                }
            }
        }
    }
}

void Extension::SetI3DL2Params(const TCHAR* pathToSound, int IRoom, int IRoomHF, float fIRoomRolloffFactor, float fIDecayTime, float fIDecayHFRatio, int IReflections, float fIReflectionsDelay, int IReverb, float fIReverbDelay, float fIDiffusion, float fIDensity, float fIHFReference)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableI3DL2ReverbSoundEffect(IRoom, IRoomHF, fIRoomRolloffFactor, fIDecayTime, fIDecayHFRatio, IReflections, fIReflectionsDelay, IReverb, fIReverbDelay, fIDiffusion, fIDensity, fIHFReference);
            }
        }
    }
}

void Extension::SetParamEq(const TCHAR* pathToSound, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableParamEqSoundEffect();
                }
                else
                {
                    sfx->disableParamEqSoundEffect();
                }
            }
        }
    }
}

void Extension::SetParamEqParams(const TCHAR* pathToSound, float fCenter, float fBandwidth, float fGain)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableParamEqSoundEffect(fCenter, fBandwidth, fGain);
            }
        }
    }
}

void Extension::SetWaves(const TCHAR* pathToSound, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableWavesReverbSoundEffect();
                }
                else
                {
                    sfx->disableWavesReverbSoundEffect();
                }
            }
        }
    }
}

void Extension::SetWavesParams(const TCHAR* pathToSound, float fInGain, float fReverbMix, float fReverbTime, float fHighFreqRTRatio)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.fileName != DarkEdif::TStringToWide(pathToSound))
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableWavesReverbSoundEffect(fInGain, fReverbMix, fReverbTime, fHighFreqRTRatio);
            }
        }
    }
}

// ID

void Extension::SetChorusID(int id, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableChorusSoundEffect();
                }
                else
                {
                    sfx->disableChorusSoundEffect();
                }
            }
        }
    }
}

void Extension::SetChorusParamsID(int id, float fWetDryMix, float fDepth, float fFeedback, float fFrequency, int sinusWaveForm, float fDelay, int IPhase)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableChorusSoundEffect(fWetDryMix, fDepth, fFeedback, fFrequency, TrueFalse(sinusWaveForm), fDelay, IPhase);
            }
        }
    }
}

void Extension::SetCompressorID(int id, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableCompressorSoundEffect();
                }
                else
                {
                    sfx->disableCompressorSoundEffect();
                }
            }
        }
    }
}

void Extension::SetCompressorParamsID(int id, float fGain, float fAttack, float fRelease, float fThreshold, float fRatio, float fPredelay)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableCompressorSoundEffect(fGain, fAttack, fRelease, fThreshold, fRatio, fPredelay);
            }
        }
    }
}

void Extension::SetEchoID(int id, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableEchoSoundEffect();
                }
                else
                {
                    sfx->disableEchoSoundEffect();
                }
            }
        }
    }
}

void Extension::SetEchoParamsID(int id, float fWetDryMix, float fFeedback, float fLeftDelay, float fRightDelay, int IPanDelay)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableEchoSoundEffect(fWetDryMix, fFeedback, fLeftDelay, fRightDelay, IPanDelay);
            }
        }
    }
}

void Extension::SetDistortionID(int id, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableDistortionSoundEffect();
                }
                else
                {
                    sfx->disableDistortionSoundEffect();
                }
            }
        }
    }
}

void Extension::SetDistortionParamsID(int id, float fGain, float fEdge, float fPostEQCenterFrequency, float fPostEQBandwidth, float fPreLowpassCutoff)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableDistortionSoundEffect(fGain, fEdge, fPostEQCenterFrequency, fPostEQBandwidth, fPreLowpassCutoff);
            }
        }
    }
}

void Extension::SetFlangerID(int id, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableFlangerSoundEffect();
                }
                else
                {
                    sfx->disableFlangerSoundEffect();
                }
            }
        }
    }
}

void Extension::SetFlangerParamsID(int id, float fWetDryMix, float fDepth, float fFeedback, float fFrequency, int triangleWaveForm, float fDelay, int IPhase)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableFlangerSoundEffect(fWetDryMix, fDepth, fFeedback, fFrequency, TrueFalse(triangleWaveForm), fDelay, IPhase);
            }
        }
    }
}

void Extension::SetGargleID(int id, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableGargleSoundEffect();
                }
                else
                {
                    sfx->disableGargleSoundEffect();
                }
            }
        }
    }
}

void Extension::SetGargleParamsID(int id, int rateHz, int sinusWaveForm)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableGargleSoundEffect(rateHz, TrueFalse(sinusWaveForm));
            }
        }
    }
}

void Extension::SetI3DL2ID(int id, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableI3DL2ReverbSoundEffect();
                }
                else
                {
                    sfx->disableI3DL2ReverbSoundEffect();
                }
            }
        }
    }
}

void Extension::SetI3DL2ParamsID(int id, int IRoom, int IRoomHF, float fIRoomRolloffFactor, float fIDecayTime, float fIDecayHFRatio, int IReflections, float fIReflectionsDelay, int IReverb, float fIReverbDelay, float fIDiffusion, float fIDensity, float fIHFReference)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableI3DL2ReverbSoundEffect(IRoom, IRoomHF, fIRoomRolloffFactor, fIDecayTime, fIDecayHFRatio, IReflections, fIReflectionsDelay, IReverb, fIReverbDelay, fIDiffusion, fIDensity, fIHFReference);
            }
        }
    }
}

void Extension::SetParamEqID(int id, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableParamEqSoundEffect();
                }
                else
                {
                    sfx->disableParamEqSoundEffect();
                }
            }
        }
    }
}

void Extension::SetParamEqParamsID(int id, float fCenter, float fBandwidth, float fGain)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableParamEqSoundEffect(fCenter, fBandwidth, fGain);
            }
        }
    }
}

void Extension::SetWavesID(int id, int enable)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                if (enable == 1)
                {
                    sfx->enableWavesReverbSoundEffect();
                }
                else
                {
                    sfx->disableWavesReverbSoundEffect();
                }
            }
        }
    }
}

void Extension::SetWavesParamsID(int id, float fInGain, float fReverbMix, float fReverbTime, float fHighFreqRTRatio)
{
    for (auto p : ikData.pSoundDatas)
    {
        if (p.ID != id)
            continue;
        if (p.pSound)
        {
            irrklang::ISoundEffectControl* sfx = p.pSound->getSoundEffectControl();
            if (sfx)
            {
                sfx->enableWavesReverbSoundEffect(fInGain, fReverbMix, fReverbTime, fHighFreqRTRatio);
            }
        }
    }
}

void Extension::CreateRecorder(const TCHAR* dID)
{
    if (!recorder && audio)
        recorder = irrklang::createIrrKlangAudioRecorder(audio, driverChoice, DarkEdif::TStringToUTF8(dID).c_str());
}

void Extension::CreateIrrKDevice(const TCHAR* driver, const TCHAR* dID)
{
    if (!audio)
    {
        irrklang::E_SOUND_OUTPUT_DRIVER outputDriver;
        std::wstring driverW = driver;
        std::transform(driverW.begin(), driverW.end(), driverW.begin(), towupper);

        if (driverW == L"AUTOMATIC")
            outputDriver = irrklang::ESOD_AUTO_DETECT;
        else if (driverW == L"DIRECTSOUND")
            outputDriver = irrklang::ESOD_DIRECT_SOUND;
        else if (driverW == L"DIRECTSOUND8")
            outputDriver = irrklang::ESOD_DIRECT_SOUND_8;
        else if (driverW == L"WINMM")
            outputDriver = irrklang::ESOD_WIN_MM;
        else
            outputDriver = driverChoice;

        if (use3D)
            audio = irrklang::createIrrKlangDevice(outputDriver, irrklang::ESEO_USE_3D_BUFFERS, DarkEdif::TStringToUTF8(dID).c_str());
        else
            audio = irrklang::createIrrKlangDevice(outputDriver, irrklang::ESEO_DEFAULT_OPTIONS, DarkEdif::TStringToUTF8(dID).c_str());
    }

    if (audio)
        audio->setListenerPosition(listenerPos, listenerRot, listenerVel, irrklang::vec3df(0, 1, 0));
}

void Extension::StartRecording(int sRate)
{
    if (recorder)
        recorder->startRecordingBufferedAudio(sRate);
}

void Extension::StopRecording(const TCHAR* name)
{
    if (recorder)
    {
        recorder->stopRecordingAudio();
        recorder->addSoundSourceFromRecordedAudio(DarkEdif::TStringToUTF8(name).c_str());
    }
}

void Extension::SaveToWAV(const TCHAR* path)
{
    if (recorder && recorder->getRecordedAudioData())
        writeWaveFile(DarkEdif::TStringToUTF8(path).c_str(), recorder->getAudioFormat(), recorder->getRecordedAudioData());
}

void Extension::LoadPlugins(const TCHAR* path)
{
    if (audio)
        audio->loadPlugins(DarkEdif::TStringToUTF8(path).c_str());
}