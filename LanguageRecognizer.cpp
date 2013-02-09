#include <LanguageRecognizer.h>
#include <cstdlib>

LanguageRecognizer::LanguageRecognizer(){

}

int LanguageRecognizer::Record{
    return system("arecord -f cd -v -r 22050 -d 7 last.wav");
}

int LanguageRecognizer::Play{
    return system("aplay -f cd -v last.wav");
}
