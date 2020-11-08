//https://pintia.cn/problem-sets/994805260223102976/problems/994805275146436608
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    int N;
    int m, n;
    cin >> N;
    for (m = 1; m <= sqrt(N); m++)
    {
        if (N % m == 0)
            n = N / m;
    }
    m = n;
    n = N / m;

    vector<vector<int>> maxtrix(m);
    vector<int> num(N);
    for (int i = 0; i < m; i++)
        maxtrix[i].insert(maxtrix[i].begin(), n, -1);
    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num.begin(), num.end());
    int x, y;
    x = 0, y = 0;
    int direction = 1;
    while (!num.empty())
    {
        if (direction == 1) //right
        {
            while (true)
            {
                maxtrix[x][y] = num.back();
                num.pop_back();
                if (y + 1 >= n || maxtrix[x][y + 1] != -1)
                    break;
                y++;
            }
            if (num.empty())
                break;
            direction = 2;
            x++;
        }
        if (direction == 2) //down
        {
            while (true)
            {
                maxtrix[x][y] = num.back();
                num.pop_back();
                if (x + 1 >= m || maxtrix[x + 1][y] != -1)
                    break;
                x++;
            }
            if (num.empty())
                break;
            direction = 3;
            y--;
        }
        if (direction == 3) //left
        {
            while (true)
            {
                maxtrix[x][y] = num.back();
                num.pop_back();
                if (y - 1 < 0 || maxtrix[x][y - 1] != -1)
                    break;
                y--;
            }
            if (num.empty())
                break;
            direction = 4;
            x--;
        }
        if (direction == 4) //up
        {
            while (true)
            {
                maxtrix[x][y] = num.back();
                num.pop_back();
                if (x - 1 < 0 || maxtrix[x - 1][y] != -1)
                    break;
                x--;
            }
            if (num.empty())
                break;
            direction = 1;
            y++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << maxtrix[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}