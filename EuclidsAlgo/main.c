#include <stdio.h>

/*
Common Big-O Terms
Notation        Description         Example
O(1)            Constant time       Looking up a simle element in an array
O(log n)        Logarithmic         Finding an item in a sorted array with a binary search
O(n)            Linear time         Searching an unsorted array for a specific value
O(n log n)      Log-linear          Complex sorting algorithms like heap sort and merge sort
O(n2)           Quadratic           Simple sorting algoritums, such as bubble sort, selection sort, and insertion sort.
*/

/*
Common Data Structures
- Array
- Linked lists
- Stacks and queues
- Trees
- Hash tables
*/

//Find the greatest common denominator of two numbers
// using Euclid's algorithm
int gcd(int a, int b)
{
    while(b != 0){
        int t = a;
        a = b;
        b = t % b;
    }

    return a;
}

int main()
{
    //try out the function with a few examples
    printf("%d\n", gcd(60, 96)); //should be 12
    printf("%d\n", gcd(20, 8)); //should be 4
}