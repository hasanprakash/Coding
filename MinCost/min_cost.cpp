#include <fstream>
#include <queue>
using namespace std;
ifstream cin;
ofstream cout;

void printQueue(priority_queue<int, vector<int>, greater<int>> pq) {
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    {
        cin.open("input.txt");
        cout.open("output.txt");
    }
    int t;
    cin >> t;
    int a;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<t;i++) {
        cin >> a;
        pq.push(a);
    }   
    int mini = 0;
    while(pq.size() > 1) {
        int top1 = pq.top();
        pq.pop();
        int top2 = pq.top();
        pq.pop();
        mini += (top1 + top2);
        cout << "TOTAL is " << mini << endl;
        pq.push(top1 + top2);
        printQueue(pq);
    }
    cout << "FINAL ANS " << pq.top() << endl;
}