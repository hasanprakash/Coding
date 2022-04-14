// Sum of GCD of all numbers upto N with N itself
// 9 March 2022  Wednesday
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
void printVector(vector<int> v1);
void printList(list<int> l1);
vector<int> v;
int finalAns = 0;
ifstream cin;
ofstream cout;
void findDivisors(int n)
{
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            v.push_back(i);
    // list<int> v1;
    // list<int> v2;
    // for (int i=1; i<=sqrt(n); i++)
    // {
    //     if (n%i == 0)
    //     {
    //         if (n/i == i)
    //             v1.push_back(i);
    //         else  {
    //             v1.push_back(i);
    //             v2.push_front(n/i);
    //         }
    //     }
    // }
    // // printList(v1);
    // // printList(v2);
    // v1.splice(v1.end(), v2);
    // copy(v1.begin(), v1.end(), back_inserter(v));
}
void findAns(int n) {
    int occupied = 0, totalActive = 0;
    for(int i=v.size()-1;i>=0;i--) {
        occupied += ((n/v[i]) - occupied);
        cout << "occupied = " << occupied << endl;
        totalActive = occupied - totalActive;
        finalAns += (totalActive * v[i]);
        cout << totalActive << endl;
        totalActive = occupied;
    }
}
int main()
{
    cin.open("../input.txt");
    cout.open("../output.txt");
    int n;
    cin >> n;
    findDivisors(n);
    findAns(n);
    cout << finalAns << endl;
    printVector(v);
}



void printVector(vector<int> v1) {
    for(int i=0;i<v1.size();i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
}
void printList(list<int> v1) {
    for(auto i: v1) {
        cout << i << " ";
    }
    cout << endl;
}


