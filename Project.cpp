#include <iostream>
#include <cmath>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;
// proto types
string adminLogin(string admin_name, string admin_password);
void header();
char mainMenu(string num);
int employ_menu(int employ_num);
int adminMenu(string admin_num);
int customerLogin(int number1);
int customerMenu(int customer_num);
string customerSignin();
string customerSignup();
int category(int categoryNum);
string getField(string line, int field);

// global variables
string num;
int employ_num;
string admin_num;
int customer_num;
int count = 0;
float adminAccount = 99999999999;
int numberOfTrains = 0;
int number1;
int customerData = 0;
int index = 0;
int categoryNum;
int store = 0;
int employeeCount = 0;
float bonusNum;
float Bonus = 0;
int sort = 0;
int customerCount = 0;
int initiativeCount = 0;
string publicNotices;
// global arrays
string trainRoutes[200];
float EmploySalary[200];
string employ_password[200];
string employ_name[200];
string customerName[200];
string customerPassword[200];
string customerContactNo[200];
string customerCNIC[200];
string nearestStation[200];
string Email[200];
string employeeTask[200];
string employeeComplaint[200];
string customerComplaint[200];
int attendance[200];
float deductedAmount[200];
string initiativeName[50];
string initiativeContact[50];
string initiativeCountry[50];
string initiativeEmail[50];
string initiativeDetails[50];
// remvoe cursor from cmd
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

main()
{
    ShowConsoleCursor(false);
    system("cls");
    header();
    mainMenu(num);
}
char mainMenu(string num)
{
    system("cls");
    header();
    cout << "         Input" << endl;
    cout << "Select one of the following;" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Employee" << endl;
    cout << "3. Cutomer" << endl;
    cout << "4. Exit" << endl;
    cout << "Select option : ";
    cin >> num;
    // admin login
    if (num == "1")
    {
        system("cls");
        header();
        string admin_name;
        string admin_password;
        cout << "Please identify your identity: ";
        cin >> admin_name;
        cout << "Enter the correct password: ";
        cin >> admin_password;
        adminLogin(admin_name, admin_password);
    }
    // Employee login
    else if (num == "2")
    {
        int idx = 0;
        system("cls");
        header();
        string employName;
        string employPassword;
        string line;
        fstream newFile;
        newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\EmployeeName.txt", ios::in);
        while (!newFile.eof())
        {
            getline(newFile, line);
            employ_name[idx] = getField(line, 1);
            employ_password[idx] = getField(line, 2);
            idx = idx + 1;
        }
        cout << "Enter your name: ";
        cin >> employName;
        cout << "Enter your password: ";
        cin >> employPassword;
        for (int y = 0; y < idx; y++)
        {
            if (employName == employ_name[y] && employPassword == employ_password[y])
            {
                system("cls");
                header();
                index = y;
                employ_menu(employ_num);
            }
        }
        newFile.close();
        cout << "Invalid Cradientials " << endl;
        cout << "Press any key to continue: ";
        getch();
        mainMenu(num);
    }
    // customer login
    else if (num == "3")
    {
        system("cls");
        header();
        int z = customerLogin(number1);
        if (z == 1)
        {
            customerSignup();
        }
        if (z == 2)
        {
            customerSignin();
        }
        if (z == 3)
        {
            mainMenu(num);
        }
    }
    else if (num == "4")
    {
    }
    else
    {
        cout << "Invalid input " << endl;
        cout << "Press any key to continue" << endl;
        getch();
        mainMenu(num);
    }
}
// admin
int adminMenu(string admin_num)
{
    string line;
    fstream newFile;
    newFile.open("mainMenu.txt", ios::in);
    while (!newFile.eof())
    {
        getline(newFile, line);
        cout << line << endl;
    }
    newFile.close();
    cout << "1.  Add employ. " << endl;
    cout << "2.  Remove employ." << endl;
    cout << "3.  Add new train. " << endl;
    cout << "4.  Remove Train. " << endl;
    cout << "5.  Release pay." << endl;
    cout << "6.  Employees Attendance." << endl;
    cout << "7.  Grant Bonus." << endl;
    cout << "8.  Deductions." << endl;
    cout << "9.  Check customer complaint." << endl;
    cout << "10. Check employee complaint." << endl;
    cout << "11. Employ list & Password." << endl;
    cout << "12. Assign task to employee." << endl;
    cout << "13. Change the password of employee." << endl;
    cout << "14. Give promortion." << endl;
    cout << "15. Pblic Notice: " << endl;
    cout << "16. Initiative requests." << endl;
    cout << "17. Exit." << endl;
    cout << "Select option:  ";
    cin >> admin_num;
    if (admin_num == "1")
    {
        string employeeName;
        string name;
        string employeePassword;
        string password;
        float salary;
        system("cls");
        header();
        for (int y = 0; y <= 5; y++)
        {
            cout << "Enter " << y + 1 << " employee  name (Capital letters): ";
            cin >> name;
            bool tf = false;
            for (int y = 0; y <= count; y++)
            {
                if (name == employ_name[y])
                {
                    cout << " Name Already Exists" << endl;
                    tf = true;
                    cout << "Press any key to continue" << endl;
                    getch();
                    continue;
                }
            }
            if (tf == false)
            {
                cout << "Assign Password (Four digit): ";
                cin >> password;
                if (password.length() == 4)
                {
                    employ_password[count] = password;
                    employ_name[count] = name;
                    cout << "Enter the ammount of salary :";
                    cin >> salary;
                    if (salary > 0)
                    {
                        EmploySalary[count] = salary;
                    }
                    else
                    {
                        cout << "Salary must be in postitve " << endl;
                        cout << "Press any key to continue" << endl;
                        getch();
                        continue;
                    }
                    count = count + 1;
                    cout << "Succesfully Assigned" << endl;
                    cout << "Press any key to continue" << endl;
                    getch();
                }
                else
                {
                    cout << "Failed to assign " << endl;
                    cout << "Press any key to continue" << endl;
                    getch();
                    continue;
                }
            }
        }
        fstream newFile;
        string line;
        newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\EmployeeName.txt", ios::out);
        for (int y = 0; y < count; y++)
        {
            newFile << employ_name[y] << "," << employ_password[y] << endl;
        }
        newFile.close();
        system("cls");
        header();
        adminMenu(admin_num);
    }
    if (admin_num == "2")
    {
        int idx = 0;
        string line;
        fstream newFile;
        string removeEmployee;
        system("cls");
        header();
        newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\EmployeeName.txt", ios::in);
        while (!newFile.eof())
        {
            getline(newFile, line);
            employ_name[idx] = getField(line, 1);
            employ_password[idx] = getField(line, 2);
            idx = idx + 1;
        }
        newFile.close();
        cout << "Enter the name of Employee you want to remove: ";
        cin >> removeEmployee;
        for (int y = 0; y <= idx; y++)
        {
            if (removeEmployee == employ_name[y])
            {
                employ_name[y] = " ";
                employ_password[y] = " ";
            }
        }
        idx = idx - 2;
        newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\EmployeeName.txt", ios::out);
        for (int y = 0; y <= idx; y++)
        {
            newFile << employ_name[y] << "," << employ_password[y] << endl;
        }
        newFile.close();
        cout << "Successfully Removed" << endl;
        count = count - 1;
        cout << "Press any Key to continue" << endl;
        getch();
        adminMenu(admin_num);
        {

            cout << "NO RECORD FOUND" << endl;
            cout << "Press any Key to continue" << endl;
            getch();
            system("cls");
            header();
            adminMenu(admin_num);
        }
    }
    if (admin_num == "3")
    {
        string routes;
        fstream newFile;
        string junctionName;
        bool tf = false;
        system("cls");
        header();
        cout << "Enter the new junction point: ";
        cin >> junctionName;
        for (int y = 0; y < numberOfTrains; y++)
        {
            if (junctionName == trainRoutes[y])
            {
                cout << "Junction already added " << endl;
                tf = true;
                cout << "Press any key to cotinue" << endl;
                getch();
                system("cls");
                header();
                adminMenu(admin_num);
            }
        }
        if (tf == false)
        {
            newFile.open("Junctions.txt", ios::app);
            routes == junctionName;
            newFile << junctionName << endl;
            newFile.close();
            trainRoutes[numberOfTrains] = junctionName;
            cout << "Succesfully Added the junction" << endl;
            cout << "Press any key to cotinue" << endl;
            getch();
            numberOfTrains = numberOfTrains + 1;
        }
        adminMenu(admin_num);
    }
    if (admin_num == "4")
    {
        int idx = 0;
        string line;
        string removeJunction;
        system("cls");
        header();
        fstream newFile;
        cout << "Enter the name of junction you want to remove: ";
        cin >> removeJunction;
        newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\Junctions.txt", ios::in);
        while (!newFile.eof())
        {
            getline(newFile, line);
            trainRoutes[idx] = getField(line, 1);
            idx = idx + 1;
        }
        newFile.close();
        for (int y = 0; y <= idx; y++)
        {
            if (removeJunction == trainRoutes[y])
            {
                trainRoutes[y] == " ";
                newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\Junctions.txt", ios::out);
                for (int y = 0; y <= idx; y++)
                {
                    newFile << trainRoutes[y];
                }
                newFile.close();
                cout << "Sccessfully Removed the Junction" << endl;
                cout << "Press any key to cotinue" << endl;
                getch();
                adminMenu(admin_num);
            }
            else
            {
                cout << "NO RECORD FOUND" << endl;
                cout << "Press any Key to continue" << endl;
                getch();
                system("cls");
                header();
                adminMenu(admin_num);
            }
        }
    }
    if (admin_num == "5")
    {
        system("cls");
        header();
        float pay = 0;
        for (int y = 0; y <= count; y++)
        {
            pay = pay + EmploySalary[y];
        }
        cout << "The total ammount of salary to be paid is: " << pay << endl;
        if (adminAccount >= pay)
        {
            cout << "Successfully released " << endl;
            adminAccount = adminAccount - pay;
            cout << "Press any Key to continue" << endl;
            getch();
            system("cls");
            header();
            adminMenu(admin_num);
        }
        if (adminAccount < pay)
        {
            cout << "Your expenses are running out of order" << endl;
            cout << "Press any Key to continue" << endl;
            getch();
            system("cls");
            header();
            adminMenu(admin_num);
        }
    }
    if (admin_num == "6")
    {
        int idx = 0;
        system("cls");
        header();
        string name;
        fstream newFile;
        string line;
        newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\EmployeeName.txt", ios::in);
        while (!newFile.eof())
        {
            getline(newFile, line);
            employ_name[idx] = getField(line, 1);
            idx = idx + 1;
        }
        newFile.close();
        cout << "Enter the name of the employee : ";
        cin >> name;
        for (int y = 0; y <= idx; y++)
        {
            if (name == employ_name[y])
            {
                cout << attendance[y] << endl;
                cout << "Press any key to continue" << endl;
                getch();
                system("cls");
                header();
                adminMenu(admin_num);
            }
        }
    }
    if (admin_num == "7")
    {
        system("cls");
        header();
        cout << "Enter the percentage of bonus you want alott:  ";
        cin >> bonusNum;
        if (bonusNum > 0)
        {
            for (int y = 0; y <= count; y++)
            {
                EmploySalary[y] = EmploySalary[y] + ((EmploySalary[y] / 100) * bonusNum);
                cout << "Press any key to continue" << endl;
                getch();
                system("cls");
                header();
                adminMenu(admin_num);
            }
        }
        else
        {
            cout << "Bonus must be in postive" << endl;
            cout << "Press any key to continue" << endl;
            getch();
            system("cls");
            header();
            adminMenu(admin_num);
        }
    }
    if (admin_num == "8")
    {
        system("cls");
        header();
        float num;
        string name;
        cout << "Enter the name of the employee : ";
        cin >> name;
        for (int y = 0; y <= count; y++)
        {
            if (name == employ_name[y])
            {
                cout << "Enter the percentage you want to deduct: ";
                cin >> num;
                if (num > 0)
                {
                    deductedAmount[y] = ((EmploySalary[y] / 100) * num);
                    sort = y;
                    EmploySalary[y] = EmploySalary[y] - deductedAmount[y];
                    cout << "Successfully Deducted" << endl;
                    cout << "Press any Key to continue" << endl;
                    getch();
                    system("cls");
                    header();
                    adminMenu(admin_num);
                }
                else
                {
                    cout << "Deducted amount must be in postive" << endl;
                    cout << "Press any key to continue" << endl;
                    getch();
                    system("cls");
                    header();
                    adminMenu(admin_num);
                }
            }
            if (name != employ_name[y])
            {
                cout << "Invalid Employee name" << endl;
                cout << "Press any Key to continue" << endl;
                getch();
                system("cls");
                header();
                adminMenu(admin_num);
            }
        }
    }
    if (admin_num == "9")
    {
        system("cls");
        header();
        for (int y = 0; y < customerCount; y++)
        {
            cout << "Complainer name: " << customerName[y] << endl;
            cout << "\t" << customerComplaint[y] << endl;
            cout << endl;
        }
        cout << "Press any Key to continue" << endl;
        getch();
        system("cls");
        header();
        adminMenu(admin_num);
    }
    if (admin_num == "10")
    {
        system("cls");
        header();
        for (int y = 0; y < employeeCount; y++)
        {
            cout << "Complainer name: " << employ_name[y] << endl;
            cout << "NO." << y + 1 << "\t" << employeeComplaint[y] << endl;
        }
        cout << endl;
        cout << "Press any Key to continue" << endl;
        getch();
        system("cls");
        header();
        adminMenu(admin_num);
    }
    if (admin_num == "11")
    {
        system("cls");
        header();
        fstream newFile;
        string line;
        newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\EmployeeName.txt", ios::in);
        while (!newFile.eof())
        {
            getline(newFile, line);
            cout << line << endl;
        }
        newFile.close();
        cout << "Press any Key to continue" << endl;
        getch();
        system("cls");
        header();
        adminMenu(admin_num);
    }
    if (admin_num == "12")
    {
        system("cls");
        header();
        string name;
        cout << "Enter the name of the employee to whom you want to assign the task: ";
        cin >> name;
        for (int y = 0; y <= count; y++)
        {
            if (name == employ_name[y])
            {
                cout << "Enter the task you want to assign: ";
                cin >> employeeTask[y];
                store = y;
                cout << "Succesfully Assigned" << endl;
                cout << "Press any Key to continue" << endl;
                getch();
                system("cls");
                header();
                adminMenu(admin_num);
            }
        }
        for (int y = 0; y <= count; y++)
        {
            if (name != employ_name[y])
            {
                cout << "Invalid Employee name " << endl;
                cout << "Press any Key to continue" << endl;
                getch();
                system("cls");
                header();
                adminMenu(admin_num);
            }
        }
    }
    if (admin_num == "13")
    {
        system("cls");
        header();
        string name;
        string password;
        cout << "Enter the name of the employee :";
        cin >> name;
        for (int y = 0; y < count; y++)
        {
            if (name == employ_name[y])
            {
                cout << "Enter the new password :";
                cin >> password;
                if (password.length() == 4)
                {
                    employ_password[y] = password;
                    fstream newfile;
                    string line;
                    newfile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\EmployeeName.txt", ios::out);
                    for (int y = 0; y < count; y++)
                    {
                        newfile << employ_name[y] << "," << employ_password[y] << endl;
                    }
                    newfile.close();
                    cout << "Successfully changed " << endl;
                    cout << "Press any Key to continue" << endl;
                    getch();
                    system("cls");
                    header();
                    adminMenu(admin_num);
                }
                else
                {
                    cout << "Failed to change the password " << endl;
                    cout << "Press any Key to continue" << endl;
                    getch();
                    system("cls");
                    header();
                    adminMenu(admin_num);
                }
            }
            if (name != employ_name[y])
            {
                cout << "Name does't exists";
                cout << "Press any Key to continue" << endl;
                getch();
                system("cls");
                header();
                adminMenu(admin_num);
            }
        }
    }
    if (admin_num == "14")
    {
        system("cls");
        header();
        string name;
        fstream newFile;
        string line;
        int idx = 0;
        newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\EmployeeName.txt", ios::in);
        while (!newFile.eof())
        {
            getline(newFile, line);
            employ_name[idx] = getField(line, 1);
            idx = idx + 1;
        }
        newFile.close();
        cout << "Enter the name of the employee whom you want to give promortion: ";
        cin >> name;
        for (int y = 0; y <= idx; y++)
        {
            if (name == employ_name[y])
            {
                float promortion;
                cout << "Enter the percentage of the slary you want to increment: ";
                cin >> promortion;
                EmploySalary[y] = EmploySalary[y] + ((EmploySalary[y] / 100) * promortion);
                cout << "Successfully Promoted " << endl;
                cout << "Press any Key to continue" << endl;
                getch();
                system("cls");
                header();
                adminMenu(admin_num);
            }
        }
        for (int y = 0; y < count; y++)
        {
            if (name != employ_name[y])
            {
                cout << "Name does't exists" << endl;
                cout << "Press any Key to continue" << endl;
                getch();
                system("cls");
                header();
                adminMenu(admin_num);
            }
        }
    }
    if (admin_num == "15")
    {
        system("cls");
        header();
        string line;
        fstream newFile;
        cout << "Enter the new notice: ";
        cin >> publicNotices;
        newFile.open("Public Notices.txt", ios::out);
        line = publicNotices;
        newFile << line << endl;
        newFile.close();
        cout << endl;
        cout << "Suuccessfully added" << endl;
        cout << "Press any Key to continue" << endl;
        getch();
        system("cls");
        header();
        adminMenu(admin_num);
    }
    if (admin_num == "16")
    {
        system("cls");
        header();
        int idx = 0;
        fstream newFile;
        string line;
        newFile.open("Initiative.txt", ios::in);
        while (!newFile.eof())
        {
            getline(newFile, line);
            initiativeName[idx] = getField(line, 1);
            initiativeContact[idx] = getField(line, 2);
            initiativeCountry[idx] = getField(line, 3);
            initiativeEmail[idx] = getField(line, 4);
            initiativeDetails[idx] = getField(line, 5);
        }
        newFile.close();
        for (int y = 0; y <= idx; y++)
        {
            cout << "Sender name: " << initiativeName[y] << endl;
            cout << "Sender Email: " << initiativeEmail[y] << endl;
            cout << "Sender Contact no: " << initiativeContact[y] << endl;
            cout << "Sender Country:  " << initiativeCountry[y] << endl;
            cout << "Details:  " << initiativeDetails[y] << endl;
            cout << endl;
        }
        cout << "Press any Key to continue" << endl;
        getch();
        system("cls");
        header();
        adminMenu(admin_num);
    }
    else if (admin_num == "17")
    {
        cout << "Press any key to make sure you want to exit:  ";
        getch();
        mainMenu(num);
    }
    else
    {
        cout << "Invalid Input" << endl;
        cout << "Press any key to continue ";
        getch();
        system("cls");
        header();
        adminMenu(admin_num);
    }
}

// header
void header()
{
    // string line;
    // fstream newFile;
    // newFile.open("header.txt", ios::in);
    // while (!newFile.eof())
    // {
    //     getline(newFile, line);
    //     // system("Color B4");
    //     cout << line << endl;
    // }
    // newFile.close();
}
// admin login
string adminLogin(string admin_name, string admin_password)
{
    if (admin_name == "NOUMAN" && admin_password == "1242")
    {
        system("cls");
        header();
        adminMenu(admin_num);
    }

    else
    {
        cout << "INVALID CRADENTIALS: " << endl;
        cout << "Press any key to continue";
        getch();
        mainMenu(num);
    }
}
// employee menu
int employ_menu(int employ_num)
{
    system("cls");
    header();
    cout << "Main menu" << endl;
    cout << "-------------------------" << endl;
    cout << "1.  Mark Attendance " << endl;
    cout << "2.  View Balance" << endl;
    cout << "3.  View Alotted Bonus" << endl;
    cout << "4.  View running attendance" << endl;
    cout << "5.  Withdraw Salary" << endl;
    cout << "6.  View assigned Tasks / Duties" << endl;
    cout << "7.  Deducted Amount " << endl;
    cout << "8.  Change Password" << endl;
    cout << "9.  Lodge a complaint" << endl;
    cout << "10. Exit" << endl;
    cout << "Select option:  ";
    cin >> employ_num;

    if (employ_num == 1)
    {
        int date;
        int month;
        int year;
        cout << "Enter the today date : ";
        cin >> date;
        cout << "Enter the month number : ";
        cin >> month;
        cout << "Enter the year : ";
        cin >> year;
        attendance[index] = attendance[index] + 1;
        cout << "Succesfully Marked" << endl;
        cout << "Press any key to continue" << endl;
        getch();
        employ_menu(employ_num);
    }
    if (employ_num == 2)
    {
        cout << "Your current Balance is: " << EmploySalary[index] << endl;
        cout << "Press any key to continue" << endl;
        getch();
        employ_menu(employ_num);
    }
    if (employ_num == 3)
    {
        Bonus = (EmploySalary[index] / 100) * bonusNum;
        cout << Bonus << endl;
        cout << "Press any key to continue" << endl;
        getch();
        employ_menu(employ_num);
    }
    if (employ_num == 4)
    {
        cout << "Your Running attendace is: " << attendance[index] << endl;
        cout << "Press any key to continue" << endl;
        getch();
        employ_menu(employ_num);
    }
    if (employ_num == 5)
    {
        float num;
        float employeeAccountNo;
        cout << "Enter the account number: ";
        cin >> employeeAccountNo;
        cout << "Enter the ammount you want to withdraw: ";
        cin >> num;
        if (num <= EmploySalary[index])
        {
            EmploySalary[index] = EmploySalary[index] - num;
            cout << "Successfully Transferred" << endl;
            cout << "Your remaining balance is : " << EmploySalary[index] << endl;
            cout << "Press any key to continue" << endl;
            getch();
            employ_menu(employ_num);
        }
        if (num > EmploySalary[index])
        {
            cout << "Insufficent Balance" << endl;
            cout << "Press any key to continue" << endl;
            getch();
            employ_menu(employ_num);
        }
    }
    if (employ_num == 6)
    {
        cout << "Your assigned task is: " << employeeTask[store] << endl;
        cout << "Press any key to continue" << endl;
        getch();
        employ_menu(employ_num);
    }
    if (employ_num == 7)
    {
        cout << "The deducted amount is: " << deductedAmount[sort] << endl;
        cout << "Press any key to continue" << endl;
        getch();
        employ_menu(employ_num);
    }
    if (employ_num == 8)
    {
        string password;
        cout << "Enter the old password ";
        cin >> password;
        if (password == employ_password[index])
        {
            cout << "Enter the new password: ";
            cin >> employ_password[index];
            cout << "Succesfully Changed" << endl;
            cout << "Please Login again " << endl;
            cout << "Press any key to continue: ";
            getch();
            mainMenu(num);
        }
        else
        {
            cout << "Incorrect Old Password" << endl;
            cout << "Press any key to continue: ";
            getch();
            employ_menu(employ_num);
        }
    }
    if (employ_num == 9)
    {
        cout << "Enter the complaint: ";
        cin >> employeeComplaint[employeeCount];
        employeeCount = employeeCount + 1;
        cout << "Successfully submitted" << endl;
        cout << "Press any key to continue: ";
        getch();
        employ_menu(employ_num);
    }
    if (employ_num == 10)
    {
        mainMenu(num);
    }
}
// customer menu
int customerMenu(int customer_num)
{
    system("cls");
    header();
    cout << "Main menu" << endl;
    cout << "-------------------------" << endl;
    cout << "1.  Train timings" << endl;
    cout << "2.  Calculate Fare" << endl;
    cout << "3.  Go for E-tickets " << endl;
    cout << "4.  Freight rates" << endl;
    cout << "5.  Public notices" << endl;
    cout << "6.  Career" << endl;
    cout << "7.  Initiative Junction" << endl;
    cout << "8.  General info" << endl;
    cout << "9.  Lodge a Complaint" << endl;
    cout << "10. FAQ's" << endl;
    cout << "11. Logout" << endl;
    cout << "Select option:  ";
    cin >> customer_num;
    if (customer_num == 1)
    {
        system("cls");
        header();
        string startPoint;
        string endPoint;
        cout << "Enter the start point: ";
        cin >> startPoint;
        cout << "Enter the destinantion point: ";
        cin >> endPoint;
        if (startPoint == "LAHORE")
        {

            cout << "The starting time is 6 A.M." << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
        if (startPoint == "RAWALPINDI")
        {
            cout << "The starting time is 10 A.M." << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
        if (startPoint == "KARACHI")
        {
            cout << "The starting point is 3 P.M." << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
    }

    if (customer_num == 2)
    {
        system("cls");
        header();
        string startPoint;
        string endPoint;
        float farePrice;
        cout << "Enter Starting Point:  ";
        cin >> startPoint;
        cout << "Enter destination point:  ";
        cin >> endPoint;
        if (startPoint == "LAHORE" && endPoint == "RAWALPINDI" || (startPoint == "RAWALPINDI" && endPoint == "LAHORE"))
        {
            cout << "The calculated fare is: 600 Rs." << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
        if (startPoint == "LAHORE" && endPoint == "KARACHI" || (startPoint == "KARACHI" && endPoint == "LAHORE"))
        {
            cout << "The calculated fare is: 1200 Rs." << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
        if (startPoint == "RAWALPINDI" && endPoint == "KARACHI" || (startPoint == "KARACHI" && endPoint == "RAWALPINDI"))
        {
            cout << "The calculated fare is: 800 Rs." << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
    }
    if (customer_num == 3)
    {
        int num;
        system("cls");
        header();
        string startPoint;
        string endPoint;
        cout << "Enter Starting Point:  ";
        cin >> startPoint;
        cout << "Enter destination point:  ";
        cin >> endPoint;
        if (startPoint == "LAHORE" && endPoint == "RAWALPINDI")
        {
            cout << "The starting tine is 6 A.M." << endl;
            cout << "The ticket price is 600 Rs. per person." << endl;
            cout << "Enter the number of tickets you want to buy: ";
            cin >> num;
            cout << endl;
            cout << "The total price to be paid is: " << num * 600 << " Rs." << endl;
            cout << "Press Enter key to confirm your purchase " << endl;
            getch();
            cout << "Successfully Purchased" << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
        if (startPoint == "RAWALPINDI" && endPoint == "LAHORE")
        {
            cout << "The starting tine is 10 A.M." << endl;
            cout << "The ticket price is 600 Rs. per person." << endl;
            cout << "Enter the number of tickets you want to buy: ";
            cin >> num;
            cout << endl;
            cout << "The total price to be paid is: " << num * 600 << " Rs." << endl;
            cout << "Press Enter key to confirm your purchase " << endl;
            getch();
            cout << "Successfully Purchased" << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
        if (startPoint == "LAHORE" && endPoint == "KARACHI")
        {
            cout << "The starting tine is 10 A.M." << endl;
            cout << "The ticket price is 1200 Rs. per person." << endl;
            cout << "Enter the number of tickets you want to buy: ";
            cin >> num;
            cout << endl;
            cout << "The total price to be paid is: " << num * 1200 << " Rs." << endl;
            cout << "Press Enter key to confirm your purchase " << endl;
            getch();
            cout << "Successfully Purchased" << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
        if (startPoint == "KARACHI" && endPoint == "LAHORE")
        {
            cout << "The starting tine is 3 P.M." << endl;
            cout << "The ticket price is 1200 Rs. per person." << endl;
            cout << "Enter the number of tickets you want to buy: ";
            cin >> num;
            cout << endl;
            cout << "The total price to be paid is: " << num * 1200 << " Rs." << endl;
            cout << "Press Enter key to confirm your purchase " << endl;
            getch();
            cout << "Successfully Purchased" << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
        if (startPoint == "RAWALPINDI" && endPoint == "KARACHI")
        {
            cout << "The starting tine is 10 A.M." << endl;
            cout << "The ticket price is 800 Rs. per person." << endl;
            cout << "Enter the number of tickets you want to buy: ";
            cin >> num;
            cout << endl;
            cout << "The total price to be paid is: " << num * 800 << " Rs." << endl;
            cout << "Press Enter key to confirm your purchase " << endl;
            getch();
            cout << "Successfully Purchased" << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
        if (startPoint == "KARACHI" && endPoint == "RAWALPINDI")
        {
            cout << "The starting tine is 3 P.M." << endl;
            cout << "The ticket price is 800 Rs. per person." << endl;
            cout << "Enter the number of tickets you want to buy: ";
            cin >> num;
            cout << endl;
            cout << "The total price to be paid is: " << num * 800 << " Rs." << endl;
            cout << "Press Enter key to confirm your purchase " << endl;
            getch();
            cout << "Successfully Purchased" << endl;
            cout << endl;
            cout << "Press any key to continue";
            getch();
            customerMenu(customer_num);
        }
    }
    if (customer_num == 4)
    {
        cout << "\t"
             << "Popular Destinations" << endl;
        cout << "From Lahore to Karachi= upto 1400Rs. " << endl;
        cout << "From Rawalpindi to Karachi= upto 1550Rs." << endl;
        cout << "From Multan to Karachi= upto 1000Rs." << endl;
        cout << "from Quetta to Karachi= upto 800Rs." << endl;
        cout << "From Karachi to Lahore= upto 1400Rs." << endl;
        cout << "From Rawalpindi to Lahore= upto 500Rs." << endl;
        cout << "From Multan to Lahore= upto 500Rs." << endl;
        cout << "From Quetta to Lhaore= upto 1050Rs." << endl;
        cout << "From Karachi to Islamabad= upto 1550Rs." << endl;
        cout << "From Lahore to Islamabad= upto 500Rs." << endl;
        cout << "From Multan to Islamabad= upto 600Rs." << endl;
        cout << "From Quetta to Islamabad= upto 1850Rs." << endl;
        cout << endl;
        cout << "Press any key to continue";
        getch();
        customerMenu(customer_num);
    }
    if (customer_num == 5)
    {
        fstream newFile;
        string line;
        newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\Public Notices.txt", ios::in);
        while (!newFile.eof())
        {
            getline(newFile, line);
            cout << line << endl;
        }
        newFile.close();
        cout << "Press any key to continue" << endl;
        getch();
        customerMenu(customer_num);
    }
    if (customer_num == 6)
    {
        cout << "There will be no career availiable at that moment" << endl;
        cout << endl;
        cout << "Press any key to continue" << endl;
        getch();
        customerMenu(customer_num);
    }
    if (customer_num == 7)
    {
        cout << "Enter Your name : ";
        cin >> initiativeName[initiativeCount];
        cout << "Enter your contact no. ";
        cin >> initiativeContact[initiativeCount];
        cout << "Enter your Country: ";
        cin >> initiativeCountry[initiativeCount];
        cout << "Enter your email: ";
        cin >> initiativeEmail[initiativeCount];
        cout << "Enter your Details:  ";
        cin >> initiativeDetails[initiativeCount];
        fstream newFile;
        string line;
        newFile.open("Initiative.txt", ios::app);
        newFile << initiativeName[initiativeCount] << "," << initiativeContact[initiativeCount] << "," << initiativeCountry[initiativeCount] << "," << initiativeEmail[initiativeCount] << "," << initiativeDetails[initiativeCount] << endl;
        newFile.close();
        initiativeCount = initiativeCount + 1;
        cout << "Press any Key to continue" << endl;
        getch();
        system("cls");
        header();
        customerMenu(customer_num);
    }
    if (customer_num == 8)
    {
        string line;
        cout << "Enter your Gallery here: ";
        cin >> line;
        cout << endl;
        cout << "Press any Key to continue" << endl;
        getch();
        system("cls");
        header();
        customerMenu(customer_num);
    }
    if (customer_num == 9)
    {
        cout << "Enter your complaint(Starting with your name): ";
        cin >> customerComplaint[customerCount];
        cout << "Press any Key to continue" << endl;
        getch();
        system("cls");
        header();
        customerMenu(customer_num);
    }
    if (customer_num == 10)
    {
        system("cls");
        header();
        int num;
        cout << "1.What are important travel tips? " << endl;
        cout << "2.CAN I BOOK A TICKET FROM ANYWHERE?" << endl;
        cout << "3.HOW MANY DAYS IN ADVANCE I CAN RESERVE MY TICKET?" << endl;
        cout << "4.HOW DO I KNOW THE RESERVATION STATUS OF MY TICKET?" << endl;
        cout << "5.WHAT ARE THE FACILITIES FOR COMPUTERIZED RESERVATION?" << endl;
        cout << "6.HOW CAN I BOARD A TRAIN IN THE RESERVED COACH IF I AM NOT ABLE TO GET A RESERVED TICKET?" << endl;
        cout << "7.HOW DO I FIND OUT THE CURRENT STATUS OF MY UNCONFIRMED TICKET?" << endl;
        cout << "Select option: ";
        cin >> num;
        if (num == 1)
        {
            system("cls");
            header();
            cout << "Excess fare ticket issued by the ticket checking staff will be more expensive than the ticket issued from the booking window. The passengers are requested to buy tickets from booking windows/Reservation Offices." << endl;
            cout << "Tickets are not transferable if a passenger commences journey on a ticket against which reservation for another person has been made and is found traveling. As such he will be considered as traveling without a proper ticket and will be dealt with under Section 113 of the Railway Act." << endl;
            cout << "Before leaving the Reservation Counter, please ensure that Train No. Date of Journey/Berth/Seat No. and Name of passenger is recorded on the ticket." << endl;
            cout << "All passengers are requested not to accept any eatable from any unknown/unauthorized person." << endl;
            cout << "Press any Key to continue" << endl;
            getch();
            system("cls");
            header();
            customerMenu(customer_num);
        }
        if (num == 2)
        {
            system("cls");
            header();
            cout << "Berths/Seats can be reserved from Railway Reservation Offices, PRACS Reservation Offices and on line E-ticketing." << endl;
            cout << "Press any Key to continue" << endl;
            getch();
            system("cls");
            header();
            customerMenu(customer_num);
        }
        if (num == 3)
        {
            system("cls");
            header();
            cout << "Seats/Berths can be got reserved maximum up to 90 days in advance" << endl;
            cout << "Press any Key to continue" << endl;
            getch();
            system("cls");
            header();
            customerMenu(customer_num);
        }
        if (num == 4)
        {
            system("cls");
            header();
            cout << "From Reservation Offices on a telephone, on personal visit or from Conductor Guard or from your account dashboard ofbefore departure of train." << endl;
            cout << "Press any Key to continue" << endl;
            getch();
            system("cls");
            header();
            customerMenu(customer_num);
        }
        if (num == 5)
        {
            system("cls");
            header();
            cout << "Computerized reservation facilities are provided at online E-ticketing and all main Railway reservation offices including return journey ticket." << endl;
            cout << "Press any Key to continue" << endl;
            getch();
            system("cls");
            header();
            customerMenu(customer_num);
        }
        if (num == 6)
        {
            system("cls");
            header();
            cout << "By contacting Conductor Guard subject to availability of accommodation." << endl;
            cout << "Press any Key to continue" << endl;
            getch();
            system("cls");
            header();
            customerMenu(customer_num);
        }
        if (num == 7)
        {
            system("cls");
            header();
            cout << "By visiting Reservation Office or contacting Conductor Guard before train departure." << endl;
            cout << "Press any Key to continue" << endl;
            getch();
            system("cls");
            header();
            customerMenu(customer_num);
        }
    }

    if (customer_num == 11)
    {
        mainMenu(num);
    }
}

int customerLogin(int number1)
{
    cout << "         Input" << endl;
    cout << "Select one of the following;" << endl;
    cout << "1. Signup" << endl;
    cout << "2. Signin" << endl;
    cout << "3. EXIT" << endl;
    cout << "Select one option:  ";
    cin >> number1;
    return number1;
}
string customerSignup()
{
    int idx = 0;
    bool tf = false;
    string name;
    system("cls");
    header();
    cout << "Name: ";
    cin >> name;
    string line;
    fstream newFile;
    newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\CustomerData.txt", ios::in);
    while (!newFile.eof())
    {
        getline(newFile, line);
        customerName[idx] = getField(line, 1);
        idx = idx + 1;
    }
    newFile.close();
    for (int y = 0; y <= idx; y++)
    {
        if (name == customerName[y])
        {
            cout << "Username already taken" << endl;
            tf = true;
            cout << "Press any key to continue:" << endl;
            getch();
            system("cls");
            header();
            mainMenu(num);
        }
    }
    if (tf == false)
    {
        string contactNo;
        string CNIC;
        string password;
        cout << "Contact No. ";
        cin >> contactNo;
        cout << "CNIC No. (without space)  ";
        cin >> CNIC;
        cout << "Password (5 digit password): ";
        cin >> password;
        if (CNIC.length() == 13 && contactNo.length() == 11 && password.length() == 5)
        {
            customerName[customerData] = name;
            customerCNIC[customerData] = CNIC;
            customerContactNo[customerData] = contactNo;
            customerPassword[customerData] = password;
            cout << "Emai Adress: ";
            cin >> Email[customerData];
            cout << "Nearest station: ";
            cin >> nearestStation[customerData];
            string line;
            customerData = customerData + 1;
            fstream newFile;
            newFile.open("CustomerData.txt", ios::app);
            for (int y = 0; y <= customerData; y++)
            {
                newFile << customerName[y] << "," << customerPassword[y] << endl;
                newFile.close();
            }
            cout << "Successfully created " << endl;
            cout << "Please Signin" << endl;
            cout << "Press any key to continue:" << endl;
            getch();
            system("cls");
            header();
            customerSignin();
        }
        else
        {
            cout << "Failed to signup" << endl;
            cout << "Press any key to continue" << endl;
            getch();
            system("cls");
            header();
            mainMenu(num);
        }
    }
}
string customerSignin()
{
    int idx = 0;
    string customer_name;
    string customer_password;
    string line;
    fstream newFile;
    newFile.open("C:\\Users\\Nouma\\OneDrive\\Desktop\\Application\\CustomerData.txt", ios::in);
    while (!newFile.eof())
    {
        getline(newFile, line);
        customerName[idx] = getField(line, 1);
        customerPassword[idx] = getField(line, 2);
        idx = idx + 1;
    }
    cout << "Enter your name: ";
    cin >> customer_name;
    cout << "Enter your password: ";
    cin >> customer_password;
    for (int y = 0; y <= idx; y++)
    {
        if (customer_name == customerName[y] && customer_password == customerPassword[y])
        {
            customerMenu(customer_num);
        }
    }
    {
        cout << "NO RECORD FOUND!" << endl;
        Sleep(1000);
        system("cls");
        header();
        mainMenu(num);
    }
}

string getField(string line, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < line.length(); x++)
    {
        if (line[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + line[x];
        }
    }
    return item;
}