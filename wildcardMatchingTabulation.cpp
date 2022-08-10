#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1="ab*cd",s2="abdefcd";
    //  string s1="a?ay",s2="ray";
    int l1=s1.length(),l2=s2.length();
     vector<vector<bool>> dp(l1+1,vector<bool>(l2+1,false));
      dp[0][0]=true;
     for(int j=1;j<=l2;j++){
        dp[0][j]=false;
     }
       
     for(int i=1;i<=l1;i++){
    //     bool flag=true;
    //     for(int ii=1;ii<=i;ii++){
    //    if(s1[ii-1]!='*'){
    //     flag=false;
    //     break;
    //    }
    //     }
    if(s1[i-1]=='*')
       dp[i][0]=true;
     }

      for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1] || s1[i]=='?')
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else if(s1[i-1]=='*'){
                dp[i][j]=dp[i-1][j-1] || dp[i][j-1];
            }
            else dp[i][j]=false;
        }
      }
     
    cout<<dp[l1][l2]<<'\n';

}