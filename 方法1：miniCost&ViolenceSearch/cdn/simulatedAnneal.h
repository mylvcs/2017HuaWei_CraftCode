#ifndef __SIMULATEDANNEAL_H__
#define __SIMULATEDANNEAL_H__

#include <set>  
#include "graph.h"


using namespace std;

#define E   2.2250738585072014e-308  // 迭代误差     

void simulatedAnneal(SparseGraph &gh, double t, float RANDX, float RANDY);  //利用模拟退火算法求解最短路径   
int random(int m, int n);
void addOneServer(set<int> &existNode, set<int> &notWantedNode);//随机增加一个服务器
void reduceOneServer(set<int> &existNode);   //随机减少一个服务器

#endif
