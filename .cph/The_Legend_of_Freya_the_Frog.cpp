#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long x,y,k;
        cin>>x>>y>>k;
        long long count=0;
        if(x>=k && y>=k){
            count+=x/k + y/k;
        }
        else if(x<k && y>=k){
            count+=( y/k )*2 ;
        }
        else if(y<k && x>=k){
            count+=( x/k )*2 ;
        }
        long long xr=x%k;
        long long yr=y%k;
        if(count%2==0){
            if( (yr>0 && xr>=0 ))
            count+=2;
            else if(yr==0 && xr>0)
            count+=1;
        }else{
            if( (yr>0 && xr>=0 ))
            count+=1;
            else if(yr==0 && xr>0)
            count+=2;
        }
        cout<<count<<endl;
    }
}