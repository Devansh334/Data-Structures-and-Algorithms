/*
 N-Queen Algorithm n Queens Solution
 Time Complexity : O(n2) where n = no of queens
*/

#include <stdio.h>
#include <stdbool.h>
int ans = 0;
int n;
void display(int queen[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", queen[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int queen[n][n], int r, int c)
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

    for (i = r, j = c; i >= 0 && j <= n - 1; i--, j++)
    {

        if (queen[i][j])
        {
            return false;
        }
    }

    return true;
}
int count = 0;
bool show(int queen[n][n], int r)
{
    if (r >= n)
    {
        display(queen);
        printf("\n");
        ans++;
        return false;
    }

    if (queen[0][n - 1] == 1 && count == n)
    {
        return true;
    }

    int j;
    for (j = 0; j < n; j++)
    {

        if (isValid(queen, r, j))
        {
            queen[r][j] = 1;
            count++;

            if (show(queen, r + 1))
                return true;

            queen[r][j] = 0;
            count--;
        }
    }

    return false;
}

void main()
{

    printf("Enter value of n for N QUeens  ");
    scanf("%d", &n);
    int queen[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            queen[i][j] = 0;
        }
    }

    show(queen, 0);

    printf("%d", ans);
    printf(" Solutions Exists");
}
