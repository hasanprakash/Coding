// 15-12-2021 - Wednesday
#include <fstream>
#include <unordered_map>
#include <algorithm>
using namespace std;
ifstream cin;
ofstream cout;
int main() {
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }
    int n;cin >> n;
    int m; cin >> m;
    int arr[10];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int arr1[m];
    for(int j=0;j<m;j++) {
        cin >> arr1[j];
    }
    int i = n-1, j = m-1;
    int k = i+j+1;
    int total = k;
    while(i>=0 && j>=0) {
        if(arr[i] > arr1[j])
        {
            arr[k--] = arr[i];
            i--;
        }
        else if(arr[i] <= arr1[j]) {
            arr[k--] = arr1[j];
            j--;
        }
        cout << i << " " << j << endl;
    }
    if(j>=0) {
        for(int l=0;l<=j;l++) {
            arr[l] = arr1[l];
        }
    }
    if(i>=0) {
        for(int l=0;l<=i;l++) {
            arr[l] = arr[l];
        }
    }
    for(int i=0;i<=total;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}