#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;
int main() {
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }
        
    }
    return 0;
}