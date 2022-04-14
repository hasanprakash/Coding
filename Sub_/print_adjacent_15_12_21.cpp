#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
int main() {
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }
    int n;cin >> n;
    char a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    for(int i=0;i<n-k+1;i++) {
        for(int j=i;j<i+k;j++) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
    return 0;
}