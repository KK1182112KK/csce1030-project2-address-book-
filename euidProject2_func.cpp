/* Author: Kenshin Kotari (KotariKenshin@unt.edu)
   Date:      07/14/2025
   Instructor: Amar Maharjan, Anamul Haque Mollah, Bailu Zhang
   Description: Project 2
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include "euidProject2_header.h"

using namespace std;

extern int getNumber();

void addContact() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string fn, ln, mail, ph, addr;
    cout << "First name: ";   getline(cin, fn);
    cout << "Last name: ";    getline(cin, ln);
    cout << "Email: ";        getline(cin, mail);
    cout << "Phone: ";        getline(cin, ph);
    cout << "Address: ";      getline(cin, addr);

    int n;
    Contact* contacts = loadContacts(n);
    int maxId = findMaxId(contacts, n);
    int newId = (maxId == -1) ? 1 : maxId + 1;

    ofstream ofs("contacts.dat", ios::app);
    ofs << newId << ';' << fn << ';' << ln << ';' << mail
        << ';' << ph << ';' << addr << endl;
    ofs.close();
    delete[] contacts;
    cout << "Added new contact successfully." << endl;
}

void editContact(int Contact_ID) {
    int n;
    Contact* contacts = loadContacts(n);
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        if (contacts[i].Contact_ID == Contact_ID) { idx = i; break; }
    }
    if (idx < 0) {
        cout << "Contact not found." << endl;
        delete[] contacts;
        return;
    }

    cout << "Current information of " << contacts[idx].FirstName << " " << contacts[idx].LastName << ":" << endl;
    printLine();
    cout << left
         << setw(5)  << "ID"
         << setw(30) << "Name"
         << setw(30) << "Email"
         << setw(20) << "Phone"
         << setw(45) << "Address"
         << endl;
    printLine();
    cout << setw(5)  << contacts[idx].Contact_ID
         << setw(30) << (contacts[idx].FirstName + " " + contacts[idx].LastName)
         << setw(30) << contacts[idx].Email
         << setw(20) << contacts[idx].Phone
         << setw(45) << contacts[idx].Address
         << endl;
    printLine();
 

    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Update first name: ";
    getline(cin, input);
    if (!input.empty()) contacts[idx].FirstName = input;

    cout << "Update last name: ";
    getline(cin, input);
    if (!input.empty()) contacts[idx].LastName = input;

    cout << "Update email: ";
    getline(cin, input);
    if (!input.empty()) contacts[idx].Email = input;

    cout << "Update phone: ";
    getline(cin, input);
    if (!input.empty()) contacts[idx].Phone = input;

    cout << "Update address: ";
    getline(cin, input);
    if (!input.empty()) contacts[idx].Address = input;

    ofstream ofs("contacts.dat");
    for (int i = 0; i < n; ++i) {
        ofs << contacts[i].Contact_ID << ';'
            << contacts[i].FirstName << ';'
            << contacts[i].LastName << ';'
            << contacts[i].Email << ';'
            << contacts[i].Phone << ';'
            << contacts[i].Address << endl;
    }
    ofs.close();
    delete[] contacts;
    cout << "Updated existing contact successfully." << endl;
}

void deleteContact(int Contact_ID) {
    int n;
    Contact* contacts = loadContacts(n);
    bool found = false;
    ofstream ofs("contacts.dat");
    for (int i = 0; i < n; ++i) {
        if (contacts[i].Contact_ID == Contact_ID) { found = true; continue; }
        ofs << contacts[i].Contact_ID << ';'
            << contacts[i].FirstName << ';'
            << contacts[i].LastName << ';'
            << contacts[i].Email << ';'
            << contacts[i].Phone << ';'
            << contacts[i].Address << endl;
    }
    ofs.close();
    delete[] contacts;
    if (found) {
        cout << "Deleted existing contact successfully." << endl;
    } else {
        cout << "Contact id " << Contact_ID << " not found." << endl;
    }
}

void searchContact(int Contact_ID) {
    int n;
    Contact* contacts = loadContacts(n);
    if (!contacts) {
        cout << "Error: unable to get the contacts." << endl;
        return;
    }
    if (n == 0) {
        cout << "Error: unable to get the contacts." << endl;
        delete[] contacts;
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        if (contacts[i].Contact_ID == Contact_ID) {
            printLine();
            cout << left
                 << setw(5)  << "ID"
                 << setw(25) << "Name"
                 << setw(30) << "Email"
                 << setw(15) << "Phone"
                 << setw(45) << "Address"
                 << endl;
            printLine();
            cout << setw(5)  << contacts[i].Contact_ID
                 << setw(25) << (contacts[i].FirstName + " " + contacts[i].LastName)
                 << setw(30) << contacts[i].Email
                 << setw(15) << contacts[i].Phone
                 << setw(45) << contacts[i].Address
                 << endl;
            printLine();
            delete[] contacts;
            return;
        }
    }
    delete[] contacts;
    cout << "Contact id " << Contact_ID << " not found." << endl;
}


void printLine(char c) {
    cout << string(128, c) << endl;
}

void display() {
    int n;
    Contact* contacts = loadContacts(n);
    if (!contacts || n == 0) {
        cout << "Empty contact list." << endl;
        delete[] contacts;
        return;
    }
    printLine();
    cout << left
         << setw(5)  << "ID"
         << setw(25) << "Name"
         << setw(30) << "Email"
         << setw(15) << "Phone"
         << setw(45) << "Address"
         << endl;
         
    printLine();
    for (int i = 0; i < n; ++i) {
        cout << setw(5)  << contacts[i].Contact_ID
             << setw(25) << (contacts[i].FirstName + " " + contacts[i].LastName)
             << setw(30) << contacts[i].Email
             << setw(15) << contacts[i].Phone
             << setw(45) << contacts[i].Address
             << endl;
        if (i < n - 1) printLine('-');
    }
    printLine();
    delete[] contacts;
}


Contact* loadContacts(int &numContacts) {
    numContacts = getNumber();
    Contact* arr = new Contact[numContacts];
    ifstream ifs("contacts.dat");
    for (int i = 0; i < numContacts; ++i) {
        string line;
        getline(ifs, line);
        stringstream ss(line);
        string tmp;
        getline(ss, tmp, ';'); arr[i].Contact_ID = stoi(tmp);
        getline(ss, arr[i].FirstName, ';');
        getline(ss, arr[i].LastName, ';');
        getline(ss, arr[i].Email, ';');
        getline(ss, arr[i].Phone, ';');
        getline(ss, arr[i].Address);
    }
    return arr;
}

int findMaxId(Contact *contacts, int size) {
    if (size == 0) return -1;
    int mx = contacts[0].Contact_ID;
    for (int i = 1; i < size; ++i) if (contacts[i].Contact_ID > mx) mx = contacts[i].Contact_ID;
    return mx;
}
