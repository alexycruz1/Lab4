#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void imprimir_cubo(int***, int);
int main(int argc, char*argv[]){
	srand(time(NULL));
	return 0;
}

void imprimir_cubo(int*** cubo, int size){
	for(int i =0; i<size; i++){
		cout<<"piso: "<< i<<endl;
		for(int j=0;j<size; j++){
			for(int k=0; i<size; k++){
				cout << cubo[i][j][k];
			}
			cout<<endl;
		}
	}

}











