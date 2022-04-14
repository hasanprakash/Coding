#include <fstream>
#include <tuple>
using namespace std;
ifstream cin;
ofstream cout;

tuple<int, int> getFirstAndSecond(int arr[], int n, int k) {
    int first_max = arr[0], second_max = arr[0];
    for(int i=0;i<k;i++) {
        if(arr[i] > first_max) {
            second_max = first_max;
            first_max = arr[i];
        }
        else if(arr[i] > second_max) {
            second_max = arr[i];
        }
    }
    tuple<int, int> t = make_tuple(first_max, second_max);
    return t;
}

int main() {
    {
        cin.open("../input.txt");
        cout.open("../output.txt");
    }
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int k; cin >> k;
    tuple<int, int> firstAndSecond = getFirstAndSecond(arr, n, k);
    int first_max = get<0>(firstAndSecond);
    int second_max = get<0>(firstAndSecond);
    for(int i=0;i<n-k+1;i++) {
        if(arr[i] = first_max) {
            first_max = second_max
        }
    }
    return 0;
}