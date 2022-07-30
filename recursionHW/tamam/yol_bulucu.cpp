#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_way_valid(string str,string links[100],int current,char typenum,int linkscount){
	int i;
	int length=str.length();

	if((length>current+2) && typenum=='a') {
		for(i=0;i<linkscount;i++){
			if((links[i][4]==str[current+1]) && (links[i][0]==str[current])){
				if(is_way_valid(str,links,current+1,links[i][5],linkscount))
					return true;
			}
		}
		return false;
	}

	else if(length>current+2){
		for(i=0;i<linkscount;i++){
			if((links[i][4]==str[current+1]) && (links[i][0]==str[current]) && (links[i][1]==typenum)){
				if(is_way_valid(str,links,current+1,links[i][5],linkscount))
					return true;
			}
		}
		return false;
	}

	else{
		if(current==0){

			for(i=0;i<linkscount;i++){
				if((links[i][4]==str[current+1]) && (links[i][0]==str[current]))
					return true;
			}
			return false;

		}
			for(i=0;i<linkscount;i++){
				if((links[i][4]==str[current+1]) && (links[i][0]==str[current]) && (links[i][1]==typenum))
					return true;
			}
			return false;
	}
}

int main(){

	//------------------------------FILE READ----------------------------------------------------------------

	ifstream myfile("input.txt");

	string line,inputline;
	string linklines[100];
	string pathlines[100];

	int count = 0;
	int linklinecount;
	int pathlinecount;

	while (getline (myfile,line) && (line!= "Links:")) {

		inputline = line;

	}

	while (getline (myfile,line) && (line!= "Paths:")) {

		linklines[count] = line;

		count++;
	}

	linklinecount = count;

	count = 0;

	while (getline (myfile,line)) {

		pathlines[count] = line;

		count++;
	}

	pathlinecount = count;

	//----------------------------------------------------FILE WRITE---------------------------------------------------	
	
	ofstream myoutfile("output.txt");

	for(int i=0;i<pathlinecount;i++){

		if(is_way_valid(pathlines[i],linklines,0,'a',linklinecount)){

			myoutfile<<pathlines[i]<<" "<<"[YES]"<<endl;
		}else
			myoutfile<<pathlines[i]<<" "<<"[NO]"<<endl;
	}
	
	myoutfile.close();

	return 0;
}
