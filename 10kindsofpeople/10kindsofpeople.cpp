//  author : amit kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>
  #include <iostream>
//  #include <chrono>
  #include <string>
//  #include <utility>
//  #include <queue>
//  #include <stack>
//  #include <cmath>
  #include <map>
//  #include <unordered_map>
//  #include <deque>
//  #include <unordered_set>
//  #include <set>
//  #include <climits>
//  #include <sstream>
//  #include <iomanip>
//  #include <cassert>
  #include <bitset>
  #include <numeric>
  #include <vector>
//  #include <array>
//  #include <algorithm>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename typeinfo>
//  using new_set = tree< // find_by_order & order_of_key
//          typeinfo ,
//          null_type ,
//          less<typeinfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
#define mod 1000000007
vector<string>graph;
int n,m; 
int counter; 
map<pair<int,int>,int>parent;
vector<bitset<1020>>visited;
void dfs(int x,int y , char type){
    if(x>=n || y>=m || x<0 || y<0 || visited[x][y]==true || type != graph[x][y]){
        return;
    }
    visited[x][y] = true;
    parent[make_pair(x,y)] = counter;
    dfs(x+1,y,type);
    dfs(x,y+1,type);
    dfs(x-1,y,type);
    dfs(x,y-1,type);
}
int main(void){
#ifdef hell_judge
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//      auto initial_time = high_resolution_clock::now();
    scanf("%d%d",&n,&m);
    graph.resize(n+10);
    visited.resize(n+10);
    counter = n*m+n*m;
    for(int i=0;i<n;++i){
        visited[i].reset();
        cin >> graph[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!visited[i][j]){
                dfs(i,j,graph[i][j]);
                counter++; // next parent 
            }
        }
    }
    int q; scanf("%d",&q);
    while(q--){
        int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
        --a,--b,--c,--d;
        if(parent[make_pair(a,b)] == parent[make_pair(c,d)]){
            if(graph[a][b]=='1'){
                puts("decimal");
            }else{
                puts("binary");
            }
        }else{
            puts("neither");
        }
    }

//      auto final_time = high_resolution_clock::now();
//      cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
