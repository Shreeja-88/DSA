#include <stdio.h>

int main() {
    int partitions[20], isFree[20], partCount;
    int processes[20], allocated[20], procCount;

    printf("Enter the number of partitions: ");
    scanf("%d", &partCount);

    printf("Enter the size of each partition:\n");
    for (int i = 0; i < partCount; i++) {
        scanf("%d", &partitions[i]);
        isFree[i] = 1;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &procCount);

    printf("Enter the size of each process:\n");
    for (int i = 0; i < procCount; i++) {
        scanf("%d", &processes[i]);
        allocated[i] = -1;
    }

    for (int i = 0; i < procCount; i++) {
        for (int j = 0; j < partCount; j++) {
            if (isFree[j] && partitions[j] >= processes[i]) {
                allocated[i] = j;
                isFree[j] = 0;
                break;
            }
        }
    }

    printf("\nProcess\tSize\tAllocated partition\n");
    for (int i = 0; i < procCount; i++) {
        if (allocated[i] == -1) {
            printf("P%d\t%d\tNot Allocated\n", i+1, processes[i]);
        } else {
            printf("P%d\t%d\tPartition %d\n", i+1, processes[i], allocated[i]+1);
        }
    }

    return 0;
}