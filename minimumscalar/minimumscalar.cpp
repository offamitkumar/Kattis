// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t; cin >> t; 
    for(int tt = 1; tt<=t; ++tt){
        cout <<"Case #"<<tt<<": ";
        int n; cin >> n; 
        vector<int64_t>a(n),b(n);
        for(auto&itr:a) cin>> itr; 
        for(auto&itr:b) cin>> itr; 
        sort(a.begin(),a.end());
        sort(b.begin(), b.end() , greater<int>());
//         for(auto&itr:a) cout << itr <<' '; 
//         cout << '\n'; 
//         for(auto&itr:b) cout << itr <<' ';; 
//         cout << '\n'; 
        int64_t counter{};
        for(int i=0;i<n;++i){
            counter += (a.at(i) * b.at(i));
        }
        cout << counter << '\n'; 
    }
    return 0;
}
