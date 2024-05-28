#include "Dijkstra.h"



// 迪杰斯特拉算法函数
void dijkstra(int graph[V][V],char *cities[V] ,int startNode) {
    int cost[V][V], distance[V], pred[V]; // 定义成本矩阵，距离数组和前驱数组
    int visited[V], count, mindistance, nextNode, i, j; // 定义访问数组，计数器，最小距离，下一个节点和循环变量

    // 创建成本矩阵
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            if (graph[i][j] == 0)
                cost[i][j] = INF; // 如果图中的值为0，那么成本矩阵中的对应位置为无穷大
            else
                cost[i][j] = graph[i][j]; // 否则，成本矩阵中的对应位置为图中的值


    // 初始化 pred[], distance[] 和 visited[]
    for (i = 0; i < V; i++) {
        distance[i] = cost[startNode][i]; // 距离数组初始化为从起始节点到其他节点的成本
        pred[i] = startNode; // 前驱数组初始化为起始节点
        visited[i] = 0; // 访问数组初始化为0，表示所有节点都未被访问
    }

    distance[startNode] = 0; // 起始节点到自身的距离为0
    visited[startNode] = 1; // 标记起始节点为已访问
    count = 1; // 计数器初始化为1

    while (count < V - 1) { // 当访问的节点数小于总节点数时，执行循环
        mindistance = INF; // 最小距离初始化为无穷大

        // 下一个节点必须是距离最小的
        for (i = 0; i < V; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i]; // 更新最小距离
                nextNode = i; // 更新下一个节点
            }

        // 检查是否有更好的路径到我们的前选节点的邻居
        visited[nextNode] = 1; // 标记下一个节点为已访问
        for (i = 0; i < V; i++)
            if (!visited[i])
            if (mindistance + cost[nextNode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextNode][i]; // 更新距离
                    pred[i] = nextNode; // 更新前驱节点
                }
        count++; // 计数器加1
    }

    // 打印最短距离和最短路径
    for (i = 0; i < V; i++)
        if (i != startNode) {
            printf("\nDistance from %s to %s: %d", cities[startNode],cities[i], distance[i]); // 打印从起始节点到其他节点的最短距离
            printf("\nPath: %d", i); // 打印路径

            j = i;
            do {
                j = pred[j];
                printf(" <- %s", cities[j]); // 打印路径上的节点
            } while (j != startNode);
    }
}
