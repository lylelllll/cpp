#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
	string s = "dig1 art can key dog";
	vector<string::size_type> st;
	string::size_type pos=0;

	/*pos = s.find("dig2",pos); out:4294967295 (2^32-1)*/
	/*cout<<string::npos<<endl; out:18446744073709551615 (2^64-1)*/

	//pos need +1,because start at pos will always find target
	/*while(flag){
		pos=s.find(' ',pos);
		if(pos>=s.size())flag=false;
		st.push_back(pos);
	}
	*/
	while((pos=s.find(' ',pos))!=string::npos){
		st.push_back(pos);
		cout<<pos<<' ';
		++pos;
	}
	cout<<st.size()<<endl;
	//out:4 8 12 16 4
	return 0;
}
