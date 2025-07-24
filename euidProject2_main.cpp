/* Author: Kenshin Kotari (KotariKenshin@unt.edu)
   Date:      07/14/2025
   Instructor: Amar Maharjan, Anamul Haque Mollah, Bailu Zhang
   Description: Project 2
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include "euidProject2_header.h"
using namespace std;

static void printHeader() {
    const int width = 49;
    const string headers[] = {
        "Computer Science and Engineering",
        "CSCE 1030 - Computer Science I",
        "Kenshin Kotari kk1267 KotariKenshin@my.unt.edu"
    };
    // Top border
    cout << '+' << setfill('-') << setw(width) << "" << setfill(' ') << '+' << endl;
    // Center each header line
    for (const auto &line : headers) {
        int pad = (width - static_cast<int>(line.length())) / 2;
        int rightPad = width - pad - static_cast<int>(line.length());
        cout << '|' << setw(pad) << "" << line << setw(rightPad) << "" << '|' << endl;
    }
    // Bottom border
    cout << '+' << setfill('-') << setw(width) << "" << setfill(' ') << '+' << endl << endl;
}

static void showMenu() {
    cout << "******Menu******" << endl;
    cout << "1. Add" << endl;
    cout << "2. Edit" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Search" << endl;
    cout << "5. Display" << endl;
    cout << "6. Exit" << endl;
    cout << "****************" << endl;
    cout << "Enter your choice: ";
}

int main() {
    printHeader();

    while (true) {
        showMenu();
        int choice;

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Incorrect choice. Please enter again." << endl << endl;
            continue;
        }

        switch (static_cast<MenuChoice>(choice)) {
            
            case Add:
                addContact();
                break;

            case Edit: {
                cout << "Enter contact id to edit: ";
                int id;
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid ID." << endl;
                } else {
                    editContact(id);
                }
                break;
            }

            case Delete: {
                cout << "Enter contact id to delete: ";
                int id;
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid ID." << endl;
                } else {
                    deleteContact(id);
                }
                break;
            }

            case Search: {
                cout << "Enter contact id to search: ";
                int id;
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid ID." << endl;
                } else {
                    searchContact(id);
                }
                break;
            }
        
            case Display:
                display();
                break;

            case Exit:
                cout << "Good Bye!!!" << endl;
                return 0;

            default:
                cout << "Incorrect choice. Please enter again." << endl;
        }
        cout << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}