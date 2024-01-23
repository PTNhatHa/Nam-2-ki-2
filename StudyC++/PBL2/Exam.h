#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <filesystem>
#include <vector>
#include<thread>
#include<Windows.h>
using namespace std;
#pragma region Class_Exam 

struct Question{
    int ID_Q;
    int Hardly;
    string Question;
    string Ans_1;
    string Ans_2;
    string Ans_3;
    string Ans_4;
    int CorrectAns[5];
};
// Subject ID: 
// 0 : Science
// 1 : Maths
class Exam
{
private:
    Question *DetailQuestion;
public:
    int n;
    Exam();
    ~Exam();
    void ReadAllExamData();
    void ShowAllQuestion();
    void ShowQuestion(string);
    bool CheckID(int id);
    int GetID(int);
    void Update();
    float DoExam(int);
    Question GetQuestion(int);
};
Exam::Exam()
{
    //readfile
    ReadAllExamData();
}

Exam::~Exam()
{

}
Question Exam::GetQuestion(int id){
    return this->DetailQuestion[id];
}
 //Xuất câu hỏi theo mã môn
void Exam::ShowQuestion(string _SubID){
    string temp;
    for(int i = 0; i<n; i++){
        temp.push_back(to_string(DetailQuestion[i].ID_Q).at(1));
        temp.push_back(to_string(DetailQuestion[i].ID_Q).at(2));
        if(temp == _SubID){
            cout<<"ID: "<<DetailQuestion[i].ID_Q<<endl;
            cout<<DetailQuestion[i].Question<<endl;
            if(DetailQuestion[i].CorrectAns[1] == 1){
                cout<<"Dung   ";
            } else {
                cout<<"       ";
            }
            cout<<DetailQuestion[i].Ans_1<<endl;
            if(DetailQuestion[i].CorrectAns[2] == 1){
                cout<<"Dung   ";
            } else {
                cout<<"       ";
            }
            cout<<DetailQuestion[i].Ans_2<<endl;
            if(DetailQuestion[i].CorrectAns[3] == 1){
                cout<<"Dung   ";
            } else {
                cout<<"       ";
            }
            cout<<DetailQuestion[i].Ans_3<<endl;
            if(DetailQuestion[i].CorrectAns[4] == 1){
                cout<<"Dung   ";
            } else {
                cout<<"       ";
            }
            cout<<DetailQuestion[i].Ans_4<<endl;
            cout<<"----------------------------------"<<endl;
        }
        temp.clear();
    }
}
void Exam::ReadAllExamData()
{
    cout<<"Read data...."<<endl;
    ifstream input;
    input.open("Questions.txt");
    string data;
    getline(input, data);
    n  = stoi(data);
    DetailQuestion = new Question[n];
    int check = 0;
    int counting = 0;
    while (!input.eof())
    {
        getline(input, data);
        switch (check)
        {
        case 0:
            DetailQuestion[counting].ID_Q = stoi(data);
            check = 1;
            break;
        case 1:
            DetailQuestion[counting].Question = data;
            check = 2;
            break;
        case 2:
            DetailQuestion[counting].CorrectAns[1] = stoi(data);
            check = 3;
            break;
        case 3:
            DetailQuestion[counting].Ans_1 = data;
            check = 4;
            break;
        case 4:
            DetailQuestion[counting].CorrectAns[2] = stoi(data);
            check = 5;
            break;
        case 5:
            DetailQuestion[counting].Ans_2 = data;
            check = 6;
            break;
        case 6:
            DetailQuestion[counting].CorrectAns[3] = stoi(data);
            check = 7;
            break;
        case 7:
            DetailQuestion[counting].Ans_3 = data;
            check = 8;
            break;
        case 8:
            DetailQuestion[counting].CorrectAns[4] = stoi(data);
            check = 9;
            break;
        case 9:
            DetailQuestion[counting].Ans_4 = data;
            check = 0;
            counting++;
            break;
        default:
            cout<<"ERROR";
            break;
        }
    }
    input.close();
}
void Exam::ShowAllQuestion(){
    for(int i = 0 ; i<n; i++){
        cout<<"ID: "<<DetailQuestion[i].ID_Q<<endl;
        cout<<DetailQuestion[i].Question<<endl;
        if(DetailQuestion[i].CorrectAns[1] == 1){
            cout<<"Dung   ";
        } else {
            cout<<"       ";
        }
        cout<<DetailQuestion[i].Ans_1<<endl;
        if(DetailQuestion[i].CorrectAns[2] == 1){
            cout<<"Dung   ";
        } else {
            cout<<"       ";
        }
        cout<<DetailQuestion[i].Ans_2<<endl;
        if(DetailQuestion[i].CorrectAns[3] == 1){
            cout<<"Dung   ";
        } else {
            cout<<"       ";
        }
        cout<<DetailQuestion[i].Ans_3<<endl;
        if(DetailQuestion[i].CorrectAns[4] == 1){
            cout<<"Dung   ";
        } else {
            cout<<"       ";
        }
        cout<<DetailQuestion[i].Ans_4<<endl;
        cout<<"----------------------------------"<<endl;
    }
}
//Xuất 1 câu hỏi theo ID
bool Exam::CheckID(int id)
{
    cout << id << endl;
    for (int i = 0; i < n; i++)
    {
        if(DetailQuestion[i].ID_Q==id)
        {
            cout << "ID: " << DetailQuestion[i].ID_Q << endl;
            cout << DetailQuestion[i].Question << endl;
            if (DetailQuestion[i].CorrectAns[1] == 1)
            {
                cout << "Dung   ";
            }
            else
            {
                cout << "       ";
            }
            cout << DetailQuestion[i].Ans_1 << endl;
            if (DetailQuestion[i].CorrectAns[2] == 1)
            {
                cout << "Dung   ";
            }
            else
            {
                cout << "       ";
            }
            cout << DetailQuestion[i].Ans_2 << endl;
            if (DetailQuestion[i].CorrectAns[3] == 1)
            {
                cout << "Dung   ";
            }
            else
            {
                cout << "       ";
            }
            cout << DetailQuestion[i].Ans_3 << endl;
            if (DetailQuestion[i].CorrectAns[4] == 1)
            {
                cout << "Dung   ";
            }
            else
            {
                cout << "       ";
            }
            cout << DetailQuestion[i].Ans_4 << endl;
            cout << "----------------------------------" << endl;
            return true;
        }
    }
    return false;
}

int Exam::GetID(int index){
    return this->DetailQuestion[index].ID_Q;
}
float Exam::DoExam(int id){
    float score;
    for(int i = 0; i< n; i++){
        if(DetailQuestion[i].ID_Q == id){
            cout<<DetailQuestion[i].Question<<endl;
            cout<<DetailQuestion[i].Ans_1<<endl;
            cout<<DetailQuestion[i].Ans_2<<endl;
            cout<<DetailQuestion[i].Ans_3<<endl;
            cout<<DetailQuestion[i].Ans_4<<endl;
            
            cout<<"----------------------"<<endl;
            cout<<"Your Answer: "<<endl;
            string ans;
            int intAns[5] = {0, 0, 0, 0, 0};
            getline(cin, ans);
            for(int i = 0; i<ans.length(); i++){
                if(ans[i] != ' '){
                    switch (ans[i])
                    {
                    case 'A':
                        intAns[1] = 1;
                        break;
                    case 'B':
                        intAns[2] = 1;
                        break;
                    case 'C':
                        intAns[3] = 1;
                        break;
                    case 'D':
                        intAns[4] = 1;
                        break;
                    }
                }
            }
            int c = 0;
            for(int j = 1; j<5 ; j++){
                if(DetailQuestion[i].CorrectAns[j] == 1){
                    ++c;
                }
            }
            float scorePerAns = 10 / (float)c;
            for(int j = 1; j<5 ; j++){
                if(DetailQuestion[i].CorrectAns[j] == intAns[j]){
                    if(intAns[j] == 1){
                        score += scorePerAns;
                    }
                } else {
                    score -= scorePerAns;
                }
            }
            if(score<0) score = 0;
            break;
        }
    }
    return score;
}
#pragma endregion Class_Exam