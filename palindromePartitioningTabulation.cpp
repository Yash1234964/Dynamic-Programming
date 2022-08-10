#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i,int j,string str){
    while(i<j){
        if(str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main(){
    string str="bababcbadcede";
    int n=str.size();
    vector<int> dp(n+1,0);
    
    for(int i=n-1;i>=0;i--){
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
        if(isPalindrome(i,j,str)){
        int cost=1+dp[j+1];

        mini=min(mini,cost);
        }
        }
        dp[i]=mini;
    }
    cout<<dp[0]-1<<'\n';
}