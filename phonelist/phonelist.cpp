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

struct Node {
    bool isEnd;
    Node* arr[10];
    Node(){
        isEnd =false;
        for(int i=0;i<10;++i){
            arr[i] = nullptr;
        }
    }
};

bool check(Node*root , const string &s){
    Node*temp = root;
    for(int i=0;i<(int)s.size();++i){
        int val = s[i]-'0';
        if(temp->arr[val] != nullptr){
            temp = temp->arr[val];
            if(temp->isEnd){
                return false;
            }
        }else{
            return true;
        }
    }
    return false;
}

void add(Node*root , const string &s){
    Node*temp = root;
    for(int i=0;i<(int)s.size();++i){
        int val = s[i]-'0';
        if(temp->arr[val] == nullptr){
            temp -> arr[val] = new Node;
        }
        temp = temp->arr[val];
    }
    temp->isEnd = true;
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
    int t; scanf("%d",&t);
    while(t--){
        Node*root= new Node();
        int n; cin >> n; 
        bool possible = true;
        for(int i=0;i<n;++i){
            string s; cin >> s; 
            possible &= check(root , s);
            add(root , s);
        }
        if(possible){
            puts("YES");
        }else{
            puts("NO");
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
