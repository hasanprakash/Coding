#include <fstream>
#include <queue>
using namespace std;
ifstream cin;
ofstream cout;

struct Student
{
    string name;
    int marks;
    int cash;
};

class Cmp {
    public:
    bool operator()(Student s1, Student s2) {
        return s1.cash < s2.cash;
    }
};


int main() {
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, Cmp> pq;
    while(n--) {
        Student s;
        string name;
        int marks;
        int cash;
        cin >> name >> marks >> cash;
        s.cash = cash;
        s.marks = marks;
        s.name =  name;
        pq.push(s);
    }
    while(!pq.empty()) {
        auto data = pq.top();
        cout << data.name << " " << data.marks << " " << data.cash << endl;
        pq.pop();
        
    }

}