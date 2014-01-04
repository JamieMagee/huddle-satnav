#include <string.h>
#include <iostream>
#include <climits>

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4

using namespace std;

int dist(int graph[][5], char *path);
int traverse(int graph[][5], char start, char stop, int min_junc, int max_junc, int max_dist);
int shortest(int graph[][5], char start, char end);
void matrix_mul(int a[][5], int b[][5], int product[][5]);