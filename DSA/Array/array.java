import java.util.Scanner;
public class array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("The elements in the array are:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}
// Sample Input/Output:
// Enter the size of the array: 5
// Enter 5 elements: 10 20 30 40 50
// The elements in the array are: 10 20 30 40 50

//basic operations on array
//1. Traversing
/*import java.util.Scanner;
public class array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("The elements in the array are:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}
    */
// Sample Input/Output:
// Enter the size of the array: 5
// Enter 5 elements: 10 20 30 40 50
// The elements in the array are: 10 20 30 40 50


//2. Insertion
/*
*import java.util.Scanner;
public class ArrayInsertion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n + 1];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.print("Enter position to insert (0 to " + n + "): ");
        int pos = sc.nextInt();
        System.out.print("Enter element to insert: ");
        int x = sc.nextInt();

        for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
        arr[pos] = x;

        System.out.println("Array after insertion:");
        for (int i = 0; i <= n; i++) System.out.print(arr[i] + " ");
        sc.close();
    }
}
 Sample Input/Output:
 Enter size of array: 5
 Enter 5 elements: 10 20 30 40 50
 Enter position to insert (0 to 5): 2
 Enter element to insert: 25
 Array after insertion: 10 20 25 30 40 50
 */

//3. Deletion
/*
 * import java.util.Scanner;
public class ArrayDeletion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.print("Enter position to delete (0 to " + (n - 1) + "): ");
        int pos = sc.nextInt();

        for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
        n--;

        System.out.println("Array after deletion:");
        for (int i = 0; i < n; i++) System.out.print(arr[i] + " ");
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 5
    Enter 5 elements: 10 20 30 40 50
    Enter position to delete (0 to 4): 2
    Array after deletion: 10 20 40 50


//4. Searching
import java.util.Scanner;
public class ArraySearching {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.print("Enter element to search: ");
        int key = sc.nextInt();

        boolean found = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                System.out.println("Element found at index " + i);
                found = true;
                break;
            }
        }
        if (!found) System.out.println("Element not found!");
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 5
    Enter 5 elements: 10 20 30 40 50
    Enter element to search: 30
    Element found at index 2


//5. Sorting
import java.util.Scanner;
import java.util.Arrays;

public class ArraySorting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        Arrays.sort(arr);

        System.out.println("Array after sorting:");
        for (int num : arr) System.out.print(num + " ");
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 5
    Enter 5 elements: 30 10 50 20 40
    Array after sorting: 10 20 30 40 50


//6. Merging
import java.util.Scanner;
public class ArrayMerging {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of first array: ");
        int n1 = sc.nextInt();
        int[] a = new int[n1];
        System.out.println("Enter " + n1 + " elements:");
        for (int i = 0; i < n1; i++) a[i] = sc.nextInt();

        System.out.print("Enter size of second array: ");
        int n2 = sc.nextInt();
        int[] b = new int[n2];
        System.out.println("Enter " + n2 + " elements:");
        for (int i = 0; i < n2; i++) b[i] = sc.nextInt();

        int[] merged = new int[n1 + n2];
        for (int i = 0; i < n1; i++) merged[i] = a[i];
        for (int i = 0; i < n2; i++) merged[n1 + i] = b[i];

        System.out.println("Merged array:");
        for (int num : merged) System.out.print(num + " ");
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of first array: 3
    Enter 3 elements: 10 20 30
    Enter size of second array: 2
    Enter 2 elements: 40 50
    Merged array: 10 20 30 40 50


//7. Splitting
import java.util.Scanner;
public class ArraySplitting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.print("Enter position to split: ");
        int pos = sc.nextInt();

        System.out.println("First half:");
        for (int i = 0; i < pos; i++) System.out.print(arr[i] + " ");

        System.out.println("\nSecond half:");
        for (int i = pos; i < n; i++) System.out.print(arr[i] + " ");
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 6
    Enter 6 elements: 10 20 30 40 50 60
    Enter position to split: 3
    First half: 10 20 30 
    Second half: 40 50 60


//8. Reversing
import java.util.Scanner;
public class ArrayReversing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.println("Array in reverse order:");
        for (int i = n - 1; i >= 0; i--) System.out.print(arr[i] + " ");
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 5
    Enter 5 elements: 10 20 30 40 50
    Array in reverse order: 50 40 30 20 10


//9. Finding max and min
import java.util.Scanner;
public class ArrayMaxMin {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        int max = arr[0], min = arr[0];
        for (int num : arr) {
            if (num > max) max = num;
            if (num < min) min = num;
        }
        System.out.println("Maximum: " + max);
        System.out.println("Minimum: " + min);
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 5
    Enter 5 elements: 10 20 5 30 15
    Maximum: 30
    Minimum: 5


//10. Finding sum and average
import java.util.Scanner;
public class ArraySumAverage {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        int sum = 0;
        for (int num : arr) sum += num;

        double avg = (double) sum / n;
        System.out.println("Sum = " + sum);
        System.out.println("Average = " + avg);
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 4
    Enter 4 elements: 10 20 30 40
    Sum = 100
    Average = 25.0


//11. Finding second largest and second smallest
import java.util.Arrays;
import java.util.Scanner;
public class ArraySecondLargestSmallest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        Arrays.sort(arr);
        System.out.println("Second Smallest: " + arr[1]);
        System.out.println("Second Largest: " + arr[n - 2]);
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 5
    Enter 5 elements: 10 20 5 30 15
    Second Smallest: 10
    Second Largest: 20


//12. Finding frequency of elements
import java.util.Scanner;
public class ArrayFrequency {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    visited[j] = true;
                    count++;
                }
            }
            System.out.println(arr[i] + " occurs " + count + " time(s)");
        }
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 7
    Enter 7 elements: 10 20 10 30 20 10 40
    10 occurs 3 time(s)
    20 occurs 2 time(s)
    30 occurs 1 time(s)
    40 occurs 1 time(s)


//13. Finding union and intersection of two arrays
import java.util.*;
public class ArrayUnionIntersection {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of first array: ");
        int n1 = sc.nextInt();
        int[] a = new int[n1];
        System.out.println("Enter elements:");
        for (int i = 0; i < n1; i++) a[i] = sc.nextInt();

        System.out.print("Enter size of second array: ");
        int n2 = sc.nextInt();
        int[] b = new int[n2];
        System.out.println("Enter elements:");
        for (int i = 0; i < n2; i++) b[i] = sc.nextInt();

        Set<Integer> union = new HashSet<>();
        for (int num : a) union.add(num);
        for (int num : b) union.add(num);

        System.out.println("Union: " + union);

        System.out.print("Intersection: ");
        for (int numA : a) {
            for (int numB : b) {
                if (numA == numB) System.out.print(numA + " ");
            }
        }
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of first array: 4
    Enter elements: 10 20 30 40
    Enter size of second array: 3
    Enter elements: 30 40 50
    Union: [50, 20, 40, 10, 30]
    Intersection: 30 40


//14. Finding common elements in two arrays
import java.util.Scanner;
public class ArrayCommonElements {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of first array: ");
        int n1 = sc.nextInt();
        int[] a = new int[n1];
        System.out.println("Enter elements:");
        for (int i = 0; i < n1; i++) a[i] = sc.nextInt();

        System.out.print("Enter size of second array: ");
        int n2 = sc.nextInt();
        int[] b = new int[n2];
        System.out.println("Enter elements:");
        for (int i = 0; i < n2; i++) b[i] = sc.nextInt();

        System.out.println("Common elements:");
        for (int x : a) {
            for (int y : b) {
                if (x == y) {
                    System.out.print(x + " ");
                    break;
                }
            }
        }
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of first array: 4
    Enter elements: 10 20 30 40
    Enter size of second array: 3
    Enter elements: 30 40 50
    Common elements: 30 40


//15. Finding difference of two arrays
import java.util.Scanner;
public class ArrayDifference {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of first array: ");
        int n1 = sc.nextInt();
        int[] a = new int[n1];
        System.out.println("Enter elements:");
        for (int i = 0; i < n1; i++) a[i] = sc.nextInt();

        System.out.print("Enter size of second array: ");
        int n2 = sc.nextInt();
        int[] b = new int[n2];
        System.out.println("Enter elements:");
        for (int i = 0; i < n2; i++) b[i] = sc.nextInt();

        System.out.println("Difference (elements in A not in B):");
        for (int x : a) {
            boolean found = false;
            for (int y : b) {
                if (x == y) {
                    found = true;
                    break;
                }
            }
            if (!found) System.out.print(x + " ");
        }
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of first array: 4
    Enter elements: 10 20 30 40
    Enter size of second array: 3
    Enter elements: 30 40 50
    Difference (elements in A not in B): 10 20


//16. Finding subarray with given sum
import java.util.Scanner;
public class SubarrayWithGivenSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.print("Enter target sum: ");
        int sum = sc.nextInt();

        boolean found = false;
        for (int i = 0; i < n; i++) {
            int currSum = 0;
            for (int j = i; j < n; j++) {
                currSum += arr[j];
                if (currSum == sum) {
                    System.out.println("Subarray found from index " + i + " to " + j);
                    found = true;
                }
            }
        }
        if (!found) System.out.println("No subarray found!");
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 5
    Enter 5 elements: 10 20 30 40 50
    Enter target sum: 70
    Subarray found from index 1 to 2
    Subarray found from index 2 to 3


//17. Finding pair with given sum
import java.util.Scanner;
public class PairWithGivenSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.print("Enter target sum: ");
        int sum = sc.nextInt();

        boolean found = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    System.out.println("Pair found: (" + arr[i] + ", " + arr[j] + ")");
                    found = true;
                }
            }
        }
        if (!found) System.out.println("No pair found!");
        sc.close();
    }
}
    Sample Input/Output:
    Enter size of array: 5
    Enter 5 elements: 10 20 30 40 50
    Enter target sum: 70
    Pair found: (20, 50)
    Pair found: (30, 40)
 */