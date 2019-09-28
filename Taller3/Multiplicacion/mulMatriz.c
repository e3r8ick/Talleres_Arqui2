#include <emmintrin.h> //v3
#include <smmintrin.h> //v4


#include <stdio.h>

int main(){

	printf("\n PROBLEMA: MULTIPLICACIONES ENTRE MATRICES\n");
	float matrizA [4][4] = { 	{0.12,4.56,5.59,11.23},
								{2.1,2.3,2.65,34.12},
								{1.12,0.23,0.0,50.40},
								{45.56,3.89,4.12,5.23}};

	float matrizB [4][4] = { 	{2.593,0.123,3.456,1.789},
								{5.78,9.0,1.23,5.2},
								{3.23,2.127,1.24,0.56},
								{1.12,8.56,1.78,1.00}};

	__m128i matrixA [4];

	for (int row=0; row<4; row++) {
		matrixA[row] = _mm_set_epi32(matrizA[row][3], matrizA[row][2], matrizA[row][1], matrizA[row][0]);
	}

	__m128i matrizTranspuesta [4];
	//Genera la transpuesta de una matriz
	for (int row=0; row<4; row++) {
		matrizTranspuesta[row] = _mm_set_epi32(matrizB[3][row], matrizB[2][row], matrizB[1][row], matrizB[0][row]);
	}

	float result [4][4];

	for (int row=0; row<4; row++) {

		for (int col=0; col<4; col++) {

			__m128i mul = _mm_mullo_epi32(matrixA[row], matrizTranspuesta[col]);

			float sum = _mm_extract_epi32(mul,0) + _mm_extract_epi32(mul, 1) + _mm_extract_epi32(mul, 2) + _mm_extract_epi32(mul, 3);
			result[row][col] = sum;
		}
	}

	//Imprimir las amtrices
	for (int x=0; x<4; x++) {
		printf("|");
		for (int y=0; y<4; y++) {
			printf("%f   ", matrizA[x][y]);
		}
		if(x==1){
			printf("|    x    |");
		}
		else{
			printf("|    \t|");
		}
		for (int y=0; y<4; y++) {
			printf("%f   ", matrizB[x][y]);
		}
		printf("|");
		printf("\n");
	}
	// Imprimir Resultado
	printf("\nResultado\n");
	for (int x=0; x<4; x++) {
		printf("|");
		for (int y=0; y<4; y++) {
			printf("%f\t", result[x][y]);
		}
		printf("|");
		printf("\n");
	}

}
