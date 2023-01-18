#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


void reset_Board();
void print_Board();
int check_for_freespace();
void player_move();
void computer_move();
char Check_winner();
void print_Winner(char);

int main()
{
    char Winner = ' ';
    reset_Board();

    while(Winner == ' ' && check_for_freespace() != 0){
        print_Board();

        player_move();
        computer_move();
        Winner = Check_winner();
        if(Winner != ' ' || check_for_freespace()== 0){
            break;
        }
    }
    print_Board();
    print_Winner(Winner);

    return 0;
}


    void reset_Board(){
        for(int i =0; i < 3; i++){
            for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
          }
        }

    }
    void print_Board(){
        printf(" %c | %c | %c ", board[0][0],board[0][1],board[0][2]);
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ", board[1][0],board[1][1],board[1][2]);
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ", board[2][0],board[2][1],board[2][2]);
        printf("\n");
    }
    int check_for_freespace(){
        int freespaces = 9;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j<3; j++){
                if(board[i][j] != ' ' ){
                    freespaces--;
                }
            }
        }
        return freespaces;

    }

    void player_move(){
        int x,y;

        do{

        printf("Enter row num(1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter column num(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("invaid move\n");
        }
        else{
            board[x][y] = PLAYER;
            break;
        }
    } while(board[x][y] != ' ' );

    }
    void computer_move(){
        // creates a seed based on current time
        srand(time(0));
        int x;
        int y;

        if(check_for_freespace()> 0){
            do{
                x = rand() % 3;
                y = rand() % 3;
            }while(board[x][y] != ' ');

            board[x][y] = COMPUTER;
        }
        else{
            print_Winner(' ');
        }
    }
    char Check_winner(){
        // we'll check for rows
        for(int i =0; i < 3; i++){
            if(board[i][0] == board[i][1] && board[i][1]== board[i][2]){
                return board[i][0];
            }

        // for columns

            if(board[0][i] == board[1][i]&& board[1][i] == board[2][i]){
            return board[0][i];
            }

        // diagonal 1

            if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
                return board[0][0];
            }

        // diagonal 2

            if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
                return board[0][2];
            }
        }

    }
    void print_Winner(char Winner){
        if(Winner == PLAYER){
            printf("You Won\n");
        }
        else if(Winner == COMPUTER){
            printf("You lost\n");
        }
        else{
            printf("It's a tie\n");
        }
    }

