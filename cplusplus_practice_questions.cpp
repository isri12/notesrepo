/*

//Leet code
//1637. Widest Vertical Area Between Two Points Containing No Points
//https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        std::vector<int> yAxis;

        // Extract y values
        for (const auto& point : points) {
            yAxis.push_back(point[1]);
        }

        // Print y values using a range-based for loop
        std::cout << "Y Axis: ";
        for (int y : yAxis) {
            std::cout << y << " ";
        }
        std::cout << '\n';

        // Sort y values
       std::sort(yAxis.begin(), yAxis.end());

      // Print y values using a range-based for loop
        std::cout << "Y Axis: ";
        for (int y : yAxis) {
            std::cout << y << " ";
        }
        std::cout << '\n';

        // Find the maximum difference between adjacent y values
        int maxWidth = 0;
        for (size_t i = 1; i < yAxis.size(); ++i) {
            int currentWidth = yAxis[i] - yAxis[i - 1];
            maxWidth = std::max(maxWidth, currentWidth);
        }

        return maxWidth;
    }
};

//{{8,7},{9,9},{7,4},{9,7}}

int main() {
    Solution s1;
    std::vector<std::vector<int>> coordinates = {{8,7},{9,9},{7,4},{9,7}};
    int result = s1.maxWidthOfVerticalArea(coordinates);
    std::cout << "Max Width: " << result << std::endl;
    return 0;
}


*/




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



/*

//Leet code
//1637. Widest Vertical Area Between Two Points Containing No Points
//https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        std::vector<int> yAxis;

        // Extract y values
        for (const auto& point : points) {
            yAxis.push_back(point[1]);
        }

        // Print y values using a range-based for loop
        std::cout << "Y Axis: ";
        for (int y : yAxis) {
            std::cout << y << " ";
        }
        std::cout << '\n';

        // Sort y values
       std::sort(yAxis.begin(), yAxis.end());

      // Print y values using a range-based for loop
        std::cout << "Y Axis: ";
        for (int y : yAxis) {
            std::cout << y << " ";
        }
        std::cout << '\n';

        // Find the maximum difference between adjacent y values
        int maxWidth = 0;
        for (size_t i = 1; i < yAxis.size(); ++i) {
            int currentWidth = yAxis[i] - yAxis[i - 1];
            maxWidth = std::max(maxWidth, currentWidth);
        }

        return maxWidth;
    }
};

//{{8,7},{9,9},{7,4},{9,7}}

int main() {
    Solution s1;
    std::vector<std::vector<int>> coordinates = {{8,7},{9,9},{7,4},{9,7}};
    int result = s1.maxWidthOfVerticalArea(coordinates);
    std::cout << "Max Width: " << result << std::endl;
    return 0;
}


*/




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

//-------------------------------------------------

// // compile: g++ -std=c++11 -o pointers pointers.cpp
// #include <iostream>
// #include <string>

// typedef struct Student {
//     int id;
//     char *f_name;
//     char *l_name;
//     int n_assignments;
//     double *grades;
// } Student;

// int promptInt(std::string message, int min, int max);
// double promptDouble(std::string message, double min, double max);
// void calculateStudentAverage(void *object, double *avg);

// int main(int argc, char **argv)
// {
//     Student student;
//     double average;

//     // Sequence of user input -> store in fields of `student`

//     // Call `CalculateStudentAverage(???, ???)`
//     // Output `average`

//     return 0;
// }

// /*
//    message: text to output as the prompt
//    min: minimum value to accept as a valid int
//    max: maximum value to accept as a valid int
// */
// int promptInt(std::string message, int min, int max)
// {
//     // Code to prompt user for an int
// }

// /*
//    message: text to output as the prompt
//    min: minimum value to accept as a valid double
//    max: maximum value to accept as a valid double
// */
// double promptDouble(std::string message, double min, double max)
// {
//     // Code to prompt user for a double
// }

// /*
//    object: pointer to anything - your choice! (but choose something that will be helpful)
//    avg: pointer to a double (can store a value here)
// */
// void calculateStudentAverage(void *object, double *avg)
// {
//     // Code to calculate and store average grade
// }
// ```


/*
Leetcode
1887. Reduction Operations to Make the Array Elements Equal
Medium
Topics
Companies
Hint
Given an integer array nums, your goal is to make all elements in nums equal. To complete one operation, follow these steps:

Find the largest value in nums. Let its index be i (0-indexed) and its value be largest. If there are multiple elements with the largest value, pick the smallest i.
Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest.
Reduce nums[i] to nextLargest.
Return the number of operations to make all elements in nums equal.

 

Example 1:

Input: nums = [5,1,3]
Output: 3
Explanation: It takes 3 operations to make all elements in nums equal:
1. largest = 5 at index 0. nextLargest = 3. Reduce nums[0] to 3. nums = [3,1,3].
2. largest = 3 at index 0. nextLargest = 1. Reduce nums[0] to 1. nums = [1,1,3].
3. largest = 3 at index 2. nextLargest = 1. Reduce nums[2] to 1. nums = [1,1,1].
Example 2:

Input: nums = [1,1,1]
Output: 0
Explanation: All elements in nums are already equal.
Example 3:

Input: nums = [1,1,2,2,3]
Output: 4
Explanation: It takes 4 operations to make all elements in nums equal:
1. largest = 3 at index 4. nextLargest = 2. Reduce nums[4] to 2. nums = [1,1,2,2,2].
2. largest = 2 at index 2. nextLargest = 1. Reduce nums[2] to 1. nums = [1,1,1,2,2].
3. largest = 2 at index 3. nextLargest = 1. Reduce nums[3] to 1. nums = [1,1,1,1,2].
4. largest = 2 at index 4. nextLargest = 1. Reduce nums[4] to 1. nums = [1,1,1,1,1].
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 5 * 104

*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int reductionOperations(std::vector<int>& nums) {
        int min = 0;
        std::sort(nums.begin(),nums.end());
        for(int i =0; i < nums.size(); ++i) 
        {
          std::cout<<nums.at(i)<<" "<<std::endl;
        } 
        return 0;
    }
};




int main()
{
  Solution s1;
 std::vector<int> num = {5,1,3};
  //std::vector<int> num = {1,1,2,2,3};
  s1.reductionOperations(num);

}
