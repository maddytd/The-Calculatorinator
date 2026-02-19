#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned int)time(NULL));

    printf("=====================================\n");
    printf("  WELCOME TO THE VERY SERIOUS C APP  \n");
    printf("=====================================\n\n");

    int a, b;

    printf("Enter two numbers for EXTREME COMPUTATION: ");
    scanf("%d %d", &a, &b);

    printf("\nAnalyzing inputs...\n");

    for (int i = 0; i < 3; i++) {
        printf("Thinking");
        for (int j = 0; j < 3; j++) {
            printf(".");
        }
        printf("\n");
    }

    int randomDrama = rand() % 5;

    switch (randomDrama) {
        case 0:
            printf("\nResult: %d + %d = %d\n", a, b, a + b);
            break;

        case 1:
            printf("\nResult: %d - %d = %d\n", a, b, a - b);
            break;

        case 2:
            printf("\nResult: %d * %d = %d\n", a, b, a * b);
            break;

        case 3:
            if (b != 0)
                printf("\nResult: %d / %d = %d\n", a, b, a / b);
            else
                printf("\nERROR: Division by zero detected. Universe collapsing.\n");
            break;

        case 4:
            printf("\nResult: I have decided math is meaningless.\n");
            printf("Have a nice day.\n");
            break;
    }

    printf("\nThank you for using this highly questionable software.\n");

    return 0;
}
