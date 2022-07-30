#include <iostream>
#include <string>

using namespace std;

bool is_path_true(string str,int matrix[5][5],int current) {
	int i;
	int length=str.length();
	//cout<<"length";
	if(length>current+2) {

		if(matrix[str[current]-48][str[current+1]-48]==1){cout<<str[current]<<endl; 
			return is_path_true(str,matrix,current+1);
		}
		else
			return false;
	}

	else{cout<<str[current]<<endl;
	cout<<str[current+1]<<endl;  
		if(matrix[str[current]-48][str[current+1]-48]==1){
			return true;
		}
		else
			return false;
	}

}

void possible_ways(string str){
	int totala=2;
	int totalb=3;
	int all_a[2]={0,1};
	int all_b[3]={2,3,4};
	int total=2*2*3;
	char ways[total][3];
	int strcount=0;
	for(int i=0;i<3;i++) {

		if(i==0) {
			if(str[i]=='A'){
				for(int j=0;j<totala;j++){
					ways[count][i]=all_a[j]-48;
					count++;
				} }
			else if(str[i]=='B'){
				for(int j=0;j<totalb;j++){
					ways[count][i]=all_b[j]-48;
					count++;
				}
			}
		}

		else {
			//katla
				if(str[i]=='A'){
					for(int j=0;j<totala;j++){
						ways[count][i]=all_a[j]-48;
						count++;
					}
				}
				else if(str[i]=='B'){
					for(int j=0;j<totalb;j++){
						ways[count][i]=all_b[j]-48;
						count++;
					} 
				}
			}




		}




	}




int main() {
	/*int matrix[5][5]={	{0,1,1,0,0},
						{0,0,1,0,0},
						{0,0,0,1,1},
						{0,0,0,0,0},
						{1,0,0,0,0}};


	if(is_path_true("01240",matrix,0))
		cout<<"wuhuuu";
	else
		cout<<"a"; */


}