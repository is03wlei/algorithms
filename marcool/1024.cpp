#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int bfs(string fromGrid,map<string,int> &step)
{
	if (fromGrid=="123456780") return 0;
	int d[8]={-3,3,-1,1};
	step[fromGrid]=0;
	int head=0;
	int tail=1;
	vector<string> list;
	list.push_back(fromGrid);
	while(head<tail){
		fromGrid=list[head];
		int curStep=step[fromGrid];
		int zeroPos=fromGrid.find("0");
		for(int i=0;i<4;i++){
			if (zeroPos%3==0&&d[i]==-1) continue;
			if (zeroPos%3==2&&d[i]==1) continue;
			if (zeroPos<3&&d[i]==-3) continue;
			if (zeroPos>5&&d[i]==3) continue;
			int newZeroPos=zeroPos+d[i];
			string toGrid=fromGrid;
			swap(toGrid[zeroPos],toGrid[newZeroPos]);
			if (step.find(toGrid)==step.end()){
				list.push_back(toGrid);
				tail++;
				step[toGrid]=curStep+1;
				if (toGrid=="123456780") return step[toGrid]; 
			}
		}
		head++;
	}
	return -1;
}

int main()
{
	string fromGrid;
	cin>>fromGrid;
	map<string,int> step;
	cout<<bfs(fromGrid,step)<<endl;
	return 0;
}

