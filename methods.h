#include <iostream>
/**
 * cin and cout are defined in the header iostream and in the namespace std. iostream is a file name
 * and std is a namespace used by the source code of that file.
 **/
#include <conio.h>
/*
 It is a header file used in c and cpp and it includes inbuilt functions like getch() and clrscr().
 It stand for console input ouput i.e. it takes input from keyboard and displays it on screen
*/
#include <cstdlib>
/*
header file declares a set of general-purpose functions such as:
atof() to convert string to double.
*/
#include <cstring>   //This header file defines several functions to manipulate C strings and arrays.
#include <cstdio>    //The C++ <cstdio> header file includes several macros and functions of C-style input/output library.
#include <windows.h> // win32 api for windows functions like sleep
using namespace std; // we use the namespace named std. “std” is an abbreviation for standard.

// prototyping the functions declaration that specifies the types of the arguments

int login();                 // method for login sytem as admin or user
void waitForEnter();         // method for getting back to main menu
void listemployees();        // method for getting list of employees
void showDetail();           // method for getting employee's detail informations
void editExisting();         // method for updating employee's informations
void addNEwEmployee();       // method for putting new informations
void deleteEmployeeDetail(); // method for deleting employee's informations

// variables declarations
char name[30];        // employee's (user) name
char id[5];           // employee's identification
char designation[10]; // employee's job title(disignation)
int age;              // employee's age
int salary;           // employee's salary
int experience;       // employee's experience

// method for login system as admin or normal user
int login()
{
    system("cls");
    /*
     system() is a library function of stdlib.h header file.This function is used
     to run system/ command prompt commands and here cls is a command to clear the output screen.
      */
    int c; // integer declaration for making choice
    cout << "\n\n\n\n\t\t\t\t\tARE YOU A NEW EMPLOYEE OR AN ADMIN?";
    cout << "\n\n\n\t\t\t\t\t(1) ADMIN \n\n\n\t\t\t\t\t(2) NEW EMPLOYE \n\n\n\n\t\t\t\t\t";
    cin >> c;

    if (c == 1) // if the user is admin
    {
        system("cls");    // clearing the terminal screen
        string pass = ""; // declaring password string
        string name;      // declaring names string
        char ch;
        cout << "\n\n\n\n\n\t\t\t\tWELCOME TO EMPLOYEE MANAGEMENT SYSTEM";
        cout << "\n\n\n\n\t\t\t\t\tEnter Admin Username :";
        cin >> name;
        cout << "\n\n\t\t\t\t\tEnter Your Password :";
        ch = _getch(); // to pause the screen until a keystroke is given by the user.
        while (ch != 13)
        {                       // character 13 is enter
            pass.push_back(ch); // puts the character specified as parameter at the end of the string
            cout << '*';        // making user's password hidden
            ch = _getch();      // to pause the screen until a keystroke is given by the user.
        }
        if (pass == "0000" && name == "admin")
        {
            cout << "\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
            for (int a = 1; a < 10; a++) // Change 'a<?' to how many * you want
            {
                Sleep(500);
                cout << "...";
            }
            cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";

            system("PAUSE");
            system("CLS");
        }
        else
        {
            cout << "\nAccess Aborted...\n";
            login();
        }
    }

    if (c == 2)
    {
        system("cls");
        cout << "\n\n\n\t\t\t\t\tREGISTER YOURSELF \n\nFILL IN YOUR DETAILS\n";

        cout << "\n----------------------------------------";
        cout << "\n Enter First Name of Employee: ";
        cin >> name;
        cout << "\n----------------------------------------";
        cout << "\n Enter Employee ID [max 4 digits]: ";
        cin >> id;
        cout << "\n----------------------------------------";
        cout << "\n Enter Designation/job tittle: ";
        cin >> designation;
        cout << "\n----------------------------------------";
        cout << "\n Enter Employee Age: ";
        cin >> age;
        cout << "\n----------------------------------------";
        cout << "\n Enter Employee salary(CTC): ";
        cin >> salary;
        cout << "\n----------------------------------------";
        cout << "\n Enter Employee Experience: ";
        cin >> experience;
        cout << "\n----------------------------------------";

        char ch;
        cout << "\nEnter 'y' to save above information\n";
        cin >> ch;
        if (ch == 'y')
        {
            FILE *file;
            file = fopen("database.txt", "a");
            fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, salary, experience);
            /*
             It is defined in <cstdio> header file.

              The fprintf() function in C++ is used to write a formatted string to file stream.
              The string format may contain format specifiers starting with % which are replaced by the
              values of variables that are passed to the fprintf() function as additional arguments.


              The fopen() function takes a two arguments and returns a file
              stream associated with that file specified by the argument filename.
                        FILE* fopen (const char* filename, const char* mode);
                        mode: "r"  Opens a file for reading. The file must exist.
                              "a"  Appends to a file. Writing operations, append data at the end of the file.
                              "w"  Creates an empty file for writing

              The fscanf() function reads the data from file stream and stores the values into the respective variables.
              The fclose(): close the stream
             */
            fclose(file); // closing the file
            cout << "\nNew Employee has been added to database.\n";
            system("cls");
            login();
        }
    }
}

// Method for getting back to main menu
void waitForEnter(void)
{
    cout << "\n\n\n Press enter to go back \n\n";
    cin.get(); // cin.get takes all the data including blank spaces
    cin.get(); // but, using “cin>>” it will ignore some characters like blank spaces
}

// method for getting list of employees with Name, Id, Designation and Salary
void listEmployees(void)
{
    system("cls");
    FILE *file; // File pointer is a pointer which is used to handle and keep track on the files being accessed
    file = fopen("database.txt", "r");
    // FILE* fopen (const char* filename, const char* mode);
    // mode: "r"  Opens a file for reading. The file must exist.
    cout << "\n\t      List of Employees Record\n";
    cout << "\n------------------------------------------------------------------";
    cout << "\nNAME      |     ID     |      DESIGNATION      |   Salary \n";
    cout << "------------------------------------------------------------------";
    // int fscanf( FILE* stream, const char* format, ... );
    // The fscanf() function reads the data from file stream and stores the values into the respective variables.
    while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0], &age, &salary, &experience) != EOF)
        cout << "\n"
             << name << "\t\t" << id << " \t\t " << designation << " \t\t" << salary;
    fclose(file);
    waitForEnter();
}
// Method for getting all details according to Employee's id
void showDetails(void)
{
    system("cls"); // clearing terminal screen
    FILE *file;    // File pointer is a pointer which is used to handle and keep track on the files being accessed
    char checkId[5];
    cout << "\n\nEnter Employee ID: ";
    cin >> checkId;
    file = fopen("database.txt", "r"); // fopen: "r"  Opens a file for reading. The file must exist.
    while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0], &age, &salary, &experience) != EOF)
        // fscanf: reads the data from file stream and stores the values into the respective variables.
        if (strcmp(checkId, id) == 0)
        // The strcmp() function compares string1 and string2. The function operates on null-ended strings.
        {
            cout << "\n---------------------";
            cout << "\nName: " << name;
            cout << "\n---------------------";
            cout << "\nId: " << id;
            cout << "\n---------------------";
            cout << "\nDesignation: " << designation;
            cout << "\n---------------------";
            cout << "\nAge: " << age;
            cout << "\n---------------------";
            cout << "\nsalary: " << salary;
            cout << "\n---------------------";
            cout << "\nExperience: " << experience;
            cout << "\n---------------------";
        }
    fclose(file); // closing file
    waitForEnter();
}

// Method for updating informations of an employee
void editExisting(void)
{
    system("cls");   // clearing screen
    char checkId[5]; // temp id for cross-checking (confirmation)
    cout << "\nEnter employee id: ";
    cin >> checkId;
    // new name
    char newName[10];
    cout << "\n-----------------------------";
    cout << "\nEnter new username: ";
    cin >> newName;
    // new designation or job tittle
    char newDesignation[10];
    cout << "\n-----------------------------";
    cout << "\nEnter new designation: ";
    cin >> newDesignation;
    // new salary
    int newsalary;
    cout << "------------------------------";
    cout << "\nEnter new salary: ";
    cin >> newsalary;
    // file pointer which is used to handle and keep track on the files being accessed
    FILE *file, *tempfile;

    file = fopen("database.txt", "r");
    // fopen mode: "r"  Opens a file for reading. The file must exist.
    tempfile = fopen("temp.txt", "w");
    // fopen mode: "w"  Creates an empty file for writing
    while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0], &age, &salary, &experience) != EOF)
    { // fscanf: reads the data from file stream and stores the values into the respective variables.
        if (strcmp(checkId, id) == 0)
            // The strcmp() function compares string1 and string2. The function operates on null-ended strings.
            fprintf(tempfile, "%s %s %s %d %d %d \n", newName, id, newDesignation, age, newsalary, experience);
        // function to write a formatted string to file stream.
        else
            fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, salary, experience);
    }
    // fclose(file *) close a stream pointed to by stream
    fclose(file);
    fclose(tempfile);
    int isRemoved = remove("database.txt"); // deleting file
    int isRenamed = rename("temp.txt", "database.txt");
    // The rename() function takes a two arguments: oldname , newname and returns an integer value.
    waitForEnter();
}

// method for adding new employee records.
void addNewEmployee(void)
{
    system("cls");
    cout << "\n----------------------------------------";
    cout << "\n Enter First Name of Employee: ";
    cin >> name;
    cout << "\n----------------------------------------";
    cout << "\n Enter Employee ID [max 4 digits]: ";
    cin >> id;
    cout << "\n----------------------------------------";
    cout << "\n Enter Designation(Job Tittle): ";
    cin >> designation;
    cout << "\n----------------------------------------";
    cout << "\n Enter Employee Age: ";
    cin >> age;
    cout << "\n----------------------------------------";
    cout << "\n Enter Employee salary(CTC): ";
    cin >> salary;
    cout << "\n----------------------------------------";
    cout << "\n Enter Employee Experience: ";
    cin >> experience;
    cout << "\n----------------------------------------";

    char ch;
    cout << "\nEnter 'y' to save above information\n";
    cin >> ch;
    if (ch == 'y')
    {
        FILE *file;
        file = fopen("database.txt", "a"); // mode "a"
        fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, salary, experience);
        // function to write a formatted string to file stream.
        fclose(file);
        cout << "\nNew Employee has been added to database\n";
    }
    else
        addNewEmployee(); // calling itself
    waitForEnter();
}

// Method for deleting employees' records
void deleteEmployeeDetails(void)
{
    system("cls");   // clearing screen
    char checkId[5]; // confirmation id
    cout << "\n----------------------------------";
    cout << "\nEnter Employee Id To Remove: ";
    cin >> checkId;
    char ch;
    cout << "----------------------------------";
    cout << "\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
    cin >> ch;
    if (ch == 'y')
    {
        FILE *file, *tempfile;
        file = fopen("database.txt", "r"); // mode "r" readonly
        tempfile = fopen("temp.txt", "w"); // mode "w" write empty file
        // fscanf: reads the data from file stream and stores the values into the respective variables.
        while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0], &age, &salary, &experience) != EOF)
            if (strcmp(checkId, id) != 0) // string comparision
                fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, salary, experience);
        // function to write a formatted string to file stream.
        fclose(file);
        fclose(tempfile);
        int isRemoved = remove("database.txt");             // function deletes a file from memory.
        int isRenamed = rename("temp.txt", "database.txt"); // function takes the name of a file as its argument, and the new name of the file as a second argument.
        cout << "\nRemoved Successfully\n";
        waitForEnter();
    }
    else
        deleteEmployeeDetails();
}
