/* Author: Kenshin Kotari (KotariKenshin@unt.edu)
   Date:      07/14/2025
   Instructor: Amar Maharjan, Anamul Haque Mollah, Bailu Zhang
   Description: Project 2
*/

#ifndef euidProject2_header_h
#define euidProject2_header_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

enum MenuChoice { 

    Add     = 1, 
    Edit    = 2, 
    Delete  = 3, 
    Search  = 4, 
    Display = 5, 
    Exit    = 6 

};

struct Contact {

    int Contact_ID;
    string FirstName;
    string LastName;
    string Email;
    string Phone;
    string Address;
};

int getNumber();  
void addContact();
void editContact(int Contact_ID);
void deleteContact(int Contact_ID);
void searchContact(int Contact_ID);
void display();
Contact* loadContacts(int &numContacts);
int findMaxId(Contact *contacts, int size);
void printLine(char c = '=');

#endif 