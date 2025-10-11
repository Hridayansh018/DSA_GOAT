#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter number : " ;
    cin >> n;
    int m;
    if(n>1 && n%2 == 1){;
        for(int i=0; i<n-1; i++){
            cout<<"    ";
            for(int j = 0; j<n-i; j++){
                cout << " ";
            }
            for(int k=0; k<2*i+1; k++){
                cout << "*";
            }
            cout << endl;
        }
        for(int i=0; i<n; i++){
            cout << "e     e" << endl;
        }
        cout << "eeeeeee" ;
    }
    return 0;
}