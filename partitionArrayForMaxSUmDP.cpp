#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr,int idx,int n,int k,vector<int> &dp){
    if(idx==n) return 0;
    if(dp[idx]!=-1) return dp[idx];

    int maxi=INT_MIN,l=0,maxCost=INT_MIN;

    for(int i=idx;i<min(idx+k,n);i++){

        l++;
        maxi=max(maxi,arr[i]);
        int sum=(l*maxi)+solve(arr,i+1,n,k,dp);
        maxCost=max(maxCost,sum);
    }
    return dp[idx]=maxCost;

}

int main(){
    vector<int>arr={1,15,7,9,2,5,10};
    int n=arr.size(),k=3;
    vector<int> dp(n,-1);
    cout<<solve(arr,0,n,k,dp)<<'\n';
}