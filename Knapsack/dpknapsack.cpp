#include <bits/stdc++.h>
using namespace std;
class Item {
    public:
    int weight;
    int value;
    Item(int weight, int value) {
        this->weight = weight;
        this->value = value;
    }
};

string h(vector<Item> items, int n, int cap, int i) {
    if(cap <= 0 || i >= n)
    return 0;
    long long incIth = 0;
    if(items[i].weight <= cap) {
        incIth = items[i].value + h(items, n, cap - items[i].weight, i+1);
    }
    long long excIth = h(items, n, cap, i+1);
    return max(incIth, excIth);
}

string maxProfit(vector<Item> items[], int cap){
    return h(items, items->size(), cap, 0);
}
int main() {
    int t;
    cin >> t;
    vector<Item> items;
    int cap;
    cin >> cap;
    while(t--) {
        int a, b;
        cin >> a >> b;
        Item obj(a, b);
        items.push_back(obj);
        cout << maxProfit(items, cap) << endl;
    }
}
