// 15-12-2021 - Wednesday
// in O(nlogn + n*n)
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
    sort(arr, arr+n);
    int t;cin >> t;
    int flag = 0, flag1 = 0;
    for(int i=0;i<n-2;i++) {
        int j=i+1;
        int k=n-1;
        while(j<k) {
            if(arr[i]+arr[j]+arr[k]==t) {
                flag = 1;
                break;
            }
            else if(arr[i]+arr[j]+arr[k]<t)
            j++;
            else if(arr[i]+arr[j]+arr[k]>t)
            k--;
        }
        if(flag) {
            flag1 = 1;
        }
    }
    if(flag1)
    cout << "Found the triplet\n";
    else
    cout << "We Failed\n";


}