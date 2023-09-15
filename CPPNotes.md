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

<<<<<<< Updated upstream
=======

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

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
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

#### 2.4.5

#### Smart Pointers
1 Unique pointer - 
2 auto_ptr - 
3 shared_ptr - 
4 weak_ptr - 



Pointers: https://www.tutorialspoint.com/cplusplus/cpp_pointers.htm 
    Sr.No 	Concept & Description
1 	Null Pointers

C++ supports null pointer, which is a constant with a value of zero defined in several standard libraries.
2 	Pointer Arithmetic

There are four arithmetic operators that can be used on pointers: ++, --, +, -
3 	Pointers vs Arrays

There is a close relationship between pointers and arrays.
4 	Array of Pointers

You can define arrays to hold a number of pointers.
5 	Pointer to Pointer

C++ allows you to have pointer on a pointer and so on.
6 	Passing Pointers to Functions

Passing an argument by reference or by address both enable the passed argument to be changed in the calling function by the called function.
7 	Return Pointer from Functions

C++ allows a function to return a pointer to local variable, static variable and dynamically allocated memory as well.
-----------------------------------------------------------------------------------------------
## 3 Object Oriented programming

Introduction to OPPs in C++

Object-oriented programming (OOP) is a programming paradigm based on the concept of "objects", which can contain **data** and **code**: data in the form of fields (often known as attributes or properties), and code, in the form of procedures (often known as methods).¹ C++ is an object-oriented programming language that allows you to create classes that encapsulate data and functions. Classes are user-defined types that can be used to create objects. 

**class** = is a blueprint for an object, which defines its data members and member functions.
**Object** = an instance of a class that contains **data** and **functions**. aka grouped data
**Methods** = the procedures that an object performs 

In C++, OOP provides several advantages over procedural programming such as faster and easier execution, clear structure for programs, helps keep the code DRY (Don't Repeat Yourself), makes the code easier to maintain, modify and debug, and makes it possible to create full reusable applications with less code and shorter development time.

What is an **instance**? In object-oriented programming (OOP), an instance is a specific realization of any object. An object may be different in several ways, and each realized variation of that object is an instance. The creation of a realized instance is called **instantiation**.????
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
----------------------------------------------------------------------------------------------------------------------
### 3.1 Structure 
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
### 3.2 enum
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
### 3.3 Classes and obj
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


**Access Modifiers in C++**
**Constructor in C++**
**Encapsulation in C++**
**Abstraction in C++**
**Inheritance in C++**
**Polymorphism in C++**
- **Construcror**:
-  **Destructor**
- **Operator Overload**:
==================================================================================================================================================================
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
### Typedef 
-typedef statement to create an alias for a type
-syntax: 
	typedef existing_data_type new_data_type

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
### this pointer

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

