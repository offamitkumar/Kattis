//  Author : Amit Kumar 
//  Date   : Friday 03 July 2020 11:07:33 AM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(void){
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int n; 
    int tt = 1;
    while(cin >> n){
        cout << "Case "<<tt++<<": "<<'\n'; 
        vector<int>v(n);
        for(auto&itr:v){
            cin >> itr;
        }
        int q; 
        cin >> q; 
        while(q--){
            int x; cin >> x; 
            cout <<"Closest sum to "<< x<<" is "; 
            int temp{INT_MAX};
            int best_sum{};
            for(int i=0;i<n;++i){
                for(int j=0;j<n; ++j){
                    if(i==j){continue;}
                    if(x < 0){
                        if(abs(abs(x) - abs(v[i]+v[j])) < temp){
                            temp = abs(abs(x) - (v[i]+v[j]));
                            best_sum = v[i]+v[j];
                        }
                    }else{
                        if(abs((x) - (v[i]+v[j])) < temp){
                            temp = abs(x - (v[i]+v[j]));
                            best_sum = v[i]+v[j];
                        }
                    }
                }
            }
            cout << best_sum <<"."<<'\n'; 
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
