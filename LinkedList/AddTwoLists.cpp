#include <fstream>
#include <stack>
using namespace std;
ifstream cin;
ofstream cout;

struct Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insert(Node* head, int data) {
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
Node* addTwoLists(Node* first, Node* second)
{
    stack<Node*> s1;
    stack<Node*> s2;
    Node* temp = first;
    Node* head = NULL;
    while(temp != NULL) {
        s1.push(temp);
        temp = temp->next;
    }
    temp = second;
    while(temp != NULL) {
        s2.push(temp);
        temp = temp->next;
    }
    int carry = 0, num1, num2;
    string string_sum = "";
    stack<string> ans;
    while(!s1.empty() || !s2.empty()) {
        if(!s1.empty()) {
            num1 = s1.top()->data;
            s1.pop();
        }
        else
            num1 = 0;
        if(!s2.empty()) {
            num2 = s2.top()->data;
            s2.pop();
        }
        else
            num2 = 0;
        int sum = num1 + num2 + carry;
        carry = 0;
        string_sum = to_string(sum);
        if(string_sum.length() > 1) {
            carry = (string_sum[0]) - 48;
            ans.push(to_string(string_sum[1]-48));
        }
        else {
            ans.push(to_string(string_sum[0]-48));
        }
    }
    if(string_sum.length() > 1)
        ans.push(to_string(string_sum[0] - 48));
    // this is to add the last character, if the length of sum is greater than 2 in the last iteration
    // eg: 5
    // 7 7 0 3 2
    // 5
    // 2 9 6 6 0
    // output: 1 0 6 6 9 2 
    
    while(!ans.empty()) {
        head = insert(head, stoi(ans.top()));
        ans.pop();
    }
    return head;
}

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n;
    cin >> n;
    Node* first = NULL;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        first = insert(first, a);
    }
    int m;
    cin >> m;  
    Node* second = NULL;
    for(int i=0;i<m;i++) {
        int b;
        cin >> b;
        second = insert(second, b);
    }
    printLinkedList(addTwoLists(first, second));
}