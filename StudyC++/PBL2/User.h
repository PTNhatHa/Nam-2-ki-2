// #include <iostream>
// #include <string.h>
// #include <fstream>
// #include <sstream>
// #include <dirent.h>
// #include <filesystem>
// #include <vector>
// #include<thread>
// #include<Windows.h>
// using namespace std;
#include "Exam.h"

#pragma region Class_User
class User : public Exam
{    
public:
    int NumberOfUser;
    int *ID;
    string *Password;
    int Login_ID;
    User();
    ~User();
    void Init();
    void Search();
    virtual void Login();
    virtual void MainProgram() = 0;
};

User::User()
{
    system("cls");
    cout<<"Wellcome to Exam system...."<<endl;
    Init();
    cout<<"Read User data SUCCESSFULLY !!"<<endl;
    Login();
}
User::~User()
{   
    cout<<"Log out SUCCESSFULLY !!"<<endl;
}
void User::Init(){
    //get login data
    ifstream input;
    input.open("User_Data.txt",ios::in);
    input>>NumberOfUser;
    ID = new int[NumberOfUser];
    Password = new string[NumberOfUser];
    for(int i = 0; i<NumberOfUser; i++)
    {
        input>>ID[i];
        input>>Password[i];
    }
    input.close();
}
void User::Login(){
    cout<<"===========================================\n";
    cout<<"|                                         |\n";
    cout<<"|                  LOGIN                  |\n";
    cout<<"|                                         |\n";
    cout<<"===========================================\n\n";
    cout<<"Please Login to continue!!"<<endl;
}
void User::Search(){
    cout<<"List Exam: "<<endl;
    ifstream ip;
    ip.open("ListTest.txt", ios::in);
    string t;
    while (!ip.eof())
    {
        ip>>t;
        cout<<t<<endl;
    }
    cout<<"====================="<<endl;
    cout<<"Enter ID: ";
    int ID;
    cin>>ID;
    string dir;
    dir = "TestDetail/" + to_string(ID) + ".txt";
    ifstream input;
    input.open(dir, ios::in);
    while (!input.eof())
    {
        string temp;
        input>>temp;
        CheckID(stoi(temp));
    }
    system("pause");
}
#pragma endregion Class_User