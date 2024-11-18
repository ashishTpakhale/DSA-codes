#include <bits/stdc++.h>
using namespace std;

map<long long, bool> pre_comp;

bool check(long long n) {
    string s = to_string(n);
    for (int i = 0; i < s.size(); ++i) {
        int digit = s[i] - '0';
        if ((i+1)% 2==0) { 
            if (digit%2 !=0) 
                return false;
        } else {
            if (digit % 2==0) 
                return false;
        }
    }
    return true;
}

void valid(long long limit) {
    for (long long i = 1; i <= limit; ++i) {
        if (check(i)) {
            pre_comp[i] = true;
        }
    }
}

int main() {
    long long n;
    cin >> n;
    long long limit = min(n, (long long)1e6);
    valid(limit);
    long long c = 0;
    for (long long i = 1; i <= n; ++i) {
        if (i <= limit) {
            if (pre_comp[i]) {
                c++;
            }
        } else {
            if (check(i)) {
                c++;
            }
        }
    }
    
    cout << c << endl;
}
