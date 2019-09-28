#include <immintrin.h>
#include <emmintrin.h> //v3

#include <stdio.h>


int main(){

	printf("\n PROBLEMA: NUMEROS MAYORES ENTRE DOS VECTORES\n");
	short vectorA [8];
	short vectorB [8];
	printf("\nIntroduzca los valores del vector 0 de la matriz\n");
	for (int x=0; x<8; x++) {
		printf("matriz [0][%d]: ", x);
		scanf("%hu", &vectorA[x]);
	}

	printf("\nIntroduzca los valores del vector 1 de la matriz\n");
	for (int x=0; x<8; x++) {
		printf("matriz [1][%d]: ", x);
		scanf("%hu", &vectorB[x]);
	}
  printf("\nMatriz Generada:\n");
	printf("| ");
	for (int x=0; x<8; x++) {
		printf("%d \t", vectorA[x]);

	}
	printf(" |");
	printf("\n");
	printf("| ");
	for (int y=0; y<8; y++) {
		printf("%d \t", vectorB[y]);
	}
	printf(" |");
	printf("\n");
	printf("\n");

	__m128i vector1 = _mm_set_epi16 (	vectorA[0], vectorA[1], vectorA[2], vectorA[3],
										vectorA[4], vectorA[5], vectorA[6], vectorA[7]);

	__m128i vector2 = _mm_set_epi16 (	vectorB[0], vectorB[1],vectorB[2], vectorB[3],
										vectorB[4], vectorB[5], vectorB[6], vectorB[7]);

	__m128i result = _mm_cmpgt_epi16 (vector1, vector2);
	printf("Vector de Maximos\n");
	printf("[%d, ", (_mm_extract_epi16(result, 7)!=0) ? _mm_extract_epi16(vector1, 7) : _mm_extract_epi16(vector2, 7));
	printf("%d, ", (_mm_extract_epi16(result, 6)!=0) ? _mm_extract_epi16(vector1, 6) : _mm_extract_epi16(vector2, 6));
	printf("%d, ", (_mm_extract_epi16(result, 5)!=0) ? _mm_extract_epi16(vector1, 5) : _mm_extract_epi16(vector2, 5));
	printf("%d, ", (_mm_extract_epi16(result, 4)!=0) ? _mm_extract_epi16(vector1, 4) : _mm_extract_epi16(vector2, 4));
	printf("%d, ", (_mm_extract_epi16(result, 3)!=0) ? _mm_extract_epi16(vector1, 3) : _mm_extract_epi16(vector2, 3));
	printf("%d, ", (_mm_extract_epi16(result, 2)!=0) ? _mm_extract_epi16(vector1, 2) : _mm_extract_epi16(vector2, 2));
	printf("%d, ", (_mm_extract_epi16(result, 1)!=0) ? _mm_extract_epi16(vector1, 1) : _mm_extract_epi16(vector2, 1));
	printf("%d] ", (_mm_extract_epi16(result, 0)!=0) ? _mm_extract_epi16(vector1, 0) : _mm_extract_epi16(vector2, 0));
	printf("\n");


}
