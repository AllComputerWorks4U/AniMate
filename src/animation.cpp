#include "./Include/animate.h"
#include <cstring>
#include <string>
#include <thread>

extern "C" void AniMate (const char* target_message, LetterAnimation goprint) {
    char keyboardChars[] = {
        ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        ':', ';', '<', '=', '>', '?', '@',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        '[', ']', '^', '_', '`',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '{', '|', '}', '~'
    };
    
    
    unsigned int GuessPosition = 0;
    unsigned int MessageLen = strlen(target_message);
    std::string MessageLoad(MessageLen, ' ');

    while (GuessPosition <  MessageLen) {
        unsigned long int CharN = 0;

        while (MessageLoad[GuessPosition] != target_message[GuessPosition]) {
            std::this_thread::sleep_for(std::chrono::microseconds(1000));
            MessageLoad[GuessPosition] = keyboardChars[CharN++];
            
            goprint(MessageLoad.c_str());
            
        }
        GuessPosition++;
    }
}