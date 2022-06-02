// Kadanes algorithm is also known as max sub array sum.

#include <fstream>
#include <limits.h>
using namespace std;
ifstream cin;
ofstream cout;

long long maxSubarraySum(int arr[], int n){    
    long long maxi = INT_MIN;
    long long sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}

int main() {
    cin.open("../../input.txt");
    cout.open("../../output.txt");
    int n; cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    cout << maxSubarraySum(arr, n);
}