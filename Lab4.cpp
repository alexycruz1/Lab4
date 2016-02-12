#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char*argv[]){
	srand(time(NULL));
	int azar = (rand()% 100 - 500); 
	int size = 12;

	int*** matriz = new int**[size];

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			matriz[i][j] = new int*[size];
		}	
	}

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			matriz[i][j] = int azar = (rand()% 12 + 0)
		}
	}
	
	return 0;
}
