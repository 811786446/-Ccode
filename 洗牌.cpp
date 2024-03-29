//[编程题]洗牌
//洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。
//首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿 着第n + 1张到第2n张（下半堆）。接着就开始洗牌的过程，
//先放下右手的最后一张牌，再放下左手的最后一张牌，接着放下右手的倒数第二张牌，再放下左手的 倒数第二张牌，直到最后放下左手的第一张牌。
//接着把牌合并起来就可以了。 例如有6张牌，最开始牌的序列是1, 2, 3, 4, 5, 6。首先分成两组，左手拿着1, 2, 3；右手拿着4, 5, 6。
//在洗牌过程中按顺序放下了 6, 3, 5, 2, 4, 1。把这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，
//就变成了序列1, 4, 2, 5, 3, 6。 现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
//输入描述 :
//第一行一个数T(T ≤ 100)，表示数据组数。对于每组数据，第一行两个数n, k(1 ≤ n, k ≤ 100)，
//接下来一行有2n个数a1, a2, …, a2n(1 ≤ ai ≤ 1000000000)。表示原始牌组从上到下的序列。
//
//输出描述 :
//对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。
//
//输入例子 :
//3
//3 1
//1 2 3 4 5 6
//3 2
//1 2 3 4 5 6
//2 2
//1 1 1 1
//
//输出例子:
//1 4 2 5 3 6
//1 5 4 3 2 6
//1 1 1 1


#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> fun(int n, int k)
{
	vector<int> ret;
	int num;
	int i;
	stack<int> left;
	stack<int> right;

	for (i = 0; i < 2 * n; i++)
	{
		cin >> num;
		ret.push_back(num);
	}
	while (k--)
	{
		for (i = 0; i < n; i++)
		{
			left.push(ret[i]);
		}
		for (i = n; i < 2 * n; i++)
		{
			right.push(ret[i]);
		}
		ret.clear();
		for (i = 0; i < n; i++)
		{
			ret.push_back(right.top());
			ret.push_back(left.top());
			left.pop();
			right.pop();
		}
		reverse(ret.begin(), ret.end());
	}
	
	return ret;
}


int main()
{
	int T = 0;
	int n = 0, k = 0;
	cin >> T;
	vector<vector<int>> arr;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> k;
		vector<int> tmp;
		tmp = fun(n, k);
		arr.push_back(tmp);
	}
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
#endif