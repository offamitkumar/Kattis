//  Author : Amit Kumar 

#include <iostream>
#include <algorithm> 
#include <string> 
#include <sstream>
#include <fstream>
#include <iomanip> 
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
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <deque>
#include <list>


#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
using namespace __gnu_pbds;
template<typename TypeInfo>
using new_set = tree< 
/* ob.order_of_key(element) -> number of element strictly less than element
 * *ob.find_by_order(n) ->  nth element in increasing order
 */
         TypeInfo ,
         null_type ,
         less<TypeInfo> ,
         rb_tree_tag ,
         tree_order_statistics_node_update 
 > ;

void debug_out() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void debug_out(HEAD H, TAIL... T) {
  cerr << " " << (H);
  debug_out(T...);
}
 
#ifdef HELL_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 


const int64_t P_INF = INT_MAX;
const int64_t MAXN = (int64_t)1e5+100;
const int64_t MOD  = (int64_t)1e9+7;


struct Node{
    int64_t start, end_ , weight;
    Node(){
        start = -1;
        end_ = -1;
        weight = -400000;
    }
    friend istream& operator>>(istream&in , Node&n){
        in >> n.start >> n.end_ >> n.weight;
        return in;
    }
};

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            //
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int64_t n, m, q, s; 
    while(cin >> n >> m >> q >> s && (n+m+q+s)) {
        vector<Node>edge(m);
        for(int i=0;i<m;++i){
            cin >> edge[i].start >> edge[i].end_ >> edge[i].weight; 
        }
        vector<int64_t>dist(n,P_INF);
        dist[s] = 0;
        bool updating = true;
        for(int64_t i=0;i<n && updating;++i){
            updating = false;
            for(int64_t j=0;j<m;++j){
                const int64_t& source = edge[j].start;
                const int64_t& end_ = edge[j].end_;
                const int64_t& weight = edge[j].weight;
                if(dist[source]==P_INF){
                    continue;
                }
                if(dist[end_] > dist[source]+weight){
                    updating = true;
                    dist[end_] = dist[source]+weight;
                }
            }
        }
        updating = true;
        while(updating){
            updating = false;
            for(int64_t j=0;j<m;++j){
                const int64_t& source = edge[j].start;
                const int64_t& end_ = edge[j].end_;
                const int64_t& weight = edge[j].weight;
                if(dist[end_]==-P_INF){
                    continue;
                }
                if(dist[source]==P_INF){
                    continue;
                }
                if(dist[end_] > dist[source]+weight){
                    updating = true;
                    dist[end_] = -P_INF;
                }
            }
        }
        while(q--){
            int64_t l; cin >> l;
            if(dist[l]==P_INF){
                cout << "Impossible";
            }else if(dist[l] == -P_INF){
                cout << "-Infinity";
            }else{
                cout << dist[l];
            }
             cout << '\n'; 
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
