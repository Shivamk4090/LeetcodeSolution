class Solution
{
public:
    bool canCross(vector<int> &s)
    {
        int n = s.size();
        vector<int> mem(n, false);
        vector<unordered_set<int>> mpj(n);
        mpj[0] = {0};
        mem[0] = true;
        int c = 0;
        for (auto i : s){
            for (auto j : mpj[c]){
                for (int k = -1; k <= 1; k++){
                    if (j + k > 0 && binary_search(s.begin(), s.end(), i+j+k)){
                        int idx = lower_bound(s.begin(), s.end(), i+j+k) - s.begin();
                        mem[idx] = true;
                        mpj[idx].insert(j + k);
                    }
                }
            }
            c++;
        }
        return mem[n-1];
    }
};