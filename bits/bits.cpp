//  Author : Amit Kumar 
//  Date   : Sunday 05 July 2020 05:00:18 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(void){
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n ;
        int counter{};
        while(n){
            counter = max(counter ,int(__builtin_popcount(n)));
            n/=10;
        }
        cout << counter << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
