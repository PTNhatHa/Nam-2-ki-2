#include <iostream>
#include <string>
#include "QuanLi.cpp"
using namespace std;

int main()
{
    cout<<"helo\n";
    int cv;

    Node<PhongBT> *bt;
    Node<PhongVIP> *vip;
    QuanLi<PhongBT> ds_bt;
    QuanLi<PhongVIP> ds_vip;
    string pl, mp;
    int vt;
    do
    {
        cout<<"\n----------MENU----------\n";
        cout<<"1. Nhap danh sach doi tuong\n";
        cout<<"2. Hien thi danh sach doi tuong\n";
        cout<<"3. Them doi tuong vao dau danh sach\n";
        cout<<"4. Cap nhat doi tuong\n";
        cout<<"5. Xoa doi tuong dau tien khoi danh sach\n";
        cout<<"6. Hien thi thong tin doi tuong dau tien trong danh sach\n";
        cout<<"7. Tim kiem doi tuong\n";
        cout<<"8. Sap xep danh sach\n";
        cout<<"9. Ket thuc\n";
        cout<<"Chon cong viec ban muon lam: ";
        cin>>cv;
        switch (cv)
        {
        case 1: //1. Nhap danh sach doi tuong
            cout<<"\nChon loai phong ban muon nhap (BT/VIP): ";
            cin>>pl;
            if (pl=="BT"||pl=="bt")
            {
                cin>>ds_bt;
            }
            if (pl=="VIP"||pl=="vip")
            {
                cin>>ds_vip;
            }
            break;

        case 2: //2. Hien thi danh sach doi tuong
            cout<<"\nChon loai phong ban muon xem (BT/VIP): ";
            cin>>pl;
            if (pl=="BT"||pl=="bt")
            {
                cout<<ds_bt;
            }
            if (pl=="VIP"||pl=="vip")
            {
                cout<<ds_vip;
            }
            break;

        case 3: //3. Them doi tuong vao dau danh sach
            cout<<"\nTHEM DOI TUONG VAO DAU DANH SACH\n";
            cout<<"\nChon loai phong ban muon them (BT/VIP): ";
            cin>>pl;
            if (pl=="BT"||pl=="bt")
            {
                cin>>*bt;
                ds_bt.push(bt);
            }
            if (pl=="VIP"||pl=="vip")
            {
                cin>>*vip;
                ds_vip.push(vip);
            }
            break;

        case 4: //4. Cap nhat doi tuong
            cout<<"\nCAP NHAT THONG TIN DOI TUONG\n";
            cout<<"\nChon loai phong ban muon cap nhat thong tin (BT/VIP): ";
            cin>>pl;
            if (pl=="BT"||pl=="bt")
            {
                cout<<ds_bt<<endl;
                cout<<"Chon ma phong ban muon cap nhat: ";
                cin>>mp;
                ds_bt.update_sn(mp);
                ds_bt.update_tt(mp);
            }
            if (pl=="VIP"||pl=="vip")
            {
                cout<<ds_vip<<endl;
                cout<<"Chon ma phong ban muon cap nhat: ";
                cin>>mp;
                ds_vip.update_sn(mp);
                ds_vip.update_tt(mp);
            }
            break;

        case 5: //5. Xoa doi tuong dau tien khoi danh sach
            cout<<"\nXOA DOI TUONG DAU TIEN TRONG DANH SACH\n";
            cout<<"\nChon loai phong ban muon xoa (BT/VIP): ";
            cin>>pl;
            if (pl=="BT"||pl=="bt")
            {
                ds_bt.pop();
            }
            if (pl=="VIP"||pl=="vip")
            {
                ds_vip.pop();
            }
            break;

        case 6: //6. Hien thi thong tin doi tuong dau tien trong danh sach
            cout<<"\nTHONG TIN DOI TUONG DAU TIEN TRONG DANH SACH\n";
            cout<<"\nChon loai phong ban muon xem (BT/VIP): ";
            cin>>pl;
            if (pl=="BT"||pl=="bt")
            {
                ds_bt.top();
            }
            if (pl=="VIP"||pl=="vip")
            {
                ds_vip.top();
            }
            break;

        // case 7: //6. Tim kiem doi tuong
        //     cout<<"\nTIM KIEM THEO MA PHONG\n";
        //     cout<<"\nChon loai phong ban muon tim kiem (BT/VIP): ";
        //     cin>>pl;
        //     if (pl=="BT"||pl=="bt")
        //     {
        //         cout<<"Nhap ma phong ban muon tim kiem: ";
        //         cin>>mp;
        //         ds_bt.interpolation_search(mp);
        //     }
        //     if (pl=="VIP"||pl=="vip")
        //     {
        //         ds_vip.top();
        //     }

        //     cout<<"Tim thu tu phong co gia 200:";
        //     vt=l1.interpolation_search(200);
        //     if(vt!=-1)
        //         {
        //             cout<<"\nPhong co gia 200 la: \n"<<l1[vt]<<endl;
        //         }
        //     else
        //         {
        //             cout<<"\nKhong ton tai\n";
        //         }
        //     break;
        // case 8: //7. Sap xep danh sach
        //     cout<<"\nSAP XEP DANH SACH THEO THU TU TANG DAN GIA PHONG\n";
        //     l1.shell_sort(ascending);
        //     cout<<l1;
        //     break;
        }
    } while (cv!=9);

    return 0;
}