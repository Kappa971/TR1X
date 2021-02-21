#include "3dsystem/phd_math.h"
#include "game/data.h"
#include "game/game.h"
#include "specific/file.h"
#include "specific/init.h"
#include "specific/shed.h"
#include "specific/sndpc.h"
#include "util.h"
#include <stdarg.h>
#include <time.h>
#include <windows.h>

void __cdecl DB_Log(char* a1, ...)
{
    va_list va;
    char buffer[256] = { 0 };

    va_start(va, a1);
    if (!dword_45A1F0) {
        vsprintf(buffer, a1, va);
        TRACE(buffer);
        OutputDebugStringA(buffer);
        OutputDebugStringA("\n");
    }
}

void __cdecl S_InitialiseSystem()
{
    TRACE("");
    FindCdDrive();

    GameVidWidth = 640;
    GameVidHeight = 480;

    DumpX = 0;
    DumpY = 0;
    DumpWidth = 640;
    DumpHeight = 480;

    sub_4380E0(&GameVidWidth);

    SoundStart();
    if (SoundInit() == -1) {
        SoundIsActive = 0;
    }

    CalculateWibbleTable();

    GameMemorySize = 0x380000;

    InitialiseHardware();
}

void __cdecl init_game_malloc()
{
    TRACE("");
    GameAllocMemPointer = GameMemoryPointer;
    GameAllocMemFree = GameMemorySize;
    GameAllocMemUsed = 0;
}

void __cdecl game_free(int free_size)
{
    TRACE("");
    GameAllocMemPointer -= free_size;
    GameAllocMemFree += free_size;
    GameAllocMemUsed -= free_size;
}

void __cdecl CalculateWibbleTable()
{
    for (int i = 0; i < WIBBLE_SIZE; i++) {
        PHD_ANGLE angle = (i * 65536) / WIBBLE_SIZE;
        WibbleTable[i] = phd_sin(angle) * MAX_WIBBLE >> W2V_SHIFT;
        ShadeTable[i] = phd_sin(angle) * MAX_SHADE >> W2V_SHIFT;
        RandTable[i] = (GetRandomDraw() >> 5) - 0x01ff;
    }
}

void __cdecl S_SeedRandom()
{
    time_t lt = time(0);
    struct tm* tptr = localtime(&lt);
    SeedRandomControl(tptr->tm_sec + 57 * tptr->tm_min + 3543 * tptr->tm_hour);
    SeedRandomDraw(tptr->tm_sec + 43 * tptr->tm_min + 3477 * tptr->tm_hour);
}

void Tomb1MInjectSpecificInit()
{
    INJECT(0x0041E100, S_InitialiseSystem);
    INJECT(0x0041E2C0, init_game_malloc);
    INJECT(0x0041E3B0, game_free);
    INJECT(0x0042A2C0, DB_Log);
}
