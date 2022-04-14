// Count of Same Adjacent Charaters

#include <fstream>
#include <vector>
using namespace std;
ifstream cin;
ofstream cout;
int main()
{
    cin.open("../input.txt");
    cout.open("../output.txt");
    string s;
    cin >> s;
    vector<string> v;
    int wendy = 0;
    int bob = 0;
    int n = s.size();
    int wtemp = 0;
    int btemp = 0;
    if(s[0] == 'w') {
        wtemp = 1;
    }
    else {
        btemp = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'w' && s[i - 1] == 'w')
        {
            wtemp++;
        }
        else if (s[i] == 'b' && s[i - 1] == 'b')
        {
            btemp++;
        }
        else if (s[i] == 'w' && s[i - 1] == 'b')
        {
            cout << wtemp << " " << btemp << endl;
            if (btemp > 2)
            {
                bob += (btemp - 2);
            }
            wtemp = 1;
            btemp = 0;
        }
        else if (s[i] == 'b' && s[i - 1] == 'w')
        {
            cout << wtemp << " " << btemp << endl;
            if (wtemp > 2)
            {
                wendy += (wtemp - 2);
            }
            wtemp = 0;
            btemp = 1;
        }
        
    }
    cout << wtemp << " " << btemp << endl;
    if (wtemp > 2)
    {
        wendy += (wtemp - 2);
    }
    if (btemp > 2)
    {
        bob += (btemp - 2);
    }
    // cout << wendy << " " << bob << endl;
    if(wendy <= bob)
    {
        cout << "wendy" << endl;
    }
    else
    {
        cout << "bob" << endl;
    }
}

/**
 * @brief 
 * INPUT:
 * wwwwwwbwbbbbbwww
 * OUTPUT:
 * wendy
 * 
 */