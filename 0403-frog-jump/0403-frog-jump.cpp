class Solution
{
public:
    bool canCross(vector<int> &s)
    {

        int n = s.size();
        //<pos, true/false>
        unordered_map<int, bool> v;
        for (auto e : s)
        {
            v[e] = false;
        }
        // <pos, v<jumps>
        unordered_map<int, unordered_set<int>> mpj;
        mpj[s[0]] = {0};
        v[s[0]] = true;
        int c = 1;
        for (auto i : s)
        {
            for (auto j : mpj[i])
            {
                for (int k = -1; k <= 1; k++)
                {
                    if (j + k > 0 && v.find(i + j + k) != v.end())
                    {
                        v[i + j + k] = true;
                        mpj[i + j + k].insert(j + k);
                    }
                }
            }
            c++;
        }
        return v[s[n - 1]];
    }
};