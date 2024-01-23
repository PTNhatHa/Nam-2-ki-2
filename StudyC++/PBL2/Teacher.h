#include "User.h"

#pragma region Class_Teacher
class Teacher : private User
{
private:
    int n_tc;
    string Name;
    string Subject;
public:
    Teacher();
    ~Teacher();
    bool Login(int, string);
    void MainProgram();
    void RandomExam();
    void CustomExam();
    void ShowExam();
    void Insert();
    void Delete();  
};

Teacher::Teacher()
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
    input.open("Teacher_Data.txt", ios::in);
    string data;
    getline(input, data);
    n_tc = stoi(data);
    int check = 0;

    while (!input.eof())
    {
        getline(input, data);
        if(data == to_string(Login_ID)){
            getline(input, data);
            Name = data;
            getline(input, data);
            Subject = data;
            break;
        }
    }
    
    system("pause");
    system("cls"); 
    MainProgram();
}

Teacher::~Teacher()
{
}
bool Teacher::Login(int lgID, string lgPass){
    for(int i = 0; i<NumberOfUser; i++){
        if(lgID == ID[i] && lgPass == Password[i] && lgID / 1000 == 2){
            cout<<"Login SUCCESSFULLY !!"<<endl;
            Login_ID = lgID;
            return true;
        }
    }
    system("cls"); 
    return false;
}
void Teacher::MainProgram(){
    int c;
    string SubID;
    do
    {
        system("cls"); 
        cout<<"===========================================\n";
        cout<<"|                                         |\n";
        cout<<"|                 TEACHER                 |\n";
        cout<<"|                                         |\n";
        cout<<"===========================================\n\n";
        cout<<"Welcome Teacher : "<<Name<<" ..!"<<endl;

        cout<<"_______________Command List_______________"<<endl;
        cout<<"0. Log out "<<endl;
        cout<<"1. Random Exam Build "<<endl;
        cout<<"2. Custom Exam Build "<<endl;
        cout<<"3. Insert more Question to System "<<endl;
        cout<<"4. Delete Exam "<<endl;
        cout<<"5. Find Question "<<endl;
        cout<<"6. Show Questions"<<endl;
        cout << "7. Show Exam " << endl;
        cout<<"__________________________________________"<<endl;
        cout<<"Enter your Action: ";
        cin>>c;
        system("cls");
        switch (c)
        {
            case 0:

                break;
            case 1:
                RandomExam();
                break;
            case 2:
                CustomExam();
                break;
            case 3:
                Insert();
                break;
            case 4:
                Delete();
                break;
            case 5:
                Search();
                break;
            case 6:
                cout<<"00. Show Science Questions."<<endl;
                cout<<"01. Show Maths Questions."<<endl;
                cout<<"02. Show All Questions."<<endl;
                cout<<"Enter your Action: ";
                do
                {
                    cin>>SubID;
                } while (SubID!="00" && SubID!="01" && SubID!="02");

                if(SubID == "00"){
                    cout<<"Science Question: "<<endl;
                    ShowQuestion(SubID);
                } 
                if(SubID == "01"){
                    cout<<"Maths Question: "<<endl;
                    ShowQuestion(SubID);
                }  
                if(SubID == "02"){
                    cout<<"All Question: "<<endl;
                    ShowAllQuestion();
                }    
                system("pause");
                break;
            case 7:
                ShowExam();
                break;
        }

    } while (c!=0);
    
}
void Teacher::RandomExam(){
    cout<<"Random Exam System....."<<endl;
    cout<<"00. Science Test."<<endl;
    cout<<"01. Maths Test."<<endl;
    cout<<"02. Random Test."<<endl;
    cout<<"Enter your Action: ";
    string SubID;
    do
    {
        cin>>SubID;
    } while (SubID!="00" && SubID!="01" && SubID!="02");
    int count_lv1 = 0;
    int count_lv2 = 0;
    int count_lv3 = 0;
    string temp;
    if(SubID == "00"){
        for(int i = 0; i<n; i++){
            temp.push_back(to_string(GetID(i)).at(1));
            temp.push_back(to_string(GetID(i)).at(2));
            if(temp == "00"){
                if(to_string(GetID(i)).at(0) == '1') ++count_lv1;
                if(to_string(GetID(i)).at(0) == '2') ++count_lv2;
                if(to_string(GetID(i)).at(0) == '3') ++count_lv3;
            }
            temp.clear();
        }
    } 
    if(SubID == "01"){
        for(int i = 0; i<n; i++){
            temp.push_back(to_string(GetID(i)).at(1));
            temp.push_back(to_string(GetID(i)).at(2));
            if(temp == "01"){
                if(to_string(GetID(i)).at(0) == '1') ++count_lv1;
                if(to_string(GetID(i)).at(0) == '2') ++count_lv2;
                if(to_string(GetID(i)).at(0) == '3') ++count_lv3;
            }
            temp.clear();
        }
    } 
    if(SubID == "02"){
        for(int i = 0; i<n; i++){
            if(to_string(GetID(i)).at(0) == '1') ++count_lv1;
            if(to_string(GetID(i)).at(0) == '2') ++count_lv2;
            if(to_string(GetID(i)).at(0) == '3') ++count_lv3;
        }
    }
    if(SubID == "00" ||SubID == "01"){
        int lastID = 0;
        fstream listTest_Input;
        listTest_Input.open("ListTest.txt",ios::in);
        while(!listTest_Input.eof()){
            listTest_Input>>lastID;
        }
        listTest_Input.close();
        string dir;
        if(lastID == 0){
            dir = "TestDetail/" + to_string(++lastID) + SubID +".txt";
        } else {
            dir = "TestDetail/" + to_string(lastID/100 + 1) + SubID +".txt";
        }
        ofstream output(dir);
        string id;
        int rad;
        //add lv1
        rad = rand()%(count_lv1+1) + 1;
        id = "1"+ SubID;
        if(rad < 10){
            id += "0";
            id += to_string(rad);
        } else {
            id +=to_string(rad) ;
        }
        output<<id;
        output<<"\n";
        id.clear();
        //add lv2
        rad = rand()%(count_lv2+1) + 1;
        id = "2"+ SubID;
        if(rad < 10){
            id += "0";
            id += to_string(rad);
        } else {
            id +=to_string(rad) ;
        }
        output<<id;
        output<<"\n";
        id.clear();
        //add lv3
        rad = rand()%(count_lv3+1) + 1;
        id = "3"+ SubID;
        if(rad < 10){
            id += "0";
            id += to_string(rad);
        } else {
            id +=to_string(rad) ;
        }
        output<<id;
        output<<"\n";
        id.clear();
        listTest_Input.open("ListTest.txt",ios::app);
        int n =stoi(to_string(lastID/100 + 1) + SubID);
        listTest_Input<<n;
        listTest_Input<<"\n";
        listTest_Input.close();
        output.close();
    } else {
        int lastID = 0;
        fstream listTest_Input;
        listTest_Input.open("ListTest.txt",ios::in);
        while(!listTest_Input.eof()){
            listTest_Input>>lastID;
        }
        listTest_Input.close();
        string dir;
        if(lastID == 0){
            dir = "TestDetail/" + to_string(++lastID) + SubID +".txt";
        } else {
            dir = "TestDetail/" + to_string(lastID/100 + 1) + SubID +".txt";
        }
        ofstream output(dir);
        string id;
        int rad;
        //add lv1
        rad = rand()%(11) + 1;
        id = "10"+ to_string(rand()%2);
        if(rad < 10){
            id += "0";
            id += to_string(rad);
        } else {
            id +=to_string(rad) ;
        }
        output<<id;
        output<<"\n";
        id.clear();
        //add lv2
        rad = rand()%(11) + 1;
        id = "20"+ to_string(rand()%2);
        if(rad < 10){
            id += "0";
            id += to_string(rad);
        } else {
            id +=to_string(rad) ;
        }
        output<<id;
        output<<"\n";
        id.clear();
        //add lv3
        rad = rand()%(11) + 1;
        id = "30"+ to_string(rand()%2);
        if(rad < 10){
            id += "0";
            id += to_string(rad);
        } else {
            id +=to_string(rad) ;
        }
        output<<id;
        output<<"\n";
        id.clear();
        listTest_Input.open("ListTest.txt",ios::app);
        int n =stoi(to_string(lastID/100 + 1) + SubID);
        listTest_Input<<n;
        listTest_Input<<"\n";
        listTest_Input.close();
        output.close();
    }
    
    system("pause");

}
void Teacher::CustomExam(){
    cout<<"Custom Exam System......"<<endl;
    cout<<"00. Show Science Questions."<<endl;
    cout<<"01. Show Maths Questions."<<endl;
    cout<<"02. Show All Questions."<<endl;
    cout<<"Enter your Action: ";
    string SubID;
    do
    {
        cin>>SubID;
    } while (SubID!="00" && SubID!="01" && SubID!="02");
    if(SubID == "00"){
        cout<<"Science Question: "<<endl;
        ShowQuestion(SubID);
    } 
    if(SubID == "01"){
        cout<<"Maths Question: "<<endl;
        ShowQuestion(SubID);
    }  
    if(SubID == "02"){
        cout<<"All Question: "<<endl;
        ShowAllQuestion();
    }    
    int lastID = 0;
    fstream listTest_Input;
    listTest_Input.open("ListTest.txt",ios::in);
    while(!listTest_Input.eof()){
        listTest_Input>>lastID;
    }
    listTest_Input.close();
    string dir;
    if(lastID == 0){
        dir = "TestDetail/" + to_string(++lastID) + SubID +".txt";
    } else {
        dir = "TestDetail/" + to_string(lastID/100 + 1) + SubID +".txt";
    }
    
    int id;
    cout<<"Enter ID of Question which you want to ADD (enter 0 to exit and save): ";
    ofstream output(dir);
    bool checking = false;
    do{
        cin>>id;
        for(int i = 0; i< n; i++){
            if(id == GetID(i)){
                checking = true;
                break;
            }
        }
        if(checking){
            output<<id;
            output<<"\n";
        } else {
            if(id != 0) cout<<"Invalid ID"<<endl;
        }
        checking = false;
    } while (id != 0);
    listTest_Input.open("ListTest.txt",ios::app);
    int n =stoi(to_string(lastID/100 + 1) + SubID);
    listTest_Input<<n;
    listTest_Input<<"\n";
    listTest_Input.close();
    output.close();
}

void Teacher::ShowExam()
{    
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

void Teacher::Insert(){
    cout<<"Insert Question.....";
    Question newQuestion;
    int subID;
// Subject ID: 
// 0 : Science
// 1 : Maths
    cout<<"Subject ID: "<<endl;
    cout<<"0 : Science: "<<endl;
    cout<<"1 : Maths: "<<endl;
    cout<<"Enter ID: ";
    cin>>subID;
    cout<<"Enter Difficult (1 - 2 - 3): ";
    cin>>newQuestion.Hardly;
    cin.ignore(1);
    cout<<"Enter Question: ";
    getline(cin, newQuestion.Question);
    cout<<"0 : False"<<endl;
    cout<<"1 : True "<<endl;
    cout<<"Enter Answer 1: ";
    getline(cin, newQuestion.Ans_1);
    cout<<"True/False: "<<endl;
    cin>>newQuestion.CorrectAns[1];
    cin.ignore(1);
    cout<<"Enter Answer 2: ";
    getline(cin, newQuestion.Ans_2);
    cout<<"True/False: "<<endl;
    cin>>newQuestion.CorrectAns[2];
    cin.ignore(1);
    cout<<"Enter Answer 3: ";
    getline(cin, newQuestion.Ans_3);
    cout<<"True/False: "<<endl;
    cin>>newQuestion.CorrectAns[3];
    cin.ignore(1);
    cout<<"Enter Answer 4: ";
    getline(cin, newQuestion.Ans_4);
    cout<<"True/False: "<<endl;
    cin>>newQuestion.CorrectAns[4];
    int lastID = 0;
    int sID;
    for(int i = 0; i< n; i++){
        if(GetID(i)/10000 == newQuestion.Hardly){
             sID = (GetID(i)/100)%10;
             cout<<GetID(i);
             cout<<"+"<<sID<<"+"<<endl;
            if(sID == subID){
                lastID++;
            }
        }
    }
    cout<<lastID<<endl;
    string temp;
    if(lastID <9){
        temp = "0" + to_string(lastID +1);
    } else {
        temp = to_string(lastID +1);
    }
    newQuestion.ID_Q = stoi(to_string(newQuestion.Hardly)+ "0"+to_string(subID) + temp);
    cout<<"------------------------------------------"<<endl;
    cout<<"Your Question: ";
    cout<<"ID: "<<newQuestion.ID_Q<<endl;
    cout<<"Question: "<<newQuestion.Question<<endl;
    cout<<newQuestion.CorrectAns[1]<<" "<< newQuestion.Ans_1<<endl;
    cout<<newQuestion.CorrectAns[2]<<" "<< newQuestion.Ans_2<<endl;
    cout<<newQuestion.CorrectAns[3]<<" "<< newQuestion.Ans_3<<endl;
    cout<<newQuestion.CorrectAns[4]<<" "<< newQuestion.Ans_4<<endl;
    cout<<"------------------------------------------"<<endl;
    int cd;
    cout<<"1: Confirm and Save ..!"<<endl;
    cout<<"0: Exit ..!"<<endl;
    cout<<"Enter your Action: ";
    cin>>cd;
    if(cd == 1){
        bool added = false;
        fstream output;
        output.open("Questions.txt", ios::out);
        output<<++n;
        for(int i = 0; i< n-1; i++){
            output << "\n";
            output << GetQuestion(i).ID_Q ;
            output << "\n";
            output << GetQuestion(i).Question;
            output << "\n";
            output << GetQuestion(i).CorrectAns[1];
            output << "\n";
            output << GetQuestion(i).Ans_1;
            output << "\n";
            output << GetQuestion(i).CorrectAns[2];
            output << "\n";
            output <<GetQuestion(i).Ans_2;
            output << "\n";
            output << GetQuestion(i).CorrectAns[3];
            output << "\n";
            output <<GetQuestion(i).Ans_3;
            output << "\n";
            output << GetQuestion(i).CorrectAns[4];
            output << "\n";
            output << GetQuestion(i).Ans_4;
        }
        output << "\n";
        output << newQuestion.ID_Q ;
        output << "\n";
        output << "Câu hỏi: " <<newQuestion.Question;
        output << "\n";
        output << newQuestion.CorrectAns[1];
        output << "\n";
        output <<"A. "<< newQuestion.Ans_1;
        output << "\n";
        output << newQuestion.CorrectAns[2];
        output << "\n";
        output <<"B. "<<  newQuestion.Ans_2;
        output << "\n";
        output << newQuestion.CorrectAns[3];
        output << "\n";
        output <<"C. "<<  newQuestion.Ans_3;
        output << "\n";
        output << newQuestion.CorrectAns[4];
        output << "\n";
        output <<"D. "<<  newQuestion.Ans_4;
        //change n 
        output.close();
        ReadAllExamData();
        
    }
    system("pause");
}
void Teacher::Delete(){
    cout<<"Delete Exam......"<<endl;
    vector<int> list;
    int data;
    fstream listTest_Input;
    listTest_Input.open("ListTest.txt");
    while(!listTest_Input.eof()){
        listTest_Input>>data;
        list.push_back(data);
    }
    listTest_Input.close();
    cout<<"List Exam: "<<endl;
    for(int i = 0; i< list.size(); i++){
        cout<<list[i]<<endl;
    }
    cout<<"Enter ID's Exam to Delete: ";
    int id;
    cin >>id;
    bool check = false;
    while (!check)
    {
       for(int i = 0; i< list.size(); i++){
            if(id == list[i]){
                check = true;
                list.erase(list.begin() + i);
                listTest_Input.open("ListTest.txt", ios::out);
                for(int j = 0; j <list.size(); j++){
                    listTest_Input<<"\n";
                    listTest_Input<<list[j];
                }
                listTest_Input.close();
                cout<<"Delete Successfully..!"<<endl;
                break;
                
            }
       }
       if(check){
            break;
       } else {
            cout<<"Fail..!! Enter ID's Exam to Delete: ";
            cin>>id; 
       }
    }
    system("pause");

}

#pragma endregion Class_Teacher