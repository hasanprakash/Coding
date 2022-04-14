// #include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
using namespace std;
ifstream cin;
ofstream cout;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class MaxHeap
{
public:
    static int arr[100];
    Node *create_heap(int data, Node *head)
    {
        cout << data << endl;
        if (head == NULL)
        {
            head = new Node(data);
        }
        else
        {
        }
        return head;
    }

    void tree_to_array(Node *head)
    {
        cout << "Converting tree to array..\n";
        queue<Node*> q;
        q.push(head);
        while(!q.empty()) {
            Node* f = q.front();
            cout << f->data << " ";
            if(f->left!=NULL) {
                q.push(f->left);
            }
            if(f->right!=NULL) {
                q.push(f->right);
            }
            q.pop();
        }
        cout << endl;
    }

    void array_to_BT(int arr[], int size) {
        queue<Node*> q;
        Node* head = NULL;
        if(size>0) {
            head = new Node(arr[0]);
            q.push(head);
        }
        else
            return;
        for(int i=1;i<size;i++) {
            Node* f = q.front();
            if(f->left == NULL) {
                f->left = new Node(arr[i]);
                q.push(f->left);
            }
            else if(f->right == NULL)  {
                f->right = new Node(arr[i]);
                q.push(f->right);
                q.pop();
            }
        }
        this->tree_to_array(head);
    }
};

int main()
{
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }
    int t;
    cin >> t;
    Node *head = NULL;
    MaxHeap obj;
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        // head = obj.create_heap(a, head);
        cout << a << endl;
    }
    
    head = new Node(7);
    head->left = new Node(9);
    head->right = new Node(13);
    head->left->left = new Node(6);
    head->left->right = new Node(8);
    head->right->left = new Node(15);
    head->right->right = new Node(11);
    obj.tree_to_array(head);

    int arr[7] = {7, 9, 13, 6, 8, 15, 11};
    obj.array_to_BT(arr, 7);

}