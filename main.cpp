
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;
int num = 0;
struct Student {
    char name[20];
    int classNum;
    int gradeNum;
    char major[20];
    char gender[2];
    double gpa;
    Student * next;
};

Student* list;
int studentNum;

void printMain(){
    cout << "\n [Main Menu]\n";
    cout << "===============================================\n";
    cout << "  1. Add Student\t 2. Delete Student\n";
    cout << "  3. Print Students\n";
    //cout << "  3. Edit Student\t4. Search Student\n";
    //cout << "  5. Group Assignment\n";
    cout << "  0. Exit\n";
    return;
};

void addfile(char* fileName){
    int j = 0;
    ifstream inFile(fileName);
    if(!inFile.is_open()){
        cout << "Error opening file\n";
        return;
    }    
    string line;
    string sub[6];
    while(getline(inFile, line)){
	studentNum++; j++;
	Student * s = (Student*)malloc(sizeof(Student));
	stringstream line_s(line);
	for(int k = 0; k < 6; k++){
	    getline(line_s, sub[k], ' ');
	}
	strcpy(s->name,sub[0].c_str());
	s->classNum = atoi(sub[1].c_str()); 
	s->gradeNum = atoi(sub[2].c_str());
	strcpy(s->major,sub[3].c_str());
    strcpy(s->gender, sub[4].c_str());
	s->gpa = atof(sub[5].c_str());
	s->next = NULL;
	if(list==NULL){
	    list = s;
	}
	else{
	    s->next = list;
	    list = s;
	}
    }
    cout <<"\n"<< j << " students added\n";
    inFile.close();		
    return;
}

void remove_studentname (char* studentName){
    if(list == NULL){
        cout << "Student name is not found\n";
	return;
    }
		if(!strcmp(list->name,studentName)){
		Student * cur = list;
		list = list -> next;
		free(cur);
		cout << "1 student deleted\n";
		return;
    }
    else{
	Student * cur = list->next;
	Student * prev = list;
	while(cur != NULL && strcmp(cur->name,studentName)){
	    prev = cur;
	    cur = cur->next;
	}
	if(cur == NULL){
	    cout << "Student name is not found\n";
	    return;
	}
	prev->next = cur->next;
	free(cur);
	cout << "1 student deleted\n";	
	return;
    }
}
bool remove_majorname(char* majorname) { //major deletion
	if (list == NULL) {
		return 0;
	}
	if (!strcmp(list->major, majorname)) {
		Student * cur = list;
		list = list->next;
		free(cur);
		num++;
		return 1;
	}
	else {
		Student * cur = list->next;
		Student * prev = list;
		while (cur != NULL && strcmp(cur->major, majorname)) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL) {
			return 0;
		}
		prev->next = cur->next;
		free(cur);
		num++;
		return 1;
	}
}
bool remove_classnum(int classnum) { //remove by classnumber
	int num = 0;
	if (list == NULL) {
		return 0;
	}
	if (classnum==list->classNum) {
		Student * cur = list;
		list = list->next;
		free(cur);
		num++;
		return 1;
	}
	else {
		Student * cur = list->next;
		Student * prev = list;
		while (cur != NULL &&classnum!=list->classNum) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL) {
			return 0;
		}
		prev->next = cur->next;
		free(cur);
		num++;
		return 1;
	}
}
bool remove_gradenum(int gradenum) { //remove by grade number

	if (list == NULL) {
		return 0;
	}
	if (gradenum == list->gradeNum) {
		Student * cur = list;
		list = list->next;
		free(cur);
		num++;
		return 1;
	}
	else {
		Student * cur = list->next;
		Student * prev = list;
		while (cur != NULL && gradenum != list->gradeNum) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL) {
			return 0;
		}
		prev->next = cur->next;
		free(cur);
		num++;
		return 1;
	}
}
bool remove_gender(char* gender2) {
	if (list == NULL) {
		printf("student with %s is not found",gender2);
		return 0;
	}
	if (!strcmp(list->gender, gender2)) {
		Student * cur = list;
		list = list->next;
		free(cur);
		num++;
		return 1;
	}
	else {
		Student * cur = list->next;
		Student * prev = list;
		while (cur != NULL && strcmp(cur->gender, gender2)) {
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL) {
			return 0;
		}
		prev->next = cur->next;
		free(cur);
		return 1;
	}
}
bool remove_gpa(double GP) {
	int index;
	cout << "Which range of student you want to delete? greater(>=GPA): 1   less(<=GPA): 2 ";
	cin >> index;
	switch (index) {
	case(1):
		if (list == NULL) {
			printf("student with gpa in range you've selected is not found");
			return 0;
		}
		if (list->gpa>=GP) {
			Student * cur = list;
			list = list->next;
			free(cur);
			num++;
			return 1;
		}
		else {
			Student * cur = list->next;
			Student * prev = list;
			while (cur != NULL && list->gpa>=GP) {
				prev = cur;
				cur = cur->next;
			}
			if (cur == NULL) {
				return 0;
			}
			prev->next = cur->next;
			free(cur);
			return 1;
		}
	case(2):
		if (list == NULL) {
			printf("student with gpa in range you've selected is not found");
			return 0;
		}
		if (list->gpa <= GP) {
			Student * cur = list;
			list = list->next;
			free(cur);
			num++;
			return 1;
		}
	
		else {
			Student * cur = list->next;
			Student * prev = list;
			while (cur != NULL && list->gpa>=GP) {
				prev = cur;
				cur = cur->next;
			}
			if (cur == NULL) {
				return 0;
			}
			prev->next = cur->next;
			free(cur);
			return 1;
		}
	default:
		break;
	}
	
}
int main(){
    char a, c;
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
			string line;
			cin.ignore();
			cout << " [With file]\n";
			cout << "Enter the file name: ";
		    	cin >> name;
			addfile(name);
			break;
		    }
		    case '2':{
			string line;
			Student * s = (Student*)malloc(sizeof(Student));
			cout << " [With direct input]\n";
		    	cin.ignore();
			cout << "Enter student's name: ";
			getline(cin, line);
		    	strcpy(s->name,line.c_str());

			cout << "Enter student's class: ";
			getline(cin, line);
			s->classNum = atoi(line.c_str()); 
			
			cout << "Enter student's grade: ";
			getline(cin, line);
			s->gradeNum = atoi(line.c_str());
		
			cout << "Enter student's major: ";
		    	getline(cin, line);
			strcpy(s->major,line.c_str());			

			cout << "Enter student's gender(f/m): ";
			getline(cin,line);
			strcpy(s->gender,line.c_str());
					
			cout << "Enter student's gpa: ";
			getline(cin, line);
		    	s->gpa = atof(line.c_str());
			s->next = NULL;
			if(list == NULL){
			    list = s;
			}
			else{
			    s->next = list;
			    list = s;
			}
			studentNum++;
			cout << "\n1 student added\n";
			break;
		    }
		    default:
			break;
		}
	        break;
	    }
	    case '2': {
			string line;
			int number;
			cout << "\n [Delete Student]\n";
			cout << "===============================================\n";
			cout << "Delete by name :1 || Delete by classnum : 2 || Delete by gradenum : 3 || Delete by major : 4 || Delete by gender : 5 || Delete by gpa : 6 ";
			cin >> number;
			switch (number) {
			case 1: //학생이름으로제거
				char name[20];
				cin.ignore();
				cout << "Enter student's name : ";
				cin >> name;
				remove_studentname(name);

			case 2: //특정 반 번호를 가진 학생들을 모두제거
				int classnum;
				cin.ignore();
				cout << "Enter class number :";
				cin >> classnum;
				while (remove_classnum(classnum) ) {
				}
				printf("%d students deleted", num);
				num = 0;

			case 3: //특정 학년 학생들 모두제거
				int gradenum;
				cin.ignore();
				cout << "Enter grade number :";
				cin >> gradenum;
				while (remove_gradenum(gradenum)) {
				}
				printf("%d students deleted", num);
				num = 0;

			case 4:
				char majorname[20];
				cin.ignore();
				cout << "Enter major :";
				cin >> majorname;
				while (remove_majorname(majorname)) {
				}
				printf("%d students deleted", num);
				num = 0;

			case 5:
				char gender[2];
				cin.ignore();
				cout << "Enter gender :";
				cin >> gender;
				while (remove_gender(gender)) {
				}
				printf("%d students deleted", num);
				num = 0;

			case 6:
				double gpa;
				cin.ignore();
				cout << "Enter gpa in your range :";
				cin >> gpa;
				while (remove_gpa(gpa)) {
				}
				printf("%d students deleted", num);
				num = 0;

			default:
				break;
			
			
			}
			
			break;
	    }
	    case '3': {
	    	cout << "\n [Students]\n";
	    	cout << "===============================================\n";
			cout << "Name\tclass\tgrade\tmajor\tgender\tgpa\n";
			cout << "-----------------------------------------------\n";
			Student * cur = list;
			while(cur != NULL){
				cout << cur->name << "\t" << cur->classNum << "\t" << cur->gradeNum << "\t" << cur->major << "\t" << cur->gender << "\t" << cur->gpa << endl;
			cur = cur->next;
		}	
	    }
	    default:
	        break;
	}
    }
}
