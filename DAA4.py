import time

# Function to solve 0-1 Knapsack problem using Dynamic Programming and display the DP table
def knapsack_dp(weights, values, capacity):
    n = len(values)
    
    # Create a DP table with dimensions (n+1) x (capacity+1)
    dp = [[0 for x in range(capacity + 1)] for y in range(n + 1)]
    
    # Build the table dp[][] in bottom-up manner
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                # Include the item, or exclude it
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
            else:
                # Exclude the item
                dp[i][w] = dp[i - 1][w]

    # Print the DP table with proper formatting
    print("\nDP Table:")
    print("     ", end="")  # For proper header alignment
    for w in range(capacity + 1):
        print(f"{w:4}", end="")  # Printing column headers for weights
    print()
    
    for i in range(n + 1):
        print(f"{i:3} ", end="")  # Printing row headers for items
        for w in range(capacity + 1):
            print(f"{dp[i][w]:4}", end="")  # Formatting each DP cell with width 4 for alignment
        print()

    # The last cell of the table contains the maximum value
    return dp[n][capacity]

# Taking user input
n = int(input("Enter the number of items: "))

weights = []
values = []

for i in range(n):
    weight = int(input(f"Enter weight of item {i+1}: "))
    value = int(input(f"Enter profit of item {i+1}: "))
    weights.append(weight)
    values.append(value)

capacity = int(input("Enter the capacity of the knapsack: "))

# Start timer
start_time = time.time()

# Solving the problem
max_value = knapsack_dp(weights, values, capacity)

# End timer
end_time = time.time()

# Display the result and execution time
print(f"\nThe maximum value that can be carried using Dynamic Programming is {max_value}")
print(f"Execution time: {end_time - start_time:.6f} seconds")













# Enter the number of items: 4
# Enter weight of item 1: 2
# Enter profit of item 1: 3
# Enter weight of item 2: 2  
# Enter profit of item 2: 7
# Enter weight of item 3: 4
# Enter profit of item 3: 2
# Enter weight of item 4: 5
# Enter profit of item 4: 9
# Enter the capacity of the knapsack: 10

# DP Table:
#         0   1   2   3   4   5   6   7   8   9  10
#   0    0   0   0   0   0   0   0   0   0   0   0
#   1    0   0   3   3   3   3   3   3   3   3   3
#   2    0   0   7   7  10  10  10  10  10  10  10
#   3    0   0   7   7  10  10  10  10  12  12  12
#   4    0   0   7   7  10  10  10  16  16  19  19

# The maximum value that can be carried using Dynamic Programming is 19
# Execution time: 0.007126 seconds


# Enter the number of items: 3
# Enter weight of item 1: 1
# Enter profit of item 1: 10
# Enter weight of item 2: 2
# Enter profit of item 2: 12
# Enter weight of item 3: 4
# Enter profit of item 3: 28
# Enter the capacity of the knapsack: 6

# DP Table:
#         0   1   2   3   4   5   6
#   0    0   0   0   0   0   0   0
#   1    0  10  10  10  10  10  10
#   2    0  10  12  22  22  22  22
#   3    0  10  12  22  28  38  40

# The maximum value that can be carried using Dynamic Programming is 40
# Execution time: 0.002409 seconds





# Enter the number of items: 3
# Enter weight of item 1: 1
# Enter profit of item 1: 10
# Enter weight of item 2: 2
# Enter profit of item 2: 12
# Enter weight of item 3: 4
# Enter profit of item 3: 28
# Enter the capacity of the knapsack: 6

# DP Table:
#         0   1   2   3   4   5   6
#   0    0   0   0   0   0   0   0
#   1    0  10  10  10  10  10  10
#   2    0  10  12  22  22  22  22
#   3    0  10  12  22  28  38  40

# The maximum value that can be carried using Dynamic Programming is 40
# Execution time: 0.002409 seconds


# Time O(n*w)
# Space O(n*w)

# imp formulas

# K(i,c)=max[(pi+k(i-1,c-wi)),k(i-1,c)]       for include and exclude            
# 0 if  i=0 or  c=0
# K(i-1,C) (wi>C )           for exclude