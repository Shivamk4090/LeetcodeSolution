//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The functions which 
builds the segment tree */
void build(int arr[], int s, int e, int tree[], int index){
    if(s==e){
        tree[index] =  arr[s];
        return;
    }
    int mid  =  (s+e)/2;
    build(arr, s, mid, tree, 2*index);
    build(arr, mid+1, e, tree, 2*index+1);
    tree[index] =  min(tree[2*index] ,tree[2*index+1]);
}
int *constructST(int arr[],int n)
{
    
  int * tree  = new int[4*n+1];
  build(arr, 0, n-1, tree, 1);
  return tree;

}


/* The functions returns the
 min element in the range
 from a and b */
int query(int tree[], int s, int e, int index, int a, int b){
    if(e<a || s>b){
        return INT_MAX;
    }
    
    if(s>=a && e<=b){
        return tree[index];
    }
    

    int mid = (s+e)/2;
    int ans1 = query(tree, s, mid,  index*2, a, b);
    int ans2 = query(tree, mid+1, e,  index*2+1, a, b);
    return min(ans1, ans2);
}
int RMQ(int st[] , int n, int a, int b)
{
    //Your code here
    return query(st, 0, n-1, 1, a, b);
    
    
}