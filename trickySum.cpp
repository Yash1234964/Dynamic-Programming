#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> plli;
typedef vector<long long int> vlli;
typedef vector<string> vst;
typedef map<lli,lli> mlli;
typedef set<lli> slli;
typedef unordered_set<lli> uslli;
const lli inf =1e9 + 10;
const lli INF=1e18 + 10;
int main(){
    
    int t=0;
cin>>t;
    while(t--){
    lli n;
    cin>>n;
    lli sum=(n*(n+1))/2;
    sum-=1;   
    for(lli i=2;i<=n;i*=2){
          sum-=(2*i); 
    }

    cout<<sum-1<<'\n';
        
    }
}