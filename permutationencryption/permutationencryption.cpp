// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

int main(void){
//    freopen("input","r",stdin);
    int n; 
    while(cin >> n,n){
        vector<int>v(n); 
        for(auto&itr:v){
            cin >> itr;
        }
        cin.ignore();
        string a; getline(cin,a);
        int i = 0;
        cout <<"'";
        while(i<(int)a.size()){
            for(int j=0;j<n; ++j){
                if((v[j]-1+i)>=(int)a.size())
                    cout <<' ';
                else
                    cout << a[v[j]-1+i];
            }
            i+=(n);
//              if(a.size()>(n-1)){
//                  a.erase(a.begin()+(n-1));
//              }else{
//                  break;
//              }
        }
        cout <<"'";
        cout <<'\n'; 
    }
    return 0;
}
