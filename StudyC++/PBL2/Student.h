#include "User.h"

#pragma region Class_Student
class Student : private User
{
private:
    int n_std;
    string Name;
public:
    Student();
    ~Student();
    bool Login(int, string);
    void MainProgram();
    void Examination();
};
Student:: Student()
{
    int tempID;
    string tempPass;
    do
    {
        cout<<"__________________________________________"<<endl;
        cout<<"ID: ";
        cin>>tempID;
        cout<<"Password: ";
        cin>>tempPass;
        cout<<"__________________________________________"<<endl;
    } while (!Login(tempID,tempPass));

    ifstream input;
    input.open("Student_Data.txt", ios::in);
    string data;
    getline(input, data);
    n_std = stoi(data);
    int check = 0;

    while (!input.eof())
    {
        getline(input, data);
        if(data == to_string(Login_ID)){
            getline(input, data);
            Name = data;
            break;
        }
    }

    system("pause");
    system("cls"); 
    MainProgram();
}
Student:: ~Student()
{
}
bool Student::Login(int lgID, string lgPass){
    for(int i = 0; i<NumberOfUser; i++){
        if(lgID == ID[i] && lgPass == Password[i] && lgID / 1000 == 1){
            cout<<"Login SUCCESSFULLY !!"<<endl;
            Login_ID = lgID;
            return true;
        }
    }
    system("cls"); 
    return false;
}
void Student::MainProgram(){
    int c;
    do
    {
        system("cls"); 
        cout<<"===========================================\n";
        cout<<"|                                         |\n";
        cout<<"|                 STUDENT                 |\n";
        cout<<"|                                         |\n";
        cout<<"===========================================\n\n";
        cout<<"Welcome Student : "<<Name<<" ..!"<<endl;

        cout<<"_______________Command List_______________"<<endl;
        cout<<"0. Log out "<<endl;
        cout<<"1. Examination "<<endl;
        cout<<"2. Find Exam "<<endl;
        cout<<"__________________________________________"<<endl;
        cout<<"Enter your Action: ";
        cin>>c;
        system("cls");
        switch (c)
        {
            case 0:

                break;
            case 1:
                Examination();
                break;
            case 2:
                Search();
                break;
        }

    } while (c!=0);
    
}

void Student::Examination(){
    cout<<"Examination...."<<endl;
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
    
    string data;
    float score;
    cin.ignore(1);
    while (!input.eof())
    {
        system("cls"); 
        getline(input, data);
        score +=DoExam(stoi(data));
    }
    system("cls"); 
    cout<<"Your Score: "<<score<<endl;
    system("pause");
}

#pragma endregion Class_Student