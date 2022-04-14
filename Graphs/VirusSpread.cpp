#include <bits/stdc++.h>
using namespace std;
void printMatrix();
int countOnes();

int arr[1001][1001];
int r, c;

void floodFillHelper(int x, int y) {
    arr[x][y] = 2;
    if(x-1 >= 0 && arr[x-1][y] == 1 && arr[x-1][y] != 3) {
        floodFillHelper(x-1, y);
    }
    if(x+1 < r && arr[x+1][y] == 1 && arr[x-1][y] != 3) {
        floodFillHelper(x+1, y);
    }
    if(y-1 >= 0 && arr[x][y-1] == 1 && arr[x-1][y] != 3) {
        floodFillHelper(x, y-1);
    }
    if(y+1 < c && arr[x][y+1] == 1 && arr[x-1][y] != 3) {
        floodFillHelper(x, y+1);
    }
    if(x-1 >= 0 && y-1 >= 0 && arr[x-1][y-1] == 1 && arr[x-1][y] != 3) {
        floodFillHelper(x-1, y-1);
    }
    if(x-1 >=0 && y+1 < c && arr[x-1][y+1] == 1 && arr[x-1][y] != 3) {
        floodFillHelper(x-1,y+1);
    }
    if(x+1 < r && y-1 >= 0 && arr[x+1][y-1] == 1 && arr[x-1][y] != 3) {
        floodFillHelper(x+1, y-1);
    }
    if(x+1 < r && y+1 < c && arr[x+1][y+1] == 1 && arr[x-1][y] != 3) {
        floodFillHelper(x+1, y+1);
    }
}

void floodFill() {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(arr[i][j] == 3) {
                floodFillHelper(i, j);
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> arr[i][j];
        }
    }
    floodFill();
    // printMatrix();
    cout << countOnes() << endl;
    
}







int countOnes() {
    int count = 0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(arr[i][j] == 1)
            count++;
        }
    }
    return count;
}


// void printMatrix() {
//     for(int i=0;i<r;i++) {
//         for(int j=0;j<c;j++) {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }