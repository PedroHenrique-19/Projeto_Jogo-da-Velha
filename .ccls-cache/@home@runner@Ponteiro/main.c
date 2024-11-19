#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


void printBoard(){
  printf(" %c | %c | %c  \n", board[0][0], board[0][1], board[0][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c  \n", board[1][0], board[1][1], board[1][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c  \n", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}


void resetBoard(){
  for(int i = 0; i < 3; i ++){
    for(int j = 0; j < 3; j++){
      board[i][j] = ' ';
    }
  }
}


int verificarEspacos(char board[3][3]){
  int espacos = 9;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j ++){
      if(board[i][j] != ' '){
        espacos --;
        if(espacos == 0){
          return 0;
        }
      }
    }
  }
  return espacos;
}


void jogadaPlayer(char board[3][3]){
  int linha, coluna;

  while(1){
  printf("Digite a linha para jogar: ");
  scanf("%d", &linha);

  printf("Digite a coluna para jogar: ");
  scanf("%d", &coluna);
  
  if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {
    // Verificar se a célula está vazia
    if (board[linha][coluna] == ' ') {
        board[linha][coluna] = PLAYER;  // 'PLAYER' deve estar definido com o símbolo do jogador
        break;
    } else {
        printf("Movimento inválido! A célula já está ocupada.\n");
      }
    }else{
    printf("Número inválido\n");
    }
  }
}

void jogadaComputador(char board[3][3]){
  int linha, coluna;

  srand(time(0));

  if(verificarEspacos(board)){
  do{
    linha = rand() % 3;
    coluna = rand() % 3;

    
  }while(board[linha][coluna] != ' ');

   board[linha][coluna] = COMPUTER;
  }
}

int verificarVencedor(char board[3][3]){
  for (int i = 0; i < 3; i++){
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
      return board[i][0];
    }
  }
  
  for(int i = 0; i < 3; i++){
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
        return board[0][i];
      }
    }  
  
  if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
  }
  if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
    return board[0][2];
  }
  return ' ';
}


void declararVencedor(char vencedor){
  if (vencedor == PLAYER){
    printf("Você venceu.");
  }else if(vencedor == COMPUTER){
    printf("Você perdeu");
  }else{
    printf("Empate");
  }
}


int main() {
  char vencedor = ' ';
  
  resetBoard();

  while(vencedor == ' ' && verificarEspacos(board) != 0) {
  printBoard();

    
  jogadaPlayer(board);
  vencedor = verificarVencedor(board); 
  if(vencedor != ' ' || verificarEspacos(board) == 0){
    break;
    }
  

  jogadaComputador(board);
  vencedor = verificarVencedor(board); 
  if(vencedor != ' ' || verificarEspacos(board) == 0){
    break;
    }
  }
  

  printBoard();
  declararVencedor(vencedor);

 
  return 0;
}