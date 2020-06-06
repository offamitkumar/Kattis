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
  #include <tuple>
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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    string attributes;
    while(getline(cin , attributes)) {
        if(attributes.size() == 0){
            break;
        }
        string attribute_order = attributes;
        map<string , int > attribute_index;
        int temp_index = 0;
        stringstream ss(attributes); 
        while(ss >> attributes){
            attribute_index[attributes] = temp_index++;
        }
        int total_songs; cin >> total_songs; 
        vector<vector<string>>data(total_songs, vector<string>(temp_index));
        for(int i = 0; i < total_songs; ++i){
            for(int j = 0; j< temp_index; ++j){
                cin >> data[i][j];
            }
        }
        int total_sorting; cin >> total_sorting;
        while(total_sorting--){
            string sort_by; cin >> sort_by;
            int index =  attribute_index[sort_by];
            auto comparator = [&](const vector<string>&a,const vector<string>&b) {
                string A = a[index];
                string B = b[index];
                bool ok = A < B; 
                return ok; 
            };
            stable_sort(data.begin(),data.end(), comparator);
            cout << attribute_order << '\n';
            for(auto&vec:data){
                for(auto&itr:vec){
                    cout << itr<<' ';
                }
                cout <<'\n';
            }
            cout << '\n'; 
        }
    }

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
