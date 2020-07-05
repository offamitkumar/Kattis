//  Author : Amit Kumar 
//  Date   : Sunday 05 July 2020 05:06:40 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(void){
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    vector<int>v(9); 
    for(auto&itr:v)cin >> itr; 
    int x = accumulate(v.begin() , v.end() , 0ll);
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(i==j){
                continue;
            }
            if(x-(v.at(i)+v.at(j))==100){
                for(int k=0;k<9;++k){
                    if(k==i || k==j)continue;
                    cout << v.at(k) << '\n'; 
                }
                return 0;
            }
        }
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
