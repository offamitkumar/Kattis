//  Author : Amit Kumar 
//  Date   : Friday 03 July 2020 10:00:58 AM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(void){
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    int64_t n; 
    while(cin >> n){
        if(n==0){
            cout<<0 << '\n'; 
            continue;
        }else if(n==1){
            cout << 1 << '\n'; 
            continue;
        }
        cout << 2ll * (n - 1ll) << '\n';
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
