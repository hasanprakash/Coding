#include <fstream>
#include <vector>
#include <map>
using namespace std;
ifstream cin;
ofstream cout;

void printMap(map<int, vector<int>> mp) {
    for(auto i: mp) {
        cout << i.first << ": ";
        for(auto j: i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        if(mp[a].size() != 0) {
            mp[a].push_back(b);
        } else {
            vector<int> v1;
            v1.push_back(b);
            mp[a] = v1;
        }
    }
    printMap(mp);
}