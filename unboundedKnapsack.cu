#include <bits/stdc++.h>

using namespace std;

/* 
 * HackerRank Problem Solving(Intermediate).
 * Dynamic Programming approach with Recursion.
 * 11/11 tests accepted.
 * Time Complexity O(k*n), Space Complexity O(n+k).
 * Pretty common problem uhuh@@
 */

int unboundedKnapsack(int k, vector<int> arr, vector<int> memoi) {
    
    if(memoi[k]!=-1) return memoi[k];
    if(k==0) return 0;
    
    int ret=0;
    int temp=0;
    
    for(size_t i=0; i<arr.size(); ++i){
        if(k>=arr[i]){
            temp=unboundedKnapsack(k-arr[i],arr,memoi)+arr[i];
        }
        if(temp==k){
            memoi[k]=k;
            return k;
        }
        if (temp>ret){
            ret=temp;
        }
    }
    
    memoi[k]=ret;
        
    return ret;
}

int main(){
        
    int t=0,n=0,k=0;
    cin>>t;
    
    for(int x=0; x<t; ++x){
        cin>>n>>k;
        
        vector<int> arr(n);
        vector<int> memoi(k+1,-1); //Use a memoization technique with a vector
        
        for(int j=0; j<n; ++j){
            cin>>arr[j];
        }
        
        cout<<unboundedKnapsack(k,arr,memoi)<<'\n';
    }
    return 0;
}