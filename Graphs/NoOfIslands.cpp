/*
Finding No of Islands.
8th March 2022   Tuesday
*/
#include <fstream>
using namespace std;
void printArray();
ifstream cin;
ofstream cout;

int arr[100][100];
int r, c;
int count = 0;

void countHelper(int x, int y) {
    arr[x][y] = 8;
    if(x-1 >= 0 && arr[x-1][y] == 1)
    countHelper(x-1, y);
    if(x+1 < r && arr[x+1][y] == 1)
    countHelper(x+1, y);
    if(y-1 >= 0 && arr[x][y-1] == 1)
    countHelper(x, y-1);
    if(y+1 < c && arr[x][y+1] == 1)
    countHelper(x, y+1);
}

int NoOfIslands() {
    int countOfIslands = 0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(arr[i][j] == 1) {
                countHelper(i, j);
                countOfIslands++;
            }
        }
    }
    return countOfIslands;
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
    cout << "No of Islands are " << NoOfIslands() << endl;
    cout << "No of recursions = " << count << endl;
    cout << "Final Array = " << endl;
    printArray();
}






void printArray() {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



/*
INPUT:
4 6
0 1 1 0 1 1
0 0 1 0 0 0
0 1 1 1 0 1
1 1 0 1 0 1

OUTPUT:
No of Islands are 3
No of recursions = 0
Final Array = 
0 8 8 0 8 8 
0 0 8 0 0 0 
0 8 8 8 0 8 
8 8 0 8 0 8 
*/