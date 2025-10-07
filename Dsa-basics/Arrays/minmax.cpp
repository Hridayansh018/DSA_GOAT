#include <iostream>
using namespace std;

int main(){

    int arr[5] = {6,2,3,4,5};
    int mx = arr[0];
    int mn = arr[0];

    for(int i =0; i<5; i++){
        if(mx<arr[i]){
            mx = arr[i];
        }
        if(mn>arr[i]){
            mn = arr[i];
        }
    }

    cout <<"==========================================="<< endl;
    cout << "Maximum element in the array is : " << mx << endl;
    cout << "Minimum element in the array is : " << mn << endl;
    cout <<"==========================================="<< endl;

    for(int i=1; i<5; i++){
        mx = max(mx,arr[i]);
        mn = min(mn,arr[i]);
    }

    cout << "Maximum element in the array is : " << mx << endl;
    cout << "Minimum element in the array is : " << mn << endl;
    cout <<"==========================================="<< endl;

    return 0;
}