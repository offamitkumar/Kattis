//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
//  #include <algorithm>
//  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
//  #include <utility>

//  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
//  #include <map>
//  #include <deque>

  #include <climits>
  #include <cstring>
//  #include <cmath>
//  #include <cassert>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
const int MAXM = (int)1e5+100;
const int MAXN = (int)1e4+100;
const int MOD = (int)1e5+100;
int n , m , q , s; 
struct Node{
    int u , v , w; 
};
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    bool more = false;
    while(scanf("%d %d %d %d",&n,&m,&q,&s) && n+m+q+s){
        if(more){
            puts("");
        }
        more = true;
        vector<Node>v(m);
        for(int i=0;i<m;++i){
            cin >> v[i].u >> v[i].v >> v[i].w;
        }
        int dist[MAXN];
        for(int i=0;i<MAXN;++i){
            dist[i] = 100000000;
        }
        dist[s] =0;
        bool relaxed = true;
        for(int i=0;i<n - 1 && relaxed;++i){
            relaxed = false;
            for(int j=0;j<m;++j ){ 
                if(dist[v[j].v] > dist[v[j].u]+v[j].w){
                    relaxed = true;
                    dist[v[j].v] = dist[v[j].u] + v[j].w;
                }
            }
        }
        while(q--){
            int x; cin >> x;
            if(dist[x] == 100000000){
                puts("Impossible");
            }else{
                cout << dist[x] << '\n'; 
            }
        }
    }
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
