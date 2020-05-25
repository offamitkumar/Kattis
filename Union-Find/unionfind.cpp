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
#define MAXN (int)1e6+10
int parent[MAXN];
int parent_size[MAXN];
int find_parent(int p){
    if(parent[p] == p){
        return p;
    }else{
        return parent[p] = find_parent(parent[p]);
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n , q; scanf("%d %d",&n,&q);
    char ch; int a,b;
 //   if(q){
        iota(parent ,parent+n+1 , 0);
//        memset(parent_size ,1 , sizeof(parent_size) );
   // }
    while(q--){
        scanf(" %c %d %d",&ch ,&a,&b);
        a = find_parent(a);
        b = find_parent(b);
        if(ch == '='){
//            if(parent_size[a] > parent_size[b]){
//                parent_size[a]+=parent_size[b];
                parent[b] = a;
 //           }else{
//                parent_size[b]+=parent_size[a];
  //              parent[a] = b;
 //           }
        }else{
            puts((a==b)?"yes":"no");
        }
    }
    return 0;
}
