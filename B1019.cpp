//https://pintia.cn/problem-sets/994805260223102976/problems/994805302786899968
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int num;
    cin >> num;
    while (true)
    {
        string a = to_string(num);
        while (a.size() < 4)
            a.insert(a.begin(), '0');
        sort(a.begin(), a.end());
        string b(a);
        reverse(b.begin(), b.end());
        num = stod(b) - stod(a);
        cout << b << " - " << a << " = ";
        printf("%04d\n", num);
        if (num == 0)
            break;
        if (num == 6174)
            break;
    }
    return 0;
}