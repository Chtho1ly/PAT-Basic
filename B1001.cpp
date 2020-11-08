//https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    while (n != 1)
    {
        if (n % 2 == 1)
            n = (3 * n + 1) / 2;
        else
            n = n / 2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
