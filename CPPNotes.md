# Basics of C++
## 1. Variables and Data types
### Integer
- Signed  5 ,-5
- Unsigned  23u or 23U
- Octa 023
- Hex  0X3A
- Binary  0b1100
### Floating point	
- Float   23.0f,0.00f  
### Double
-  
#### Long double
- 
### long
- Never less than 4 bytes.
### long long
   - usually 8 bytes
### Char(8 bit integer or 1 byte ) 
- usually 1 byte, may be signed or unsigned if unqualified.  You can always formally declare a char as signed or unsigned if you need to be sure.
- 'a', 'x', 
- '\n'(new line character)
- '\0' (null)
### Short
	- usually 2 bytes
### Boolean
- bool x ;
- True 1
- False 0

**size_type or size_t**

### Notes 
#### How big are all these data types? 
 - Use sizeof operator sizeof(int) will return the number of bytes in an int. Or check <limits> file for max/min size of various data types.

char <= short <= int <= long <= long long

- You may have come across code where integer types are expressed as int16_t or uint32_t.
- Use #include <cstdint>.  There you will find std::uint32_t, std::int16_t etc.  But declared within the std:: namespace.
-  **std::uint32_t should be preferred over uint32_t.**

##### Topics
	-Serializing data.
	-Packing data tightly and predictably.
	-Performing bit operations.

----------------------------------------------------------------------
## 2. Compound Data Types
### 2.1 Array
	-  Indexed from 0 to n-1 , n is #of elements 
	- Implicit conversions 
	- store multiple values in a single variable
> string cars[4]; 
> string cars[4] = {"Toyota", "BMW", "Ford", "Mazda"};  
> string cars[] = {"Toyota", "BMW", "Ford", "Mazda"};  

- cars[0] is toyota ,....cars[3] is mazda
- Accessing array
> int a = cars[0]
-2d array
> string cars [2] [3] = {{1,2,3},{4,5,6}}

### 2.2 Constants 
- don’t change while execution 
	1. With preprocessor or macros
	#define  ROOMS 4
	
	2. Declarations 
	const x =8;
### 2.3 String
- Supported as a class
-  Not native in C++
-  Arrays of character (better using string than char). string is actually a
   one-dimensional array of characters which is terminated by a null character '\0
-  The standard C++ library provides a string class type. #include<string>

```cpp
#include <iostream>
using namespace std;

int main () {
   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};   //using character
   cout << "Greeting message: ";
   cout << greeting << endl;
   return 0;
}
```

```cpp
#include <iostream>
#include <string>   //using array

using namespace std;

int main () {

   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;

   // copy str1 into str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;

   // concatenates str1 and str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;

   // total length of str3 after concatenation
   len = str3.size();
   cout << "str3.size() :  " << len << endl;

   return 0;
}

```
-----------------------------------------------------------------------------------------------------------------------

### 2.4 References and Pointers
-we can get the memory address of a variable by using the & operator
 
-**variables** that store the memory addresses of other variables. 
- Special data type for memory address
- Same pointer maybe used to access many different variables.
- why? if you want to access data outside of a function. 
- pointers are variables so they can change
```cpp
#include <iostream>
#include <string>

int main()
{
    std::string car = "Toyota"; // A car variable of type string
    std::cout << car << std::endl; // Outputs the value of food (Toyota)  //> Toyota
    std::cout << &car; // Outputs the memory address of food (0x7fff996e11f0) //> 0x7fff996e11f0
 
    int num{10};
    std::cout<<num<<std::endl; // 10
    std::cout<<sizeof(num)<<std::endl; //4 bytes are allocated
    std::cout<<&num<<std::endl;//0x7fff9ff31f14

    int *p= nullptr;
    p=&num;	
    std::cout<<"P: " <<p<<std::endl; //0 or garbage if not assigned nullptr
    std::cout<<"sizeof(p): "<<sizeof(p)<<std::endl;  //8 byte
    std::cout<<"&p: "<<&p<<std::endl;  //&p: 0x7ffe1a95d050
   // std::cout<<"*p: "<<*p<<std::endl; //null

    // size of a pointer usually 4 or 8 byte(machine specific) (**it is really diffrent from size of what it points to**)
     int *p1 {nullptr};
     double *p2 {nullptr};
     float *p3 {nullptr};
     long long *p4 {nullptr};
     std::vector<std::string> *p5 {nullptr};
    std::cout<<"sizeof(p1): "<<sizeof(p1)<<std::endl;  //sizeof(p1): 8
    std::cout<<"sizeof(p2): "<<sizeof(p)<<std::endl;  //sizeof(p2): 8
    std::cout<<"sizeof(p3): "<<sizeof(p)<<std::endl;  //sizeof(p3): 8
    std::cout<<"sizeof(p4): "<<sizeof(p)<<std::endl;  //sizeof(p4): 8
    std::cout<<"sizeof(p5): "<<sizeof(p)<<std::endl;  //sizeof(p5): 8

    int num{10};
    std::cout<<num<<std::endl; // 10
    std::cout<<sizeof(num)<<std::endl; //4 bytes are allocated
    std::cout<<&num<<std::endl;//0x7fff366cf7bc
    int *p= nullptr;
    p=&num;	
    //or // int *p=&num; 
    std::cout<<"P: " <<p<<std::endl; //0x7fff366cf7bc
    std::cout<<"sizeof(p): "<<sizeof(p)<<std::endl;  //8 byte
    std::cout<<"&p: "<<&p<<std::endl;  //&p: 0x7fff366cf7c0
   // std::cout<<"*p: "<<*p<<std::endl; //null
    std::cout<<"&num " <<&num<<std::endl;//0x7fff366cf7c0

    return 0;
}

```
Example 
```cpp
#include <iostream>

void changeValue(int &ref){
    ref = 20;
}

int main()
{
    int a=5;
    std::cout<<"Variable a : "<<a<<std::endl;  //5
    std::cout<<"Address of Variable : "<<&a<<std::endl; //0x7fff2c19510c
  
    int *ptr=&a;
    std::cout<<"*ptr : "<<*ptr<<std::endl;  //5     *ptr equals variable a
    std::cout<<"ptr : "<<ptr<<std::endl;  //0x7fff2c19510c  same as &a equals ptr
    
    int &ref=a;      // & Sign indicates that is a reference,not an address.
    std::cout<<"&ref : "<<&ref<<std::endl;  //0x7fff2c19510c
    
    ref++;
    std::cout<<"new a : "<<a<<std::endl;  // 6

    changeValue(a);    //call by reference 
    std::cout<<"changeValue a : "<<a<<std::endl;  // 20
}
```
#### 2.4.1 dereferencing a pointer (access the data were pointing to)
std::cout<<*ptr<<std::endl;

``` cpp
    int score{10};
    int *score_ptr{&score};
    std::cout<<"score: "<<score<<std::endl; //10
    std::cout<<"&score: "<<&score<<std::endl; //&score: 0x7ffd91be966c
    std::cout<<"*score_ptr: "<<*score_ptr<<std::endl; //*score_ptr: 10
    std::cout<<"score_ptr: "<<score_ptr<<std::endl; //score_ptr: 0x7ffd91be966c
    *score_ptr=200;
    std::cout<<"score: "<<score<<std::endl; //score: 200
    std::cout<<"&score: "<<&score<<std::endl; //&score: 0x7ffd91be966c
    std::cout<<"*score_ptr: "<<*score_ptr<<std::endl; //*score_ptr: 200
    std::cout<<"score_ptr: "<<score_ptr<<std::endl; //score_ptr: 0x7ffd91be966c

    int low_temp{60};
    int high_temp{100};
    int *tmp_ptr=&high_temp;
    std::cout<<"low_temp: "<<low_temp<<std::endl; //low_temp: 60
    std::cout<<"high_temp: "<<high_temp<<std::endl; //high_temp: 100
    std::cout<<"&high_temp: "<<&high_temp<<std::endl; //high_temp: 100
    std::cout<<"*tmp_ptr: "<<*tmp_ptr<<std::endl; //*tmp_ptr: 100
    *tmp_ptr=low_temp;
    std::cout<<"*tmp_ptr: "<<*tmp_ptr<<std::endl; //*tmp_ptr: 60

    std::vector<std::string> *vector_ptr = &names;
    std::cout<<(*vector_ptr).at(0)<<std::endl; //Bob
    std::cout<<(*vector_ptr).at(2)<<std::endl;  //Smith

    for(auto names:*vector_ptr)
    {
        std::cout<<"name: "<<names<<std::endl;
    }
    //name: Bob
    //name: John
    //name: Smith

```
#### 2.4.2 Dynamic Memory Allocation 
-Dynamic Programming and Heap

**Stack vs heap**

In C++, memory allocation can be broadly categorized into two areas: the stack and the heap. These two areas have different characteristics and are used for different purposes. Here's an overview of the stack and heap in C++:

**Stack**:

The stack is a region of memory that is managed by the compiler and is typically of fixed size.
It is used for storing local variables, function call information (such as return addresses and parameters), and for managing function call execution (stack frames).
Memory allocation and deallocation on the stack are fast and deterministic since it involves simple pointer manipulations.
The lifetime of variables on the stack is limited to the scope of the block or function they are declared in. They are automatically destroyed when they go out of scope.
The stack is suitable for managing relatively small, short-lived objects.
Example:

``` cpp
void foo() {
    int x = 10; // 'x' is allocated on the stack
}
```
**Heap**:

The heap is a region of memory that is managed by the programmer, and it is typically larger and more flexible than the stack.
It is used for dynamic memory allocation, where memory is allocated and deallocated manually during program execution.
Memory allocation on the heap involves functions like new and malloc, and deallocation requires manual calls to delete and free.
The lifetime of objects on the heap is not tied to a specific scope, and they must be explicitly deallocated to prevent memory leaks.
The heap is suitable for managing objects with a longer and potentially unpredictable lifetime, such as objects that need to persist beyond the function or block where they were created.
Example:

``` cpp

int* p = new int; // Allocate memory on the heap for an integer
*p = 42;
delete p; // Deallocate the memory when done
```
It's important to note that improper use of the heap, such as failing to deallocate memory when it's no longer needed, can lead to memory leaks and inefficient memory usage. Modern C++ provides smart pointers (e.g., std::shared_ptr and std::unique_ptr) to help manage dynamic memory more safely and reduce the risk of memory leaks.

In summary, the choice between the stack and the heap depends on the specific requirements of your program. Use the stack for small, short-lived variables and the heap for dynamic memory allocation when the lifetime and size of objects are less predictable. Always be mindful of memory management to avoid resource leaks and excessive memory consumption.


|Feature   |    Stack  | Heap  | 
|---       |---        |---    |
| Location  |  Part of the call stack      | Unallocated memory area      | 
| Allocation  | Automatic  | Manual      | 
| Deallocation  | Automatic  |  Manual     |  
| Access speed  | Faster  |  Slower     |  
| Size          |  Limited |  Unlimited     | 
| Fragmentation  | Less likely  | More likely   | 



| Heap (Dynamic Memory) |
|---    |
|Stack   |
| static/global  |
| code  |


**Dynamic Memory Allocation**
- Dynamic memory allocation is a process in computer programming that allows you to allocate and manage memory for objects or data structures at **runtime**, rather than at compile time. This provides flexibility in handling memory, allowing you to create data structures whose size is not known until the program is running. Dynamic memory allocation is especially important when dealing with data structures like arrays, linked lists, trees, and other containers whose size can vary during program execution.

- In C++ and other programming languages, dynamic memory allocation is typically achieved using functions or operators like new and delete (in C++), malloc and free (in C), or similar constructs in other languages. Here's a brief explanation of how dynamic memory allocation works in C++:

Allocation: You use the new operator (in C++) or the malloc function (in C) to request a specific amount of memory from the system's heap, which is a region of memory separate from the stack. For example, in C++, you can allocate memory for an integer as follows:

``` cpp
int* p = new int; // Allocate memory for an integer
```

Initialization: Once the memory is allocated, you can initialize the allocated memory as needed. In the above example, p points to a dynamically allocated integer, but it doesn't have a defined value until you assign one.

``` cpp
*p = 42; // Store the value 42 in the dynamically allocated memory
```
Deallocation: When you're done using the dynamically allocated memory, you should release it to avoid memory leaks. In C++, you use the delete operator:

```cpp
Copy code
delete p; // Deallocate the dynamically allocated memory
```
In C, you use the free function:

``` c
free(p); // Deallocate the dynamically allocated memory
```
Failure to deallocate memory can result in memory leaks, where memory is allocated but never released, leading to a gradual consumption of available memory.

Dynamic memory allocation is essential when you need to create data structures whose size is not known at compile time, or when you want to manage memory explicitly. However, it also comes with responsibilities, such as ensuring proper deallocation and handling of exceptions that can occur if memory allocation fails (e.g., due to insufficient memory). In modern C++, smart pointers like std::shared_ptr and std::unique_ptr provide safer and more automated memory management, reducing the need for manual new and delete operations.

``` cpp
#include <iostream>
int main()
{
    
    int *int_ptr {nullptr};
    //using new to allocate storage
    int_ptr=new int; //allocate an intiger on the heap
    
    std::cout<<int_ptr<<std::endl; //0x556850761eb0
    std::cout<<*int_ptr<<std::endl;//0

    *int_ptr=100;
    std::cout<<int_ptr<<std::endl; //0x556850761eb0
    std::cout<<*int_ptr<<std::endl; //100
    
    delete int_ptr; //frees the allocated storage
    
    return 0;
}
```
``` cpp
#include <iostream>
#include <memory>

 void* operator new(size_t size)
    {
       std::cout<<"Allocating size: "<<size<<" bytes\n";
       return malloc(size);
    }

void operator delete(void* memory, size_t size)
{
    std::cout<<"Freeing "<<size<<" Bytes\n";
    free(memory);
}
int main()
{   
    int *array_ptr{nullptr};
    size_t size {};
    
    std::cout<<"How big do you want the array? ";
    std::cin>>size;
    
    array_ptr = new int[size]; //allocate array on the heap
    
    delete array_ptr;
    
    return 0;
} 
```
``` cpp
#include <iostream>
#include <memory>

struct AllocationMetrics
{
    uint32_t TotalAllocated =0;
    uint32_t TotalFreed=0;
    
    uint32_t CurrentUsage(){
        return TotalAllocated-TotalFreed; 
    }
};

static AllocationMetrics s_AllocationMetrics;

 void* operator new(size_t size)
    {
       s_AllocationMetrics.TotalAllocated += size;    
       return malloc(size);
    }

void operator delete(void* memory, size_t size)
{
    s_AllocationMetrics.TotalFreed += size;
    free(memory);
}

static void PrintMemoryUsage()
{
           std::cout<<"Memory Usage: "<<s_AllocationMetrics.CurrentUsage()<<" bytes\n";
}

int main()
{  
    PrintMemoryUsage();  
    int *array_ptr{nullptr};
    size_t size {}; 
    std::cout<<"How big do you want the array? ";
    std::cin>>size;
    PrintMemoryUsage();
    {
    array_ptr = new int[size]; //allocate array on the heap
    PrintMemoryUsage();
    }
    delete [] array_ptr;
    PrintMemoryUsage();

    return 0;
}

```
std::bad_alloc is a type of exception that occurs when the new operator fails to allocate the requested space. This type of exception is thrown  by the standard definitions of ​operator new (declaring a variable) and operator new[] (declaring an array) when they fail to allocate the  requested storage space.
see Exception handling
see memory leak 
``` cpp
//below shows 
  int *array_ptr{nullptr};
    size_t size {9999999};
    
    //std::cout<<"How big do you want the array? ";
    //std::cin>>size;
    
    
    while (true){
    array_ptr = new int[size]; //allocate array on the heap
    }
    delete array_ptr;
```
#### 2.4.3 The Relationship between arrays and pointers
- The value of an array name is the address of the first element in the array
- the value of a pointer variable is an address
- if the pointer points to the same data type as the array element then the pointer and array name can be used interchangbly(almost)
``` cpp
#include <iostream>
int main()
{
    int scores[] {100,95,89};
    
    std::cout<<scores[0]<<std::endl; //100
    std::cout<<scores[1]<<std::endl; //95
    std::cout<<scores[2]<<std::endl;  //89
   
    std::cout<<scores<<std::endl;  //0x7ffcdf7e608c  //the value of a pointer variable is an address
    std::cout<<*scores<<std::endl;  //100 //The value of an array name is the address of the first element in the array
    std::cout<<*(scores+1)<<std::endl;  //95
    std::cout<<*(scores+2)<<std::endl;  //89  

    int *score_ptr {scores};
    std::cout<<*score_ptr<<std::endl;  //100 
    std::cout<<*(score_ptr+1)<<std::endl;  //95 
    std::cout<<*(score_ptr+2)<<std::endl;  //89 
    
    std::cout<<score_ptr<<std::endl;  //0x7ffcdf7e608c 
    std::cout<<(score_ptr+1)<<std::endl;  //0x7ffcdf7e6090 //increased by 4 byte
    std::cout<<(score_ptr+2)<<std::endl;  //0x7ffcdf7e6094 //increment by 4 byte
    
    std::cout<<score_ptr[0]<<std::endl; //100
    std::cout<<score_ptr[1]<<std::endl; //95
    std::cout<<score_ptr[2]<<std::endl;  //89
    
    return 0;
}
```
#### 2.4.4 pointer Arithmetric
- pointers can be used in:
  	- Assignment expression
  	- arithmetric expressions
  		-four arithmetic operators that can be used on pointers: ++, --, +, and -
  	- comparision expressions
- pointer arithmetric only makes sense with raw arrays
	-ptr++ increments to the next array and ptr-- decrements to previous
- increment pointer + and -
	- (+) increment by n*sizeof(type) Eg: ptr+=n; or ptr=ptr+n;
   	- (-) decrement pointer by n*sizeof(type) Eg:ptr-=n; or ptr=ptr-n;
 ``` cpp
#include <iostream>
int main()
{
    int score[]={500,400,300,200,100};
    int *score_ptr={score};  //score_ptr points to score[0], first array
    while (*score_ptr != 100 )
    {
      //std::cout<<*score_ptr<<std::endl;
      //score_ptr ++;
      //or
      std::cout<<*score_ptr++<<std::endl;
	//or
	//       std::cout<<*(score_ptr++)<<std::endl;
    }
    return 0;
}
	500
	400
	300
	200
```
-both pointers must point the same data types
-comparing two pointers == and !=
	-if two pointers point to the same location does not compare the data where they point.
``` cpp
#include <iostream>
#include <string>

int main()
{
    std::string s1{"Frank"};
    std::string s2{"Frank"};
    
    std::string *p1 {&s1};
    std::string *p3 {&s1};
    
    std::string *p2 {&s2};
    
    std::cout<<std::boolalpha<<(p1==p3)<<std::endl; //true
    std::cout<<std::boolalpha<<(p1 == p2)<<std::endl; //false pointer comparision dont compare data.
    
    //to compare data deref. it
    std::cout<<std::boolalpha<<(*p1==*p3)<<std::endl; //true
    std::cout<<std::boolalpha<<(*p1 == *p2)<<std::endl; //true 
    //---------------------------------------------------------------
    char name[]{"Don"};
    char *char_ptr1{name};
    char *char_ptr2{name};
    std::cout<<*char_ptr1<<std::endl; //D
    std::cout<<*char_ptr2<<std::endl; //D
    
    char *char_ptr3{name};
    std::cout<<char_ptr3<<std::endl; //Don ????
    
    char *char_ptr4=&name[0];
    char *char_ptr5=&name[2];
    char *char_ptr6=&name[3];
    char *char_ptr7=&name[4];
    std::cout<<*char_ptr4<<std::endl; //D
    std::cout<<*char_ptr5<<std::endl; //n
    std::cout<<*char_ptr6<<std::endl; //null
    std::cout<<*char_ptr7<<std::endl; //null

    return 0;
}
```
Example: Swap Pointers
```cpp
#include <iostream>
#include <string>

void swap_pointers(int* ptr1, int* ptr2) {
    //-- Write your code below this line
    //  int tmp = *ptr1;
    // *ptr1=*ptr2;
    // *ptr2= tmp;
    //or
    *ptr1=*ptr1+*ptr2;
    *ptr2=*ptr1-*ptr2;
    *ptr1=*ptr1-*ptr2;
    std::cout<<"inside fun call "<<*ptr1<<" ";
    std::cout<<*ptr2<<std::endl; 
    //-- Write your code above this line
}

int main()
{
    int a {5};
    int b {10};
 
    int* ptrA = &a;
    int* ptrB = &b;
    
    std::cout<<"before "<<*ptrA<<" ";
    std::cout<<*ptrB<<std::endl;
 
    swap_pointers(ptrA, ptrB);
    
    std::cout<<"after fun call "<<*ptrA<<" ";
    std::cout<<*ptrB<<std::endl;

    return 0;    
}  
```
	before 5 10
	inside fun call 10 5
	after fun call 10 5
#### 2.4.4 const and pointers
several ways to qualify pointers using const
- pointers to constants  **const int *high_ptr{&high_score};**
 	- the data pointed to by the pointer is constant and can not change
    	- but can point to diffrent address
```cpp
    int high_score {100};
    int low_score {50};
    const int *high_ptr{&high_score};  //the data pointed to by the pointer 
    //is constant and can not change
    std::cout<<high_ptr<<std::endl;     //0x7ffd0d9a8208
    std::cout<<&high_score<<std::endl; //0x7ffd0d9a8208
    //*high_ptr=60;  //error: assignment of read-only location ‘* high_ptr’ //can not change
    //but can point to diffrent address
    high_ptr = &low_score;
    std::cout<<high_ptr<<std::endl; //0x7ffd0d9a820c
    std::cout<<&low_score<<std::endl; //0x7ffd0d9a820c
```
- constant pointers
  	- very useful to **pass pointer to function**
	- the data //the data can be changed
  	- the pointer itself can not change and point somewhere else
```cpp
     ////////constant pointers/////////////////
    int high_score {100};
    int low_score {50};
    int *const score_ptr {&high_score}; 
    //the data can be changed
    //the pointer itself can not change and point somewhere else
    *score_ptr =60;
    //score_ptr = &low_score;  //error: assignment of read-only variable ‘score_ptr’
```   
- constant pointers to constants
 	- the data pointed by the pointer can not change
    	- the pointer itself cannot change and point to somewhere else
```cpp
    //Constant pointer to constants 
    int high_score {100};
    int low_score {50};
    const int *const score_ptr {&high_score}; 
    
    *score_ptr =60; //error: assignment of read-only location ‘*(const int*)score_ptr’
    score_ptr = &low_score;  //error: assignment of read-only variable ‘score_ptr’
```

#### 2.4.5 passng pointer to a function

- adress of a variable or pointer variable

```cpp
//-----------pass by ref. with pointers---------------------
#include <iostream>
void double_data(int *int_ptr)
{
  *int_ptr *=2;  
}

int main()
{
    int value=10;
    int *int_ptr=nullptr;
    
    std::cout<<value<<std::endl; //10
    std::cout<<&value<<std::endl;  //0x7ffe00c0b5cc
   
    double_data(&value);
    
    std::cout<<value<<std::endl; //20
    std::cout<<&value<<std::endl;  //0x7ffe00c0b5cc
    
    //------------------------------------------------------------
    int_ptr=&value;
    std::cout<<value<<std::endl; //20
    std::cout<<&value<<std::endl;   //0x7ffe00c0b5cc
    std::cout<<int_ptr<<std::endl;  //0x7ffe00c0b5cc

    double_data(int_ptr);
    std::cout<<value<<std::endl; //40
    std::cout<<&value<<std::endl;   //0x7ffe00c0b5cc
    std::cout<<int_ptr<<std::endl;  //0x7ffe00c0b5cc
    
    return 0;
}

```
Example: Swap Pointers with ref. 

``` cpp
///```cpp
#include <iostream>
#include <string>

void swap_pointers(int* ptr1, int* ptr2) {
    //-- Write your code below this line
     int tmp = *ptr1;
    *ptr1=*ptr2;
    *ptr2= tmp;
    //or
    // *ptr1=*ptr1+*ptr2;
    // *ptr2=*ptr1-*ptr2;
    // *ptr1=*ptr1-*ptr2;
    std::cout<<"inside fun call "<<*ptr1<<" ";
    std::cout<<*ptr2<<std::endl; 
    //-- Write your code above this line
}

int main()
{
    int a {5};
    int b {10};
 
    // int* ptrA = &a;
    // int* ptrB = &b;
    
    std::cout<<"before "<<a<<" ";
    std::cout<<b<<std::endl;
 
    swap_pointers(&a, &b);
    
    std::cout<<"after fun call "<<a<<" ";
    std::cout<<b<<std::endl;

    return 0;    
}  
```
#### 2.4.5 returning a pointer to a function
- should return pointers to 
    - memory dynamically allocated in the function
    - to data that was passed in
- Never return a pointer to a local function variable!!!

```cpp
int *dont_do_this(){
    int size{};
    ...
    return &size;
}

int or_this(){
    int size{};
    int *int_ptr{&size};
    ...
    return int_ptr;
}

```

```cpp
#include <iostream>

int *largest_int(int *int_ptr1,int *int_ptr2){
    if(*int_ptr1 > *int_ptr2)
    {
        return int_ptr1;
    }else{
        return int_ptr2;
    }
}
int main()
{
    int a{10};
    int b{100};
    int *large_int{nullptr};
    
    large_int=largest_int(&a,&b);
    std::cout<<*large_int<<std::endl;
    
    return 0;
}
```
- returning dynamically allocated memory
```cpp
#include <iostream>

int *create_array(size_t size, int value =0)
{
    int *new_storage{nullptr};
    new_storage = new int[size]; //dynamically allocate memory
    for (size_t i=0;i<size;++i)
    {
        *(new_storage+i)=value;
    }
    return new_storage;
}


int main()
{
    int *arraycreated={nullptr};
    int size{5};
    int val{100};
    
    arraycreated=create_array(size,val);
    
    for(int i=0;i<size;i++)
    {
       std::cout<<&arraycreated[i]<<std::endl; 
       std::cout<<arraycreated[i]<<std::endl;
    }
    
    delete [] arraycreated; //remember to delete after use
    
    return 0;
}

// 0x56391096aeb0
// 100
// 0x56391096aeb4
// 100
// 0x56391096aeb8
// 100
// 0x56391096aebc
// 100
// 0x56391096aec0
// 100
```


#### Smart Pointers
-C++ provides absolute flexiblity with memory mnanagement 
	-Allocation
 	-Deallocation
  	-Lifetime management 
- the issues with raw pointers
  	- unintalized (wild) pointers
  	- Memory leaks
  	- Dangling pointers
  	   	-> one pointer points to a location thinks its valid but its been deallocated.  
  	- not exception safe
  - Ownership
	- who owns the pointer?
	- when should a pointer be deleted?
- #include<memory>
- wrapper around raw pointers
- Overloaded operators
  	- Dereferance (*)
  	- Member selection (->)
  	- pointer arithmetric not supported(++,--,etc.)
```cpp
{
	std::smart_ptr<some_class> ptr_name = .....
	ptr_name -> method();
	cout<<(*ptr_name)<<endl;
}
// ptr will be destroyed automatically when no longer needed. 
```
**RAII** - Resource Acquisition is initalization
	-RAII objects are allocated on a stack
 	- the idea of grabbing resources on the constractor and release resources in the destractor
 Resource Acquisition
 	- open a file
  	- Allocate memory
   	- Acquire a lock
-  Initialization 
	- The resource is acquired in a constructor 
- Resource relinquishing
  	-happens in the destractor
		- close the file
   		- Deallocate the memory
   		- Release the lock
##### A. Unique pointer 
- is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.
- The object is disposed of, using the associated deleter when either of the following happens:
	- the managing unique_ptr object is destroyed
	- the managing unique_ptr object is assigned another pointer via operator= or reset().
- points to an object of type T on the heap. 
- its unique- there can only be one unique_ptr<T> pointing to object on the heap
- owns what it points to
- can not be assigned or copies
- can be moved
- when the pointer is destroyed, what it points to is automatically destroyed.
``` cpp
#include <iostream>
#include <memory>
int main()
{
    std::unique_ptr<int> p1{new int {100}};
    std::cout<<*p1<<std::endl; //100
    *p1=200;
    std::cout<<*p1<<std::endl;//200
    std::cout<<p1.get()<<std::endl;//0x55e4e6d73eb0
    std::cout<<*p1.get()<<std::endl;//200
    p1.reset(); //memory is released. so p1 unique ptr wont work. released
    std::cout<<*p1.get()<<std::endl;//0 or null
    std::cout<<*p1<<std::endl;//0 or null
    *p1=300; //won't execute
    std::cout<<*p1.get()<<std::endl;// won't execute
    std::cout<<*p1<<std::endl;//won't execute
    return 0;
} //p1 is out of scope , its automatically deleted
```
``` cpp
//not working
#include <iostream>
#include <memory>
#include <string>
class Account
{
    public:
    Account(std::string name)
    {
      this -> name = name; 
    }
    
    int deposit()
    {
       return 0; 
    }
    int withdraw()
    {
      return 0;  
    }
    ~Account();
    private:
    std::string name;
};

int main()
{
    std::unique_ptr<Account> p1 {new Account{"Larry"}};
    std::cout<<*p1<<std::endl;
    return 0;
}

```
``` cpp
// not working
#include <iostream>
#include <memory>
#include <string>
#include <vector>

int main()
{
        //std::unique_ptr<int> p1{new int {100}};

    std::vector<std::unique_ptr<int>> vec;
    //std::unique_ptr<int> ptr{new int {100}};
    std::cout<<vec.at(0)<<std::endl;
    return 0;
}

``` 
##### B. shared_ptr 


##### c. weak_ptr 
4. auto_ptr - has been Deprecated and we wont use it. 


#### POINTERS REVISION
Pointers: https://www.tutorialspoint.com/cplusplus/cpp_pointers.htm 
    Sr.No 	Concept & Description
1 	Null Pointers
- C++ supports null pointer, which is a constant with a value of zero defined in several standard libraries.
2 	Pointer Arithmetic
- There are four arithmetic operators that can be used on pointers: ++, --, +, -
3 	Pointers vs Arrays
- There is a close relationship between pointers and arrays.
4 	Array of Pointers
- You can define arrays to hold a number of pointers.
5 	Pointer to Pointer
- C++ allows you to have pointer on a pointer and so on.
6 	Passing Pointers to Functions
- Passing an argument by reference or by address both enable the passed argument to be changed in the calling function by the called function.
7 	Return Pointer from Functions
- C++ allows a function to return a pointer to local variable, static variable and dynamically allocated memory as well.
-----------------------------------------------------------------------------------------------
## 3 Object Oriented programming

Introduction to OPPs in C++
Object-oriented programming (OOP) is a programming paradigm based on the concept of "objects", which can contain **data** and **code**: data in the form of fields (often known as attributes or properties), and code, in the form of procedures (often known as methods).¹ C++ is an object-oriented programming language that allows you to create classes that encapsulate data and functions. Classes are user-defined types that can be used to create objects. 

### 3.3 Classes and obj
#### 3.3.1 Declaring a class and creating object
- may contain** data member **and **member functions**
  	- Example car.make, car.paint()
- contain Public Constructor, data, and methods ???
- data member (recommended to be Private) and member functions
- Separate declarations and definitions in the h and cpp file respectively
- Instance of class is called object eg. Cout,cin 
		○ Example : make, model, year…..
- Members maybe **public** or **private** or **protected** 
- by default class members are private
- Two types of data access
	- **setters**:write into data members
	- **getters**:return the values
-.h header file: contain class definations and function declarations
-.cpp implementation file: contain executable code,must contain header file.
The #ifndef and #define statements are used to prevent the header file from being included multiple times in the same program.

**class** = is a blueprint for an object, which defines its data members and member functions. User defined types. 
- has attributes **data**
- has methods **function**
- Example: Account, Employee, Car, std::vector, std::string.
  
**Object** = an instance of a class that contains **data** and **functions**. aka grouped data
Example: 
- int **highscore**
- Account **sam_account**
- Account **Smith_account**
- std::vector<int> **scores**;
- std::string **name**;

**Methods** = the procedures that an object performs 
**Encapsulation** = object contain data and operations that work on that data, abstract data type(ADT)
**Inheritance** = can create a new classes in term of existing classes
In C++, OOP provides several advantages over procedural programming such as faster and easier execution, clear structure for programs, helps keep the code DRY (Don't Repeat Yourself), makes the code easier to maintain, modify and debug, and makes it possible to create full reusable applications with less code and shorter development time.

What is an **instance**? In object-oriented programming (OOP), an instance is a specific realization of any object. An object may be different in several ways, and each realized variation of that object is an instance. The creation of a realized instance is called **instantiation**.????
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class Player
{
public:
    //methods
    void talk(std::string name,int health, int xp);
    bool is_playing();

private:
    // attributes
    std::string name;
    int health;
    int xp;

};


int main()
{
    Player sam;
    Player smith;
    
    Player *enemy1 = new Player(); //creating pointer dynamically allocate on the heap.
    std::cout<<enemy1<<'\n';
    delete enemy1;  //free 0x55555556aeb0
    
    Player players[] {sam, smith}; //array of objects
    
    Player sam1;
    Player smith1;
    std::vector<Player> player_vec{sam1};
    std::cout<<typeid(player_vec).name() <<'\n'; //St6vectorI6PlayerSaIS0_EE
    std::cout<<typeid(sam).name() <<'\n';  //6Player
    player_vec.push_back(smith1);
    
    return 0;
}

```

``` cpp
#include <iostream>
class Rectangle 
{
    public:    
	 Rectangle(){}
	 Rectangle(double width, double length)
	 {
	     this -> width = width;
	     this -> length = length;
	 }
 	 double setwidth(double width)
 	 {
	     return (this -> width = width);
 	 }
 	 double getwidth()
 	 {
 	   return width;
 	 }
  	 double setlength(double length){
	     return (this -> length = length);
  	 }
  	 double getlength( )
 	 {
 	   return length;
 	 }
  	 double area()
  	 {
  	    return getwidth()*getlength( );
  	 }
 	~Rectangle(){};
 	private:
 	    double width;
 	    double length;
};
int main()
{
    Rectangle *obja;  //obja is a pointer that holds the address of Rectangle object
   	obja= new Rectangle(); //instantiation
    obja ->setlength(4);
    obja -> setwidth(2);
    std::cout<<"from Rectangle ptr: "<<obja -> area()<<std::endl;

    Rectangle objb;
    objb.setlength(4);
    objb.setwidth(2);
    std::cout<<"from Rectangle obj: "<<objb.area()<<std::endl;
    return 0;
}
```
```cpp   
//car.h
#include<string>

#ifndef CAR_H
#define CAR_H

class Car
{
    public:
        int get_year();
        void set_year(int caryear);
            
        std::string get_name();
        void set_name(std::string carname);

        std::string get_model();
        void set_model(std::string carmodel);      
    private:
        int year;
        std::string name;
        std::string model;
};
#endif

```
```cpp
//car.cpp
#include"car.h"

int year;
std::string name;
std::string model;

int Car::get_year(){
    return year;
}
void Car::set_year(int caryear)
{
    year=caryear;
}


std::string Car::get_name()
{
    return name;
}
void Car::set_name(std::string carname)
{
    name=carname;
}


std::string Car::get_model()
{
    return model;
}
void Car::set_model(std::string carmodel)
{
    model=carmodel; 
}
```
``` cpp
//main.cpp

#include <iostream>
#include <memory>
#include "car.h"

int main()
{
    std::cout<<"Testing Hello world!"<<std::endl;

    Car mycar1;
    mycar1.set_year(2005);
    mycar1.set_name("Toyota");
    mycar1.set_model("sienna");
    std::cout<<"my car1 is: "<<mycar1.get_year()<<" "<<mycar1.get_name()<<" "<<mycar1.get_model()<<std::endl;

    Car *mycar2= new Car;
    mycar2 ->set_year(2023); 
    mycar2 ->set_name("Toyota"); 
    mycar2 ->set_model("Camery"); 
    std::cout<<"my car2(ptr) is: "<<mycar2->get_year()<<" "<<mycar2->get_name()<<" "<<mycar2->get_model()<<std::endl;

    // Create a smart pointer to a Car object.
    std::shared_ptr<Car> myCar3(new Car());
    myCar3 ->set_year(2005); 
    myCar3 ->set_name("Toyota"); 
    myCar3 ->set_model("Camery");
    std::cout<<"my car3(smart ptr) is: "<<myCar3->get_year()<<" "<<myCar3->get_name()<<" "<<myCar3->get_model()<<std::endl;


}
```
``` cpp
cmake_minimum_required(VERSION 2.8)
# CMAKE_CXX_STANDARD
# CMAKE_CXX_STANDARD_REQUIRED

#set()
#set(CMAKE_CXX_FLAGS "-g -Wall")

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME cars)
project(${PROJECT_NAME})

#add library
add_library(car_proj_lib car.cpp)

#add_executable()  #Create the executable file called app
add_executable(app main.cpp)
target_link_libraries(app car_proj_lib)


#option(test "Build all tests." OFF) # Makes boolean 'test' available. Options. Turn on with 'cmake -Dmyvarname=ON'.
```
 	mkdir build
 	cd build
  	cmake ..
   	make
    	./app
     
	Testing Hello world!
	my car1 is: 2005 Toyota sienna
	my car2(ptr) is: 2023 Toyota Camery
	my car3(smart ptr) is: 2005 Toyota Camery

 					
** C++ Class Member Functions			
**	A member function of a class is a function that has its definition or its prototype within the class definition like any other variable. It operates on any object of the class of which it is a member, and has access to all the members of a class for that object.
	 
Member functions can be defined within the class definition or separately using scope resolution operator, : −. Defining a member function within the class definition declares the function inline, even if you do not use the inline specifier. So either you can define Volume() function as below −
```cpp	 
	class Box {
	   public:
	      double length;      // Length of a box
	      double breadth;     // Breadth of a box
	      double height;      // Height of a box
	   
	      double getVolume(void) {
	         return length * breadth * height;
	      }
	};
```	 
If you like, you can define the same function outside the class using the scope resolution operator (::) as follows −
```cpp	 
	double Box::getVolume(void) {
	   return length * breadth * height;
	}
```
Here, only important point is that you would have to use class name just before :: operator. A member function will be called using a dot operator (.) on a object where it will manipulate data related to that object only as follows −
```cpp	 
	Box myBox;          // Create an object
	myBox.getVolume();  // Call member function for the object
```
Let us put above concepts to set and get the value of different class members in a class −
```cpp
	#include <iostream>
	using namespace std;
	class Box {
	   public:
	      double length;         // Length of a box
	      double breadth;        // Breadth of a box
	      double height;         // Height of a box
	      // Member functions declaration
	      double getVolume(void);
	      void setLength( double len );
	      void setBreadth( double bre );
	      void setHeight( double hei );
	};
	// Member functions definitions
	double Box::getVolume(void) {
	   return length * breadth * height;
	}
	void Box::setLength( double len ) {
	   length = len;
	}
	void Box::setBreadth( double bre ) {
	   breadth = bre;
	}
	void Box::setHeight( double hei ) {
	   height = hei;
	}
	// Main function for the program
	int main() {
	   Box Box1;                // Declare Box1 of type Box
	   Box Box2;                // Declare Box2 of type Box
	   double volume = 0.0;     // Store the volume of a box here
	 
	   // box 1 specification
	   Box1.setLength(6.0); 
	   Box1.setBreadth(7.0); 
	   Box1.setHeight(5.0);
	   // box 2 specification
	   Box2.setLength(12.0); 
	   Box2.setBreadth(13.0); 
	   Box2.setHeight(10.0);
	   // volume of box 1
	   volume = Box1.getVolume();
	   cout << "Volume of Box1 : " << volume <<endl;				
	   // volume of box 2
	   volume = Box2.getVolume();
	   cout << "Volume of Box2 : " << volume <<endl;
	   return 0;
	}
	When the above code is compiled and executed, it produces the following 

	result −				
	Volume of Box1 : 210
	Volume of Box2 : 1560
```	
 					
#### 3.2 Accessing Class Members
Two methods
	1. class attribute (dot operator )
	2.  class methods  (arrow operator or member of pointer operator)
```cpp	
	1. using the dot operator
	Class Account{
	};
	 
	Account frank_account;
	frank_account.balance;
	frank_account.deposit(1000.0);
	 
	3. Class methods , use the member of operator of pointer operator
		a.  (arrow operator ) very often used
		Account *frank_account= new Account();
		frank_account -> balance
		frank_account -> deposit(1000.0)
	4. (dot operator)
		(*frank_account).balance
		(*frank_account).deposit(1000.0)
	5 using smart pointer

```
```cpp
#include <iostream>
#include <string>
class Player{
public:
    //attributes
    std::string name;
    int health;
    int xp;
    //methods
    void talk(std::string text_to_say){
        std::cout<<text_to_say<<std::endl;
    }
    bool is_dead();
private:
};
class Account{
public:
//attr
    std::string name;
    double balance;
    bool deposit(double bal);
    bool withdraw(double bal);
};
 ```
 ```cpp
int main () {
    Player frank ;
    Player *12; = new Player;
 
    frank.xp =50;
    frank.health =100;
    frank.talk("hello frank");
 
    israel->xp =150;   //Segmentation fault (core dumped) if you didnt add = new Player
    std::cout<<israel->xp<<std::endl;
    israel->health=200; //Segmentation fault (core dumped) if you didnt add = new Player
    std::cout<<israel->health<<std::endl;
    israel->talk("hello israel");
 
    return 0;
}
```
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class Player
{
public:
    //methods
    void talk(std::string text)
    {
        std::cout<<name<<" says "<<text<<'\n';
    };
    bool is_playing();

//private:
    // attributes
    std::string name;
    int health;
    int xp;

};

class Account{
public:
//attr
    std::string name;
    double balance;
//methods
    bool deposit(double bal)
    {
        balance += bal;
        std::cout<<"deposit balance: "<<balance<<std::endl;
    };
    bool withdraw(double bal)
    {
        balance=-bal;
        std::cout<<"withdraw balance: "<<balance<<std::endl;

    };
};

int main()
{
    
    Player sam;
    sam.name="SAM";
    sam.health=100;
    sam.xp=12;
    
    std::cout<<sam.name<<'\n';  //SAM
    std::cout<<sam.health<<'\n'; //100
    std::cout<<sam.xp<<'\n'; //12
    sam.talk("hello!");  //SAM says hello!

    Player *smith= new Player;
    (*smith).name="SMITH";
    (*smith).health=1000;
    smith->xp=1;
    
    std::cout<<(*smith).name<<'\n';  //SMITH
    std::cout<<(*smith).health<<'\n'; //1000
    std::cout<<(*smith).xp<<'\n'; //1
    (*smith).talk("hello!");  //SMITH says hello!
    smith->talk("i am using arrow!");  //SMITH says i am using arrow!
     
    Account sam_account;
    sam_account.name="SAM'S";
    sam_account.balance=1000;
    sam_account.deposit(1000);//deposit balance: 2000
    sam_account.withdraw(500);//withdraw balance: -500    

    return 0;
}

```
#### 3.3 public,private and protected
* public:
    - accessable everywhere
* private:
    - accessable only by members or friends of class
    - by default everything in class is private if not specified
       - forexaple: want to control health and only setup upto 100 and dont want users to directly change xp. 

       ```cpp
       class Player
       {
            private:
                xp;
            public:
                set_xp{
                    if (xp<100)
                    {
                        ...
                    }else{

                    }
                }
       }
       ```
* protected:
    - used with inheretance

#### 3.4 Implementing Member Methods
  
- public methods has direct access to private attributes.
- separating specification from implementation
    - A header(for ex. **file.h** specification) file in C++ is a file that contains declarations of functions, classes, variables, constants, or macros that can be shared by multiple source files. Header files allow you to reuse code and avoid duplication. Header files usually have the extension .h or .hpp, and they are included in the source files using the #include preprocessor directive. 
    - file.cpp implementation

- include guards
    -  An include guard is a way of preventing a header file from being included more than once in a source file. It can help avoid errors such as multiple definitions or declarations of the same entity. An include guard consists of three preprocessor directives: #ifndef, #define, and #endif.
```cpp
    #ifndef MYHEADER_H 
    #define MYHEADER_H

    // code for the header file

    #endif // MYHEADER_H
```

```cpp
//car.h

#include<string>

#ifndef CAR_H
#define CAR_H

class Car
{
    public:
        int get_year();
        void set_year(int caryear);
            
        std::string get_name();
        void set_name(std::string carname);

        std::string get_model();
        void set_model(std::string carmodel);      
    private:
        int year;
        std::string name;
        std::string model;
};

#endif //CAR_H

```
```cpp
//car.cpp
#include"car.h"

int Car::get_year(){
    return year;
}
void Car::set_year(int caryear)
{
    year=caryear;
}

std::string Car::get_name()
{
    return name;
}
void Car::set_name(std::string carname)
{
    name=carname;
}

std::string Car::get_model()
{
    return model;
}
void Car::set_model(std::string carmodel)
{
    model=carmodel; 
}
```
```cpp
#include <iostream>
#include <memory>
#include "car.h"

int main()
{
    std::cout<<"Testing Hello world!"<<std::endl;

    Car mycar1;
    mycar1.set_year(2005);
    mycar1.set_name("Toyota");
    mycar1.set_model("sienna");
    std::cout<<"my car1 is: "<<mycar1.get_year()<<" "<<mycar1.get_name()<<" "<<mycar1.get_model()<<std::endl;

    Car *mycar2= new Car;
    mycar2 ->set_year(2023); 
    mycar2 ->set_name("Toyota"); 
    mycar2 ->set_model("Camery"); 
    std::cout<<"my car2(ptr) is: "<<mycar2->get_year()<<" "<<mycar2->get_name()<<" "<<mycar2->get_model()<<std::endl;

    // Create a smart pointer to a Car object.
    std::shared_ptr<Car> myCar3(new Car());
    myCar3 ->set_year(2005); 
    myCar3 ->set_name("Toyota"); 
    myCar3 ->set_model("Camery");
    std::cout<<"my car3(smart ptr) is: "<<myCar3->get_year()<<" "<<myCar3->get_name()<<" "<<myCar3->get_model()<<std::endl;
}
```
```cmake
cmake_minimum_required(VERSION 2.8)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME cars)
project(${PROJECT_NAME})

#add library
add_library(car_proj_lib car.cpp)

#Create the executable file called app
add_executable(app main.cpp)
target_link_libraries(app car_proj_lib)

```
    $ ./app
    Testing Hello world!
    my car1 is: 2005 Toyota sienna
    my car2(ptr) is: 2023 Toyota Camery
    my car3(smart ptr) is: 2005 Toyota Camery
---------------------------------
Account program.

```cpp
// account.h file 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account {
private:
    // attributes
    std::string name;
    double balance;
    
public:
    // methods
    // declared inline
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }
    
    // methods will be declared outside the class declaration
    void set_name(std::string n);
    std::string get_name();
    
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _ACCOUNT_H_
```
```cpp
//account.cpp
#include "Account.h"

void Account::set_name(std::string n) {
    name = n;
}

std::string Account::get_name() {
    return name;
}

bool Account::deposit(double amount) {
    // if verify amount
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (balance-amount >= 0) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}

```
```cpp 
// Section 13
// Implementing member methods 2
//main.cpp
#include <iostream>
#include "Account.h"

using namespace std;

int main() {
    Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);
    
    if (frank_account.deposit(200.0))
        cout << "Deposit OK" << endl;
    else 
        cout << "Deposit Not allowed" << endl;
        
    if (frank_account.withdraw(500.0))
        cout << "Withdrawal OK" << endl;
    else
        cout << "Not sufficient funds" << endl;
        
    if (frank_account.withdraw(1500.0))
        cout << "Withdraw OK" << endl;
    else
        cout << "Not sufficient funds" << endl; 
    
    return 0;
}
```
#### 3.4 Constructors and Destructors

The Class Constructor
A class constructor is a special member function of a class that is executed whenever we create new objects of that class.
A constructor will have exact same name as the class and it does not have any return type at all, not even void. Constructors can be very useful for setting initial values for certain member variables
 
class Line {
   public:
      void setLength( double len );
      double getLength( void );
      Line();  // This is the constructor
   private:
      double length;
};
 
 
Destructor: 
Like a constructor, Destructor is also a member function of a class that has the same name as the class name preceded by a tilde(~) operator. It helps to deallocate the memory of an object. It is called while the object of the class is freed or deleted. In a class, there is always a single destructor without any parameters so it can’t be overloaded. It is always called in the reverse order of the constructor. if a class is inherited by another class and both the classes have a destructor then the destructor of the child class is called first, followed by the destructor of the parent or base class. 
Syntax:  
  ~ClassName()
   { 
       //Destructor's Body
   }
 
 
#### 3.5  The Default Constructor
 
From < https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535580#content> 
 
	• Doesn’t expect no argument 
	• Called when you instance a new obj
	
Class player{
player ((std::string name, int val, int num ) ;
 
};
Int main(){
Player frank;  //doesn’t work
Player frank{"frank,100,13"};
Frank.set_name{"Frank"};
}
 
 
#include <string>
using namespace std;
 
class Dog {
private:
    string name;
    int age;
public:
 
//---- WRITE YOUR OVERLOADED CONSTRUCTOR BELOW THIS LINE
    Dog(std::string n, int a){
        name=n;
        age=a;
    }
144. Constructor Initialization lists
 ```
#include<iostream>
using namespace std;
 
class Point {
private:
    int x;
    int y;
public:
    Point(int i = 0, int j = 0):x(i), y(j) {}
    /*  The above use of Initializer list is optional as the
        constructor can also be written as:
        Point(int i = 0, int j = 0) {
            x = i;
            y = j;
        }
    */   
     
    int getX() const {return x;}
    int getY() const {return y;}
};
 
int main() {
  Point t1(10, 15);
  cout<<"x = "<<t1.getX()<<", ";
  cout<<"y = "<<t1.getY();
  return 0;
}
 
/* OUTPUT:
   x = 10, y = 15
*/
 ```
https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
145. Delegating Constructors
 
From < https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535586#overview> 
 
To minimize duplicated code
 
 
Player::player() 
	: name{'none'},health{0},xp{0} { }
	 
To Delegating Constructors
Player::player() 
	: player{'none',0,0} { }
 
 
Player::player(std::string name_val) 
	: name{name_val},health{0},xp{0} { }
To Delegating Constructors
Player::player(std::string name_val) 
	: player{name_val,0,0} { }
	 
 
Player::player(std::string name_val, int health_val, int xp_val) 
		: name{name_val},health{health_val},xp{xp_val} { }
	 
To Delegating Constructors
Player::player(std::string name_val, int health_val, int xp_val):
		player(name_val,health_val,xp_val) { }
146. Constructor Parameters and Default Values
 
From < https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535588#overview> 
Just like default function
 
 
Class player{
 
Public: 
 
Player::player(std::string name_val = "none", int health_val = 0, int xp_val =0):
 
}
 
Player::player(std::string name_val, int health_val, int xp_val) 
		: name{name_val},health{health_val},xp{xp_val} { }
 


#### 3.7 Copy Constructor(study more)
used to initialize the members of a newly created object by copying the members of an already existing object.
-when
	Passing an obj by value as a parameter
	Returning an object from a fun by value
	Constructing one obj based on another of same class
	 
ClassName (const ClassName &old_obj); 
 			
 	 		#include <iostream>
	// C++ program to demonstrate the working		using namespace std;
	// of a COPY CONSTRUCTOR		class Line {
	#include <iostream>		   public:
	using namespace std;		      int getLength( void );
	class Point {		      Line( int len );             // simple constructor
	private:		      Line( const Line &obj);  // copy constructor
	    int x, y;		      ~Line();                     // destructor
	public:		   private:
	    Point(int x1, int y1)		      int *ptr;
	    {		};
	        x = x1;		// Member functions definitions including constructor
	        y = y1;		Line::Line(int len) {
	    }		   cout << "Normal constructor allocating ptr" << endl;
	    // Copy constructor		   
	    Point(const Point& p1)		   // allocate memory for the pointer;
	    {		   ptr = new int;
	        x = p1.x;		   *ptr = len;
	        y = p1.y;		}
	    }		Line::Line(const Line &obj) {
	    int getX() { return x; }		   cout << "Copy constructor allocating ptr." << endl;
	    int getY() { return y; }		   ptr = new int;
	};		   *ptr = *obj.ptr; // copy the value
	int main()		}
	{		Line::~Line(void) {
	    Point p1(10, 15); // Normal constructor is called here		   cout << "Freeing memory!" << endl;
	    Point p2 = p1; // Copy constructor is called here		   delete ptr;
	    // Let us access values assigned by constructors		}
	    cout << "p1.x = " << p1.getX()		int Line::getLength( void ) {
	        << ", p1.y = " << p1.getY();		   return *ptr;
	    cout << "\np2.x = " << p2.getX()		}
	        << ", p2.y = " << p2.getY();		void display(Line obj) {
	    return 0;		   cout << "Length of line : " << obj.getLength() <<endl;
	}		}
			// Main function for the program
			int main() {
			   Line line1(10);
			   Line line2 = line1; // This also calls copy constructor
			   display(line1);
			   display(line2);
			   return 0;
			}
			When the above code is compiled and executed, it produces the following result −
			Normal constructor allocating ptr
			Copy constructor allocating ptr.
			Copy constructor allocating ptr.
			Length of line : 10
			Freeing memory!
			Copy constructor allocating ptr.
			Length of line : 10
			Freeing memory!
			Freeing memory!
			Freeing memory!
 			
148. Shallow Copying with the Copy Constructor
 
Depending upon the resources like dynamic memory held by the object, either we need to perform Shallow Copy or Deep Copy in order to create a replica of the object. In general, if the variables of an object have been dynamically allocated, then it is required to do a Deep Copy in order to create a copy of the object.
	// C++ program for the above approach
	#include <iostream>
	using namespace std;
	// Box Class
	class box {
	private:
		int length;
		int breadth;
		int height;
	public:
		// Function that sets the dimensions
		void set_dimensions(int length1, int breadth1,
							int height1)
		{
			length = length1;
			breadth = breadth1;
			height = height1;
		}
		// Function to display the dimensions
		// of the Box object
		void show_data()
		{
			cout << " Length = " << length
				<< "\n Breadth = " << breadth
				<< "\n Height = " << height
				<< endl;
		}
	};
	// Driver Code
	int main()
	{
		// Object of class Box
		box B1, B3;
		// Set dimensions of Box B1
		B1.set_dimensions(14, 12, 16);
		B1.show_data();
		// When copying the data of object
		// at the time of initialization
		// then copy is made through
		// COPY CONSTRUCTOR
		box B2 = B1;
		B2.show_data();
		// When copying the data of object
		// after initialization then the
		// copy is done through DEFAULT
		// ASSIGNMENT OPERATOR
		B3 = B1;
		B3.show_data();
		return 0;
	}
	Let us see the differences in a tabular form -:
	 	Shallow Copy 	Deep copy
	1.	When we create a copy of object by copying data of all member variables as it is, then it is called shallow copy 	When we create an object by copying data of another object along with the values of memory resources that reside outside the object, then it is called a deep copy
	2.	A shallow copy of an object copies all of the member field values.	 Deep copy is performed by implementing our own copy constructor.
	3.	In shallow copy, the two objects are not independent	It copies all fields, and makes copies of dynamically allocated memory pointed to by the fields
	4.	It also creates a copy of the dynamically allocated objects	If we do not create the deep copy in a rightful way then the copy will point to the original, with disastrous consequences.
	
149. Deep Copying with the Copy Constructor
 
From < https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535594#content> 
 
In Deep copy, an object is created by copying data of all variables, and it also allocates similar memory resources with the same value to the object. In order to perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as well, if required. Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.
// C++ program to implement the
// deep copy
#include <iostream>
using namespace std;
// Box Class
class box {
private:
	int length;
	int* breadth;
	int height;
public:
	// Constructor
	box()
	{
		breadth = new int;
	}
	// Function to set the dimensions
	// of the Box
	void set_dimension(int len, int brea,
					int heig)
	{
		length = len;
		*breadth = brea;
		height = heig;
	}
	// Function to show the dimensions
	// of the Box
	void show_data()
	{
		cout << " Length = " << length
			<< "\n Breadth = " << *breadth
			<< "\n Height = " << height
			<< endl;
	}
	// Parameterized Constructors for
	// for implementing deep copy
	box(box& sample)
	{
		length = sample.length;
		breadth = new int;
		*breadth = *(sample.breadth);
		height = sample.height;
	}
	// Destructors
	~box()
	{
		delete breadth;
	}
};
// Driver Code
int main()
{
	// Object of class first
	box first;
	// Set the dimensions
	first.set_dimension(12, 14, 16);
	// Display the dimensions
	first.show_data();
	// When the data will be copied then
	// all the resources will also get
	// allocated to the new object
	box second = first;
	// Display the dimensions
	second.show_data();
	return 0;
}
Let us see the differences in a tabular form -:
 	Shallow Copy 	Deep copy
1.	When we create a copy of object by copying data of all member variables as it is, then it is called shallow copy 	When we create an object by copying data of another object along with the values of memory resources that reside outside the object, then it is called a deep copy
2.	A shallow copy of an object copies all of the member field values.	 Deep copy is performed by implementing our own copy constructor.
3.	In shallow copy, the two objects are not independent	It copies all fields, and makes copies of dynamically allocated memory pointed to by the fields
4.	It also creates a copy of the dynamically allocated objects	If we do not create the deep copy in a rightful way then the copy will point to the original, with disastrous consequences.

A constructor is a special type of member function that is called automatically when an object is created.

From <https://www.programiz.com/cpp-programming/constructors> 

In C++, a constructor has the same name as that of the class and it does not have a return type. For example,
Class Wall{
public:
    // create a constructor 
Wall() {
    // code}
};

From <https://www.programiz.com/cpp-programming/constructors> 

150. (come back for this) Move Constructors
	- Study L value and R value

From <https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535596#overview> 

 
A move constructor of class T is a non-template constructor whose first parameter is T&&, const T&&, volatile T&&, or const volatile T&&, and either there are no other parameters, or the rest of the parameters all have default values.
Syntax
class-name ( class-name && )	(1)	(since C++11)
class-name ( class-name && ) = default;	(2)	(since C++11)
class-name ( class-name && ) = delete;	(3)	(since C++11)
Where class-name must name the current class (or current instantiation of a class template), or, when declared at namespace scope or in a friend declaration, it must be a qualified class name.
Explanation
1) Typical declaration of a move constructor.
2) Forcing a move constructor to be generated by the compiler.
3) Avoiding implicit move constructor.
The move constructor is typically called when an object is initialized (by direct-initialization or copy-initialization) from rvalue (xvalue or prvalue) (until C++17)xvalue (since C++17) of the same type, including
• initialization: T a = std::move(b); or T a(std::move(b));, where b is of type T;
• function argument passing: f(std::move(a));, where a is of type T and f is void f(T t);
• function return: return a; inside a function such as T f(), where a is of type T which has a move constructor.
When the initializer is a prvalue, the move constructor call is often optimized out (until C++17)never made (since C++17), see copy elision.
Move constructors typically "steal" the resources held by the argument (e.g. pointers to dynamically-allocated objects, file descriptors, TCP sockets, I/O streams, running threads, etc.) rather than make copies of them, and leave the argument in some valid but otherwise indeterminate state. For example, moving from a std::string or from a std::vector may result in the argument being left empty. However, this behavior should not be relied upon. For some types, such as std::unique_ptr, the moved-from state is fully specified.
Implicitly-declared move constructor
If no user-defined move constructors are provided for a class type (struct, class, or union), and all of the following is true:
• there are no user-declared copy constructors;
• there are no user-declared copy assignment operators;
• there are no user-declared move assignment operators;
• there is no user-declared destructor.
then the compiler will declare a move constructor as a non-explicit inline public member of its class with the signature T::T(T&&).
A class can have multiple move constructors, e.g. both T::T(const T&&) and T::T(T&&). If some user-defined move constructors are present, the user may still force the generation of the implicitly declared move constructor with the keyword default.
The implicitly-declared (or defaulted on its first declaration) move constructor has an exception specification as described in dynamic exception specification (until C++17)noexcept specification (since C++17)
Deleted implicitly-declared move constructor
The implicitly-declared or defaulted move constructor for class T is defined as deleted if any of the following is true:
• T has non-static data members that cannot be moved (have deleted, inaccessible, or ambiguous move constructors);
• T has direct or virtual base class that cannot be moved (has deleted, inaccessible, or ambiguous move constructors);
• T has direct or virtual base class or a non-static data member with a deleted or inaccessible destructor;
• T is a union-like class and has a variant member with non-trivial move constructor.
A defaulted move constructor that is deleted is ignored by overload resolution (otherwise it would prevent copy-initialization from rvalue).
Trivial move constructor
The move constructor for class T is trivial if all of the following is true:
• it is not user-provided (meaning, it is implicitly-defined or defaulted);
• T has no virtual member functions;
• T has no virtual base classes;
• the move constructor selected for every direct base of T is trivial;
• the move constructor selected for every non-static class type (or array of class type) member of T is trivial.
A trivial move constructor is a constructor that performs the same action as the trivial copy constructor, that is, makes a copy of the object representation as if by std::memmove. All data types compatible with the C language (POD types) are trivially movable.

From <https://en.cppreference.com/w/cpp/language/move_constructor> 

151. The 'this' Pointer(study more)

From <https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535598#content> 

To understand ‘this’ pointer, it is important to know how objects look at functions and data members of a class.
1. Each object gets its own copy of the data member.
2. All-access the same function definition as present in the code segment.

From <https://www.geeksforgeeks.org/this-pointer-in-c/> 


Meaning each object gets its own copy of data members and all objects share a single copy of member functions.
Then now question is that if only one copy of each member function exists and is used by multiple objects, how are the proper data members are accessed and updated?
The compiler supplies an implicit pointer along with the names of the functions as ‘this’.
The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions. ‘this’ pointer is not available in static member functions as static member functions can be called without any object (with class name).
For a class X, the type of this pointer is ‘X* ‘. Also, if a member function of X is declared as const, then the type of this pointer is ‘const X *’ (see this GFact)
In the early version of C++ would let ‘this’ pointer to be changed; by doing so a programmer could change which object a method was working on. This feature was eventually removed, and now this in C++ is an r-value.
C++ lets object destroy themselves by calling the following code :

delete this;
As Stroustrup said ‘this’ could be the reference than the pointer, but the reference was not present in the early version of C++. If ‘this’ is implemented as a reference then, the above problem could be avoided and it could be safer than the pointer.
Following are the situations where ‘this’ pointer is used:
1) When local variable’s name is same as member’s name

#include<iostream>
using namespace std;
  
/* local variable is same as a member's name */
class Test
{
private:
   int x;
public:
   void setX (int x)
   {
       // The 'this' pointer is used to retrieve the object's x
       // hidden by the local variable 'x'
       this->x = x;
   }
   void print() { cout << "x = " << x << endl; }
};
  
int main()
{
   Test obj;
   int x = 20;
   obj.setX(x);
   obj.print();
   return 0;
}
Output:
 x = 20
For constructors, initializer list can also be used when parameter name is same as member’s name.


2) To return reference to the calling object

/* Reference to the calling object can be returned */ 
Test& Test::func ()
{
   // Some processing
   return *this;
} 
When a reference to a local object is returned, the returned reference can be used to chain function calls on a single object.

#include<iostream>
using namespace std;
  
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
  Test &setX(int a) { x = a; return *this; }
  Test &setY(int b) { y = b; return *this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
  
int main()
{
  Test obj1(5, 5);
  
  // Chained function calls.  All calls modify the same object
  // as the same object is returned by reference
  obj1.setX(10).setY(20);
  
  obj1.print();
  return 0;
}
Output:
x = 10 y = 20


Exercise:
Predict the output of following programs. If there are compilation errors, then fix them.
Question 1

#include<iostream>
using namespace std;
  
class Test
{
private:
  int x;
public:
  Test(int x = 0) { this->x = x; }
  void change(Test *t) { this = t; }
  void print() { cout << "x = " << x << endl; }
};
  
int main()
{
  Test obj(5);
  Test *ptr = new Test (10);
  obj.change(ptr);
  obj.print();
  return 0;
}


Question 2

#include<iostream>
using namespace std;
  
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
  static void fun1() { cout << "Inside fun1()"; }
  static void fun2() { cout << "Inside fun2()"; this->fun1(); }
};
  
int main()
{
  Test obj;
  obj.fun2();
  return 0;
}


Question 3

#include<iostream>
using namespace std;
  
class Test
{
private:
  int x;
  int y;
public:
  Test (int x = 0, int y = 0) { this->x = x; this->y = y; }
  Test setX(int a) { x = a; return *this; }
  Test setY(int b) { y = b; return *this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
  
int main()
{
  Test obj1;
  obj1.setX(10).setY(20);
  obj1.print();
  return 0;
}


Question 4

#include<iostream>
using namespace std;
  
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
  void setX(int a) { x = a; }
  void setY(int b) { y = b; }
  void destroy()  { delete this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
  
int main()
{
  Test obj;
  obj.destroy();
  obj.print();
  return 0;
}
Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above

From <https://www.geeksforgeeks.org/this-pointer-in-c/> 

Every object in C++ has access to its own address through an important pointer called this pointer. The this pointer is an implicit parameter to all member functions. Therefore, inside a member function, this may be used to refer to the invoking object.
Friend functions do not have a this pointer, because friends are not members of a class. Only member functions have a this pointer.
Let us try the following example to understand the concept of this pointer −

From <https://www.tutorialspoint.com/cplusplus/cpp_this_pointer.htm> 


#include <iostream>
 
using namespace std;
class Box {
   public:
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume() {
         return length * breadth * height;
      }
      int compare(Box box) {
         return this->Volume() > box.Volume();
      }
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};
int main(void) {
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2
if(Box1.compare(Box2)) {
      cout << "Box2 is smaller than Box1" <<endl;
   } else {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   
   return 0;
}

From <https://www.tutorialspoint.com/cplusplus/cpp_this_pointer.htm> 

C++ this Pointer
In C++ programming, this is a keyword that refers to the current instance of the class. There can be 3 main usage of this keyword in C++.
	• It can be used to pass current object as a parameter to another method.
	• It can be used to refer current class instance variable.
	• It can be used to declare indexers.

C++ this Pointer Example
Let's see the example of this keyword in C++ that refers to the fields of current class.
1. #include <iostream>  
2. using namespace std;  
3. class Employee {  
4.    public:  
5.        int id; //data member (also instance variable)      
6.        string name; //data member(also instance variable)  
7.        float salary;  
8.        Employee(int id, string name, float salary)    
9.         {    
10.              this->id = id;    
11.             this->name = name;    
12.             this->salary = salary;   
13.         }    
14.        void display()    
15.         {    
16.             cout<<id<<"  "<<name<<"  "<<salary<<endl;    
17.         }    
18. };  
19. int main(void) {  
20.     Employee e1 =Employee(101, "Sonoo", 890000); //creating an object of Employee   
21.     Employee e2=Employee(102, "Nakul", 59000); //creating an object of Employee  
22.     e1.display();    
23.     e2.display();    
24.     return 0;  
25. } 

From <https://www.javatpoint.com/cpp-this-pointer> 

152. Using const with Classes(study more)

From <https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535602#overview> 

Const Player villlan {"Villan,100,55"} //attributes can not change

Recommended Getters should be const

std::string get_name()const {return name;}
int get_health()const {return health;}
int get_xp()const{return xp;} 


Constant member functions are those functions which are denied permission to change the values of the data members of their class. To make a member function constant, the keyword “const” is appended to the function prototype and also to the function definition header.
Like member functions and member function arguments, the objects of a class can also be declared as const. an object declared as const cannot be modified and hence, can invoke only const member functions as these functions ensure not to modify the object. 
A const object can be created by prefixing the const keyword to the object declaration. Any attempt to change the data member of const objects results in a compile-time error. 
Syntax: 
(i)    For function declaration within a class.
<return_type> <function_name>() const
Example:
Int get_data() const;
(ii)    For function definition within the class declaration.
<return_type> <function_name>() const
{
         //function body
}
Example:
int get_data() const
{
               //function body
}
(iii)    For function definition outside the class.
<return_type> <class_name> : : <function_name>() const
{
         //function body
}
Example:
int Demo :: get_data() const
{
}
• When a function is declared as const, it can be called on any type of object, const object as well as non-const objects.
• Whenever an object is declared as const, it needs to be initialized at the time of declaration. however, the object initialization while declaring is possible only with the help of constructors.
A function becomes const when the const keyword is used in the function’s declaration. The idea of const functions is not to allow them to modify the object on which they are called. It is recommended the practice to make as many functions const as possible so that accidental changes to objects are avoided.
Following is a simple example of a const function. 
• C++

// Example: Not a constant member function.
#include<iostream>
using namespace std;
 
class Demo
{
    int x;
     
      public:
     
    void set_data(int a)
    {
        x=a;
    }
  
    int get_data()
     {
         ++x;
         return x;
     }
  
};
 
 
main()
{
    Demo d;
    d.set_data(10);
    cout<<endl<<d.get_data();
 
    return 0;
}
Output
11
• C++

// Example: of Constant member function
 
#include<iostream>
using namespace std;
 
class Demo
{
    int x;
 
      public:
     
    void set_data(int a)
    {
        x=a;
    }
  
     int get_data() const           //constant member function
     {
         ++x;                 // Error while attempting to modify the data member
         return x;
     }
  
};
 
 
main()
{
    Demo d;
    d.set_data(10);
    cout<<endl<<d.get_data();
 
    return 0;
}
• C++

// Example: Constant member function defined outside the class
 
#include<iostream>
using namespace std;
 
class Demo
{
    int x;
 
      public:
     
    void set_data(int);
  
     int get_data() const;
  
};
 
void Demo::set_data(int a)
{
    x=a;
}
 
 int Demo::get_data() const
 {
     return x;
 }
 
main()
{
    Demo d;
    d.set_data(10);
    cout<<endl<<d.get_data();
 
    return 0;
}
Output
10
• CPP

#include <iostream>
using namespace std;
 
class Test {
    int value;
 
public:
    Test(int v = 0) { value = v; }
 
    int getValue() const { return value; }
};
 
int main()
{
    Test t(20);
    cout << t.getValue();
    return 0;
}
Output
20
When a function is declared as const, it can be called on any type of object. Non-const functions can only be called by non-const objects. 
For example the following program has compiler errors.  
• CPP

#include<iostream>
using namespace std;
 
class Test {
    int value;
public:
    Test(int v = 0) {value = v;}
    int getValue() {return value;}
};
 
int main() {
    const Test t;
    cout << t.getValue();
    return 0;
}
Output: 
 passing 'const Test' as 'this' argument of 'int 
Test::getValue()' discards qualifiers
Let’s look at another example:  
• CPP

// Demonstration of constant object,
// show that constant object can only
// call const member function
#include<iostream>
using namespace std;
class Demo
{
    int value;
    public:
    Demo(int v = 0) {value = v;}
    void showMessage()
    {
        cout<<"Hello World We are Tushar, "
        "Ramswarup, Nilesh and Subhash Inside"
        " showMessage() Function"<<endl;
    }
    void display()const
    {
        cout<<"Hello world I'm Rancho "
        "Baba Inside display() Function"<<endl;
    }
};
int main()
{
   //Constant object are initialised at the time of declaration using constructor
    const Demo d1;
    //d1.showMessage();Error occurred if uncomment.
    d1.display();
    return(0);
}
Output
Hello world I'm Rancho Baba Inside display() Function
OUTPUT : Hello world I'm Rancho Baba Inside display() Function
Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.

From <https://www.geeksforgeeks.org/const-member-functions-c/> 



153. Static Class Members

From <https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535604#overview> 

Private:
static int num_players; //static class member

Public: 
static int get_num_player();




--------------------------------------------------------------------
### 3.4 Operator Overloading 
#### 3.4.1 what is Operator Overloading
- Overloading means: giving meaning to
- In C++, we can change the way operators work for user-defined types like objects and structures. This is known as operator overloading.
- allows user defined types behave similar to built in types.
- can make our code readable and writable
-  not dont automatically (except for addignment operatoe : =)
- without operator overloader
  	- using function
  	  	number result = multiply(add(a,b),divide(c,d))
  	  - using member methods from class
  	    	number result = ((a.add(b)).multiply(c.divide(d)));
- using overloaded operators (we have to define first) (dont overload unless it makes sense)
  	number result =(a+b)*(c/d);
  - Almost all operators can be overloaded except a few. Following is the list of operators that cannot be overloaded. 
	sizeof
	typeid
	Scope resolution (::)
	Class member access operators (.(dot)
	 .* (pointer to member operator))
	Ternary or conditional (?:)
- Examples:
  	- operator with built in types
  	  int
  	  a=b+c
  	  a<b
  	  std::cout<<a
  	  - 	**user defined types**
  	    	std::string
  	    	s1=s2+s3
  	    	s1<s2
  	    	std::cout<<s1
	 	
   			**mystring**
	    		s1=s2+s3
  	    		s1<s2
  	    		std::cout<<s1

```cpp
#include <iostream>
#include <cstring>
class Mystring
{
    private:
        char *str; // pointer to char[] that holds c style Mystring
    public:
        Mystring():str{nullptr}    //no args constructor
        {
          std::cout<<"no args constructor"<<std::endl;
          str=new char[1];
          *str='\0';
        }
        
        Mystring(const char *s):str{nullptr}   //overloaded constructor
        {
            std::cout<<"overloaded constructor"<<std::endl;
            if (s==nullptr)
            {
                str= new char[1];
                *str='\0';
            }else{
                str=new char[std::strlen(s)+1];
                std::strcpy(str,s);
            }
        }
        
        
        Mystring(const Mystring &source):str{nullptr} //copy constructor
        {
            std::cout<<"copy constructor"<<std::endl;
            str=new char[std::strlen(source.str)+1];
            std::strcpy(str,source.str);
        }
        
        ~Mystring( ) //destructor
        {
            delete [] str;
        }    
        
        void display() const 
        {
            std::cout<<"string= "<<str<<" :length= "<<get_length()<<std::endl;
        }
        int get_length() const   //getters
        {
            return std::strlen(str);
        }
        const char *get_str() const
        {
            return str;
        }
};
int main()
{
    Mystring empity; //no args constructor
    empity.display(); //string=  :length= 0
    
    Mystring a{"hello"}; //overloaded constructor
    a.display(); //string= hello :length= 5
    
   // Mystring *addressofa;  
    //addressofa=&a;
    Mystring *addressofa=&a;
    (*addressofa).display(); //string= hello :length= 5
    addressofa->display();  //string= hello :length= 5
    
    Mystring stooge {a}; //**copy constructor**
    stooge.display(); //string= hello :length= 5
    
    return 0;
}
```
   
#### 3.4.2 Overloading the assignment operator (copy) (=)
- 	assigns one object to another (not to confuse with initalization)
- 	Mystring s1{"Frank"};// this is assignment
- 	s2=s1; //assignment
- 	Mystring s2 =s1;  copy constructor, not an assignment 

- Default is memberwise assignment (shallow copy)
- if we have raw pointer data member, we must deep copy
- we use **operator=  ** to declare operators 

- overloading the copy assignmant operator(deep copy)
  ``` cpp
  	Type &Type::operator=(const Type &rhs);
	Mystring &Mystring::operator=(const Mystring &rhs);
  	s2=s1; 
  	s2.operator=(s1);  //operator method is called
  ```

```cpp
#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }


using namespace std;

int main() {
    Mystring a {"Hello"};                // overloaded constructor
    Mystring b;                             // no-args contructor
    b = a;                                      // copy assignment 
                                                  // b.operator=(a)
    b = "This is a test";                 // b.operator=("This is a test");
  
    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge {larry};            // copy constructor 
    Mystring stooges;                   // no-args constructor
    
    empty = stooge;                     // copy assignment operator
    
    empty.display();                      // Larry : 5
    larry.display();                         // Larry : 5
    stooge.display();                     // Larry : 5
    empty.display();                      // Larry : 5
    
    stooges = "Larry, Moe, and Curly";  
    stooges.display();                              // Larry, Moe, and Curly : 21
    
    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");
    
    cout << "=== Loop 1 ==================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                        // Larry
                                                                // Moe
                                                                //Curly
    cout << "=== Loop 2 ==================" << endl;
    for (Mystring &s: stooges_vec)
        s = "Changed";                              // copy assignment
        
    cout << "=== Loop 3 ================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                     // Changed
                                                            // Changed
                                                            // Changed
    
    return 0;
}
  ```
#### 3.4.3 Overloading the assignment operator (move)

#### 3.4.4 Overloading operators as a member functions

#### 3.4.5 Overloading the assignment operator





REVIEW:
- Dot and pointer operators
- public and private access modifers 
- methods,Constructors and destructors
	- Class methods
  	- default and overloaded constructors
	- copy and move constractors
   	- shallow vs deep copying
      	- this pointer
- static class members
- virtual
- struct vs. class
- friend of class ????
**Encapsulation in C++**
**Abstraction in C++**
**Inheritance in C++**
**Polymorphism in C++**

=============================================================================================
###  Structure 
- abstraction i.e collection of individual properties of real-world object. 
- containers of hetrogenous data mambers
- the diffrence betwen struct and class is **class is private by default** and **struct is public by default**.
  
```cpp   
	struct car {
		string name;
		int year;
		unsigned char car_purpose;
		string model;
		}
```
###  enum
-user-defined data type that consists of integral constants
-one benefit over constant is they provide encapsulation 
```cpp
	enum car_purpose {offroad,dailydriver,tow,camper};

	int main(){
	car mycar1;
	mycar1.name= "Toyota";
	mycar1.model="tacoma";
	mycar1.car_purpose=offroad;
        std::cout................................... finish.................
	}
```


=====================================================================
## TOPICS
### **namespace**
  Namespaces give you one mechanism to modularize code. A namespace allows you to label
your types, functions, and variables with a unique name so that, using the scope resolution
operator, you can give a fully qualified name. The advantage is that you know exactly which
item will be called. The disadvantage is that using a fully qualified name you are in effect
switching off C++'s argument-dependent lookup mechanism for overloaded functions where
the compiler will choose the function that has the best fit according to the arguments passed
to the function.
```cpp
#include <iostream>
namespace apple 
{ 
    namespace function {
    void print(const char* text)
    {
        std::cout<<"apple:: "<<text<<std::endl;
    }
                        }
}
namespace mango
{
    void print(const char* text)
    {
        std::cout<<"mando:: "<<text<<std::endl;
    }
}
int main()
{
    apple::function::print("Hello World");
    mango::print("Hello World");
    using namespace apple::function;
    print("Hello from apple::function ");
    return 0;
}
```
avoiding **using namespace X**; is a form of future-proofing, a way of making sure a change to the libraries and/or header files in use is not going to break a program. Consider two libraries called Foo and Bar:

``` cpp
using namespace foo;
using namespace bar;
```
Everything works fine, and you can call Blah() from Foo and Quux() from Bar without problems. But one day you upgrade to a new version of Foo 2.0, which now offers a function called Quux(). Now you've got a conflict: Both Foo 2.0 and Bar import Quux() into your global namespace. This is going to take some effort to fix, especially if the function parameters happen to match.
If you had used foo::Blah() and bar::Quux(), then the introduction of foo::Quux() would have been a non-event.
https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice 

------------------------------------------------------------------------------------------------------------
### Template
- the idea is to pass data type as a parameter so that we don’t need to write the same code for different data types.
- two types: function Templates and Class templates
  function Templates:

``` cpp
//function Template 
#include <iostream>
template<typename Temp>
void swap(Temp &x, Temp &y)
{
    Temp z{}; 
    std::cout<<"origin: "<<x<<","<<" "<<y<<std::endl;
    z=x;
    x=y;
    y=z;
    std::cout<<"swapped: "<<x<<","<<" "<<y<<std::endl;
}

int main()
{
    char x{'a'};
    char y{'b'};
    swap(x,y); //origin: a, b  swapped: b, a
    
    int a=1;
    int b=5;
    swap(a,b);  //origin: 1, 5 swapped: 5, 1
    
    double i=200.5;
    double j=53.9;
    swap(i,j);  //origin: 200.5, 53.9 swapped: 53.9, 200.5
    
    return 0;
}
```
Class templates: 
- 


- Advanced Template: https://learn.microsoft.com/en-us/cpp/cpp/class-templates?view=msvc-170

------------------------------------------------------------------------------------------------------------
### typename
The typename keyword must be used if a name in a template definition is a qualified name that is dependent on a template argument; it's optional if the qualified name isn't dependent.
The typename keyword is used in two different situations:
1) When referring to a qualified member of a class template, the compiler cannot tell whether the name refers to a type, object, or function. Use typename before the qualified name to tell the compiler that it names a type.
2)  In a template declaration, use typename to name a type parameter. In this context, class means the same thing as typename.

The typename keyword can also be used in place of class in template parameter lists. For example, the following statements are semantically equivalent:
```cpp
template<class T1, class T2>...
template<typename T1, typename T2>...
```
```cpp
//#define _USE_MATH_DEFINES
#include <cassert>  /// for assert
#include <cmath>    /// for M_PI definition and pow()
#include <cstdint>   /// for uint16_t datatype
#include <iostream>  /// for IO operations

namespace math {
template <typename T>
T square_area(T length) {
    return length * length;
}
} 

static void test() {
    // I/O variables for testing
    uint16_t int_length = 0;    // 16 bit integer length input

    // 1st test
    int_length = 5;
    int_expected = 25;
    int_area = math::square_area(int_length);
    
    std::cout << "AREA OF A SQUARE (int)" << std::endl;
    std::cout << "Input Length: " << int_length << std::endl;
    std::cout << "Expected Output: " << int_expected << std::endl;
    std::cout << "Output: " << int_area << std::endl;
    assert(int_area == int_expected);
    std::cout << "TEST PASSED" << std::endl << std::endl;
}
int main()
{
    test();
    return 0;
}
```
------------------------------------------------------------------------------------------------------------
### Typedef 
typedef keyword in C++ is used for aliasing existing data types, user-defined data types, and pointers to a more meaningful name. Typedefs allow you to give descriptive names to standard data types, which can also help you self-document your code. Mostly typedefs are used for aliasing, only if the predefined name is too long or complex to write again and again.  **The unnecessary use of typedef is generally not a good practice.**

-typedef statement to create an alias for a type
-syntax: 
	typedef < existing_data_type > < new_data_type >

``` cpp
#include <iostream>
#include <typeinfo>
#include <bits/stdc++.h>
#include <stdint.h>
//typedef unsigned int age_t; //or myagetype

int main()
{
    typedef size_t age1_t;  //*_t convention for defined typedef
    typedef unsigned int age2_t;
    typedef std::bitset<8> bytetype;

    age1_t age1 =20;
    std::cout<<age1<<std::endl;
    age1++;
    std::cout<<age1<<std::endl;
    
    std::cout<<typeid(age1).hash_code()<<std::endl;
    std::cout<<typeid(age1).name()<<std::endl;

    
    age2_t age2 =30;
    std::cout<<age2<<std::endl;
    age2++;
    std::cout<<age2<<std::endl;
    
    std::cout<<typeid(age2).hash_code()<<std::endl;
    std::cout<<typeid(age2).name()<<std::endl;
    
    bytetype mb=100;
    std::cout<<"mb=100: "<<mb<<std::endl;
 
    return 0;
}
```
	20
	21
	14947210986724563927
	m
	30
	31
	10485857595211860659
	j
	mb=100: 01100100
``` cpp
typedef struct {   
    char name[20];
    char sex; 
    int age; 
} person_t;

main()
{
    person_t p = {"Tom", 'M', 19};
    printf("%s %c %d\n", p.name, p.sex, p.age);
    return 0;
}
//> Tom M 19

```
------------------------------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------------------------
### this pointer
``` cpp
#include <iostream>
#include <string>

struct car
{
    std::string name;
    int year;
    car(){ }
    car(std::string name,int year)
    {
        this ->name = name;
        this ->year = year;
    }
    void getcar()
    {
        std::cout<<name<<" "<<year<<std::endl;
    }

};

int main()
{
    car car1;
    car1.year = 2005;
    car1.name = "Toyota"; 
    car1.getcar();  //Toyota 2005 
    return 0;
}
```
------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------
### Preprocessor directives 
	#include<iostream>    //file will be search in a pre-defined location 
	#define CAPACITY 5000  //the preprocessor will replace everything with 5000
	

------------------------------------------------------------------------------------------------------------	
### Type casting 
	-  Explicitly specifying the data type of an expression.
	-  Suppose you want to have several lines of code that print data out for debugging purposes, but you don't want those lines to make it to the final application, for efficiency reasons. Which of the following achieves the desired behavior by using preprocessor directives?

------------------------------------------------------------------------------------------------------------
### DEBUGGING
	// comment the following line for the final application 
	#define DEBUGGING 

	// copy and customize this for every debugging line 
	#ifdef DEBUGGING 
	cout<<"Var1 = "<<var1<<endl; 
	#endif
------------------------------------------------------------------------------------------------------------
- pragma once **vs** #ifdef CAR_H .... #define CAR_H.....#endif //CAR_H (include gard)
- class and struct keywords: Used to define classes and structures.
- Member variables: Data attributes stored within a class.
- Member functions: Methods that define the behavior of objects.
- Access specifiers: public, private, and protected to control member visibility.
- Constructors and destructors: Special methods to initialize and clean up objects.
- Inheritance: class Derived : public Base to create derived classes.
- Polymorphism: Achieved through virtual functions and dynamic dispatch.
- Operator overloading: Defining custom behaviors for operators like +, -, ==, etc.
- Templates: Used to create generic classes and functions.
- Namespaces: Used for organizing and managing code.
- Links
	[google C++ style guide](https://google.github.io/styleguide/cppguide.html)
	[C++ projects](https://github.com/practical-tutorials/project-based-learning#cc)
	[Calculator project](https://github.com/microsoft/calculator) 
------------------------------------------------------------------------------------------------------------
**Review code**
```cpp
// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`

    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
}
```

----------------------------------------------------------------------------------------------------------------

