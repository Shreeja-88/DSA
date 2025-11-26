#include <stdio.h>

int main() {
    int part[20], proc[20], alloc[20], free[20];
    int p, q;

    printf("Enter the number of partitions: ");
    scanf("%d", &p);

    printf("Enter the partition sizes:\n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &part[i]);
        free[i] = 1;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &q);

    printf("Enter the process sizes:\n");
    for (int i = 0; i < q; i++) {
        scanf("%d", &proc[i]);
        alloc[i] = -1;
    }

    for (int i = 0; i < q; i++) {
        int worst = -1;

        for (int j = 0; j < p; j++) {
            if (free[j] && part[j] >= proc[i]) {
                if (worst == -1 || part[j] > part[worst]) {
                    worst = j;
                }
            }
        }

        if (worst != -1) {
            alloc[i] = worst;
            free[worst] = 0;
        }
    }

    printf("\nProcess\tSize\tAllocated Partition\n");
    for (int i = 0; i < q; i++) {
        if (alloc[i] == -1) {
            printf("P%d\t%d\tNot Allocated\n", i+1, proc[i]);
        } else {
            printf("P%d\t%d\tPartition %d\n", i+1, proc[i], alloc[i] + 1);
        }
    }

    return 0;
}