#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void crear_llenar();

int main(int argc, char*argv[]){
	srand(time(NULL));

	return 0;
}

void crear_llenar(){
	int size = 12;
	int cont_barcos = 0;
	int azar1 = (rand()% 12 + 0); 
	int azar2 = (rand()% 12 + 0);
	int azar3 = (rand()% 12 + 0);

	int*** matriz = new int**[size];

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
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			for (int k = 0; k < size; k++){
				if (matriz[azar1][azar2][azar3] == 0 && cont_barcos < 15){
					azar1 = (rand()% 12 + 0); 
					azar2 = (rand()% 12 + 0);
					azar3 = (rand()% 12 + 0);

					matriz[azar1][azar2][azar3] = 1;
					cont_barcos++;
				}		
			}
		}
	}
}