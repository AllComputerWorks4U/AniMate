#pragma once

#ifdef DLL_EXPORTING
    #define EXPORT_FUNCTION __declspec(dllexport)
#else 
    #define EXPORT_FUNCTION __declspec(dllimport)
#endif

typedef void (*LetterAnimation)(const char*);

extern "C" {
    EXPORT_FUNCTION void AniMate(const char* target_message, LetterAnimation goprint);
}