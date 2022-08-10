#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,2,3};
    int n=4,target=3;
    vector<vector<int>> dp(n,vector<int>(target+1,0));

    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int notTake=dp[i-1][j];
            int take=0;
            if(arr[i]<=j) take=dp[i-1][j-arr[i]];

            dp[i][j]=take+notTake;


        }
    }
        cout<<dp[n-1][target]<<endl;
        for(auto i:dp)
        {
            for(auto j:i)
            cout<<j<<" ";
            cout<<endl;
        }
    
    


}