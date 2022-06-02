// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#
// not completed
#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin;
ofstream cout;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);
    printArray(arr, n);
    int ans = arr[n - 1] - arr[0]; // Maximum possible height difference

    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];

    for (int i = 1; i < n; i++) {
        if(arr[i] - k < 0) // if on subtracting k we got negative then continue 
        continue;
        tempmin= min(arr[0] + k,arr[i] - k); // Minimum element when we
                                                // add k to whole array
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k); // Maximum element when we
                                                         // subtract k from whole array
        cout << tempmin << " " << tempmax << endl;
        ans = min(ans, tempmax - tempmin); 
    }
    cout << tempmin << " " << tempmax << endl;
    return ans;
    // sort(arr, arr + n);
    // printArray(arr, n);
    // for(int i=0;i<n;i++) {
    //     arr[i] += k;
    // }
    // printArray(arr, n);
    // for(int i=0;i<n;i++) {
    //     arr[i] -= k;
    //     arr[i] -= k;
    // }
    // printArray(arr, n);
    // return 0;
}

int main() {
    cin.open("../../input.txt");
    cout.open("../../output.txt");
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k; cin >> k;
    cout << getMinDiff(arr, n, k);
}

/*
10
5 5 8 6 4 10 3 8 9 10
5

10
2 6 3 4 7 2 10 3 2 1
5

1 2 2 2 3 3 4 6 7 10 
*/