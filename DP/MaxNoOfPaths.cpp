// 21 FEB 2022 - MONDAY
// Diagonals not allowed
#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
int R = 100;
int C = 100;
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");


    int r, c;
    cin >> r >> c;
    int dp[r][c];
    int arr[r][c];
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            dp[i][j] = 0;
            cin >> arr[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(arr[i][j] == 1) {
                if(i-1 >= 0 && j-1 >= 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else if(i-1 >= 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else if(j-1 >= 0) {
                    cout << i << " " << j << endl;
                    dp[i][j] = dp[i][j-1];
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    // print matrix
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    




    cin.close();
    cout.close();
    return 0;
}









/*
INPUT:
4 4
1 1 0 1
1 1 1 0
0 0 1 1
1 1 1 1
*/