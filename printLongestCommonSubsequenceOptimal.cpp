#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1="bdgek",s2="abcde";
    int l1=5,l2=5;

    vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));

    // for(int i=1;i<=l1;i++)
    // dp[i][0]=0;

    //  for(int j=1;j<=l2;j++)
    //  dp[0][j]=0;

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[l1][l2]<<'\n';
    int l=dp[l1][l2];
    string ans="";
    for(int i=0;i<l;i++)
    ans+='@';

    int index=l-1,i=l1,j=l2;

    while(i>0 && j>0){
        
        if(s1[i-1]==s2[j-1]){
            ans[index--]=s1[i-1];
            i--;j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else j--;

    }
    cout<<ans<<'\n';
}