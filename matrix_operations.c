#include <stdio.h>

#define MAX 10

// Function Declarations
void input(int matrix[MAX][MAX], int rows, int cols);
void display(int matrix[MAX][MAX], int rows, int cols);
void add(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiply(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2);
void transpose(int matrix[MAX][MAX], int trans[MAX][MAX], int rows, int cols);

int main()
{
    int choice;

    int matrix1[MAX][MAX];
    int matrix2[MAX][MAX];
    int result[MAX][MAX];
    int trans[MAX][MAX];

    int rows1, cols1;
    int rows2, cols2;

    while (1)
    {
        printf("\n=====================================\n");
        printf("          MATRIX OPERATIONS\n");
        printf("=====================================\n");

        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("\nEnter rows and columns of Matrix 1: ");
                scanf("%d%d", &rows1, &cols1);

                printf("Enter rows and columns of Matrix 2: ");
                scanf("%d%d", &rows2, &cols2);

                if (rows1 != rows2 || cols1 != cols2)
                {
                    printf("\nMatrix Addition is not possible!\n");
                    break;
                }

                printf("\nEnter elements of Matrix 1:\n");
                input(matrix1, rows1, cols1);

                printf("\nEnter elements of Matrix 2:\n");
                input(matrix2, rows2, cols2);

                add(matrix1, matrix2, result, rows1, cols1);

                printf("\nResult Matrix:\n");
                display(result, rows1, cols1);

                break;

            case 2:

                printf("\nEnter rows and columns of Matrix 1: ");
                scanf("%d%d", &rows1, &cols1);

                printf("Enter rows and columns of Matrix 2: ");
                scanf("%d%d", &rows2, &cols2);

                if (cols1 != rows2)
                {
                    printf("\nMatrix Multiplication is not possible!\n");
                    break;
                }

                printf("\nEnter elements of Matrix 1:\n");
                input(matrix1, rows1, cols1);

                printf("\nEnter elements of Matrix 2:\n");
                input(matrix2, rows2, cols2);

                multiply(matrix1, matrix2, result, rows1, cols1, cols2);

                printf("\nResult Matrix:\n");
                display(result, rows1, cols2);

                break;

            case 3:

                printf("\nEnter rows and columns of Matrix: ");
                scanf("%d%d", &rows1, &cols1);

                printf("\nEnter matrix elements:\n");
                input(matrix1, rows1, cols1);

                transpose(matrix1, trans, rows1, cols1);

                printf("\nTranspose Matrix:\n");
                display(trans, cols1, rows1);

                break;

            case 4:

                printf("\nThank you for using Matrix Operations Program.\n");
                return 0;

            default:

                printf("\nInvalid Choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to input matrix
void input(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void display(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%5d", matrix[i][j]);
        }

        printf("\n");
    }
}

// Function for matrix addition
void add(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function for matrix multiplication
void multiply(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2)
{
    int i, j, k;

    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols2; j++)
        {
            result[i][j] = 0;

            for (k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function for transpose
void transpose(int matrix[MAX][MAX], int trans[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            trans[j][i] = matrix[i][j];
        }
    }
}