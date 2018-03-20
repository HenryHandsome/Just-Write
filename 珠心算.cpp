/*

珠心算是一种通过在脑中模拟算盘变化来完成快速运算的一种计算技术。珠心算训练， 既能够开发智力，又能够为日常生活带来很多便利，因而在很多学校得到普及。
某学校的珠心算老师采用一种快速考察珠心算加法能力的测验方法。他随机生成一个正整数集合，集合中的数各不相同，然后要求学生回答：
其中有多少个数，恰好等于集合中另外两个（不同的）数之和？
最近老师出了一些测验题，请你帮忙求出答案。


输入共两行，第一行包含一个整数 n，表示测试题中给出的正整数个数。
第二行有 n 个正整数，每两个正整数之间用一个空格隔开，表示测试题中给出的正整数。
对于 100%的数据，3 ≤ n ≤ 100，测验题给出的正整数大小不超过 10,000。


*/


#include<iostream>
#include<algorithm>
using namespace std;

int f(int a[], int i, int n) {
	int sum = 0;
	int x = a[n];
	for (; a[n-1] > x / 2;) {
		if (x == a[i] + a[n - 1]) {
			sum++;
			break;
		}
		else if (x > a[i] + a[n - 1]) {
			i++;
		}
		else if (x < a[i] + a[n - 1]) {
			n--;
		}
	}
	return sum;
}

int main() {
	int a[101];
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i <n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = n-1; i >=2; i--)
		sum += f(a, 0, i);
	cout << sum << endl;
}
