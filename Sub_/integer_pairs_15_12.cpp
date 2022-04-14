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
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int targetsum = 9;
    int c = 0;
    int getToTarget = 0;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i] < arr[j])
            c++;
            if(arr[i]+arr[j] == targetsum)
            getToTarget++;
            cout << arr[i] << " " << arr[j] << endl;
        }
    }
    cout << "Total Count = " << n * (n-1) / 2 << endl;
    cout << "First element is less than second element is " << c << "\n";
    cout << "Total pairs that get sum is equal to target is " << getToTarget << "\n";
}