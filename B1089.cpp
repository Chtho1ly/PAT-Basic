//https://pintia.cn/problem-sets/994805260223102976/problems/1038429385296453632
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<int> tab(num + 1);
    vector<int> identity(num + 1);
    vector<int> lying;
    vector<int> wolf;
    vector<int> ans;
    for (int i = 1; i < num + 1; i++)
        cin >> tab[i];
    for (int i = 1; i < num + 1; i++)
        for (int j = i + 1; j < num + 1; j++)
        {
            //假设i,j撒谎
            tab[i] = -tab[i];
            tab[j] = -tab[j];

            for (int k = 1; k < num + 1; k++)
                identity[k] = 0;
            for (int k = 1; k < num + 1; k++)
            {
                if (identity[abs(tab[k])] == 0)
                {
                    int id = tab[k] / abs(tab[k]);
                    identity[abs(tab[k])] = id;
                    if (id == -1)
                        wolf.push_back(abs(tab[k]));
                }
                else if (identity[abs(tab[i])] != tab[i] / abs(tab[i]))
                    break;
            }

            if (wolf.size() == 2)
            {
                if ((i == wolf[0] && j != wolf[1]) || (i != wolf[0] && j == wolf[1]) || (i == wolf[1] && j != wolf[0]) || (i != wolf[1] && j == wolf[0]))
                    if (ans.size() == 0 || wolf[0] < ans[0] || (wolf[0] == ans[0] && wolf[1] < ans[1]))
                        ans = wolf;
            }
            else
            {
                vector<int> noId;
                for (int k = 1; k < num + 1; k++)
                {
                    if (identity[k] == 0)
                        noId.push_back(k);
                }
                if (wolf.size() < 2 && wolf.size() + noId.size() >= 2)
                {
                    if (wolf.size() == 0)
                    {
                        for (int m = 0; m < noId.size(); m++)
                        {
                            vector<int> newWolf;
                            newWolf.push_back(noId[m]);
                            for (int n = m + 1; n < noId.size(); n++)
                            {
                                newWolf.push_back(noId[n]);

                                if ((i == newWolf[0] && j != newWolf[1]) || (i != newWolf[0] && j == newWolf[1]) || (i == newWolf[1] && j != newWolf[0]) || (i != newWolf[1] && j == newWolf[0]))
                                    if (ans.size() == 0 || newWolf[0] < ans[0] || (newWolf[0] == ans[0] && newWolf[1] < ans[1]))
                                        ans = newWolf;
                                newWolf.pop_back();
                            }
                            newWolf.pop_back();
                        }
                    }
                    if (wolf.size() == 1)
                    {
                        for (int m = 0; m < noId.size(); m++)
                        {
                            vector<int> newWolf(wolf);
                            newWolf.push_back(noId[m]);
                            sort(newWolf.begin(), newWolf.end());
                            if ((i == newWolf[0] && j != newWolf[1]) || (i != newWolf[0] && j == newWolf[1]) || (i == newWolf[1] && j != newWolf[0]) || (i != newWolf[1] && j == newWolf[0]))
                                if (ans.size() == 0 || newWolf[0] < ans[0] || (newWolf[0] == ans[0] && newWolf[1] < ans[1]))
                                    ans = newWolf;
                        }
                    }
                }
            }

            //恢复
            wolf.clear();
            tab[i] = -tab[i];
            tab[j] = -tab[j];
        }
    if (ans.empty())
        cout << "No Solution" << endl;
    else
        cout << ans[0] << " " << ans[1] << endl;
    return 0;
}