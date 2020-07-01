// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

int main(void){

    int n; cin >> n ;
    vector<pair<int,int>>v(n);
    for(int i=0; i < n; ++i){
        cin >> v.at(i).first  >> v.at(i).second;
    }
    sort(v.begin() , v.end(), 
            [](pair<int,int>&a, pair<int,int>&b){
                if(a.second == b.second){
                    return a.first < b.first;
                }
                    return a.second < b.second;
                }
            );
    int counter{1};
    int max_dist = v.at(0).second;
    for(int i=0;i <n; ++i){
        if(max_dist < v.at(i).first){
            ++counter;
            max_dist = v.at(i).second;
        }
    }
    cout << counter << '\n'; 
    return 0;
}
