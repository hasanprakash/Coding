/*
Given Few Number of Pairs, We have to find No Of Groups
(Indirect relation is also part of the group)
it's a graph problem can also be solved with disjoint set
8th March 2022   Tuesday
*/
#include <fstream>
#include <vector>
using namespace std;
void printArray();
ifstream cin;
ofstream cout;

int main() {
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n;
    cin >> n;
    vector<pair<char, char>> v;
    for(int i=0;i<n;i++) {
        char a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

}






void printArray() {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



/*
INPUT:
4 6
0 1 1 0 1 1
0 0 1 0 0 0
0 1 1 1 0 1
1 1 0 1 0 1

OUTPUT:
No of Islands are 3
No of recursions = 0
Final Array = 
0 8 8 0 8 8 
0 0 8 0 0 0 
0 8 8 8 0 8 
8 8 0 8 0 8 
*/