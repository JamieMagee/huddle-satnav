#include <stdio.h>

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"

int dist(int graph[][5], char *path);
int traverse(int graph[][5], char start, char stop, int min_junc, int max_junc);
int shortest(int graph[][5], char start, char end);
int min(int a, int b);
void matrix_mul(int a[][5], int b[][5], int product[][5]);
