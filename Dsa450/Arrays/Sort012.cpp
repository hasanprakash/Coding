// 14th April 2022
// Sorting an array contains only 0, 1, 2 without sort algorithm

#include <fstream>
#include <cstring>
using namespace std;
ifstream cin;
ofstream cout;
int main() {
    cin.open("../../input.txt");
    cout.open("../../output.txt");
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int h[3];
    memset(h, 0, sizeof(h));
    for(int i = 0; i < n; i++) {
        h[arr[i]]++;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < h[i]; j++) {
            cout << i << " ";
        }
    }
}

/*
    @input:
    5
    0 2 1 2 0
    @output:
    0 0 1 2 2    
*/