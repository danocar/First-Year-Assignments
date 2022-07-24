/*
Assignment 2 - Programming
Michael Collins
March 2022
*/

#include <stdio.h>

#define SIZE 6
#define NUMS 42

// Function signatures
void enter_nums(int [], int[]);
void display_nums(int []);
void sort_nums(int []);
void compare_nums(int []);
void frequency(int []);
char end(void);

// Winning numbers - Constant global array
const int winning_nums[SIZE] = {1, 3, 5, 7, 9, 11};

int main()
{
    int selected_nums[SIZE];
    int freq_nums[NUMS] = {0};
    int option = 0;
    char confirm = ' ';

    do
    {
        printf("\n\n------------------------");
        printf("\nSelect option:\n");
        printf("\n1. Enter 6 numbers (1 - 42)");
        printf("\n2. Display numbers entered");
        printf("\n3. Sort numbers entered (increasing order)");
        printf("\n4. Compare with winning numbers");
        printf("\n5. Frequency of selected numbers");
        printf("\n6. End program\n");

        scanf("%d", & option);

        // clear input buffer
        while(getchar() != '\n');

        // Implement the respective function based on the user's choice
        switch (option)
        {
            case 1:
            {
                // Enter selected numbers
                // freq_nums keeps track of the frequency of the numbers entered
                // while the program is running
                enter_nums(selected_nums, freq_nums);
                break;
            }
            case 2:
            {
                // Display the user's selected numbers
                display_nums(selected_nums);
                break;
            }
            case 3:
            {
                // Sort the array containg the user's numbers in
                // increasing order
                sort_nums(selected_nums);
                break;
            }
            case 4:
            {
                // Compare the user numbers with the winning numbers
                compare_nums(selected_nums);
                break;
            }
            case 5:
            {
                // Show the frequency of the user numbers entered
                frequency(freq_nums);
                break;
            }
            case 6:
            {
                char confirm = end();

                if(confirm == 'y')
                {
                    // end program
                    printf("\nBye ..");
                    return 0;
                }
                break;
            }
            default:
            {
                printf("\nInvalid entry - dope !!");        
            }
        } // end switch
        
    } // end do
    while(confirm != 'y');
    
    return 0;
    
} // end main()


// Option 1 - Enter the user's selected numbers
void enter_nums(int my_nums[], int freq_nums[])
{
    int i;
    int temp;

    printf("\nEnter any 6 numbers (1 - 42)\n");

    for(i = 0; i < SIZE; i++)
    {
        // enter the user's selected 6 numbers
        scanf("%d", & *(my_nums + i));

        // assign temp the current selected number entered
        temp = *(my_nums + i);

        // Increment the corresponding index of freq_nums[] with the
        // numbers entered by the user contained in my_nums[]
        //freq_nums[temp - 1]++;
        *(freq_nums + (temp - 1) ) = *(freq_nums + (temp - 1) ) + 1;
        
    } // end for 
    
} // end enter_nums()


// Option 2 - Display the user's selected numbers
void display_nums(int my_nums[])
{
    int i;

    printf("\nYour selected numbers are:\n");

    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", *(my_nums + i));
    } // end for
    
} // end enter_nums()


// Option 3 - Sort the user's selected numbers into increasing order
void sort_nums(int my_nums[])
{
    // Bubble sort
    // Sort the array into increasing order
    //
    for (int step = 0; step < SIZE - 1; step++)
    {
        // loop to compare array elements
        for (int i = 0; i < SIZE - step - 1; i++)
        {
            // compare two adjacent elements
            // change > to < to sort in descending order
            if ( *(my_nums + i) > *(my_nums + (i + 1)) )
            {
                // swap numbers if elements are not in order
                int temp = *(my_nums + i);
                *(my_nums + i) = *(my_nums + (i + 1));
                *(my_nums + (i + 1)) = temp;
            } // end if
        } // end for
    } // end for

    printf("\nSelected numbers sorted\n");
    
} // end sort_nums()


// Option 4 - Compare the user's selected numbers with the winning numbers
void compare_nums(int my_nums[])
{
    int i,j;
    int counter = 0;

    for (i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            // Compare each user's number with each winning number
            if( *(my_nums + i) == *(winning_nums + j) )
            {
              counter++;
                
            } // end if
        } // end inner for
    } // end outer for

    printf("\nYou matched %d numbers", counter);

    // Show corresponding prize if user's numbers match 3, 4, 5 or 6
    switch(counter)
    {
        case 3:
        {
            printf("\nYou won a Cinema pass");
            break;
        }
        case 4:
        {
            printf("\nYou won a Weekend away");
            break;
        }
        case 5:
        {
            printf("\nYou won a new car");
            break;
        }
        case 6:
        {
            printf("\nJackpot");
            break;
        }

    } // end switch
    
} // end compare_nums()


// Option 5 - Show the frequency of the numbers entered
void frequency(int freq_nums[])
{
    int i;
    int temp = 0;

    // show the frequency of the numbers entered
    for (i = 0; i < NUMS; i++)
    {
        // need to use the temp variable instead of i in order not to
        // change the value of i in the loop to access the correct
        // array index for freq_nums[]
        temp = i;
        temp++;

        // Only display the numbers entered and NOT those not entered
        if (*(freq_nums + i) != 0)
        {
            printf("\nNo %d selected %d time(s)", temp, *(freq_nums + i));
        } // end if 
        
    } // end for 
    
} // end frequency()


// Option 6 - End program
char end(void)
{
    char choice = ' ';
    
    printf("\nConfirm end? y/n\n");
    scanf("%c", &choice);

    // Clear input buffer
    while(getchar() != '\n');

    if(choice == 'y')
    {
        return 'y';
    }
    else
    {
        return 'n';
    }
} // end end()