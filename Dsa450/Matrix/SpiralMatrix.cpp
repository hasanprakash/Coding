#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
int a[100][100];
int xValue = 0, yValue = 0;
void spiralMatrix(int r, int c) {
    for(int i=xValue;i<c-yValue;i++) {
        cout << a[yValue][i] << " ";
    }
    cout << endl;
    for(int i=1 + yValue;i<r - yValue;i++) {
        cout << a[i][c-1 - xValue] << " ";
    }
    cout << endl;
    for(int i=c-2 - yValue;i>=yValue;i--) {
        cout << a[r-1 - xValue][i] << " ";
    }
    cout << endl;
    for(int i=r-2 - yValue;i>=yValue + 1;i--) {
        cout << a[i][xValue] << " ";
    }
    cout << endl;
    xValue++;
    yValue++;
    if(xValue < c/(float)2 && yValue < r/(float)2) {
        spiralMatrix(r, c);
    }
}

int main() {
    cin.open("../../input.txt");
    cout.open("../../output.txt");
    int r, c; cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    spiralMatrix(r, c); 
    return 0;
}