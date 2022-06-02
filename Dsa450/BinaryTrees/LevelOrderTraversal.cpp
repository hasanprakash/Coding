#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;

class Node
{
    int data;
    int left;
    int right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Operations {
    public:
    vector<int> levelOrder(Node* node)
    {
        vector<int> ans;
        if(head == NULL) {
            ans.push_back(node->data);
            return ans;
        }
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            Node* front = q.front();
            ans.push_back(front->data);
            if(front->left) 
                q.push(front->left);
            if(front->right) 
                q.push(front->right);
            q.pop();
        }
        return ans;
    }
}

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    Operations ops;
    Node* head = NULL;
    vector<int> v = ops.levelOrder(head);
    for(int i: v) {
        cout << i << " ";
    }
    cout << endl;
}