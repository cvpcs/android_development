/*
 * Copyright 2008, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "PluginObject.h"
#include <stdio.h>

#ifndef audioPlugin__DEFINED
#define audioPlugin__DEFINED

struct SoundPlay {
    NPP             instance;
    ANPAudioTrack*  track;
    FILE*           file;
    int             fileSize;
    int             progress; // value between 0 and 100
};

class AudioPlugin : public SubPlugin {
public:
    AudioPlugin(NPP inst);
    virtual ~AudioPlugin();
    virtual bool supportsDrawingModel(ANPDrawingModel);
    virtual void draw(ANPCanvas*);
    virtual int16 handleEvent(const ANPEvent* evt);
private:

    ANPRectF    m_trackRect;
    ANPRectF    m_playRect;
    ANPRectF    m_pauseRect;
    ANPRectF    m_stopRect;

    ANPPaint*   m_paintTrack;
    ANPPaint*   m_paintRect;
    ANPPaint*   m_paintText;

    ANPPaint*   m_paintTrackProgress;
    ANPPaint*   m_paintActiveRect;

    SoundPlay*  m_soundPlay;

    bool        m_activeTouch;
    ANPRectF*   m_activeTouchRect;
    ANPRectF*   m_activeRect;

    ANPPaint* getPaint(ANPRectF*);
    ANPRectF* validTouch(int x, int y);
    void handleTouch(int x, int y);
    void invalActiveRect();


};

#endif // audioPlugin__DEFINED