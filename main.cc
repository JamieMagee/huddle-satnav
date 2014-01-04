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
  cout << (dist(graph, path)==9?"Test #1 Passed":"Test #1 Failed") << endl;
  
  strcpy(path,"AD");
  cout << (dist(graph, path)==5?"Test #2 Passed":"Test #2 Failed") << endl;
  
  strcpy(path,"ADC");
  cout << (dist(graph, path)==13?"Test #3 Passed":"Test #3 Failed") << endl;
  
  strcpy(path,"AEBCD");
  cout << (dist(graph, path)==21?"Test #4 Passed":"Test #4 Failed") << endl;
  
  strcpy(path,"AED");
  cout << (dist(graph, path)==-1?"Test #5 Passed":"Test #5 Failed") << endl;
  
  cout << (traverse(graph, 'C', 'C', 0, 3, 999)==2?"Test #6 Passed":"Test #6 Failed") << endl;
  
  cout << (traverse(graph, 'A', 'C', 4, 4, 999)==3?"Test #7 Passed":"Test #7 Failed") << endl;
  
  cout << (shortest(graph, 'A', 'C')==9?"Test #8 Passed":"Test #8 Failed") << endl;
  
  cout << (shortest(graph, 'B', 'B')==9?"Test #9 Passed":"Test #9 Failed") << endl;
  
  // TODO: Implement distance check in traverse
  // cout << (traverse(graph, 'C', 'C', 0, 20, 30)==9?"Test #10 Passed":"Test #10 Failed") << endl;

  return 0;
}