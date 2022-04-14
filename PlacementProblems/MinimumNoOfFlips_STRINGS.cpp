#include <fstream>
using namespace std;
ifstream cin;
ofstream cout;

string removeInitialZeros(string s) {
    int i = 0;
    while(i < s.size() && s[i] == '0') {
        i++;
    }
    return s.substr(i);
}
int theFinalProblem(string s) {
    int ans = 0;
    s = removeInitialZeros(s);
    // cout << s << endl;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != s[i-1]) {
            ans++;
        }
    }
    return ans + 1;
}
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    string s;
    cin >> s;
    cout << theFinalProblem(s) << endl;
}