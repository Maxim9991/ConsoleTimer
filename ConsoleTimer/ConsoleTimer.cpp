#include <iostream>
#include <stdio.h>
#include <conio.h>    
#include <Windows.h>
using namespace std;

int hour = 1, minute = 1, second = 59, flag = 0;    

void instal() {
    cout << "\n\nHour: ";
    cin >> hour;
    cout << "Minute: ";
    cin >> minute;
    cout << "Second: ";
    cin >> second;
}

void printData() {
    system("cls");

    cout << "1.Start  2.Stop  3.Reset  4. End\n";
    cout << "         [ " << hour << " : " << minute << " : " << second << " ]";
}

void selection() {
    switch (getch()) {
    case 49: flag = 0; break;
    case 50: flag = 1; break;
    case 51:
        hour = minute = second = 0; flag = 1; 
        printData();
        instal();
        cout << "\nPress Start";
        break;
    case 52: exit(0); break;
    }
}

void counter() {
    while (!kbhit() && flag == 0) {  
        if (minute < 1) {           
            minute = 59; --hour;
        }
        if (second < 0) {
            second = 59; --minute;
        }
        printData();
        Sleep(1000);
        second -= 1;
    }
    selection();
}

int main()
{
    instal();
    while (1) {   // 1 = true
        counter();
    }
}