#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main (){
//cabeçalho
setlocale(LC_ALL, "Portuguese");
printf("\n\n");	
printf("		          P  /_\\  P                              	\n");
printf("		         /_\\_|_|_/_\\                             	\n");
printf("		     n_n | ||. .|| | n_n         Bem vindo ao    	\n");
printf("		     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!	\n");	
printf("		    |_____| ' _ ' |_____|                        	\n");
printf("		          \\__|_|__/								\n");
printf("\n\n");	




//aleatoriedade	
	int segundos = time(0);
	srand(segundos);
	int numerogrande = rand();
	int numerosecreto = numerogrande % 100;
//pontos 
	int chute = 0;
	int tentativas = 1;
	double pontos = 1000;
	int acertou = 0;
	
//Escolha do nível
	int numerodetentativas = 0;
	int nivel = 0;
	printf("(1)Nível fácil (2)Nível médio (3)Nível difícil\n\n");
	printf("Escolha seu nível: ");
	scanf("%d",&nivel);	

//Escolha do nível	
	switch(nivel){
		case 1:
			numerodetentativas =  15;
		break;
		case 2:
			numerodetentativas = 10;
		break;
		default:
			
			numerodetentativas = 6;
		break; 
	}
	
//Inicio do jogo 
		int i=0;
	for(i = 1; i <= numerodetentativas; i++){
		printf ("Tentativa %d\n", tentativas);
		printf ("Qual é o seu chute? ");
		scanf ("%d",&chute);
		
		if (chute < 0){
			printf("Você não pode chutar números negativos!\n");
			continue; 
		}
	
		acertou = chute == numerosecreto;
		int maior = chute > numerosecreto;
		
		if (acertou){
			break;
		}
		else if (maior){
			printf ("Seu chute foi maior que o número secreto\n");
		} else {
			printf ("Seu chute foi menor que o número secreto\n ");
		}
		
		tentativas++;	
		
		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos;
	}


//Vitória ou Derrota	
	printf ("Fim de jogo!\n");
	if(acertou){
		printf("Você ganhou!\n");
		printf ("Você acertou em %d tentativas!\n", tentativas);
		printf ("Total de pontos %.1f\n",pontos);
	}else {
		printf("Você perdeu!Tente novamente!");
	} 
	
}






