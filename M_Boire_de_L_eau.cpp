#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vec vector<ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define F(i, n) for (ll i = 0; i < n; i++)
#define RF(i, n) for (ll i = n - 1; i >= 0; i--)
#define mod 1000000007
#define nl "\n"
#define YES cout << "YES\n"
#define NO cout << "NO"
#define mod 1000000007

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> v(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    ll target = ceil(sum/double(m));
    vector<ll> parts;
    int curr_sum=0;
    for(int i=0;i<n;i++){
        if(curr_sum+v[i] > target){
            parts.pb(curr_sum);
            curr_sum = 0;
        }
        curr_sum += v[i];
    }
    ll maxi = *max_element(parts.begin(),parts.end());
    ll hours = (maxi/k) + (maxi%k ?  1 : 0);
    cout<<hours<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}