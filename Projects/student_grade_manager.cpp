#include <iostream>
#include <string>
#include <sstream>
#include <cctype>   // For std::isspace()
#include <utility>  // For std::swap()
#include <iomanip>
//global declarations
const int MAX_STUDENTS = 50;
int studentIDs[MAX_STUDENTS];
std::string studentNames[MAX_STUDENTS];
double studentMarks[MAX_STUDENTS];
int studentCount = 0;

//function protoypes
void showMenu();
int getMenuChoice();
int getValidInteger(std::string prompt);
double getValidMarks();
int getUniqueStudentID();
std::string getValidName();
void pauseScreen();
void addStudents();
void displayStudents();
void calculateStatistics();
int searchStudent(int id);
void searchStudents();
void sortStudentsByMarks();
void displayResults();

int main() {

    int choice;

    do {
        choice = getMenuChoice();

        switch (choice) {
        case 1: {//add student records
            addStudents();
            break;
        }
        case 2: {//display all students
            displayStudents();
            break;
        }
        case 3: {//calculate class statistics
            calculateStatistics();
            break;
        }
        case 4: {//search student
            searchStudents();
            break;
        }
        case 5: {//sort students by marks
            sortStudentsByMarks();
            break;
        }
        case 6: {//display student results
            displayResults();
            break;
        }
        case 0: {
            std::cout << "Exiting Student Grade Manager. Goodbye!\n\n";
            break;
        }
        }
    } while (choice != 0);
    return 0;
}
//defining showMenu function
void showMenu() {
    std::cout << "+" << std::string(46, '-') << "+\n";
    std::cout << "|  " << std::left << std::setw(10) << " " << "STUDENT GRADE MANAGER" << std::setw(11) << " " << "  |\n";
    std::cout << "|" << std::string(46, ' ') << "|\n";
    std::cout << "+" << std::string(46, '-') << "+\n";
    std::cout << "|  " << std::left << std::setw(42) << "[1] Add student records" << "  |\n";
    std::cout << "|  " << std::left << std::setw(42) << "[2] Display all students" << "  |\n";
    std::cout << "|  " << std::left << std::setw(42) << "[3] Calculate class statistics" << "  |\n";
    std::cout << "|  " << std::left << std::setw(42) << "[4] Search student" << "  |\n";
    std::cout << "|  " << std::left << std::setw(42) << "[5] Sort students by marks" << "  |\n";
    std::cout << "|  " << std::left << std::setw(42) << "[6] Display student results" << "  |\n";
    std::cout << "|  " << std::left << std::setw(42) << "[0] Exit" << "  |\n";
    std::cout << "+" << std::string(46, '-') << "+\n";
}
//defining pauseScreen() function
void pauseScreen() {
    std::string pauseInput;
    std::cout << "|  " << std::left << std::setw(42) << "Press Enter to continue..." << "  |\n";
    std::cout << "+" << std::string(46, '-') << "+\n";
    //wait for user to press Enter
    std::getline(std::cin, pauseInput);//getline() consumes the newline, whereas cin >> generally leaves it behind.
}
//defining getValidInteger function
int getValidInteger(std::string prompt) {
    int validInteger;
    do {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);//reads whole string
        std::cout << "+" << std::string(46, '-') << "+\n";

        std::stringstream ss(input);
        if (ss >> validInteger) {//if extraction of an integer from string is succeed
            std::string extra;
            // If extra extraction fails, the input contained only an integer.
            if (!(ss >> extra)) {
                return validInteger;
            }
        }
        //display an error if the input is invalid
        std::cout << "+" << std::string(46, '-') << "+\n";
        std::cout << "|  Invalid input! Please enter a number...     |\n";
    } while (true);//this condition creates an infinite loop
}
//defining getValidMarks function
double getValidMarks() {
    double marks;
    do {
        std::cout << "|  Enter marks(0-100): ";

        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input);

        //extracting decimal number
        if (ss >> marks) {
            std::string extra;
            //check if extra characters remaining in string
            if (!(ss >> extra)) {
                //check whether marks are within the allowed range
                if (marks >= 0 && marks <= 100) {
                    return marks;
                }
            }
        }
        std::cout << "Invalid marks! Enter a number between 0 and 100. \n";
    } while (true);
}
//defining getUniqueStudentID function
int getUniqueStudentID() {
    int id;
    do {
        id = getValidInteger("|  Enter student ID: ");
        if (id <= 0) {
            std::cout << "|  Enter non-zero positive ID!  \n";
        }
        else {
            //check if ID already exists
            if (searchStudent(id) == -1) {
                return id;
            }
            else {
                std::cout << "The ID already exists, try new one. \n";
            }
        }
    } while (true);
}
//defining getValidName function
std::string getValidName() {
    std::string name;
    bool isValid;
    do {
        isValid = false;//assuming the name is invalid initially
        std::cout << "|  Enter student name: ";
        std::getline(std::cin, name);

        //examine every character in the name
        for (char character : name) {//a range-based for loop, it visits every character in the string.
            //check whether the character is not whitespace
            if (!std::isspace(static_cast<unsigned char>(character))) {
                isValid = true;
            }
        }
        if (!isValid) {
            std::cout << "Invalid name! Please enter a valid name. \n";
        }

    } while (!isValid);
    return name;
}
//defining getMenuChoice function
int getMenuChoice() {
    int choice;
    do {
        showMenu();

        //get a valid integer from the user
        choice = getValidInteger("|  Enter your choice: ");

        //check whether the number belongs to the menu
        if (choice < 0 || choice > 6) {
            std::cout << "+" << std::string(46, '-') << "+\n";
            std::cout << "|  " << std::left << std::setw(42) << "Enter the number from menu only!" << "  | \n";
            pauseScreen();
        }
    } while (choice < 0 || choice > 6);
    return choice;
}
//defining addStudents function
void addStudents() {
    int remainSpace = MAX_STUDENTS - studentCount;
    int numberToAdd;
    if (remainSpace == 0) {
        std::cout << "Maximum no.of students is fullfilled\n";
        return;
    }

    //get a valid no.of students to add
    do {
        numberToAdd = getValidInteger("|  How many students do you want to add? ");

        //check whether the number is within the remaining capacity
        if (numberToAdd <= 0 || numberToAdd > remainSpace) {
            std::cout << "+" << std::string(46, '-') << "+\n";
            std::cout << "|  Enter a number between 1 and " << remainSpace << "!            |\n";
            pauseScreen();
        }
    } while (numberToAdd <= 0 || numberToAdd > remainSpace);
    //each students details
    int i;
    for (i = 0; i < numberToAdd; i++) {
        std::cout << "|              ---Student" << i + 1 << "---              |\n";
        studentIDs[studentCount] = getUniqueStudentID();
        studentNames[studentCount] = getValidName();
        studentMarks[studentCount] = getValidMarks();
        std::cout << "+" << std::string(46, '-') << "+\n";

        studentCount++;
    }
    std::cout << "|  " << numberToAdd << std::left << std::setw(40) << " student records added successfully!" << "  |\n";
    pauseScreen();
}
//defining displayStudents function
void displayStudents() {
    //check if records exist
    if (studentCount == 0) {
        std::cout << "+" << std::string(46, '-') << "+\n";
        std::cout << "|  " << std::left << std::setw(42) << "NO STUDENTS RECORD FOUND!" << "  |\n";
        pauseScreen();
        return;
    }
    std::cout << "+" << std::string(46, '-') << "+\n";
    std::cout << "|  " << std::setw(14) << " " << "STUDENT RECORDS" << std::setw(15) << " " << "|\n";
    std::cout << "+" << std::string(46, '-') << "+\n";
    std::cout << "|  " << studentCount << " STUDENTS FOUND" << std::left << std::setw(28) << " " << "|\n";
    std::cout << "+" << std::string(46, '-') << "+\n";
    std::cout << "|  " << std::left << std::setw(8) << "ID" << "|  " << std::left << std::setw(20) << "NAME" << "|  " << std::left << std::setw(10) << "MARKS" << "|\n";//setw() specifies a minimum width of column, not a maximum
    int i = 0;
    while (i < studentCount) {
        std::cout << "|  " << std::left << std::setw(8) << studentIDs[i] << "|  " << std::left << std::setw(20) << studentNames[i] << "|  " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << studentMarks[i] << "|\n";
        i++;
    }
    std::cout << "+" << std::string(46, '-') << "+\n";
    pauseScreen();
}
//defining calculateStatistics function
void calculateStatistics() {
    //check if records exist
    if (studentCount == 0) {
        std::cout << "+" << std::string(46, '-') << "+\n";
        std::cout << "|  " << std::left << std::setw(42) << "NO STUDENTS RECORD FOUND!" << "  |\n";
        pauseScreen();
        return;
    }
    double totalMarks = 0;
    for (int i = 0; i < studentCount; i++) {
        totalMarks += studentMarks[i];
    }
    double averageMarks = totalMarks / studentCount;

    //finding highest marks and lowest marks
    double highestMarks = studentMarks[0];
    double lowestMarks = studentMarks[0];
    for (int i = 0; i < studentCount; i++) {
        if (studentMarks[i] > highestMarks) {
            highestMarks = studentMarks[i];
        }
        if (studentMarks[i] < lowestMarks) {
            lowestMarks = studentMarks[i];
        }
    }
    //count the no.of students passed or failed
    int passedStudents = 0, failedStudents = 0;
    for (int i = 0; i < studentCount; i++) {
        if (studentMarks[i] >= 40) {
            passedStudents++;
        }
        else {
            failedStudents++;
        }
    }
    //prinitng class statistics
    std::cout << "+" << std::string(46, '-') << "+\n";
    std::cout << "|  " << std::setw(14) << " " << "CLASS STATISTICS" << std::setw(14) << " " << "|\n";
    std::cout << "+" << std::string(46, '-') << "+\n";
    std::cout << "|  " << std::left << std::setw(32) << "STATISTICS" << std::right << std::setw(10) << "RESULTS" << "  |\n";
    std::cout << "+" << std::string(46, '-') << "+\n";

    std::cout << std::fixed << std::setprecision(2);//displays exactly decimal places
    std::cout << "|  " << std::left << std::setw(32) << "Total marks" << std::right << std::setw(10) << totalMarks << "  |\n";
    std::cout << "|  " << std::left << std::setw(32) << "Average marks" << std::right << std::setw(10) << averageMarks << "  |\n";
    std::cout << "|  " << std::left << std::setw(32) << "Highest marks" << std::right << std::setw(10) << highestMarks << "  |\n";
    std::cout << "|  " << std::left << std::setw(32) << "Lowest marks" << std::right << std::setw(10) << lowestMarks << "  |\n";
    std::cout << "|  " << std::left << std::setw(32) << "Passed students" << std::right << std::setw(10) << passedStudents << "  |\n";
    std::cout << "|  " << std::left << std::setw(32) << "Failed students" << std::right << std::setw(10) << failedStudents << "  |\n";
    std::cout << "+" << std::string(46, '-') << "+\n";
    pauseScreen();
}
//defining searchStudent function
int searchStudent(int id) {
    //using linear search algorithm
    for (int i = 0; i < studentCount; i++) {
        if (studentIDs[i] == id) {
            return i;
        }
    }
    return -1;
}
//defining searchStudents function
void searchStudents() {
    //check if records exist
    if (studentCount == 0) {
        std::cout << "+" << std::string(46, '-') << "+\n";
        std::cout << "|  " << std::left << std::setw(42) << "NO STUDENTS RECORD FOUND!" << "  |\n";
        pauseScreen();
        return;
    }

    std::cout << "+" << std::string(46, '-') << "+\n";
    //get a valid student ID
    int id = getValidInteger("|  Enter student ID: ");
    std::cout << "+" << std::string(46, '-') << "+\n";
    int index = searchStudent(id);
    //check if student is not found
    if (index == -1) {
        std::cout << "+" << std::string(46, '-') << "+\n";
        std::cout << "|  " << std::left << std::setw(42) << "STUDENT NOT FOUND!" << "  |\n";
        pauseScreen();
    }
    else {

        std::cout << "|  ID " << id << std::left << std::setw(36) << " STUDENT DETAILS" << "  |\n";
        std::cout << "|" << std::string(46, ' ') << "|\n";
        std::cout << "|  " << std::left << std::setw(20) << "Student Name:" << std::setw(22) << studentNames[index] << "  |\n";
        std::cout << "|  " << std::left << std::setw(20) << "Marks Obtained: " << std::setw(22) << std::fixed << std::setprecision(2) << studentMarks[index] << "  |\n";
        std::cout << "|  " << std::left << std::setw(20) << "Student ID: " << std::setw(22) << studentIDs[index] << "  |\n";
        if (studentMarks[index] >= 40) {
            std::cout << "|  " << std::left << std::setw(42) << "Result's status: Passed" << "  |\n";
        }
        else {
            std::cout << "|  " << std::left << std::setw(42) << "Result's status: Failed" << "  |\n";
        }
        std::cout << "+" << std::string(46, '-') << "+\n";
        pauseScreen();
    }
}
//defining sortStudentsByMarks function
void sortStudentsByMarks() {
    //check if records exist
    if (studentCount == 0) {
        std::cout << "+" << std::string(46, '-') << "+\n";
        std::cout << "|  " << std::left << std::setw(42) << "NO STUDENTS RECORD FOUND!" << "  |\n";
        pauseScreen();
        return;
    }

    //using Bubble sort algorithm for sorting
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = studentCount - 1; j > 0 + i; j--) {
            if (studentMarks[j] > studentMarks[j - 1]) {
                std::swap(studentMarks[j], studentMarks[j - 1]);
                std::swap(studentNames[j], studentNames[j - 1]);
                std::swap(studentIDs[j], studentIDs[j - 1]);
            }
        }
    }
    std::cout << "+" << std::string(46, '-') << "+\n";
    std::cout << "|  " << std::setw(3) << " " << "STUDENTS SORTED BY MARKS(descending)" << std::setw(3) << " " << "  |\n";
    std::cout << "+" << std::string(46, '-') << "+\n";

    std::cout << "|  " << std::left << std::setw(10) << "ID" << std::left << std::setw(20) << "NAME" << std::right << std::setw(12) << "MARKS" << "  |\n";
    std::cout << "+" << std::string(46, '-') << "+\n";

    int i = 0;
    while (i < studentCount) {
        std::cout << "|  " << std::left << std::setw(10) << studentIDs[i] << std::left << std::setw(20) << studentNames[i] << std::right << std::setw(12) << std::fixed << std::setprecision(2) << studentMarks[i] << "  |\n";
        i++;
    }
    std::cout << "+" << std::string(46, '-') << "+\n";
    pauseScreen();
}
//defining displayResults function
void displayResults() {
    //check if records exist
    if (studentCount == 0) {
        std::cout << "+" << std::string(46, '-') << "+\n";
        std::cout << "|  " << std::left << std::setw(42) << "NO STUDENTS RECORD FOUND!" << "  |\n";
        pauseScreen();
        return;
    }
    //Students results
    std::cout << "+" << std::string(58, '-') << "+\n";
    std::cout << "|  " << std::setw(19) << " " << "STUDENT RESULTS" << std::setw(20) << " " << "  |\n";
    std::cout << "+" << std::string(58, '-') << "+\n";

    std::cout << "|  " << std::left << std::setw(6) << "ID" << std::setw(20) << "NAME" << std::right << std::setw(10) << "MARKS" << std::setw(8) << "GRADE" << std::setw(10) << "STATUS" << "  |\n";
    std::cout << "+" << std::string(58, '-') << "+\n";

    std::string studentGrade[MAX_STUDENTS];
    bool isPass;
    for (int i = 0; i < studentCount; i++) {
        isPass = true;
        //using grade system
        if (studentMarks[i] >= 90) {
            studentGrade[i] = "A+";
        }
        else if (studentMarks[i] >= 80) {
            studentGrade[i] = "A";
        }
        else if (studentMarks[i] >= 70) {
            studentGrade[i] = "B+";
        }
        else if (studentMarks[i] >= 60) {
            studentGrade[i] = "B";
        }
        else if (studentMarks[i] >= 50) {
            studentGrade[i] = "C";
        }
        else if (studentMarks[i] >= 40) {
            studentGrade[i] = "D";
        }
        else {
            studentGrade[i] = "F";
            isPass = false;
        }
        //printing student details and results
        std::cout << "|  " << std::left << std::setw(6) << studentIDs[i] << std::setw(20) << studentNames[i] << std::right << std::setw(10) << std::fixed << std::setprecision(2) << studentMarks[i] << std::setw(8) << studentGrade[i] << std::setw(10) << (isPass == true ? "Passed" : "Failed") << "  |\n";
    }
    std::cout << "+" << std::string(58, '-') << "+\n";
    pauseScreen();
}