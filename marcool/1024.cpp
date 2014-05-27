#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int d[4]={-3,3,-1,1};

int bfs(string fromGrid,map<string,int> &step)
{
	if (fromGrid=="123456780") return 0;
	step[fromGrid]=0;
	int head=0;
	int tail=1;
	vector<string> list;
	list.push_back(fromGrid);
	while(head<tail){
		fromGrid=list[head];
		int curStep=step[fromGrid];
		int zeroPos=fromGrid.find("0");
		//cout<<fromGrid<<" "<<zeroPos<<" "<<head<<endl;
		for(int i=0;i<4;i++){
			int newZeroPos=zeroPos+d[i];
			if (newZeroPos<0||newZeroPos>=9) continue;
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
	map<string,int> step;
	cin>>fromGrid;
	cout<<bfs(fromGrid,step)<<endl;
	return 0;
}

