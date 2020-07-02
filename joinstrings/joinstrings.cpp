//  Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

vector<string>s;
vector<vector<int>>graph;
void print(int u){
    cout << s[u];
    for(auto&itr:graph[u]){
        print(itr);
    }
}

signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            //
    cout.tie(nullptr);           //
    int n; cin >> n; 
    graph.resize(n+1);
    s.resize(n+1);
    for(int i=0;i<n;++i){
        cin >> s[i];
    }
    int l{};
    n--;
    while(n--){
        int u,v; cin >> u >> v; 
        --u , --v;
        graph[u].push_back(v);
        l = u;
    }
    print(l);
    cout<<'\n';
    return 0;
}
