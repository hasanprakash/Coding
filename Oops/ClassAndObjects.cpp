#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
class Car {
    public:
    int speed;
    int price;
    Car(int s, int p) {
        speed = s;
        price = p;
    }
    void printDetails() {
        cout << "Speed: " << speed << ", ";
        cout << "Price: " << price << endl;
    }
};
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    Car c1(100, 200);
    Car c2(200, 300);
    c1.printDetails();
    c2.printDetails();
}