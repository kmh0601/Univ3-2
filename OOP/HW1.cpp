#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
#include<stdlib.h>
#include<fstream>

using namespace std;

/** class **/
enum Sort{
    NAME = 1,
    ID,
    AY,
    DEPT,
};

class StudentInformation{
public:
    string name; // 15 PK
    string studentId; // 10 PK, first4 = admission year
    string birthYear; // 4
    string dept;
    string tel; // up to 12
public:
    StudentInformation(string name, string studentId, string birthYear, string tel, string dept){
        this->name = name;
        this->studentId = studentId;
        this->birthYear = birthYear;
        this->tel = tel;
        this->dept = dept;
    }
};

// qsort의 매개변수로 들어갈 compare()함수
bool compareName(StudentInformation a, StudentInformation b){
    string x = a.name;
    string y = b.name;
    if(x > y){
        return 1;
    }
    else if(x < y){
        return -1;
    }
    return 0;
}

bool compareId(StudentInformation a, StudentInformation b){
    string x = a.studentId;
    string y = b.studentId;
    if(x > y){
        return 1;
    }
    else if(x < y){
        return -1;
    }
    return 0;
}
bool compareDept(StudentInformation a, StudentInformation b){
    string x = a.dept;
    string y = b.dept;
    if(x > y){
        return 1;
    }
    else if(x < y){
        return -1;
    }
    return 0;
}
bool compareAdYear(StudentInformation a, StudentInformation b){
    string x = a.studentId.substr(0,4);
    string y = b.studentId.substr(0,4);
    if(x > y){
        return 1;
    }
    else if(x < y){
        return -1;
    }
    return 0;
}

class StudentList {
private:
    vector<StudentInformation> studentInformationList;
    Sort sortingOption;
public:
    // 기본 생성자
    StudentList(){
        this->sortingOption = Sort::NAME;
    }
    void addStudentInformation(StudentInformation information){
        studentInformationList.push_back(information);
    }
    // make student information
    StudentInformation makeStudentInformation(){
        string name;
        string studentId;
        string birthYear;
        string tel;
        string dept;

        // enter만 입력하면 빈 문자열로 받아들임
        cout << "Name?";
        getline(cin,name);
        cout  << "\n" << "StudentId?";
        getline(cin,studentId);
        cout  << "\n" << "birthYear?";
        getline(cin,birthYear);
        cout  << "\n" << "dept?";
        getline(cin,dept);
        cout  << "\n" << "tel?";
        getline(cin,tel);

        return StudentInformation(name, studentId, birthYear, tel, dept);
    }

    // insertion -> 정렬된 위치에 insert하는거 생각해보기
    void Insert(){
        StudentInformation newStudent = makeStudentInformation();

        // newStudent의 PK가 모두 채워줬는지 체크 하는 부분
        if(newStudent.name.empty() || newStudent.studentId.empty()){
            cout << "ERROR : You must fill Name and StudentId" << endl;
            return;
        }

        // newStudent가 중복인지 체크 하는 부분
        for(StudentInformation information : studentInformationList){
            if(information.name == newStudent.name){
                cout << "중복 이름";
                return;
            }
        }
        studentInformationList.push_back(newStudent);
    }

    // search
    // search 해서 작은 list에 push_back()하면 정렬된 상태로 작은 list 만들고 -> display
    void search(int option){
        vector<StudentInformation> searchedList;
        sorting();
        string target;
        getline(cin, target);

        switch (option)
        {
        case 1:
            /* search by name */
            for(StudentInformation information : studentInformationList){
                if(information.name == target){
                    searchedList.push_back(information);
                }
            }
            break;
        case 2 :
            /* search by ID */
            for(StudentInformation information : studentInformationList){
                if(information.studentId == target){
                    searchedList.push_back(information);
                    break;
                }
            }
            break;
        case 3 :
            /* search by Admission year */
            for(StudentInformation information : studentInformationList){
                if(information.studentId.substr(0,4) == target){
                    searchedList.push_back(information);
                }
            }
            break;
        case 4 :
            /* search by dept */
            for(StudentInformation information : studentInformationList){
                if(information.dept == target){
                    searchedList.push_back(information);
                }
            }
            break;
        case 5 :
            // display all
            display(studentInformationList);
            return;
        }
        display(searchedList);
    }

    // setSortingOption
    void setSortingOption(){
        cout << "1. Sort by Name" << endl;
        cout << "2. Sort by Student ID" << endl;
        cout << "3. Sort by Admission Year" << endl;
        cout << "4. Sort by Department name" << endl;
        string str;
        getline(cin, str);
        switch (stoi(str))
        {
        case Sort::NAME:
            sortingOption = Sort::NAME;
            break;
        case Sort::ID:
            sortingOption = Sort::ID;
            break;
        case Sort::AY:
            sortingOption = Sort::AY;
            break;
        case Sort::DEPT:
            sortingOption = Sort::DEPT;
            break;
        }
    }

    // display
    void display(vector<StudentInformation> displayList){
        cout << left << setw(15) << "Name" << setw(10) << "StudentId" << setw(20) << "Dept" << "Birth Year" <<"  " << setw(13) << "Tel" << endl;
        for(StudentInformation information : displayList){
            cout << left << setw(15) << information.name << setw(10) << information.studentId << setw(20) << information.dept;
            cout << right << setw(10) << information.birthYear << " ";
            cout << left << setw(10) << information.tel << endl;
        }
    }

    // sort
    void sorting(){
        if(sortingOption == Sort::NAME){
            sort(studentInformationList.begin(), studentInformationList.end(), compareName);
        }
        else if(sortingOption == Sort::ID){
            sort(studentInformationList.begin(), studentInformationList.end(), compareId);
        }
        else if(sortingOption == Sort::DEPT){
            sort(studentInformationList.begin(), studentInformationList.end(), compareDept);
        }
        else{
            sort(studentInformationList.begin(), studentInformationList.end(), compareAdYear);
        }
    }
};

class SIMSystem{
private:
    StudentList studentList;

public:
    SIMSystem(){
    }
    void addInformation(StudentInformation information){
        studentList.addStudentInformation(information);
    }
    void service(){
        int choice;
        do{
            showMenu();
            cin >> choice;
            cin.ignore();

            if (choice == 1){
                studentList.Insert();
            }
            else if (choice == 2){
                showSearchMenu();
                int searchOption;
                cin >> searchOption;
                cin.ignore();
                studentList.search(searchOption);
            }
            else if(choice == 3){
                studentList.setSortingOption();
            }
        }while(choice != 4);
        return;
    }
    void showMenu(){
        cout << "1. Insertion" << endl << "2. Search" << endl;
        cout << "3. Sorting Option" << endl << "4. Exit" << endl;
    }
    void showSearchMenu(){
        cout << "- Search -" << endl;
        cout << "1. Search by name" << endl;
        cout << "2. Search bt student ID (10 numbers)" << endl;
        cout << "3. Search by admission year (4 numbers)" << endl;
        cout << "4. Search by department name" << endl;
        cout << "5. List All" << endl;
    }
};


/** main **/
int main(void){
    SIMSystem newSystem = SIMSystem();


    string nameBuf;
    string idBuf;
    string deptBuf;
    string birthBuf;
    string telBuf;
    string buf;

    fstream fs;


    fs.open("file1.txt",ios::in);
    while(!fs.eof()){
        getline(fs,nameBuf,',');
        getline(fs,idBuf,',');
        getline(fs,birthBuf,',');
        getline(fs,deptBuf,',');
        getline(fs,telBuf,',');
        getline(fs,buf,'\n');
        cout << nameBuf << "," << idBuf << "," << birthBuf << "," << deptBuf << "," << telBuf << endl;
        StudentInformation information = StudentInformation(nameBuf, idBuf, birthBuf, deptBuf, telBuf);
        newSystem.addInformation(information);
    }
    fs.close();

    newSystem.service();
    // 학생 정보 파일에 쓰는 부분
    return 0;
}

