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

ifstream cin;
ofstream cout;

Node* insert(int data, Node* head) {
    Node* temp = head;
    if(head==NULL)
    head = new Node(data);
    else {
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
    return head;
}

void deleteNode(Node* head, int index) {
    int i = 0;
    Node* temp = head;
    Node* prev = head;
    if(head == NULL) 
    return;
    else {
        while(temp->next!=NULL) {
            if(i==index) {
                prev->next = temp->next;
            }
            prev = temp;
            temp = temp->next;
            i++;
        }
    }
}

void display(Node* head) {
    Node* temp = head;
    while(temp->next != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl;
}

int main() {
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }
    int t;
    cin >> t;
    Node* head = NULL;
    for(int i=0;i<t;i++) {
        int a;
        cin >> a;
        head = insert(a, head);
    }
    display(head);
    deleteNode(head, 3);
    display(head);
}