#include<iostream>

using namespace std;

int main()
{
    int b[2][3]={{2,3,6},{4,5,8}};
    int (*p)[3]=b;
    cout<<b<<endl<<&b<<endl<<*b<<endl<<b[0]<<endl<<&b[0]<<endl<<&b[0][0]<<endl;
    cout<<*b[0]<<endl<<b[0][0]<<endl;

    cout<<endl;
    
    int x[1][2]={{5,4}};
    cout<<x<<endl<<&x<<endl<<*x<<endl<<x[0]<<endl<<&x[0]<<endl<<&x[0][0]<<endl;
    cout<<*x[0]<<endl<<x[0][0]<<endl;
    
    cout<<endl;
    
    cout<<**(b+1)<<endl; //check out
    cout<<*(*(b+1)+2)<<endl; //check out
    cout<<*(*b+1)<<endl; //check out

    // b[i][j] = *(b[i]+j) = *(*(b+i)+j)

    return 0;
}