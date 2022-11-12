class Solution {
public:
    int findNthDigit(int t) {
        
        if(t<=9) return t;
        long long  n = t;
        long long temp  = n;
        long long i = 1;
        long x = 1;
        long long count = 0;
        while(n>0){
            n = n - 9*i*x;
            if(n>0){
                count = count + (9*i*x);
            }
            x *= 10;
            i++;
        }
        long long idx = i-1;
        long long rest  =  temp-count;
        long long num = pow(10, idx-1)-1 + (rest/idx);
        string ss = "";
        long long rem = rest%idx;
        if(rem>0){
            num++;
            ss = to_string(num);
            return ss[rem-1]-48;
        }
        ss = to_string(num);
        return ss[ss.size()-1]-48;
        
    }
};