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
### Array
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

### Constants 
- don’t change while execution 
	1. With preprocessor or macros
	#define  ROOMS 4
	
	2. Declarations 
	const x =8;
### String
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

### References 
-we can get the memory address of a variable by using the & operator
### Pointers
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
#### dereferencing a pointer (access the data were pointing to)
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
---------------------------------------------------------------------------------------------------------------------
## 3 Object Oriented programming

Introduction to OPPs in C++

Object-oriented programming (OOP) is a programming paradigm based on the concept of "objects", which can contain **data** and **code**: data in the form of fields (often known as attributes or properties), and code, in the form of procedures (often known as methods).¹ C++ is an object-oriented programming language that allows you to create classes that encapsulate data and functions. Classes are user-defined types that can be used to create objects. 

**class** = is a blueprint for an object, which defines its data members and member functions.
**Object** = an instance of a class that contains **data** and **functions**. aka grouped data
**Methods** = the procedures that an object performs 

In C++, OOP provides several advantages over procedural programming such as faster and easier execution, clear structure for programs, helps keep the code DRY (Don't Repeat Yourself), makes the code easier to maintain, modify and debug, and makes it possible to create full reusable applications with less code and shorter development time.

### Structure 
- abstraction i.e collection of individual properties of real-world object. 
- containers of hetrogenous data mambers
- the diffrence betwen struct and class is **class is private by default** and **struct is public by default**.
- 
```cpp   
	struct car {
		string name;
		int year;
		unsigned char car_purpose;
		string model;
		}
```
### enum
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
### Classes
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


**Access Modifiers in C++
Constructor in C++
Encapsulation in C++
Abstraction in C++
Inheritance in C++
Polymorphism in C++**

- **Construcror**:
- - **Destructor**
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

-pragma once **vs** #ifdef CAR_H .... #define CAR_H.....#endif //CAR_H (include gard)
-class and struct keywords: Used to define classes and structures.
-Member variables: Data attributes stored within a class.
-Member functions: Methods that define the behavior of objects.
-Access specifiers: public, private, and protected to control member visibility.
-Constructors and destructors: Special methods to initialize and clean up objects.
-Inheritance: class Derived : public Base to create derived classes.
-Polymorphism: Achieved through virtual functions and dynamic dispatch.
-Operator overloading: Defining custom behaviors for operators like +, -, ==, etc.
-Templates: Used to create generic classes and functions.
-Namespaces: Used for organizing and managing code.

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
### Dynamic Programming and Heap

### Preprocessor directives 
	#include<iostream>    //file will be search in a pre-defined location 
	#define CAPACITY 5000  //the preprocessor will replace everything with 5000
	

	
### Type casting 
	-  Explicitly specifying the data type of an expression.
	-  Suppose you want to have several lines of code that print data out for debugging purposes, but you don't want those lines to make it to the final application, for efficiency reasons. Which of the following achieves the desired behavior by using preprocessor directives?


### DEBUGGING
	// comment the following line for the final application 
	#define DEBUGGING 

	// copy and customize this for every debugging line 
	#ifdef DEBUGGING 
	cout<<"Var1 = "<<var1<<endl; 
	#endif
