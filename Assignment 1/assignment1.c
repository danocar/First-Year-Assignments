/*
Title:Programming CA1

Program Description:
    The game will include various features, each of which will be incorporated in the program.

    

    The menu will include the folling options:

    1. Enter the number of questions to be asked for this round of the quiz
    2. Start and play quiz
    3. Display the number of questions that were answered (i) correctly and (ii)
    incorrectly for this round.
    4. Exit Program
    

Student Number: C21431136
Author: Daniel Carson
Date: 27th November 2021
Due Date: 28th of November 2021

Edited by:
Date:
*/

#include <stdio.h>



int main()
{

    int menu_choice, num_q; 
    int correct = 0;
    int incorrect = 0;
    int n = 0;

    while (1)
    { // Start while

        // Welcome Message
        printf("*******************************\n");
        printf("Welcome to Daniel's Maths Quiz!\n");
        printf("*******************************\n");

        printf("1. Enter number of questions to be asked\n2. Start and play quiz\n3. Display number of answers answered correctly/incorrectly\n4. Exit Program\n\n");
      
        scanf("%d", &menu_choice);

        // Exit Program
        if (menu_choice == 4)
        {
            break;
        }

        // Enter number of questions to be asked
        else if (menu_choice == 1)
        {
            printf("Enter number of Questions\n");
            scanf("%d", &num_q);

        }
        // Prints questions answered correctly, incorrectly, and total number of questions answered.
        else if (menu_choice == 3)
        {

            printf("Questions answered correctly: %d\n", correct);
            printf("Questions answered incorrectly: %d\n", incorrect);
            printf("Total questions answered: %d\n", correct + incorrect);

        }
        // Purpose of option 2 is to ask the questions
        else if (menu_choice == 2)
        {

            if (num_q > 0) // Checks to see if there is 1 or greater questions to be asked
            {
                printf("Q1. 2 + 2 = ?\n");
                printf("Enter answer: \n");
                scanf("%d", &n);

                if (n == 4)
                {
                    correct++;
                    printf("Correct!\n");
                }

                else if(n != 4)
                {
                    incorrect++;
                    printf("Incorrect!\n");
                }
            }

            if (num_q > 1) // Checks to see if there is 2 or greater questions to be asked
            {
                printf("Q2. 2 * 2 = ?\nEnter answer: \n");
                scanf("%d", &n);

                if (n == 4)
                {
                    correct++;
                    printf("Correct!\n");
                }

                else if(n != 4){
                    incorrect++;
                    printf("Incorrect!\n");
                }
            }
            
            if (num_q > 2) // Checks to see if there is 3 or greater questions to be asked
            { 
                printf("Q3. 16/4 = ?\nEnter answer: \n");
                scanf("%d", &n);
                

                if (n == 4)
                {
                    correct++;
                    printf("Correct!\n");
                }

                else if(n != 4)
                {
                    incorrect++;
                    printf("Incorrect!\n");
                }
            } 

            if (num_q > 3) // Checks to see if there is 4 or greater questions to be asked
            {
                printf("Q4. 8/2 = ?\n Enter answer: ");
                scanf("%d", &n);

                if (n == 4)
                {
                    correct++;
                    printf("Correct!\n");
                }

                else if(n != 4) // Checks to see if the answer is incorrect
                {
                    incorrect++;
                    printf("Incorrect!\n");
                }
            }
        }

    } // End while

    return 0; 
} // End int main
    


