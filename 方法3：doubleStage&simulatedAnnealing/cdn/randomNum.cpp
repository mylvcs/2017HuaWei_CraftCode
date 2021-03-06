#include<set>
#include<iterator>
#include"cdn.h"


/*
@产生m-n的随机数
*/
int random(int m, int n){
    double x = (double)rand() / RAND_MAX;
    int a = (int)(x*(n - m) + 0.5) + m;
    return a;
}
/*
@减去服务器群组中一个节点
*/
void reduceOneServer(set<int> &existNode){
	set<int>::iterator iter = existNode.begin();
	int i = 0;
	//随机创建一个网络节点
	int randNum = random(0, existNode.size() - 1);
	while ((i < randNum) && (iter != existNode.end()))
	{
	    ++iter;
	    ++i;
	}
	//删除该节点  
	existNode.erase(iter);
}
/*
@减去服务器群组中一个节点(重载)

*/
void reduceOneServer(set<int> &existNode,float* weight){
	int randNum, i;
	set<int>::iterator iter;
	while(1){
            i = 0;
	    randNum = random(0, existNode.size() - 1);
	    iter = existNode.begin();
	    while ((i < randNum) && (iter != existNode.end()))
	    {
	        ++iter;
	        ++i;
	    }
	    //删除该节点 
	    if((float)rand() / RAND_MAX < weight[*iter]){
	        existNode.erase(iter);
	        break;
           }
	}
}
/*
@增加一个服务器，但节点要求不在当前服务器群组中
*/
void addOneServer(set<int> &existNode, set<int> &notWantedNode){
	set<int>::iterator iter = notWantedNode.begin();
	int i = 0;
	//随机创建一个网络节点
	int randNum = random(0, notWantedNode.size() - 1);
	//遍历到想要的那个点
	while ((i < randNum) && (iter != notWantedNode.end())){
	    ++iter;
	    ++i;
	}
	//将该点数值加到服务器群组中
	existNode.insert(*iter);
}
/*
@增加一个服务器，但节点要求不在当前服务器群组中(重载)
*/
void addOneServer(set<int> &existNode,set<int> &notWantedNode,float* weight){
    int randNum, i;
    set<int>::iterator iter;
    while(1){
        i = 0;
	//随机创建一个网络节点
        randNum = random(0, notWantedNode.size() - 1);
	iter = notWantedNode.begin();
	//遍历到想要的那个点
	while ((i < randNum) && (iter != notWantedNode.end())){
	    ++iter;
	    ++i;
	}
	if((float)rand() / RAND_MAX > weight[*iter]){
	    existNode.insert(*iter);
	    break;
	}
   }
}
/*
@查找出除服务器网络节点
*/
void getRemainNode(vector<ConsumeNode> f, set<int> &existNode, set<int> &notWantedNode){
    bool isExist;
    notWantedNode.clear();  //清除之前的服务器
    for (size_t i = 0; i < f.size(); i++){
	isExist = false;
	for (set<int>::iterator iter = existNode.begin(); iter != existNode.end(); iter++){
	    if (f[i].linkedNodeID == *iter){
		isExist = true;
		break;
	    }
	}
	if (!isExist)
	    notWantedNode.insert(f[i].linkedNodeID);
    }
}
/*
@查找出除服务器网络节点
*/
void getRemainNode(int networkNodeNum, set<int> &existNode, set<int> &notWantedNode){
    bool isExist;
    notWantedNode.clear();  //清除之前的服务器
    for (size_t i = 0; i < networkNodeNum; i++){
	isExist = false;
	for (set<int>::iterator iter = existNode.begin(); iter != existNode.end(); iter++){
	    if (i == *iter){
		isExist = true;
		break;
	    }
	}
	if (!isExist)
	    notWantedNode.insert(i);
    }
}

