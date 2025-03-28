#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a = rock, b = paper, c = scissors

int game(char player, char computer) 
{
    if (player == computer) 
    {
        return 0;
    }

    if (player == 'a' && computer == 'b')
    {
        return -1;
    }

    if (player == 'b' && computer == 'a')
    {
        return 1;
    }

    if (player == 'a' && computer == 'c')
    {
        return 1;
    }

    if (player == 'c' && computer == 'a')
    {
        return -1;
    }

    if (player == 'b' && computer == 'c')
    {
        return -1;
    }

    if (player == 'c' && computer ==  'b')
    {
        return 1;
    }

    return 0;
}

int main()
{
    int random_number;
    char computer, player;

    /* 
        srand: seed the number generator using time(NULL), which returns the current time in seconds.
        This ensures a different number is generated each time program runs.
    */
    /* 
        rand: generates a number in the range 0-RAND_MAX.
        Using the modulus operator limits the number to the 0-99 range.
    */
    srand(time(NULL));
    random_number = rand() % 100;

    /*
        Determine the computers selection using random_number.
        0-32 = rock
        33-65 = paper
        66-99 = scissors
    */
    if (random_number < 33)
    {
        computer = 'a';
    } else if (random_number > 33  && random_number < 66) {
        computer = 'b';
    } else {
        computer = 'c';
    }

    /*
        Get the player selection using scanf and storing this in the player variable.
        %c is the format specifier for a char.
    */ 
    printf("Enter a for rock, b for paper, and c for scissors\n");
    scanf("%c", &player);

    /*
        Call the game function and passes the player and computer selection, and stores the return value in result variable.
        Returns -1 (computer win), 0 (draw), or 1 (player win).
    */
    int result = game(player, computer);

    // Display the result to the user based on the return value of the game function.
    if (result == -1)
    {
        printf("You lost the game");
    } else if (result == 0) {
        printf("Game draw");
    } else {
        printf("You won the game");
    }

    // Display both player and computer choice to the user at the end of the game.
    printf("You chose %c and the computer chose %c", player, computer);
    
    return 0;
}