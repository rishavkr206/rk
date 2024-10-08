
#include <stdio.h>

#define MAX 10

int s[MAX], x[MAX];  // s[] for input set, x[] for tracking included elements
int d;  // Target sum

void sumofsub(int p, int k, int r) {
    int i;
    x[k] = 1;
    if ((p + s[k]) == d) {
        for (i = 1; i <= k; i++)  // Print subset if sum matches target
            if (x[i] == 1)
                printf("%d ", s[i]);
        printf("\n");
    } else if (p + s[k] + s[k+1] <= d) {
        sumofsub(p + s[k], k + 1, r - s[k]);
    }
    if ((p + r - s[k] >= d) && (p + s[k+1] <= d)) {
        x[k] = 0;
        sumofsub(p, k + 1, r - s[k]);
    }
}

int main() {  // Use int main() as per C standard
    int i, n, sum = 0;
    printf("Enter max. number: ");
    scanf("%d", &n);

    printf("\nEnter the set in increasing order:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }

    printf("\nEnter the max. subset value: ");
    scanf("%d", &d);

    for (i = 1; i <= n; i++) {
        sum += s[i];
    }

    if (sum < d || s[1] > d) {
        printf("\nNo subset possible\n");
    } else {
        sumofsub(0, 1, sum);
    }

    return 0;  // Return 0 to indicate successful execution
}
