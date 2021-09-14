#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Tabuleiro{
    
    int campo[9][9];
    int campoMostrar[9][9];

};

void Preencher(int campo[9][9], int campoMostrar[9][9]){

    int x = 0;
    int y = 0;
    int bombs = 0;

    local:
    
    srand(time(NULL));

    for(x = 0; x < 9; x++){

        for(y = 0; y < 9; y++){

            campoMostrar[y][x] = 0;

            int valor = rand()%100;

            if(valor%3 == 0 && bombs < 15){

                campo[y][x] = 9;

                bombs++;

            }
            else{

                campo[y][x] = 0;

            }

        }

    }

    if(bombs < 15){

        goto local;
        
    }

}

int Expandir(int campo[9][9], int campoMostrar[9][9]){

    int bomb = 81;

    for(int j = 0; j <= 10; j++){

        int bombas;

        for(int a = 0; a < 9; a++){

            for(int b = 0; b < 9; b++){

                if(campoMostrar[b][a]){

                    bombas = 0;

                    if(b == 0){

                        if(a == 0){

                            if(campo[b+1][a] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a+1] == 9 ){
                                bombas++;
                            }

                            if(campo[b][a+1] == 9){
                                bombas++;
                            }

                            if(bombas == 0){

                                campo[b][a] = 0;
                                
                                campoMostrar[b][a] = 1;

                                campoMostrar[b+1][a] = 1;

                                campoMostrar[b+1][a+1] = 1;

                                campoMostrar[b][a+1] = 1;

                            }
                            else{

                                campo[b][a] = bombas;

                                campoMostrar[b][a] = 1;

                            }

                        }
                        else if(a == 8){

                            if(campo[b+1][a] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a-1] == 9 ){
                                bombas++;
                            }

                            if(campo[b][a-1] == 9){
                                bombas++;
                            }

                            if(bombas == 0){

                                campo[b][a] = 0;
                                
                                campoMostrar[b][a] = 1;

                                campoMostrar[b+1][a] = 1;

                                campoMostrar[b+1][a-1] = 1;

                                campoMostrar[b][a-1] = 1;

                            }
                            else{

                                campo[b][a] = bombas;

                                campoMostrar[b][a] = 1;

                            }
                            
                        }
                        else{

                            if(campo[b][a-1] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a-1] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a+1] == 9){
                                bombas++;
                            }

                            if(campo[b][a+1] == 9){
                                bombas++;
                            }

                            if(bombas == 0){

                                campo[b][a] = 0;
                                
                                campoMostrar[b][a] = 1;

                                campoMostrar[b][a-1] = 1;

                                campoMostrar[b+1][a-1] = 1;

                                campoMostrar[b+1][a] = 1;

                                campoMostrar[b+1][a+1] = 1;

                                campoMostrar[b][a+1] = 1;

                            }
                            else{

                                campo[b][a] = bombas;

                                campoMostrar[b][a] = 1;

                            }

                        }

                    }
                    else if(b == 8){

                        if(a == 0){

                            if(campo[b-1][a] == 9){
                                bombas++;
                            }

                            if(campo[b-1][a+1] == 9 ){
                                bombas++;
                            }

                            if(campo[b][a+1] == 9){
                                bombas++;
                            }

                            if(bombas == 0){

                                campo[b][a] = 0;

                                campoMostrar[b][a] = 1;
                                
                                campoMostrar[b-1][a] = 1;

                                campoMostrar[b-1][a+1] = 1;

                                campoMostrar[b][a+1] = 1;

                            }
                            else{

                                campo[b][a] = bombas;

                                campoMostrar[b][a] = 1;

                            }

                        }
                        else if(a == 8){

                            if(campo[b][a-1] == 9){
                                bombas++;
                            }

                            if(campo[b-1][a-1] == 9 ){
                                bombas++;
                            }

                            if(campo[b-1][a] == 9){
                                bombas++;
                            }

                            if(bombas == 0){

                                campo[b][a] = 0;
                                
                                campoMostrar[b][a] = 1;

                                campoMostrar[b][a-1] = 1;

                                campoMostrar[b-1][a-1] = 1;

                                campoMostrar[b-1][a] = 1;

                            }
                            else{

                                campo[b][a] = bombas;

                                campoMostrar[b][a] = 1;

                            }
                            
                        }
                        else{

                            if(campo[b][a-1] == 9){
                                bombas++;
                            }

                            if(campo[b-1][a-1] == 9){
                                bombas++;
                            }

                            if(campo[b-1][a] == 9){
                                bombas++;
                            }

                            if(campo[b-1][a+1] == 9){
                                bombas++;
                            }

                            if(campo[b][a+1] == 9){
                                bombas++;
                            }

                            if(bombas == 0){

                                campo[b][a] = 0;

                                campoMostrar[b][a] = 1;
                                
                                campoMostrar[b][a-1] = 1;

                                campoMostrar[b-1][a-1] = 1;

                                campoMostrar[b-1][a] = 1;

                                campoMostrar[b-1][a+1] = 1;

                                campoMostrar[b][a+1] = 1;

                            }
                            else{

                                campo[b][a] = bombas;

                                campoMostrar[b][a] = 1;

                            }

                        }

                    }
                    else{

                        if(a == 0){

                            if(campo[b-1][a] == 9){
                                bombas++;
                            }

                            if(campo[b-1][a+1] == 9 ){
                                bombas++;
                            }

                            if(campo[b][a+1] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a+1] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a] == 9){
                                bombas++;
                            }

                            if(bombas == 0){

                                campo[b][a] = 0;

                                campoMostrar[b][a] = 1;
                                
                                campoMostrar[b-1][a] = 1;

                                campoMostrar[b-1][a+1] = 1;

                                campoMostrar[b][a+1] = 1;

                                campoMostrar[b+1][a+1] = 1;

                                campoMostrar[b+1][a] = 1;                            

                            }
                            else{

                                campo[b][a] = bombas;

                                campoMostrar[b][a] = 1;

                            }

                        }
                        else if(a == 8){

                            if(campo[b+1][a] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a-1] == 9 ){
                                bombas++;
                            }

                            if(campo[b][a-1] == 9){
                                bombas++;
                            }

                            if(campo[b-1][a-1] == 9){
                                bombas++;
                            }

                            if(campo[b-1][a] == 9){
                                bombas++;
                            }

                            if(bombas == 0){

                                campo[b][a] = 0;
                                
                                campoMostrar[b][a] = 1;

                                campoMostrar[b+1][a] = 1;

                                campoMostrar[b+1][a-1] = 1;

                                campoMostrar[b][a-1] = 1;

                                campoMostrar[b-1][a-1] = 1;

                                campoMostrar[b-1][a] = 1;

                            }
                            else{

                                campo[b][a] = bombas;

                                campoMostrar[b][a] = 1;

                            }
                            
                        }
                        else{

                            if(campo[b-1][a-1] == 9){
                                bombas++;
                            }

                            if(campo[b-1][a] == 9 ){
                                bombas++;
                            }

                            if(campo[b-1][a+1] == 9){
                                bombas++;
                            }

                            if(campo[b][a+1] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a+1] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a] == 9){
                                bombas++;
                            }

                            if(campo[b+1][a-1] == 9){
                                bombas++;
                            }

                            if(campo[b][a-1] == 9){
                                bombas++;
                            }

                            if(bombas == 0){

                                campo[b][a] = 0;

                                campoMostrar[b][a] = 1;
                                
                                campoMostrar[b-1][a-1] = 1;

                                campoMostrar[b-1][a] = 1;

                                campoMostrar[b-1][a+1] = 1;

                                campoMostrar[b][a+1] = 1;

                                campoMostrar[b+1][a+1] = 1;

                                campoMostrar[b+1][a] = 1;

                                campoMostrar[b+1][a-1] = 1;

                                campoMostrar[b][a-1] = 1;

                            }
                            else{

                                campo[b][a] = bombas;

                                campoMostrar[b][a] = 1;
                            }

                        }

                    }

                }

            }

        }

    }

    for(int j = 0; j < 9; j++){

        for(int k = 0; k < 9; k++){

            if(campoMostrar[k][j]){

                bomb -=1;

            }

        }

    }

    if(bomb == 15){

        system("cls");
        printf("\nParabens!! Voce ganhou o jogo!!\n");
        system("pause");
        return 2;

    }
    else{
        return 1;
    }

}

int Verificar(char posicao[3], int campo[9][9], int campoMostrar[9][9]){

    int coluna;
    int linha;

    switch (tolower(posicao[0])){
    
        case 'a':
            coluna = 0;
        break;

        case 'b':
            coluna = 1;
        break;

        case 'c':
            coluna = 2;
        break;

        case 'd':
            coluna = 3;
        break;

        case 'e':
            coluna = 4;
        break;

        case 'f':
            coluna = 5;
        break;

        case 'g':
            coluna = 6;
        break;

        case 'h':
            coluna = 7;
        break;

        case 'i':
            coluna = 8;
        break;
        
        default:
        break;
    }

    switch (posicao[1]){
    
        case '1':
            linha = 0;
        break;

        case '2':
            linha = 1;
        break;

        case '3':
            linha = 2;
        break;

        case '4':
            linha = 3;
        break;

        case '5':
            linha = 4;
        break;

        case '6':
            linha = 5;
        break;

        case '7':
            linha = 6;
        break;

        case '8':
            linha = 7;
        break;

        case '9':
            linha = 8;
        break;
        
        default:
        break;
    }

    if(campo[coluna][linha] == 9){

        printf("\nVoce pisou em uma bomba!! Voce perdeu!!\n");

        system("pause");

        return 0;

    }
    else{
        
        campoMostrar[coluna][linha] = 1;

        return Expandir(campo, campoMostrar);

    }

}

void Printar(int campo[9][9], int campoMostrar[9][9]){

    system("cls");

    char cabecalho = 'A';

    printf("   | ");

    for(int a = 0; a < 9; a++){
        printf(" %c ", cabecalho+a);
    }

    printf("\n___|\n");

    for(int a = 0; a < 9; a++){

        printf(" %d | ", a+1);

        for(int b = 0; b < 9; b++){

            if(campoMostrar[b][a]){

                if(campo[b][a] == 0){
                    printf("[-]", campo[b][a]);
                }
                else{
                    printf("[%d]", campo[b][a]);
                }

            }      
            else{
                printf("[ ]");
            }      

        }

        printf("\n___|\n   |\n");

    }


}

int main(){

    char posicao[3];
    int vida = 1;
    
    struct Tabuleiro tabuleiro;

    Preencher(tabuleiro.campo, tabuleiro.campoMostrar);

    char cabecalho = 'A';

    printf("   | ");

    for(int a = 0; a < 9; a++){
        printf(" %c ", cabecalho+a);
    }

    printf("\n___|\n");

    for(int a = 0; a < 9; a++){

        printf(" %d | ", a+1);

        for(int b = 0; b < 9; b++){

            // printf("[%d]", tabuleiro.campo[b][a]);

            printf("[ ]");

        }

        printf("\n___|\n   |\n");

    }

    while(vida == 1){

        system("cls");

        Printar(tabuleiro.campo, tabuleiro.campoMostrar);

        printf("\nExistem 15 bombas no total!!");

        printf("\n\nDigite a posicao (Ex. F3, B5, etc): ");
        fflush(stdin);
        fgets(posicao, 3, stdin);

        vida = Verificar(posicao, tabuleiro.campo, tabuleiro.campoMostrar);

    }
    

}