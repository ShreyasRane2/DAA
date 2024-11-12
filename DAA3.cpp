#include <bits/stdc++.h>
using namespace std;
#include <chrono> // For measuring execution time

// Define a structure to store the profit and weight of each item
struct Item {
    int profit;
    int weight;
};

// Comparator function to sort items by profit-to-weight ratio in descending order
bool compare(Item i1, Item i2) {
    double r1 = (double) i1.profit / i1.weight;
    double r2 = (double) i2.profit / i2.weight;
    return r1 > r2;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter profit and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
    }

    int w;
    cout << "Enter the capacity of the knapsack: ";
    cin >> w;

    // Record start time
    auto start = chrono::high_resolution_clock::now();

    // Sort items by profit-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0;          // Total profit from selected items
    vector<double> fraction(n, 0);   // Fraction array to store fraction of each item included

    // Process each item
    for (int i = 0; i < n; i++) {
        if (w >= items[i].weight) {
            // If the full item can be taken, take it fully
            totalProfit += items[i].profit;
            w -= items[i].weight;
            fraction[i] = 1;         // Mark as fully taken
        } else {
            // If only part of the item can be taken
            double ratio = (double) items[i].profit / items[i].weight;
            totalProfit += ratio * w;  // Add partial profit
            fraction[i] = (double) w / items[i].weight;  // Fraction of this item taken
            w = 0; // Knapsack is now full
            break;
        }
    }

    // Record end time
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start; // Calculate the duration in milliseconds

    // Display the total profit and fractions of items taken
    cout << fixed << setprecision(4); // Set precision for output
    cout << "Total Profit: " << totalProfit << endl;
    cout << "Fraction of each item taken:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << (i + 1) << ": " << fraction[i] << endl;
    }
    cout << "Execution time: " << duration.count() << " ms" << endl;

    return 0;
}

// Time Complexity = O(n log n)
// Space Complexity = O(n)


// Enter the number of items: 5
// Enter profit and weight for each item:
// 21 7
// 24 4
// 12 6
// 40 5
// 30 6
// Enter the capacity of the knapsack: 20
// Total Profit: 109.0000
// Fraction of each item taken:
// Item 1: 1.0000
// Item 2: 1.0000
// Item 3: 1.0000
// Item 4: 0.7143
// Item 5: 0.0000
// Execution time: 0.0000 ms