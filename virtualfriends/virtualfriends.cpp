// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

map<string , string>parent;
map<string , int>country;
string find_parent(string node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}

int main(void){
    int t; cin >> t; 
    while(t--){
        parent.clear();
        country.clear();
        int f; cin >> f; 
        for(int i=0;i<f;++i){
            string u , v; cin >> u >> v; 
            if(parent.find(u) == parent.end()){
                parent[u] = u;
                country[u] = 1;
            }
            if(parent.find(v) == parent.end()){
                parent[v] = v;
                country[v] = 1;
            }
            string x = find_parent(u);
            string y = find_parent(v);
            if(x != y){
                parent[x] = y;
                country[y] += country[x];
            }
            cout << country[y] << '\n'; 
        }
    }
    return 0;
}
