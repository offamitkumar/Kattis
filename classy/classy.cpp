//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
  #include <algorithm>
  #include <string>
  #include <sstream>
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
  #include <map>
//  #include <deque>

//  #include <climits>
//  #include <cstring>
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
const int MAXN = (int)1e5+100;
const int MOD = (int)1e5+100;
struct Node{
    vector<int>pre;
    string name;
};
bool comparator(const Node&a , const Node&b){
    int i = 0;
    while (i < (int)a.pre.size() && i < (int)b.pre.size()){
        if(a.pre[i] < b.pre[i]) {
            return true;
        }else if (a.pre[i] > b.pre[i]){
            return false;
        }
        ++i;
    }
    return a.name < b.name;
}

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int t; scanf("%d",&t);
    map<string , int>value;
    value["upper"] = 2;
    value["middle"] = 1;
    value["lower"] = 0;
    while(t--){
        int n; scanf("%d",&n);
        vector<Node>v(n);
        int max_class = 0;
        for(int i=0;i<n;++i){
            string a,b,c;
            cin >> a >> b >> c ;
            v[i].name = a.substr(0,a.size()-1);
            stringstream ss(b);
            while(getline(ss , b , '-')){
                v[i].pre.push_back(-1 * value[b]);
            }
            reverse(v[i].pre.begin(), v[i].pre.end()); // lowest first 
            while(v[i].pre.size() != 10){
                v[i].pre.push_back(-1); // take all remaining class as middle stated in question 
            }
        }

        sort(v.begin() , v.end() , comparator);
        for(auto&itr:v){
            cout << itr.name << '\n';
        }
        cout << string(30,'=') << '\n'; 
    }

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
