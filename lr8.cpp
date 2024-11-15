#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int** createG(int size) {
	int** G;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) {
		G[i] = (int*)malloc(size * sizeof(int));
	}
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			G[i][j] = rand() % 2;
			if (i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

int printG(int **G, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//int **G=NULL, size = 5, vis[5] = {0};


void BFS(int **G, int size, int *vis, int s){
    queue <int> q;
    q.push(s);
    
    vis[s] = 1;
    
    while(!q.empty()){
        s = q.front();
        printf("%d ", s);
        q.pop();
        for(int i = 0; i < size; i++){
            if(G[s][i] == 1 && vis[i]== 0){
               q.push(i);
               vis[i] = 1;
            }
        }
    }
}

int main(){
    int **G=NULL;
    int *vis=NULL;
    int size=5;
    printf("Введите  количество вершин графа: \n");
    scanf("%d", &size);
    G = createG(size);
    printG(G, size);
    
    printf("\nВведите  начальную вершину:\n");
    
    vis = (int*)malloc(size*sizeof(int));
    
    int s = 1;
    scanf("%d", &s);
    printf("\nОбход графа: ");
    BFS(G, size, vis, s);
    
    return 0;
}
