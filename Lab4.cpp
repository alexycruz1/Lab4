#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

int ataque_expansive(int*** matriz, int size);
bool ataque_normal(int*** matriz, int size);
void crear_llenar(int***);
void imprimir_cubo(int*** ,int);
int tipo_ataque(int,int);
void jugador_tablero1(int***, int);
void jugador_tablero2(int***, int);
int wave(int***,int,int);

int main(int argc, char*argv[]){
	srand(time(NULL));
	int size = 12;
	int p1=15,p2=15;
	int wave1=3,wave2=3, expansive1=3,expansive2=3;
	bool terminar_juego=false;
	int bandera=1;
	int*** matriz = new int**[size];
	int*** matriz2 = new int**[size];

	crear_llenar(matriz);
	crear_llenar(matriz2);
	
	while(!terminar_juego){
		if(bandera ==1){
			jugador_tablero1(matriz, size);
			int seleccion = tipo_ataque(wave1,expansive1);
			if(seleccion ==1){
				ataque_normal(matriz2, size);
				bool destruyo = ataque_normal(matriz2, size);
				if (destruyo){
					p2--;
				}
			}
			if(seleccion == 2){
				int punto;
				cout<< "Ingrese el punto:";
				cin>>punto;
				int restar_barcos = wave(matriz2,punto,seleccion);
				p2 = p2-restar_barcos;			
				wave1--;	
			}
			if(seleccion == 3){
				int punto;
                                cout<< "Ingrese el punto:";
                                cin>>punto;
                                int restar_barcos = wave(matriz2,punto,seleccion);
				p2 = p2-restar_barcos;
                                wave1--;
                        }
			if(seleccion == 4){
				int punto;
                cout<< "Ingrese el punto:";
                cin>>punto;
                int restar_barcos = wave(matriz2,punto,seleccion);
				p2 = p2-restar_barcos;
                wave1--;
            }

			if(seleccion == 5){
				int destruyo = ataque_expansive(matriz2, size);
				p2 - destruyo;
				expansive1--;
			}

			if(p2=0){
				terminar_juego=true;
			}else{
				bandera=2;
			}
		}

		if(bandera ==2){
			jugador_tablero2(matriz2, size);
			int seleccion= tipo_ataque(wave2,expansive2);
			if(seleccion ==1){
				bool destruyo = ataque_normal(matriz, size);
				if (destruyo){
					p1--;
				}
				cout << p1;
            		}
            		if(seleccion == 2){
            			int punto;
                        cout<< "Ingrese el punto:";
                        cin>>punto;
                        int restar_barcos = wave(matriz,punto,seleccion);
						p1 = p1-restar_barcos;
						wave2--;
            		}
            		if(seleccion == 3){
             			int punto;
                        cout<< "Ingrese el punto:";
                        cin>>punto;
                        int restar_barcos = wave(matriz,punto,seleccion);
						p1 = p1-restar_barcos;
						wave2--;
            		}			
            }
            if(seleccion == 2){
            	wave2--;
            }
            if(seleccion == 3){
             	wave2--;
            }			
 			if(seleccion == 4){
				int punto;
                cout<< "Ingrese el punto:";
                cin>>punto;
                int restar_barcos = wave(matriz,punto,seleccion);
				p1 = p1-restar_barcos;
	           	wave2--;
            		}
			if(seleccion == 5){
               	expansive2--;
            }
            int destruyo = ataque_expansive(matriz, size);
            p1 - destruyo;
            expansive2--;
            }


			if(p1=0){
               	terminar_juego=true;
            }else{
               	bandera=1;
            }
		}
	}

	cout << "Ganaste!" << endl;

	//inicio de borrado
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			delete [] matriz[i][j];
		}
	}

	for (int i = 0; i < size; i++){
		delete[] matriz[i];
	}

	delete[] matriz;

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			delete [] matriz2[i][j];
		}
	}

	for (int i = 0; i < size; i++){
		delete[] matriz2[i];
	}

	delete[] matriz2;
	//fin de borrado

	return 0;
}

int wave(int*** matriz, int punto, int opcion ){
	int eliminados=0;
	if(opcion == 2){
		for(int i=0; i<12;i++){
			for(int j=0; j<12;j++){
				if(matriz[punto][i][j]==1){
					matriz[punto][i][j]=0;
					cout<<"Barco destruido en: "<<punto<< " "<< i << " "<< j<< " " <<endl;
					eliminados++;		
				}				
			}
		}	
	}
	if(opcion == 3){
		for(int i=0; i<12;i++){
            for(int j=0; j<12;j++){
                if(matriz[i][punto][j]==1){
                    matriz[i][punto][j]=0;
                    cout<<"Barco destruido en: "<<punto<< " "<< i << " "<< j<< " " <<endl;
                    eliminados++;
                } 
            }
        } 
	}

	if(opcion == 4){
		for(int i=0; i<12;i++){
            for(int j=0; j<12;j++){
                if(matriz[i][j][punto]==1){
                    matriz[i][j][punto]=0;
                    cout<<"Barco destruido en: "<<punto<< " "<< i << " "<< j<< " " <<endl;
                    eliminados++;
                } 
            }
        } 
	}
	
	return eliminados;
}

int ataque_expansive(int*** matriz, int size){
	int x, y, z;
	int destruyo = 0;

	cout << "Ingrese el punto x: ";
	cin >> x;
	cout << endl;

	while(x <= 0 || x >= 11){
		cout << "Ingrese el punto x: ";
		cin >> x;
		cout << endl;
	}

	cout << "Ingrese el punto y: ";
	cin >> y;
	cout << endl;

	while(y <= 0 || y >= 11){
		cout << "Ingrese el punto y: ";
		cin >> y;
		cout << endl;
	}

	cout << "Ingrese el punto z: ";
	cin >> z;
	cout << endl;

	while(z <= 0 || z >= 11){
		cout << "Ingrese el punto z: ";
		cin >> z;
		cout << endl;
	}

	for (int i = x - 1; i < x + 2; ++i){
		for (int j = y - 1; j < y + 2; ++j){
			for (int k = z - 1; k < z + 2; ++k){
				if (matriz[i][j][k] == 1){
					matriz[i][j][k] = 0;
					cout << "Se elimino el submarino en el punto: " << "(" << i << ", " << j << ", " << k << ")" << endl;
					destruyo++;
				}
			}
		}
	}

}

bool ataque_normal(int*** matriz, int size){
	int x, y, z;
	bool destruyo = false;
	cout << "Ingrese el punto x: ";
	cin >> x;
	cout << endl;

	while(x < 0 || x > 11){
		cout << "Ingrese el punto x: ";
		cin >> x;
		cout << endl;
	}

	cout << "Ingrese el punto y: ";
	cin >> y;
	cout << endl;

	while(y < 0 || y > 11){
		cout << "Ingrese el punto y: ";
		cin >> y;
		cout << endl;
	}

	cout << "Ingrese el punto z: ";
	cin >> z;
	cout << endl;

	while(z < 0 || z > 11){
		cout << "Ingrese el punto z: ";
		cin >> z;
		cout << endl;
	}

	if (matriz[x][y][z] == 1){
		matriz[x][y][z] = 0;
		cout << "Barco destruido en: " << "(" << x << ", " << y << ", " << z << ")" << endl << endl;
		destruyo = true;
	}

	return destruyo;
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
		<<"2-Wave en XY "<<endl
		<<"3-Wave en XZ "<<endl
		<<"4-Wave en YZ"<<endl
		<<"5-Expansive "<< endl << endl
		<<"Quedan "<<wave<< " Waves"<<endl
		<<"Quedan " << expansive<<" Expansive"<<endl;
		cin >> seleccion;
		cout << endl;
	
		if(seleccion == 2 && wave ==0 || seleccion ==3 && wave==0 || seleccion ==4 && wave==0){
			cout<< "No quedan mas ataques del tipo wave."<<endl;
		}else{
			if(seleccion == 5 && expansive == 0){
				cout<< "No quedan mas ataques del tipo expansive."<<endl;
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

