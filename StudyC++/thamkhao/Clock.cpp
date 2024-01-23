#include<Windows.h>
#include<iostream>
using namespace std;

void demnguoc(int gio, int phut, int giay)
{
    int kt;
    while (true)
    {
        kt=0;
        cout<<gio<<" : "<<phut<<" : "<<giay;
        if (giay==0 && phut!=0)
        {
            giay=59;
            phut--;
            kt=1;
        }
        if (giay==0 && phut==0 && gio!=0)
        {
            giay=59;
            phut=59;
            gio--;
            kt=1;
        }
        if (gio==0 && phut==0 && giay==0)
        {
           break;
        }
        if (kt==0)
        {
            giay--;
        }
        Sleep(1000); //1000 mili = 1s    
        system("cls");   
         
    }
    
}

// int main()
// {
//     cout<<"ĐỒNG HỒ ĐẾM NGƯỢC\n";
//     demnguoc(1,0,10);
//     return 0;
// }