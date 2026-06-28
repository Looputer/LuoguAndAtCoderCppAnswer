#include <iostream>
#define int long long
using namespace std;

const int N = 2e5+5;
const int M = 2e5+5;

int fa[N];

int A[M], B[M];


int ex_id[M], ex_cnt = 0;

int rep[N], rep_cnt = 0;

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=1;i<=n;i++) fa[i]=i;

    for(int i=1;i<=m;i++){
        cin >> A[i] >> B[i];

        int x = find(A[i]);
        int y = find(B[i]);

        if(x == y){
            ex_id[ex_cnt++] = i;
        }else{
            fa[x] = y;
        }
    }

    for(int i=1;i<=n;i++){
        if(find(i) == i){
            rep[rep_cnt++] = i;
        }
    }

    int need = rep_cnt - 1;

    cout << need << "\n";

    int p = 0;

    for(int i=1;i<=need;i++){
        int id = ex_id[p++];

        int u = rep[0];
        int v = rep[i];

        cout << id << " " << A[id] << " " << v << "\n";

        fa[find(v)] = find(u);
    }

    return 0;
}