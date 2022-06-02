// first and last occurance of x
#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;

int binarySearch(int arr[], int n, int x, string direction) {
    int l = 0, r = n;
    int index = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(direction == "right") {
            if(arr[mid] <= x) {
                l = mid + 1;
            } else if(arr[mid] > x) {
                r = mid-1;
            }
            if(arr[mid] == x)
                index = mid;
        }
        else {
            if(arr[mid] < x) {
                l = mid + 1;
            } else if(arr[mid] >= x) {
                r = mid-1;
            }   
            if(arr[mid] == x)
                index = mid;
        }
    }
    return index;
}

int main() {
    cin.open("../../input.txt");
    cout.open("../../output.txt");
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    cout << binarySearch(arr, n-1, key, "left") << 
        " " << binarySearch(arr, n-1, key, "right") << endl;
}

// github copilot: it's microsoft and github's official artificial intelligent auto complete ai programmer.