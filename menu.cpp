#include "menu.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "String.h"
#include "Identifier.h"
#include "BinaryString.h"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;


void gotoXY(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}


void drawMenu(String **strings, int num_elements, int y, int current_element) {
    gotoXY(0, 0);
    cout << "Main Menu";
    gotoXY(2, 1);
    cout << "1. Initialization";
    gotoXY(2, 2);
    cout << "1.1 Number of elements";
    gotoXY(2, 3);
    cout << "1.2 Initial value";
    gotoXY(2, 4);
    cout << "2. Testing";
    gotoXY(2, 5);
    cout << "2.1 Choose object";
    gotoXY(2, 6);
    cout << "2.4 Operand";
    gotoXY(2, 7);
    cout << "3. Exit";

    if (num_elements != -1) {
        gotoXY(60, 0);
        cout << "Current strings:";
        for (int i = 0; i < num_elements; i++)
            gotoXY(60, i + 1);
        gotoXY(0, y);
        cout << "->";

        if (current_element != -1) {
            gotoXY(58, current_element + 1);
            cout << "->";
        }
    }
}

void clear() {
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

int menu() {
    int menu_item = 0, y = 1;

    auto **strings = new String *[6];
    int num_elements = -1;
    int current_element;

    int type;
    std::string strtmp;

    bool running = true;
    drawMenu(strings, num_elements, y, -1);
    while (running) {


        system("pause>nul"); // the >nul bit causes it the print no message

        if (GetAsyncKeyState(VK_DOWN) && y != 7) //down button pressed
        {
            gotoXY(0, y);
            cout << "  ";
            y++;
            gotoXY(0, y);
            cout << "->";
            menu_item++;
            continue;

        }

        if (GetAsyncKeyState(VK_UP) && y != 1) //up button pressed
        {
            gotoXY(0, y);
            cout << "  ";
            y--;
            gotoXY(0, y);
            cout << "->";
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN)) {

            switch (menu_item) {
                case 0: {
                    break;
                }
                case 1: {
                    gotoXY(2, 16);
                    if (num_elements == -1) {
                        cout << "Please input number of elements (4 - 6): ";
                        cin >> num_elements;
                    } else {
                        cout << "Number of elements was already chosen";
                    }
                    clear();
                    drawMenu(strings, num_elements, y, current_element);
                    break;
                }
                case 2: {
                    gotoXY(2, 16);
                    if (num_elements == -1) {
                        cout << "Please choose number of elements";
                        break;
                    }

                    cout << "Please input number of element: ";
                    cin >> current_element;
                    if (current_element > num_elements - 1 || current_element < 0) {
                        cout << "Wrong element number";
                        drawMenu(strings, num_elements, y, current_element);
                        break;
                    }
                    cout << "Please input type of element:\n"
                            "1. String\n"
                            "2. Identifier String\n"
                            "3. Binary String\n";
                    cin >> type;
                    cout << type;
                    cout << "Please input value of element: ";
                    cin >> strtmp;
                    cout << strtmp;
                    switch (type) {
                        case 1:
                            strings[current_element] = new String(strtmp.c_str());
                            break;
                        case 2:
                            strings[current_element] = new Identifier(strtmp.c_str());
                            break;
                        case 3:
                            strings[current_element] = new BinaryString(strtmp.c_str());
                            break;
                        default:
                            break;
                    }
                    clear();
                    drawMenu(strings, num_elements, y, current_element);
                    break;
                }

                case 3: {
                    break;
                }

                case 4: {
                    if (num_elements == -1) {
                        cout << "Please choose number of elements";
                        break;
                    }
                    gotoXY(2, 16);
                    cout << "Please choose element: ";
                    cin >> current_element;
                    if (current_element > num_elements - 1 || current_element < 0) {
                        cout << "Wrong element number";
                        drawMenu(strings, num_elements, y, current_element);
                        break;
                    }
                    clear();
                    drawMenu(strings, num_elements, y, current_element);
                    break;
                }

                case 8: {
                    gotoXY(2, 16);
                    cout << "The program has now terminated!!";
                    running = false;
                }

                default:
                    break;

            }
        }
    }
    gotoXY(2, 21);
    return 0;
}