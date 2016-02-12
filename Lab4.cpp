#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void crear_llenar(int***);
void imprimir_cubo(int*** ,int);
int tipo_ataque(int,int);
void jugador_tablero1(int***, int);
void jugador_tablero2(int***, int);

int main(int argc, char*argv[]){
	srand(time(NULL));
	int size = 12;
	int p1=15,p2=15;
	int wave1=3,wave2=3, expansive1=3,expansive2=3;
	int contador_subs1 = 0;
	int contador_subs2 = 0;
	bool terminar_juego=false;
	int bandera=1;

	int*** matriz = new int**[size];
	int*** matriz2 = new int**[size];

	crear_llenar(matriz);
	crear_llenar(matriz2);
	
	while(!terminar_juego){
		if(bandera ==1){
			jugador_tablero1(matriz, size);
			tipo_ataque(wave1,expansive1);
			if(p2=0){
				bandera=3;
				terminar_juego=true;
			}else{
				bandera=2;
			}	
		}
		if(bandera ==2){
			jugador_tablero2(matriz2, size);
			tipo_ataque(wave2,expansive2); 		
			if(p1=0){
                bandera=3;
                terminar_juego=true;
            }else{
               	bandera=1;
            }
		}
	}
	
	return 0;
}


void jugador_tablero1(int*** cubo, int size){
	cout << "------------------Mapa de submarinos de player 1-------------------" << endl;
	for(int i =0; i< size; i++){
                for(int j=0;j< size; j++){
                        for(int k=0; k < size; k++){
                                if (cubo[i][j][k] != 0){
                                	cout << "{(" << i << ", " << j << ", " << k << ")}" << endl;
                                }
                        }
                }
        }
        cout << endl;
}

void jugador_tablero2(int*** cubo, int size){
	cout << "------------------Mapa de submarinos de player 2-------------------" << endl;
	for(int i =0; i< size; i++){
                for(int j=0;j< size; j++){
                        for(int k=0; k < size; k++){
                                if (cubo[i][j][k] != 0){
                                	cout << "{(" << i << ", " << j << ", " << k << ")}" << endl;
                                }
                        }
                }
        }
        cout << endl;
}

int tipo_ataque(int wave, int expansive){
	int seleccion;
	bool seguir=true;
	while(seguir){
		cout<<"Seleccione el tipo de ataque: "<<endl
		<<"1-Normal"<<endl
		<<"2-Wave "<<"Quedan "<< wave<<" Por usar."<<endl
		<<"3-Expansive "<< "Quedan "<< expansive << " Por usar"<<endl;
		cin>> seleccion;
	
		if(seleccion == 2 && wave ==0){
			cout<< "No quedan mas ataques del tipo wave.";
		}else{
			if(seleccion == 3 && expansive == 0){
				cout<< "No quedan mas ataques del tipo expansive.";
			}else{
				seguir=false;
			}
	
		}
	}
	return seleccion;
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

