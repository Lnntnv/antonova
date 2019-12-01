#include <iostream>
#include <string.h>

using namespace std;

struct Student
{
    char fio[30];
    char group[10];
    int marks[5];
};

int main(int argc, char const *argv[])
{
    const int SIZE = 3;  // todo: set 10
    Student *students = new Student[SIZE]; 

    for (int i = 0; i < SIZE; ++i) {
        cout << "Введите данные студента номер " << i+1 << '\n'; 
        Student student;
        cout << "Фамилия и инициалы: ";
        cin >> student.fio;
        cout << "Номер группы: ";
        cin >> student.group;
        cout << "5 оценок:\n";
        for (int i1 = 0; i1 < 5; ++i1) {
            cin >> student.marks[i1];
        }
        students[i] = student;
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            if (strcmp(students[j].fio, students[j+1].fio) > 0) {
                swap(students[j], students[j+1]);
            }
        }
    }

    cout << "Вы ввели:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << students[i].fio << '\t' << students[i].group << endl;
    }

    cout << "Список студентов имеющие 2\n";
    bool flag = false;
    for (int i = 0; i < SIZE; ++i) {
        for (int i1 = 0; i1 < 5; ++i1) {
            if (students[i].marks[i1] == 2) {
                cout << students[i].fio << '\t' << students[i].group << '\n';
                flag = true;
                break;
            }
        }
    }

    if (!flag) {
        cout << "Нет студентов с оценкой 2" << endl;
    }

    return 0;
}

