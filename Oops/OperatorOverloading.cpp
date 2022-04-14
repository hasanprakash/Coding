#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
class Game
{
public:
    int score;
    int rating;
    Game() {}
    Game(int score, int rating)
    {
        this->score = score;
        this->rating = rating;
    }
    Game operator+(Game g)
    {
        Game g1(this->score + g.score, this->rating + g.rating);
        return g1;
    }
    Game operator-(Game g)
    {
        cout << "SCORES = " << this->score << " " << g.score << endl;
        Game g1(this->score - g.score, this->rating - g.rating);
        return g1;
    }
    operator float()
    {
        return (float)this->score / this->rating;
    }

    friend Game operator*(Game const, Game const);
};

class Shape {
    public:
    virtual int getArea() = 0;
};
class Rectangle : public Shape {
    private: 
    int l, b, h;
    public:
    Rectangle(int l, int b, int h) {
        this->l = l;
        this->b = b;
        this->h = h;
    }
    int getArea() {
        return l * b * h;
    }
    operator int() {
        return l*b*h;
    }
};
class Square : public Shape {
    private: 
    int side;
    public:
    Square(int side) {
        this->side = side;
    }
    int getArea() {
        return side * side;
    }
    operator int() {
        return side*side;
    }
};
Game operator*(Game g1, Game g2)
{
    Game g3(g1.score * g2.score, g1.rating * g2.rating);
    return g3;
}

int main()
{
    cin.open("../input.txt");
    cout.open("../output.txt");
    Game g1;
    g1 = Game(10, 6);
    Game g2(20, 10);
    Game g3;
    g3 = g1 + g2;
    cout << g3.score << " " << g3.rating << endl;
    g3 = g1 - g2;
    cout << g3.score << " " << g3.rating << endl;
    g3 = g1 * g2;
    cout << g3.score << " " << g3.rating << endl;

    float result = g1;
    cout << result << endl;

    Rectangle r1(10, 20, 30);
    Square s1(10);

    int r1_area = r1;
    int s1_area = s1;
    cout << "\nArea of Rectangle and Square \n" << r1_area << " " << s1_area << endl;

    Shape *s;
    cout << "Finding areas with dynamic polymorphism\n";
    s = &r1;
    cout << s->getArea() << " ";
    s = &s1;
    cout << s->getArea() << endl;
}