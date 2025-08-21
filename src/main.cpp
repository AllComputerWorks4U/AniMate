#include <iostream>
#include <chrono>
#include <thread>
#include <string.h>

int main () {
    unsigned int  count = 0;
    char keyboardChars[] = {
        ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        ':', ';', '<', '=', '>', '?', '@',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        '[', ']', '^', '_', '`',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '{', '|', '}', '~'
    };

    std::cout<<"\x1b[1A"<<"\x1b[2K";
    
    
    std::string Message;
    std::cout<<"Input message here: ";
    std::getline(std::cin, Message);

    char Messageload [Message.length()];    

    while (count <  Message.length()) {
        unsigned long int i = 0;
        bool got = (Messageload[count] == Message[count]);

        while (!got) {
            std::this_thread::sleep_for(std::chrono::microseconds(1000));
            Messageload[count] = keyboardChars[i++];
            std::cout<<Messageload[count];

            if ((Messageload[count] == Message[count])) {
                got = true;
                count++;
            } else {
                std::cout<<'\b';
            }
            
        }
    }
    return 0;
}