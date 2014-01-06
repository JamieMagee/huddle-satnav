#include "route.h"

int main()
{
  
  char* colour;
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
  
  colour = dist(graph, "ABC")==9?KGRN:KRED;
  printf("%sTest #1 %s\n", colour, dist(graph, "ABC")==9?"Passed":"Failed");
  
  colour = dist(graph, "AD")==5?KGRN:KRED;
  printf("%sTest #2 %s\n", colour, dist(graph, "AD")==5?"Passed":"Failed");
  
  colour = dist(graph, "ADC")==13?KGRN:KRED;
  printf("%sTest #3 %s\n", colour, dist(graph, "ADC")==13?"Passed":"Failed");
  
  colour = dist(graph, "AEBCD")==21?KGRN:KRED;
  printf("%sTest #4 %s\n", colour, dist(graph, "AEBCD")==21?"Passed":"Failed");
  
  colour = dist(graph, "AED")==-1?KGRN:KRED;
  printf("%sTest #5 %s\n", colour, dist(graph, "AED")==-1?"Passed":"Failed");
  
  colour = traverse(graph, 'C', 'C', 0, 3, 999)==2?KGRN:KRED;
  printf("%sTest #6 %s\n", colour, traverse(graph, 'C', 'C', 0, 3, 999)==2?"Passed":"Failed");
  
  colour = traverse(graph, 'A', 'C', 4, 4, 999)==3?KGRN:KRED;
  printf("%sTest #7 %s\n", colour, traverse(graph, 'A', 'C', 4, 4, 999)==3?"Passed":"Failed");
  
  colour = shortest(graph, 'A', 'C')==9?KGRN:KRED;
  printf("%sTest #8 %s\n", colour, shortest(graph, 'A', 'C')==9?"Passed":"Failed");
  
  colour = shortest(graph, 'B', 'B')==9?KGRN:KRED;
  printf("%sTest #9 %s\n", colour, shortest(graph, 'B', 'B')==9?"Passed":"Failed");
  
  // TODO: Implement distance check in traverse
  // printf("%sTest #10 %s\n", colour, traverse(graph, 'C', 'C', 0, 20, 30)==9?"Passed":"Failed");
  
  printf(KNRM);

  return 0;
}