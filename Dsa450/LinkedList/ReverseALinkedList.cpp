#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;

struct Node {
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    public:
    Node *head;
    LinkedList() {
        this->head = NULL;
    }
    void insert(int data) {
        Node *newNode = new Node(data);
        if(this->head == NULL) {
            this->head = newNode;
        } else {
            Node *temp = this->head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void print() {
        Node *temp = this->head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse() {
        Node *prev = NULL;
        Node *curr = this->head;
        Node *next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        this->head = prev;
    }
};

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    LinkedList ll;
    ll.insert(10);
    ll.insert(3);
    ll.insert(6);
    ll.insert(9);
    ll.insert(12);
    ll.insert(15);
    ll.print();
    ll.reverse();
    ll.print();
}