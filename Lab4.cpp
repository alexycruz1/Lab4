#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void crear_llenar(int***);
void imprimir_cubo(int*** ,int);

int main(int argc, char*argv[]){
	srand(time(NULL));
	int size = 12;
	
	int*** matriz = new int**[size];
	int*** matriz2 = new int**[size];

	crear_llenar(matriz);
	//imprimir_cubo(matriz,size);

	crear_llenar(matriz2);
	//imprimir_cubo(matriz2, size);
	return 0;
}

void imprimir_cubo(int*** cubo, int size){
        for(int i =0; i<size; i++){
                cout<<"piso: "<< i<<endl;
                for(int j=0;j<size; j++){
                        for(int k=0; k<size; k++){
                                cout << cubo[i][j][k];
                        }
                        cout<<endl;
                }
        }
}

void crear_llenar(int*** matriz){
	int size = 12;
	int cont_barcos = 0;
	int azar1 = (rand()% 12 + 0); 
	int azar2 = (rand()% 12 + 0);
	int azar3 = (rand()% 12 + 0);

	for (int i = 0; i < size; i++){
		matriz[i] = new int*[size];
	}

	//creacion de matriz
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			matriz[i][j] = new int[size];
		}	
	}

	//llenado de ceros
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			for (int k = 0; k < size; k++){
				matriz[i][j][k] = 0;
			}
		}
	}

	//llenado de barcos
	for (int i = 0; i <15 ; i++){
		if(matriz[rand()%12][rand()%12][rand()%12]==0){
			matriz[rand()%12][rand()%12][rand()%12]=1;
		}else{
			i--;
		}
	}
}

