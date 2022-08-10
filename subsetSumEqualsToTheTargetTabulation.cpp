#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,3,4};
    int n=4;
    int target=7;
    vector<vector<bool>> dp(n,vector<bool>(target+1,false));
    for(int i=0;i<n;i++){
        dp[i][0] =true;
    }
    if(arr[0]<=target)
        dp[0][arr[0]]=true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
               bool notTaken=dp[i-1][j];
                  
               bool taken=false;   
               if(arr[i]<=j)
               taken=dp[i-1][j-arr[i]];

               dp[i][j]=taken||notTaken;
            }

        }
        if(dp[n-1][target]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        for(auto i:dp){
            for(auto j:i){
                cout<<j<<" ";
            }cout<<endl;
        }
    }

