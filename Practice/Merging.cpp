#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;
int arr[100000];

// my code
void merge2Arrays(int arr1[], int n1, int arr2[], int n2) {
    int i=0, j=0;
    vector<int> ans;
    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i] > arr2[j]) {
            ans.push_back(arr2[j]);
            j++;
        }
        else {
            ans.push_back(arr1[i]);
            ans.push_back(arr2[j]);
            i++;j++;
        }
    }
    if(i < n1) {
        for(int k=i;k<n1;k++) {
            ans.push_back(arr1[k]);
        }
    }
    if(j < n2) {
        for(int k=j;k<n2;k++) {
            ans.push_back(arr2[k]);
        }
    }
    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

// copilot's code
void mergeArrays(int arr1[], int n1, int arr2[], int n2) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n1; cin >> n1;
    int arr1[n1];
    for(int i=0;i<n1;i++) {
        cin >> arr1[i];
    }
    int n2;cin >> n2;
    int arr2[n2];
    for(int i=0;i<n2;i++) {
        cin >> arr2[i];
    }
    //mergeArrays(arr1, 5, arr2, 5);
    merge2Arrays(arr1, n1, arr2, n2);
}