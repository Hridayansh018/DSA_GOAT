#include <iostream> 
using namespace std;

void change(int x ,int y,int arr[], int length){
    if(x<length){
        arr[x] =  y;
    } else {
        cout << "Invalid Array Size :- " << x << endl;
    } 
}


void display(int arr[], int length){
    for (int i = 0; i<length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(arr)/sizeof(arr[0]);

    cout << "Original Array :- " << endl;
    display(arr,length);
    cout << "Modified Array :- " << endl;
    change(9,20,arr,length);
    display(arr,length);

    return 0;
}