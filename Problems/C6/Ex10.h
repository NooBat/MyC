#ifndef _TOWER
#define _TOWER

#include "/Users/danielnguyen/Repo/C++/ADT/Stack.h"
#include<math.h>

using namespace std;

class Solution {
public: 
    LinkedStack<int> solveTower(int count) {
        LinkedStack<int> source;
        LinkedStack<int> destination;
        LinkedStack<int> auxiliary;

        for (int i = count; i >= 1; i--) {
            source.push(i);
        }
        
        int numberOfSteps = pow(2, count) - 1;

        for (int i = 1; i <= numberOfSteps; i++) {
            if (i % 3 == 1) {
                if (destination.isEmpty()) {
                    cout << "Move disk " << source.peek() << " from source to destination" << endl;
                    destination.push(source.peek());
                    source.pop();
                }
                else if (source.isEmpty()) {
                    cout << "Move disk " << destination.peek() << " from destination to source" << endl;
                    source.push(destination.peek());
                    destination.pop();
                }
                else if (destination.peek() > source.peek()) {
                    cout << "Move disk " << source.peek() << " from source to destination" << endl;
                    destination.push(source.peek());
                    source.pop();
                }
                else if (destination.peek() < source.peek()) {
                    cout << "Move disk " << destination.peek() << " from destination to source" << endl;
                    source.push(destination.peek());
                    destination.pop();
                }
            }
            else if (i % 3 == 2) {
                if (auxiliary.isEmpty()) {
                    cout << "Move disk " << source.peek() << " from source to auxiliary" << endl;
                    auxiliary.push(source.peek());
                    source.pop();
                }
                else if (source.isEmpty()) {
                    cout << "Move disk " << auxiliary.peek() << " from auxiliary to source" << endl;
                    source.push(auxiliary.peek());
                    auxiliary.pop();
                }
                else if (auxiliary.peek() > source.peek()) {
                    cout << "Move disk " << source.peek() << " from source to auxiliary" << endl;
                    auxiliary.push(source.peek());
                    source.pop();
                }
                else if (auxiliary.peek() < source.peek()) {
                    cout << "Move disk " << auxiliary.peek() << " from auxiliary to source" << endl;
                    source.push(auxiliary.peek());
                    auxiliary.pop();
                }
            }
            else if (i % 3 == 0) {
                if (destination.peek() > auxiliary.peek()) {
                    cout << "Move disk " << auxiliary.peek() << " from auxiliary to destination" << endl;
                    destination.push(auxiliary.peek());
                    auxiliary.pop();
                }
                else {
                    cout << "Move disk " << destination.peek() << " from destination to auxiliary" << endl;
                    auxiliary.push(destination.peek());
                    destination.pop();
                }
            }
        }

        return (destination.isEmpty()) ? (auxiliary) : (destination);
    }
};

#endif