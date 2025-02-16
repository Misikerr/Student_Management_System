# Student Management System

## Overview
The **Student Management System** is a simple C++ console application that allows users to manage student records. It provides functionalities to add, update, search, display, delete student records, and save/load data from a file.

## Features
- Add new students with unique IDs.
- Update student details.
- Search for students by ID.
- Display all student records.
- Delete a student record.
- Save student records to a file.
- Load student records from a file.

## Technologies Used
- C++
- File Handling
- Object-Oriented Programming (OOP)
  
## Handled Errors
- Prevents adding students with duplicate IDs.
- Ensures only valid numeric values are entered for age.
- Checks if the file exists before loading data.
- Validates input formats (e.g., no spaces in names).
- Displays appropriate messages for invalid operations (e.g., deleting a non-existent student).


## Installation & Usage
### Prerequisites
- A C++ compiler (G++/Clang/MSVC)

### Steps to Compile and Run
1. Clone or download the repository.
2. Open a terminal/command prompt in the project directory.
3. Compile the program using the following command:
   ```sh
   g++ student_management.cpp -o student_management
   ```
4. Run the executable:
   ```sh
   ./student_management
   ```

## File Format for Data Persistence
Student records are stored in a file (`students.txt`). Each student entry is stored in the following format:
```
ID Name Age Department
```
Example:
```
101 John_Doe 20 Computer_Science
102 Jane_Smith 22 Electrical_Engineering
```

## Future Improvements
- Implement a graphical user interface (GUI).
- Improve search efficiency using data structures like **unordered_map**.
- Add exception handling for file operations.
- Allow data export in CSV format.

## License
This project is open-source and available under the MIT License.

## Author
* Misiker Genene
* You can call me Rio✌

