// rotating the matrix without any extra space
// reference: https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
int arr[100][100];
void printRotateMatrix(int r, int c) {
    for(int j=0;j<c;j++) {
        for(int i=r-1;i>=0;i--) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rotateMatrixWithoutExtraSpace() {
    // rotating matrix
}

int main() {
    cin.open("../../input.txt");
    cout.open("../../output.txt");
    int r, c; cin >> r >> c;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> arr[i][j];
        }
    }
    printRotateMatrix(r, c);
    rotateMatrixWithoutExtraSpace();
}