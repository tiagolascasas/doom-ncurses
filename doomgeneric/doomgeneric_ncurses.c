#include "doomkeys.h"

#include "doomgeneric.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

long frames = 0;

void DG_Init()
{
    printf("\033[2J");
    printf("\033[H");
}

void DG_DrawFrame()
{
    printf("\033[2J");
    printf("\033[H");
    printf("%ld\n", frames);
    frames++;
}

void DG_SleepMs(uint32_t ms)
{
    usleep(ms * 1000);
}

uint32_t DG_GetTicksMs()
{
    struct timeval tp;
    struct timezone tzp;

    gettimeofday(&tp, &tzp);

    return (tp.tv_sec * 1000) + (tp.tv_usec / 1000); /* return milliseconds */
}

int DG_GetKey(int *pressed, unsigned char *doomKey)
{
    return 0;
}

void DG_SetWindowTitle(const char *title)
{
    printf("\033]0;%s\007", "DOOM");
    fflush(stdout);
}

int main(int argc, char **argv)
{
    doomgeneric_Create(argc, argv);

    for (int i = 0;; i++)
    {
        doomgeneric_Tick();
    }

    return 0;
}