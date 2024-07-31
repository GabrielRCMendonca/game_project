#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int generate_random_number() {
    return (rand() % 20) + 1;
}

void game_menu() {
    int tries = 0;
    int player_guess;
    char player_choice;
    int random_number = generate_random_number();
    
    while(tries < 10) {
        printf("What number is loiro thinking of?\n");
        scanf("%d", &player_guess);
        
        if(player_guess == random_number) {
            printf("You won! Loiro is crying and running away\n");
            break;
        } else if(abs(player_guess - random_number) <= 5) {
            printf("Wrong...But Close!\n");
        } else {
            printf("You're very wrong!\n");
        }
        
        tries++;
    }
    
    if(tries == 10) {
        printf("Loiro won :(\n");
    }
    
    printf("Do You want to play again? (y/n):\n");
    scanf(" %c", &player_choice);
    player_choice = tolower(player_choice);
        
    if (player_choice == 'y') {
        game_menu();
    } else {
        printf("Loiro won and killed everyone\n");
    }
}

int main() {
    srand(time(NULL));
    printf("Loiro likes numbers from 1 to 20!\n");
    game_menu();

    return 0;
}