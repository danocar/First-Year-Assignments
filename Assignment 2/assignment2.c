
/*

Title:Programming CA2

Program Description:
    The lottery will include various features, each of which will be incorporated in the program through the use of functions. Aside from using the functions required by the assignment brief, this program deploys various other functions in order to error check and improve the user experience.

Student Number: C21431136
Author: Daniel Carson
Date: 20th of March 2022
Due Date: 20th of March 2022

Edited by:
Date:

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//size definitions
#define SIZE 6

//function signatures
void welcomeMessage(void);
void welcomeMenuOptions(void);
void welcomeMenu(void);
void enteringNumbers(int[]);
void displayingNumbers(int[]);
void orderingNumbers(int[]);
int isUnique(int[], int);	
void winningNumbers(int[], int[]);
void displayFreq(int[]);


//global variables
int frequency[42];


//main function
int main()
{
    //main variables
    int holder[SIZE];
    int holder_2[SIZE]; 
    int holder_3[SIZE];
    int holder_4[SIZE] = {1, 3, 5, 7, 9, 11};
    int i;
    int j;
    int a;
    int numbers_ordered[SIZE];
    int menu = 1;
    int flag = 0;

    //welcome message
    welcomeMessage();

    //welcome menu
    welcomeMenu();

    printf("\n\n*******************\n");
    
    //displays the lottery menu
    while (menu != 0)
    {
        printf("\n*******************\n");

        //menu options
        welcomeMenuOptions();

        scanf("%d", &menu);

        //Switch statement to control the menu
        switch(menu)
        {
            case 1:
            {
                //function for the users to enter numbers into an array
                enteringNumbers(holder);
                
                displayFreq(holder);

                //flag variable created for error checking
                flag++;                

                break;
            }
            case 2:
            {
                //switch continues to run if the error checking variable isn't triggered
                if (flag != 0)
                {   
                    //fills in the holder 2 array
                    for(i = 0; i < SIZE; i++)
                    {
                        *(holder_2 + i) = *(holder + i);
                    }

                    //function to display numbers
                    displayingNumbers(holder_2);
                }
                else
                {
                    printf("Please enter your numbers before proceeding!\n");

                }

                break;
            }
            case 3:
            {
                if (flag != 0)
                {
                    //fills in the holder 3 array
                    for (i = 0; i < SIZE; i++)
                    {
                        *(holder_3 + i) = *(holder + i); 
                    }
                    
                    //function that displays numbers in increasing order
                    orderingNumbers(holder_3);
                }
                else
                {
                    printf("Please enter your numbers before proceeding!\n");

                }
                
                break;
            
            }
            case 4:
            {
                if (flag != 0)
                {
                    // fills in numbers ordered array for later comparison 
                    for (i = 0; i < SIZE; i++)
                    {
                        *(numbers_ordered + i) = *(holder + i); 
                    }

                    // Sorting algorithm
                    for (i = 0; i < SIZE; i++)
                    {
                        for (j = i + 1; j < SIZE; ++j)
                        {
                            if (*(numbers_ordered + i) > *(numbers_ordered + j))
                            {
                                a =  *(numbers_ordered + i);
                                *(numbers_ordered + i) = *(numbers_ordered + j);
                                *(numbers_ordered + j) = a;
                            }

                        }
                    }                  

                    winningNumbers(numbers_ordered, holder_4);
                    
                }
            }
        }
    }

    return 0;
}

//function created to provide for the game description
void welcomeMessage(void)
{
    printf("\n*********************\n");
    printf("Welcome to TeleLotto!\n");
    printf("*********************\n\n");

    printf("This lotto gives players a chance to enter 6 numbers between 1 and 46 for a chance of winning a prize.\n\n");

}

//function outlining the user's options
void welcomeMenuOptions(void)
{
    printf("\n*******************\n");

        //menu options
        printf("\nPlease select one of the following options:\n\n");
        printf("Press 1 to enter your numbers\n");
        printf("Press 2 to display the numbers entered\n");
        printf("Press 3 to display the numbers entered in ascending order\n");
        printf("Press 4 to see if you have won\n");

        printf("\nPress 0 to exit\n");
}

//welcome menu function
void welcomeMenu(void)
{
    //function variables
    int decider = 0;
    
    //determines player's eligibility
    printf("If you wish to proceed with the game, please type 1\n");
    printf("If you do not wish to proceed, please type any other number: ");

    scanf("%d", &decider);
   
    while(1)
    {
        if (decider != 1)
        {
            printf("\nGoodbye!\n");
            
            //terminates the game if the user decides not to play
            exit(-1);

        }
        //the game continues if the user enters 1
        else if(decider == 1)
        {
            printf("\nThank you for choosing to play TeleLotto!");

            break;
        }
    }
}

//function created for error checking
int isUnique(int numbers_entered[], int entry) 
{
    for (int i = 0; i < entry; i++) 
    {
        if (*(numbers_entered + i) == *(numbers_entered + entry)) 
        {
            
            return 1;
        }
    }
    return 0;
}

//function allowing the user to enter numbers
void enteringNumbers(int numbers_entered[])
{
    //local variables
    int i;

    printf("\nPlease enter 6 numbers between 1 and 42\n");

    //entering the numbers
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &*(numbers_entered + i));

        //error checking
        while((*(numbers_entered + i) < 1 || *(numbers_entered + i) > 42) || (isUnique(numbers_entered, i) == 1 )) 
        {
            printf("Please enter a valid number\n");
            scanf("%d", &*(numbers_entered + i));
        }

        //used for displaying the frequency of numbers entered
        frequency[numbers_entered[i]-1]++;
    }


    //formatting
    printf("\n\n\n");

}

//function to display the numbers as entered
void displayingNumbers(int numbers_displayed[])
{
    //local variables
    int i;
    
    printf("\nThe numbers you have entered are:\n");

    //prints the numbers as entered
    for (i = 0; i < SIZE; i++)
    {
        printf("%d, ", *(numbers_displayed + i));

    }

    printf("\n\n\n");

}

//function to order the numbers entered
void orderingNumbers(int numbers_ordered[])
{

    //local variables
    int i;
    int j;
    int a;

    // ordering the numbers entered using nested loop
    for (i = 0; i < SIZE; i++) 
    {
        for (j = i + 1; j < SIZE; ++j)
        {

            if (*(numbers_ordered + i) > *(numbers_ordered + j)) 
            {

                a =  *(numbers_ordered + i);
                *(numbers_ordered + i) = *(numbers_ordered + j);
                *(numbers_ordered + j) = a;

            }
        }
    }

    printf("\nIn order, the numbers you have entered are: ");
    
    //printing out the numbers after the ordering
    for (i = 0; i < SIZE; i++)
    {
        printf("%d, ", *(numbers_ordered + i));

    }

    printf("\n\n\n");


}

//function that determines if the user has won
void winningNumbers(int numbers_ordered[], int winning_numbers[])
{
    //local variables
    int i;
    int j;
    int count = 0;

    //calculates if the user has won
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++) 
        {
            if (*(numbers_ordered + j) == *(winning_numbers + i))
            {
                count++;
            }        
        }
    }
    
    //outlines to the user what they have won
    switch(count)
    {
        case 6:
        {
            printf("You have won the jackpot!\n");

            break;
        }
        case 5:
        {
            printf("You won a brand new car!\n");

            break;

        }
        case 4:
        {
            printf("You have won a weekend away!\n");

            break;

        }
        case 3:
        {
            printf("You have won a cinema pass!\n");

            break;

        }
        default:
        {
            printf("You have won nothing\n");
        }
        
    }
}

//function that displays the frequency of numbers entered
void displayFreq(int numbers_entered[])
{
    //local variables
    int i;

    //displays the frequency of numbers entered
    for(i = 0; i < SIZE; i++)
    {
        
        printf("The number %d has been selected %d times\n", *(numbers_entered+i), *(frequency + (*(numbers_entered+i)-1)));
        
    }

}