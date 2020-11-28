// A simple example of putting three items into a queue and
// then taking them off the queue.
#include<cstdio>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main()
{
	queue<char> q;

	q.push('a');
	q.push('b');
	q.push('c');
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();

	return 0;
}
