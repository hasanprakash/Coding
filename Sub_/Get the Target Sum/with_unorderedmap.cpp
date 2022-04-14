// 15-12-2021 - Wednesday
#include <fstream>
#include <unordered_map>
using namespace std;
ifstream cin;
ofstream cout;
int main() {
    {
        cin.open("../../input.txt");
        cout.open("../../output.txt");
    }
    int n; cin >> n;
    int arr[n];
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int target_sum;
    cin >> target_sum;
    int count = 0;
    for(int i=0;i<n;i++) {
        int element_needed = target_sum - arr[i];
        if(mp[element_needed] != 0 && mp[arr[i]] != 0) {
            count++;
            if(mp[element_needed] > mp[arr[i]])
            mp[element_needed]--;
            else
            mp[arr[i]]--;
        }
    }
    cout << count << endl;
    
}
