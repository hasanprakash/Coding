#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
class Shape {
    public:
    int area(int l, int b, int h);
};
class Rectangle : public Shape {
    public:
    int area(int l, int b, int h) {
        return l * b * h;
    }
};
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    Shape s;
    s.area(10, 20, 30);
}