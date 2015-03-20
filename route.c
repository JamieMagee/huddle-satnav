#include "route.h"

/*
  Simply check is a path from one node in the graph to the next exists
  A distance of 999 is used to indicate that a path does not exist
*/
int dist(int graph[][5], char *path)
{
  int dist = 0;
  for (int i = 0 ; path[i+1] != '\0'; i++)
  {
    if (graph[path[i]-65][path[i+1]-65] != 999)
    {
      dist += graph[path[i]-65][path[i+1]-65];
      // A is ASCII character code 65
    }
    else return -1;
  }
  return dist;
}

/*
  Find the routes from one vertex to another using an adjacency matrix.
  If we find A^n[i][j] where A is the adjacency matrix, n is the 
  number of junctions minus one, i is the starting vertex, and j is the vertex 
  we wish to finish at, then the integer at that matrix location is the number
  of possible routes with n-1 junctions
*/

int traverse(int graph[][5], char start, char stop, int min_junc, int max_junc)
{
  int routes = 0;
  int adjacency[5][5] = {{ 0} };
  int product[5][5] = {{ 0 }};
  int temp[5][5] = {{ 0 }};
  
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      adjacency[i][j] = graph[i][j] != 999 ? 1 : 0;
      product[i][j] = adjacency[i][j];
    }
  }
    
  for (int i = 0; i < (min_junc-1); i++)
  {
    matrix_mul(product, adjacency, temp);
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        product[i][j] = temp[i][j];
        temp[i][j] = 0;
      }
    }
  }
  
  /* 
    This is used as the minimum number of junctions is 2, as there are
    no loops in this graph
  */
  min_junc = min_junc == 0 ? 2 : min_junc;
  
  for (int i = min_junc; i <= max_junc; i++)
  {
    matrix_mul(product, adjacency, temp);
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        product[i][j] = temp[i][j];
        temp[i][j] = 0;
      }
    }
    routes += product[start-65][stop-65];
  }
  return routes;
}

/*
  Shortest path between two vertices is found using Floyd's algorithm
*/

int shortest(int graph[][5], char start, char end)
{
  for(int k = 0; k < 5; k++)
  {
    for(int i = 0; i < 5; i++)
    {
      for(int j = 0; j < 5; j++)
      {
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }
  return graph[start-65][end-65];
}
int min(int a, int b)
{
  return a < b ? a : b;
}

void matrix_mul(int a[][5], int b[][5], int product[][5])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      for (int k = 0; k < 5; k++)
      {
        product[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}
