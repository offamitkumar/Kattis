//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
  #include <algorithm>
  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
//  #include <utility>

//  #include <bitset>
//  #include <tuple>
  #include <queue>
//  #include <stack>
  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
//  #include <map>
  #include <deque>

  #include <climits>
  #include <cstring>
  #include <cmath>
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
const int MOD = (int)1e9+7;
vector<vector<string>>grid;
int dp[35][35][35];
vector<int>start(3) , end_(3);
int l, r, c;
void pre(void){
    for(int i=0;i<35;++i){
        for(int j=0;j<35;++j){
            for(int k=0;k<35;++k){
                dp[i][j][k] = INT_MAX;
            }
        }
    }
}
bool check(int level , int x , int y){
    if(level < 0 || x < 0 || y <0){
        return false;
    }
    if( level >= l || x >= r || y >= c ){
        return false;
    }
    if(dp[level][x][y]!= INT_MAX){
        return false; // grid is already visited
    }
    if(grid[level][x][y]=='#'){
        return false;
    }
    return true;
}
int getAns(void){
    pre();
    queue<vector<int>>q;
    dp[start[0]][start[1]][start[2]] =0;
    q.push(start);
    while(!q.empty()){
        int level = q.front().at(0);
        int x_c = q.front().at(1);
        int y_c = q.front().at(2);
//        if(level == end_[0] && x_c == end_[1] && y_c == end_[2]){
//            return dp[level][x_c][y_c];
//        }
        q.pop();
        if(check(level+1 , x_c,y_c)){
            dp[level+1][x_c][y_c] = dp[level][x_c][y_c] + 1;
            q.push({level+1 , x_c , y_c});
        }
        if(check(level-1 , x_c,y_c)){
            dp[level-1][x_c][y_c] = dp[level][x_c][y_c] + 1;
            q.push({level-1 , x_c , y_c});
        }
        if(check(level , x_c-1,y_c)){
            dp[level][x_c-1][y_c] = dp[level][x_c][y_c] + 1;
            q.push({level , x_c-1 , y_c});
        }
        if(check(level , x_c+1,y_c)){
            dp[level][x_c+1][y_c] = dp[level][x_c][y_c] + 1;
            q.push({level , x_c+1 , y_c});

        }
        if(check(level , x_c,y_c-1)){
            dp[level][x_c][y_c-1] = dp[level][x_c][y_c] + 1;
            q.push({level , x_c , y_c-1});
        }
        if(check(level , x_c,y_c+1)){
            dp[level][x_c][y_c+1] = dp[level][x_c][y_c] + 1;
            q.push({level , x_c , y_c+1});
        }
    }
    if(dp[end_[0]][end_[1]][end_[2]]==INT_MAX){
        return -1;
    }else{
        return dp[end_[0]][end_[1]][end_[2]];
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    while(scanf("%d %d %d",&l,&r,&c) && (l+r+c)){
        grid.assign(l+1, vector<string>(r+1));
        for(int i=0;i<l;++i){
            for(int j=0;j<r;++j){
                cin >> grid[i][j];
                for(int k=0;k<c;++k){
                    if(grid[i][j][k] == 'S'){
                        start = {i,j,k};
                    }else if(grid[i][j][k]=='E'){
                        end_ = {i,j,k};
                    }
                }
            }
        }
        int ans = getAns();
        if(ans == -1){
            puts("Trapped!");
        }else{
            printf("Escaped in %d minute(s).\n",ans);
        }
    }

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
