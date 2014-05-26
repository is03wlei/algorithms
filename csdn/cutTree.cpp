//problem description: http://hero.csdn.net/OnlineCompiler/Index?ID=593&ExamID=588&from=4

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(const int &fromNode,const vector<int> &weight,const vector<vector<int> > &edge,
		vector<bool> &visit, vector<int> &subTreeSum)
{
	if (visit[fromNode]) return 0;
	visit[fromNode]=true;
	subTreeSum[fromNode]=weight[fromNode];
	for(int i=0;i<edge[fromNode].size();i++){
		int toNode=edge[fromNode][i];
		subTreeSum[fromNode]+=dfs(toNode,weight,edge,visit,subTreeSum);
	}
	return subTreeSum[fromNode];
}

int main()
{
	int nodeNum,i;

	while(scanf("%d",&nodeNum)!=EOF){
		int weightSum=0;
		vector<int> weight(nodeNum);
		for(i=0;i<nodeNum;i++){
			scanf("%d",&weight[i]);
			weightSum+=weight[i];
		}

		vector<vector<int> > edge(nodeNum);

		for(i=1;i<nodeNum;i++){
			int fromNode,toNode;
			scanf("%d%d",&fromNode,&toNode);
			fromNode--;
			toNode--;
			edge[fromNode].push_back(toNode);
			edge[toNode].push_back(fromNode);
		}
		
		vector<bool> visit(nodeNum);
		vector<int> subTreeSum(nodeNum);

		dfs(0,weight,edge,visit,subTreeSum);

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

