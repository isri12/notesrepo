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

	- You may have come across code where integer types are expressed as int16_t or uint32_t. Use #include <cstdint>.  There you will find std::uint32_t, std::int16_t etc.  But declared within the std:: namespace. **std::uint32_t should be preferred over uint32_t.**

##### Topics
	-Serializing data.
	-Packing data tightly and predictably.
	-Performing bit operations.

------------------------------------------------------------------


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
### References 
-we can get the memory address of a variable by using the & operator
```cpp
#include <iostream>
#include <string>

int main()
{
    std::string car = "Toyota"; // A car variable of type string

    std::cout << car << std::endl; // Outputs the value of food (Toyota)
    std::cout << &car; // Outputs the memory address of food (0x7fff996e11f0)
}
```
> Toyota
> 0x7fff996e11f0
### Pointers
-variables that store the memory addresses of other variables. 
- Special data type for memory address
- Same pointer maybe used to access many different variables. 
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

### Structure 
- containers of hetrogenous data mambers
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
- may contain data and member functions
  	- Example car.make, car.paint()
- contain Public Constructor, data, and methods
- Private data and methods
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
```cpp   
//mycar.h
	class car
		{
	Public:
		std::string get_name();
		int get_model();
		void set_year(int y);
	Private:
		std::string name;                       // class- or data member 
		int year;				// class member 
		unsigned char car_purpose;		// class member 
		std::string model;				// class member 
		}
```
```cpp
//mycar.cpp
#include "car.h"

std::string get_name()
{
	return name;
}
int get_model()
{
	return model;
}
void set_year(int y)
{
	year=y;
}

```
- **Construcror**:
- - **Destructor**
- **Operator Overload**: 
-pragma once **vs** #ifdef CAR_H .... #define CAR_H.....#endif //CAR_H (include gard)


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
