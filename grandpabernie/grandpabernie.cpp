//  Author : Amit Kumar 
//  Date   : Friday 03 July 2020 10:44:58 AM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

bool compare(pair<string,int>&a , pair<string,int>&b){
    return a.second < b.second;
}

int main(void){
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    int n; cin >> n; 
    vector<pair<string,int>>v(n); 
    for(int i=0;i<n;++i){
        cin >> v.at(i).first >> v.at(i).second;
    }
    sort(v.begin() , v.end() , compare);
    map<string,int>visit_counter;
    map<pair<string,int>, int>f;
    for(auto&itr:v){
        string country; int date; 
        country = itr.first; 
        date = itr.second;
        visit_counter[country]++;
        int Time = visit_counter[country];
        f[make_pair(country , Time)] = date;
    }
    int q; 
    cin >> q; 
    while(q--){
        string country ;  int Time; 
        cin >> country >> Time ; 
        cout << f[make_pair(country , Time)] << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
