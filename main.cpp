#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int classNum;
    int gradeNum;
    string major;
    string gender;
    double gpa;
};

void printMain(){
    cout << "\n [Main Menu]\n";
    cout << "===========================\n";
    cout << "  1. Add Student\n";
    cout << "  2. Print Students\n";
    //cout << "  2. Delete Student\n";
    //cout << "  3. Edit Student\n";
    //cout << "  4. Search Student\n";
    //cout << "  5. Group Assignment\n";
    cout << "  0. Exit\n";
    return;
};

int main(){
    char a, c;
    int studentNum = 0;
    Student s[100];
    while (true) {
	printMain();
	cin >> c;
	switch (c) {
	    case '0':{
		exit(0);
	    }
	    case '1': {	
		break;
	    }
	    case '2': {
		break;
	    }	
	    default:
	        break;
	}
    }
}
