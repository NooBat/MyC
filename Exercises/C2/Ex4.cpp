#include<iostream>

using namespace std;


/** Gives the sum of numbers from integer start to integer end.
 * @param Intergers start and end
 * @pre end >= start
 * @post returns sum as integer */
int sumOfStartToEnd(int start, int end) {
    if (start > end) return 0;
    if (start == end) return start;

    return start + sumOfStartToEnd(start + 1, end);
}

int main() {
    int start, end;
    do {
        cin >> start >> end;
    }
    while (start > end);

    cout << sumOfStartToEnd(start, end);

    return 0;
}