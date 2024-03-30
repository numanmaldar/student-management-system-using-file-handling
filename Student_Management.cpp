#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

class Student {
private:
    string Name, RollNo, Year;
    float CGPA;

public:
    Student(string name = "", string rollNo = "", string year = "", float cgpa = 0.0)
        : Name(name), RollNo(rollNo), Year(year), CGPA(cgpa) {}

    void setName(string name) { Name = name; }
    void setRollNo(string rollNo) { RollNo = rollNo; }
    void setYear(string year) { Year = year; }
    void setCGPA(float cgpa) { CGPA = cgpa; }

    string getName() const { return Name; }
    string getRollNo() const { return RollNo; }
    string getYear() const { return Year; }
    float getCGPA() const { return CGPA; }
};

void addStudent(Student& s) {
    string name, rollNo, year;
    float cgpa;

    cout << "Enter Name Of Student: ";
    cin >> name;
    s.setName(name);

    cout << "Enter RollNo of Student: ";
    cin >> rollNo;
    s.setRollNo(rollNo);

    cout << "Enter Year of Student: ";
    cin >> year;
    s.setYear(year);

    cout << "Enter CGPA of Student: ";
    cin >> cgpa;
    s.setCGPA(cgpa);

    ofstream out("Student.txt", ios::app);
    if (!out) {
        cout << "ERROR: File Not Opened!" << endl;
        return;
    }

    out << s.getName() << " : " << s.getRollNo() << " : " << s.getYear() << " : " << s.getCGPA() << endl;
    cout << "Student Added Successfully!" << endl;
    out.close();
}

void search(const string& name) {
    ifstream in("Student.txt");
    if (!in) {
        cout << "Error: File Cannot Open!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ':'); // Name
        if (token.find(name) != string::npos) {
            cout << " Name | RollNo | Year | CGPA" << endl;
            cout << line << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Student Not Found!" << endl;
    }

    in.close();
}

void display() {
    ifstream in("Student.txt");
    if (!in) {
        cout << "Error: File Cannot Open!" << endl;
        return;
    }

    string line;
    cout << " Name | RollNo | Year | CGPA" << endl;
    while (getline(in, line)) {
        cout << line << endl;
    }

    in.close();
}


int main() {
    bool exit = false;
    while (!exit) {
        system("cls");
        cout << "Welcome To Student Management System" << endl;
        cout << "************************************" << endl;
        cout << "1. Add Student." << endl;
        cout << "2. Search Student." << endl;
        cout << "3. Display." << endl;
		cout << "4. Exit." << endl;
        cout << "Enter Choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                system("cls");
                Student s;
                addStudent(s);
                break;
            }
            case 2: {
                system("cls");
                string name;
                cout << "Enter Name of Student: ";
                cin >> name;
                search(name);
                break;
            }
            case 3: {
			  system("cls");
              display();
              break;
            }
			
            case 4: {
                system("cls");
                exit = true;
                cout << "Good Luck!";
                break;
                
            }
            default: {
                cout << "Invalid choice! Please enter a valid option." << endl;
                break;
            }
        }
        cout << "Press Enter to continue...";
        cin.ignore(); 
        cin.get();    
    }

    return 0;
}
