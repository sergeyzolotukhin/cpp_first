#include <iostream>
#include <windows.h>
#include "library.h"

using namespace std;

int main() {
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i;
    for (i = 0; i < 2; ++i) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);
        std::cout << i << " In color" << std::endl;
    }

    hello();

    return 0;
}