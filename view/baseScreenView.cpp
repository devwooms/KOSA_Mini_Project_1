#include "baseScreenView.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

void baseScreenView::clearScreen() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}