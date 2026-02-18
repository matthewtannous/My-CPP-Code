#include <iostream>

using namespace std;

double power(double, unsigned);
int factorial(int x);
long fibonacci(long x);
long fibonacciIterative(long x);
void display(int *a, int size);
void displayIterative(int *a, int size);
void towerOfHanoi(int n, char o, char i, char d);

int main()
{
    // int s = 6;
    // int *arr = new int[s];
    // // for (int i = 0; i < s; i++)
    // // {
    // //     arr[i] = rand();
    // // }

    // arr[0] = 5;
    // arr[1] = 7;
    // arr[2] = 3;
    // arr[3] = 1;
    // arr[4] = 8;
    // arr[5] = 2;

    // displayIterative(arr, s);

    // display(arr, s);
    towerOfHanoi(7, 'A', 'B', 'C');
}

void towerOfHanoi(int n, char o, char i, char d)
{
    if (n > 0)
    {
        towerOfHanoi(n - 1, o, d, i);
        cout << "From " << o << " to " << d << endl;
        towerOfHanoi(n - 1, i, o, d);
    }
}
double power(double base, unsigned n)
{
    if (n == 0)
    {
        return 1;
    }
    return power(base, n - 1) * base;
}

int factorial(int x)
{
    if (x == 0)
    {
        return 1;
    }
    return factorial(x - 1) * x;
}

// 1 1 2 3 5 8 13 21 34 55 89
long fibonacci(long x)
{
    if (x <= 2)
    {
        return 1;
    }
    return fibonacci(x - 1) + fibonacci(x - 2);
}

// fib(n) = fib(n - 1) + fib(n - 2)
long fibonacciIterative(long x)
{
    if (x <= 2)
    {
        return 1;
    }

    /*
      Every pass, we add the sum to itself and add the number before it
      fib(3) = fib(2) + fib(1)
      */
    long sum;
    long n1 = 1;
    long n2 = 1;
    for (int i = 2; i < x; i++)
    {
        sum = n1 + n2;
        if (i % 2 == 0)
        {
            n1 = sum;
        }
        else
        {
            n2 = sum;
        }
    }
    return sum;
}

void displayIterative(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " , ";
    }
    cout << endl;
}

void display(int *a, int size)
{
    if (size == 1)
    {
        cout << a[0];
    }
    if (size > 0)
    {
        // do not print bigger number
        if (a[size - 2] < a[size - 1])
        {
            // compare a[size - 2] to other number and keep repeating until it's done
            display(a, size - 1);
        }
        else
        {
            // replace both numbers and try again
            int temp = a[size - 2];
            a[size - 2] = a[size - 1];
            a[size - 1] = temp;
            display(a, size - 1);
        }
    }
}
