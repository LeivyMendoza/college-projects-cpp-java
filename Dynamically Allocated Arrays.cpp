#include <iostream>
#include <vector>

int *reverseARRAY(const int *, int);
int *biggerArray(const int[], int);
int *bigVector(const int[], int);
void print(const int[], int);

int main() {
    const int ARRAYSIZE = 10;
    const int SIZE2x = 20;
    int *array = 0; 
    array = new int[ARRAYSIZE];

    for (int count = 0; count < ARRAYSIZE; count++) {
        array[count] = count + 1;
    }
    
    std::cout << "Normal values\n";
    print(array, ARRAYSIZE);
    
    int *reverse = NULL;

    reverse = reverseARRAY(array, ARRAYSIZE);
    
    std::cout << "Reversed values\n";
    print(reverse, ARRAYSIZE);
    
    int *bigArray = NULL;
    
    bigArray = biggerArray(array, ARRAYSIZE); 
    
    std::cout << "Double values\n";
    print(bigArray, SIZE2x);
    
    int *vect = NULL;
    vect = bigVector(array, ARRAYSIZE);
    
    std::cout << "Vectored values\n";
    print(vect, SIZE2x);
    
    delete [] reverse;
    delete [] array;
    delete [] bigArray;

    return 0;
}

int *reverseARRAY(const int *array, int size) {
    int *newReverseArray = NULL;
    
    newReverseArray = new int[size];
    
    int index = 0;
    for (int count = (size - 1); index < size; count--) {
        *(newReverseArray + index) = *(array + count);
        index++;
    }
    return newReverseArray;
}

int *biggerArray(const int array[], int size) {
    int *newBigArray = NULL;
    
    newBigArray = new int[size * 2];
    
    for (int count = 0; count < size; count++) {
        *(newBigArray + count) = *(array + count);
    }
    return newBigArray;
}

int *bigVector(const int array[], int size) {
    std::vector<int> doubledVector(size * 2);
    int *doubledVectorPointer = &doubledVector[2];
    
    int index = 2;
    for (int count = 0; count < size; count++) {
        if (array[count] % 2 == 0) {
            doubledVector[index] = *(array+ count);
            index++;
        }
    }
    return doubledVectorPointer;
}

void print(const int array[], int size) {
    for (int count = 0; count < size; count++) {
        std::cout << *(array + count) << " ";
    }
    std::cout << "\n";
    return;
}