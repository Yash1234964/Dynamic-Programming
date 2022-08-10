#include<bits/stdc++.h>
using namespace std;

bool solve(int *arr,int n,vector<vector<int>> &dp,int target){
    if(target==0)
    return true;

    if(n==0) return arr[n]==target;

    if(dp[n][target]!=-1) return dp[n][target];
    
    bool notTake = solve(arr,n-1,dp,target);

    bool take=false;
    if(target>=arr[n])
    take = solve(arr,n-1,dp,target-arr[n]);

    return dp[n][target]= take || notTake;
    

}
int main(){
    int arr[]={3,2,7};
    int n=3;
    int maxi=0;
    for(auto i:arr){
        maxi+=i;
    }
    vector<vector<int>> dp(n,vector<int>(maxi+1,-1));
    for(int i=0;i<=maxi;i++)
    solve(arr,n-1,dp,i);

    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }

    vector<int> arr1(maxi+1,-1);
      int mini=INT_MAX;
    for(int i=0;i<=maxi;i++){
        if(dp[n-1][i] == 1){
            int temp=maxi-i;
        mini=min(mini,abs(i-temp));
        }
    }
    cout<<mini<<endl;


}