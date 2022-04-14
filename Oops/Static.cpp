// Static Rules
// 13 - March - 2022
#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
class Hasan {
    public:
    static int value;
    int nonStatic = 10;
    Hasan() {
        Hasan::value++;
    }
    static void display() { // static 
        cout << Hasan::value << endl;
    }
    void displayNonStatic() { // non-static
        cout << nonStatic << " " << value << endl;
    }
};
int Hasan::value = 0;
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    Hasan h;
    cout << h.value << endl; // with instance
    Hasan::value = 10;
    h.value = 20;
    cout << Hasan::value << endl; // without instance
    cout << endl;
    h.display(); // accessing static method with non-static (obj)
    Hasan::display();
    cout << endl;
    h.displayNonStatic();
    // Hasan::displayNonStatic(); // error (object reference is required)
}
