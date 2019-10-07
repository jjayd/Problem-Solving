#include <iostream>
using namespace std;
int D, W, K;
int res;
int cell[14][21];
bool chk[14];
bool isOK(int mode) {
    int a, b;
    bool flag;
    if(mode==0) {
        for(int i=1; i<=W; i++) {
            a = 0;
            b = 0;
            flag = false;
            for(int j=1; j<=D; j++) {
                if(cell[j][i] == 0 || chk[j]) {
                    a++;
                    b=0;
                } else {
                    b++;
                    a=0;
                }
                if(a==K || b==K) {
                    flag = true;
                    break;
                }
            }
            if(!flag) return false;
        }
    } 
    else {
        for(int i=1; i<=W; i++) {
            a = 0;
            b = 0;
            flag = false;
            for(int j=1; j<=D; j++) {
                if(cell[j][i] == 1 || chk[j]) {
                    b++;
                    a=0;
                } else {
                    a++;
                    b=0;
                }
                if(a==K || b==K) {
                    flag = true;
                    break;
                }
            }
            if(!flag) return false;
        }
    }
    return true;
}
void dfs(int idx, int cnt) {
    if(cnt>K) return; // 
    chk[idx] = true; // A이든 B이든 화학약품을 넣은 경우
   // for(int i=1;i<=D;i++) printf("%d ",chk[i]);
    //printf("\n"); 
    if(isOK(0) || isOK(1)) {
        res = min(cnt, res);
    }
    for(int i=idx+1; i<=D; i++) {
        dfs(i, cnt+1); // if(!chk[i])를 넣지 않고 중복되지 않게 검색하는 방법.
    }
    chk[idx] = false; // 화학약품 넣지 않은 경우
}
int main() {
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        cin >> D >> W >> K;
        for(int i=1; i<=D; i++) {
            for(int j=1; j<=W; j++) {
                cin >> cell[i][j];
            }
        }
        res = K;
        dfs(0, 0); // 0부터 시작한 이유는 화학약품 넣지 않았을 경우를 고려한 것.(처음 시작상태)
        cout << '#' << tc << ' ' << res << '\n';
    }
    return 0;
}