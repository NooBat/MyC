#include<bits/stdc++.h>

using namespace std;

//[Q1.1]
int* zeros(int n) {
    if (!n) return nullptr;

    try {
        int* res = nullptr;        
        
        res = new int[n];
        
        for (int i = 0; i < n; i++) {
            *(res + i) = 0;
        }
        
        return res;
    } catch(exception& e) {
        return nullptr;
    }
}


//[Q1.2]
void shallowCopy(int*& newArr, int*& arr) {
    newArr = arr;
}


//[Q1.5]
void deleteMatrix(int**& matrix, int r) {
    // TODO;
    for (int i = 0; i < r; i++) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    
    delete[] matrix;
    matrix = nullptr;
}


//[Q1.3]
int** deepCopy(int** matrix, int r, int c) {
    // TODO
    if (r == 0 || c == 0) return nullptr;

    try {
        int** newMatrix = new int*[r];
        
        for (int i = 0; i < r; i++) {
            newMatrix[i] = new int[c];
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                newMatrix[i][j] = matrix[i][j];
            }
        }
        
        return newMatrix;
    } catch(const exception& e) {
        return nullptr;
    }
}


//[Q1.7]
void insertRow(int**& matrix, int r, int c, int* rowArr, int row) {
    // TODO
    if (row > r || c == 0) {
        matrix = nullptr;
        return;
    }
    
    try {
        int rowIndex = 0;
        r++;
        int** newMatrix = new int*[r];
        
        for (int i = 0; i < r; i++) {
            newMatrix[i] = new int[c];

            if (i == row) {
                for (int j = 0; j < c; j++) {
                    newMatrix[i][j] = rowArr[j];
                }
            } else {
                for (int j = 0; j < c; j++) {
                    newMatrix[i][j] = matrix[rowIndex][j];
                }
                rowIndex++;
            }

        }
        
        for (int i = 0; i < r - 1; i++) {
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
        
        delete[] matrix;
        matrix = nullptr;

        matrix = new int*[r];
        
        matrix = newMatrix;
    }
    catch(const exception& e) {
        matrix = nullptr;
        return;
    }
}


//[Q2.1]
struct SCP {
    // Student answer
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};


//[Q2.4]
void addAddendum(SCP &obj, string addendum) {
    // Student answer
    obj.numAddendums += 1;
    string* newAddendums = new string[obj.numAddendums];
    for (int i = 0; i < obj.numAddendums - 1; i++) {
        newAddendums[i] = obj.addendums[i];
    }
    newAddendums[obj.numAddendums - 1] = addendum;
    
    delete[] obj.addendums;
    obj.addendums = newAddendums;
}


//[Q3.1]
struct node
{
  int data;
  node *next;
};

bool isEqual(node *head1, node *head2)
{
  // TO DO
  node* ptr1 = head1;
  node* ptr2 = head2;
  
  while (ptr1 != nullptr && ptr2 != nullptr) {
      if (ptr1->data != ptr2->data) {
          return false;
      }
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
  } 
  
  if (ptr1 != nullptr || ptr2 != nullptr) {
      return false;
  }
  return true;
}


//[Q3.2]
int countNode(node* head)
{
  //TODO
  node* ptr = head;
  int count = 0;
  
  while (ptr != nullptr) {
      count++;
      ptr = ptr->next;
  }
  
  return count;
}


//[Q3.4]
node *createLinkedList(int n)
{
    node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        
        if (!head) {
            head = new node();
            head->data = d;
            head->next = nullptr;
        } else {
            node* newNode = new node();
            newNode->data = d;
            newNode->next = head;
            
            head = newNode;
        }
    }
    
    return head;
}

int main() {
    int **matrix = new int*[2];

    for (int i = 0; i < 2; i++) {
        matrix[i] = new int[3];
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i + j + 1;
        }
    }

    int* rowArr = new int[3];
    for (int i = 0; i < 3; i++) {
        rowArr[i] = 7 + i;
    }

    insertRow(matrix, 2, 3, rowArr, 2);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
