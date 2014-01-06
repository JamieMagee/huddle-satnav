#include "route.h"

int main()
{
  
  int graph[5][5];
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5 ; j++)
    {
      graph[i][j] = 999;
    }
  }
  graph[A][B] = 5;
  graph[A][D] = 5;
  graph[A][E] = 7;
  graph[B][C] = 4;
  graph[C][D] = 7;
  graph[C][E] = 2;
  graph[D][C] = 8;
  graph[D][E] = 6;
  graph[E][B] = 3;
  
  char path[5] = "ABC";
  printf("Test #1 %s\n",dist(graph, path)==9?"Passed":"Failed");
  
  strcpy(path,"AD");
  printf("Test #2 %s\n",dist(graph, path)==5?"Passed":"Failed");
  
  strcpy(path,"ADC");
  printf("Test #3 %s\n",dist(graph, path)==13?"Passed":"Failed");
  
  strcpy(path,"AEBCD");
  printf("Test #4 %s\n",dist(graph, path)==21?"Passed":"Failed");
  
  strcpy(path,"AED");
  printf("Test #5 %s\n",dist(graph, path)==-1?"Passed":"Failed");
  
  printf("Test #6 %s\n",traverse(graph, 'C', 'C', 0, 3, 999)==2?"Passed":"Failed");
  
  printf("Test #7 %s\n",traverse(graph, 'A', 'C', 4, 4, 999)==3?"Passed":"Failed");
  
  printf("Test #8 %s\n",shortest(graph, 'A', 'C')==9?"Passed":"Failed");
  
  printf("Test #9 %s\n",shortest(graph, 'B', 'B')==9?"Passed":"Failed");
  
  // TODO: Implement distance check in traverse
  // printf("Test #10 %s\n",traverse(graph, 'C', 'C', 0, 20, 30)==9?"Passed":"Failed");

  return 0;
}