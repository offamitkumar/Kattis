//  Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(void){
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    int x , y; cin >> x >> y; 
    if(y&1){
        cout << "impossible" << '\n'; 
    }else{
        cout << "possible" << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
