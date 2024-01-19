
# Basics of C++
--------------------------------------------------------------------------
## 0. Topics
REVIEW LIST:
	- 	Dot and pointer operators
	- 	public and private access modifers 
	- 	methods,Constructors and destructors
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
------------------------------------------------------------------------------------------------------------

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
------------------------------------------------------------------------------------------------------------

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
### The Rule of 5 in modern C++
The Rule of 5 in modern C++ refers to a set of guidelines related to resource management and object semantics. It complements the Rule of 3 (which involves implementing custom destructors, copy constructors, and copy assignment operators) by extending it to handle move semantics.

The Rule of 5 members: 
- destructor, 
- copy constructor, 
- copy assignment operator, 
- move constructor, and 
- move assignment operator.
These ensure proper resource management and efficient handling of objects in C++.

As of C++11, with the introduction of move semantics and move constructors/move assignment operators, the Rule of 5 is as follows:

1. **Destructor (`~MyClass()`):**
   - Implement a destructor to clean up resources when an object is destroyed.

2. **Copy Constructor (`MyClass(const MyClass&)`):**
   - Implement a copy constructor to perform a deep copy of resources from one object to another.

3. **Copy Assignment Operator (`MyClass& operator=(const MyClass&)`):**
   - Implement a copy assignment operator to handle proper resource cleanup and deep copying when assigning one object to another.

4. **Move Constructor (`MyClass(MyClass&&) noexcept`):**
   - Implement a move constructor to transfer ownership of resources from a temporary object (rvalue) to the current object.

5. **Move Assignment Operator (`MyClass& operator=(MyClass&&) noexcept`):**
   - Implement a move assignment operator to transfer ownership of resources when moving from one object to another.

Here's a brief example demonstrating the Rule of 5 in action:

```cpp
#include <iostream>

class MyClass {
private:
    int* ptr;

public:
    // Constructor
    MyClass(int value) {
        ptr = new int(value);
    }

    // Destructor
    ~MyClass() {
        delete ptr;
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        ptr = new int(*other.ptr);
    }

    // Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other)
            return *this;

        // Delete existing memory
        delete ptr;

        // Allocate new memory and copy value
        ptr = new int(*other.ptr);

        return *this;
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;  // Reset the source object's pointer
    }

    // Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this == &other)
            return *this;

        // Delete existing memory
        delete ptr;

        // Transfer ownership of the pointer
        ptr = other.ptr;
        other.ptr = nullptr;  // Reset the source object's pointer

        return *this;
    }

    void displayValue() const {
        std::cout << "Value: " << (ptr ? *ptr : 0) << std::endl;
    }
};

int main() {
    MyClass obj1(42);
    obj1.displayValue();

    MyClass obj2 = obj1;  // Copy constructor
    obj2.displayValue();

    MyClass obj3(10);
    obj3.displayValue();

    obj3 = obj1;  // Copy assignment operator
    obj3.displayValue();

    MyClass obj4(std::move(obj1));  // Move constructor
    obj4.displayValue();
    obj1.displayValue();  // After move, obj1 should have nullptr

    MyClass obj5(99);
    obj5 = std::move(obj2);  // Move assignment operator
    obj5.displayValue();
    obj2.displayValue();  // After move, obj2 should have nullptr

    return 0;
}
```

------------------------------------------------------------------------------------------------------------
### Naming conventions
In C++, there are several naming conventions that developers commonly follow to enhance code readability and maintainability. While different projects or organizations might adopt slightly different conventions, there are some widely accepted practices. Here are some common naming conventions in C++:

1. **CamelCase for Identifiers:**
   - Classes and structs: `MyClass`, `MyStruct`
   - Functions and methods: `myFunction()`, `calculateTotal()`
   - Variables: `myVariable`, `totalCount`

2. **PascalCase for Type Names:**
   - Class and struct names should start with an uppercase letter: `MyClass`, `MyStruct`

3. **ALL_CAPS for Constants:**
   - Constants and macros should be in uppercase with underscores separating words: `MAX_VALUE`, `PI`

4. **Underscore Prefix/Suffix for Member Variables:**
   - Some developers prefer using underscores as a prefix or suffix for member variables to distinguish them from local variables or parameters: `myVariable_`, `_myVariable`

5. **Namespace Naming:**
   - Namespaces should be in lowercase and follow the CamelCase convention: `namespace myNamespace { /* ... */ }`

6. **File Naming:**
   - File names should be in lowercase and may use underscores or hyphens to separate words: `my_file.cpp`, `utility_functions.h`

7. **Function Overloading with Meaningful Names:**
   - When overloading functions, use names that convey the difference in functionality: `calculateArea(float radius)`, `calculateArea(float length, float width)`

8. **Abbreviations and Acronyms:**
   - Abbreviations and acronyms should be capitalized consistently: `XMLParser`, `calculateHTTPResponse`

9. **Booleans with Is/Has Prefix:**
   - Boolean variables and functions returning a boolean should use names that suggest a true/false condition: `isEnabled`, `hasData`

10. **Avoid Single-Letter Names:**
    - Except for loop indices and some other specific cases, it's generally better to use descriptive names instead of single-letter variables or functions.

Remember that consistency within a codebase is crucial. If you're working on a project, it's essential to follow the established conventions to maintain code uniformity. Additionally, these conventions are not strict rules but are widely adopted guidelines to improve code readability and maintainability.

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
 ### Libraries(static Vs dynamic)
 - There are two parts in a library usually: includes and libraries. İnclude directory has a bunch of header files and lib directory has those pre-built binaries.
- Dynamic library is loaded(linked) into program at runtime, dynamic library can be anywhere and you do the linking whereas static library is put(compiled) into your executable program
- We have to point our compiler to header files (include files) and then we also have to point out our linker to library files.
------------------------------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------------------------
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
	- Allocation
 	- Deallocation
  	- Lifetime management 
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
- smart pointers only point to heap memory
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
- can not be assigned or copied, However can be moved
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
- working
```cpp

#include <iostream>
#include <memory>
#include <string>
class Account
{
    public:
    Account(std::string name, double balance)
    {
      this -> name = name; 
      this -> balance = balance;
    }
    
     // Getter for balance
    double getBalance() const {
        return balance;
    }
    
    int deposit()
    {
       return 0; 
    }
    int withdraw()
    {
      return 0;  
    }
    
     // Overloaded << operator
    friend std::ostream& operator<<(std::ostream& os, const Account& account) {
        os << "Account Holder: " << account.name << "\n";
        os << "Balance: $" << account.balance << "\n";
        return os;
    }
    
    ~Account()
    {
        
    };
    private:
    std::string name;
    double balance;
};

int main()
{
    std::unique_ptr<Account> p1 {new Account{"Larry", 20.0}};
    std::cout<<*p1<<std::endl;
    return 0;
}

//error: std::default_delete<Account>::operator()(Account*) const
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

```cpp

#include <iostream>
#include <memory>
#include <vector>

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
    
    
    std::vector<std::unique_ptr<int>> vec;
    std::unique_ptr<int> ptr{new int{100}};
    
    //vec.push_back(ptr);//ERROR- COPY NOT ALLOWED
    
    vec.push_back(std::move(ptr));
    
    return 0;
} //p1 is out of scope , its automatically deleted

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
//dog.h exercise
#ifndef __DOG_H__
#define __DOG_H__
#include <string>
using namespace std;

class Dog {
private:
    string name;
    int age;
public:

//---- WRITE YOUR CLASS FUNCTIONS BELOW THIS LINE----
string get_name()
{
  return name;
}
string set_name(string name)
{
     return this -> name = name;  
}

int get_age()
{
  return age;
}
int set_age(int age)
{
   return this -> age = age;  
}

//---- WRITE YOUR CLASS FUNCTIONS ABOVE THIS LINE----
};
#endif 

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
``` cpp 
class Line {
   public:
      void setLength( double len );
      double getLength( void );
      Line();  // This is the constructor
   private:
      double length;
};
 ```
```cpp
class Account {
private:
    // attributes
    std::string name;
    double balance;
public:
	//Constructor
	Account(); //no args constructor
	Account(std::string name);
	Account(std::string name,double balance);
```
 
Destructor: 
Like a constructor, Destructor is also a member function of a class that has the same name as the class name preceded by a tilde(~) operator. It helps to deallocate the memory of an object. It is called while the object of the class is freed or deleted. In a class, there is always a single destructor without any parameters so it can’t be overloaded. It is always called in the reverse order of the constructor. if a class is inherited by another class and both the classes have a destructor then the destructor of the child class is called first, followed by the destructor of the parent or base class. 
Syntax:  
  ~ClassName()
   { 
       //Destructor's Body
   }
 
 ```cpp
class Account {
private:
    // attributes
    std::string name;
    double balance;
public:
	//Constructor
	Account(); //no args constructor
	Account(std::string name);
	Account(std::string name,double balance);
	//Destructor
	~Account();
```
#### 3.5  The Default Constructor

	• Doesn’t expect no argument 
	• Called when you instance a new obj
```	cpp
Class player{
player ((std::string name, int val, int num ) 
{
	name=name_val;
 	health=health_val;
  	num=num=val;
};
 
};


Int main(){
Player frank;  //doesn’t work, Default Constructor will not automatically be generated. 
Player frank{"frank,100,13"};
Frank.set_name{"Frank"};
}
``` 
 
#### 3.6 Overloading Constractors
```cpp
//player.h
Class player{
private:
	std::string name;
    int health;
    int xp;
public: 
//overloaded constructors 
Player ();
Player(std::string name);
player (std::string name, int health, int xp ) ;
};
```
```cpp
//player.cpp
#include "player.h"

Player::Player() {
        name = "None";
        health = 0;
        xp = 0;
    }
Player::Player(std::string name) {
       this -> name = name;
        health = 100;
        xp = 3;
    }
Player::Player(std::string name_val, int health_val, int xp_val) {
        name = name_val;
        health = health_val;
        xp = xp_val;
    }

```
```cpp
//main.cpp

int main() {
    Player empity;
    Player hero{"Hero"};
    Player frank {"Frank", 100, 13};
    
    Player *enemy=new Player("");
    return 0;
}


```
#### 3.7 Constructor Initialization lists 

- initalize lit immediately follows parameter list
- are more efficient
```cpp
//Previous way
Player::Player() {
        name = "None";//this is assignment not initalization
        health = 0;
        xp = 0;
    }
```
```cpp
//better way
Player::Player() 
    : name{"None"}, health{0}, xp{0} { //this is initalization
}

```
```cpp
// Section 13
// Constructor Initialization Lists
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
   std::string name {"XXXXXXX"};
   int health;
   int xp;
public:
// Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player() 
    : name{"None"}, health{0}, xp{0} {
}

Player::Player(std::string name_val) 
   : name{name_val}, health{0}, xp{0} {
}
  
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
    
}

int main() {
    
    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
    
    return 0;
}
```
 ```cpp
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

#### 3.8 Delegating Constructors
 
To minimize duplicated code
 #efficient

 ```cpp
//Constructor Initialization list
Player::player() 
	: name{'none'},health{0},xp{0} { }
	 
//To Delegating Constructors
Player::player() 
	: player{'none',0,0} { }
 
```
```cpp 
Player::player(std::string name_val) 
	: name{name_val},health{0},xp{0} { }
To Delegating Constructors
Player::player(std::string name_val) 
	: player{name_val,0,0} { }
	 
```
``` cpp
Player::player(std::string name_val, int health_val, int xp_val) 
		: name{name_val},health{health_val},xp{xp_val} { }
	 
//To Delegating Constructors  //you keep the deligated constructor 
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
            cout << "Three-args constructor" << endl;
}
```
```cpp
// Section 13
// Delegating Constructors
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
   std::string name;
   int health;
   int xp;
public:
// Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player() 
    : Player {"None",0,0} {
        cout << "No-args constructor" << endl;
}

Player::Player(std::string name_val) 
   : Player {name_val,0, 0}  {
           cout << "One-arg constructor" << endl;
}
  
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
            cout << "Three-args constructor" << endl;
}

int main() {
    
    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
    
    return 0;
}

```
#### 3.9 Constructor Parameters and Default Values
  
- Just like default function
- to reduce number of overloaded constructors
 
 ```cpp
Class Player{
 
Public: 
Player::Player(std::string name_val = "none", 
                        int health_val = 0, 
                        int xp_val =0)
 
}
```



```cpp
// Section 13
// Delegating Constructors
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
   std::string name;
   int health;
   int xp;
public:
    // Delegating Constructors here
    Player(std::string name_val="None", int health_val=0, int xp_val=0);
    std::string getname()
    {
        return name;
    }
    int gethealth()
    {
        return health;
    }
    int getxp()
    {
        return xp;
    }
};

 // Delegating Constructors 
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
            //cout << "Three-args constructor" << endl;
}

int main() {
    
    Player empty;
    std::cout<< empty.getname()<<'\n';      //none
    std::cout<< empty.gethealth()<<'\n';    //0
    std::cout<< empty.getxp()<<'\n';        //0
    
    Player frank {"Frank"};
    std::cout<< frank.getname()<<'\n';      //Frank
    std::cout<< frank.gethealth()<<'\n';    //0
    std::cout<< frank.getxp()<<'\n';        //0
    
    
    Player bob{"Bob",20};
    std::cout<< bob.getname()<<'\n';        //Bob
    std::cout<< bob.gethealth()<<'\n';      //20
    std::cout<< bob.getxp()<<'\n';          //0
    
    Player villain {"Villain", 100, 55};
    std::cout<< villain.getname()<<'\n';    //villan
    std::cout<< villain.gethealth()<<'\n';  //100
    std::cout<< villain.getxp()<<'\n';      //55
    
    
    return 0;
}
```
#### 3.10 Copy Constructor
- when objects are copied C++ must create a new object from an existing object. 
- used to initialize the members of a newly created object by copying the members of an already existing object.
- when is a cioy of an object made?
    - when Passing an obj by value as a parameter 
    - Returning an object from a fun by value 
    - Constructing one obj based on another of same class. 

- Declaring the copy constructor
eg.
```cpp
    Type::Type(const Type &source);
    Player::Player(const Player &source);
    Account::Account(const Account &source);
```
- Implementing copy constructor 
```cpp
    Type::Type(const Type &source)
    {
        ....
    }
```
```cpp
Player villain {"Villain", 100, 55};

void display_player(Player p)
{
    //p is a copy of hero object
    //p is local to the function
    //when p is out of scope the Destructor is called
}

display_player(hero);

```	 
 ```cpp			
 	// Section 13
// Copy Constructor
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
   std::string name;
   int health;
   int xp;
public:
    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() {return xp; } 
    // Delegating Constructors
    Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
    // Copy constructor
    Player(const Player &source);
    // Destructor
    ~Player() { cout << "Destructor called for: " << name << endl; }
};

Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
            cout << "Three-args constructor for " + name << endl;
}
//copy constructor
Player::Player(const Player &source)
   // : name(source.name), health(source.health), xp{source.xp} {
       : Player {source.name, source.health, source.xp}  {
        cout << "Copy constructor - made copy of: " << source.name << endl; 
}

void display_player(Player p) {
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;    
}

int main() {    
    Player empty {"XXXXXX", 100, 50};
    
    Player my_new_object {empty};
    
    display_player(empty);
    
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};
        
    return 0;
}
 ```		
#### 3.11 Shallow Copying with the Copy Constructor
 
- consider a class that contains a pointer as a data member
- constructor allocates atorage dynamically and initalizes the pointer
- destructor releases the memory allocated by the constructor 
- what happens in the default copy constructor?
- we can do deep or shallow copy.
- memberwise copy
- each data member is copied from the source subject
- the pointer is copied not what it points to(shallow copy)
- **problem** when we release the storage in the destructor, the other object still refers to the released storage! 
Soln - deep copy to avoid the error. 

    - example 
```cpp
        class Shallow
        {
            private:
                int *data;   //pointer data mamber
            public: 
                Shallow(int d); //constructor
                Shallow(const shallow &source); //copy constructor
                ~Shallow();     //destructor
        };
 ```
```cpp
    //constructor
    Shallow::Shallow(int d)
    {
        data=new int //allocate storage
        *data=d;
    }

    //since we allocate dynamically, lets be sure to deallocate the memory
    ~Shallow::Shallow()
    {
        delete data; //free storage
        std::cout<<"Destructor freeing data"<<endl;
    }

    //shallow copy constructor

    Shallow::Shallow(const Shallow &source):data(source.data)
    {
        std::cout<<"copy constructor - shallow"<<'\n'; 
    }

```
- **shallow copy** only the pointer is copied, not what it is pointing to.
- **Problem:** source and the newley created object BOTH point to the same **data**!!! so when destructor called the object s is pointing to  invalid data and cant be accessable. 

```cpp
// Section 13
// Copy Constructor - Shallow Copy
// Note: this program will crash
#include <iostream>

using namespace std;

class Shallow {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    // Destructor
    ~Shallow();
};
//constructor
Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}
//copy constructor
Shallow::Shallow(const Shallow &source) //copying the pointer not what its pointing to
    : data(source.data) {
        cout << "Copy constructor  - shallow copy" << endl;
}
//Descructor
Shallow::~Shallow() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s) {
    cout << s.get_data_value() << endl;
}

int main() {
    
    Shallow obj1 {100};
    display_shallow(obj1);//willl crash here ,Shallow s is freed so the object s is pointing to  invalid data
    
    Shallow obj2 {obj1};
    obj2.set_data_value(1000);
    
    return 0;
}



```

When a class contains a pointer as a data member, it's important to manage the pointer properly to prevent memory leaks and ensure proper behavior. You typically need to consider the following:

1. **Constructor and Destructor:**
   - In the constructor, allocate memory for the pointer (e.g., using `new`).
   - In the destructor, deallocate the memory (e.g., using `delete`).

2. **Copy Constructor and Assignment Operator:**
   - Define a copy constructor and an assignment operator to handle deep copying of the pointer when instances of the class are copied or assigned.

Here's a simple example demonstrating these concepts:

```cpp
#include <iostream>

class MyClass {
private:
    int* ptr;

public:
    // Constructor
    MyClass(int value) {
        ptr = new int(value);
    }

    // Destructor
    ~MyClass() {
        delete ptr;
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        ptr = new int(*other.ptr);
    }

    // Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other)
            return *this;

        // Delete existing memory
        delete ptr;

        // Allocate new memory and copy value
        ptr = new int(*other.ptr);

        return *this;
    }

    void displayValue() const {
        std::cout << "Value: " << *ptr << std::endl;
    }
};

int main() {
    MyClass obj1(42);
    obj1.displayValue();

    MyClass obj2 = obj1;  // Copy constructor
    obj2.displayValue();

    MyClass obj3(10);
    obj3.displayValue();

    obj3 = obj1;  // Assignment operator
    obj3.displayValue();

    return 0;
}
```

In this example:
- `MyClass` has a pointer to an integer as a data member.
- The constructor allocates memory for the integer.
- The destructor deallocates the memory.
- The copy constructor and assignment operator handle deep copying to ensure each object has its own memory for the integer.

It's important to follow the rule of three (or rule of five in modern C++) when dealing with classes that manage resources like pointers to prevent memory leaks and undefined behavior.


Depending upon the resources like dynamic memory held by the object, either we need to perform Shallow Copy or Deep Copy in order to create a replica of the object. In general, if the variables of an object have been dynamically allocated, then it is required to do a Deep Copy in order to create a copy of the object.
```cpp
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
```	
#### 3.12 Deep Copying with the Copy Constructor (study more)
 In Deep copy, an object is created by copying data of all variables, and it also allocates similar memory resources with the same value to the object. In order to perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as well, if required. Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.


``` cpp
// Copy Constructor - Deep Copy
#include <iostream>

using namespace std;

class Deep {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Deep(int d);
    // Copy Constructor
    Deep(const Deep &source);
    // Destructor
    ~Deep();
};


  // Shallow constructor
    // Shallow::Shallow(int d)
    // {
    //     data=new int //allocate storage
    //     *data=d;
    // }

Deep::Deep(int d) {
    data = new int; //added this for deep
    *data = d;
    std::cout<<"inside Deep Constructor data: "<<*data<<" addr: "<<data<<'\n';
}

//copy Shallow constructor
//Shallow::Shallow(const Shallow &source) //copying the pointer not what its pointing to
//    : data(source.data) {
//        cout << "Copy constructor  - shallow copy" << endl;
//}

//copy Deep constructor
Deep::Deep(const Deep &source)
    : Deep {*source.data} {
    cout << "inside Copy constructor - deep copy: " <<*source.data<<" addr: "<<&source<< endl;
}

Deep::~Deep() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_deep(Deep s) {
    cout << s.get_data_value() << endl;
    
}

int main() {
    
    Deep obj1 {100}; //inside Deep Constructor data: 100 addr: 0x55c2040442e0
    display_deep(obj1);  //inside Copy constructor - deep copy: 100 addr: 0x7ffca68fc4e8
                            //100
                        //Destructor freeing data
    
    Deep obj2 {obj1};  //inside Deep Constructor data: 100 addr: 0x55c2040442e0
                        //inside Copy constructor - deep copy: 100 addr: 0x7ffca68fc4e8
                        
    obj2.set_data_value(1000);   
    std::cout<<"new obj2 val: "; display_deep(obj2);  //new obj2 val: inside Deep Constructor data: 1000 addr: 0x55da55476300
                                               //inside Copy constructor - deep copy: 1000 addr: 0x7ffdc47209a8
                                               //Destructor freeing data
                                                //Destructor freeing data
                                                //Destructor freeing data

    return 0;
}

```
```
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

```
Let us see the differences in a tabular form -:

 	Shallow Copy 	|     Deep copy
1. |	When we create a copy of object by copying data of all member variables as it is, then it is called shallow copy  |	When we create an object by copying data of another object along with the values of memory resources that reside outside the object, then it is called a deep copy
2. |	A shallow copy of an object copies all of the member field values. |	 Deep copy is performed by implementing our own copy constructor.
3. |	In shallow copy, the two objects are not independent |	It copies all fields, and makes copies of dynamically allocated memory pointed to by the fields
4. |	It also creates a copy of the dynamically allocated objects |	If we do not create the deep copy in a rightful way then the copy will point to the original, with disastrous consequences.


#### 3.13 Move Constructors (study more)
	- Study L value and R value
 - copy constructors doing deep coping can have a performance bottleneck. 
 - Optional but recommended when you have raw pointer
 - moves an object rather than copying it.

R value referances
 - they use && operator
 - used in moving semantics and perfect forwarding
```cpp
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
 void func(int &num) //l value
{
    std::cout<<num<<std::endl;
}

void func(int &&num)//R value 
{
    std::cout<<num<<std::endl;
}


int main()
{
    int x{100};
    
    int &l_ref=x; //l value referance
    l_ref=10;    //change x to 10
    
    int &&r_ref=200; //r-value ref
    r_ref=300;  //change r_ref to 300
    
    //int &&x_ref=x;  //compiler error
    //error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
    
    int y{5000};
    func(y);  //calls l-value  //5000
    func(200); //calls r- value  //200
    
    return 0;
}

```

```cpp
// Section 13
// Move Constructor 
#include <iostream>
#include <vector>

using namespace std;

class Move {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Move(int d);
    // Copy Constructor
    Move(const Move &source);
    // Move Constructor
    Move(Move &&source) noexcept;
    // Destructor
    ~Move();
};

 Move::Move(int d)  {
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

// Copy ctor
Move::Move(const Move &source)
    : Move {*source.data} {
        cout << "Copy constructor  - deep copy for: " << *data << endl;
}

//Move ctor
Move::Move(Move &&source) noexcept 
    : data {source.data} {
        source.data = nullptr;
        cout << "Move constructor - moving resource: " << *data << endl;
}

Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor freeing data for: " << *data << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

int main() {
    vector<Move> vec;

    vec.push_back(Move{10});

    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
     vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});


    return 0;
}


```
 
#### 3.14 The 'this' Pointer

To understand ‘this’ pointer, it is important to know how objects look at functions and data members of a class.
1. Each object gets its own copy of the data member. to access data members and methods. 
2. All-access the same function definition as present in the code segment.
```cpp
void Account::set_balance(double balance)
{
balance=balance; //which balance??? very confusing
}

void Account::set_balance(double balance)
{
this->balance =balance; //Unambiguous
}
```


Meaning each object gets its own copy of data members and all objects share a single copy of member functions.
Then now question is that if only one copy of each member function exists and is used by multiple objects, how are the proper data members are accessed and updated?
The compiler supplies an implicit pointer along with the names of the functions as ‘this’.
The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions. ‘this’ pointer is not available in static member functions as static member functions can be called without any object (with class name).

For a class X, the type of this pointer is ‘X* ‘. Also, if a member function of X is declared as const, then the type of this pointer is ‘const X *’ (see this GFact)
In the early version of C++ would let ‘this’ pointer to be changed; by doing so a programmer could change which object a method was working on. This feature was eventually removed, and now this in C++ is an r-value.
C++ lets object destroy themselves by calling the following code :
```cpp
delete this;
```
As Stroustrup said ‘this’ could be the reference than the pointer, but the reference was not present in the early version of C++. If ‘this’ is implemented as a reference then, the above problem could be avoided and it could be safer than the pointer.
Following are the situations where ‘this’ pointer is used:
1) When local variable’s name is same as member’s name
```cpp
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
```

2) To return reference to the calling object
```cpp
/* Reference to the calling object can be returned */ 
Test& Test::func ()
{
   // Some processing
   return *this;
}
```
When a reference to a local object is returned, the returned reference can be used to chain function calls on a single object.
```cpp
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
```
Every object in C++ has access to its own address through an important pointer called this pointer. The this pointer is an implicit parameter to all member functions. Therefore, inside a member function, this may be used to refer to the **invoking object**.
Friend functions do not have a this pointer, because friends are not members of a class. Only member functions have a this pointer.
Let us try the following example to understand the concept of this pointer −

From <https://www.tutorialspoint.com/cplusplus/cpp_this_pointer.htm> 

```cpp
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
```
From <https://www.tutorialspoint.com/cplusplus/cpp_this_pointer.htm> 

C++ this Pointer
In C++ programming, this is a keyword that refers to the current instance of the class. There can be 3 main usage of this keyword in C++.
	• It can be used to pass current object as a parameter to another method.
	• It can be used to refer current class instance variable.
	• It can be used to declare indexers.

C++ this Pointer Example
Let's see the example of this keyword in C++ that refers to the fields of current class.
```cpp
 #include <iostream>  
using namespace std;  
class Employee {  
    public:  
        int id; //data member (also instance variable)      
        string name; //data member(also instance variable)  
        float salary;  
        Employee(int id, string name, float salary)    
         {    
              this->id = id;    
             this->name = name;    
             this->salary = salary;   
         }    
        void display()    
         {    
             cout<<id<<"  "<<name<<"  "<<salary<<endl;    
         }    
 };  
 int main(void) {  
     Employee e1 =Employee(101, "Sonoo", 890000); //creating an object of Employee   
     Employee e2=Employee(102, "Nakul", 59000); //creating an object of Employee  
     e1.display();    
     e2.display();    
     return 0;  
 } 

From <https://www.javatpoint.com/cpp-this-pointer>
```

this pointer example
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


#### 3.15 Using const with Classes(study more)
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
``` Cpp
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
```
```cpp
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
```
```cpp
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
```
When a function is declared as const, it can be called on any type of object. Non-const functions can only be called by non-const objects. 
For example the following program has compiler errors.  

```cpp
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
```

// Demonstration of constant object,
// show that constant object can only
// call const member function
```cpp
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
    Player()
    {
        
    }
    
    Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
            std::cout << "Three-args constructor for " + name << std::endl;
    }


    void talk(std::string name,int health, int xp);
    bool is_playing();
    
    void set_name(std::string name)
    {
        this-> name=name;
    }
    
    std::string get_name() { return name; }
    
    std::string get_name_const() const 
    {
        return name;
    }
    
 
private:
    // attributes
    std::string name;
    int health;
    int xp;

};

void display_player_name_const(const Player &p)
    {
        std::cout<<p.get_name_const()<<std::endl;
    }
    
void display_player_name(Player &p)
    {
        std::cout<<p.get_name_const()<<std::endl;
    }
int main()
{
    const Player Constvillain {"villain",100,55};
    //Constvillain.set_name("abc");  //error: passing ‘const Player’ as ‘this’ argument discards qualifiers [-fpermissive]
    //std::cout<<Constvillain.get_name()<<std::endl; //error: passing ‘const Player’ as ‘this’ argument discards qualifiers [-fpermissive]
    
    Player nonConstVillain {"non-villain",100,55};//
    nonConstVillain.set_name("cdf"); //
    std::cout<<nonConstVillain.get_name()<<std::endl; //cdf

   // display_player_name(nonConstVillain);//main.cpp:33:30: error: passing ‘const Player’ as ‘this’ argument discards qualifiers [-fpermissive]
    //solution lets set std::string get_name_const() const;
    
    display_player_name(nonConstVillain);//cdf
    
    display_player_name_const(nonConstVillain);//cdf//we can view but not modify this method is better: std::string get_name_const() const 
    return 0;
}
```
#### 3.16  Static Class Members

- class data members can be declared as static
  	- a singme data member that belongs to the class, not objects
  	- useful to store class-wide information
-class functions can be declared as static
	- independent of any objects
 	- can be called using the class name
```cpp
class player{
private:
	static int num_players;
public:
	static 
};

```
In C++, static class members are shared among all instances of a class rather than being specific to each instance. There are several use cases for static class members, providing features and functionalities that are shared across all instances of a class:

1. **Shared Data:**
   - Static members can be used to represent shared data that is common to all instances of a class. For example, a counter that keeps track of the number of instances created:

     ```cpp
     class MyClass {
     private:
         static int instanceCount;  // Shared data

     public:
         MyClass() {
             ++instanceCount;
         }

         static int getInstanceCount() {
             return instanceCount;
         }
     };

     // Initialize the static member
     int MyClass::instanceCount = 0;
     ```

     In this example, `instanceCount` is shared among all instances of `MyClass`, and the constructor increments it each time a new instance is created. The static member function `getInstanceCount` allows accessing the shared data.

2. **Constants:**
   - Static members can be used to define constants that are associated with a class, rather than with instances. For example:

     ```cpp
     class MathConstants {
     public:
         static const double PI;
         static const double E;
     };

     // Initialize the static constants
     const double MathConstants::PI = 3.14159265358979323846;
     const double MathConstants::E = 2.718281828459045;
     ```

     Here, `PI` and `E` are constants associated with the `MathConstants` class, and they are shared among all instances.

3. **Shared Functions:**
   - Static member functions can be used to implement functionality that does not depend on specific instance data. These functions can be called without creating an instance of the class.

     ```cpp
     class Utility {
     public:
         static void doSomething() {
             // Functionality not tied to instance data
         }
     };
     ```

     The `doSomething` function can be called using the class name without creating an instance: `Utility::doSomething()`.

4. **Singleton Pattern:**
   - Static members are often used in the implementation of the Singleton design pattern, ensuring that a class has only one instance and providing a global point of access to it.

     ```cpp
     class Singleton {
     private:
         static Singleton* instance;  // The single instance

         // Private constructor to prevent instantiation
         Singleton() {}

     public:
         static Singleton* getInstance() {
             if (!instance) {
                 instance = new Singleton();
             }
             return instance;
         }
     };

     // Initialize the static member
     Singleton* Singleton::instance = nullptr;
     ```

     The `getInstance` function provides a global point of access to the single instance of the `Singleton` class.

- Static members in C++ provide a way to introduce shared data, constants, and functionalities that are not tied to individual instances of a class. They are part of the class rather than the objects created from it.
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
// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "inside operator overload Copy assignment" << std::endl;
    if (this == &rhs) //check for self assignmwnt, this = lhs
        return *this;  
    delete [] this->str; //deallocate 
    str = new char[std::strlen(rhs.str) + 1]; //allocate storage for deep copy
    std::strcpy(this->str, rhs.str); //perform the 
    return *this; //return by ref to allow chain 
}
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


### 3.5 Inheritance

#### 3.5.1 What is inheritance? 

- provides a method os creating a classes from existing classes
- the new class contains the data and behaviors of the existing class.
- allow the reuse of existing classes
- allows the new class modify beavior of existing class to make it unique without actually modifying the original class.
- Inheritance in C++ is a powerful way to reuse code and build new classes based on existing ones. It allows you to define a base class that contains shared attributes and methods, and then create derived classes that inherit those features and can further specialize them or add their own unique traits.

**1 Base Class**: This is the existing class that provides the foundation for inheritance. It defines the initial set of attributes and methods that will be inherited by derived classes.

**2 Derived Class**: This is a new class that inherits from the base class. It gains access to all the public and protected members of the base class, and can then add its own members or override existing ones to create specialized functionality.

- Inheritance is a fundamental concept in object-oriented programming (OOP) that allows a class (called the "derived" or "child" class) to inherit properties and behaviors from another class (called the "base" or "parent" class). This mechanism promotes code reusability and establishes a relationship between classes.

In C++, the syntax for inheritance is as follows:

```cpp
class BaseClass {
  // Base class members and methods
};

class DerivedClass : public BaseClass {
  // Derived class members and methods
};
```

Here, `DerivedClass` is inheriting from `BaseClass` using the `:` symbol, and the keyword `public` specifies the access level for the inheritance. The `public` keyword means that public members of the base class remain public in the derived class, while protected members remain protected.

There are three types of inheritance in C++:

1. **Public Inheritance:**
   - Public members of the base class become public members of the derived class.
   - Protected members of the base class become protected members of the derived class.

   ```cpp
   class DerivedClass : public BaseClass {
     // ...
   };
   ```

2. **Protected Inheritance:**
   - Public and protected members of the base class become protected members of the derived class.

   ```cpp
   class DerivedClass : protected BaseClass {
     // ...
   };
   ```

3. **Private Inheritance:**
   - Public and protected members of the base class become private members of the derived class.

   ```cpp
   class DerivedClass : private BaseClass {
     // ...
   };
   ```

Inheritance supports the "is-a" relationship, meaning that an object of the derived class can be treated as an object of the base class. This facilitates polymorphism, where objects of different classes can be manipulated using a common interface defined in the base class.

#### 3.5.2  Inheretance VS Composition

- Both allow reuse of Existing Class
- public inheretance
  	- "is-a" relationship
  	- EX. Employee is a person(base class)
  	- EX. CheckingAccount is-a Account
  	- EX Circle is-a shape
  - Composition
    	- Has-a relationship
    	- Person has a Account
    	- Circle has-a location
    	- Player has-a special run
    

In software design, inheritance and composition are two different approaches to building relationships between classes. Let's consider an example with a `Person` class and an `Account` class to illustrate both inheritance and composition.

### Inheritance Example:

```cpp
#include <iostream>
#include <string>

class Account {
public:
    Account(double balance) : balance(balance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

private:
    double balance;
};

class Person : public Account {
public:
    Person(const std::string& name, double balance)
        : Account(balance), name(name) {}

    void display() const {
        std::cout << "Name: " << name << ", Balance: $" << getBalance() << std::endl;
    }

private:
    std::string name;
};

int main() {
    Person person("John Doe", 1000.0);
    person.display();

    person.deposit(500.0);
    person.display();

    person.withdraw(200.0);
    person.display();

    return 0;
}
```

In this example, `Person` is inheriting from `Account`. A `Person` object has access to the `deposit`, `withdraw`, and `getBalance` methods of the `Account` class. The `Person` class adds a `display` method to show additional information.

### Composition Example:

```cpp
#include <iostream>
#include <string>

class Account {
public:
    Account(double balance) : balance(balance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

private:
    double balance;
};

class Person {
public:
    Person(const std::string& name, double balance)
        : name(name), account(balance) {}

    void display() const {
        std::cout << "Name: " << name << ", Balance: $" << account.getBalance() << std::endl;
    }

    void deposit(double amount) {
        account.deposit(amount);
    }

    void withdraw(double amount) {
        account.withdraw(amount);
    }

private:
    std::string name;
    Account account;
};

int main() {
    Person person("John Doe", 1000.0);
    person.display();

    person.deposit(500.0);
    person.display();

    person.withdraw(200.0);
    person.display();

    return 0;
}
```

In this example, `Person` has an instance of the `Account` class as a member variable. `Person` delegates calls to `deposit`, `withdraw`, and `getBalance` to the `Account` class. This is an example of composition.

### Choosing Between Inheritance and Composition:

- **Inheritance:**
  - Useful when you want to model an "is-a" relationship.
  - Can lead to a more natural hierarchy.
  - Can reuse code from the base class.

- **Composition:**
  - Useful when you want to model a "has-a" relationship.
  - Provides better encapsulation.
  - More flexible and allows for easier modification.

The choice between inheritance and composition depends on the specific needs of your design and the relationships between the classes. Often, a combination of both techniques is used to achieve the desired results.


#### 3.5.3 Deriving class from Existing class

C++ derivation syntax

class Base {
	//Base class Members
}
class Derived : access-specifier Base 
{
	//Derived class members
}

In C++, you can create a derived class from an existing class using the syntax:

```cpp
class BaseClass {
    // Base class definition
};

class DerivedClass : public BaseClass {
    // Derived class definition
};
```

Here, `DerivedClass` is derived from `BaseClass` using the `public` access specifier. This means that the public and protected members of `BaseClass` will retain their access levels in `DerivedClass`. If you use `protected` or `private` instead of `public`, the access level of the base class members will be accordingly changed in the derived class.

Here's an example to illustrate this:

```cpp
#include <iostream>

class BaseClass {
public:
    void baseMethod() {
        std::cout << "Base class method\n";
    }
};

class DerivedClass : public BaseClass {
public:
    void derivedMethod() {
        std::cout << "Derived class method\n";
    }
};

int main() {
    DerivedClass derivedObj;

    // Accessing base class method through derived class object
    derivedObj.baseMethod();

    // Accessing derived class method
    derivedObj.derivedMethod();

    return 0;
}
```

In this example, `DerivedClass` is derived from `BaseClass`. Objects of `DerivedClass` can access both the methods of the base class (`baseMethod`) and the methods specific to the derived class (`derivedMethod`). When you run this program, it will output:

```
Base class method
Derived class method
```

Remember that the access specifier (`public`, `protected`, or `private`) determines how the members of the base class are inherited in the derived class. `public` inheritance means that public members stay public, protected members stay protected, and private members remain inaccessible in the derived class.

Certainly! Let's build on the previous example and introduce more advanced concepts such as constructors, destructors, and additional methods. We'll also illustrate method overriding in the derived class.

```cpp
#include <iostream>

class BaseClass {
private:
    int basePrivateData;

protected:
    int baseProtectedData;

public:
    BaseClass() : basePrivateData(0), baseProtectedData(0) {
        std::cout << "Base class constructor\n";
    }

    // A virtual function to be overridden by derived classes
    virtual void displayInfo() const {
        std::cout << "Base class information\n";
    }

    void setBaseData(int privateData, int protectedData) {
        basePrivateData = privateData;
        baseProtectedData = protectedData;
    }

    ~BaseClass() {
        std::cout << "Base class destructor\n";
    }
};

class DerivedClass : public BaseClass {
private:
    int derivedPrivateData;

public:
    DerivedClass() : derivedPrivateData(0) {
        std::cout << "Derived class constructor\n";
    }

    // Override the base class virtual function
    void displayInfo() const override {
        std::cout << "Derived class information\n";
    }

    void setDerivedData(int privateData) {
        derivedPrivateData = privateData;
    }

    ~DerivedClass() {
        std::cout << "Derived class destructor\n";
    }
};

int main() {
    DerivedClass derivedObj;

    // Accessing base class method through derived class object
    derivedObj.setBaseData(10, 20);

    // Accessing derived class method
    derivedObj.setDerivedData(30);

    // Accessing overridden method
    derivedObj.displayInfo();

    return 0;
}
```

In this example:

- The `BaseClass` has a private member (`basePrivateData`) and a protected member (`baseProtectedData`).
- The constructor of `BaseClass` initializes these members, and the destructor prints a message upon destruction.
- `DerivedClass` is derived from `BaseClass` and has its private member (`derivedPrivateData`).
- The constructor of `DerivedClass` initializes its member, and the destructor prints a message upon destruction.
- `DerivedClass` overrides the virtual function `displayInfo` defined in `BaseClass`.
- The `main` function demonstrates creating a `DerivedClass` object, setting data in both the base and derived parts, and invoking overridden methods.

When you run this program, it will output:

```
Base class constructor
Derived class constructor
Derived class destructor
Base class destructor
```

This illustrates the order of construction and destruction in the case of a derived class. The base class is constructed first, then the derived class, and the destructors are called in the reverse order.

```cpp
#include <iostream>
#include <string>
#include <memory>

class Account {
public:
    Account(){
        
    }
    
    Account(double balance) : balance(balance) {
        
    }
    
    ~Account(){
        
    }

    void deposit(double amount) {
        // balance += amount;
        std::cout << "@ base Account deposit: "<<amount<< std::endl;
    }

    void withdraw(double amount) {
        // if (amount <= balance) {
        //     balance -= amount;
        // } else {
            std::cout << "@ base Account withdraw: " <<amount<< std::endl;
        //}
    }

    double getBalance() const {
        return balance;
    }

private:
    double balance;
    std::string name;
};

class Person : public Account {
public:
    Person(const std::string& name, double balance)
        : Account(balance), name(name) {}

    void display() const {
        std::cout << "Name: " << name << ", Balance: $" << getBalance() << std::endl;
    }

private:
    std::string name;
};


class savingsAccount:public Account
{
public:
  savingsAccount(){
      
  };
  
  ~savingsAccount(){
      
  }
  
   void deposit(double amount) {
        //balance += amount;
        std::cout << "@ savingsAccount deposit: " <<amount<<  std::endl;
    }

    void withdraw(double amount) {
        // if (amount <= balance) {
        //     balance -= amount;
        // } else {
            std::cout << "@ savingsAccount withdraw: " << amount<<std::endl;
        //}
    }

    
};

int main() {
   Account account1;
   account1.deposit(100);  //@ base Account deposit: 100
   account1.withdraw(200); //@ base Account withdraw: 200
   
   Account *Ptr_account = new Account();
   Ptr_account->deposit(300);//@ base Account deposit: 300
   Ptr_account->withdraw(400); //@ base Account withdraw: 400
   
   
   std::unique_ptr<Account> unique_ptr_account = std::make_unique<Account>(); 
   unique_ptr_account->deposit(500);//@ base Account deposit: 500
   unique_ptr_account->withdraw(600); //@ base Account withdraw: 600
  
  //---------------------------------------------------------------------
  
  
  savingsAccount savingsaccount1;
  savingsaccount1.deposit(100); //@ savingsAccount deposit: 100
  savingsaccount1.withdraw(200); //@ savingsAccount withdraw: 200
  
  savingsAccount *Ptr_sav_account = new savingsAccount();
  Ptr_sav_account->deposit(300);//@ savingsAccount deposit: 300
  Ptr_sav_account->withdraw(400); //@ savingsAccount withdraw: 400
   
   
   std::unique_ptr<savingsAccount> unique_ptr_sav_account = std::make_unique<savingsAccount>(); 
   unique_ptr_sav_account->deposit(500);//@ savingsAccount deposit: 500
   unique_ptr_sav_account->withdraw(600); //@ savingsAccount withdraw: 600
  
    //---------------------------------------------------------------------

  
    return 0;
}
```


#### 3.5.4 Protected Members and Class Access
Access specifiers (`public`, `protected`, and `private`) determine the visibility of class members (variables and functions) within the class and its derived classes. Here's an example that illustrates the use of these access specifiers:

**Access Specifier**
- public
  
- protected
  
- private  



```cpp
#include <iostream>

// Base class
class BaseClass {
public:    // Public members are accessible from outside the class and its derived classes
    int publicData;

    BaseClass() : publicData(0) {
        std::cout << "BaseClass Constructor\n";
    }

    // Public member function
    void publicMethod() {
        std::cout << "BaseClass publicMethod\n";
    }

protected: // Protected members are accessible within the class and its derived classes, but not from outside
    int protectedData;

    // Protected member function
    void protectedMethod() {
        std::cout << "BaseClass protectedMethod\n";
    }

private:   // Private members are accessible only within the class, not from derived classes or outside
    int privateData;

    // Private member function
    void privateMethod() {
        std::cout << "BaseClass privateMethod\n";
    }

public:
    // Public member function that calls private and protected members
    void accessPrivateAndProtected() {
        std::cout << "Accessing privateData: " << privateData << "\n";
        std::cout << "Accessing protectedData: " << protectedData << "\n";
        privateMethod();
        protectedMethod();
    }

    ~BaseClass() {
        std::cout << "BaseClass Destructor\n";
    }
};

// Derived class
class DerivedClass : public BaseClass {
public:
    void derivedMethod() {
        std::cout << "DerivedClass derivedMethod\n";
    }

    // Public member function that calls base class protected method
    void callProtectedMethod() {
        protectedMethod();
    }
};

int main() {
    // Create an object of the derived class
    DerivedClass derivedObj;

    // Access public members and methods
    derivedObj.publicData = 42;
    std::cout << "Accessing publicData: " << derivedObj.publicData << "\n";
    derivedObj.publicMethod();

    // Access protected members and methods (from within the derived class)
    derivedObj.protectedData = 10;
    std::cout << "Accessing protectedData: " << derivedObj.protectedData << "\n";
    derivedObj.protectedMethod();

    // Accessing base class public and protected members using derived class object
    derivedObj.accessPrivateAndProtected();

    // Accessing a public method that calls a protected method in the base class
    derivedObj.callProtectedMethod();

    return 0;
}
```


In this example:

- `BaseClass` has members with `public`, `protected`, and `private` access specifiers.
- `DerivedClass` is derived from `BaseClass`.
- `main` demonstrates access to these members from both within the class hierarchy and outside.

Remember the key principles:

- `public`: Members are accessible from anywhere.
- `protected`: Members are accessible within the class and its derived classes.
- `private`: Members are accessible only within the class.

Inheritance allows derived classes to access protected and public members of the base class. Access specifiers play a crucial role in controlling the visibility of members in class hierarchies.

-----

In C++, the `protected` access specifier is used to specify that the members (both data members and member functions) declared under this specifier are accessible within the class and its derived classes, but not from outside the class or its derived classes. This allows for a level of encapsulation and controlled access within an inheritance hierarchy.

Here's an example to illustrate the use of `protected` members and class access:

```cpp
#include <iostream>

class BaseClass {
protected:
    int protectedData;

public:
    BaseClass() : protectedData(0) {
        std::cout << "Base class constructor\n";
    }

    // A public member function accessing the protected member
    void setProtectedData(int data) {
        protectedData = data;
    }

    // A public member function displaying information
    void displayInfo() const {
        std::cout << "Base class information: protectedData = " << protectedData << "\n";
    }

    ~BaseClass() {
        std::cout << "Base class destructor\n";
    }
};

class DerivedClass : public BaseClass {
private:
    int derivedPrivateData;

public:
    DerivedClass() : derivedPrivateData(0) {
        std::cout << "Derived class constructor\n";
    }

    // A public member function setting data in both base and derived parts
    void setData(int baseData, int derivedData) {
        setProtectedData(baseData);
        derivedPrivateData = derivedData;
    }

    // Override the base class displayInfo method
    void displayInfo() const override {
        std::cout << "Derived class information: protectedData = " << protectedData
                  << ", derivedPrivateData = " << derivedPrivateData << "\n";
    }

    ~DerivedClass() {
        std::cout << "Derived class destructor\n";
    }
};

int main() {
    DerivedClass derivedObj;

    // Accessing protected member using a public member function
    derivedObj.setProtectedData(10);

    // Accessing derived class method
    derivedObj.setData(20, 30);

    // Accessing overridden method
    derivedObj.displayInfo();

    return 0;
}
```

In this example:

- `BaseClass` has a protected member `protectedData`.
- `DerivedClass` is derived from `BaseClass` and has an additional private member `derivedPrivateData`.
- The `setData` member function of `DerivedClass` sets data in both the base and derived parts.
- The `displayInfo` method is overridden in `DerivedClass` to display information from both base and derived parts.

When you run this program, it will output:

```
Base class constructor
Derived class constructor
Derived class information: protectedData = 20, derivedPrivateData = 30
Derived class destructor
Base class destructor
```

This example demonstrates how protected members can be accessed within a derived class and how the access specifiers affect the visibility of members in different parts of the class hierarchy.

another example: 
```cpp
#include <iostream>

class Base
{
public:
int a{0};

void display()
{
    std::cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<'\n';
}

protected:
int b{0};

private:
int c{0};
};


class Derived: public Base{
// friends of derived class has only access to only what Derived has access to
//a and b are accessable
//c is not accessable

public:
void access_base_members(){
    a=500;
    b=600;
    std::cout<<"a:"<<a<<" b:"<<b<<'\n';
    
    //c is not accessable because its private
    //" c:"<<c<<'\n'; //‘int Base::c’ is private within this context
    //c=600; error: ‘int Base::c’ is private within this context
    
}

};

int main() {
    Base base;
    base.display(); //a:0 b:0 c:0
    
    base.a=100;
    base.display(); //a:100 b:0 c:0
    //base.b{200}; //error: int Base::b’ is protected within this context
    //base.c{300}; //error: ‘int Base::c’ is private within this context
    //---------------------------------------------
    
    Derived derived1;
    derived1.a=400;
    derived1.display(); //a:400 b:0 c:0
    derived1.access_base_members(); //a:500 b:600
    
    
    return 0;
}
```
#### 3.5.5  Constructors and Destructors
#### 3.5.6 Passing Arguments to base class Constructors 
#### 3.5.7 copy/move Constructors and operator = with derived class
#### 3.5.8 Redefining Base Class Methods
#### 3.5.9 Multiple Ingeretance
#### 3.5.10 The updated Account Example


### 3.6 Polymorphism

#### 3.6.1 what is Polymorphism? 
- Polymorphism, meaning "many forms," is a fundamental concept in object-oriented programming that allows objects of different classes to be treated as if they were objects of a common base class. This enables you to write code that is more flexible, reusable, and modular.

Polymorphism is one of the four fundamental principles of object-oriented programming (OOP), along with encapsulation, inheritance, and abstraction. In C++, polymorphism is mainly achieved through two mechanisms: function overloading and virtual functions.

1. **Function Overloading:** or **compile-time Polymorphism **
   - **1.1 Function overloading** allows you to define multiple functions with the same name but with different parameter lists. The compiler determines which function to call based on the number and types of arguments provided. Here's a simple example:

    ```cpp
    #include <iostream>

    class Calculator {
    public:
        int add(int a, int b) {
            return a + b;
        }

        double add(double a, double b) {
            return a + b;
        }
    };

    int main() {
        Calculator calc;
        std::cout << calc.add(5, 7) << std::endl;       // Calls the int version
        std::cout << calc.add(3.5, 4.2) << std::endl;   // Calls the double version

        return 0;
    }
    ```

    In this example, the `add` function is overloaded with different parameter types, and the appropriate version is called based on the argument types during the function call.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Geeks {
public:
    void func (int x) {
        cout << "value of x is " << x << endl;
    }
    void func (double x) {
        cout << "value of x is " << x << endl;
    }
    void func (int x, int y) {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};

int main () {
    Geeks obj1;
    obj1.func (7);
    obj1.func (9.132);
    obj1.func (85, 64);
    return 0;
}

```
- **1.2 Operator Overloading:** C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. Here is an example of operator overloading in C++:

 ```cpp
   #include <iostream>
	using namespace std;

	class Complex {
	private:
    int real, imag;
	public:
    Complex (int r = 0, int i = 0) {
        real = r; imag = i;
    }
    Complex operator+ (Complex const& obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print () {
        cout << real << " + i" << imag << endl;
    }
	};

	int main () {
    Complex c1 (10, 5), c2 (2, 4);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
	}
```
3. **Virtual Functions and Polymorphism:** or ** Runtime polymorphism**
  - This is achieved by function overriding, i.e., when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden
  - Virtual functions enable runtime polymorphism, allowing you to achieve dynamic dispatch. This is accomplished through the use of pointers or references to base class objects. Here's an example:
    

    ```cpp
    #include <iostream>

    class Shape {
    public:
        virtual void draw() {
            std::cout << "Drawing a shape." << std::endl;
        }
    };

    class Circle : public Shape {
    public:
        void draw() override {
            std::cout << "Drawing a circle." << std::endl;
        }
    };

    class Square : public Shape {
    public:
        void draw() override {
            std::cout << "Drawing a square." << std::endl;
        }
    };

    int main() {
        Shape* shape1 = new Circle();
        Shape* shape2 = new Square();

        shape1->draw();   // Calls the draw function of Circle
        shape2->draw();   // Calls the draw function of Square

        delete shape1;
        delete shape2;

        return 0;
    }
    ```

    In this example, the `Shape` class has a virtual function `draw`, and the derived classes `Circle` and `Square` override this function. When you use pointers of the base class type to refer to objects of derived classes, the correct overridden function is called at runtime, achieving polymorphism.

Remember that to enable polymorphism through virtual functions, you need to declare the base class function as `virtual` and use the `override` keyword in the derived class to indicate that you are intentionally overriding a virtual function.

##### **The problem with static binding **

 which occurs when you have a function parameter or pointer/reference of the base class type, and you're passing an object of the derived class. In such cases, the function is bound to the base class version at compile-time.
 
In the below  example, when you call grettings(d);, you're passing a DerivedClass object to a function that expects a BaseClass reference. Therefore, the BaseClass version of say_hello() is called due to static binding.

```cpp
#include <iostream>
#include <memory>

class BaseClass {
  // Base class members and methods
  public:
  void say_hello()
  {
      std::cout<<"Hello - from BaseClass"<<std::endl;
  }
};

class DerivedClass : public BaseClass {
  // Derived class members and methods
    public:
    void say_hello()
    {
         std::cout<<"Hello - from DerivedClass"<<std::endl;
    }
  
};


void grettings( BaseClass &obj)
{
    std::cout<<"Grettings fun called"<<" : ";
    obj.say_hello();
}


int main()
{
    BaseClass b;
    b.say_hello(); //Hello - from BaseClass
    
    DerivedClass d;
    d.say_hello(); //Hello - from DerivedClass
    
    //***********************************
    //the Issue with static binding
    grettings(b); //Grettings fun called : Hello - from BaseClass
    grettings(d); //Grettings fun called : Hello - from BaseClass
    //Also same thing happens when we haVE BASE POINTER
    BaseClass *ptr = new DerivedClass();
    ptr -> say_hello(); //Hello - from BaseClass
    delete ptr;
    //same with smart POINTER
    std::unique_ptr<BaseClass> smart_ptr = std::make_unique<DerivedClass>();
    smart_ptr->say_hello(); //Hello - from BaseClass
    //THIS IS NOT WHAT WE WANT: WE WANTED  DerivedClass 
    //***********************************

    return 0;
}
```

To achieve the desired polymorphic behavior (dynamic binding), you should use pointers or references to the base class with the virtual keyword for the function in the base class. Here's an updated version of your code to demonstrate this:
```cpp
#include <iostream>
#include <memory>

class BaseClass {
public:
    virtual void say_hello() {
        std::cout << "Hello - from BaseClass" << std::endl;
    }
};

class DerivedClass : public BaseClass {
public:
    void say_hello() override {
        std::cout << "Hello - from DerivedClass" << std::endl;
    }
};

void greetings(BaseClass& obj) {
    std::cout << "Greetings function called: ";
    obj.say_hello();
}

int main() {
    BaseClass b;
    b.say_hello(); // Hello - from BaseClass

    DerivedClass d;
    d.say_hello(); // Hello - from DerivedClass

    greetings(b);  // Greetings function called: Hello - from BaseClass
    greetings(d);  // Greetings function called: Hello - from DerivedClass

    BaseClass* ptr = new DerivedClass();
    ptr->say_hello(); // Hello - from DerivedClass
    delete ptr;

    std::unique_ptr<BaseClass> smart_ptr = std::make_unique<DerivedClass>();
    smart_ptr->say_hello(); // Hello - from DerivedClass

    return 0;
}
```

#### 3.6.2
#### 3.6.3
#### 3.6.4
#### 3.6.5
#### 3.6.6
#### 3.6.7

### 3.7 Smart Pointers
-see section 
#### 3.7.1 
#### 3.7.2
#### 3.7.3
#### 3.7.4
#### 3.7.5
#### 3.7.6
#### 3.7.7


### 3.8 Exception Handling

#### 3.7.1 
#### 3.7.2
#### 3.7.3
#### 3.7.4
#### 3.7.5
#### 3.7.6
#### 3.7.7

### 3.9 i/O and streams

#### 3.9.1 Files, streams and I/O

- C++ usesstreamss as an interface between the program and input and output devices
- independent of the actua; devie
- sequence of bytes
- input stream provides data to the program
- output revieves data from the program

input devide --> input stream --> C++ program --> output stream --> output device 

- Header files
  	- iostream: provides definations for formatted input and output from/to streams
  	- fstream:  provides definations for formatted input and output from/to **file** streams
  	- iomainip: provides definations for manipulators used to format stream I/O
commonly used fstream class
	- ios
  	- ifstream - input
     	- ofstream - output
         - fstream - both input and output
         - stringstream - 
         - 
commonly used iostream class
	- cin: connected to keyboard, buffered (wont be automatic until the user presss enter)
   	- cout: connected to console,  buffered (wont be automatic until the user presss enter)
   	- cerr: standard error system , by default connected to console, and unbuffered
   	- clog: standard log stream, by default connected to console, and unbuffered


#### 3.9.2
#### 3.9.3
#### 3.9.4
#### 3.9.5
#### 3.9.6
#### 3.9.7

### 3.10 The standard Template Library (STL)

#### 3.10.1 what is standard Template Library (STL) ?
The Standard Template Library (STL) is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks.

The STL was developed by Alexander Stepanov and Meng Lee at Hewlett Packard and was incorporated into the C++ Standard Library. It provides a collection of template classes and functions, which are highly reusable and extendable, making it easier to write efficient and concise C++ code.

Key components of the STL include:

1. **Containers:** These are data structures that store objects or values. Examples include vectors, sets ,lists, queues, and maps.

2. **Algorithms:** The STL provides a set of generic algorithms that operate on containers. Examples include sorting, searching, and modifying algorithms.

3. **Iterators:** Iterators are used to iterate over the elements of a container. They provide a unified way to access the elements of various container types.

4. **Function Objects (Functors):** These are objects that can be used with algorithms to define custom behavior. Function objects can be used for sorting, searching, and other operations.

5. **Allocators:** Allocators manage the memory for containers. They provide a way to customize the memory allocation strategy used by a container.

Using the STL can result in more efficient and readable code, as many common tasks can be accomplished with high-quality, tested, and optimized implementations provided by the library. It also encourages the use of generic programming principles, promoting code that is reusable and adaptable to different data types.

Certainly! Let's look at a simple example that demonstrates the use of some common components of the Standard Template Library (STL) in C++. In this example, we'll use a vector container and some algorithms.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Example of using a vector container
    std::vector<int> numbers = {5, 2, 8, 1, 7, 3};

    // Print the original vector
    std::cout << "Original vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Example of using algorithms with iterators
    // Sorting the vector using the sort algorithm
    std::sort(numbers.begin(), numbers.end());

    // Print the sorted vector
    std::cout << "Sorted vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Using accumulate algorithm to find the sum of elements
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of elements: " << sum << "\n";

    // Using find algorithm to search for an element
    int searchElement = 7;
    auto it = std::find(numbers.begin(), numbers.end(), searchElement);
    if (it != numbers.end()) {
        std::cout << "Element " << searchElement << " found at index: " << std::distance(numbers.begin(), it) << "\n";
    } else {
        std::cout << "Element " << searchElement << " not found\n";
    }

    return 0;
}
```

In this example:

- We use a `std::vector` to store a collection of integers.
- The `std::sort` algorithm is used to sort the elements of the vector.
- The `std::accumulate` algorithm is used to calculate the sum of the elements.
- The `std::find` algorithm is used to search for a specific element.

This is a basic example, but it illustrates how the STL provides generic, reusable components that allow you to write code that is both concise and efficient. The algorithms operate on iterators, providing a uniform interface for different types of containers.

#### 3.10.2 Generic Programming with Macros
##### Macros

- Macros are text replacements performed by the C++ preprocessor before the actual compilation of code. They are defined using the #define directive and provide a way to define symbolic constants, create code shortcuts, and conditionally include or exclude code blocks.
- Beware of MACROS !!!
- Macros can lead to unexpected behavior if not used carefully.
- Prefer constants for simple values and inline functions for code blocks when possible.
- Modern C++ often favors alternatives like const variables, inline functions, and templates for greater type safety and control.
- Use #undef to undefine a macro.
- Useful for preventing conflicts or limiting scope.
- Macros Alternative
  	- use constexpr EX.  constexpr double PI = 3.14159265358979323846
  	- usage of constexpr to define the constant PI in C++ is a good practice.
  	- constexpr is a feature introduced in C++11 that allows you to declare variables or functions as constants that can be evaluated at **compile time**.
  	  
 ```cpp
#include <iostream>

constexpr double PI = 3.141592653589793238463;

int main() {
    std::cout << "The value of PI is: " << PI << std::endl;
    return 0;
}
```

1.  Object-Like Macros: Define simple constants or expressions.
```cpp
#define PI 3.14159
#define MAX_ARRAY_SIZE 100
```

2. Conditional Compilation

```cpp
#define DEBUG 1

#ifdef DEBUG
    // Debugging code
#endif
```
- If DEBUG is defined, the code within the #ifdef and #endif directives will be included; otherwise, it will be excluded.

3. String Concatenation:

```cpp
#define CONCAT(a, b) a ## b
```
- This macro concatenates two tokens together.

Example usage:
```cpp
int ab = CONCAT(3, 4);  // Expands to 34
```
4. Include Guards:
- Include guards prevent a header file from being included multiple times in the same translation unit, avoiding redefinition errors.
``` cpp
#ifndef MY_HEADER_H
#define MY_HEADER_H

// Contents of the header file

#endif
```

5. Function-Like Macros: Resemble functions but are replaced with their text during preprocessing.
	- Function-like macros can accept arguments within parentheses.
	- Use carefully, as they don't have type checking or scoping like functions.
```cpp
#define SQUARE(x) ((x) * (x))
```

-  **functions that accept many types** arguments EXAMPLE
Three methods 
Certainly! Below are three examples in C++ that demonstrate finding the maximum of two values using macros, function overloading, and templates:

### 1. Using Macros: 
- DON'T USE MACROS IF POSSIBLE! IT WILL LEAD TO ALL SORTS OF ERRORS 
- The macro version (`MAX_MACRO`) performs a simple conditional check to determine the maximum.

```cpp
#include <iostream>

#define MAX_MACRO(a, b) ((a > b) ? a : b)

int main() {
    int num1 = 10, num2 = 20;
    double double1 = 15.5, double2 = 30.7;

    std::cout << "Max of " << num1 << " and " << num2 << " is: " << MAX_MACRO(num1, num2) << std::endl;  //20
    std::cout << "Max of " << double1 << " and " << double2 << " is: " << MAX_MACRO(double1, double2) << std::endl; //30.7
    std::cout<<MAX_MACRO('A','C')<<std::endl;  //C
    return 0;
}
```

### 2. Using Function Overloading: 
- better BUT WE CANT TEST CHARACTER TYPE FOR EXAMPLE
- The function overloading version defines two functions, one for `int` and one for `double`, each performing the comparison.
```cpp
#include <iostream>

int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

int main() {
    int num1 = 10, num2 = 20;
    double double1 = 15.5, double2 = 30.7;

    std::cout << "Max of " << num1 << " and " << num2 << " is: " << max(num1, num2) << std::endl;
    std::cout << "Max of " << double1 << " and " << double2 << " is: " << max(double1, double2) << std::endl;

    return 0;
}
```

### 3. Using Templates: BEST METHOD!!!
- The template version defines a single function template that can work with various types.

```cpp
#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int num1 = 10, num2 = 20;
    double double1 = 15.5, double2 = 30.7;

    std::cout << "Max of " << num1 << " and " << num2 << " is: " << max(num1, num2) << std::endl;
    std::cout << "Max of " << double1 << " and " << double2 << " is: " << max(double1, double2) << std::endl;

    return 0;
}
```

In these examples:

The template version is generally considered more flexible and type-safe, as it allows the compiler to generate the appropriate code for each type at compile time. The function overloading version is also type-safe but requires writing multiple functions for different types. The macro version should be used with caution due to potential issues with unexpected side effects and lack of type safety.

##### Templates: 
- Blueprint
- **compile time**
- Templates allow you to write code that can work with **different data types** without sacrificing type safety
- all this happens at compile time. diffrent from other programming languages.
   
1.  Function template
2. Class Template
   
#### 3.10.3 Function template

```cpp
#include <iostream>

template <typename T>  //same as:  template <class T> 
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int num1 = 10, num2 = 20;
    double double1 = 15.5, double2 = 30.7;

    std::cout << "Max of " << num1 << " and " << num2 << " is: " << max(num1, num2) << std::endl;
    std::cout << "Max of " << double1 << " and " << double2 << " is: " << max(double1, double2) << std::endl;

    return 0;
}
```
```cpp
#include <iostream>
//max val
template <typename T>
T max(T val1, T val2)
{
    return (val1 > val2) ? val1 : val2;
}
//min val
template <typename T>
T min(T val1, T val2)
{
    return (val1 < val2) ? val1 : val2;
}

int main()
{
    int a{10};
    int b{20};
    std::cout<<max<int>(a,b)<<'\n'; //20
    std::cout<<min<int>(a,b)<<'\n'; //10
    
    double c{10.4};
    double d{10.9};
    std::cout<<max<double>(c,d)<<'\n'; //10.9
    std::cout<<min<double>(c,d)<<'\n'; //10.4
    //or we can have the compiler deduce 
    std::cout<<max(c,d)<<'\n'; //10.9
    std::cout<<min(c,d)<<'\n'; //10.4
    
    std::cout<<max('X','Z')<<'\n'; //Z
    
    return 0;
}
```
thmplate with struct
```cpp
#include <iostream>
#include <string>

template <typename T>
T min(T a,T b)
{
   return (a<b) ? a:b;
}

struct Person
{
    std::string name;
    int age;
    
    //overloading operator. 
    bool operator<(const Person &rhs) const
    {
        return this->age<rhs.age;
    }
    
};

int main()
{
    Person p1{"joe",28};
    Person p2{"smith",50};
    
    Person p3=min(p1,p2);  //error: no match for ‘operator<’ 
    //(operand types are ‘Person’ and ‘Person’)
    //we will need to write overloading operator. 
    std::cout<<p3.name<<'\n'; //joe 

    return 0;
}
```

```cpp
#include <iostream>
#include <string>

template <typename T>
T min(T a,T b)
{
   return (a<b) ? a:b;
}

template<typename T1, typename T2>
void func(T1 a,T2 b)
{
    std::cout<<a<<" and " <<b<<'\n';
}

struct Person
{
    std::string name;
    int age;
    
    //overloading operator. 
    bool operator<(const Person &rhs) const
    {
        return this->age<rhs.age;
    }
    
};

std::ostream &operator<<(std::ostream& os, const Person& obj)
{
    os<<obj.name;
    return os;
}

int main()
{
    Person p1{"joe",28};
    Person p2{"smith",50};
    
    Person p3=min(p1,p2);  //error: no match for ‘operator<’ 
    //(operand types are ‘Person’ and ‘Person’)
    //we will need to write overloading operator. 
    std::cout<<p3.name<<'\n'; //joe 
    
    func(p1,p2); //error: no match for ‘operator<<’ 
    //(operand types are ‘std::ostream’ {aka ‘std::basic_ostream’} and ‘Person’)
    //we will need to add insersion operator overloading 
    //after overload operator//joe and smith

    return 0;
}
```
#### 3.10.4 Class Template
-  A class template allows you to create a template for a class that can work with different data types. 
- Template class is added in .h file. not .cpp file

```cpp
#include <iostream>

// Class template for a generic Pair
template <typename T1, typename T2>
class Pair {
public:
    Pair(T1 first, T2 second) : first(first), second(second) {}

    void display() const {
        std::cout << "Pair: (" << first << ", " << second << ")" << std::endl;
    }

private:
    T1 first;
    T2 second;
};

int main() {
    // Creating instances of Pair with different data types
    Pair<int, double> intDoublePair(42, 3.14);
    Pair<std::string, char> stringCharPair("Hello", 'A');

    // Displaying the pairs
    intDoublePair.display();
    stringCharPair.display();

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>

template<typename T>
class Item {
public:
    Item(std::string name,T value):name(name),value(value) {
        
    }
    std::string get_name() const {
        //std::cout<<name<<'\n';
        return name;
    }
    
    T get_value() const {
        //std::cout<<value<<'\n';
        return value;
    }
    
private:
    std::string name;
    T value;
};


template <typename T1,typename T2>
struct MyPair{
    T1 first;
    T2 second;
};

int main()
{
    Item<int> item1{"ItemNum1",200};
    item1.get_name(); //ItemNum1
    item1.get_value(); //200
    
    Item<std::string> item2{"ItemNum2","stringItem"};
    item2.get_name(); //ItemNum2
    item2.get_value(); //stringItem
    
    
    Item<Item<std::string>> item3{"frank",{"C++","Professor"}};
    item3.get_name(); //frank
    std::cout<<item3.get_value().get_name()<<" ";  //C++
    std::cout<<item3.get_value().get_value()<<'\n';  //C++ Professor
    
    std::vector<Item<double>> vec{};
    vec.push_back(Item<double>("Larry",100.0));
    vec.push_back(Item<double>("BOB",100.0));
    vec.push_back(Item<double>("SMITH",100.0));
    
    for(const auto& i:vec)
    {
        std::cout<<i.get_name()<<" : "<<i.get_value()<<std::endl;
    }
    
    //Larry : 100
    //BOB : 100
    //SMITH : 100
    
    MyPair<std::string,int> p1{"Hi",100};
    std::cout<<p1.first<<" : "<<p1.second<<'\n'; //Hi : 100
    MyPair<int,double> p2{2,2.56};
    std::cout<<p2.first<<" : "<<p2.second<<'\n'; //2 : 2.56

}


```

#### 3.10.5

#### 3.10.6

#### 3.10.7


### 3.11 Lambda Expressions

#### 3.7.1 
#### 3.7.2
#### 3.7.3
#### 3.7.4
#### 3.7.5
#### 3.7.6
#### 3.7.7

### 3.12 Enumerations

#### 3.7.1 
#### 3.7.2
#### 3.7.3
#### 3.7.4
#### 3.7.5
#### 3.7.6
#### 3.7.7

### 3.13 Bonus
#### 3.7.1 
#### 3.7.2
#### 3.7.3
#### 3.7.4
#### 3.7.5
#### 3.7.6
#### 3.7.7

- Links
	[google C++ style guide](https://google.github.io/styleguide/cppguide.html)
	[C++ projects](https://github.com/practical-tutorials/project-based-learning#cc)
	[Calculator project](https://github.com/microsoft/calculator) 
------------------------------------------------------------------------------------------------------------
