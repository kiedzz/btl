#include <iostream>
#include "StudentLinkedList.h"

using namespace std;

void insertStudent(StudentLinkedList *list)
{
    Student student;
    student.createNewStudent();
    list->pushNewStudent(student).updateToFile();
}

void insertListStudents(StudentLinkedList *list)
{
    do
    {
        char tmp;
        insertStudent(list);
        cout << "Nhan 0 de thoat hoac ki tu bat ki de tiep tuc: ";
        cin >> tmp;
        cin.ignore(1);
        if (tmp == '0')
            break;
    } while (true);
}

void findStudent(StudentLinkedList *list)
{
    vector<Student> students;
    string studentName, className;

    cout << "Nhap ten lop: ";
    getline(cin, className);
    cout << "Nhap ten hoc sinh: ";
    getline(cin, studentName);

    students = list->findStudent(studentName, className);

    if (students.size() == 0)
    {
        cout << "Khong tim thay hoc sinh nao! ";
        cout << endl;
        pauseScreen();
        return;
    }

    sprintf("STT", 5);
    sprintf("Ho va ten");
    sprintf("So dien thoai");
    cout << endl;

    for (int i = 0; i < students.size(); i++)
    {
        sprintf(students[i].getFullName());
        sprintf(students[i].getPhoneNumber());
        cout << endl;
    }
    pauseScreen();
}

void showFullList(StudentLinkedList *list)
{
    cout << "Danh sach hoc sinh day du: " << endl;
    sprintf("STT", 5);
    sprintf("Ho va ten");
    sprintf("Lop");
    sprintf("So dien thoai");
    sprintf("Diem trung binh");
    sprintf("Xep loai");
    cout << endl;
    list->printList();
    pauseScreen();
}

void showNameAndClassification(StudentLinkedList *list)
{
    vector<string> fields = {"fullName", "classification"};

    sprintf("STT", 5);
    sprintf("Ho va ten");
    sprintf("Xep loai");
    cout << endl;
    list->printList(fields);
    pauseScreen();
}

void sortByScoreAvg(StudentLinkedList *list)
{
    cout << "Danh sach sau khi sap xep: " << endl;
    sprintf("STT", 5);
    sprintf("Ho va ten");
    sprintf("Lop");
    sprintf("So dien thoai");
    sprintf("Diem trung binh");
    cout << endl;
    list->sortByScoreAvg().updateToFile().printList();
    pauseScreen();
}

void insertAt(StudentLinkedList *list)
{
    int index;
    cout << "Nhap vi tri muon them hoc sinh: ";
    Student student;
    student.createNewStudent();
    list->insertNewStudentAt(index, student).updateToFile();
}

void removeAllStudentFromClass(StudentLinkedList *list)
{
    string className;
    cout << "Nhap ten lop muon xoa: ";
    getline(cin, className);
    list->deleteStudent(className).updateToFile();
}

int main()
{
    StudentLinkedList *list = new StudentLinkedList();

    while (true)
    {
        int option;

        cout << "----------------------------" << endl;
        cout << "1. Nhap danh sach hoc sinh tu ban phim: " << endl;
        cout << "2. In danh sach hoc sinh day du: " << endl;
        cout << "3. In danh sach ten hoc sinh va xep loai: " << endl;
        cout << "4. Tim kiem hoc sinh: " << endl;
        cout << "5. Nhap ho so sinh vien moi: " << endl;
        cout << "6. Loai bo hoc sinh cua 1 lop: " << endl;
        cout << "7. Sap xep theo DTB giam dan: " << endl;
        cout << "8. Chen ho so vao vi tri bat ki: " << endl;
        cout << "9. Nhap danh sach tu file: " << endl;
        cout << "----------------------------" << endl;

        cout << "Lua chon cua ban: ";
        cin >> option;
        cin.ignore(1);
        cout << "----------------------------" << endl;

        switch (option)
        {
        case 1:
            insertListStudents(list);
            break;
        case 2:
            showFullList(list);
            break;
        case 3:
            showNameAndClassification(list);
            break;
        case 4:
            findStudent(list);
            break;
        case 5:
            insertStudent(list);
            break;
        case 6:
            removeAllStudentFromClass(list);
            break;
        case 7:
            sortByScoreAvg(list);
            break;
        case 8:
            insertAt(list);
            break;
        default:
            cout << "Lua chon khong hop le!";
            return 0;
        }
    }

    delete list;
}