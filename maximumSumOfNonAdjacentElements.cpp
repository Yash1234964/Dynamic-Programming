#include<bits/stdc++.h>
using namespace std;

int utility(int idx,int arr[],vector<int>& dp){
if(idx==0) return arr[0];
if(idx<0) return 0;
if(dp[idx]!=-1)
return dp[idx];
 
 int pick=arr[idx]+utility(idx-2,arr,dp);
int nonPick=utility(idx-1,arr,dp);

return dp[idx]=max(pick,nonPick);
}
int main(){
    int arr[]={2,1,4,9};
    int n=4;
    vector<int> dp(n,-1);
    cout<<utility(n-1,arr,dp)<<endl;
    for(int i:dp)
    cout<<i<<" ";
    cout<<endl;

}