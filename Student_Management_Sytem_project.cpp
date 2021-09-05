//STUDENT MANAGEMENT SYSTEM by Dishant Kumar Samal
//Run the output in full screen or open the .exe file in full screen after compilation.

#include <iostream>
#include <windows.h>  //used for sleep func.
#include <unistd.h>   
#include <conio.h>    //for _getch functions and other input/output functions.
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
using namespace std;

class Student //class Student to hold the raw data.
{
private:
    // Variables for User and Student details
    string first_name;
    string last_name;
    char Roll_number[3];
    char Course[10];
    char gender[10];
    int age;
    float total_marks;
    char Address[100];
    char contact_no[10];

public:
    void menu();
    void waitForEnter();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

void Student::menu() //Project Menu
{
    int password_user(); //login declaration
    password_user();
    //login screen
    while (true)
    {
        int choice;
        char x; // Options to choose an action
        system("cls");
        cout << "\n\t\t\t\t\t===============================" << endl;
        cout << "\t\t\t\t\t>> STUDENT MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t\t\t===============================" << endl;
        cout << "\t\t\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t\t\t 6. Exit" << endl;

        cout << "\t\t\t\t\t===================================" << endl;
        cout << "\t\t\t\t\t|| Choice Options: [1/2/3/4/5/6] ||" << endl;
        cout << "\t\t\t\t\t===================================" << endl;
        cout << " Enter Your Choice: "; // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:
            do
            {
                insert();
                cout << "\n\n\t\t\t To Add Another Student Data Press (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            waitForEnter();
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;
        case 6:
            system("cls");
            cout << "\n\t\t\t>> STUDENT MANAGEMENT SYSTEM EXIT <<\n\n";
            Sleep(10);
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...Press any key to get back to menu.\n";
        }
        getch();
    }
}

void Student::insert() // add data of student
{
    system("cls");
    fstream file;
    cout << "\n*********************************************************************************************************" << endl;
    cout << "************************************** User Insert Data *************************************************" << endl;
    cout << "\n Enter First Name of Student: ";
    cin >> first_name;
    cout << "\n Enter Last Name of Student: ";
    cin >> last_name;
    cout << "\n Enter Student Roll No [MAX 100]: ";
    cin >> Roll_number;
    cout << "\n Enter Course(Science/Commerce/Arts): ";
    cin >> Course;
    cout << "\n Enter Student Gender(Male/Female/Others): ";
    cin >> gender;
    cout << "\n Enter Student Age: ";
    cin >> age;
    cout << "\n Enter Student Total Marks(/500): ";
    cin >> total_marks;
    if(total_marks>500)
    {
        cout<<"Total mark is 500 but you entered more than 500 marks.";
        cout << "\n Enter Student Total Marks(/500): ";
        cin >> total_marks;
        
    }
    cout << "\n Enter Student Address: ";
    cin >> Address;
    cout << "\n Enter Student contact no.(max 10 digits): ";
    cin >> contact_no;
    file.open("Admin_Record.txt", ios::app | ios::out);
    file << " " << first_name << " " << last_name << " " << Roll_number << " " << Course << " " << gender << " " << age << " " << total_marks << " " << Address << " " << contact_no << "\n";
    file.close();
}

void Student::display() // Displays User data
{
    system("cls");
    int total = 1;
    fstream file;
    cout << "\n=============================================================================================================================" << endl;
    cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ STUDENT DATA TABLE ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
    // cout << "\n" << endl;
    file.open("Admin_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        cout << "=============================================================================================================================" << endl;
        file >> first_name >> last_name >> Roll_number >> Course >> gender >> age >> total_marks >> Address >> contact_no;
        cout << "|" << setw(5) << left << "SNo.";
        cout << "|" << setw(25) << left << "Full Name";
        cout << "|" << setw(10) << left << "Roll No.";
        cout << "|" << setw(15) << left << "course";
        cout << "|" << setw(10) << left << "Gender";
        cout << "|" << setw(5) << left << "Age";
        cout << "|" << setw(15) << left << "Percentage(%)";
        cout << "|" << setw(15) << left << "Address";
        cout << "|" << setw(15) << left << "Contact No.";
        cout << "|" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
        while (!file.eof())
        {
            cout << "|" << setw(5) << left << total++;
            cout << "|" << setw(25) << left << (first_name + " " + last_name);
            cout << "|" << setw(10) << left << Roll_number;
            cout << "|" << setw(15) << left << Course;
            cout << "|" << setw(10) << left << gender;
            cout << "|" << setw(5) << left << age;
            cout << "|" << setw(15) << left << total_marks * 100.0 / 500.0;
            cout << "|" << setw(15) << left << Address;
            cout << "|" << setw(15) << left << contact_no;
            cout << "|" << endl;
            file >> first_name >> last_name >> Roll_number >> Course >> gender >> age >> total_marks >> Address >> contact_no;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data is Present...";
        }
    }
    file.close();
    waitForEnter();
}

void Student::modify() // Modify data of User
{
    system("cls");
    char checkId[5];
    int found = 0;
    fstream file, file1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- User Modify Data ------------------------------------------" << endl;
    file.open("Admin_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Student Roll No.: ";
        cin >> checkId;
        file1.open("data.txt", ios::app | ios::out);
        file >> first_name >> last_name >> Roll_number >> Course >> gender >> age >> total_marks >> Address >> contact_no;
        while (!file.eof())
        {
            if (strcmp(checkId, Roll_number) == 0)
            {
                cout << "\n Enter First Name of Student: ";
                cin >> first_name;
                cout << "\n Enter Last Name of Student: ";
                cin >> last_name;
                cout << "\n Enter Student Roll No. [MAX 100]: ";
                cin >> Roll_number;
                cout << "\n Enter Course(Science/Commerce/Arts): ";
                cin >> Course;
                cout << "\n Enter Student Gender(Male/Female/Others): ";
                cin >> gender;
                cout << "\n Enter Student Age: ";
                cin >> age;
                cout << "\n Enter Student Total Marks(/500): ";
                cin >> total_marks;
                if(total_marks>500)
                {
                    cout<<"\tTotal marks is 500 ... but you entered more than 500 marks.Enter less than or equal to 500 marks.";
                    cout << "\n Enter Student Total Marks(/500): ";
                    cin >> total_marks;
                }
                
                cout << "\n Enter Address: ";
                cin >> Address;
                cout << "\n Enter Student contact no.(max 10 digits): ";
                cin >> contact_no;
                cout << "\n\nSuccessfully Modied Details Of Student";
                file1 << " " << first_name << " " << last_name << " " << Roll_number << " " << Course << " " << gender << " " << age << " " << total_marks << " " << Address << " " << contact_no << "\n";
                found++;
            }
            else
            {
                
                file1 << " " << first_name << " " << last_name << " " << Roll_number << " " << Course << " " << gender << " " << age << " " << total_marks << " " << Address << " " << contact_no << "\n";
            }
            file >> first_name >> last_name >> Roll_number >> Course >> gender >> age >> total_marks >> Address >> contact_no;
        }
        if (found == 0)
        {
            cout << "\n\n\tStudent Roll No. Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Admin_Record.txt");
        rename("data.txt", "Admin_Record.txt");
    }
    waitForEnter();
}

void Student::search() // Search student Data
{                      //Displays all details according to Roll no.
    system("cls");
    fstream file;
    char checkId[5];
    int flag=0;

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- User Search Data -------------------------------------------" << endl;
    file.open("Admin_Record.txt", ios::in);
    cout << "\n\nEnter Student Roll No.: ";
    cin >> checkId;
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> first_name >> last_name >> Roll_number >> Course >> gender >> age >> total_marks >> Address >> contact_no;
        while (!file.eof())
        {

            if (strcmp(checkId, Roll_number) == 0)
            {
                cout << "\n---------------------\n";
                cout << "Student Name: " << first_name << " " << last_name << "\n";
                cout << "Student Roll No.: " << Roll_number << "\n";
                cout << "Course(Science/Commerce/Arts): " << Course << "\n";
                cout << "Student Gender(Male/Female/Others): " << gender << "\n";
                cout << "Student Age: " << age << "\n";
                cout << "Student Total Marks(/500): " << total_marks<<endl ;
                cout << "Student Percentage(max_100%): " << total_marks * 100.0 / 500.0 << "%" << endl;
                cout << "Student Student Address: " << Address << "\n";
                cout << "Student Student Contact No.(max 10 digits): " << contact_no << "\n";
                cout << "---------------------\n";
                flag++;

            }

            file >> first_name >> last_name >> Roll_number >> Course >> gender >> age >> total_marks >> Address >> contact_no;
        }
        if (flag == 0)
        {
            cout << "\n\n\tStudent Roll No. Not Found.. Please Try Again";
        }

    }
    file.close();
    waitForEnter();
}

void Student::deleted() // Delete data of USer
{
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete User Data ------------------------------------------" << endl;
    file.open("Admin_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Student Roll Number to Remove Data: ";
        cin >> checkId;
        file1.open("data.txt", ios::app | ios::out);
        file >> first_name >> last_name >> Roll_number >> Course >> gender >> age >> total_marks >> Address >> contact_no;
        while (!file.eof())
        {
            if (strcmp(checkId, Roll_number) != 0)
            {
                file1 << " " << first_name << " " << last_name << " " << Roll_number << " " << Course << " " << gender << " " << age << " " << total_marks << " " << Address << " " << contact_no << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Deleted Data";
            }
            file >> first_name >> last_name >> Roll_number >> Course >> gender >> age >> total_marks >> Address >> contact_no;
        }
        if (found == 0)
        {
            cout << "\n\n\tStudent Roll No. Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Admin_Record.txt");
        rename("data.txt", "Admin_Record.txt");
        waitForEnter();
    }
}

void Student::waitForEnter()
{
    cout << "\n\nPress enter to go back: ";
    cin.get();
}

int password_user() //Admin Authentication
{
    string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    fstream file;
    char ch;
    system("cls");
    cout << "\n\t\t\t============================================";
    cout << "\n\t\t\t||  WELCOME TO STUDENT MANAGEMENT SYSTEM  ||";
    cout << "\n\t\t\t============================================";
    cout << "\n\n\t\t\t   <| Press: [1] Register & [2] Login  |>";
    int selection;
    cout << "\n\nPlease Enter Value: ";
    cin >> selection;
    // if user press [1], then it would lead them to register.

    if (selection == 1)
    {
        system("cls");
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t>> REGISTRATION EMPLOYEE <<";
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name_reg;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass_reg.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file.open("u_data.txt", ios::app);
        file << " " << name_reg << " " << pass_reg << "\n";
        file.close();
        cout << "\nRegistration Succesfully save";
        getch();
        password_user();
    }
    // if user press [2], then it would lead them to login.
    else if (selection == 2)
    {
        system("cls");
        file.open("u_data.txt", ios::in);
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\t\t\t\t\t>>  LOGIN ADMIN   <<";
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file >> name_reg >> pass_reg;
        while (!file.eof())
        {
            if (pass == pass_reg && name == name_reg)
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying Admin |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Granted..\n\n";
                system("PAUSE");
                system("cls");
            }
            else
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying Admin    |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Denied...\n\n";
                system("PAUSE");
                system("cls");
                password_user();
            }
            file >> name_reg >> pass_reg;
        }
        file.close();
    }
    else
    {
        cout << "\nInvalid Input.. Please Try Again..";
        password_user();
    }
    return 0;
}
int main()
{
    // Call the function
    Student system;
    system.menu();
    return 0;
}
