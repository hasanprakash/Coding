#include <fstream>
#include <queue>
using namespace std;
ifstream cin;
ofstream cout;

int main() {
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }
    // priority_queue<pair<int, int>> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        pq.push(make_pair(a, b));
    }
    while(!pq.empty()) {
        auto data = pq.top();
        cout << data.first << " " << data.second << endl;
        pq.pop();
    }
}