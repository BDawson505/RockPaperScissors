#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a = rock, b = paper, c = scissors

int game(char player, char computer) 
{
    /*
        Map the choices of the player and the computer to an integer.
        Converting the char player or computer to an integer gives the ASCII value of the char.
        Subtracting the ASCII value of 'a' (97) gives a value of 0 for a, 1 for b, and 2 for c.
    */
    int p = player - 'a';
    int c = computer - 'a';

    /*
        Calculate the result of the game based on the player and computer choice (after converted to integers).
        p - c: calculates the difference between the selections.
        + 3: converts the result of the above calculation to a positive value
        % 3: ensures the outcome is mapped to 0, 1, or 2
          - 0: Draw 
          - 1: Player Win
          - 2: Computer Win
    */
    int calculated_result = (p - c + 3) % 3;
    return calculated_result;
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
    scanf(" %c", &player);

    /*
        Call the game function and passes the player and computer selection, and stores the return value in result variable.
        Returns 0 (computer win), 1 (draw), or 2 (player win).
    */
    int result = game(player, computer);

    // Display the result to the user based on the return value of the game function.
    if (result == 0)
    {
        printf("Game Draw");
    } else if (result == 1) {
        printf("You won the game");
    } else {
        printf("You lost");
    }

    // Display both player and computer choice to the user at the end of the game.
    printf("You chose %c and the computer chose %c", player, computer);
    
    return 0;
}