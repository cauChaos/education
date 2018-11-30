#include<iostream>
#include<queue>

using namespace std;
 
char map[11][11];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int r, c;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> r >> c;
    
    for (int i = 0; i < r; i++)
    {
        cin >> map[i];
    }
 
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == '.')
            {
                int cnt = 0;
            
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                    if (map[ny][nx] == '.') cnt++;
                }
                if (cnt <= 1)
                {
                    cout << "1";
                    return 0;
                }
            }
        }
    }
    cout << "0";
    return 0;
}
