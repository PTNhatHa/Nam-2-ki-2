#include <iostream>
#include <string>
#include "List.cpp"
using namespace std;

int main()
{
    int cv;
    list l1(5);
    phongks p1;
    int vt;
    do
    {
        cout<<"\n----------MENU----------\n";
        cout<<"1. Nhap danh sach doi tuong\n";
        cout<<"2. Hien thi danh sach doi tuong\n";
        cout<<"3. Them doi tuong vao danh sach\n";
        cout<<"4. Cap nhat doi tuong\n";
        cout<<"5. Xoa doi tuong khoi danh sach\n";
        cout<<"6. Tim kiem doi tuong\n";
        cout<<"7. Sap xep danh sach\n";
        cout<<"8. Ket thuc\n";
        cout<<"Chon cong viec ban muon lam: ";
        cin>>cv;
        switch (cv)
        {
        case 1:
            cout<<"Nhap danh sach phong:\n";
            cin>>l1;
            cout<<l1;
            break;
        case 2:
            cout<<"Danh sach phong da nhap:\n";
            cout<<l1;
            break;
        case 3:
            //Thêm đối tượng vào danh sách
            cout<<"\nTHEM DOI TUONG VAO DANH SACH\n";
            cout<<"\nNhap dt muon them p1: \n";
            cin>>p1;
            cout<<"\nThem doi tuong p1 vao dau ds:";
            l1.addf(p1);
            cout<<"\nDs sau khi them: \n";
            cout<<l1;

            cout<<"\nThem doi tuong p1 vao cuoi ds:";
            l1.addl(p1);
            cout<<"\nDs sau khi them: \n";
            cout<<l1;

            cout<<"\nThem doi tuong p1 vao vi tri thu 2:"; //vị trí bắt dầu từ 0
            l1.add(1,p1);
            cout<<"\nDs sau khi them: \n";
            cout<<l1;
            break;
        case 4:
            //Cập nhật thông tin đối tượng
            cout<<"\nCAP NHAT THONG TIN DOI TUONG\n";
            cout<<"\nCap nhat so nguoi toi da cua phan tu dau tien: ";
            l1.update_sn(0);
            cout<<l1;

            cout<<"\nCap nhat tinh trang cua pt dau tien:";
            l1.update_tt(0);
            cout<<l1;

            cout<<"\nCap nhat gia cua phan tu thu 2: ";
            l1.update_gia(1);
            cout<<l1;
            break;
        case 5:
            //Xóa đối tượng
            cout<<"\nXOA DOI TUONG\n";
            cout<<"\nXoa dt tai vi tri dau tien:";
            l1.delf();
            cout<<l1;

            cout<<"\nXoa dt tai vi tri cuoi cung:";
            l1.dell();
            cout<<l1;

            cout<<"\nXoa dt tai vi tri thu 2:";
            l1.del(1);
            cout<<l1;
            break;
        case 6:
            cout<<"\nTIM KIEM THEO GIA PHONG\n";
            cout<<"Tim thu tu phong co gia 200:";
            vt=l1.interpolation_search(200);
            if(vt!=-1)
                {
                    cout<<"\nPhong co gia 200 la: \n"<<l1[vt]<<endl;
                }
            else
                {
                    cout<<"\nKhong ton tai\n";
                }
            break;
        case 7:
            cout<<"\nSAP XEP DANH SACH THEO THU TU TANG DAN GIA PHONG\n";
            l1.shell_sort(ascending);
            cout<<l1;
            break;
        }
    } while (cv!=8);

    return 0;
}