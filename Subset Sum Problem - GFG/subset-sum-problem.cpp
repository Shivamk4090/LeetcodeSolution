//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<vector<int>> mp;
    bool sol(vector<int> v, int s, int i){
        
        if(s==0) return true;
        if(s<0 || i>=v.size()) return false;
        
        if(mp[i][s] != -1) return mp[i][s];
        
        if(v[i]>s) 
            mp[i][s] =  sol(v, s, i+1);
        else
            mp[i][s] =  sol(v, s-v[i], i+1) || sol(v, s, i+1);
            
        return mp[i][s];
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        mp.resize(arr.size(), vector<int>(sum+1, -1));
        return sol(arr, sum, 0);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends