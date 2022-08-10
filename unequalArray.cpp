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

    for(lli i=0;i<n;i++)
    cin>>arr[i];

    lli mn=-1,mx=-1;
    for(lli i=0;i<n-1;i++)
    if(arr[i]==arr[i+1]){
        if(mn==-1) mn=i;
        mx=i;
    }
    if(mn==mx) cout<<0<<endl;
    else cout<<max(1ll,mx-mn-1)<<endl;

        
    }
}