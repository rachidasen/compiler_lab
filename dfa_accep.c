#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // getting input from the input file

    FILE *fp = fopen("dfa_accep.txt","r+");
    char ch;
    int read_value;
    char input_string[10];
    int final_states[10];

    char input_file[10][10];

    int i = 0,j = 0, k =0;

    int row_count,column_count;
    int count = 0;
    int final_count = 0;

    int starting_state;



    while ( (read_value  = fgetc(fp)) != -1 )
    {
        // printf("I am in while\n");
        
        ch = (char)read_value ;

        if ( count == 0 )
        {
            if ( ch !='\n')
            starting_state = read_value - 48;
            // count++;
            // continue;    
        }
        // else if ( count == 1)
        // {
        //  printf("read_value is: %d\n", read_value);

        // }
        if ( ch == ' ')
        {
            j++;
        }
        else if( ch == '\n')
        {
            count++;
            j = 0;
            if ( count > 2 )
                i++;
        }
        else
        {
            if ( count == 1 )
                final_states[final_count++] = read_value - 48;
            if ( count > 1 )
                input_file[i][j] = ch;
        }
        
    }

    for ( row_count = 0 ; row_count <= i ; row_count++ )
    {
        for ( column_count = 0 ; column_count <= j ; column_count++ )
        {
            printf("%c ",input_file[row_count][column_count] );
        }
        printf("\n");
    }
    printf("Starting state is: %d\n",starting_state );
    printf("Final states are: \n");
    for (int i = 0; i < final_count; ++i)
    {
        printf("%d ", final_states[i]);
    }


    

    printf("Enter the input:\n");

    fgets(input_string,10,stdin);

    int next_state;
    
    for ( k = 0 ; k < strlen(input_string) - 1 ; k++ )
    {
        int index = (int)input_string[k] - 48;

        if ( ch = input_file[starting_state][ index ] )
        {
            if ( ! (ch >= 48 && ch < 57) )
            {
                next_state = 99;
                break;
            }
        }

        next_state = (int)input_file[starting_state][ index ] - 48;


        

        starting_state = next_state;
        
    }

    int flag = 0;

    for (int i = 0; i < final_count; ++i)
    {
        if ( final_states[i] == next_state )
        {

            flag = 1;
        }   
    } 

    if ( flag )
    {
        printf("Input is accepted by the machine.\n");
    }
    else
    {
        printf("Input is not accepted by the machine.\n");
    }
    
    fclose(fp);
    return 0;
}