#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<string>
#include<sstream>

using namespace std;
int main(){

int seedVal,digit,rnum, gamenum(1);
vector<char> seed;
string iseed,fname("Dicegame.txt");
ofstream fout;
char confirm('y'),yes;

fout.open(fname.c_str(),ios::out);
/*
if(!fout.is_open()){
	cerr<<"Unable to open file"<<endl;
	exit(20);
}
*/

while (confirm=='y'||confirm=='Y'){
	seedVal=0;
	cout<<"Would you like to enter a seed?(y/n): ";
	cin>>yes;

	if(yes=='y' || yes=='Y'){
		cout<<"Please enter your seed now: ";
		cin>>iseed;
		
		for(int i=0; i<iseed.length();i++){
			//~Keeps track of seed for debugging
			/*
			cout<<(int)iseed[i]<<" "<<iseed[i];
			if((int)iseed[i]==65){
				cout<<" "<<seedVal<<endl;
				continue;
			}
			*/
			seedVal+=(((int)iseed[i])-65)*pow(10,iseed.length()-i-1);
			seed.push_back(iseed[i]);

			//cout<<" "<<seedVal<<endl;
			
		}
	}

	else{
		seedVal=(int)time(0);
		digit=floor(log10(seedVal))+1;
		
		for(int i=digit; i>0; i--){
			int num=((seedVal%(int)pow(10,i))/pow(10,i-1))+65;
			seed.push_back((char)num);
		}
	}

	srand(seedVal);

	cout<<"\nEnter number of dice rolls: ";
	cin>>rnum;

	cout<<"You rolled a: ";

	for(int i=0; i<rnum;i++){
		if(i>=1)
			cout<<setw(15);
		cout<<(rand()%6)+1<<endl;
	}
	cout<<"\nSeed: ";
	
	fout<<"Game #"<<gamenum<<" seed: ";

	for(int i=0; i<seed.size(); i++){
		cout<<seed[i];
		fout<<seed[i];
	}

	cout<<endl;
	fout<<endl;

	cout<<"Seed saved in Dicegame.txt"<<endl<<endl;
	cout<<"Will you run the program again?: ";
	cin>>confirm;
	gamenum++;
	seed.clear();
	
}
fout.close();

return 0;

}



