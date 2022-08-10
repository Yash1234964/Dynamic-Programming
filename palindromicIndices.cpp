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
    string s;
    cin>>n>>s;
    lli  mid=n/2,ans=0,i=mid;
    char ch=s[mid];
    while(i<n && s[i]==ch  ){
        i++;ans++;
    }
        i=mid;
     while( i>=0 && s[i]==ch ){
        i--;ans++;
    }
    cout<<ans-1<<'\n';

        
    }
}