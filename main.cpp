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
	        cout << "\n [Add Student]\n";
		cout << "===========================\n";
		cout << "1) with file 2) with input\n";
		cin >> a;
		switch(a){
		    case '1':{
			char name[20];
			cout << " [With file]\n";
			cout << "Enter your file name: ";
			cin >> name;
			ifstream inFile(name);
			if(! inFile.is_open()){
			    cout << "Error opening file\n";
			    break;
			}
			break;
		    }
		    case '2':{
			string line;
			cout << " [With direct input]\n";
			cin.ignore();
			cout << "Enter student's name: ";
			getline(cin, s[studentNum].name);
			cout << "Enter student's class: ";
			getline(cin, line);
			s[studentNum].classNum = atoi(line.c_str()); 
			cout << "Enter student's grade: ";
			getline(cin, line);
			s[studentNum].gradeNum = atoi(line.c_str());
			cout << "Enter student's major: ";
			getline(cin, s[studentNum].major);
			cout << "Enter student's gender(f/m): ";
			getline(cin, s[studentNum].gender);
			cout << "Enter student's gpa: ";
			getline(cin, line);
		    	s[studentNum++].gpa = atof(line.c_str());
			break;
		    }
		    default:
			break;
		}
	        break;
	    }
	    case '2': {

	    }	
	    default:
	        break;
	}
    }
}
