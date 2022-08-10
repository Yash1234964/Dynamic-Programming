#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1="intention" , s2="execution";
    int l1=s1.length(),l2=s2.length();

    vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
       
       for(int i=0;i<=l1;i++) dp[i][0]=i;
       for(int i=0;i<=l2;i++) dp[0][i]=i;

       for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
               
               if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
               else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
               }
        }
       }
       cout<<dp[l1][l2]<<'\n';

       for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
       }
       
}