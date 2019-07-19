#pragma once
#if 0
int a[10], book[10], total, n;
void dfs(int step);
void dfs_match(int step);
int n, m, p, q, k, min;
int a[51][51], book[51][51];
void dfs_maze(int x, int y, int step);
int bfs();
#endif
int getnum(int i, int j);
char a[20][21];
int book[20][20], max, mx, my, n, m;
void dfs(int x, int y);