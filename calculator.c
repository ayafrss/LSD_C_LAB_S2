#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_add(float **a, float **b, int row, int col) {
    
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%f", a[i][j] + b[i][j]);
    }
}

void my_sub(float **a, float **b, int row, int col) {
    
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < col; j++)
           for (int j = 0; j < col; j++)
            printf("%f", a[i][j] - b[i][j]);
    }
}
void my_mult(float **a, float **b, int row, int col) {
    
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < col; k++)
            {
                
            }
        }
    }
}
void my_div(float **a, float **b, int row, int col) {
    
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%f", a[i][j] / b[i][j]);
    }
}

void    *matrix_stor(int row, int col)
{
    int    **Matrix;
    
    printf("Here;\n");
    Matrix = malloc(sizeof(int*) * row);
    for (int i = 0 ; i < row ; i++)
        Matrix[i] = malloc(sizeof(int) * col);
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
            printf("Enter Elem\n");
            scanf("%d", &Matrix[i][j]);
        }
    }
    return Matrix;
}

int main()
{
    char instruction[10];
    void *Matrix[27];
    int cols[27], rows[26], row, col;
    char c, op_chars[] = "+-*/";
    
    void(*operations[4])(float**,float**,int,int);
    
    printf("Welcome to Aya matrix\n");
    
    operations[0] = my_add;
    operations[1] = my_sub;
    operations[2] = my_mult;
    operations[3] = my_div;
    
    while(1) {
        printf("Enter instruction\n");
        scanf("%s", instruction);
        if (!strcmp(instruction, "Set"))
        {
            scanf("%c(%d, %d) =", &c, &row, &col);
            Matrix[c - 'A'] = matrix_stor(row, col);
            rows[c - 'A'] = row;
            cols[c - 'A'] = col;
        }
        else if (!strcmp(instruction,"Calc"))
        {
            char c1, op, c2;
            scanf(" %c %c %c", &c1, &op, &c2);
            int e = strchr(op_chars, op) - op_chars;
            operations[e](Matrix[c1 - 'A'] , Matrix[c2 - 'A'], rows[c2 - 'A'], cols[c2 - 'A']);
            break;
        }
        else if (!strcmp(instruction,"exit"))
            break;
    }
    printf("Calculator exited");
    return 0;
}
