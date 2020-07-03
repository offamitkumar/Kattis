//  Author : Amit Kumar 
//  Date   : Friday 03 July 2020 12:51:20 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;



template<typename A, typename B>
ostream& operator<<(ostream&out, const pair<A, B>&p){
    out << p.first << ' ' << p.second ;
    return out;
}

template<typename A, typename B>
istream& operator>>(istream&in, pair<A, B>&p){
    in >> p.first >> p.second ;
    return in;
}

template<typename A> 
istream& operator>>(istream&in, vector<A>&vec){
    for(auto&itr:vec){
        in >> itr;
    }
    return in;
}

template<typename A>
ostream& operator<<(ostream&out,const vector<A>&vec){
    for(auto&itr:vec){
        out << itr <<' '; // VVV 
    }
    return out;
}


int main(void){
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    unsigned seed = system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    int n; 
    while(cin >> n){
        vector<pair<double , double>>v(n);
        cin >> v;
        set<int>visited; 
        while((int)visited.size()!=n){
            int vis = generator()%n; 
            while(visited.find(vis)!=visited.end()){
                vis = generator()%n;
            }
            visited.insert(vis);
            cout << vis << '\n'; 
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
