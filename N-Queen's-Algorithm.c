/*
 N-Queen Algorithm 4 Queens Solution
 Time Complexity : O(n2) where n = no of queens
*/

#include <stdio.h>
#include <stdbool.h>

void display(int queen[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", queen[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int queen[4][4], int r, int c)
{

    int i, j;
    for (j = c; j >= 0; j--)
    {
        if (queen[r][j])
        {
            return false;
        }
    }

    for (i = r; i >= 0; i--)
    {
        if (queen[i][c])
        {
            return false;
        }
    }

    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {

        if (queen[i][j])
        {
            return false;
        }
    }

    for (i = r, j = c; i >= 0 && j <= 3; i--, j++)
    {

        if (queen[i][j])
        {
            return false;
        }
    }

    return true;
}

bool show(int queen[4][4], int r)
{
    if (r >= 4)
        return true;
    int j;
    for (j = 0; j < 4; j++)
    {
        if (isValid(queen, r, j))
        {
            queen[r][j] = 1;

            if (show(queen, r + 1))
                return true;

            queen[r][j] = 0;
        }
    }

    return false;
}

void main()
{
    int queen[4][4] = {0};

    show(queen, 0);

    display(queen);
}
