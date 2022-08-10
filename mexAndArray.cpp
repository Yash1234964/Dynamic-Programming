#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> plli;
typedef vector<long long int> vlli;
typedef vector<string> vst;
typedef map<lli,lli> mlli;
typedef set<lli> slli;
typedef unordered_set<lli> uslli;
int main(){
    
    int t=0;
cin>>t;
    while(t--){
    lli n;
    cin>>n;
    vlli arr(n);
    for(auto &i:arr)
    cin>>i;

    lli ans=0;
    for( lli i=0;i<n;i++){
        ans+=(i+1)*(n-i);
        if(arr[i]==0)
        ans+=(i+1)*(n-i);
    }
    cout<<ans<<"\n";
    }

}