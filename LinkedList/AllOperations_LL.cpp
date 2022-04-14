#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
class Node {
    public:
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
        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void print() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
class SpecialOperations : public LinkedList {
    public:
    void reverseAtEveryLevel(int k) {
        if(head == NULL) cout << "HI\n";
        Node *temp = head;
        Node *prev = NULL;
        Node *next = NULL;
        int count = 0;
        while (temp != NULL) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
            if (count == k) {
                head->next = temp;
                head = prev;
                count = 0;
            }
        }
    }
};
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n;
    cin >> n;
    Node* head = NULL;
    LinkedList ll;
    for(int i=0;i<n;i++) {
        cin >> n;
        ll.insert(n);
    }
    ll.print();
    SpecialOperations so;
    so.reverseAtEveryLevel(1);
    ll.print();
}