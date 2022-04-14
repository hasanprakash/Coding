#include <bits/stdc++.h>
using namespace std;

// WITH RECUURSION
bool isPalindrome(string s, int i, int j) {
    if(s[i] != s[j])
    return false;
    else {
        isPalindrome(s, i+1, j-1);
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << isPalindrome(s, 0, s.size()-1) << endl;

    // WITH ITERATIONS
    // int i = 0, j = n - 1;
    // while (i < j) {
    //     if (s[i] != s[j]) {
    //         cout << "NO";
    //         return 0;
    //     }
    //     i++;
    //     j--;
    // }
    // cout << "YES";
    // return 0;
}