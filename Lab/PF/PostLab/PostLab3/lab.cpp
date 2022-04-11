#include<bits/stdc++.h>

//[Q1.9]
bool deleteRow(int**& matrix, int r, int c, int row) {
    // TODO
    if (r * c == 0) {
        matrix = nullptr;
        return false;
    } else if (row < 0 || row >= r) {
        return false;
    } else if (r == 1) {
        delete[] matrix[0];
        delete[] matrix;
        matrix = nullptr;
        return true;
    }

    int** newMatrix = new int*[r - 1];
    int rowIndex = 0;

    for (int i = 0; i < r; i++) {
        if (i != row) {
            newMatrix[rowIndex] = new int[c];

            for (int j = 0; j < c; j++) {
                newMatrix[rowIndex][j] = matrix[i][j];
            }

            ++rowIndex;
        }
    }

    for (int i = 0; i < r; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = newMatrix;

    return true;
}


//[Q1.10]
void transpose(int**& matrix, int r, int c) {
    int** newMatrix = new int*[c];
    
    for (int i = 0; i < c; i++) {
        newMatrix[i] = new int[r];
        
        for (int j = 0; j < r; j++) {
            newMatrix[i][j] = matrix[j][i];
        }
    }
    
    for (int i = 0; i < r; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    matrix = newMatrix;
}

bool deleteCol(int**& matrix, int r, int c, int col) {
    // TODO
    if (r * c == 0) {
        matrix = nullptr;
        return false;
    } else if (col < 0 || col >= c) {
        return false;
    } else if (c == 1) {
        for (int i = 0; i < r; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;
        return true;
    }
    
    int** transposeMatrix = new int*[c - 1];
    int colIndex = 0;
    
    for (int i = 0; i < c; i++) {
        if (i != col) {
            transposeMatrix[colIndex] = new int[r];

            for (int j = 0; j < r; j++) {
                transposeMatrix[colIndex][j] = matrix[j][i];
            }
            
            colIndex++;
        }
    }
    
    transpose(transposeMatrix, c - 1, r);
    
    for (int i = 0; i < r; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    matrix = transposeMatrix;
    
    return true;
}


//[Q1.8]
int** insertCol(int**& matrix, int r, int c, int* colArr, int col) {
    // TODO
    if (r == 0) {
        matrix = nullptr;
        return matrix;
    } else if (col < 0 || col > c) {
        return matrix;
    }
    
    for (int i = 0; i < r; i++) {
        int* newMatrix = new int[c + 1];
        int colIdx = 0;
        
        for (int j = 0; j < c + 1; j++) {
            if (j == col) {
                newMatrix[j] = colArr[i];
            } else {
                newMatrix[j] = matrix[i][colIdx++];
            }
        }
        
        delete[] matrix[i];
        matrix[i] = newMatrix;
    }
    
    return matrix;
}


//[Q2.7]
struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};

int compareObjectClass(const SCP &objA, const SCP &objB) {
    // Student answer
    int result;
    if (objA.objClass == objB.objClass) {
        result = 0;
    } else if (objA.objClass > objB.objClass) {
        result = 1;
    } else {
        result = -1;
    }
    
    return result;
}


//[Q2.6]
SCP** sortDatabase(SCP** arr, int n) {
    // Student answer
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i]->id > arr[j]->id) {
                swap(arr[i], arr[j]);
            }
        }
    }
    
    return arr;
}


//[Q3.5]
struct node
{
    int data;
    node *next;
};

node* evenThenOddLinkedList(node *head)
{
    //TODO
    int n = 0;

    node* temp = head;

    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }

    int* even = new int[n];
    int evenIdx = 0;
    int* odd = new int[n];
    int oddIdx = 0;

    for (node* i = head; i != nullptr; i = i->next) {
        if (i->data % 2 == 0) {
            even[evenIdx++] = i->data;
        } else {
            odd[oddIdx++] = i->data;
        }
    }

    temp = head;
    for (int i = 0; temp != nullptr; i++) {
        if (i < evenIdx) {
            temp->data = even[i];
        } else {
            temp->data = odd[i - evenIdx];
        }
        
        temp = temp->next;
    }

    delete[] even;
    even = nullptr;
    delete[] odd;
    odd = nullptr;

    return head;
}


//[Q3.7]
void mergeList(node* head1, node* head2)
{
  // TODO
  while (head1->next) {
      head1 = head1->next;
  }
  
  head1->next = head2;
}