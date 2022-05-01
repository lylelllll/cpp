#include <iostream>

using namespace std;

int main(int params_num,char* params[]){
	cout<<"params_num: "<<params_num<<endl;
	for(int i=0;i<params_num;i++){
		cout<<params[i]<<endl;
	}
	return 0;
}
