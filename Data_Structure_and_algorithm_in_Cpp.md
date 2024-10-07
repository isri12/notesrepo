
# I Data Structure 
## 1. Big O - Upper Bound (Worst Case)
- Big O, also known as Big O notation, represents an algorithm's worst-case complexity. It uses algebraic terms to describe the complexity of an algorithm.
- What it means: Big O (O) describes the worst-case scenario for an algorithm.
- In simple terms: It tells you the slowest an algorithm can run in the worst
circumstances.

 ### 1.1 Big O notation and how it relates to the rate of growth of a function.  
-  consider \( f(n) = 7n^3 + 100n^2 + 20n + 6 \)
1. **Highest-order Term**:
   - The highest-order term of a function is the term with the highest power of the variable (in this case, 'n'). In the given function, the highest-order term is 7n^3.

2. **Rate of Growth**:
   - The rate of growth of a function describes how quickly the function's value increases as the input size ('n') increases. In this case, the function's rate of growth is n^3 because of the highest-order term.

3. **Big O Notation**:
   - Big O notation (O()) is used to describe the upper bound of the rate of growth of a function. It represents the worst-case scenario in terms of the function's growth.
   - In the given example, the function 7n^3 + 100n^2 + 20n + 6 is said to be O(n^3) because its rate of growth is no faster than n^3.
   - However, it can also be said to be O(n^4), O(n^5), O(n^6), and so on. This is because the function grows more slowly than these higher-order terms, and thus, it is also correct to say that it grows no faster than them.
   - More generally, the function can be described as O(n^c) for any constant c ≥ 3.

In summary, the function's rate of growth determines its Big O notation, and it is possible to describe the function's growth using higher-order terms, as long as they represent an upper bound on the function's growth.

Let's write a C++ function that represents the given polynomial function \( f(n) = 7n^3 + 100n^2 + 20n + 6 \) and demonstrate how its growth rate can be described using Big O notation.

```cpp
#include <iostream>

// Function representing the polynomial: f(n) = 7n^3 + 100n^2 + 20n + 6
int polynomialFunction(int n) {
    return 7 * n * n * n + 100 * n * n + 20 * n + 6;
}

int main() {
    // Test the polynomial function for different values of n
    int n_values[] = {1, 10, 100, 1000};

    for (int n : n_values) {
        std::cout << "f(" << n << ") = " << polynomialFunction(n) << std::endl;
    }

    return 0;
}
```

### 1.2 Drop Non-Dominant 
To drop the non-dominant terms from the Big O notation of the function \( f(n) = 7n^3 + 100n^2 + 20n + 6 \), we consider only the term with the highest growth rate, which is \( 7n^3 \) in this case. 

So, the simplified Big O notation for the function \( f(n) \) is \( O(n^3) \).

This notation indicates that as the input size \( n \) grows, the dominant term \( n^3 \) will have the most significant impact on the overall growth rate of the function. The non-dominant terms \( 100n^2 \), \( 20n \), and \( 6 \) will become less significant as \( n \) becomes large.

### 1.3  asymptotic notation symbols
These are the three major asymptotic notation symbols used to describe the time complexity of algorithms:
1. **Omega (Ω)**:
   - **Meaning**: Omega (Ω) describes the best-case scenario for an algorithm. It represents the lower bound of the time complexity.
   - **Simple Explanation**: It tells you the fastest an algorithm can run in the best circumstances.

2. **Theta (Θ)**:
   - **Meaning**: Theta (Θ) represents the tight bound of the time complexity. It indicates the average or expected performance of the algorithm.
   - **Simple Explanation**: It tells you what to generally expect in terms of time complexity.

3. **Big O (O)**:
   - **Meaning**: Big O (O) describes the worst-case scenario for an algorithm. It represents the upper bound of the time complexity.
   - **Simple Explanation**: It tells you the slowest an algorithm can run in the worst circumstances.

In summary:
- Omega (Ω) gives the best-case scenario.
- Theta (Θ) provides a tight, average-case scenario.
- Big O (O) gives the worst-case scenario.
  
### 1.4 The basic concepts of Big O
These are the basic concepts of Big O notation along with their meanings and examples:

1. **O(1)**: Constant Time
   - **Meaning**: The time complexity is constant and doesn't depend on the size of the data set.
   - **Example**: Accessing an array element by its index.
```cpp
int addItems(int n){
 return n+n; //one operation
// return n+n+n ....  //still one operation  
}
```

2. **O(log n)**: Logarithmic Time
   - **Meaning**: The time complexity grows logarithmically as the size of the data set increases. Each step divides the data set in half (divide and conquer).
   - **Example**: Binary search.
```cpp
#include <iostream>
#include <vector>

class BinarySearch {
public:
    int search(const std::vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If the target is found at the middle
            if (arr[mid] == target) {
                return mid;
            }

            // If the target is greater, ignore the left half
            if (arr[mid] < target) {
                left = mid + 1;
            }
            // If the target is smaller, ignore the right half
            else {
                right = mid - 1;
            }
        }

        // If the target is not found
        return -1;
    }
};

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;

    BinarySearch bs;
    int index = bs.search(arr, target);

    if (index != -1) {
        std::cout << "Element found at index " << index << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}

```
3. **O(n)**: Linear Time
   - **Meaning**: The time complexity grows directly proportional to the size of the data set.
   - **Example**: Looping through an array.

```cpp
#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr) {
    // Iterate through the array and print each element
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Create a vector of integers
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Call the function to print the array
    printArray(numbers);

    return 0;
}
```
- Different Terms for Inputs
 To illustrate the time complexity of an algorithm with different terms for different inputs, let's consider an example where we have two separate for loops, each iterating over different inputs. 
 Suppose we have two arrays `arr1` and `arr2` of sizes `n` and `m` respectively, and we want to perform some operation on each element of both arrays. Here's how you might write the code:

```cpp
#include <iostream>
#include <vector>

void performOperation(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    // Iterate over elements of arr1 (size n)
    for (int i = 0; i < arr1.size(); ++i) {
        // Perform some operation on arr1[i]
        std::cout << "Operation on arr1[" << i << "]: " << arr1[i] << std::endl;
    }

    // Iterate over elements of arr2 (size m)
    for (int j = 0; j < arr2.size(); ++j) {
        // Perform some operation on arr2[j]
        std::cout << "Operation on arr2[" << j << "]: " << arr2[j] << std::endl;
    }
}

int main() {
    std::vector<int> arr1 = {1, 2, 3};   // Array of size n
    std::vector<int> arr2 = {4, 5, 6, 7}; // Array of size m

    performOperation(arr1, arr2);

    return 0;
}
```
- We have two separate for loops iterating over `arr1` (size `n`) and `arr2` (size `m`) respectively.
- The time complexity of the first for loop is O(n) because it iterates over `n` elements of `arr1`.
- The time complexity of the second for loop is O(m) because it iterates over `m` elements of `arr2`.
- Since the two loops are independent of each other, we can consider the overall time complexity as the sum of the time complexities of each loop, which is O(n + m). it wouldnt be O(n+n) = O(2n). 
This scenario demonstrates an example where different terms are used for different inputs, and the overall time complexity is the sum of the complexities of each part.
4. **O(n log n)**: Linearithmic Time
   - **Meaning**: The time complexity grows logarithmically with the data set size, but also performs an additional linear operation within each step.
   - **Example**: Merge sort, quick sort.
```cpp
//merge sort
#include <iostream>
#include <vector>

class MergeSort {
public:
    void sort(std::vector<int>& arr) {
        if (arr.size() <= 1) {
            return; // Base case: Array is already sorted
        }

        // Divide the array into two halves
        int mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());

        // Recursively sort the two halves
        sort(left);
        sort(right);

        // Merge the sorted halves
        merge(arr, left, right);
    }

private:
    void merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
        int i = 0, j = 0, k = 0;

        // Merge the elements from left and right arrays into arr
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        // Copy the remaining elements of left array
        while (i < left.size()) {
            arr[k++] = left[i++];
        }

        // Copy the remaining elements of right array
        while (j < right.size()) {
            arr[k++] = right[j++];
        }
    }
};

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    MergeSort sorter;
    sorter.sort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

```

```cpp
#include <iostream>
#include <vector>

class QuickSort {
public:
    void sort(std::vector<int>& arr) {
        quickSort(arr, 0, arr.size() - 1);
    }

private:
    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            // Recursively sort elements before and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Choose the last element as pivot
        int i = low - 1; // Index of smaller element

        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    QuickSort sorter;
    sorter.sort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

```
5. **O(n^2)**: Polynomial Time
   - **Meaning**: The time complexity grows quadratically with the size of the data set. Typically involves nested loops where each loop iterates over the data set.
   - **Example**: Bubble sort (O(n^2)).
```cpp
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Create a vector of integers
    std::vector<int> numbers = {5, 3, 8, 2, 1};

    // Sort the array using bubble sort
    bubbleSort(numbers);

    // Print the sorted array
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

```
Understanding these Big O concepts helps in analyzing the efficiency and scalability of algorithms and choosing the most suitable algorithm for a given problem based on its time complexity.

![Big O](images/bigo.jpg)

----------------------------------

## 2. Linked Lists

### Arrays in C++:

An array is a collection of elements of the same data type stored in contiguous memory locations. Arrays have a fixed size determined at compile time.

#### Declaration and Initialization:
```cpp
// Declaration and initialization of an array
int arr[5] = {1, 2, 3, 4, 5};
```

#### Accessing Elements:
```cpp
// Accessing elements of an array
int element = arr[2]; // Accessing the third element (index 2)
```

#### Iterating through Array:
```cpp
// Iterating through array elements using a for loop
for (int i = 0; i < 5; ++i) {
    std::cout << arr[i] << " ";
}
```
### Arrays and lists in c++
# Arrays and Lists in C++

## Arrays

### Built-in Arrays

C++ has built-in arrays which are fixed-size sequential collections of elements of the same type.

```cpp
int numbers[5] = {1, 2, 3, 4, 5};
```

Characteristics:
- Fixed size (determined at compile-time)
- Contiguous memory allocation
- Fast random access (O(1))
- Cannot be resized
- No built-in bounds checking

### std::array

`std::array` is a container that encapsulates fixed-size arrays from the C++ Standard Template Library (STL).

```cpp
#include <array>
std::array<int, 5> numbers = {1, 2, 3, 4, 5};
```

Characteristics:
- Fixed size (determined at compile-time)
- Contiguous memory allocation
- Fast random access (O(1))
- Cannot be resized
- Provides bounds checking with the `at()` method
- Knows its own size

## Lists

### std::list

`std::list` is a container that supports constant time insertion and removal of elements from anywhere in the container.

```cpp
#include <list>
std::list<int> numbers = {1, 2, 3, 4, 5};
```

Characteristics:
- Dynamic size
- Non-contiguous memory allocation (doubly-linked list)
- Slow random access (O(n))
- Fast insertion and deletion at any position (O(1))
- No direct element access (must use iterators)

## Comparison

| Feature | Built-in Array | std::array | std::list |
|---------|----------------|------------|-----------|
| Size | Fixed | Fixed | Dynamic |
| Memory | Contiguous | Contiguous | Non-contiguous |
| Random Access | O(1) | O(1) | O(n) |
| Insertion/Deletion | N/A | N/A | O(1) at any position |
| Size Overhead | None | Small | Higher |
| Iterator Invalidation | N/A | Never | Only for erased elements |

## When to Use Each

- Use built-in arrays when you need a lightweight, fixed-size collection and don't need additional safety features.
- Use `std::array` when you want a fixed-size collection with the benefits of STL containers (like bounds checking and size awareness).
- Use `std::list` when you need frequent insertions and deletions at arbitrary positions and don't need random access.

## Basic Operations

### Array Operations

```cpp
// Built-in array
int arr[5] = {1, 2, 3, 4, 5};
int element = arr[2];  // Access element (no bounds checking)

// std::array
std::array<int, 5> stdArr = {1, 2, 3, 4, 5};
int element = stdArr.at(2);  // Access with bounds checking
int size = stdArr.size();    // Get size
```

### List Operations

```cpp
std::list<int> myList = {1, 2, 3, 4, 5};

// Insert at the beginning
myList.push_front(0);

// Insert at the end
myList.push_back(6);

// Insert at a specific position
auto it = std::next(myList.begin(), 3);
myList.insert(it, 10);

// Remove an element
myList.remove(3);

// Access elements (using iterator)
for (const auto& elem : myList) {
    std::cout << elem << " ";
}
```

Remember, the choice between arrays and lists depends on your specific use case, considering factors like size flexibility, access patterns, and performance requirements.
### std::vector vs std::list(doubly linked list) in C++

# std::vector vs std::list in C++

## std::vector

std::vector is a dynamic array that can grow or shrink in size.

Characteristics:
- Contiguous memory allocation
- Fast random access (O(1))
- Fast insertion/deletion at the end (amortized O(1))
- Slow insertion/deletion at the beginning or middle (O(n))
- Automatic resizing when capacity is exceeded

## std::list

std::list is implemented as a doubly-linked list.

Characteristics:
- Non-contiguous memory allocation
- Slow random access (O(n))
- Fast insertion/deletion anywhere in the list (O(1))
- No random access operator []
- No capacity concept (size == capacity always)

## Comparison Table

| Feature | std::vector | std::list |
|---------|-------------|-----------|
| Memory layout | Contiguous | Non-contiguous |
| Random access | O(1) | O(n) |
| Insertion at end | Amortized O(1) | O(1) |
| Insertion at beginning | O(n) | O(1) |
| Insertion in middle | O(n) | O(1) |
| Deletion at end | O(1) | O(1) |
| Deletion at beginning | O(n) | O(1) |
| Deletion in middle | O(n) | O(1) |
| Memory overhead | Low | Higher (two pointers per element) |
| Iterator invalidation | On reallocation | Only for erased elements |

## When to Use Each

Use std::vector when:
- You need fast random access
- You mostly add/remove elements at the end
- You want to minimize memory usage
- You need cache-friendly traversal

Use std::list when:
- You need frequent insertions/deletions at arbitrary positions
- You don't need random access
- You want to avoid iterator invalidation on insertion/deletion
- The size of your data structure changes frequently

## Basic Usage Examples

### std::vector

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Add element to the end
    vec.push_back(6);
    
    // Access element
    std::cout << "Third element: " << vec[2] << std::endl;
    
    // Insert in the middle
    vec.insert(vec.begin() + 3, 10);
    
    // Remove last element
    vec.pop_back();
    
    // Print all elements
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

### std::list

```cpp
#include <list>
#include <iostream>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // Add element to the beginning
    lst.push_front(0);
    
    // Add element to the end
    lst.push_back(6);
    
    // Insert in the middle
    auto it = std::next(lst.begin(), 3);
    lst.insert(it, 10);
    
    // Remove an element
    lst.remove(4);
    
    // Print all elements
    for (int num : lst) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

Remember, the choice between std::vector and std::list depends on your specific use case and the operations you'll be performing most frequently.


### Sets, pair, Tuples and dictionaries in c++

#### Sets

Sets in C++ are containers that store unique elements in a specific order. The standard library provides three types of sets:

1. `std::set`: Stores unique elements in sorted order.
2. `std::unordered_set`: Stores unique elements in no particular order, but offers faster access.
3. `std::multiset`: Allows duplicate elements, stored in sorted order.

##### Example of std::set

```cpp
#include <set>
#include <iostream>

int main() {
    std::set<int> mySet = {3, 1, 4, 1, 5, 9};
    
    // Inserting elements
    mySet.insert(2);
    
    // Checking if an element exists
    if (mySet.find(4) != mySet.end()) {
        std::cout << "4 is in the set" << std::endl;
    }
    
    // Printing all elements (will be in sorted order)
    for (int num : mySet) {
        std::cout << num << " ";
    }
    // Output: 1 2 3 4 5 9
    
    return 0;
}
```

#### Pairs

`std::pair` is a simple container that holds two data elements.

##### Example of std::pair

```cpp
#include <utility>
#include <iostream>

int main() {
    std::pair<std::string, int> person("Alice", 30);
    
    std::cout << person.first << " is " << person.second << " years old." << std::endl;
    
    // Creating a pair using make_pair
    auto couple = std::make_pair("Bob", "Carol");
    
    return 0;
}
```

#### Tuples

`std::tuple` is a fixed-size collection of heterogeneous values.

##### Example of std::tuple

```cpp
#include <tuple>
#include <iostream>

int main() {
    std::tuple<int, std::string, double> myTuple(1, "Hello", 3.14);
    
    std::cout << std::get<0>(myTuple) << std::endl;  // Prints 1
    std::cout << std::get<1>(myTuple) << std::endl;  // Prints Hello
    
    // Unpacking a tuple
    int a;
    std::string b;
    double c;
    std::tie(a, b, c) = myTuple;
    
    return 0;
}
```

#### Dictionaries (Maps)

Dictionaries in C++ are implemented as maps. There are four types of maps in the STL:

1. `std::map`: Stores key-value pairs in sorted order by keys.
2. `std::unordered_map`: Stores key-value pairs in no particular order, but offers faster access.
3. `std::multimap`: Allows duplicate keys, stored in sorted order.
4. `std::unordered_multimap`: Allows duplicate keys, stored in no particular order.

##### Example of std::map

```cpp
#include <map>
#include <iostream>

int main() {
    std::map<std::string, int> ages;
    
    // Inserting key-value pairs
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    ages.insert({"Carol", 35});
    
    // Accessing values
    std::cout << "Alice's age: " << ages["Alice"] << std::endl;
    
    // Checking if a key exists
    if (ages.find("David") == ages.end()) {
        std::cout << "David is not in the map" << std::endl;
    }
    
    // Iterating through the map
    for (const auto& pair : ages) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }
    
    return 0;
}
```

#### Key Differences and Use Cases

- Use `set` when you need to maintain a collection of unique elements in sorted order.
- Use `unordered_set` when you need fast lookup and don't care about the order.
- Use `pair` when you need to group two values together.
- Use `tuple` when you need to group more than two values together.
- Use `map` when you need to associate keys with values and maintain sorted order.
- Use `unordered_map` when you need fast key-value lookup and don't care about the order.

Remember, `unordered_` variants generally offer faster access times (O(1) average case) but may use more memory and don't maintain any specific order. The ordered variants maintain a specific order (usually sorted) but have slower access times (O(log n)).

### Linked Lists in C++:

A linked list is a dynamic data structure where elements are stored in nodes. Each node consists of a data field and a pointer field pointing to the next node in the sequence.



#### Linked List :Destructor:

#### Linked List :Append(Add something to the end):

#### Linked List :Delete Last:

#### Linked List :Prepend(add at first):

#### Linked List :delete first:

#### Linked List :Get:

#### Linked List :set:

#### Linked List :insert:

#### Linked List :delete node:

```cpp
#include <iostream>


class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value=value;
        next=nullptr;
    }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
        
    public:    
    LinkedList(int value){  //constructor
        Node* newNode = new Node (value);
        head=newNode;
        tail=newNode;
        length=1;
    }

    void printList(){ //print list
        Node* temp = head;
        while (temp != nullptr){
            std::cout<<"->"<<temp->value;
            temp = temp->next;
        }
        std::cout<<'\n';
    }
    
    void getHead(){
        std::cout<<"Head: "<<head->value<<'\n';
    }
    
    void getTail(){
        std::cout<<"Tail: "<< tail->value<<'\n';
        
    }
    
    void getLength(){
        std::cout<<"Length: "<<length<<'\n';
    }

    ~LinkedList(){  //destructor
        Node* temp=head;
        while(head){
            head=head->next;
            delete temp;
            temp=head;
        }
    }
    void append(int value){ //add to tail
       Node* newNode= new Node(value);
       if (length == 0){
        head=newNode;
        tail=newNode;
       }else{
        tail->next= newNode;
        tail=newNode;
       }
       length ++;
    }
    
    void deleteLast(){
        if(length==0){
            return ;
        }
        if (length==1){
            head = nullptr;
            tail = nullptr;
        }else{
            Node* temp=head;
            Node* pre=head;
            while(temp->next){  //when temp points to null pointer it breaks the loop
                pre=temp;
                temp=temp->next; //
            }
            tail=pre; 
            tail->next = nullptr;
            length --;
            if (length ==0){
                head = nullptr;
                tail = nullptr;
            }
            delete temp;
        }
    }
    void prepend(int value){ //add new node at beginning (Head)
        Node* newNode = new Node(value);
        if(length==0){
            newNode=head;
            newNode=tail;
        }else{
        newNode->next=head;
        head=newNode;
        }
     length ++;   
    }
    
    void deletefirst(){
        Node* temp=head;
        if (length==0){
            return ;
        }
        if(length==1){
            head=nullptr;
            tail=nullptr;
        }else{
            head=head->next;
        }
        delete temp;
        length --;
    }
    
    Node* get(int index){
        if ( index<0 || index>=length){
            return nullptr;
        }
        Node* temp=head;
        for (int i=0;i<index;i++){
            temp=head->next;
        }
        return temp;
    }
    
    bool set(int index, int value){
        Node* temp;
        temp=get(index);
        if (temp){
            temp->value=value;                
            return true;
        }else{
            return false;
        }
    }
    
    bool insert(int index, int value){
        if(index<0 || index>length){
            return false;
        }
        if(index==0){
            prepend(value);
            return true;
        }
        if(index==length){
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* temp = get(index-1);
        newNode->next=temp->next;
        temp->next= newNode;
        length++;
        return true;
    }
    
    void deleteNode(int index){
        if(index<0 || index>=length){
            return;
        }
        if (index == 0){
            return deletefirst();
        }
        if(index == length-1){
            return deleteLast();
        }
        
        Node* prev=get(index-1);
        Node* temp= prev->next;
        prev->next=temp->next;
        delete temp;
        length --;
        
    }
    
    void reverseNode(){
        
        Node* temp= head;
        head=tail;
        tail=temp;
        
        Node* after=temp->next;
        Node* before=nullptr;
        
        
        for(int i=0;i<length;i++){
            after=temp->next;
            temp->next=before;
            before=temp;
            temp=after;
        }
    }
    
};

int main()
{
    LinkedList* mylinkedlist = new LinkedList(1);
    mylinkedlist->append(2);
    mylinkedlist->append(3);
    
    //mylinkedlist->deleteLast();
    mylinkedlist->getHead();
    mylinkedlist->getTail();
    mylinkedlist->getLength();
    mylinkedlist->printList();
    
    mylinkedlist->prepend(4);
    mylinkedlist->printList();
    
    mylinkedlist->deletefirst();
    mylinkedlist->printList();

    std::cout<<mylinkedlist->get(1)->value<<'\n';
    mylinkedlist->printList();

    mylinkedlist->set(1,4);
    mylinkedlist->printList();
    
    mylinkedlist->insert(1,6);
    mylinkedlist->printList();
    
    mylinkedlist->deleteNode(1);
    mylinkedlist->printList();
    
    mylinkedlist->reverseNode();
    mylinkedlist->printList();
    
    return 0;
}
```

#### Example Usage:
```cpp
// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;
};
```
```cpp
// Linked list class
template<typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    // Insertion methods
    void insertFront(const T& value);
    void insertEnd(const T& value);

    // Deletion methods
    void removeFront();
    void removeEnd();

    // Display method
    void display();
};
```
```cpp
template<typename T>
void LinkedList<T>::insertFront(const T& value) {
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
```
```cpp
template<typename T>
void LinkedList<T>::insertEnd(const T& value) {
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
```
```cpp
template<typename T>
void LinkedList<T>::removeFront() {
    if (head == nullptr) {
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    delete temp;
}
```
```cpp
template<typename T>
void LinkedList<T>::removeEnd() {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
```
```cpp
template<typename T>
void LinkedList<T>::display() {
    Node<T>* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
```
```cpp
template<typename T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
```

```cpp
int main() {
    // Create a linked list
    LinkedList<int> myList;

    // Insert elements
    myList.insertFront(5);
    myList.insertEnd(10);
    myList.insertEnd(15);

    // Display the list
    myList.display(); // Output: 5 10 15

    // Remove an element
    myList.removeFront();

    // Display the modified list
    myList.display(); // Output: 10 15

    return 0;
}
///////////////////////////////////////////////////////////////
```
#### Linked List EXAMPLE 2
```cpp
class Node{
    int value;
    Node* next;

    Node(int value){
        this->value=value;
        next=nullptr;
    }
};
```
```cpp
class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
        
    public:    
    LinkedList(int value){  //constructor
        Node* newNode = new Node (value);
        head=newNode;
        tail=newNode;
        length=1;
    }

    void printList(int value){ //print list
        Node* temp = head;
        while (temp != nullptr){
            std::cout<<temp->value<<'\n';
            temp = temp->next;
        }
    }

    void append(){};
    void prepend(){}; //add new node at beginning 
    bool insert(){}; //insert 
    
};
```


[Leet code practice] (https://leetcode.com/problem-list/linked-list/)


=========================================================================================================
## 3. Doubly Linked list
### DLL: Constructor

 A doubly linked list is a data structure where each node contains data and two pointers - one to the next node and one to the previous node. This allows for traversal in both directions.

```cpp
struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int x):next(nullptr),prev(nullptr),val(x){

    }
}; 

class MyDoublyLinkedList {
private:
    Node *head;
    Node *tail;
    int size;

public:
    MyLinkedList(int val) {
        Node* newNode= new Node(val);
        head=newNode;
        tail=newNode;
        size=1;
    }

.
.
.
.
```
### DLL: Append(add at end)
```cpp
   //append or add at tail
    void append(int val){
        Node* newNode=new Node(val);
        current= head;
        if(head == nullptr){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail = newNode;
        }
        size++;
    }
```

### DLL: Delete Last

```cpp
    void deleteLast(){
        if(head == nullptr){
            return;
        }else if(size == 1){
             head =nullptr;
             tail=nullptr;
        }else{
            Node* temp=tail;
            tail=temp->prev;
            tail->next=nullptr;
            delete temp;
        }
       
        size --;
    }
```

### DLL: Prepend (add at beginning)

```cpp
    void prepend(int x){
        Node* newNode=new Node(x);
        if(head == nullptr){
            head=newNode;
            tail=newNode;
        }else{
           newNode->next=head;
           head->prev=newNode;
           head=newNode;
        }
        size++;
    }
```
### DLL: Delete First (add at beginning)

```cpp
void deleteFirst(){
        if(head == nullptr){
            return;
        }else if(size == 1){
            head=nullptr;
            tail=nullptr;
        }else{
            Node* temp = head;
            head=head->next;
            head->prev=nullptr;
            delete temp;
        }
        size--;
    }
```
### DLL:get
```cpp
Node* get(int index){
        if(index<0 || index>=size){
            return nullptr;
        }
        if(index < size/2){
            Node* current=head;
            for(int i=0;i<index;i++){
                current=current->next;
            }
            return current;
        }else{
            Node* current = tail;
            for(int i=size-1;i>index;i--){
                current=current->prev;
            }
            return current;
        }
}  
```
### DLL:set
```cpp     
bool set(int index, int value){
    Node* temp= get(index);
    if (temp){
        temp->val=value;
        return true;
    }else{
        return false;
    }

}
```
### DLL:insert

```cpp
    bool insert(int index, int value){
        
        if(index<0 || index >size ){
            return false;
        }else if(index==0){
            prepend(value);
            return true;
        }else if(index == size){
            append(value);
            return true;
        }else{
            Node* newNode = new Node(value);
            Node* prevNode=get(index-1);
            Node* nextNode=prevNode->next;
         
            newNode->prev=prevNode;
            newNode->next=nextNode;
            prevNode->next=newNode;
            nextNode->prev=newNode; 
            size++;
            return true;
        }
    }

```
### DLL:Delete node

```cpp

```

-------------------------------------


## doubly linked lists
## Two Pointers
## Stacks
## Queues
## Deques (double-ended queues)

## TREES
## TREE see https://neetcode.io/courses/dsa-for-beginners/0 



# II Algorithm

## Recursion
### Factorial
### Fibonacci Sequence

## Sorting
### Insertion Sort
### Merge Sort
### quick Sort
### Bucket Sort

## search
### Search Array
### Search Range
### binary search
### Depth first search
### breadth first search

## greedy Algorithm

## Dynamic programming 



# III Advanced Algorithm


# IIII Coding Interview Patterns https://www.educative.io/module/WnDG1YSxqj4k4gzB0/10370001/5626850551529472

## Sliding Door 

The sliding window technique is a method for performing operations on arrays or strings, typically to reduce the use of nested loops and optimize the given solution. It's particularly useful for problems involving subarrays or substrings.

Here's an explanation of the sliding window basics:

1. The idea is to create a "window" that slides over the data.
2. This window can be fixed-size or variable-size, depending on the problem.
3. As the window slides, we process the elements within it.
4. We typically use two pointers: one for the start of the window and one for the end.

I've provided two examples in the code above:

1. Fixed-size window: Finding the maximum sum subarray of size k
   - We initialize the sum of the first k elements.
   - Then we slide the window by one position at a time, adding the new element and subtracting the element that's no longer in the window.
   - We keep track of the maximum sum encountered.

2. Variable-size window: Finding the longest substring with at most k distinct characters
   - We use a hash map to keep count of characters in the current window.
   - We expand the window to the right, adding characters to the map.
   - If the number of distinct characters exceeds k, we shrink the window from the left until we're back to k distinct characters.
   - We keep track of the maximum length encountered.

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Example 1: Find the maximum sum subarray of size k
int maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    // Check if the array is smaller than the window size
    if (n < k) return -1;  // Invalid case
    
    // Calculate the sum of first k elements (first window)
    int maxSum = 0;
    for (int i = 0; i < k; i++)
        maxSum += nums[i];
    
    // Slide the window and update the sum
    int windowSum = maxSum;
    for (int i = k; i < n; i++) {
        // Add the next element and remove the first element of the previous window
        windowSum = windowSum - nums[i-k] + nums[i];
        // Update maxSum if current windowSum is greater
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}

// Example 2: Find the longest substring with at most k distinct characters
int longestSubstringKDistinct(string s, int k) {
    // Use a hash map to store character frequencies
    unordered_map<char, int> charCount;
    int left = 0, maxLen = 0;
    
    // Right pointer to expand the window
    for (int right = 0; right < s.length(); right++) {
        // Add the current character to the window
        charCount[s[right]]++;
        
        // Shrink the window if we have more than k distinct characters
        while (charCount.size() > k) {
            // Decrease the count of the leftmost character
            charCount[s[left]]--;
            // If its count becomes 0, remove it from the map
            if (charCount[s[left]] == 0)
                charCount.erase(s[left]);
            // Move the left pointer to shrink the window
            left++;
        }
        
        // Update the maximum length if current window is longer
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}

int main() {
    // Test Example 1
    vector<int> nums = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    cout << "Max sum subarray of size " << k << ": " << maxSubarraySum(nums, k) << endl;
    
    // Test Example 2
    string s = "aabacbebebe";
    k = 3;
    cout << "Longest substring with at most " << k << " distinct characters: " 
         << longestSubstringKDistinct(s, k) << endl;
    
    return 0;
}

```
Key points to remember:

- The sliding window technique often reduces the time complexity from O(n^2) to O(n).
- It's particularly useful for problems involving subarrays or substrings.
- The window can be fixed-size or variable-size, depending on the problem.
- Often, you'll use additional data structures (like hash maps) to keep track of information about the elements in the window.

Common problem types where sliding window is useful:
- Maximum/minimum sum subarray of size k
- Longest/shortest substring with certain properties
- Finding anagrams or permutations in a string
- Maximum of all subarrays of size k

## The Two-Pointer Technique:
 
The two-pointer technique is an algorithm design pattern where two pointers iterate through the data structure (often an array) in a coordinated way. This technique is often used to solve problems with a time complexity of O(n) and a space complexity of O(1).

Types of Two-Pointer Approaches:
1. Opposite Directional: Two pointers start from the opposite ends and move towards each other.
2. Same Directional: Both pointers generally move in the same direction.
3. Fast and Slow Pointers: One pointer moves faster than the other.

Let's examine each example:

1. Two Sum II - Input array is sorted
   - This uses the opposite directional approach.
   - We have two pointers: `left` starts at the beginning, `right` starts at the end.
   - We sum the values at these pointers and compare with the target.
   - If the sum is too small, we move `left` to increase the sum.
   - If the sum is too large, we move `right` to decrease the sum.
   - Time Complexity: O(n), Space Complexity: O(1)

2. Remove Duplicates from Sorted Array
   - This uses the same directional approach.
   - We have two pointers: `writePointer` and `readPointer`.
   - `readPointer` scans through the array.
   - `writePointer` keeps track of where to write the next unique element.
   - We only move unique elements to the position of `writePointer`.
   - Time Complexity: O(n), Space Complexity: O(1)

3. Reverse String
   - This uses the opposite directional approach.
   - We have two pointers: `left` starts at the beginning, `right` starts at the end.
   - We swap the characters at these pointers and move them towards each other.
   - We stop when the pointers meet in the middle.
   - Time Complexity: O(n), Space Complexity: O(1)


```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Example 1: Two Sum II - Input array is sorted
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1}; // 1-indexed
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {}; // No solution found
}

// Example 2: Remove Duplicates from Sorted Array
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int writePointer = 1;
    for (int readPointer = 1; readPointer < nums.size(); readPointer++) {
        if (nums[readPointer] != nums[writePointer - 1]) {
            nums[writePointer] = nums[readPointer];
            writePointer++;
        }
    }
    
    return writePointer;
}

// Example 3: Reverse String
void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    // Test Example 1
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    cout << "Two Sum II Result: [" << result[0] << ", " << result[1] << "]" << endl;

    // Test Example 2
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int newLength = removeDuplicates(nums);
    cout << "Remove Duplicates Result: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // Test Example 3
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    cout << "Reverse String Result: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}

```
Key Points to Remember:
1. Two-pointer technique often helps reduce time complexity from O(n^2) to O(n).
2. It's particularly useful for problems involving arrays or linked lists.
3. The technique can help solve problems with constant space complexity.
4. Common problem types include searching pairs, reversing, or removing elements.

Practice Problems:
1. Container With Most Water (LeetCode 11)
2. 3Sum (LeetCode 15)
3. Move Zeroes (LeetCode 283)
4. Palindrome Linked List (LeetCode 234)

