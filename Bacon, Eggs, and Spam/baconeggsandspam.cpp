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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; 
    while(cin>>t ,t){
        cin.ignore();
        map<string,set<string>>menu;
        string s;
        for(auto i=0;i<t;++i){
            getline(cin , s);
            stringstream ss(s);
            string order , user;
            ss>>user;
            while(ss>>order){
                menu[order].insert(user);
            }
        }
        for(auto&itr:menu){
            cout<<itr.first<<' ';
            for(auto &itr1:itr.second){
                cout<<itr1<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}
