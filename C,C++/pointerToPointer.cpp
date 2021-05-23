#include<iostream>
using namespace std;

int main()
{
    cout<<"shamim rahman khan"<<endl;
    int x=50;
    int ***r,**q,*p=&x;
    q=&p,r=&q;
    cout<<&x<<endl;
    cout<<"address: "<<p<<" Value: " <<*p<<endl;
    cout<<&p<<endl;
    cout<<"address2: "<<q<<" Value2: "<<*q<<endl;
    cout<<**q<<endl;
    cout<<"address3: "<<r<<" Value3: "<<*r<<endl;
    cout<<**r<<endl;
    cout<<***r<<endl;
    cout<<&r<<endl;

    return 0;
}