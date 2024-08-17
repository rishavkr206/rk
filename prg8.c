#include <stdio.h>
#include <stdlib.h>

int count = 0;

int can_place(int c[], int r) {
    for (int i = 0; i < r; i++)
        if (c[i] == c[r] || abs(i - r) == abs(c[i] - c[r]))
            return 0;
    return 1;
}

void display(int c[], int n) {
    printf("\nSolution %d:\n", ++count);
    for (int i = 0; i < n; i++) {
        printf("%4d", c[i] + 1);  // Print the column number (1-based index)
    }
    printf("\n");
    for (int i = 0; i < n; i++, printf("\n"))
        for (int j = 0; j < n; j++)
            printf("%c ", c[i] == j ? 'Q' : '-');
}

void nqueens(int n) {
    int c[10] = {0};  // Initialize all elements to 0
    int r = 0;
    while (r >= 0) {
        if (++c[r] < n && can_place(c, r)) {
            if (r == n - 1) display(c, n);
            else c[++r] = -1;
        } else {
            if (c[r] >= n) r--;
        }
    }
}

int main() {
    int n;
    printf("Enter n (number of queens): ");
    scanf("%d", &n);
    
    if (n == 2 || n == 3) 
        printf("Solution does not exist.\n");
    else {
        nqueens(n);
        printf("\nTotal solutions: %d\n", count);
    }
    return 0;
}
