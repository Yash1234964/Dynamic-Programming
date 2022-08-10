#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &arr,int i,int j,int n,vector<vector<int>> &dp){
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(i==n-1)
    return arr[n-1][j];
    
    int dsum=arr[i][j]+solve(arr,i+1,j,n,dp);
    int disum=arr[i][j]+solve(arr,i+1,j+1,n,dp);

    return dp[i][j]=min(dsum,disum);

}
int main(){
    vector<vector<int>> arr{{1},{2,3},{3,6,7},{8,9,6,10}};
    vector<vector<int>> dp(4,vector<int>(4,-1)); //hard coded size= 4;
    int m=solve(arr,0,0,4,dp);
    
    for(auto i:dp){
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }

    cout<<m<<endl;
}