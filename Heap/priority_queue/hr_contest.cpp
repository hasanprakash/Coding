#include <bits/stdc++.h>
using namespace std;

priority_queue<int> removeDublicates2(priority_queue<int> pq) {
    priority_queue<int> pq2;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        if (pq2.empty() || pq2.top() != x) {
            pq2.push(x);
        }
    }
    return pq2;
}
priority_queue<int, vector<int> , greater<int> > removeDublicates1(priority_queue<int, vector<int> , greater<int> > pq) {
    priority_queue<int, vector<int> , greater<int> > pq2;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        if (pq2.empty() || pq2.top() != x) {
            pq2.push(x);
        }
    }
    return pq2;
}


int main() {
    int n;
    priority_queue<int, vector<int> , greater<int> > arr1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr1.push(a);
    }
    // arr1 = removeDublicates1(arr1);
    int m;
    cin >> m;
    priority_queue<int> arr2;
    for(int i=0;i<m;i++) {
        int a;
        cin >> a;
        arr2.push(a);
    }
    // arr2 = removeDublicates2(arr2);
    int count = 0;
    while(1)  {
        if(arr1.empty() || arr2.empty()) {
            break;
        }
        int a = arr1.top();
        int b = arr2.top();
        cout << a << " " << b << endl;
        count++;
        if(a < b) {
            arr1.pop();
            arr1.push(a+1);
            arr2.pop();
            arr2.push(b-1);
        }
        else {
            break;
        }
        // arr1 = removeDublicates1(arr1);
        // arr2 = removeDublicates2(arr2);
    }
    cout << count << endl;
}


// Input:
/*
3
5
2
3
2
1
4
*/