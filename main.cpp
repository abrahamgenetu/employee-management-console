//----------------------------------------------------------------------------------------------//
//        EMPLOYEE RECORD MANAGEMENT SYSTEM
//        GROUP NINE: Sofanit Getnet, , , ,
//-----------------------------------------------------------------------------------------------//

#include <iostream>  //including library for input output stream
#include "methods.h" //importing custom header file which contains the functions

using namespace std; // using standard namespace

int main()
{
    login();     // login method
    int login(); // is admin?
    while (true) // if user is admin
    {
        system("cls");
        // Options to choose an action
        cout << "\n\t\t\t>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<";
        cout << "\n";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   1:   To View List of Employees Record";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   2:   To View Employee Records";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   3:   To Modify Existing Employee Record";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   4:   To Add New Employee Details";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   5:   To Remove an Employee Details";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\t\t\tENTER   0:   To Exit     ";
        cout << "\n\t\t\t------------------------------------------------";
        cout << "\n\n\t\t\t   Please Enter Your Choice: ";

        // Taking the action input for menu
        int choice;
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 0:
            system("CLS");
            cout << "\n\nEMPLOYEE MANAGEMENT SYSTEM \n\n Brought To You By Group nine \n\n ";
            Sleep(10);
            login();
        case 1:
            listEmployees(); // Method for listing records
            break;
        case 2:
            showDetails(); // Method for getting detail
            break;
        case 3:
            editExisting(); // Method for updating records
            break;
        case 4:
            addNewEmployee(); // Method for adding records
            break;
        case 5:
            deleteEmployeeDetails(); // for deleting records
            break;
        default:
            cout << "\n 400 BAD REQUEST  \n";
            break;
        }
    }
}
