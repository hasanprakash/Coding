#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if(a == 0)
                arr[i][j] = INT_MAX;
            else
                arr[i][j] = a;
        }
    }

    // Floyd Warshall Algorithm
    

    // floyed warshel
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][k] + arr[k][j] < arr[i][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    

}