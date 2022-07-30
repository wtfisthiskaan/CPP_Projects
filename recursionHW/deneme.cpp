#include <iostream>
using namespace std;

bool is_way_valid(string str,string links[7],int current,char typenum){
	int i;
	int length=str.length();

	if((length>current+2) && typenum=='a') {
		for(i=0;i<7;i++){
			if((links[i][4]==str[current+1]) && (links[i][0]==str[current])){
				if(is_way_valid(str,links,current+1,links[i][5]))
					return true;
			}
		}
		return false;
	}

	else if(length>current+2){
		for(i=0;i<7;i++){
			if((links[i][4]==str[current+1]) && (links[i][0]==str[current]) && (links[i][1]==typenum)){
				if(is_way_valid(str,links,current+1,links[i][5]))
					return true;
			}
		}
		return false;
	}

	else{
		for(i=0;i<7;i++){
			if((links[i][4]==str[current+1]) && (links[i][0]==str[current]) && (links[i][1]==typenum))
				return true;
		}
		return false;
	}
}



int main() {
	string str="AAAB";
	string links[7];
	links[0]="A1->A2";
	links[1]="A1->B1";
	links[2]="A2->B1";
	links[3]="B1->B2";
	links[4]="B1->B3";
	links[5]="B1->A1";
	links[6]="B3->A1";
	if(is_way_valid(str,links,0,'a'))
		cout<<"true";
	else
		cout<<"false";

}