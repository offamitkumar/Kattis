//  Author : Amit Kumar 
//  Date   : Friday 03 July 2020 08:48:29 AM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


struct Node{
    int firstNumber{}; 
    int secondNumber{}; 
    int index{};
};

bool compare(Node&a , Node&b){
    return a.index < b.index;
}

int main(void){
    

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 

#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int n;
    while(cin >> n, n){
        vector<pair<int,int>>v(n); 
        for(int i=0;i<n;++i){
            cin >> v[i].first; 
            v[i].second = i;
        }
        vector<int>V(n);
        for(auto&itr:V){
            cin >> itr;
        }
        sort(v.begin() , v.end());
        sort(V.begin() , V.end());
        vector<Node>res(n);
        for(int i=0;i<n;++i){
            res[i].firstNumber = v[i].first;
            res[i].secondNumber = V[i];
            res[i].index = v[i].second;
        }
        sort(res.begin() , res.end() , compare);
        for(auto&itr:res){
            cout << itr.secondNumber <<'\n'; 
        }
        cout << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
