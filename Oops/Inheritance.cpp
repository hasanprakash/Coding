#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
class Shape {
    protected:
    string firstName="My Name is Hasan";
    public:
    static int valueToChange;
    // void test() {
    //     cout << "Testing in Shape\n";
    // }
    int getChangableValue() {
        return valueToChange;
    }
    void changeValue() {
        valueToChange += 100;
    }
};
class First {
    // protected:
    // string secondName = "Second name is Prakash";
    // public:
    // void test() {
    //     cout << "Testing in First\n";
    // }
};
class Second : public First, public Shape {
    public:
    // void print() {
    //     cout << firstName << endl;
    //     cout << secondName << endl;
    //     First::test();
    //     Shape::test();
    // }
    // void test() {
    //     cout << "Testing in Second\n";
    // }
    void changeValue() {
        valueToChange += 100;
    }
};
int Shape::valueToChange = 100;
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    Second second;
    // second.print();
    // cout << endl;
    // second.Shape::test();
    // second.First::test();
    // second.Second::test();
    // cout << endl;
    Shape s;
    cout << s.getChangableValue() << endl;
    s.changeValue();
    cout << s.getChangableValue() << endl;
    cout << "With Instance From Class Name -> \n" << second.Shape::getChangableValue() << endl;
    cout << "Without Instance \n" << Shape::valueToChange << endl;
}