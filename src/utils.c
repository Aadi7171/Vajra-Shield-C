#include "utils.h"
#include <windows.h>

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_banner() {
    printf("%s%s", COLOR_BLUE, COLOR_BOLD);
    printf("============================================================\n");
    printf(" ||            VAJRA-SHIELD: EDGE AI TERMINAL            || \n");
    printf(" ||       Proactive Forensic Blackbox (Simulation)       || \n");
    printf("============================================================\n");
    printf("%s", COLOR_RESET);
}

void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#endif
}

double random_double(double min, double max) {
    double scale = rand() / (double) RAND_MAX;
    return min + scale * ( max - min );
}
