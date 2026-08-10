#include <iostream>
#include <algorithm>
using namespace std;

int M, N, K, L, D;

int row[1005];
int col[1005];

struct Node
{
    int id;
    int val;
};

Node r[1005], c[1005];

bool cmp(Node a, Node b)
{
    return a.val > b.val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> K >> L >> D;
    for (int i = 1; i <= D; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
        {
            int y = min(y1, y2);
            col[y]++;
        }
        else
        {
            int x = min(x1, x2);
            row[x]++;
        }
    }
    for (int i = 1; i < M; i++)
    {
        r[i].id = i;
        r[i].val = row[i];
    }
    for (int i = 1; i < N; i++)
    {
        c[i].id = i;
        c[i].val = col[i];
    }
    sort(r + 1, r + M, cmp);
    sort(c + 1, c + N, cmp);
    int ans1[1005];
    int ans2[1005];
    for (int i = 1; i <= K; i++)
        ans1[i] = r[i].id;
    for (int i = 1; i <= L; i++)
        ans2[i] = c[i].id;
    sort(ans1 + 1, ans1 + K + 1);
    sort(ans2 + 1, ans2 + L + 1);
    for (int i = 1; i <= K; i++)
    {
        if (i != 1)
            cout << " ";
        cout << ans1[i];
    }
    cout << endl;
    for (int i = 1; i <= L; i++)
    {
        if (i != 1)
            cout << " ";
        cout << ans2[i];
    }
    cout << endl;
    return 0;
}