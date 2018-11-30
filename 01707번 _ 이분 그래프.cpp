#include <cstdio>
#include <vector>

std::vector<int> a[200001];
int check[200001];
void dfs(int node, int checking){
    check[node] = checking;
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(check[next] == 0){
            dfs(next, 3-checking);
        }
    }
}

int main(void){
    int T;
    scanf("%d",&T);
    for(int k=1; k<=T; k++){
        int vert, edge;
        scanf("%d %d",&vert,&edge);
        for(int i=1; i<=vert; i++){
            check[i] = 0;
            a[i].clear();
        }
        for(int i=1; i<=edge; i++){
            int u, v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        
        for(int i=1; i<=vert; i++){
            if(check[i]==0){
                dfs(i,1);
            }
        }
        int flag = 1;
        for(int i=1; i<=vert; i++){
            for(int j=0; j<a[i].size(); j++){
                if(check[i]==check[a[i][j]]){
                    flag=0;
                }
            }   
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
