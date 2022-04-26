// 15th April 2022
// Finding Max Sum of Subarray in an array using Kadane's Algorithm
#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;

int maxSumSubArray(int arr[], int n) {
    int maxSum = INT_MIN;
    int currSum = 0;
    for(int i = 0; i < n; i++) {
        currSum += arr[i];
        if(currSum > maxSum) {
            maxSum = currSum;
        }
        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int main() {
    cin.open("../../input.txt");
    cout.open("../../output.txt");
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxSumSubArray(arr, n) << endl;
    
}

/*
    INPUT:
    4
    -2 -3 -4 -5
    OUTPUT:
    -2
*/