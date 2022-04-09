#include<bits/stdc++.h>

void addElement(int*& arr, int n, int val, int index) {
    // TODO
    n += 1;
    int idx = 0;
    int* newArr = new int[n];
    
    for (int i = 0; i < n; i++) {
        if (i == index) {
            newArr[i] = val;
        } else {
            newArr[i] = arr[idx++];
        }
    }
    
    delete[] arr;
    
    arr = newArr;
}

int* flatten(int** matrix, int r, int c) {
    if (r * c == 0) return nullptr;
    
    int* flattenArr = new int[r * c];
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            flattenArr[i * c + j] = matrix[i][j];
        }
    }
    
    return flattenArr;   
}

int length(char* str) {
    int count = 0;
    
    while (str[count] != '\0') {
        count++;
    }
    
    return count;
}

char* concatStr(char* str1, char* str2) {
    // TODO
    int l1 = length(str1);
    int l2 = length(str2);
    
    char* str = new char[l1 + l2 + 1];
    
    int index = 0;
    
    for (int i = 0; i < l1; i++) {
        str[index] = str1[i];
        index++;
    }
    
    for (int i = 0; i < l2; i++) {
        str[index] = str2[i];
        index++;
    }
    
    str[l1 + l2] = '\0';
    
    return str;
}

int** readArray()
{
   //TODO

    int** matrix = new int*[10];
   
    for (int i = 0; i < 10; i++) {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; j++) {
            int num;
            cin >> num;
            if (num == 0) {
                for (int k = j; k < 10; k++) {
                    matrix[i][k] = 0;
                }
                break;
            } else {
                matrix[i][j] = num;
            }
        }
    }
    
    return matrix;
}

int** transposeMatrix(int** matrix, int r, int c) {
    // TODO
    if (r * c == 0) return nullptr;
    
    int** matrixT = new int*[c];
    
    for (int i = 0; i < c; i++) {
        matrixT[i] = new int[r];
        
        for (int j = 0; j < r; j++) {
            matrixT[i][j] = matrix[j][i];
        }
    }
    
    return matrixT;
}

struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};

SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums) {
    SCP newSCP;
    newSCP.id = id;
    newSCP.objClass = objClass;
    newSCP.speConProcedures = speConProcedures;
    newSCP.description = description;
    newSCP.numAddendums = numAddendums;
    
    newSCP.addendums = new string[numAddendums];
    
    for (int i = 0; i < numAddendums; i++) {
        newSCP.addendums[i] = addendums[i];
    }
    
    return newSCP;
}

string convertToString(SCP obj) {
    // Student answer
    string result;
    string id;
    string objClass;
    string speConProcedures = "Special Containment Procedures: " + obj.speConProcedures + "\n";
    string description = "Description: " + obj.description + "\n";
    
    
    if (obj.id < 10) {
        id = "00" + to_string(obj.id);        
    } else if (obj.id < 100) {
        id = "0" + to_string(obj.id);
    } else {
        id = to_string(obj.id);
    }
    
    if (obj.objClass == 0) {
        objClass = "Safe\n";
    } else if (obj.objClass == 1) {
        objClass = "Euclid\n";
    } else {
        objClass = "Keter\n";
    }
    
    result = "Item #: SCP-" + id + "\n" + 
             "Object Class: " + objClass + 
             speConProcedures + 
             description;
    
    for (int i = 0; i < obj.numAddendums; i++) {
        result += obj.addendums[i] + "\n";
    }
    
    return result;
}

SCP* cloneSCP(SCP* original) {
    // Student answer
    SCP* clone = new SCP;
    
    clone->id = original->id;
    clone->objClass = original->objClass;
    clone->speConProcedures = original->speConProcedures;
    clone->description = original->description;
    clone->numAddendums = original->numAddendums;
    
    clone->addendums = new string[clone->numAddendums];
    
    for (int i = 0; i < clone->numAddendums; i++) {
        clone->addendums[i] = original->addendums[i];
    }
    
    return clone;
}

struct node {
    int data;
    node* next;
};

node *createLinkedList(int n)
{
    // TO DO
    node* head = nullptr;
    node* temp = nullptr;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        if (!head) {
            head = new node;
            head->data = num;
            head->next = nullptr;
            temp = head;
        } else {
            node* newNode = new node;
            newNode->data = num;
            newNode->next = nullptr;
            
            temp->next = newNode;
            
            temp = temp->next;
        }
    }
    temp = nullptr;
    return head;
}

int searchLinkedList(node* head, int key)
{
    // TODO
    node* temp = head;
    int index = 0;
    bool found = false;
    
    while (temp != nullptr) {
        if (temp->data == key) {
            found = true;
            break;
        }
        
        temp = temp->next;
        index++;
    }
    
    return ((found) ? (index) : (-1));
}

void replace(node* head, int position, int value)
{
    //TODO
    node* temp = head;
    for (int i = 0; temp != nullptr; i++) {
        if (i == position) {
            temp->data = value;
            break;
        } 
        temp = temp->next;
    }
}

node *insertNode(node *head, node *newNode, int position)
{
  // TO DO
  if (position <= 0) return head;
 
  node* temp = head;
  bool success = false;
  for (int i = 0; temp->next != nullptr; i++) {
      if (i == position - 2) {
          success = true;
          node* newPtr = temp->next;
          temp->next = newNode;
          newNode->next = newPtr;
          break;
      }
      temp = temp->next;
  }
  
  if (!success) {
      temp->next = newNode;
  }
  
  return head;
}