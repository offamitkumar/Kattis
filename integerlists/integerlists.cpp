//  Author : Amit Kumar 
//  Date   : Friday 03 July 2020 09:44:51 AM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(void){
    

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 

#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    int t; cin >> t; 
    cin.ignore();
    while(t--){
        string ops; cin >> ops; 
        int n; cin >> n; 
        cin.ignore();
        deque<int>d; 
        cin.ignore(); 
        for(int i=0; i < n; ++i){
            int x; cin >> x; 
            d.push_back(x);
            char ch; cin >> ch;
        }
        cin.ignore();
        bool reversed=false;
        bool error = false;
        for(auto&itr:ops){
            if(itr=='R'){
                reversed ^= 1;
            }else{
                if(d.empty()){
                    error = true;
                }else{
                    if(reversed){
                        d.pop_back();
                    }else{
                        d.pop_front();
                    }
                }
            }
        }
        if(error){
            cout << "error" << '\n'; 
        }else{
            cout <<'[';
            bool more =false;
            if(!reversed){
                while(!d.empty()){
                    if(more){
                        cout <<',';
                    }
                    cout << d.front();
                    d.pop_front();
                    more = true;
                }
            }else{
                while(!d.empty()){
                    if(more){
                        cout <<',';
                    }
                    cout << d.back();
                    d.pop_back();
                    more = true;
                }
            }
            cout <<']'<<'\n';
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
