#include <cstdio>
#include <iostream>
#include <fstream> 
#include <string>


//p e um vetor de tamanho n+1 com os numeros de linhas
//das matrizes
int solve(int *p, int n){
	//AQUI ENTRA O CÓDIGO!
	#define INT_MAX 2147483647
	int m[n][n];

	int i, j, k, L, q;
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
}



//NAO MODIFICAR!
int main(int argc, char **argv){
    
	//LEITURA DOS ARQUIVOS DE ENTRADA
	std::ifstream ifs (argv[1], std::ifstream::in);
	int n;
	int* P;
	
	ifs >> n;
	P = new int[n + 1];
	
	for(int i = 0; i <= n; i++){
		ifs >> P[i];
	}	
	
	printf("NUMERO DE MATRIZES = %d \n", n);
	printf("VALORES DE P: \n");
	for(int i = 0; i <= n; i++){
		printf("P[%d] = %d ", i, P[i]);
	}
    printf("\n");
	
	int sol = solve(P, n);
	
	printf("SOLUÇÃO PROVIDA: %d", sol);
	
	return 0;	
}

//476504