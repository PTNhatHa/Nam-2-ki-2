#include <iostream>
#include <string>
#include <conio.h>
#include "List.h"
#include <exception>
using namespace std;


int main()
{
    List manage;
    int choice;
    int optionSortType = 0; 
    char x;
    menustart:
    system("cls");
    cout << "\t\t\t\t              QUAN LY PHONG KHACH SAN              " << endl;
    cout << "\t\t\t\t---------------------------------------------------" << endl;
    cout << "\t\t\t\t 1. Them phong moi vao danh sach" << endl;
    cout << "\t\t\t\t 2. Hien thi danh sach phong" << endl;
    cout << "\t\t\t\t 3. Cap nhat thong tin phong" << endl;
    cout << "\t\t\t\t 4. Xoa phong trong danh sach" << endl;
    cout << "\t\t\t\t 5. Tim kiem phong trong danh sach da sap xep" << endl;
    //cout << "\t\t\t\t 6. Sap xep danh sach phong theo ma phong" << endl;
    cout << "\t\t\t\t 7. Ket thuc chuong trinh" << endl;
    cout << "\t\t\t\t---------------------------------------------------" << endl;
    cout << "\t\t\t\t    Lua chon cong viec: ";
    cin >> choice;    
    switch (choice)
    {
        case 1:
        {
            char c;
            do
            {
                int optionTypeRoom;
                PhongKS *room;
                while (true)
                {
                    try 
                    {
                        system("cls");
                        cout << "\t\t\t\t            THEM PHONG MOI VAO DANH SACH            " << endl;
                        cout << "\t\t\t\t----------------------------------------------------" << endl;
                        cout << "\t\t\t\t 1. Them phong thuong" << endl;
                        cout << "\t\t\t\t 2. Them phong VIP" << endl;
                        cout << "\t\t\t\t---------------------------------------------------" << endl;
                        cout << "\t\t\t\t    Chon loai phong: ";  
                        cin >> optionTypeRoom;  
                        if (optionTypeRoom != 1 & optionTypeRoom != 2) 
                            throw string("Lua chon khong hop le. Vui long chon lai!");
                        break;
                    }
                    catch (string s)
                    {
                        cout << s << endl;
                        getch();
                    }
                }
                while (true)
                {
                    cout << "\nNhap thong tin phong moi can them vao danh sach:" << endl;
                    if (optionTypeRoom == 1)
                    {
                        room = new PhongBT;
                        cin >> *room;
                        room->setName("Phong thuong");
                    }
                    else 
                    {
                        room = new PhongVIP;
                        cin >> *room;
                        room->setName("Phong VIP");                   
                    }
                    try 
                    {
                        if (manage.findById(room->getIdRoom()) != -1) 
                            throw string("Ma phong da ton tai trong danh sach. Vui long nhap lai!");
                        cout << endl;
                        cout << "\t\t\t\t----------------------------------------------------" << endl;
                        cout << "\t\t\t\t Chon vi tri ban muon them\n";
                        cout << "\t\t\t\t 1. Them phong moi vao dau danh sach" << endl;
                        cout << "\t\t\t\t 2. Them phong moi vao cuoi danh sach" << endl;
                        cout << "\t\t\t\t 3. Them phong moi vao vi tri bat ky trong danh sach" << endl;
                        cout << "\t\t\t\t---------------------------------------------------" << endl;
                        cout << "\t\t\t\t    Chon vi tri can them [1/2/3]: ";
                        int optionPos; 
                        while (true)
                        {
                            try 
                            {
                                cout << "\tNhap lua chon: ";      
                                cin >> optionPos;
                                if (optionPos == 1)
                                {
                                    manage.addFront(*room);
                                    cout << "\nThem thanh cong!!!\n";
                                    goto continueOption;
                                }
                                else if (optionPos == 2)
                                {
                                    manage.addBack(*room);
                                    cout << "\nThem thanh cong!!!\n";
                                    goto continueOption;
                                }
                                else if (optionPos == 3)
                                {
                                    int pos;
                                    while (true)
                                    {
                                        cout << "\nChu y cac vi tri:\n";
                                        cout << "***** 0: them vao dau danh sach\n";
                                        cout << "***** >= so phong hien tai: them vao cuoi danh sach\n\n";
                                        cout << "***** <0: nhap khong hop le\n\n";
                                        cout << "\tNhap vi tri: ";
                                        try 
                                        {
                                            cin >> pos;
                                            if (pos < 0)
                                            {
                                                throw string("Vi tri nhap khong hop le. Vui long nhap lai!");
                                            }
                                            break;
                                        }
                                        catch (string e)
                                        {
                                            cout << e << endl;
                                        }
                                    }
                                    if (pos >= manage.getLength())
                                    {
                                        manage.insert(*room, manage.getLength());
                                    }
                                    else 
                                    {
                                        manage.insert(*room, pos);
                                    }
                                    cout << "\nThem thanh cong!!!\n";
                                    goto continueOption;
                                }
                                else
                                {
                                    throw string("Lua chon khong hop le. Vui long chon lai.");
                                }
                            }
                            catch (string s)
                            {
                                cout << endl << s << endl;
                            }
                        }
                    }
                    catch (string s)
                    {
                        cout << endl << s << endl;
                    }

                }
                continueOption:
                cout << "\n\tBan co muon them phong moi khac vao danh sach khong (Y/N): ";
                cin >> c;    
            } while (c == 'Y' || c == 'y'); 
            break;
        }
        case 2: 
        {
            system("cls");
            cout << "\t\t\t\t                   DANH SACH PHONG              " << endl;
            cout << "\t\t\t\t----------------------------------------------------" << endl;
            cout << endl;
            manage.displayList();
            getch();
            break;
        }
        case 3:
        {
            system("cls");
            updateRoom:
            cout << "\t\t\t\t              CAP NHAT THONG TIN PHONG              " << endl;
            cout << "\t\t\t\t----------------------------------------------------" << endl;
            cout << endl;
            if (manage.getLength() == 0)
            {
                cout << "Khach san hien khong co phong nao ca." << endl;
            }
            else 
            {
                manage.displayList();
                cout << "\n**Cap nhat thong tin phong theo ma phong: \n";
                PhongKS *room;
                int optionTypeRoom;
                while (true)
                {
                    cout << "\nNhap thong tin phong can cap nhat:\n";
                    cout << "\nLoai phong (1-phong thuong; 2-phong VIP): ";
                    try {
                        cin >> optionTypeRoom;
                        if (optionTypeRoom == 1) 
                        {
                            room = new PhongBT;
                            cin >> *room;
                            room->setName("Phong thuong");
                            break;
                        }
                        else if (optionTypeRoom == 2) 
                        {
                            room = new PhongVIP;
                            cin >> *room;
                            room->setName("Phong VIP");
                            break;
                        }
                        else throw string("Lua chon khong hop le. Vui long chon lai!");
                    }
                    catch (string s)
                    {
                        cout << s << endl;
                    }
                }
                // cin >> *room;
                try 
                {
                    if (manage.findById(room->getIdRoom()) == -1)
                    {
                        throw string("Ma phong khong ton tai trong danh sach. Cap nhat that bai.");
                    }
                    manage.update(*room);
                    cout << "\nCap nhat thanh cong!" << endl;
                }
                catch (string s)
                {
                    cout << endl << s << endl;
                }          
            }
            getch();
            cout << endl << endl;
            cout << "Ban co muon tiep tuc cap nhat thong tin phong (Y/N): ";
            char c; 
            cin >> c;
            if (c == 'Y' || c == 'y') goto updateRoom;
            break;
        }
        case 4: 
        {
            system("cls");
            menuRemoveRoom:
            cout << "\t\t\t\t              XOA PHONG TRONG DANH SACH             " << endl;
            cout << "\t\t\t\t----------------------------------------------------" << endl;
            cout << endl;
            if (manage.getLength() == 0)
            {
                cout << "Khach san hien khong co phong nao ca." << endl;
                getch();
                break;
            }
            else 
            {
                manage.displayList();
                cout << "\tNhap phong can xoa (thu tu phong tu 1): ";
                int pos; cin >> pos;
                manage.removeAt(pos);   
                cout << endl << "Xoa phong thanh cong." << endl;
            }
            getch();
            cout << "Ban co muon tiep tuc xoa phong trong danh sach (Y/N): ";
            char c; 
            cin >> c;
            if (c == 'Y' || c == 'y') goto menuRemoveRoom;
            break;
        }
        case 5:
        {
            system("cls");
            cout << "\t\t\t\t             TIM KIEM PHONG THEO MA PHONG            " << endl;
            cout << "\t\t\t\t-----------------------------------------------------" << endl;

            if (manage.getLength() == 0)
            {
                cout << endl << "Khach san khong co phong nao ca." << endl;
            }            
            else 
            {
                if (optionSortType == 0 && manage.getLength() > 1)
                {
                    cout << endl << "Danh sach chua duoc sap xep theo ma phong. Khong the tim kiem!" << endl << endl;
                }
                else 
                {
                    cout << "\nNhap ma phong can tim kiem: ";
                    string id;
                    cin >> id;
                    cout << endl;
                    if (manage.findById(id) == -1)
                    {
                        cout << "Khong tim thay phong!" << endl;
                    }
                    else 
                    {
                        cout << "Da tim thay phong!" << endl << endl;
                        cout << "Thong tin phong ban dang tim kiem: " << endl;
                        cout << manage[manage.findById(id)];
                    }
                }
            }
            getch();
            break;
        }
        case 7: 
        {
            cout << "\nChuong trinh ket thuc!!!\n\n";
            exit(0);
        }
        default:
        {
            cout << "\n\tLua chon khong hop le. Vui long chon lai!";
            getch();
            break;
        }
    }
    goto menustart;
    return 0;
}