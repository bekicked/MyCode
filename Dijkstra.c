#include "Dijkstra.h"



// �Ͻ�˹�����㷨����
void dijkstra(int graph[V][V],char *cities[V] ,int startNode) {
    int cost[V][V], distance[V], pred[V]; // ����ɱ����󣬾��������ǰ������
    int visited[V], count, mindistance, nextNode, i, j; // ����������飬����������С���룬��һ���ڵ��ѭ������

    // �����ɱ�����
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            if (graph[i][j] == 0)
                cost[i][j] = INF; // ���ͼ�е�ֵΪ0����ô�ɱ������еĶ�Ӧλ��Ϊ�����
            else
                cost[i][j] = graph[i][j]; // ���򣬳ɱ������еĶ�Ӧλ��Ϊͼ�е�ֵ


    // ��ʼ�� pred[], distance[] �� visited[]
    for (i = 0; i < V; i++) {
        distance[i] = cost[startNode][i]; // ���������ʼ��Ϊ����ʼ�ڵ㵽�����ڵ�ĳɱ�
        pred[i] = startNode; // ǰ�������ʼ��Ϊ��ʼ�ڵ�
        visited[i] = 0; // ���������ʼ��Ϊ0����ʾ���нڵ㶼δ������
    }

    distance[startNode] = 0; // ��ʼ�ڵ㵽����ľ���Ϊ0
    visited[startNode] = 1; // �����ʼ�ڵ�Ϊ�ѷ���
    count = 1; // ��������ʼ��Ϊ1

    while (count < V - 1) { // �����ʵĽڵ���С���ܽڵ���ʱ��ִ��ѭ��
        mindistance = INF; // ��С�����ʼ��Ϊ�����

        // ��һ���ڵ�����Ǿ�����С��
        for (i = 0; i < V; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i]; // ������С����
                nextNode = i; // ������һ���ڵ�
            }

        // ����Ƿ��и��õ�·�������ǵ�ǰѡ�ڵ���ھ�
        visited[nextNode] = 1; // �����һ���ڵ�Ϊ�ѷ���
        for (i = 0; i < V; i++)
            if (!visited[i])
            if (mindistance + cost[nextNode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextNode][i]; // ���¾���
                    pred[i] = nextNode; // ����ǰ���ڵ�
                }
        count++; // ��������1
    }

    // ��ӡ��̾�������·��
    for (i = 0; i < V; i++)
        if (i != startNode) {
            printf("\nDistance from %s to %s: %d", cities[startNode],cities[i], distance[i]); // ��ӡ����ʼ�ڵ㵽�����ڵ����̾���
            printf("\nPath: %d", i); // ��ӡ·��

            j = i;
            do {
                j = pred[j];
                printf(" <- %s", cities[j]); // ��ӡ·���ϵĽڵ�
            } while (j != startNode);
    }
}
