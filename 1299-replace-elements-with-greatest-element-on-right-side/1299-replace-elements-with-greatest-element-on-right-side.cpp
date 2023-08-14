class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        s.push(arr[n-1]);
        arr[n-1] = -1;
        for(int i=n-2; i>=0 ; i--){
            int x = arr[i];
            arr[i] = s.top();
            while(s.size()>0 && s.top()<x){
                s.pop();
            }
            if(s.size()==0)  
                s.push(x);
            else if(x>s.top())s.push(x);
        }
        return arr;
    }
};