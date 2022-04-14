#include <fstream>
#include <queue>
// #include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* insert_at_end(Node* head, int data) {
    if(head == NULL)
    head = new Node(data);
    else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
    return head;
}

int get_middle(Node* head) {
    Node* slow = NULL;
    Node* fast = NULL;
    slow = head;
    fast = head;
    // finding middle node here....
}

ifstream cin;
ofstream cout;

int main() {
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }
    int n;
    cin >> n;
    int arr[n];
    Node* head = NULL;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        head = insert_at_end(head, arr[i]);
    }
    cout << get_middle(head) << endl;

}