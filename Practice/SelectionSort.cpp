#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selectionSort(int arr[], int n) {
    int h[n+1];
    for(int i=0;i<=n;i++) {
        h[i] = 0;
    }
    printArray(h, n+1);
    for(int i=0;i<n;i++) {
        h[arr[i]]++;
    }
    printArray(h, n+1);
}

void Selection_Sort(int arr, int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void Insertion_Sort(int arr, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // for(int i=0;i<n;i++) {
    //     a[i] = 0;
    // }
    selectionSort(a, n);
}