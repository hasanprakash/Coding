// 14th April 2022
// QuickSort Partition Problem
// Order of numbers in the array is not important but -ve and +ve should be separated.

#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;

void rearrange(int arr[], int n) {
    int i = 0, j = n - 1;
    for(i = 0; i < n; i++) {
        if(arr[i] > 0) {
            for(j = n - 1; j > i; j--) {
                if(arr[j] < 0) {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
}
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    cin.open("../../input.txt");
    cout.open("../../output.txt");
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    rearrange(arr, n);
    printArray(arr, n);
}

/*
    INPUT:
    9
    -12 11 -13 -5 6 -7 5 -3 -6
    OUTPUT:
    -12 -13 -5 -7 -3 -6 11 6 5
*/