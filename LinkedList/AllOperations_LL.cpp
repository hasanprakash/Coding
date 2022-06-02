#include <fstream>
#include <map>
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
        head = NULL;
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

    // finds the middle element in the linked list
    void middleInTheLinkedList() {
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle Element is " << slow->data << endl;
    }

    // checks if loop is there in the linked list
    bool isLoopExist(Node* head)
    {
        map<Node*, int> addresses;
        Node* temp = head;
        while(temp != NULL) {
            if(addresses[temp->next] == 0)  {
                addresses[temp->next] = 1;
            }
            else {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // removing dublicates
    Node *removeDuplicates(Node *head)
    {
        Node* temp = head;
        while(temp != NULL) {
            if(temp->next != NULL && temp->data == temp->next->data) {
                temp->next = temp->next->next;
            }
            else
            temp = temp->next;
        }
        return head;
    }

    void moveLastElementToFront() {
        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next->next = head;
        head = temp->next;
        temp->next = NULL;
    }
};
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n;
    cin >> n;
    SpecialOperations so;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        so.insert(num);
    }
    so.print();
    so.middleInTheLinkedList();
    so.moveLastElementToFront();
    so.print();
    so.moveLastElementToFront();
    so.print();
    return 0;
}