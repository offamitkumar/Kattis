//  Author : Amit Kumar 
//  Date   : Friday 03 July 2020 02:37:47 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(void){
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    int64_t n; cin >> n; 
    int64_t fact=1;
    int64_t five{} , two{};
    for(int64_t i=2; i<=n; ++i){
        int64_t x = i; 
        while(x%5==0){
            five++;
            x/=5;
        }
        while(x%2==0){
            two++;
            x/=2;
        }
        fact = (fact * x) %1000;
    }
    int64_t counter = (two - five);
    while(counter--){
        fact = (fact * 2)%1000; 
    }
    if(n>6 && fact<100){
        if(fact<10){
            cout << "00"<<fact<<'\n';
        }else{
            cout << "0"<<fact<<'\n';
        }
    }else{
        cout <<fact << '\n'; 
    }


#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
