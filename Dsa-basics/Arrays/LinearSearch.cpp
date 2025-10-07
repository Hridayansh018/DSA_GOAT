#include <iostream>
using namespace std;

// Linear search

int main(){

    int arr[8] = {1,2,3,4,5,6,7,8};
    int x;
    cout << "Enter Target Element : " 7;
    cin >> x;
    bool found = false;
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i<n; i++){
        if (arr[i] == x){
            found = true;
            break;
        }
    }
    if (found){
        cout << "Element "<< x <<" present in the array" << endl;
    } else {
        cout << "Element "<< x <<" not present in the array" << endl;
    }

    return 0;
}