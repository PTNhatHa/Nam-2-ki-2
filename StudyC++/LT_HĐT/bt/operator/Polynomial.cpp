#include<iostream>
#include<math.h>
using namespace std;

class Poly //đa thức
{
    private:
        int n;
        float *data;
    public:
        Poly(int n=3);
        Poly(const float f[]);
        Poly(const Poly &f);
        ~Poly();

        Poly operator + (const Poly &f);
        Poly operator - (const Poly &f);
        float operator () (float x) const; //hàm hằng // tính giá trị đa thức, chỉ tính giá trị mà không thay đổi đa thức nên dùng const
        float &operator [] (int i) const; //hàm hằng: không làm thay đổi giá trị n và data mà chỉ thay đổi giá trị các ô nhớ data[i] // truy xuất 1 hệ số đa thức, ...//hàm phải là hàm hằng thì mới đc gọi đến các đối tượng hằng
        const Poly &operator = (const Poly &f); //hàm trả về giá trị tham chiếu hằng
        friend istream &operator >> (istream &in, Poly &f);
        friend ostream &operator << (ostream &out, const Poly &f); //nếu dùng tham trị thì sẽ cấp vùng nhớ mới(tốn bọ nhớ), gọi hàm dựng sao chép giá trị tham số thực vào đối tượng, kết thúc phải gọi thêm hàm hủy

};

Poly::Poly(int n)
{
    this->n=n;
    data = new float [n];
    for(int i=0;i<=n;i++)
        data[i]=1;
}

Poly::Poly(const float f[])
{
    this->n=sizeof f / sizeof (float);
    data = new float [n];
    for(int i=0;i<=n;i++)
        data[i]=f[i];
}

Poly::Poly(const Poly &f)
{
    this->n=f.n;
    data = new float [n];
    for(int i=0;i<=n;i++)
        data[i]=f[i];
}

Poly::~Poly()
{
    delete [] data;
}

Poly Poly::operator + (const Poly &f) //có thể là hàm thành viên hoặc hàm toàn cục
{
    Poly t(this->n>f.n?this->n:f.n); //2 đa thức khác bậc
    for(int i=0;i<=t.n;i++)
    {
        float a,b;
        a=i<=this->n?data[i]:0;
        b=i<=f.n?f[i]:0;
        t[i]=a+b; //t[i] là hàm hằng nhưng không làm thay đổi giá trị n và data mà chỉ thay đổi giá trị các ô nhớ data[i]
    }
    return t;
}

Poly Poly::operator - (const Poly &f)
{
    Poly h(this->n>f.n?this->n:f.n);
    for(int i=0;i<=h.n;i++)
    {
        float a,b;
        a=i<=this->n?data[i]:0;
        b=i<=f.n?f[i]:0;
        h[i]=a-b;
    }
    return h;
}

float Poly::operator () (float x) const
{
    float t=0;
    for(int i=0;i<=this->n;i++) // for(int i=n;i>=0;i--)
        t+=(*this)[i]*pow(x,i); //     t=t*x + data[i];
    return t;
}

float &Poly::operator [] (int i) const //giá trị trả về phải là 1 biến hoặc tham chiếu đến 1 biến(thay cho bí danh của data[i]), vì ko thể gán 1 giá trị cho 1 hàm khi gọi
{
    return data[i];
}

const Poly &Poly::operator = (const Poly &f)
{
    if (this!=&f) //để đảm bảo ko gán cho chính nó, this khác địa chỉ của biến f
    {
        int i;
        delete [] data; //thu hồi vùng nhớ cũ
        n=f.n;
        data = new float [n]; //cấp phát vùng nhớ mới
        for(i=0;i<=f.n;i++)
            data[i]=f[i];
    }
    return *this; //*this là giá trị, this là địa chỉ
}

istream &operator >> (istream &in, Poly &f) //hàm toàn cục truy cập đến các thành viên private thì phải khai báo friend
{
    int i;
    for(i=0;i<=f.n;i++)
    {
        cout<<"he so cua x bac "<<i<<" : ";
        cin>>f[i];
    }
    return in;
}

ostream &operator << (ostream &out, const Poly &f) //hàm toàn cục truy cập đến các thành viên private thì phải khai báo friend
{
    int i;
    for(i=0;i<f.n;i++)
        cout<<"("<<f[i]<<")*x^"<<i<<" + ";
    cout<<"("<<f[i]<<")*x^"<<i<<" = 0";
    return out;
}

int main()
{
    //Hàm dựng mặc định với 1 tham số là bậc đa thức
    Poly a(3);
    cout<<"Da thuc a: "<<a<<endl;

    //Hàm dựng với các hệ số đc khởi tạo từ 1 mảng
    float array[3]={2,3,4};
    Poly b(array);
    cout<<"Da thuc b: "<<b<<endl;

    //Hàm dựng với các hệ số đc khởi tạo từ 1 đa thức
    Poly c(b);
    cout<<"Da thuc c: "<<c<<endl;

    //Toán tử +, -
    //Poly c=a+b: thứ tự gọi hàm: toán tử +, hàm dựng sao chép
    //Poly c; c=a+b; thứ tự: hàm dựng mặc định, toán tử +, toán tử gán =
    cout<<"Tong 2 da thuc a va b: "<<a+b<<endl;
    cout<<"Hieu 2 da thuc a va b: "<<a-b<<endl;

    //Toán tử >>, <<
    cout<<"Nhap da thuc c bac 2: "<<endl;
    cin>>c;
    cout<<"Da thuc c: "<<c<<endl;
    
    //Toán tử [],  ()
    int vt;
    cout<<"Nhap bac he so can tim trong da thuc c: ";
    cin>>vt;
    cout<<"He so cua x bac "<<vt<<" = "<<c[vt]<<endl;

    float x;
    cout<<"Nhap gia tri x can tinh cho da thuc c: ";
    cin>>x;
    cout<<"c(" <<x <<") = " <<c(x) <<endl; 

    return 0;
}