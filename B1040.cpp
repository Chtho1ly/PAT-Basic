//https://pintia.cn/problem-sets/994805260223102976/problems/994805282389999616
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    long long countP = 0;
    long long countPA = 0;
    long long countPAT = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'P')
        {
            countP++;
            countP %= 1000000007;
        }
        else if (s[i] == 'A')
        {
            countPA += countP;
            countPA %= 1000000007;
        }
        else if (s[i] == 'T')
        {
            countPAT += countPA;
            countPAT %= 1000000007;
        }
    }
    cout << countPAT << endl;
    return 0;
}