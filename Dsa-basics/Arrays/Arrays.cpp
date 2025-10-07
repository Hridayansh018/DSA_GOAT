#include <iostream>
using namespace std;

int main(){

    int arr[5];
    // arr[0] = 1;
    // arr[1] = 2;
    // arr[2] = 4;
    // arr[3] = 5;
    // arr[4] = 6;
    // cout << arr[0] << endl;

    int length = sizeof(arr)/sizeof(arr[0]);

    cout << "Enter the elements of array"<< endl;
    for (int i = 0; i<length; i++){
        cin >> arr[i];
    }

    cout << "The elements of array are : " << endl;
    for (int i = 0; i<length; i++){
        cout << arr[i] << endl;
    }

    int sum = 0;
    float avg = 0;
    int product = 1;
    for(int i = 0; i<length; i++){
        sum += arr[i];
        avg = sum/length;
        product *= arr[i];
    }
    cout << "The sum of elements of arrays are : " << sum << endl;
    cout << "The average of elements of arrays are : " << avg << endl;
    cout << "The product of elements of arrays are : " << product << endl;

    return 0; 
}