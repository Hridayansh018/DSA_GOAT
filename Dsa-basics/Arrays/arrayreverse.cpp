#include <iostream>
using namespace std;


void reverseArray(int arr[], int len){

    int arr2[len];
    for(int i = len-1; i>=0; i--){
        arr2[i] = arr[len - 1 - i];
        // cout << arr2[i] << " ";
    }
    cout << "[ ";
    for(int i = 0; i < len; i++) {
        cout << arr2[i] << " ";
    }
    cout << "]" << endl;
}



int main(){

    int arr[5];
    int n;
    for(int i = 0; i<5; i++){
        cout << "Enter number for " << i << " index : ";
        cin >> n;
        arr[i] = n;
    }

    // for(int i = 0; i < 5; i++) {
    //     cout << "Enter number for index " << i << " : ";
    //     cin >> n;
    //     arr[i] = n;  // Use assignment (=), not comparison (==)
    // }
    cout << "Original array : " << endl;
    cout << "[ ";
    for(int i = 0; i<5; i++){
        cout <<  arr[i] << " ";
    }
    cout << "]" << endl;

    cout << "Reverced array : " << endl;
    reverseArray(arr,5);
    return 0;
}