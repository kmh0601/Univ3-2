#include<iostream>
#include<list>
#include<string>
#include<iomanip>

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

class StudentList{
private:
    list<StudentInformation> studentInformationList;
    Sort sortingOption;
public:
    // 기본 생성자
    StudentList(){
        this->sortingOption = Sort::NAME;
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

    // setSortingOption
    void setSortingOption(){
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
        case 5:

            break;
        }

    }

    // display
    void display(list<StudentInformation> displayList){
        cout << left << setw(15) << "Name" << setw(10) << "StudentId" << setw(20) << "Dept" << "Birth Year" << setw(11) << "Tel" << endl;
        for(StudentInformation ){

        }
    }

    // sort
    void sort(){
        if(sortingOption == Sort::NAME){
            // qsort 구현
        }
    }

    // exit

};

class SIMSystem{

};

/** test **/


/** main **/
int main(void){
    cout << left << setw(15) << "Name" << setw(10) << "StudentId" << setw(20) << "Dept";
}

