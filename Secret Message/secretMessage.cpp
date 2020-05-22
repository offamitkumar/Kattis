#include <bits/stdc++.h>
using namespace std;
int next_square(int n) {
    return (int)ceil(sqrt(n));
}

char get(string &str, int max, int width, int x, int y) {
    return (y*width+x >=max)?'*':str[y*width+x];
}
int main( void ) {
    int n;cin>>n;
    while(n--){
        string s; cin>>s;
        int width = next_square(s.size());
        int i, j;
        for (i = 0; i < width; i++) {
            for (j = width - 1; j >=0; j--) {
                char c = get(s, s.size(), width, i, j);
                if (c != '*') {
                    cout<<c;
                }
            }
        }
        puts("");
    }
    return 0;
}
