#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <stdio.h>
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
#define MAXN (int)(2e6+100)
char s[MAXN];
int x;
bool match(int n){
    for(int i=n; i<x;++i){
        if(s[i]!=s[i-n]){
            return false;
        }
    }
    return true;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    while(fgets(s,MAXN,stdin) && s[0]!='.'){
        x = strlen(s)-1;
        for(int i=1;i<=x;++i){
            if(x%i==0){
                if(match(i)){
                    cout << x / i << '\n'; 
                    break;
                }
            }
        }
    }
    return 0;
}
