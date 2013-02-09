#ifndef LANGUAGERECOGNIZER_H_INCLUDED
#define LANGUAGERECOGNIZER_H_INCLUDED

#include <include/PlayThread.h>

enum RunState {STOPPED, PLAYING, RECORDING};

class LanguageRecognizer{

    private:

        wxThread *RecordThread;

        PlayThread *Player;

        RunState State;

    public:

        LanguageRecognizer();

        ~LanguageRecognizer();

        int Record();

        int Play();

        int Analyze();

        int RunningState();

        int Stop();
};



#endif // LANGUAGERECOGNIZER_H_INCLUDED
