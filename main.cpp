#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i;
    for (i = 0; i < 255; ++i) {
        SetConsoleTextAttribute(hConsole, i);
        std::cout << i << " In color" << std::endl;
    }
    return 0;
}