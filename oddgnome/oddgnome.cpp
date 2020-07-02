// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int counter,target;
        bool found=false;
        for(int i=0;i<n;++i){
            int x; cin >> x; 
            if(i==0){
                counter = x+1;
            }else{
                if(counter != x && (!found)){
                    target = i+1;
                    found = true;
                }else{
                    counter++;
                }
            }
        }
        cout << target << '\n'; 
    }
    return 0;
}
