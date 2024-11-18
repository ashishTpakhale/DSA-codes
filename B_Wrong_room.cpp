#include<bits/stdc++.h>
using  namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int flag=0;
    for(int i = 0; i < n; i++)  {
        cin>>a[i];
        int abel = a[0];
        if(a[i]>abel && i!=0){
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<"N";
    else
        cout<<"S";
}
