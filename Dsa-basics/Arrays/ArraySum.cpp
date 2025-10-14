#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cout << "enter array size : " ;
    cin >> n;
    vector<int> arr(n);
    int sum = 0; 

    for(int i=0; i<n; i++){
        cout << "ENter element for index ( " << i << " ) : " ;
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    cout << "Sum of the lements of array is : " << sum << endl ;

    return 0;
}