#include <fstream>
#include <queue>
using namespace std;

ifstream cin;
ofstream cout;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void print_queue(priority_queue<int> pq) {
    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main() {
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }
    priority_queue<int> pq;
    pq.push(10);
    pq.push(9);
    pq.push(5);
    pq.push(14);
    pq.push(15);
    pq.push(11);
    pq.push(8);
    print_queue(pq);
}