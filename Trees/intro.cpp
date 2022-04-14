#include <stdio.h>
#include <fstream>
#include <queue>
using namespace std;
#define COUNT 10
ifstream cin;
ofstream cout;

void printVector(vector<int> v);
void print2DVector(vector<vector<int>> v);

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

BSTNode* insert(BSTNode* root, int x) {
    BSTNode* node = new BSTNode(x);
    if(root == NULL)
    return node;
    BSTNode* temp = root;
    // BSTNode* prev = temp;
    while(temp != NULL) {
        if(x < temp->data) {
            if(temp->left != NULL) {
                // prev = temp;
                temp = temp->left;
            }
            else {
                temp->left = node;
                break;
            }
        }
        else if(x >= temp->data) {
            if(temp->right != NULL) {
                // prev = temp;
                temp = temp->right;
            }
            else {
                temp->right = node;
                break;
            }
        }
    }
    return root;
    
}


void print2DUtil(BSTNode *root, int space)
{
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
void print2D(BSTNode *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}   

void printLevelOrderTraversal(BSTNode* root) {
    if(root == NULL)
        return;
    queue<BSTNode*> q;
    q.push(root);
    while(!q.empty()) {
        BSTNode* topValue = q.front();
        q.pop();
        cout << topValue->data << " ";
        if(topValue->left != NULL) {
            q.push(topValue->left);
        }
        if(topValue->right != NULL) {
            q.push(topValue->right);
        }
    }
    cout << endl;
}

vector<vector<int>> printLevelOrderTraversalForNL(BSTNode* root) {
    vector<vector<int>> outer_vector;
    vector<int> inner_vector;
    if(root == NULL)
        return outer_vector;

    queue<BSTNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        BSTNode* topNode = q.front();
        q.pop();
        if(topNode != NULL) {
            cout << topNode->data << " ";
            inner_vector.push_back(topNode->data);
            if(topNode->left != NULL) {
                q.push(topNode->left);
            }
            if(topNode->right != NULL) {
                q.push(topNode->right);
            }
        } if(topNode == NULL) {
            q.push(NULL);
            outer_vector.push_back(inner_vector);
            inner_vector.clear();
            cout << "\n";
        }
        if(q.size()<=1) {
            cout << "\n";
            outer_vector.push_back(inner_vector);
            break;
        }
    }
    
    return outer_vector;
}

int main() {
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }

    BSTNode* root = NULL;
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        root = insert(root, arr[i]);
    }

    // Printing list in Tree Format
    //print2D(root);

    // Printing Level Order Traversal
    printLevelOrderTraversal(root);

    // Level Order Traversal returns list of list..
    vector<vector<int>> answer;
    answer = printLevelOrderTraversalForNL(root);
    print2DVector(answer);
    
    cout << "Printed\n";

    return 0;
}















void print2DVector(vector<vector<int>> v) {
    for(auto i:v) {
        for(auto j:i)  {
            cout << j << " ";
        }
        cout << endl;
    }
}