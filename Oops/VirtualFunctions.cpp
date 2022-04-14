#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;

class Employee {
    public:
    virtual void raiseSalary() {
        cout << "raising salary" << endl;
    }
};

class Manager : public Employee {
    public:
    int salary;
    Manager(int salary) {
        this->salary = salary;
    }
    void raiseSalary() {
        salary += 1000;
    }
};
class Engineer : public Employee {
    public:
    int salary;
    Engineer(int salary) {
        this->salary = salary;
    }
    void raiseSalary() {
        salary += 500;
    }
};

void globalRaiseSalary(Employee* e[], int n) {
    for (int i = 0; i < n; i++) {
        e[i]->raiseSalary();
    }
}

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    Employee *emp;
    Manager m(10000);
    Engineer e(5000);
    Employee *empArr[] = {&m, &e};
    globalRaiseSalary(empArr, 2);
    cout << m.salary << endl;
    cout << e.salary << endl;
}