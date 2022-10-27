#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//Docente: Anderson Avila Santos
//Discentes: José Alexandre de Freitas e Mateus Gonçalves de Oliveira

char velha[3][3];  //matriz
int i, j, linha, coluna, jogador, ganhou, jogadas, opcao;           //indices

void jogo(){
    printf("\n\t   Jogo da Velha");
    printf("\n\n\t   '0'  '1'  '2'\n\t -----------------\n");  //indice da coluna
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j == 0)
                printf("\t |");
            printf(" %c ", velha[i][j]);
            if (j < 2)
                printf(" | ");
            if (j == 2)
                printf("|  '%i'", i);   //indice de linha
        }
        if (i < 2)
            printf("\n\t ----------------");          //separadores
            printf("\n");
    }
    printf("\t -----------------");
}

int main() {

    do {
        jogador = 1;
        ganhou = 0;
        jogadas = 0;

        for (i = 0; i < 3; i++) {
          for (j = 0; j < 3; j++)
            velha[i][j] = ' ';
          }

        do{
           system("cls");
           jogo();

            do {
                if (jogador == 1)
                    printf("\n\n  JOGADOR O: Digite a linha e coluna desejada para jogar: ");
                else
                    printf("\n\n  JOGADOR X: Digite a linha e coluna desejada para jogar: ");
                scanf("%i%i", &linha, &coluna);
            } while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 ||    //valida a entrada e repete caso seja inválido
                     velha[linha][coluna] != ' ');

            if (jogador == 1) {
                velha[linha][coluna] = 'O';  //salva coordenada do J1
                jogador++;
            }
            else {
                velha[linha][coluna] = 'X';  //salva coordenada do J2
                jogador = 1;
            }
            jogadas++;

            if(velha[0][0] == 'O' && velha[0][1] == 'O' && velha[0][2] == 'O' ||    //verificação de acerto por linha do j1
               velha[1][0] == 'O' && velha[1][1] == 'O' && velha[1][2] == 'O' ||
               velha[2][0] == 'O' && velha[2][1] == 'O' && velha[2][2] == 'O') {
                 system("cls");
                 printf("\nFIM!! Parabens jogador O, voce venceu por linha!\n");
                 ganhou = 1;
            }

            if(velha[0][0] == 'X' && velha[0][1] == 'X' && velha[0][2] == 'X' ||    //verificação de acerto por linha do j2
               velha[1][0] == 'X' && velha[1][1] == 'X' && velha[1][2] == 'X' ||
               velha[2][0] == 'X' && velha[2][1] == 'X' && velha[2][2] == 'X') {
                 system("cls");
                 printf("\nFIM!! Parabens jogador X, voce venceu por linha!\n");
                 ganhou = 1;
            }

            if(velha[0][0] == 'O' && velha[1][0] == 'O' && velha[2][0] == 'O' ||
               velha[0][1] == 'O' && velha[1][1] == 'O' && velha[2][1] == 'O' ||           //verificação de acerto por coluna do j1
               velha[0][2] == 'O' && velha[1][2] == 'O' && velha[2][2] == 'O') {
                 system("cls");
                 printf("\nFIM!! Parabens jogador O, voce venceu por coluna!\n");
                 ganhou = 1;
            }

            if(velha[0][0] == 'X' && velha[1][0] == 'X' && velha[2][0] == 'X' ||        //verificação de acerto por coluna do j2
               velha[0][1] == 'X' && velha[1][1] == 'X' && velha[2][1] == 'X' ||
               velha[0][2] == 'X' && velha[1][2] == 'X' && velha[2][2] == 'X') {
                 system("cls");
                 printf("\nFIM!! Parabens jogador X, voce venceu por coluna!\n");
                 ganhou = 1;
            }

            if(velha[0][0] == 'O' && velha[1][1] == 'O' && velha[2][2] == 'O') {
                system("cls");
                printf("\nFIM!! Parabens jogador O, voce venceu por diagonal principal!\n");
                ganhou = 1;
            }

            if(velha[0][0] == 'X' && velha[1][1] == 'X' && velha[2][2] == 'X') {
                system("cls");
                printf("\nFIM!! Parabens jogador X, voce venceu por diagonal principal!\n");
                ganhou = 1;
            }

            if(velha[0][2] == 'O' && velha[1][1] == 'O' && velha[2][0] == 'O') {
                system("cls");
                printf("\nFIM!! Parabens jogador O, voce venceu por diagonal secundaria!\n");
                ganhou = 1;
            }

            if(velha[0][2] == 'X' && velha[1][1] == 'X' && velha[2][0] == 'X') {
                system("cls");
                printf("\nFIM!! Parabens jogador O, voce venceu por diagonal secundaria!\n");
                ganhou = 1;
            }
        } while(ganhou == 0 && jogadas < 9); //finaliza o jogo se ocorrer todas jogadas e ninguém ganhar

        jogo();

        if (ganhou == 0){
            printf("\nFIM!! Ninguem ganhou!!");
        }

        printf("\nDigite 1 para jogar novamente: \n");
        scanf("%i", &opcao);

    } while (opcao == 1); //se escolher 1 reinicia o jogo

    return 0;

}
