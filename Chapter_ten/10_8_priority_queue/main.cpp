//使用优先队列容器模拟细胞分裂
//priority_queue特点：
//1.其基础容器必须是支持随机访问的顺序容器
//2.支持栈和队列的size、empty、push、pop等几个成员函数
//3.不支持比较操作
//与栈类似，优先级队列提供一个top函数，可以获得下一个即将被弹出元素（即最‘大’元素）的引用


#include <iostream>
#include <string>
#include <time.h>
#include <functional>       //函数对象头文件
#include <iterator>         //迭代器头文件
#include <algorithm>        //算法头文件
//容器类的头文件
#include <vector>           //向量
#include <list>             //链表
#include <forward_list>     //单向链表
#include <array>            //数组
#include <stack>            //栈
#include <queue>            //队列

using namespace std;

const int SPLIT_TIME_MIN = 500;     //细胞分裂最短时间
const int SPLIT_TIME_MAX = 2000;    //细胞分裂最长时间

class Cell;
priority_queue<Cell> cellQueue;

class Cell
{
public:
	Cell(int birth)
		:id(count++) 
	{
		time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN)) + SPLIT_TIME_MIN;
	}

	int GetId() const { return id; }
	int GetSplitTime() const { return time; }
	bool operator < (const Cell& s) const { return (time > s.time); }

	void split() const
	{
		Cell child1(time), child2(time);
		cout << time << "s:Cell #" << id << "splits to #" << child1.GetId() << "and #" << child2.GetId() << endl;
		cellQueue.push(child1);   //入队
		cellQueue.push(child2);
	}


private:
	static int count;       //细胞总数
	int id;                 //当前细胞编号
	int time;               //细胞分裂时间
};


int Cell::count = 0;



int main()
{
	srand(static_cast<unsigned>(time(0)));
	int t;
	cout << "Simulation time:";
	cin >> t;

	cellQueue.push(Cell(0));

	while (cellQueue.top().GetSplitTime() <= t)
	{
		cellQueue.top().split();    //分裂
		cellQueue.pop();            //弹出最顶元素
	}


	system("pause");
	return 0;
}