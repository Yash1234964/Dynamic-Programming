#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(string &str,int i,int j,int isTrue,vector<vector<vector<ll>>>&dp){

    if(i>j) return 0;

    if(i==j){
        if(isTrue) return str[i]=='T';
        else return str[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
     ll ways=0;
    for(int idx=i+1;idx<=j-1;idx+=2){
    
        ll lt=solve(str,i,idx-1,1,dp);
        ll lf=solve(str,i,idx-1,0,dp);
        ll rt=solve(str,idx+1,j,1,dp);
        ll rf=solve(str,idx+1,j,0,dp);

        if(str[idx]=='&'){
          if(isTrue)
          ways=ways+(lt*rt);
          else
          ways=ways+(rt*lf)+(lt*rf)+(rf*lf);
        
        }
        else if(str[idx]=='|'){
            if(isTrue)
            ways=ways+(lt*rf)+(lf*rt)+(lt*rt);
            else
            ways=ways+(lf*rf);

        }
        else{
            if(isTrue) ways=ways+(lt*rf)+(lf*rt);
            else ways=ways+(lt*rt)+(lf*rf);
        
        }
    }
    return ways;

}

int main(){
    string str="F|T^F";
    int n=str.size();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
        cout<<solve(str,0,n-1,1,dp);
    
}