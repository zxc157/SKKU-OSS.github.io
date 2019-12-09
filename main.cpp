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

int main(){
    char a, c;
    int studentNum = 0;
    Student s[100];
    while (true) {
	cin >> c;
	switch (c) {
	    case '0':{
		exit(0);
	    }
	    case '1': {
	    }
	    case '2': {
	    }	
	}
	default:
	    break;
	}
    }
}
