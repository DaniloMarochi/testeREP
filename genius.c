#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COR_AMARELO     printf("\033[1;33m");
#define COR_BRANCO    	printf("\033[1;97m");
#define COR_VERDE   	printf("\033[1;32m");
#define COR_VERMELHO    printf("\033[1;31m");
#define COR_CINZA       printf("\033[1;37m");
#define COR_AZUL    	printf("\033[1;34m");


//variaveis globais
int seq[6][6];
int vel;
int fase = 0;
int contador = 0;
int tempo = 500;
int usu[6];
int cont = 0;
int aux = 0;
int pont = 0;
char resp;

//protótipo das funções
void inicia();
void geranum();
void menu();
void liga();
void muda(int i, int t, int habilita);
int verifica();
void mostraganhou();
void mostraerrou();


int main(){
	int i;
	char resp = 's';
	
while(resp == 's' || resp == 'S'){
    
	tempo = 500; //reseta o tempo
	pont = 0; //reseta a pontuação
	contador = 0; //reseta a contagem da sequencia
	fase = 0; //reseta a fase
	vel = 0; //reseta a velocidade

	inicia();
	system("clear");
	geranum();
	menu();
	liga();
	
	while(1){		
		for(i = 0; i <= contador; i++){
			printf("\nDigite a sequencia: \n");
			printf(" Numero %d: ", i + 1);
			scanf("%d", &usu[i]);
			muda(usu[i],100,1);			
		}
		
		if (verifica()){
			contador++;
			if (contador %6 == 0 ){
				printf("Preparando para a nova fase...");
				
				fase++;
				vel++;
				tempo-=100;
				if (tempo < 100){
					tempo = 500;
					fase = 0;
				}
				//reseta a contagem da sequencia
				contador = 0;
			}
			mostraganhou();
			liga();
			cont = 0;
		}else{
			aux = 1;
			mostraerrou();
			break;
			//sai do laço
			cont = 0;
		}
	}
	if(aux == 1){
		scanf("%c", &resp);
	}
	if(resp == 'n'){
		exit(0);
    }
	

}
return 0;
}

void inicia(){
   int  c = 0;
   char cmd_MSDOS[50];
   char barra[50];
   
   strcpy(barra, ""); //strcpy realiza copia do conteudo de uma variável a outra
   
   for(c = 0; c<= 15; c++){
   	   system("clear");
   	   //if(c<=15){
			sprintf(cmd_MSDOS, "color %xF", c);
			strcat(barra, ":"); //strcat concatenação de uma variável com outra
			printf("%s\n", barra);
			printf(":  GENIUS : \n");
			printf("%s\n", barra);
			
			if (c == 15){
			COR_CINZA
			}else{
			system(cmd_MSDOS);
		}
		
   }
}

void geranum(){
	int lin, col;
	int num;
	
	srand(time(NULL));
	for(lin = 0; lin <= 4; lin++){
		for(col = 0; col<= 4; col++){
			//gera numeros aleatorios de 0 a 3
			num = (rand()%4);
			while (num==seq[lin][col-1]){
				num = (rand()%4);
			}
			seq[lin][col] = num;
		}
	}
}

void menu(){
	printf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ\n");
	printf("Û                    GENIUS                   Û\n");
	printf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ\n");
	printf(": VELOCIDADE %d - FASE %d \n", vel + 1, fase + 1);
	printf("iniciando... \n");
}

void liga(){
	int j;
	for(j = 0; j <= contador; j++){
		muda(seq[fase][j], tempo, 0);
		menu();
	}	
}

void muda(int i, int t, int habilita){
	switch(i){
		//cor azul
	  case 0:
	     COR_AZUL
	     printf("\n::: 0 ::::");
	  break;
	  
		//cor vermelha
	  case 1:
	     COR_VERMELHO
	     printf("\n::: 1 ::::");
	  break;
	  
		//cor verde
	  case 2:
	     COR_VERDE
	     printf("\n::: 2 ::::");
	  break;
	  
		//cor amarela
	  case 3:
	     COR_AMARELO
	     printf("\n::: 3 ::::");
	  break;
	}
	if(habilita == 0){
	
	
	system("clear");
	
	COR_CINZA
}
}

int verifica(){
	int c, l;
	l = fase;
	for(c = 0; c<= contador; c++){
		if (seq[l][c]!= usu[c]){
			return 0;
			break;
		}
	}
	return 1;
}

void mostraganhou(){
	if(fase == 0){
		pont = pont + 10;
	}
	if(fase == 1){
		pont = pont + 20;
	}
	if(fase == 2){
		pont = pont + 30;
	}
	if(fase == 3){
		pont = pont + 40;
	}
	if(fase == 4){
		pont = pont + 50;
	}
	if(fase == 5){
		pont = pont + 60;
	}
	
	printf("\n\n:::::::::::::::::::::: \n");
	printf(":   Voce acertou!    : \n");
	printf(":::::::::::::::::::::: \n");
	printf(": VELOCIDADE %d - FASE %d -", vel + 1, fase + 1);
	printf(" PONTUACAO: %d", pont);
	system("color 5F");
	system("clear");
	menu();
}

void mostraerrou(){
	
	printf("\n\n:::::::::::::::::::::: \n");
	printf(":     Voce errou!    : \n");
	printf(":::::::::::::::::::::: \n");
	printf(": VELOCIDADE %d - FASE %d \n", vel + 1, fase + 1);
	printf(":Total de pontos: %d\n", pont);
	printf(":Voce deseja continuar jogando?(s/n):");
	scanf("%c", &resp);
	if(resp == 's'){
		tempo = 500;
		pont = 0;
		contador = 0;
		fase = 0;
		vel = 0;
		main();
	}
	if(resp == 'n'){
		exit(0);
    }
}