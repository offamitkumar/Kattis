#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXN 201008
array<int64_t, MAXN>parent, sum , connection;
void Set(int64_t n){
    fill(sum.begin(),sum.end() , 0);
    fill(parent.begin() , parent.end() , 0);
    for(int64_t i=1,j=n+1; i <= n; ++i , ++j){
        parent[i] = j;
        parent[j] = j;
        sum[j] = i;
        connection[j] = 1;
    }
}
int64_t find_parent(int64_t node){
    if(node == parent[node]){
        return node;
    }else{
        return parent[node] = find_parent(parent[node]);
    }
}
void union_(int64_t p , int64_t q){
    int64_t p_parent = find_parent(p);
    int64_t q_parent = find_parent(q);
    if(p_parent != q_parent) {
        connection[q_parent] += connection[p_parent];
        sum[q_parent] += sum[p_parent];
        parent[p_parent] = q_parent;
    }
}
void merge_(int64_t p , int64_t q){
    int64_t p_parent = find_parent(p);
    int64_t q_parent = find_parent(q);
    if(p_parent != q_parent) {
        connection[p_parent]--;
        connection[q_parent]++;
        sum[q_parent]+=p;
        sum[p_parent]-=p;
        parent[p] = q_parent;
    }
}
void print_info(int64_t p){
    int64_t p_parent = find_parent(p);
    cout<<connection[p_parent]<<' '<<sum[p_parent]<<'\n';
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n , qy;
    while(scanf("%d %d",&n,&qy)!=EOF){
        Set(n);
        while(qy--){
            int query_type, p, q;
            scanf("%d",&query_type);
            if(query_type == 1) {
                scanf("%d %d", &p, &q);
                union_(p, q);
            } else if (query_type == 2) {
                scanf("%d %d", &p, &q);
                merge_(p, q);
            } else {
                scanf("%d", &p);
                print_info(p);
            }
        }
    }
    return 0;
}
