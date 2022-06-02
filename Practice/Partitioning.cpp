#include <fstream>
#include <math.h>
using namespace std;
ifstream cin;
ofstream cout;

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void partitioning(int arr[], int n) {
    int pivot = arr[n-1];
    int i=0, j=n-2;
    bool forward = true;
    while(i <= j) {
        if(forward && arr[i] < pivot) {
            i++;
            continue;
        }
        else
            forward = false;
        if(!forward && arr[j] > pivot) {
            j--;
            continue;
        }
        else {
            forward = true;
            cout << arr[i] << " " << arr[j] << endl;
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[i], arr[n-1]);
    printArray(arr, n);
}

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    partitioning(a, n);
}