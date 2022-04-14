// 8/12/2021
#include <fstream>
#include <map>
using namespace std;
ifstream cin;
ofstream cout;

void printSubStrings(string s);
void printSubArray(int arr[], int n, int s);
int lengthOfLongestSubstring(string s); // With Unique Characters

int main() {
    {cin.open("../input.txt");
    cout.open("../output.txt");}
    
    string s; cin >> s; 
    printSubStrings(s);

    int arr[] = { 10, 20, 30, 40, 50 };
    printSubArray(arr, sizeof(arr)/sizeof(arr[0]), 1);

    lengthOfLongestSubstring(s);
    
    return  0;
}















void printSubStrings(string s) {
    // cout << "All SubStrings\n";
    for(int i=0;i<s.size();i++) {
        for(int j=i;j<s.length();j++) {
            // cout << s.substr(i, j-i+1) << endl;
        }
    }
    int l = s.size();
    // cout << "No of substrings " << l * (l+1)/2 << "\n\n" << endl;
}

void printSubArray(int arr[], int n, int s) {
    string str = "";
    for(int i=s;i<n;i++) {
        str += to_string(arr[i]) + ", ";
        // cout << str << endl;
    }
}

int lengthOfLongestSubstring(string s) {
    int l = s.length();
    map<char, int> mp;
    int length = 0;
    for(int i=0;i<l;i++) {
        if(mp[s[i]] == 0) {
            mp[s[i]]++;
            length++;
        }
        else {
            length = 1;
            mp.clear();
        }
        cout << length << endl;
    }
    return 0;
}