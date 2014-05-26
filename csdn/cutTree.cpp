//problem description: http://hero.csdn.net/OnlineCompiler/Index?ID=593&ExamID=588&from=4

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_NODES=100000;
int weight[MAX_NODES];
int subTreeSum[MAX_NODES];
bool visit[MAX_NODES];
vector<vector<int> > edge(MAX_NODES);


int dfs(const int &fromNode)
{
	if (visit[fromNode]) return 0;
	visit[fromNode]=true;
	subTreeSum[fromNode]=weight[fromNode];
	for(int i=0;i<edge[fromNode].size();i++){
		int toNode=edge[fromNode][i];
		subTreeSum[fromNode]+=dfs(toNode);
	}
	return subTreeSum[fromNode];
}

int main()
{
	int nodeNum,i;

	while(scanf("%d",&nodeNum)!=EOF){
		int weightSum=0;
		for(i=0;i<nodeNum;i++){
			scanf("%d",&weight[i]);
			weightSum+=weight[i];
		}

		edge.clear();

		for(i=1;i<nodeNum;i++){
			int fromNode,toNode;
			scanf("%d%d",&fromNode,&toNode);
			fromNode--;
			toNode--;
			edge[fromNode].push_back(toNode);
			edge[toNode].push_back(fromNode);
		}
		
		memset(visit,false,sizeof(bool)*nodeNum);
		//for(i=0;i<nodeNum;i++)cout<<visit[i]<<endl;

		dfs(0);

		//printf("%d\n",weightSum);

		int minDiff=-1;
		for(i=0;i<nodeNum;i++){
			//printf("%d\n",subTreeSum[i]);
			if (minDiff==-1||abs(subTreeSum[i]+subTreeSum[i]-weightSum)<minDiff) 
				minDiff=abs(subTreeSum[i]+subTreeSum[i]-weightSum);
		}
		printf("%d\n",minDiff);
	}
}

