#include <stdio.h>
#include <math.h>

//This program displays the Pascal's triangle by taking in
//user input for number of rows and using several functions

//function for calculating the factorial of a number
int factorial(int n)
{
    int factorial = 1;
    int i;
    for(i = n; i > 0; i--)
    {
        factorial *= i;
    }
    return factorial;
}

//function to calculate the values of the Pascal Triangle
int choose(int n, int r)
{
    int nCr = factorial(n) / (factorial(r) * factorial(n-r));
    return nCr;
}

//function to actually print the Pascal Triangle
void triangle(int rows)
{
    int row;
    int count = 1;
    
    //loop to go through the rows
    for(row = 0; row < rows; row++)
    {
        int column;
        //loop to fill in the spaces on the left of triangle
        for(column = 0; column < (rows - count) * 3; column++)
        {
            printf(" ");
        }
        count++;
        
        int value;
        //loop to fill in values of triangle (w/ spaces)
        for(value = 0; value < row + 1; value++)
        {
            printf("%-6d", choose(row, value));
        }
        printf("\n");
    }
    
    return;
}

int main(int argc, char **argv)
{
    int rows = 0;
	printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    //loop to continually ask for user input on rows for
    //the triangle, terminating when conditions aren't met
    while(rows > -1 && rows < 14)
    {
        triangle(rows);
        rows = 0;
        printf("Enter the number of rows: ");
        scanf("%d", &rows);
    }
    
	return 0;
}
