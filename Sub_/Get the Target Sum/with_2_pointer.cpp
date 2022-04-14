// 15-12-2021 - Wednesday
#include <fstream>
#include <unordered_map>
#include <algorithm>
using namespace std;
ifstream cin;
ofstream cout;
int main() {
    {
        cin.open("../../input.txt");
        cout.open("../../output.txt");
    }
    int n;cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int t; cin >> t;
    sort(arr, arr+n);
    int i=0, j=n-1;
    int flag = 0;
    while(i<j) {
        if(arr[i] + arr[j] == t) {
            flag = 1;
            break;
        }
        else if(arr[i] + arr[j] < t)  {
            i++;
        }
        else if(arr[i] + arr[j] > t) {
            j--;
        }
    }
    if(flag) {
        cout << "Got the Sum equal to Target\n";
    }
    else {
        cout << "Failed\n";
    }
    return 0;
}