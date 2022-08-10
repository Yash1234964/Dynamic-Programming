#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &points, int n,int last,vector<vector<int>>&arr){
    if(n==0){
        int maxi=0;
        if (arr[n][last]!=-1) return arr[n][last];
   for(int i=0;i<3;i++){
       if(i!=last){
      maxi=max(maxi,points[0][i]);
       }
   }
   
   return arr[n][last]=maxi;
    }
    if(arr[n][last]!=-1) return arr[n][last];
    int maxi=0;
    
    for(int i=0;i<3;i++){
        if(i!=last){
            int point=points[n][i]+solve(points,n-1,i,arr);
            maxi=max(maxi,point);
        }
    }
    return arr[n][last]=maxi;
}

int main(){
    vector<vector<int>> points={{2,1,3},{3,4,6},{10,1,6},{8,3,7}};
    int n=3;
    int tasks=3;
    vector<vector<int>> arr(n+1,vector<int>(tasks+1,-1));
     int maxi=solve(points,n,3,arr);
    cout<<maxi<<endl;
    for(auto i:arr){
        for(auto j:i)
        {
            cout<<j<<" ";
        }cout<<endl;
    }

}