// 22 FEB 2022
// printing all paths from root to leaf (backtracking)
#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;
void printVector(vector<vector<int>> v);

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

void h(Node* root, vector<int> path, vector<vector<int>> paths) {
    if(root == NULL)
    return;
    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL) {
        paths.push_back(path);
        path.pop_back();
        return;
    }
    h(root->left, path, paths);
    h(root->right, path, paths);
    
}

void printTree(Node* root) {
    // if(root == NULL)
    // return;
    vector<int> path;
    vector<vector<int>> paths;
    // path.push_back(root->data);
    h(root, path, paths);
    printVector(paths);
}

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(8);
    root->left->left = new Node(6);
    root->left->right = new Node(7);
    root->right->left = new Node(11);
    root->right->right = new Node(4);
}


void printVector(vector<vector<int>> v) {
    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[i].size();j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



/*
// ideone.com/A8Z0q4 -> input 2 arrays (1->preorder, 2->inorder)
*/