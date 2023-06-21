#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAM 10

int main() {
	pid_t pid;
	int mat[TAM][TAM] = {{1,2,3,4,5,6,7,8,9,10},
		             {11,12,13,14,15,16,17,18,19,20},
			     {21,22,23,24,25,26,27,28,29,30},
			     {31,32,33,34,35,36,37,38,39,40},
			     {41,42,43,44,45,46,47,48,49,50},
			     {51,52,53.54,55,56,57,58,59,60},
			     {61,62,63,64,65,66,67,68,69,70},
			     {71,72,73,74,75,76,77,78,79,80},
			     {81,82,83,84,85,86,87,88,89,90},
			     {91,92,93,94,95,96,97,98,99,100}};
	int i, j, status;
	char palavra[20], comando[100];

	pid = fork();

	if (pid < 0) {
		printf("AVISO: erro na criacao do processo filho,ainda dentro do processo pai!");
		exit(1);
	} else if (pid == 0) {
		printf("Agora executando o processo filho!");
		execlp("/home/unisinos/Downloads/busca_palavra", "busca_palavra", NULL);
		exit(-1);
	} else {
		wait(&status);
		printf("MATRIZ ORIGINAL:\n ");
		for (i = 0; i < TAM; i++) {
			for (j = 0; j < TAM; j++) {
				printf("%d ", mat[i][j]);
			}
		}

		printf("MATRIZ TRANSPOSTA:\n ");
		for (i = 0; i < TAM; i++) {
			for (j = 0; j < TAM; j++); {
				printf("%d ", mat[j][i]);
			}
		}

	}

	return 0;
}



#include <stdio.h>
#include <stdlib.h>

int main () {
	printf("Aqui sera indicado a quantidade de vezes que a palavra indicada aparece no site de noticias do g1:\n");
	system("curl -silence -o g1.txt http//www.g1.globo.com");
        system("egrep -o carro g1.txt | wc -l");


	return 0;
}
