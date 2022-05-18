#include <queue>
#include <iostream>

using namespace std;

static bool cmp(pair<int,int> &a,pair<int,int>&b){
	return a.second>b.second;
}

int main(){
	pair<int,int> a={1,3};
	pair<int,int> b={1,5};
	pair<int,int> c={1,4};
	vector<pair<int,int>> va;
	va.push_back(a);
	va.push_back(b);
	va.push_back(c);
	for(int i = 0;i<3;i++)cout<<va[i].second<<' ';
	puts("");
	/*xiao gen dui*/
	priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> q(cmp);
	q.push(a);q.push(b);q.push(c);
	while(q.size()){
		cout<<q.top().second<<' ';
		q.pop();
	}
	puts("");
	/*
	 *out:
	 3 5 4 
	 3 4 5 
	 *
	 *
	 * */
	return 0;
}
