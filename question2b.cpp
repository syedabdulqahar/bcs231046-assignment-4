#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void bubbleSort(vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; i++) {
        for (size_t j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void printFirstAndLastTen(const vector<int>& vec) {
    for (int i = 0; i < 10; ++i) {
        cout << vec[i] << " ";
    }
    cout << "\n...\n";
    for (int i = vec.size() - 10; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 100000;
    vector<int> vec(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        vec[i] = SIZE - i; 
    }

    vector<int> vecForBubbleSort = vec; 

    // STL sort
    clock_t start = clock();
    sort(vec.begin(), vec.end());
    clock_t end = clock();
    cout << "STL sort time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    printFirstAndLastTen(vec);

    // Bubble sort
    start = clock();
    bubbleSort(vecForBubbleSort);
    end = clock();
    cout << "Bubble sort time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    printFirstAndLastTen(vecForBubbleSort);

    return 0;
}
