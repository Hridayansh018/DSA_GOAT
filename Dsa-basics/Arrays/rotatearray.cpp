#include <iostream>
using namespace std;

void rotateSubrangeRight(int arr[], int start, int stop) {
    if (start >= stop) return;

    int temp = arr[stop];
    for (int i = stop; i > start; i--) {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

int main() {
    int x;
    cout << "Enter array length: ";
    cin >> x;

    int arr[x];
    for (int i = 0; i < x; i++) {
        cout << "Enter number for index " << i << ": ";
        cin >> arr[i];
    }

    int start, stop;
    cout << "Enter start index to rotate: ";
    cin >> start;
    cout << "Enter stop index to rotate: ";
    cin >> stop;

    rotateSubrangeRight(arr, start, stop);

    cout << "Rotated array: [ ";
    for (int i = 0; i < x; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}