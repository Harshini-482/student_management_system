#include <iostream>
#include <vector>
using namespace std;

// Base class
class Person {
protected:
    int id;
    string name;

public:
    Person(int i, string n) {
        id = i;
        name = n;
    }

    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }

    int getId() {
        return id;
    }
};

// Derived class
class Student : public Person {
private:
    string course;
    int marks;

public:
    Student(int i, string n, string c, int m)
        : Person(i, n) {
        course = c;
        marks = m;
    }

    char calculateGrade() {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 60) return 'C';
        else return 'D';
    }

    // No override keyword (C++98)
    void display() {
        Person::display();
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << calculateGrade() << endl;
        cout << "----------------------" << endl;
    }
};

// Manager class
class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id, marks;
        string name, course;

        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Marks: ";
        cin >> marks;

        students.push_back(Student(id, name, course, marks));
        cout << "Student added successfully!\n";
    }

    void viewStudents() {
        if (students.size() == 0) {
            cout << "No students found.\n";
            return;
        }

        for (int i = 0; i < students.size(); i++) {
            students[i].display();
        }
    }

    void searchStudent() {
        int sid;
        cout << "Enter Student ID to search: ";
        cin >> sid;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == sid) {
                students[i].display();
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

// Main
int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.viewStudents();
            break;
        case 3:
            manager.searchStudent();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}


