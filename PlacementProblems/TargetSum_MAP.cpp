// 12th - March - 2022  (Written with Conciousness at night 11:00 PM);
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin;
ofstream cout;
void printVector(vector<int> v) {
    cout << "[" << v[0] << ", " << v[1] << "]\n";
}
int main() {
    cin.open("input.txt");
    cout.open("output.txt");
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mp;
    vector<int> ans {0, 0};
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        mp[arr[i]] = 1;
    }
    int target;
    cin >> target;
    for(int i=0;i<n;i++) {
        if(mp[target - arr[i]]) {
            // index of target - arr[i]
            int index = find(arr, arr + n, target - arr[i]) - arr;
            // cout << i << " " << index << endl;
            if(i != index) {
                ans.clear();
                if(i<index) {
                    ans.push_back(i);
                    ans.push_back(index);
                    break;
                } else {
                    ans.push_back(index);
                    ans.push_back(i);
                    break;
                }
            }
        }
    }
    printVector(ans);
}


/**
 * @brief 
 * INPUT:
 * 6
 * 5 7 10 12 11 4
 * 14
 * OUTPUT:
 * [2, 5]
 * 
 */