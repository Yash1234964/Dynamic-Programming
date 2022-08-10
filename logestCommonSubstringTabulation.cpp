#include<bits/stdc++.h>
using namespace std;

int main(){

    string s1="abcd",s2="abzd";
    int l1=4,l2=4;

    vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
    int ans=0;
    for(int i=1;i<=l1;i++){
        for( int j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    cout<<ans<<'\n';

}