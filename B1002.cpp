//https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    string zidian[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (size_t i = 0; i < s.size(); i++)
        sum += s[i] - '0';
    vector<string> pinyin;
    while (sum != 0)
    {
        int remain = sum % 10;
        sum = sum / 10;
        pinyin.push_back(zidian[remain]);
    }
    while (!pinyin.empty())
    {
        cout << pinyin.back();
        pinyin.pop_back();
        if (!pinyin.empty())
            cout << " ";
    }
    cout << endl;
    return 0;
}
