#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// Iterative Fibonacci Calculation (with series printing)
void fibonacciIterative(int n) {
    int a = 0, b = 1, fib;
    cout << "Fibonacci series (iterative): ";
    if (n >= 0) cout << a << " ";  // First Fibonacci number
    if (n >= 1) cout << b << " ";  // Second Fibonacci number
    
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        cout << fib << " ";
        a = b;
        b = fib;
    }
    cout << endl;
}

// Recursive Fibonacci Calculation (with series printing)
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

void fibonacciRecursiveSeries(int n) {
    cout << "Fibonacci series (recursive): ";
    for (int i = 0; i <= n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }
    cout << endl;
}

// Measure execution time for the given function over multiple runs
double measureExecutionTime(void (*func)(int), int n, int runs) {
    vector<double> durations;
    for (int i = 0; i < runs; i++) {
        auto start = chrono::high_resolution_clock::now();
        func(n);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        durations.push_back(duration.count() * 1000);  // Convert to milliseconds
    }

    // Calculate average duration
    double totalDuration = 0;
    for (double dur : durations) {
        totalDuration += dur;
    }
    return totalDuration / runs;
}

int main() {
    int n, runs = 1000;
    cout << "Enter the position (n) of Fibonacci number to calculate: ";
    cin >> n;

    // Measure execution time for iterative method and print series
    auto start_iterative = chrono::high_resolution_clock::now();
    fibonacciIterative(n);  // Print series for iterative
    auto end_iterative = chrono::high_resolution_clock::now();
    chrono::duration<double> iterative_duration = end_iterative - start_iterative;
    cout << "Execution time (iterative): " << iterative_duration.count() * 1000 << " milliseconds" << endl;

    // Measure execution time for recursive method and print series
    auto start_recursive = chrono::high_resolution_clock::now();
    fibonacciRecursiveSeries(n);  // Print series for recursive
    auto end_recursive = chrono::high_resolution_clock::now();
    chrono::duration<double> recursive_duration = end_recursive - start_recursive;
    cout << "Execution time (recursive): " << recursive_duration.count() * 1000 << " milliseconds" << endl;

    return 0;
}
// Recursive Approach:

// // Time Complexity: O(2*n)
// // Space Complexity: O(n)

// // Iterative Approach:

// // Time Complexity : O(n)
// // Space Complexity : O(1)