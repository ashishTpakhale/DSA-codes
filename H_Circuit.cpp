#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int c[9];
    for(int i=0;i<9;i++){
        c[i]=ceil((double(a)*b*(i+1))/10.0);
    }
    for(int i=0;i<9;i++){
        cout<<c[i]<<" ";
    }
}