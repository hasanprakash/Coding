#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
class Test {
    private:
    string secret = "Fuck you";
    public:
    friend void print();
};

void print() {
    cout << "printing the secret, wait for it..." << endl;
    Test t;
    cout << "secret = " << t.secret << endl;
}

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    Test t;
    print();
}