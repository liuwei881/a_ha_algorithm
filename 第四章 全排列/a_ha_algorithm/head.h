#pragma once
#if 0
int a[10], book[10], total, n;
void dfs(int step);
void dfs_match(int step);
int n, m, p, q, k, min;
int a[51][51], book[51][51];
void dfs_maze(int x, int y, int step);
int bfs();
int getnum(int i, int j);
char a[20][21];
int book[20][20], max, mx, my, n, m;
void dfs(int x, int y);
int a[51][51]; //假设土地的大小不超过50*50
int book[51][51], n, m, flag = 0;
void dfs_g(int x, int y, int front);
#endif