// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int>v(n); 
        int max_{} , index;
        for(int i=0;i<n;++i){
            cin >> v.at(i);
            if(v.at(i) > max_){
                max_ = v.at(i);
                index = i+1;
            }
        }
        sort(v.begin() , v.end(), greater<int>());
        if(v.at(0) == v.at(1)){
            cout <<"no winner" << '\n'; 
        }else{
            if(accumulate(v.begin()+1 , v.end() , 0ll) < v.at(0)){
                cout << "majority winner ";
            }else{
                cout << "minority winner ";
            }
            cout << index << '\n'; 
        }
    }
    return 0;
}
