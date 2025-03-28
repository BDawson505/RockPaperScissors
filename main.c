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

// Convert the char choice of the player or computer to the string choice for final display
const char* choice_to_string(char choice)
{
    if (choice == 'a') return "rock";
    if (choice == 'b') return "paper";
    if (choice == 'c') return "scissors";
    return "Invalid"; // fallback
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
        Only allow the user to enter available options.
    */ 
    printf("Options:\n\ta = Rock\n\tb = Paper\n\tc = Scissors\n\n");
    printf("Please enter your selection:\n");

    while (1) {
        scanf(" %c", &player); 
        
        // Check if the input is valid
        if (player == 'a' || player == 'b' || player == 'c') {
            break; 
        } else {
            printf("Invalid input! Please enter 'a' for Rock, 'b' for Paper, or 'c' for Scissors:\n");
        }
    }


    /*
        Call the game function and passes the player and computer selection, and stores the return value in result variable.
        Returns 0 (computer win), 1 (draw), or 2 (player win).
    */
    int result = game(player, computer);

    // Display the result to the user based on the return value of the game function.
    if (result == 0)
    {
        printf("\nDraw!");
    } else if (result == 1) {
        printf("\nWin!");
    } else {
        printf("\nLost!");
    }

    // Display both player and computer choice to the user at the end of the game.
    printf("\nYou chose %s and the computer chose %s", choice_to_string(player), choice_to_string(computer));
    
    return 0;
}