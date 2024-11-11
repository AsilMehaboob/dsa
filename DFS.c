#include<stdio.h>
#define max 10

void dfs(int graph[max][max],int visited[max],int node,int n){
    visited[node]=1;
    printf("%d",node);

    for(int i=0;i<n;i++){
        if(graph[node][i]==1&&!visited[i])
            dfs(graph,visited,i,n);
    }
}

void main(){
    int n,start;
    printf("Number of Vertices:");
    scanf("%d",&n);
    int graph[max][max];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    int visited[max]={0};
    printf("Enter Start Index");
    scanf("%d",&start);

    printf("DFS is :");
    dfs(graph,visited,start,n);
}