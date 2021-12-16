
#include <iostream>
#include <string> 
 
#include <fstream>
#include<ios>
#include<limits>


using namespace std;

void addCourse();

void viewCourse();

void addStudent();

void viewStudent();

void searchStudent();

void findStudent();

void searchCourse();

void deleteCourse();

void deleteStudent();


struct Student {

char ID[20];

char fullName[40];

int age;

char sex;

char department[60];

char email[50];

};

struct Course {

char cID[20];

char title[50];

int creditHour;

};


int main()
{
    char choice;
    cout<<"___________WELCOME To Art Students Data Management system __________"<<endl;
    do{
    
    cout<<"   Press 1 to add course data"<<endl;
    cout<<"   Press 2 to view all course data"<<endl;
    cout<<"   Press 3 to add student data"<<endl;
    cout<<"   Press 4 to view all students data"<<endl;
    cout<<"   Press 5 to see students in a department"<<endl;
    cout<<"   Press 6 to search student"<<endl;
    cout<<"   press 7 to search a course"<<endl;
    cout<<"   press 8 to delete a course "<<endl;
    cout<<"   press 9 to delete a student "<<endl;
    cout<<"   press C to exit "<<endl;
    cin>> choice;
    switch(choice){
case '1':
    addCourse();
    break;
case '2':
    viewCourse();
    break;
case '3':
    addStudent();
    break;
case '4':
    viewStudent();
    break;
case '5':
    searchStudent();
    break;
case '6':
    findStudent();
    break;
case'7':
    searchCourse();
    break;
    case '8':
         deleteCourse();
        break;
    case'9':
         deleteStudent();
        break;
        case 'c':
        case'C':
        exit(0);
        break;
default:
    cout<<"You entered a wrong input!"<<endl;
    	system("cls");
    }
    }
    while(choice!='y');

    

return 0;

}

void addCourse(){
		system("cls");
    int numCourse;
    struct Course courseList[100];
    fstream artStudents;

    cout<< " How many courses do you want to add?\n";
    cin>> numCourse;
    for(int i=0;i<numCourse;i++){
            cout<<"enter the course number " << i+1 << "course ID" <<endl;
            cin>> courseList[i].cID;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<< "enter the course number " << i+1 << " title " <<endl;
            cin.getline(courseList[i].title,40);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<< "enter the course number " << i+1 << " credit Hour "<<endl;
            cin>> courseList[i].creditHour;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
             artStudents.open("course.txt" , ios::app);
             artStudents<<courseList[i].cID<<"           "<<courseList[i].title<<"            "<<courseList[i].creditHour<<endl;
              artStudents.close();

    }

}
void viewCourse(){
		system("cls");
    fstream artStudents;
    artStudents.open("course.txt", ios::in);
    if (artStudents.is_open()){
    string line;
    while(getline(artStudents, line)){
        cout<< line << endl;
    }
    artStudents.close();
  }
}

void addStudent(){
		system("cls");
    int numStudent;
    struct Student studentList[200];
    fstream artStudents;

    cout<< " How many students do you want to add?\n";
    cin>> numStudent;
    for(int i=0;i<numStudent;i++){
            cout<<"enter student " << i+1 << " ID" <<endl;
            cin>> studentList[i].ID;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout<< "enter student " << i+1 << " full name " <<endl;
            cin.getline(studentList[i].fullName,40);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout<< "enter student " << i+1 << " age "<<endl;
            cin>> studentList[i].age;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout<<"enter student " << i+1 << " sex " <<endl;
            cin>>studentList[i].sex;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout<< "enter student " << i+1 << " department " <<endl;
            cin.getline(studentList[i].department,60);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');


cout<< "enter student " << i+1 << " Email address " <<endl;
            cin.getline(studentList[i].email,50);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');


            artStudents.open("student.txt", ios::app);

            artStudents<<studentList[i].ID <<"           "<< studentList[i].fullName<<"           "<< studentList[i].age<<"           "<<studentList[i].sex<<"           "<< studentList[i].department<<"           "<<studentList[i].email<<endl;

              artStudents.close();
    }

}
void viewStudent(){
		system("cls");
		
    fstream artStudents;
    artStudents.open("student.txt", ios::in);
    if (artStudents.is_open()){
    string line;
    while(getline(artStudents, line)){
        cout<< line << endl;
    }
    artStudents.close();
  }
}

    void searchStudent(){
    		system("cls");
    		
    string departmentX;
    int counter=0;
    fstream artStudents;
 artStudents.open("student.txt", ios::in);
 cout<<"Enter the department to see the students in it:  ";
 cin>> departmentX;
 string line;
 int offset;
    if (artStudents.is_open()){
    while(!artStudents.eof()){
    getline(artStudents, line);
    if((offset = line.find( departmentX,0)) != string::npos){
        cout<<"ID"<<"             "<<"FULL NAME"<<"                "<<"AGE"<<"              "<<"SEX"<<"             "<<"DEPARTMENT"<<"           "<<"EMAIL"<<endl;
        cout<< line << endl;
        counter++;
    }
    }

}
 if(counter==0){
    cout<<"No item is found"<<endl;
}
artStudents.close();


}



void findStudent(){
		system("cls");
    string findName;
    int counter=0;
    fstream artStudents;
 artStudents.open("student.txt", ios::in);
 cout<<"Enter the name of the student you want to search:  ";
 cin>> findName;
 string line;
 int offset;
    if (artStudents.is_open()){
    while(!artStudents.eof()){;
    getline(artStudents, line);
    if((offset = line.find( findName,0)) != string::npos){
        cout<<"ID"<<"             "<<"FULL NAME"<<"                "<<"AGE"<<"              "<<"SEX"<<"             "<<"DEPARTMENT"<<"           "<<"EMAIL"<<endl;
        cout<< line << endl;
        counter++;
    }
    }

}
 if(counter==0){
    cout<<"No item is found"<<endl;
}
artStudents.close();


}

void searchCourse(){
		system("cls");
   char findTitle[30];
    int counter=0;
    fstream artStudents;
 artStudents.open("course.txt", ios::in);
 cout<<"Enter the title of the course you want to search:  ";
 cin.getline(findTitle,30);
 string line;
 int offset;
    if (artStudents.is_open()){
    while(!artStudents.eof()){
    getline(artStudents, line);
    if((offset = line.find( findTitle,0)) != string::npos){
        cout<<"ID"<<"           "<<"Title"<<"           "<<"credit hour"<<endl;
        cout<< line << endl;
        counter++;
    }
    }

}
 if(counter==0){
    cout<<"No item is found"<<endl;
}
artStudents.close();


}

void deleteCourse(){
		system("cls");
    string deleteCID, line;
    int offset;
 cout<<"Enter the ID of the course you want to delete :  ";
 cin>> deleteCID;

 fstream artStudents;
 artStudents.open("course.txt" , ios::in);
 fstream temporary;
 temporary.open("tempo.txt" , ios::out);
if (artStudents.is_open()){
    while(!artStudents.eof()){
    getline(artStudents, line);
    offset=((line.find( deleteCID,0)) != string::npos);
    if (offset==0){
            temporary << line << endl;
    }
    }
}

temporary.close();
artStudents.close();
remove("course.txt");
rename("tempo.txt","course.txt");
}

void deleteStudent(){
		system("cls");
    string deleteName, line;
    int offset;
 cout<<"Enter the name of the student you want to delete :  ";
 cin>> deleteName;

 fstream artStudents;
 artStudents.open("student.txt" , ios::in);
 fstream temporary;
 temporary.open("tempo.txt" , ios::out);
if (artStudents.is_open()){
    while(!artStudents.eof()){
    getline(artStudents, line);
    offset=((line.find( deleteName,0)) != string::npos);
    if (offset==0){
            temporary << line << endl;
    }
    }
}

temporary.close();
artStudents.close();
remove("student.txt");
rename("tempo.txt","student.txt");
}