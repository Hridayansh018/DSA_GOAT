#include <iostream>
#include <vector>
using namespace std;

// Vector is a dynamic array that doubles its size when completly filled

int main(){

    int n;
    cout << "Enter size : ";
    cin>>n;
    vector<int> arr(n); //Vector declaration - vector<data type> name(size)
    for(int i = 0; i<n; i++){
        cout << "Enter element for index " << i << " : " ;
        cin >> arr[i];
    }
    cout << endl;

    cout << "==============================" << endl;

    for(int i = 0; i<n; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
    cout<<"Size of the vector array : " << endl;
    cout << arr.size()<<endl;
    cout<<"Capacity of the vector array : " << endl;
    cout << arr.capacity()<<endl;
    arr.push_back(5);
    cout<<"capacity of the vector array after adding extra element : " << endl;
    cout << arr.capacity();

    // Vector operations
    // arr.push_back(element); - adds an element at the end of the array
    // arr.pop_back(element); - removes an element from the end of the array
    // arr.size(); - returns the size of the vector array

    return 0;
}