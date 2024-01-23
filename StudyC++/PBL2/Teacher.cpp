// #include <iostream>
// #include <string.h>
// #include <fstream>
// #include <sstream>
// #include "PBL.cpp"
// using namespace std;
// #pragma endregion Class_User
// #pragma region Class_Teacher
// class Teacher : private User, private Exam
// {
// private:
//     int n_tc;
//     string Name;
//     string Subject;
// public:
//     Teacher();
//     ~Teacher();
//     bool Login(int, string);
//     void RamdomExam();
//     void CustomExam();
//     void Insert();
//     void Delete();
//     void Search();   
//     void MainProgram();
// };

// Teacher::Teacher()
// {
//     int tempID;
//     string tempPass;
//     do
//     {
//         cout<<"ID: ";
//         cin>>tempID;
//         cout<<"Password: ";
//         cin>>tempPass;
//     } while (!Login(tempID,tempPass));

//     ifstream input;
//     input.open("Teacher_Data.txt", ios::in);
//     string data;
//     getline(input, data);
//     n_tc = stoi(data);
//     int check = 0;

//     while (!input.eof())
//     {
//         getline(input, data);
//         if(data == to_string(Login_ID)){
//             getline(input, data);
//             Name = data;
//             getline(input, data);
//             Subject = data;
//             break;
//         }
//     }
    
//     system("pause");
//     system("cls"); 
//     MainProgram();
// }

// Teacher::~Teacher()
// {
// }
// bool Teacher::Login(int lgID, string lgPass){
//     for(int i = 0; i<NumberOfUser; i++){
//         if(lgID == ID[i] && lgPass == Password[i] && lgID / 1000 == 2){
//             cout<<"Login SUCCESSFULLY !!"<<endl;
//             Login_ID = lgID;
//             return true;
//         }
//     }
//     system("cls"); 
//     return false;
// }
// void Teacher::MainProgram(){
//     int c;
//     do
//     {
//         system("cls"); 
//         cout<<"Welcome Teacher : "<<Name<<" ..!"<<endl;
//         cout<<"Command List "<<endl;
//         cout<<"0. Log out "<<endl;
//         cout<<"1. Random Exam Build "<<endl;
//         cout<<"2. Custom Exam Build "<<endl;
//         cout<<"3. Insert more Question to System "<<endl;
//         cout<<"4. Delete Question from System "<<endl;
//         cout<<"5. Find Question "<<endl;
//         cout<<"Enter your Action: ";
//         cin>>c;
//         system("cls");
//         switch (c)
//         {
//         case 0:

//             break;
//         case 1:
//             RamdomExam();
//             break;
//         case 2:
//             CustomExam();
//             break;
//         case 3:
//             Insert();
//             break;
//         case 4:
//             Delete();
//             break;
//         case 5:
//             Search();
//             break;
//         }

//     } while (c!=0);
    
// }
// void Teacher::RamdomExam(){
//     cout<<"Random Exam..";
//     ShowAllQuestion();
//     system("pause");
// }
// void Teacher::CustomExam(){
//     cout<<"Custom Exam System......"<<endl;
//     cout<<"00. Show Science Questions."<<endl;
//     cout<<"01. Show Maths Questions."<<endl;
//     cout<<"02. Show All Questions."<<endl;
//     cout<<"Enter your Action: ";
//     string SubID;
//     do
//     {
//         cin>>SubID;
//     } while (SubID!="00" && SubID!="01" && SubID!="02");
//     if(SubID == "00"){
//         cout<<"Science Question: "<<endl;
//         ShowQuestion(SubID);
//     } 
//     if(SubID == "01"){
//         cout<<"Maths Question: "<<endl;
//         ShowQuestion(SubID);
//     }  
//     if(SubID == "02"){
//         cout<<"All Question: "<<endl;
//         ShowAllQuestion();
//     }    
//     int lastID = 0;
//     fstream listTest_Input;
//     listTest_Input.open("ListTest.txt",ios::in);
//     while(!listTest_Input.eof()){
//         listTest_Input>>lastID;
//     }
//     listTest_Input.close();
//     string dir;
//     if(lastID == 0){
//         dir = "TestDetail/" + to_string(++lastID) + SubID +".txt";
//     } else {
//         dir = "TestDetail/" + to_string(lastID/100 + 1) + SubID +".txt";
//     }
    
//     int id;
//     cout<<"Enter ID of Question which you want to ADD (enter 0 to exit and save): ";
//     ofstream output(dir);
//     bool checking = false;
//     do{
//         cin>>id;
//         for(int i = 0; i< n; i++){
//             if(id == GetID(i)){
//                 checking = true;
//                 break;
//             }
//         }
//         if(checking){
//             output<<id;
//             output<<"\n";
//         } else {
//             if(id != 0) cout<<"Invalid ID"<<endl;
//         }
//         checking = false;
//     } while (id != 0);
//     listTest_Input.open("ListTest.txt",ios::app);
//     int n =stoi(to_string(lastID/100 + 1) + SubID);
//     listTest_Input<<n;
//     listTest_Input<<"\n";
//     listTest_Input.close();
//     output.close();
// }
// void Teacher::Insert(){
//     cout<<"Insert Exam..";
// }
// void Teacher::Delete(){
//     cout<<"Delete Exam..";
// }
// void Teacher::Search(){
//     cout<<"Search Exam..";
// }