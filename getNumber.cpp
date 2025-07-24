#include "euidProject2_header.h"

using namespace std;

int getNumber() {
	
	ifstream fin;
	fin.open("contacts.dat");
	if (fin.fail())
	{
		cout<<"File error."<<endl;
		return 0;
	}
	int count=0;
	string line;
	while(!fin.eof())
	{
		getline(fin, line);
		if(line.size() == 0) {
			continue; // skip empty lines
		}
		++count;
	}
	
	fin.close();
	return(count);
	
}