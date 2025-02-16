#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Student {
public:
    string name;
    int id;
    int age;
    string department;
    double grade;
    void displayStudentInfo() const{
        cout << "----------------------------------------------------" << endl;
        cout << "|                Student Detail.                   " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "|    Student Name: " << name << endl;
        cout << "|    Student ID: " << id << endl;
        cout << "|    Student Age: " << age << endl;
        cout << "|    Student Department: " << department << endl;
        cout << "|    Student Grade: " << grade << endl;
        cout << "----------------------------------------------------" << endl;
    }
};

class StudentManager{
    private:
    vector<Student> students;

    public:
    void addStudentInfo(){
        Student newStudent;
        cin.ignore();
        while (true){
            cout <<"Enter Student Name:";
            getline(cin,newStudent.name);

            if(!newStudent.name.empty()){
                break;
            }
            cout <<"Student name can't be empty.\n";
            continue;
        }

        while (true) {
            cout << "Enter Student ID: ";
            cin >> newStudent.id;
    
            if (cin.fail() || newStudent.id <= 0) {
                cin.clear();  // Clear input error
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid ID. Please enter a positive integer.\n";
                continue;
            }
    
            // Check for duplicate ID
            auto it = find_if(students.begin(), students.end(),[ id = newStudent.id](const Student& stud) {
                return stud.id == id;
            });
    
            if (it != students.end()) {
                cout << "Student with ID " << newStudent.id << " already exists. Please enter a unique ID.\n";
                continue;
            }
    
            break;
        }
        
        while(true){
            cout <<"Enter Student Age:";
            cin >>newStudent.age;

            if(cin.fail() || newStudent.age <= 0){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max() , '\n');
                cout <<"Student age must be valid.\n";
            }
            else{
                break;
            }
        }
        cin.ignore();

        while(true){
                cout <<"Enter Student Departement:";
                getline(cin,newStudent.department);

                if(newStudent.department.empty()){
                    cout <<"Student departement must have value;\n";
                }
                else{
                    break;
                }
        }
        
        while (true){
            cout <<"Enter Student Grade(1-100):";
            cin >>newStudent.grade;

            if(cin.fail() || newStudent.grade <= 0 || newStudent.grade > 100){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max() , '\n');
                cout <<"Student grade must be posetive integer(1-100).\n";
            }
            else{
                break;
            }
        }
        

        students.push_back(newStudent);
        cout <<"Student Added Successfully!\n";

    }

    void displayAllStudents(){
        if(students.empty()){
            cout <<"There is no student!\n";
            return;
        }
        for(const auto& student : students){
            student.displayStudentInfo();
        }
    }

    void searchForStudent(){
        if(students.empty()){
            cout <<"There is no student to search for!\n";
            return;
        }
        int choice;
        cout <<"Search Student by \n 1.Name \n 2.Id";
        cin >> choice;

        switch(choice){
            case 1:{
            string studName;
            cin.ignore();
            cout <<"Enter Student Name:";
            getline(cin,studName);
                bool found = false;

                for(const auto& student : students){
                    if(student.name == studName){
                        cout <<"Student Found!\n";
                        student.displayStudentInfo();
                        found = true;
                        break;
                    }
                }

                if(!found){
                    cout <<"No student found\n";
                }
                break;
            }
            case 2:{
            int searchId;
            cout <<"Enter Student Id:";
            cin >>searchId;
                bool found = false;

                for(const auto& student : students){
                    if(student.id == searchId){
                        cout <<"Student Found!";
                        student.displayStudentInfo();
                        found = true;
                        break;
                    }
                }

                if(!found){
                    cout <<"No student found\n";
                }
                break;
                }
                default:
                cout <<"Invalid Input!\n";       
        }
    }

    void updateStudentDetail(){
        if(students.empty()){
            cout <<"There is no student to update for.\n";
            return;
        }

        int choice,studentId;
        cout <<"Choose what to update\n1.Name\n2.Id\n3.Age\n4.Grade\n";
        cin >>choice;

        switch(choice){
            case 1:{
                string updateName;
                cout <<"Enter Student Id:";
                cin >>studentId;
                cin.ignore();
                cout <<"Enter New Name:";
                getline(cin,updateName);
                bool found = false;
                for(auto& student : students){
                    if(student.id == studentId){
                        student.name = updateName;
                        cout <<"Student Name Updated Successfully!\n";
                        found = true;
                        break;
                    }
                }
                if(!found){
                        cout <<"Student Not Found!\n";
                    }
                break;
            }
            case 2:{
                int oldId,newId;
                while (true){
                cout <<"Enter Old Id:";
                cin >>oldId;
                cout <<"Enter New Id:";
                cin >>newId;

                 // Check for duplicate ID
                auto it = find_if(students.begin(), students.end(),[ id = newId](const Student& stud) {
                    return stud.id == id;
                });
        
                if (it != students.end()) {
                    cout << "Student with ID " << newId << " already exists. Please enter a unique ID.\n";
                    continue;
                }
        
                break;
            }
                bool found = false;
                for(auto& student : students){
                    
                    if (student.id == oldId){
                        student.id = newId;
                        cout <<"Student Id Updated Successfully!\n";
                        found = true;
                        break;
                    }
                }
                if(!found){
                        cout <<"Student Not Found!\n";
                    }
                break;
            }
            case 3:{
                int newAge;
                cout <<"Enter Student Id:";
                cin >>studentId;
                cout <<"Enter New Age For The Student:";
                cin >>newAge;
                bool found = false;
                for(auto& student : students){
                    if(student.id == studentId){
                        student.age = newAge;
                        cout <<"Student Age Updated Successfully!\n";
                        found = true;
                        break;
                    }
                }
                if(!found){
                        cout <<"Student Not Found!\n";
                    }
                break;
            }
            case 4:{
                double newGrade;
                cout <<"Enter Student Id:";
                cin >>studentId;
                cout <<"Enter The Upgraded Grade For The Student:";
                cin >>newGrade;
                bool found = false;
                for(auto& student : students){
                    if(student.id == studentId){
                        student.grade = newGrade;
                        cout <<"Student Grade Updated Successfully!\n";
                        found = true;
                        break;
                    }
                }
                if(!found){
                        cout <<"Student Not Found!\n";
                    }
                break;
            }
                default:
                cout <<"Invalid Input.\n";
        }
    }

    void saveToFile() {
        ofstream outFile("student.txt");
        if (!outFile) {
            cout << "Error saving student to file.\n";
            return;
        }
        for (const auto& student : students) {
            outFile << student.id << "|" << student.name << "|" << student.age << "|"
                    << student.department << "|" << student.grade << "\n";
        }
        outFile.close();
        cout << "Student Management saved successfully!\n";
    }

     // Load inventory from file
    void loadFromFile() {
        ifstream inFile("student.txt");
        if (!inFile) {
            cout << "No saved student found.\n";
            return;
        }
        students.clear();
        string line;
        while (getline(inFile, line)) {
            Student stud;
            size_t pos = 0;
            pos = line.find("|");
            stud.id = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find("|");
            stud.name = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find("|");
            stud.age = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find("|");
            stud.department = line.substr(0, pos);
            line.erase(0, pos + 1);

            stud.grade = stod(line);
            students.push_back(stud);
        }
        inFile.close();
        // cout << "Student Management loaded successfully!\n";
    }

    void deleteStudent(){
        if(students.empty()){
            cout <<"There is no student to delete.\n";
            return;
        }

        int studentId;
        cout <<"Enter Student Id To Delete:";
        cin >>studentId;

        bool found = false;

        for(auto it = students.begin(); it != students.end(); ++it){
            if(it->id == studentId){
                students.erase(it);
                cout <<"Student Deleted Successfully!\n";
                found = true;
                break;
            }
        }
        if(!found){
            cout <<"Student Not Found!\n";
        }
    }
};

int main(){
    StudentManager manager;
    manager.loadFromFile();
    int choice;

    do{
        cout << "====================================================\n";
        cout << "|            Student Management System             |\n";
        cout << "====================================================\n";
        cout << "|  1. Add Student                                  |\n";
        cout << "|  2. Display All Students                         |\n";
        cout << "|  3. Search Student                               |\n";
        cout << "|  4. Update Student Info                          |\n";
        cout << "|  5. Delete Student                               |\n";
        cout << "|  6. Save to file                                 |\n";
        cout << "|  7. Exit                                         |\n";
        cout << "====================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudentInfo();
                break;
            case 2:
                manager.displayAllStudents();
                break;
            case 3:
                manager.searchForStudent();
                break;
            case 4:
                manager.updateStudentDetail();
                break;
            case 5:
                manager.deleteStudent();
                break;
            case 6:
                manager.saveToFile();
                break;
            case 7:
                cout << "Exiting...." << endl;
                break;
            default:
                cout << "Invalid input! Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}