class Solution
{

public:
    vector<string> vec;
    vector<string> ans;
    void solve(string s, string x)
    {
        if (s.size() == 0)
        {
            ans.push_back(x);
            return;
        }
        int i = stoi(s.substr(0, 1)) - 2;
        for (int j = 0; j < vec[i].size(); j++)
        {
            x += vec[i][j];
            solve(s.substr(1), x);
            x.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return ans;
        vec = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, "");
        return ans;
    }
};