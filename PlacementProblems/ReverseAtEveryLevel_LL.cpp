#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
struct Node {
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};
Node* insertIntoLinkedList(Node *head, int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
void printLinkedList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n;
    cin >> n;
    Node* head = NULL;
    for(int i=0;i<n;i++) {
        int data;
        cin >> data;
        head = insertIntoLinkedList(head, data);
    }
    printLinkedList(head);
}