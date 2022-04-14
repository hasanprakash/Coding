#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;
int total(vector<int> v, int i, int j) {
    int sum = 0;
    for(int k = i; k<=j;k++) {
        sum += v[k];
    }
    return sum;
}
int maximumNetworks(vector<int> speed, int minComps, int speedThreshold) {
    int n = speed.size();
    int i = 0;
    int j = i + minComps - 1;
    int ans = 0;
    while(i < n && j < n) {
        int sum = total(speed, i, j);
        cout << "SUM = " << sum << endl;
        while(sum < speedThreshold) {
            j++;
            sum += speed[j];
        }
        cout << i << " " << j << endl;
        i = j + 1;
        j = i + minComps - 1;
        ans++;
    }
    return ans;
}
int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    int minComps;
    cin >> minComps;
    int speedThreshold;
    cin >> speedThreshold;
    cout << maximumNetworks(v, minComps, speedThreshold);
}