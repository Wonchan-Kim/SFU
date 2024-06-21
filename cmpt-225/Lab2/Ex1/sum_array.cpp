#include <iostream>

using namespace std;

int sumArray(int arr[], unsigned int arrSize){
    int sum = 0;
    for(unsigned int i = 0; i < arrSize; i++){
        sum += arr[i];
    }
    return sum;
}

int main() {
    unsigned int num;
    cin >> num;

    int *arr = new int[num];
    for(unsigned int i = 0; i < num; i++){
        int input;
        cin >> input;
        arr[i] = input;
    }
    int result = sumArray(arr, num);
    cout << result << endl;
    delete [] arr;
    return result;
}