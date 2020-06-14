//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

#include <iostream>
#include <algorithm> 
#include <string> 
//  #include <sstream> 
//  #include <fstream>
//  #include <iomanip> 
#include <chrono> 
#include <numeric>
#include <utility>
#include <functional>

#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <array>
//  #include <unordered_map>
//  #include <unordered_set>
#include <set>
#include <map>
//  #include <deque>

#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>
using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//                   TypeInfo ,
//                   null_type ,
//                   less<TypeInfo> ,
//                   rb_tree_tag ,
//                   tree_order_statistics_node_update 
//       > ;

void debug_out() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void debug_out(HEAD H, TAIL... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef HELL_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 

const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int MOD = (int)1e9+7;

vector<int> parent(MAXN);
vector<bool> visited(MAXN);
vector<vector<int>>dist;
bool comparator(vector<int>&a , vector<int>&b){
    return a[2] < b[2];
}
int find_parent(int node){
    if(parent[node] == node){
        return node;
    }else{
        return parent[node] = find_parent(parent[node]);
    }
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
    int n,m;
    while(cin >> n >> m && (m+n)){
        fill(visited.begin() , visited.end() , false);
        iota(parent.begin() , parent.end() , 0);
        dist.clear();
        dist.resize(m);
        for(int i=0;i<m;++i){
            int a,b,c; cin >> a >> b >> c;
            dist[i].push_back(a);
            dist[i].push_back(b);
            dist[i].push_back(c);
        }
        sort(dist.begin() , dist.end(), comparator);
        set<pair<int,int>>edge;
        int cost{};
        for(auto&itr:dist){
            int u = itr[0];
            int v = itr[1];
            int w = itr[2];
            int x = u; 
            int y = v;
            u = find_parent(u);
            v = find_parent(v);
            if(u != v){
                visited[x] = true;
                visited[y] = true;
                parent[v] = u;
                cost+=w;
                edge.insert(make_pair(min(x,y) , max(x,y)));
            }
        }
        bool possible = true;
        for(int i=0;i<n;++i){
            if(!visited[i]){
                possible = false;
                break;
            }
        }
        if(possible){
            cout << cost << '\n';
            for(auto&itr:edge){
                cout << itr.first << ' '<< itr.second << '\n'; 
            }
        }else{
            puts("Impossible");
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
