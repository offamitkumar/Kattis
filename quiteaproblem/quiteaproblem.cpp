// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

int main(void){
    string pattern = "problem";
    string s;
    while(getline(cin,s)){
        for(auto&itr:s){
            if((itr>='a' && itr<='z') || (itr>='A' && itr<='Z')){
                itr = char(tolower(itr));
            }
        }
        if(s.find(pattern)!=string::npos){
            cout <<"yes"<<'\n';
        }else{
            cout <<"no"<<'\n';
        }
    }
    return 0;
}
