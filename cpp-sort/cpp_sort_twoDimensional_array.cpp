#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	vector<vector<int>> a = {{1,5,8},{7,8,3},{4,6,5}};
	/*out:
	 1 5 8
	 7 8 3
	 4 6 5
	 */
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	/* out:
	 1 5 8
	 4 6 5
	 7 8 3
	 */
	int dimension = 2;

	//KEY POINT:
	sort(a.begin(),a.end(),[&dimension](vector<int> &a,vector<int> &b){return a[dimension]<b[dimension];});

	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	/*out:
	 7 8 3
	 4 6 5
	 1 5 8
	 */
	return 0;
}
