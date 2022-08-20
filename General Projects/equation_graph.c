#include <stdio.h>
int main() {
    int choice;
    do { // menu
        printf("Select an operation...\n");
        printf("0. -> Enter the coefficients.\n");
        printf("1. -> Draw the graph.\n");
        printf("2. -> Exit.\n\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n\n");
        int a, b, c;
        if (choice == 0) { // taking values for the equation x = ay^2 + by + c
            printf("Please enter the coefficient for the following equation: x = a*(y*y) + b*y + c\n");
            do {
                printf("a: ");
                scanf("%d", &a);
                printf("b: ");
                scanf("%d", &b);
                printf("c: ");
                scanf("%d", &c);
                if (a > 2 || a < 0)
                    printf("enter valid numbers!\n");
            } while (a > 2 || a < 0);
        }

        if (choice == 1) {
            int y, x;
            printf("Printing the graph of x = %d(y*y) + %d*y +%d\n", a, b, c);
            for (y = 16; y >= -15; y--) { // drawing a graph for x=>(-55,55), y=>(-15,15)
                for (x = -56; x <= 56; x++) {
                    if (x == a * y * y + b * y + c && y < 16) {
                        printf("#");
                    } else if (y == 0 && x == -56)
                        printf("<");
                    else if (y == 0 && x == 56)
                        printf(">");
                    else if (x == 0 && y <= 15 && y >= -15)
                        printf("|");
                    else if (y == 0 && x >= -55 && x <= 55)
                        printf("-");
                    else if (x == 0 && y == 16)
                        printf("^");
                    else if (y == -1 && (x + 1) % 10 == 0 && x <= -10 && x >= -51)
                        printf("\b\b%d", x + 1);
                    else if (y == -1 && (x + 1) % 10 == 0 && x >= 9 && x <= 50)
                        printf("\b%d", x + 1);
                    else if (y == -1 && x == -1)
                        printf("%d", 0);
                    else if (x == -1 && y % 5 == 0 && y <= 15 && y >= 10)
                        printf("\b%d", y);
                    else if (x == -1 && y % 5 == 0 && y >= -15 && y <= -10)
                        printf("\b\b%d", y);
                    else if (x == -1 && y == 5)
                        printf("%d", 5);
                    else if (x == -1 && y == -5)
                        printf("%d", 5);
                    else
                        printf(" ");
                }
                printf("\n");
            }
        }
        if (choice == 2)
            break;
    } while (choice != 2);

    return 0;
}
