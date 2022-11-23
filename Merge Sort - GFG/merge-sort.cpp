//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
         // Your code here
 
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            // merge(arr, l, mid, r);
            int* ans =  new int[r-l+1];
            int i = l, j = mid+1;
            int p = 0;
            while(i<=mid && j<=r){
                if(arr[i]<=arr[j]){
                    ans[p]= arr[i];
                    i++;
                    p++;
                }else{
                    ans[p]= arr[j];
                    j++;
                    p++;
                }
            }
            while(i<=mid){
                ans[p] = arr[i];
                i++;
                p++;
            }
            while(j<=r){
                ans[p] = arr[j];
                j++;
                p++;
            }
            
            for(int i=0;i<r-l+1;i++){
                arr[l+i] = ans[i];
            }
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends