#include <stdio.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES]; // 0 for false, 1 for true
int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int node) {
    if (rear == MAX_NODES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = node;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front++];
}

int isQueueEmpty() {
    return front == -1 || front > rear;
}

void bfs(int startNode, int numNodes) {
    for (int i = 0; i < numNodes; i++) 
        visited[i] = 0; // Mark all nodes as not visited (0)

    enqueue(startNode);
    visited[startNode] = 1; // Mark the start node as visited (1)

    printf("BFS traversal starting from node %d: ", startNode);

    while (!isQueueEmpty()) {
        int currentNode = dequeue();
        printf("%d ", currentNode);

        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1; // Mark node as visited
            }
        }
    }
    printf("\n");
}

int main() {
    int numNodes, numEdges, u, v, startNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Initialize the graph with no edges
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (u v) for each edge:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // For undirected graph
    }

    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    bfs(startNode, numNodes);

    return 0;
}
