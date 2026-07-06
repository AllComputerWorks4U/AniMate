#include <iostream>
#include <chrono>
#include <string.h>
#include "./Include/animate.h"

void CoutMessage (const char* PrintThis) {
    std::cout<<'\r'<<PrintThis<<std::flush;
}

int main () {
    unsigned int  count = 0;

    std::cout<<"\x1b[1A"<<"\x1b[2K";
    
    
    std::string Message;
    std::cout<<"Input message here: ";
    std::getline(std::cin, Message);

    AniMate(Message.c_str(), CoutMessage);
}