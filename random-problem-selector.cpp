#include <bits/stdc++.h>
using namespace std;

int main() {
    int noOfDaysCompleted = 0;
    cout << "Enter no of days completed = ";
    cin >> noOfDaysCompleted;

    vector<int> problemsByDay = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 6, 7, 10, 6, 6, 12, 8, 7, 7, 8, 6, 12, 6, 7, 8, 7};

    if (noOfDaysCompleted <= 0 || noOfDaysCompleted > problemsByDay.size()) {
        cout << "Invalid number of days completed! Must be between 1 and " << problemsByDay.size() << "." << endl;
        return 1;
    }

    // Seed a random number generator
    random_device rd;
    mt19937 gen(rd());

    // Define random distributions
    uniform_int_distribution<> dayDist(0, noOfDaysCompleted - 1);
    int day = dayDist(gen);

    uniform_int_distribution<> problemDist(1, problemsByDay[day]);
    int problem = problemDist(gen);

    cout << "Random Selector: Day " << (day + 1) << ", Problem No. " << problem << endl;

    return 0;
}

// compile_cmd : g++ random-problem-selector.cpp -std=c++11 -o output
// output_cmd  : ./output