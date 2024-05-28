#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

int main() {
int n;

    int botton;
    int startNode;
    char* cities[V];
    int graph[V][V];


    for (int i = 0; i < V; i++) {
    cities[i] = malloc(50 * sizeof(char)); // 假设城市名称的最大长度为 50
}


    printf("需要展示各销售处信息请输入'1'\n");
    printf("需要展示销售处之间货运成本信息请输入'2'\n");
    printf("由于一些原因需要修改销售处之间货运成本信息请输入'3'\n");
    printf("需要展示两个销售处之间最低货运成本信息请输入'4'\n");
    printf("由于企业业务扩大，需要新增一处销售处，请输入'5'\n");
    printf("由于企业业务变化，需要减少某销售处，请输入'6'\n");
    printf("由于企业业务变化，某两个销售处之间新计划一处货运方案，请输入'7'\n");
    printf("由于企业业务变化，某两个销售处之间停止原先的货运方案，请输入'8'\n");
    printf("退出该程序，请输入'9'\n");
    printf("\n");
    while(1+1==2){
    printf("请输入您的操作： \n");
    scanf("%d",&botton);

    if(botton == 1){

     // 定义图的邻接矩阵
    // 定义城市名称数组


    FILE *file = fopen("matrix.txt", "r");
    // 打开文件
    if (file == NULL) {
        printf("无法打开文件\n");
        return 1;
    }

    // 从文件中读取数据到邻接矩阵
    for (int i = 0; i < V; i++)

            fscanf(file, "%s", cities[i]);

    fclose(file); // 关闭文件

    // 打印所有的城市名称
    printf("销售处：\n");
    for (int i = 0; i < V; i++) {
        printf("%s ", &cities[i]);
    }
    printf("\n");
    }



    if(botton == 2){
    FILE *file = fopen("matrix.txt", "r"); // 打开文件
    if (file == NULL) {
        printf("无法打开文件\n");
        return 1;
    }

    // 从文件中读取数据到邻接矩阵
    for (int i = 0; i < V; i++){
        fscanf(file, "%s", cities[i]);
        for (int j = 0; j < V; j++){
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file); // 关闭文件


        dijkstra(graph,cities, 0); // 调用迪杰斯特拉算法函数
        printf("\n");

    }


    if(botton == 3){

 FILE *file = fopen("matrix.txt", "r"); // 打开文件
    if (file == NULL) {
        printf("无法打开文件\n");
        return 1;
    }

    // 从文件中读取数据到邻接矩阵
    for (int i = 0; i < V; i++){
        fscanf(file, "%s", cities[i]);
        for (int j = 0; j < V; j++){
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file); // 关闭文件
        /*int graph[V][V]={{0, 5, 0, 0, 0, 0, 4, 0},
{5, 0, 1, 0, 6, 0, 0, 2},
{0, 1, 0, 4, 0, 0, 0, 0},
{0, 0 ,4, 0, 1, 0, 0, 0},
{0, 6, 0, 1, 0, 2, 5, 0},
{0, 0, 0, 0, 2, 0, 2, 0},
{4, 0, 0 ,0, 0 ,2, 0, 3},
{0, 2, 0, 0, 0, 0, 3, 0}
        };
         char *cities[V]={'ChongQing','ZhengZhou','BeiJing','ShangHai','HangZhou','FuZhou','GuangZhou','WuHan'};*/

         int startNode = 0;


        dijkstra(graph,cities,startNode );
    }


    }
    return 0; // 程序结束
}
