#include <fstream>
#include <queue>

using namespace std;
ifstream cin;
ofstream cout;

string arr[501];
int n;
queue<pair<int, int>> q;
int count = 0;

void printMatrix();
int countOnes();

void startBFS()
{
    while (!q.empty())
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
            return;
        while (nodeCount--)
        {
            auto f = q.front();
            int x = f.first;
            int y = f.second;
            // cout << "(" << x << ", " << y << ")" << endl;
            if (x - 1 >= 0 && arr[x - 1][y] == '1')
            {
                arr[x - 1][y] = '2';
                q.push(make_pair(x - 1, y));
            }
            if (x + 1 < n && arr[x + 1][y] == '1')
            {
                arr[x + 1][y] = '2';
                q.push(make_pair(x + 1, y));
            }
            if (y - 1 >= 0 && arr[x][y - 1] == '1')
            {
                arr[x][y - 1] = '2';
                q.push(make_pair(x, y - 1));
            }
            if (y + 1 < n && arr[x][y + 1] == '1')
            {
                arr[x][y + 1] = '2';
                q.push(make_pair(x, y + 1));
            }
            q.pop();
        }
        count++;
        // cout << endl;
    }
}

void initFill()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '2')
            {
                q.push(make_pair(i, j));
            }
        }
    }
}

int minLength(int n)
{
    initFill();
    startBFS();
    int noOfOnes = countOnes();
    return (noOfOnes == 0) ? (count - 1) : -1;
    // printMatrix();
}

int main()
{
    cin.open("../input.txt");
    cout.open("../output.txt");
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << minLength(n) << endl;
    }
}














void printMatrix()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int countOnes() {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '1')
            {
                count++;
            }
        }
    }
    return count;
}