#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> arr,int a,int i,int b,int n,int m,vector<vector<vector<int>>> &dp){
    
    if(a<0 ||a>=m || b<0 || b>=m)
    return -1e8;
    if(dp[i][a][b]!=-1) return dp[i][a][b];
    if(i==n-1){
     if(a==b)
    return arr[n-1][a];
    else 
    return arr[n-1][a]+arr[n-1][b];
    }
    int maxi=INT_MIN,ans=0;
    for(int k=-1;k<=1;k++){
        for(int j=-1;j<=1;j++){
            if(a==b)
            ans=arr[i][a]+solve(arr,a+k,i+1,b+j,n,m,dp);
            else 
            ans=arr[i][a]+arr[i][b]+solve(arr,a+k,i+1,b+j,n,m,dp);

            maxi=max(maxi,ans);
        }
    }
    return dp[i][a][b]=maxi;

}

int main(){
    vector<vector<int>> arr{{1,5,3,2},{2,1,9,7},{7,3,6,2},{2,4,1,3}};
    
    int n=4,m=4;
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    int maxi=solve(arr,0,0,m-1,n,m,dp);
    cout<<maxi<<endl;
}

