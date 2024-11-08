
//Leet code
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// If you are a beginner solve these problems which makes concepts clear for future coding:
// 	1. Two Sum
// 	2. Roman to Integer
// 	3. Palindrome Number
// 	4. Maximum Subarray
// 	5. Remove Element
// 	6. Contains Duplicate
// 	7. Add Two Numbers
// 	8. Majority Element
// 	9. Remove Duplicates from Sorted Array

//Microsoft
// Implement Queue using Stacks: https://leetcode.com/problems/implement-queue-using-stacks/
// Spiral Matrix: https://leetcode.com/problems/spiral-matrix/
// Find Winner on a Tic Tac Toe Game: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
// LRU Cache: https://leetcode.com/problems/lru-cache/

// Practice them in a row for better understanding and please Upvote for more questions.
//Leet code by type: https://github.com/103style/LeetCode/tree/master
//463. Island Perimeter https://leetcode.com/problems/island-perimeter/description/?envType=daily-question&envId=2024-04-18
//136. Single Number https://leetcode.com/problems/single-number/
//338. Counting Bits https://leetcode.com/problems/counting-bits/

// Linked List: https://leetcode.com/problem-list/linked-list/?difficulty=EASY 
//21. Merge Two Sorted Lists : https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=problem-list-v2&envId=linked-list&difficulty=EASY

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//===========707. Design Linked List ============================================================================================
// https://leetcode.com/problems/design-linked-list/description/?envType=problem-list-v2&envId=linked-list&difficulty=MEDIUM

// struct Node{
//     Node* next;
//     int val;
//     Node(int x):next(nullptr),val(x){

//     }
// }; 

// class MyLinkedList {
// private:
//     Node *head;
//     int size;

// public:
//     MyLinkedList(): head(nullptr),size(0) {
        
//     }
    
//     int get(int index) {
//         if (index >= size || index < 0){
//             return -1;
//         }else{
//             Node* current= head;
//             for (int i=0;i<index;i++){
//                 current = current -> next;
//             }
//             return current ->val;
//         }
        
//     }
    
//     void addAtHead(int val) {
//         Node* newNode= new Node(val);
//         newNode->next=head;
//         head=newNode;
//         size++;
//     }
    
//     void addAtTail(int val) {
//         Node* newNode= new Node(val);
//         if (head == nullptr){
//             head=newNode;
//         }else{
//             Node* current = head;
//             while (current->next != nullptr){
//                 current=current->next;
//             }
//             current->next=newNode;
//         }
//         size++;
//     }
    
//     void addAtIndex(int index, int val) {
      
//         if (index<0 || index>size){
//             return;
//         }
//         if( index == 0){
//             addAtHead(val);
//             return;
//         }
//         if(index == size){
//             addAtTail(val);
//             return;
//         }
//         Node* NewNode = new Node(val);
//         Node* current= head;
//         for(int i=0;i<index-1;i++){
//             current=current->next;
//         }
//         NewNode -> next = current->next;
//         current->next = NewNode;
//         size++;
//     }
    
//     void deleteAtIndex(int index) {
//     if (index < 0 || index >= size) {
//         return;
//     }
//     Node* toDelete;
//     if (index == 0) {
//         toDelete = head;
//         head = head->next;
//     } else {
//         Node* current = head;
//         for (int i = 0; i < index - 1; i++) {
//             current = current->next;
//         }
//         toDelete = current->next;
//         current->next = current->next->next;
//     }
//     delete toDelete;
//     size--;
// }

// ~MyLinkedList() {
//     Node* current = head;
//     while (current != nullptr) {
//         Node* next = current->next;
//         delete current;
//         current = next;
//     }
// }


// };

// /**
//  * Your MyLinkedList object will be instantiated and called as such:
//  * MyLinkedList* obj = new MyLinkedList();
//  * int param_1 = obj->get(index);
//  * obj->addAtHead(val);
//  * obj->addAtTail(val);
//  * obj->addAtIndex(index,val);
//  * obj->deleteAtIndex(index);
//  */

 
//===========860. Lemonade Change ======working======================================================================================
//<https://leetcode.com/problems/lemonade-change/?envType=daily-question&envId=2024-08-16>
// 
// At a lemonade stand, each lemonade costs $5. Customers are standing 
//in a queue to buy from you and order one at a time (in the order specified by bills).
// Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
//You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
// Note that you do not have any change in hand at first.

// Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide 
//every customer with the correct change, or false otherwise.

// Example 1:
// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.

// Example 2:
// Input: bills = [5,5,10,10,20]
// Output: false
// Explanation: 
// From the first two customers in order, we collect two $5 bills.
// For the next two customers in order, we collect a $10 bill and give back a $5 bill.
// For the last customer, we can not give the change of $15 back because we only have two $10 bills.
// Since not every customer received the correct change, the answer is false.
 
// Constraints:
// 1 <= bills.length <= 105
// bills[i] is either 5, 10, or 20.

// #include<iostream>
// #include <vector>
// class Solution {
// public:
//     bool lemonadeChange(std::vector<int>& bills) {
//       int bill5=0;
//       int bill10=0;
//       //int bill20=0;

//       for(int i:bills){
//         if (i == 5){
//           bill5++;
//         }else if (i == 10) {
//           if (bill5 == 0) return false;
//           bill5--;
//           bill10++;
//         }else{ //i=20
//           if(bill5>0 && bill10>0){
//             bill5--;
//             bill10--;
//           }else if(bill5 > 3){
//             bill5-=3;
//           }else{
//             return false;
//           }
//         }
//       }
//       //std::cout<<'\n';
//       // std::cout<<bill5<<'\n';
//       // std::cout<<bill10<<'\n';
//       return true;
//     }
      
// };

// int main (){
//   Solution s1;
//   std::vector<int> bills1 ={5,5,5,10,20};  //expected true
//   std::vector<int> bills2 = {5,5,10,10,20};
//   std::vector<int> bills3= {5,5,5,10,5,5,10,20,20,20};//expected false 
//   //std::cout<<s1.lemonadeChange(bill);
//   std::cout << "Test case 1: " << (s1.lemonadeChange(bills1) ? "true" : "false") << std::endl;
//   std::cout << "Test case 2: " << (s1.lemonadeChange(bills2) ? "true" : "false") << std::endl;
//   std::cout << "Test case 2: " << (s1.lemonadeChange(bills3) ? "true" : "false") << std::endl;
// }

//===========1700. Number of Students Unable to Eat Lunch ============================================================================================
//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08


/////////////////////////////////////////////////////////////////////////////////////////////////
//===========leet 2073. Time Needed to Buy Tickets - not solved============================================================================================
//https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=daily-question&envId=2024-04-09

// There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.
// You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].
// Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. 
//If a person does not have any tickets left to buy, the person will leave the line.
// Return the time taken for the person at position k (0-indexed) to finish buying tickets.

// Example 1:
// Input: tickets = [2,3,2], k = 2
// Output: 6
// Explanation: 
// - In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
// - In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
// The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.

// Example 2:
// Input: tickets = [5,1,1,1], k = 0
// Output: 8
// Explanation:
// - In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
// - In the next 4 passes, only the person in position 0 is buying tickets.
// The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.
 
// Constraints:
// n == tickets.length
// 1 <= n <= 100
// 1 <= tickets[i] <= 100
// 0 <= k < n

// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<string>

// class Solution {
// public:
//     int timeRequiredToBuy(std::vector<int>& tickets, int k) {
//       // for(int j:tickets){
//       //     std::cout<<j;
//       //   }
//        // std::cout<<'\n';
//       std::vector<int> buyticket{};
//       int counter=0;
//       //std::cout<<tickets.size()<<'\n';
      
//       for (size_t i=0 ;i<tickets.size();++i){
//           //std::cout<<i<<'\n';
//           //std::cout<<tickets[i];
//           if(counter<k){
//             buyticket.push_back(tickets[i]-1);
//             counter++;
//           }
//       }

//       //std::cout<<'\n';
//          for(int j:buyticket){
//           std::cout<<j;
//         }
//         std::cout<<'\n';
//         return 0;

//     }
     
// };


// int main(){
//   std::vector<int>tickets{2,3,2};
//   int k=2;

//   Solution s1;
//   s1.timeRequiredToBuy(tickets,k);

// }

//===========leet 1544. Make The String Great ============================================================================================
//https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05

// Given a string s of lower and upper case English letters.

// A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

// 0 <= i <= s.length - 2
// s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
// To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

// Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

// Notice that an empty string is also good.

 
// Example 1:
// Input: s = "leEeetcode"
// Output: "leetcode"
// Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".

// Example 2:
// Input: s = "abBAcC"
// Output: ""
// Explanation: We have many possible scenarios, and all lead to the same answer. For example:
// "abBAcC" --> "aAcC" --> "cC" --> ""
// "abBAcC" --> "abBA" --> "aA" --> ""

// Example 3:
// Input: s = "s"
// Output: "s"
 
// Constraints:
// 1 <= s.length <= 100
// s contains only lower and upper case English letters.

// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<string>

// class Solution {
// public:
//     std::string makeGood(std::string s) {


//     return s;
//     }
// };

// int main(){

//   Solution s1;

//   std::string s = "leEeetcode";

//   std::cout<<s1.makeGood(s)<<'\n';

// }

//// https://leetcode.com/problems/merge-strings-alternately/submissions/1443334537/?envType=study-plan-v2&envId=leetcode-75

// class Solution {
// public:
//     std::string mergeAlternately(std::string word1, std::string word2) {
//         std::string ans ={};
//         int minsize = std::min(word2.size(),word1.size());


//         for(int i=0;i<minsize;i++){
//             ans.push_back(word1[i]);
//             ans.push_back(word2[i]);
//             // for(int j=0;j<word2.size();j++){
//             //     std::cout<<word2[j];
//             // }
//         }

//         if (word1.size() > word2.size()){
//             // int extra = word1.size()-word2.size();
//              ans = ans + word1.substr(word2.size());
//         }

//         if (word1.size() < word2.size()){
//             //int extra = word2.size() - word1.size();
//             //std::cout<<extra<<std::endl;
//             //std::cout<<word2.substr(extra)<<std::endl;
//             ans = ans + word2.substr(word1.size());
//         }
//         return ans;
//     }
// };


// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150
// 121. best time to sell stock 

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int min_val=prices[0];
//         int current_val=0;
//         int max_Val=0;

//         for (int i=0;i<prices.size();i++){
            
//             //std::cout<<prices[i]<<std::endl;

//             if (min_val>prices[i]){
//                 min_val=prices[i];
//                 //std::cout<<"min: "<<min_val<<std::endl;
//             }
            
//             current_val=prices[i]-min_val;
            
//             if (max_Val<current_val){
//                 max_Val=current_val;
//                 //std::cout<<"max: "<<max_Val<<std::endl;
//             }
//         }
        
//         return max_Val;
//     }
// };

//===========leet 525. Contiguous Array ============================================================================================
// https://leetcode.com/problems/contiguous-array/description/?envType=daily-question&envId=2024-03-16

//Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
 
// Example 1:
// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
 
// Example 2:
// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<string>

// class Solution {
// public:
//     int findMaxLength(std::vector<int>& nums) {
        
//         std::cout<<*nums.end()<<std::endl;
//         std::cout<<*nums.begin()<<std::endl;
        
//         std::cout<<"[";
//         std::vector<int> soln;
//         for(int i:nums){
//             std::cout<<i;
//                if ()
//             {

//             }else if (){
                
//             }
//         }
//         std::cout<<"]";
//         //'\n';
//         std::cout<<std::endl;
//         return 0;
        
//     }
// };


// int main()
// {
//     //std::cout<<"Hello World";
//     std::vector<int> nums= {0,1,0,1};
//     //int nums= [0,1,0];
//     Solution s1;
//     s1.findMaxLength(nums);
    
//     return 0;
// }



//===========leet 741. cherry-pickup 2 ============================================================================================
//https://leetcode.com/problems/cherry-pickup-ii/description/?envType=daily-question&envId=2024-02-11


//===========leet 741. cherry-pickup 1 ============================================================================================
//https://leetcode.com/problems/cherry-pickup/description/


//===========leet 13. Roman to Integer ============================================================================================
//https://leetcode.com/problems/roman-to-integer/solutions/3651672/best-method-c-java-python-beginner-friendly/

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<string>
// #include<map>

// class Solution {
// public:
// int romanToInt(std::string s) 
// {
//       std::map<std::string,int> romAndIntKey {{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D" ,500},{"M",1000}};
//       int result=0;
//       std::vector<int16_t>arr={};
//       int size=s.size();
//       //std::cout<<"size: "<<size<<std::endl;

//         if(0<s.size())
//         {
//           for(int i=0;i<s.size();++i)
//           {
           

//               char singleChar= s[i];
//               std::string firstVal(1,singleChar); //character to string 
//               result=result+romAndIntKey[firstVal];

//             //If the numeral on the right is greater than the current numeral, 
//             //subtract the current numeral’s value (e.g., IV = 5 - 1 = 4).


//              //std::cout<<s[i]<<std::endl;
//             //std::cout<<s.at(i)<<std::endl;
//             //std::cout<<romAndIntKey[firstVal]<<std::endl;
//             //arr.pushback(romAndIntKey[singleChar]);
//             //std::vector<int> romanString= s.at(i);
//             // std::cout<<firstValue<<"\n";
//             // std::string firstVal(1,firstValue); //convert to str
//             // std::cout<<romAndIntKey[firstVal]<<"\n";
//             //result =result*10 + romAndIntKey[firstValue];
//             //++result;
//             //return 0;
//           }

//           //std::cout<<result<<"\n";
//         // if(s.size()==1){
//         //   for (int i=0;i<1;i++){
//         //     auto it = romAndIntKey.find(s); it != romAndIntKey.end();
//         //     result= it->second;
//         //   }
//         // }else if(s.size()==2){
//         //   char firstValue=s.at(0); //get the first string as char
//         //   std::string firstVal(1,firstValue); //convert to str
//         //   int num1= romAndIntKey[firstVal];//convert to int 
//         //   char  secondValue=s[1];
//         //   std::string secVal(1,secondValue);
//         //   int num2= romAndIntKey[secVal];
//           // std::cout<<firstVal<<" : "<<secVal<<"\n";
//           // std::cout<<romAndIntKey[firstVal]<<" : "
//           //           <<romAndIntKey[secVal]<<"\n";
//           //result=num1+num2;
//           // std::string firstChar=std::to_string(romAndIntKey.at("s[0]"));
//           // std::string secondChar=std::to_string(romAndIntKey.at("s[1]"));
//           //result=std::stoi(firstVal+romAndIntKey[secVal]);

//         }else{
//           result=0;
//         }
//       return result;
//     }
//     //}
// };

// int main(){
//   Solution s1;
//   std::cout<<s1.romanToInt("I")<<std::endl;
//   std::cout<<s1.romanToInt("II")<<std::endl;
//   std::cout<<s1.romanToInt("C")<<std::endl;
//   std::cout<<s1.romanToInt("XV")<<std::endl;
//   std::cout<<s1.romanToInt("XII")<<std::endl;
//   std::cout<<s1.romanToInt("MCMXCIV")<<std::endl;
// }



//===========leet 234. Palindrome Linked List ============================================================================================
//https://leetcode.com/problems/palindrome-linked-list/description/?envType=daily-question&envId=2024-03-22

//Leet 409. Longest Palindrome

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
// palindrome that can be built with those letters.Letters are case sensitive, for example, "Aa" is not considered a palindrome.

// Example 1:
// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
// Example 2:
// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.
 
// Constraints:
// 1 <= s.length <= 2000
// s consists of lowercase and/or uppercase English letters only

// #include <string>
// #include <iostream>

// class Solution {
// public:
//     int longestPalindrome(std::string s) {
//       if (s.size()==0){
//         return 0;
//       }

//       return 1;

//     }

// int main (){}
        
// };

//===========leet 9. Palindrome Number ============================================================================================
//https://leetcode.com/problems/palindrome-number/description/
// Given an integer x, return true if x is a palindrome , and false otherwise.
//palindrome is a word, phrase, or sequence that reads the same backward as forward, e.g., madam or nurses run

// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

// Example 3:
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

// Constraints:
// -231 <= x <= 231 - 1
// Follow up: Could you solve it without converting the integer to a string?


// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<string>

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         std::string str= std::to_string(x);
//         std::string strcpy=str;
//         std::reverse(strcpy.begin(),strcpy.end());
//         if(x < 0) {
//             return false;
//         }else if (str==strcpy){
//             return true;
//         }else{
//             return false;
//         }
//     }
// };

// int main()
// {
//   Solution s1;
//   int x=  121;
//   int y= -121;
//   int z= 10;
//   std::cout<<s1.isPalindrome(x)<<'\n';
//   std::cout<<s1.isPalindrome(y)<<'\n';
//   std::cout<<s1.isPalindrome(z)<<'\n';
// //working 
// }

//others
//Approach 1: Reversing the Entire Number
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) {
//             return false;
//         }

//         long long reversed = 0;
//         long long temp = x;

//         while (temp != 0) {
//             int digit = temp % 10;
//             reversed = reversed * 10 + digit;
//             temp /= 10;
//         }

//         return (reversed == x);
//     }
// };
//Approach 2: Reversing Half of the Number
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0 || (x != 0 && x % 10 == 0)) {
//             return false;
//         }

//         int reversed = 0;
//         while (x > reversed) {
//             reversed = reversed * 10 + x % 10;
//             x /= 10;
//         }
//         return (x == reversed) || (x == reversed / 10);
//     }
// };

// =========Leet 647 Palindromic Substrings============================================================================================
// https://leetcode.com/problems/palindromic-substrings/description/ 
// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters


// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<string>

// class Solution {
// public:
//     int countSubstrings(std::string s) {
//         int count=2;
//         // std::cout<<s[0]<<'\n';
//         // std::cout<<s[1]<<'\n';
//         // std::cout<<s[2]<<'\n';
//         //std::cout<<s.length()<<'\n';

//         std::string reverseS=s;
//         std::reverse(reverseS.begin(),reverseS.end());
//         // for(char j:reverseS){
//         //     std::cout<<j;
//         // }
//     // std::cout<<"\n";
//     //     for(int k=s.length();k>0;k--){
//     //         std::cout<<s.at(k);
//     //     }
//     std::cout<<"\n";    
//         for (char i:s){
           
//             //count=i[0]
//             if (s[0]==i){
//                  std::cout<<i;
//                  count++;
//             }
//         }
//     std::cout<<"\n";    
//     return count;
        
//     }
// };


// int main()
// {
//   Solution s1;
//   std::string str = "abc";
//   std::cout<<s1.countSubstrings(str);
// }



// ======Leet code 1637. Widest Vertical Area Between Two Points Containing No Points===============================================================================================================
//https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21

// #include <iostream>
// #include <algorithm>
// #include <vector>

// class Solution {
// public:
//     int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
//         std::vector<int> yAxis;

//         // Extract y values
//         for (const auto& point : points) {
//             yAxis.push_back(point[1]);
//         }

//         // Print y values using a range-based for loop
//         std::cout << "Y Axis: ";
//         for (int y : yAxis) {
//             std::cout << y << " ";
//         }
//         std::cout << '\n';

//         // Sort y values
//        std::sort(yAxis.begin(), yAxis.end());

//       // Print y values using a range-based for loop
//         std::cout << "Y Axis: ";
//         for (int y : yAxis) {
//             std::cout << y << " ";
//         }
//         std::cout << '\n';

//         // Find the maximum difference between adjacent y values
//         int maxWidth = 0;
//         for (size_t i = 1; i < yAxis.size(); ++i) {
//             int currentWidth = yAxis[i] - yAxis[i - 1];
//             maxWidth = std::max(maxWidth, currentWidth);
//         }

//         return maxWidth;
//     }
// };

// //{{8,7},{9,9},{7,4},{9,7}}

// int main() {
//     Solution s1;
//     std::vector<std::vector<int>> coordinates = {{8,7},{9,9},{7,4},{9,7}};
//     int result = s1.maxWidthOfVerticalArea(coordinates);
//     std::cout << "Max Width: " << result << std::endl;
//     return 0;
// }

// /* Hacker rank - For Loop
// # Practice
// ## 1) For Loop
// ### In this challenge, you will use a for loop to increment a variable through a range.
// #### Input:
// - You will be given two positive integers, a and b (a =<b ), separated by a newline.
// #### Output:
// - For each integer n in the inclusive interval[a,b] :
//   - if 1=<n=<9 then print english representation of it in lower case. i.e 1 "one", 2 "two" ...
//   - If n>9 and even number print "even"
//   - if n>9 and odd number, print "odd"
// #### Example
// Input:
// 8
// 11
// output:
// eight
// nine
// even
// odd

// INPUT:
// 3 15
// OUTPUT
// three
// four
// five
// six
// seven
// eight
// nine
// even    //10
// odd    //11
// even    //12
// odd     //13
// even    //14
// odd     //15
// */


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

// compile: g++ -std=c++11 -o pointers pointers.cpp
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

//Leet code
//1637. Widest Vertical Area Between Two Points Containing No Points
//https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21

// #include <iostream>
// #include <algorithm>
// #include <vector>

// class Solution {
// public:
//     int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
//         std::vector<int> yAxis;

//         // Extract y values
//         for (const auto& point : points) {
//             yAxis.push_back(point[1]);
//         }

//         // Print y values using a range-based for loop
//         std::cout << "Y Axis: ";
//         for (int y : yAxis) {
//             std::cout << y << " ";
//         }
//         std::cout << '\n';

//         // Sort y values
//        std::sort(yAxis.begin(), yAxis.end());

//       // Print y values using a range-based for loop
//         std::cout << "Y Axis: ";
//         for (int y : yAxis) {
//             std::cout << y << " ";
//         }
//         std::cout << '\n';

//         // Find the maximum difference between adjacent y values
//         int maxWidth = 0;
//         for (size_t i = 1; i < yAxis.size(); ++i) {
//             int currentWidth = yAxis[i] - yAxis[i - 1];
//             maxWidth = std::max(maxWidth, currentWidth);
//         }

//         return maxWidth;
//     }
// };

// //{{8,7},{9,9},{7,4},{9,7}}

// int main() {
//     Solution s1;
//     std::vector<std::vector<int>> coordinates = {{8,7},{9,9},{7,4},{9,7}};
//     int result = s1.maxWidthOfVerticalArea(coordinates);
//     std::cout << "Max Width: " << result << std::endl;
//     return 0;
// }







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

//  Leetcode:  Two sum 
// https://leetcode.com/problems/two-sum/description/ 

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
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

// #include<iostream>
// #include<vector>
// #include<algorithm>

// class Solution {
// public:
//     int reductionOperations(std::vector<int>& nums) {
//         int min = 0;
//         std::sort(nums.begin(),nums.end());
//         for(int i =0; i < nums.size(); ++i)  {
//           std::cout<<nums.at(i)<<" "<<std::endl;
//         } 

//         for (int j:nums){
//             std::cout<<j<<std::endl;
//         }
//         return 0;
//     }
// };

// int main()
// {
//   Solution s1;
//  std::vector<int> num = {5,1,3};
//   //std::vector<int> num = {1,1,2,2,3};
//   s1.reductionOperations(num);

// }
///----------------------------------------------------
