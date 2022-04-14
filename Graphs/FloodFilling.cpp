/*
Flood Filling Algorithm, to fill the path or space.
8th March 2022   Tuesday
*/
#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;

int arr[100][100];
int r, c;
int count = 0;

void floodFill(int x, int y) {
    arr[x][y] = 2;
    count++;
    if(x-1 >= 0 && arr[x-1][y] == 0) {
        floodFill(x-1, y);
    }
    if(x+1 < r && arr[x+1][y] == 0) {
        floodFill(x+1, y);
    }
    if(y-1 >= 0 && arr[x][y-1] == 0) {
        floodFill(x, y-1);
    }
    if(y+1 < c && arr[x][y+1] == 0) {
        floodFill(x, y+1);
    }
}

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    cin >> r >> c;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> arr[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    floodFill(x, y);
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "No of recursions = " << count << endl;
}