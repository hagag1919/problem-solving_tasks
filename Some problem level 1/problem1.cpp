#include<iostream>//Ahmed Maher_20216010,Essam Alaa_20216064
using namespace std;
//Creating struct Complex
struct Complex {
    float real, img;
};
    //add function to add two cmplx num
    void addition (Complex c1,Complex c2)
    {
        int x,y;
        x=c1.real+c2.real;
        y=c1.img+c2.img;
        cout<<"\n("<<c1.real<<"+"<<c1.img<<"i)+("<<c2.real<<"+"<<c2.img<<"i)=("<<x<<"+"<<y<<"i)";
    }
    //subtraction function to add two cmplx num
    void subtraction(Complex c1,Complex c2)
    {
        int x,y;
        x=c1.real-c2.real;
        y=c1.img-c2.img;
        cout<<"\n("<<c1.real<<"+"<<c1.img<<"i)-("<<c2.real<<"+"<<c2.img<<"i)=("<<x<<"+"<<y<<"i)";
    }
    //multiply function to multiply two cmplx numbers
    void multiplication(Complex c1,Complex c2)
    {
        int x,y;
        x=c1.real*c2.real-c1.img*c2.img;
        y=c1.real*c2.img+c1.img*c2.real;
        cout<<"\n("<<c1.real<<"+"<<c1.img<<"i)*("<<c2.real<<"+"<<c2.img<<"i)=("<<x<<"+"<<y<<"i)";
    }
int main () {
    Complex a, b, c;
    int add, subtract, multiply;
    cout << "\nEnter real and imaginary part of first complex number:";
    cin >> a.real >> a.img;
    cout << "\nEnter real and imaginary part of second complex number:";
    cin >> b.real >> b.img;
    cout << "if you want to add choose 1:" << endl;
    cout << "if you want to subtract choose 2:" << endl;
    cout << "if you want to multiply choose 3:" << endl;
    int operation;
    cin >> operation;
    switch (operation) {
        case (1):
            addition (a, b);
            break;
        case (2):
            subtraction(a, b);
            break;
        case (3):
            multiplication(a,b);
            break;
    }
}