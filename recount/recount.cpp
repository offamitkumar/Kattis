// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s; 
    map<string , int>f; 
    int max_{};
    string candidate;
    while(getline(cin ,s)){
        f[s]++;
        if(f[s] > max_){
            candidate = s; 
            max_ = f[s];
        }
    }
    int counter{};
    for(auto&itr:f){
        counter += (itr.second == max_);
    }
    if(counter>1){
        cout << "Runoff!"<<'\n';
    }else{
        cout << candidate << '\n'; 
    }
    return 0;
}
