#include <iostream>
using namespace std;

int main(){
	int A[13]={0,0,0,1,1,1,0,1,1,0,0,1,1},
	B[13]={1,1,1,1,1,1,1,1,0,1,1,1,1};
	int c,d;
	for(int i=0;i<13;i++){
		if (A[i]==1){
			c++;
		}
		if (B[i]==1){
			d++;
		}
	}

	int Ra[c],Rb[d];
	int conta=0,contb=0;
	
	for(int i=0;i<13;i++){
		if(A[i]==1){
			cout<<i<<endl;
			Ra[conta]=i;
			conta++;
		}
	}
	for (int j=0;j<13;j++){
		if(B[j]==1){
			cout<<j<<endl;
			Rb[contb]=j;
			contb++;
		}	
	}
	

	int Ga[conta],Gb[conta],den=0;
	Gb[0]=Rb[0];
	for (int i=1;i<conta;i++){
		for(int j=1;j<contb;j++){
			if(Rb[j]-Ra[i-1]>den){
				Gb[i]=Rb[j];
			}
		}
		
	}
	for (int i=0;i<conta;i++){
		cout <<Ra[i]<<"\t"<<Gb[i]<<endl;
	}
	
	
	
	
	return 0;
}
