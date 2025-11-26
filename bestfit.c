#include <stdio.h>

int main() {
    int part[20], proc[20], alloc[20], fre[20];
    int p, q;

    printf("Enter the number of partitions: ");
    scanf("%d", &p);

    printf("Enter the partition sizes:\n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &part[i]);
        fre[i] = 1;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &q);

    printf("Enter process sizes:\n");
    for (int i = 0; i < q; i++) {
        scanf("%d", &proc[i]);
        alloc[i] = -1;
    }

    for (int i = 0; i < q; i++) {
        int best = -1;

        for (int j = 0; j < p; j++) {
            if (fre[j] && part[j] >= proc[i]) {
                if (best == -1 || part[j] < part[best])
                    best = j;
            }
        }

        if (best != -1) {
            alloc[i] = best;
            fre[best] = 0;
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