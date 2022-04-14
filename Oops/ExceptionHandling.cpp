#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
string testException(int a, int b) {
    if(b==0) {
        throw "Divide by zero exception";
    }
    else {
        return "Successfully divided!";
    }
}
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    try {
        cout << testException(10, 1) << endl;
    }
    catch(const char* msg) {
        cout << msg << endl;
    }
}