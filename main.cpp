#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
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
    cout << "===============================================\n";
    cout << "  1. Add Student\t2. Print Students\n";
    //cout << "  2. Delete Student\n";
    //cout << "  3. Edit Student\t4. Search Student\n";
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
		cout << "===============================================\n";
		cout << "  1) with file\t2) with input\n";
		cin >> a;
		switch(a){
		    case '1':{
			char name[20];
			cout << " [With file]\n";
			cout << "Enter the file name: ";
			cin >> name;
			ifstream inFile(name);
    			if(! inFile.is_open()){
			    cout << "Error opening file\n";
			    break;
			}
					
			string line;
			string sub[6];
			int j = 0;
			while(getline(inFile, line)){
			    stringstream line_s(line);
			    j++;
			    for(int k = 0; k < 6; k++){
				getline(line_s, sub[k], ' ');
			    }
			    s[studentNum].name = sub[0];
			    s[studentNum].classNum = atoi(sub[1].c_str()); 
			    s[studentNum].gradeNum = atoi(sub[2].c_str());
			    s[studentNum].major = sub[3];
			    s[studentNum].gender = sub[4];
			    s[studentNum++].gpa = atof(sub[5].c_str()); 
			}
			cout <<"\n"<< j << " students added\n";
			inFile.close();
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
			cout << "\n1 student added\n";
			break;
		    }
		    default:
			break;
		}
	        break;
	    }
	    case '2': {
	    	cout << "\n [Students]\n";
	    	cout << "===============================================\n";
		cout << "Name\tclass\tgrade\tmajor\tgender\tgpa\n";
		cout << "-----------------------------------------------\n";
		for(int i = 0; i < studentNum; i++){
		cout << s[i].name << "\t" << s[i].classNum << "\t" << s[i].gradeNum << "\t" << s[i].major << "\t" << s[i].gender << "\t" << s[i].gpa << endl;
		}	
	    }
	    default:
	        break;
	}
    }
}
