import time

def issafe(arr, x, y, n):
    # Check the column for already placed queens
    for row in range(x):
        if arr[row][y] == 1:
            return False
    
    # Check the upper-left diagonal
    row, col = x, y
    while row >= 0 and col >= 0:
        if arr[row][col] == 1:
            return False
        row -= 1
        col -= 1
    
    # Check the upper-right diagonal
    row, col = x, y
    while row >= 0 and col < n:
        if arr[row][col] == 1:
            return False
        row -= 1
        col += 1
    
    return True

def nQueen(arr, x, n, solutions):
    # If all queens are placed
    if x == n:
        temp = []
        for row in range(n):
            temp.append(arr[row][:])  # Copy the current arrangement
        solutions.append(temp)
        return
    
    # Try placing queens in each column of the current row
    for row in range(n):
        if issafe(arr, x, row, n):  # Check if it's safe to place a queen
            arr[x][row] = 1  # Place the queen
            nQueen(arr, x + 1, n, solutions)  # Recur to place the next queen
            arr[x][row] = 0  # Backtrack: remove the queen

def main():
    start_time = time.time()  # Start the timer
    
    n = int(input("Enter number of Queens: "))
    arr = [[0] * n for _ in range(n)]
    solutions = []
        
    # Asking the user to input the position of the first queen
    first_queen_x = int(input(f"Enter row (0 to {n-1}) of the first queen: "))
    first_queen_y = int(input(f"Enter column (0 to {n-1}) of the first queen: "))
        
    # Validate the input coordinates
    if 0 <= first_queen_x < n and 0 <= first_queen_y < n:
        arr[first_queen_x][first_queen_y] = 1  # Place the first queen
        nQueen(arr, first_queen_x + 1, n, solutions)  # Start from the next row
            
        if not solutions:
            print("No solutions found.")
        else:
            print(f"Found {len(solutions)} solutions:")
            for idx, sol in enumerate(solutions, 1):
                print(f"Arrangement {idx}:")
                for row in sol:
                    print(" ".join("Q " if cell == 1 else ". " for cell in row))
                print()
            print("Possible solutions =", idx)
    else:
        print("Invalid position for the first queen. Please try again.")
    
    end_time = time.time()  # End the timer
    execution_time = end_time - start_time  # Calculate execution time
    print(f"Execution time: {execution_time:.6f} seconds")

if __name__ == '__main__':
    main()

# Time complexity = O(N!)