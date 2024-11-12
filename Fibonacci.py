import time

def fibonacci_recursion(n):
    if n <= 1:
        return n
    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2)

def fibonacci_non_recursion(n):
    if n <= 1:
        return n
    a, b = 0, 1
    for _ in range(2, n + 1):
        temp = a + b
        a = b
        b = temp
    return b

def measure_execution_time(func, n):
    start_time = time.perf_counter()  # Use perf_counter for better precision
    result = func(n)                  # Execute the function
    end_time = time.perf_counter()    # End time
    execution_time = end_time - start_time  # Calculate execution time
    return result, execution_time

if __name__ == "__main__":
    n = int(input("Enter the value of n: "))

    # Measure execution time for recursion
    result_rec, time_rec = measure_execution_time(fibonacci_recursion, n)
    print(f"Fibonacci({n}) using recursion:", end=" ")
    for i in range(n):
        print(fibonacci_recursion(i), end=" ")
    print()  # New line after printing the series
    print(f"Execution time (recursion): {time_rec:.10f} seconds")

    # Measure execution time for non-recursion (iterative)
    result_non_rec, time_non_rec = measure_execution_time(fibonacci_non_recursion, n)
    print(f"Fibonacci({n}) using non-recursion:", end=" ")
    for i in range(n):
        print(fibonacci_non_recursion(i), end=" ")
    print()  # New line after printing the series
    print(f"Execution time (non-recursion): {time_non_rec:.10f} seconds")

''' Recursive Approach:

// Time Complexity: O(2*n)
// Space Complexity: O(n)

// Iterative Approach:

// Time Complexity : O(n)
// Space Complexity : O(1)'''