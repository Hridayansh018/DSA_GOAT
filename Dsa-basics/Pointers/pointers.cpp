#include <iostream>
using namespace std;

int main(){

    int a = 10;
    int* p = &a;
    cout << a << endl;
    cout << &a << endl;
    cout << p << endl;
    cout << *p << endl;
    
    int x = 15;
    int* y = &x;
    *y = *y+1;
    cout<<x;

    return 0;
}