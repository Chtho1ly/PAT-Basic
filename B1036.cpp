//https://pintia.cn/problem-sets/994805260223102976/problems/994805285812551680
#include <iostream>

using namespace std;

int main()
{
    int num;
    char c;
    cin >> num >> c;
    for (int i = 1; i < num; i++)
    {
        if (i == 1 || i == num - 1)
        {
            for (int j = 0; j < num; j++)
                cout << c;
            cout << endl;
        }
        else
        {
            if (i % 2 == 1)
            {
                cout << c;
                for (int j = 1; j < num - 1; j++)
                    cout << " ";
                cout << c << endl;
            }
        }
    }
    return 0;
}