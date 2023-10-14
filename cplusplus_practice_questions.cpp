
/* Hacker rank - For Loop
# Practice
## 1) For Loop
### In this challenge, you will use a for loop to increment a variable through a range.
#### Input:
- You will be given two positive integers, a and b (a =<b ), separated by a newline.
#### Output:
- For each integer n in the inclusive interval[a,b] :
  - if 1=<n=<9 then print english representation of it in lower case. i.e 1 "one", 2 "two" ...
  - If n>9 and even number print "even"
  - if n>9 and odd number, print "odd"
#### Example
Input:
8
11
output:
eight
nine
even
odd

INPUT:
3 15
OUTPUT
three
four
five
six
seven
eight
nine
even    //10
odd    //11
even    //12
odd     //13
even    //14
odd     //15
*/


// #include <iostream>
// #include <cstdio>
// #include <cassert>

// using namespace std;

// void name(int x)
// {
//     switch (x) 
//     {
//         case 1:
//             cout << "one"<<"\n";
//             break;
//         case 2:
//             cout << "two"<<"\n";
//             break;
//         case 3:
//             cout << "three"<<"\n";
//             break;
//         case 4:
//             cout << "four"<<"\n";
//             break;
//         case 5:
//             cout << "five"<<"\n";
//             break;
//         case 6:
//             cout << "six"<<"\n";
//             break;
//         case 7:
//             cout << "seven"<<"\n";
//             break;
//         case 8:
//             cout << "eight"<<"\n";
//             break;
//         case 9:
//             cout << "nine"<<"\n";
//             break;
//     }
// }

// void evenoddprint(int i)
// {
//     if (i%2 == 0)
//     {
//         cout<<"even"<<"\n";
//     }else{
//         cout<<"odd"<<"\n";
//     }
// }

// void forlooper(int c,int d)
// {
//     for (int i=c;i<d+1;i++)
//         {
//             if (i>=1 && i<=9) 
//             {
//                 name(i);
//             }else if (i>9)
//             {
//                 evenoddprint(i);
//             } 
//         }
// }


// int main() 
// {
//     //int a=8 , b=11; 
//     int a,b;
//     std::cin >> a ;
//     std::cin >> b ;

//     //std::cout <<"a is : "<<a<< std::endl;
//     //std::cout <<"b is : "<<b<< std::endl;
    
//     forlooper(a,b);
 
//     return 0;
// }

//-------------------------------------------------

/* Leetcode:  Two sum 
https://leetcode.com/problems/two-sum/description/ 

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/
```cpp
// #include <iostream>
// #include <vector>

// class Solution {
// public:
//     std::vector<int> twoSum(std::vector<int>& nums, int target) 
//     //void twoSum(std::vector<int>& nums, int target) 
//     {
//         //std::cout<<nums.size()<<std::endl;
//         std::vector<int> answer;
//         for (int i=0;i<nums.size()-1;i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 //std::cout<<nums[i]+nums[j]<<" ";
//                 if (nums[i]+nums[j] == target)
//                 {
//                     // std::cout<<"i: "<<i<<std::endl;
//                     // std::cout<<"j: "<<j<<std::endl;
//                     // std::cout<<nums[i]<<" : "<<nums[j]<<std::endl;
//                     answer.push_back(i);
//                     answer.push_back(j);
//                 //   std::cout<<i+j<<std::endl;
//                     return answer;
//                 }
//             }
//             std::cout<<std::endl;//'\n';
//         }  
//         return answer;
//     }
// };
// int main()
// {
//     // std::vector<int> nums{2,7,11,15};
//     // int target{9};

//     std::vector<int> nums{3,2,4};
//     int target{6};

//     Solution T;
//     std::vector<int> ans=T.twoSum(nums,target);
//     std::cout<<ans.size()<<'\n';

//     for (int i=0;i<ans.size();i++)
//     {
//         std::cout<<ans[i]<<" ";
//     }
//     std::cout<<std::endl;
//     return 0;
// }
```cpp
//-------------------------------------------------


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
