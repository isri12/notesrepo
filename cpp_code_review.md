Study Links Topics
Level 1
- Array and Linked List
- set and maps
- STL container
- gcc debuger
- codepath
- uml
- socket programming
- object oriented C++
------------------------------------------------
- [singelton] (https://www.codeproject.com/Articles/987473/Unit-Testing-a-Singleton-in-Cplusplus)
- Friend
- Virtual fun
- explicit
- constecpr

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
- defines a Student structure, some functions to prompt the user for input, and a function to calculate the student's average grade
```cpp
#include <iostream>
#include <string>

struct Student {
    int id;
    std::string f_name;
    std::string l_name;
    int n_assignments;
    double *grades;
};

int promptInt(const std::string &message, int min, int max) {
    int value;
    do {
        std::cout << message;
        std::cin >> value;
    } while (value < min || value > max);
    return value;
}

double promptDouble(const std::string &message, double min, double max) {
    double value;
    do {
        std::cout << message;
        std::cin >> value;
    } while (value < min || value > max);
    return value;
}

void calculateStudentAverage(Student &student, double &avg) {
    double total = 0.0;
    for (int i = 0; i < student.n_assignments; i++) {
        total += student.grades[i];
    }
    avg = total / student.n_assignments;
}

int main() {
    Student student;
    double average;

    student.id = 1;
    student.f_name = "John";
    student.l_name = "Doe";

    student.n_assignments = promptInt("Enter the number of assignments: ", 1, 100);

    student.grades = new double[student.n_assignments];
    for (int i = 0; i < student.n_assignments; i++) {
        student.grades[i] = promptDouble("Enter grade for assignment " + std::to_string(i + 1) + ": ", 0.0, 100.0);
    }

    calculateStudentAverage(student, average);

    std::cout << "Student ID: " << student.id << std::endl;
    std::cout << "First Name: " << student.f_name << std::endl;
    std::cout << "Last Name: " << student.l_name << std::endl;
    std::cout << "Average Grade: " << average << std::endl;

    // Clean up dynamic memory
    delete[] student.grades;

    return 0;
}

```
----------------------------------------------------------------------------------------------------------------
```cpp
class Config {
public:
    static Config& getinstance() {
        static Config instance; // This will be created only once
        return instance;
    }

    void setSetting(const std::string& key, const std::string& value) {
        settings[key] = value;
    }

    std::string getSetting(const std::string& key) {
        if (settings.find(key) != settings.end()) {
            return settings[key];
        }
        return "Setting not found";
    }

private:
    std::map<std::string, std::string> settings;

    // Private constructor to prevent external instantiation
    Config() {
        // Initialize any default settings here
    }

    // Private copy constructor and assignment operator to prevent copying
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
};

int main() {
    Config& config = Config::getinstance();

    config.setSetting("ServerIP", "192.168.0.1");
    config.setSetting("Port", "8080");

    std::cout << "Server IP: " << config.getSetting("ServerIP") << std::endl;
    std::cout << "Port: " << config.getSetting("Port") << std::endl;

    return 0;
}
```
----------------------------------------------------------------------------------------------------------------
```cpp
#include <gtest/gtest.h>
#include "Config.h" // Assuming you have a Config class defined in Config.h

class ConfigTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize the config instance before each test
        config = &Config::getinstance();
    }

    // Member variables
    Config* config;
};

TEST_F(ConfigTest, TestSettingAndGettingValues) {
    config->setSetting("Key1", "Value1");
    config->setSetting("Key2", "Value2");

    EXPECT_EQ(config->getSetting("Key1"), "Value1");
    EXPECT_EQ(config->getSetting("Key2"), "Value2");
}

TEST_F(ConfigTest, TestDefaultValueForNonExistentSetting) {
    EXPECT_EQ(config->getSetting("NonExistentKey"), "Setting not found");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```
----------------------------------------------------------------------------------------------------------------
In this example, the Config class provides functionality to manage and manipulate configuration data, including loading from a file, setting values, getting values, and allowing subscribers to be notified of changes to specific keys. The getInstance method follows the singleton pattern to ensure there is only one instance of the Config class.
```cpp
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <functional>

class Config {
public:
    // Get the singleton instance of Config
    static Config* getInstance() {
        if (instance == nullptr) {
            instance = new Config();
        }
        return instance;
    }

    // Check if the configuration is empty
    bool isEmpty() const {
        return data.empty();
    }

    // Set a configuration key-value pair
    void set(const std::string& key, const std::string& value) {
        data[key] = value;
        // Notify subscribers that a value has been set
        notifySubscribers(key, value);
    }

    // Get the value associated with a configuration key
    std::string get(const std::string& key) const {
        if (data.find(key) != data.end()) {
            return data.at(key);
        }
        return "";
    }

    // Load configuration from a file
    void loadFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                size_t pos = line.find('=');
                if (pos != std::string::npos) {
                    std::string key = line.substr(0, pos);
                    std::string value = line.substr(pos + 1);
                    set(key, value);
                }
            }
            file.close();
        }
    }

    // Subscribe to changes in configuration values
    void subscribe(const std::string& key, std::function<void(const std::string&, const std::string&)> callback) {
        subscribers[key].push_back(callback);
    }

    // Unsubscribe from changes in configuration values
    void unsubscribe(const std::string& key, std::function<void(const std::string&, const std::string&)> callback) {
        if (subscribers.find(key) != subscribers.end()) {
            auto& callbacks = subscribers[key];
            auto it = std::remove_if(callbacks.begin(), callbacks.end(),
                [&callback](const std::function<void(const std::string&, const std::string&)>& c) {
                    return &c == &callback;
                }
            );
            if (it != callbacks.end()) {
                callbacks.erase(it, callbacks.end());
            }
        }
    }

private:
    std::map<std::string, std::string> data;
    std::map<std::string, std::vector<std::function<void(const std::string&, const std::string&)>> subscribers;

    // Singleton instance
    static Config* instance;

    // Private constructor to enforce the singleton pattern
    Config() {}

    // Notify subscribers about a configuration change
    void notifySubscribers(const std::string& key, const std::string& value) {
        if (subscribers.find(key) != subscribers.end()) {
            for (const auto& callback : subscribers[key]) {
                callback(key, value);
            }
        }
    }
};

// Initialize the singleton instance as nullptr
Config* Config::instance = nullptr;

int main() {
    Config* config = Config::getInstance();
    config->loadFile("config.txt");
    std::cout << "Loaded config file." << std::endl;

    // Example of subscribing to a configuration key
    config->subscribe("ServerAddress", [](const std::string& key, const std::string& value) {
        std::cout << "Configuration key " << key << " has been updated to: " << value << std::endl;
    });

    // Set a configuration value
    config->set("ServerAddress", "example.com");

    // Get a configuration value
    std::string serverAddress = config->get("ServerAddress");
    std::cout << "Server Address: " << serverAddress << std::endl;

    return 0;
}

```

```cpp
#include <gtest/gtest.h>
#include "Config.h" // Include the header for your Config class

class ConfigTest : public ::testing::Test {
protected:
    void SetUp() override {
        config = Config::getInstance();
        config->loadFile("test_config.txt"); // Load test configuration from a file
    }

    // Member variables
    Config* config;
};

TEST_F(ConfigTest, TestSingleton) {
    Config* config2 = Config::getInstance(); // Get another instance

    // Both instances should be the same since it's a singleton
    EXPECT_EQ(config, config2);
}

TEST_F(ConfigTest, TestEmpty) {
    // Initially, the config should be empty
    EXPECT_TRUE(config->isEmpty());

    // Set a configuration value, and it should no longer be empty
    config->set("TestKey", "TestValue");
    EXPECT_FALSE(config->isEmpty());
}

TEST_F(ConfigTest, TestSetAndGet) {
    // Set a configuration value and then retrieve it
    config->set("TestKey", "TestValue");
    EXPECT_EQ(config->get("TestKey"), "TestValue");
}

TEST_F(ConfigTest, TestLoadFile) {
    // Load a configuration file, and check if a specific key is present
    config->loadFile("test_config.txt");
    EXPECT_EQ(config->get("TestKeyFromFile"), "TestValueFromFile");
}

TEST_F(ConfigTest, TestSubscribeAndNotify) {
    std::string updatedKey;
    std::string updatedValue;

    // Subscribe to changes for a specific key
    config->subscribe("TestKey", [&updatedKey, &updatedValue](const std::string& key, const std::string& value) {
        updatedKey = key;
        updatedValue = value;
    });

    // Set a configuration value and check if the subscription works
    config->set("TestKey", "UpdatedValue");
    EXPECT_EQ(updatedKey, "TestKey");
    EXPECT_EQ(updatedValue, "UpdatedValue");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

```

----------------------------------------------------------------------------------------------------------------
- You can iterate over a set of string keys and check for the presence of key1 and key2. If both keys are found, you can print a message indicating that they have been found. Here's an example of how you can do this in C++:
```cpp
#include <iostream>
#include <set>
#include <string>

int main() {
      
    
    std::set<std::string> keySet{"key1","ke2","key3","key4","key5"};

    // // Add keys to the set
    // keySet.insert("key1");
    // keySet.insert("key2");
    // keySet.insert("key3");
    // keySet.insert("key4");

    // Print a message if both keys are found
for ( std::set<std::string>::iterator it=keySet.begin(); it!=keySet.end(); ++it)
{
    if (*it == "key1") {
        std::cout << "key1 and key2 found" << std::endl;   //key1 and key2 found
    }

}

    //std::set<std::string>::iterator it2;
    // Check if key1 present
    std::set<std::string>::iterator it2 = keySet.find("key1"); //!= keySet.end();
    std::cout<<*it2<<std::endl;
 
    return 0;
}

```
- Config class with the member functions loadRecovery and load:

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Config {
public:
    // Load a configuration file with a specified prefix into a map
    void load(std::string const &file_name, std::string const &prefix, std::map<std::string, std::string> &map) {
        std::ifstream file(file_name);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << file_name << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            // Check if the line starts with the specified prefix
            if (line.find(prefix) == 0) {
                // Extract the key-value pair
                size_t equalSignPos = line.find('=');
                if (equalSignPos != std::string::npos) {
                    std::string key = line.substr(prefix.length(), equalSignPos - prefix.length());
                    std::string value = line.substr(equalSignPos + 1);
                    map[key] = value;
                }
            }
        }

        file.close();
    }

    // Load a recovery configuration file into the map
    void loadRecovery(std::map<std::string, std::string> &map) {
        load("recovery.conf", "recovery.", map);
    }
};

int main() {
    Config config;

    std::map<std::string, std::string> configMap;

    // Load a recovery configuration file
    config.loadRecovery(configMap);

    // Print the loaded configuration
    for (const auto& pair : configMap) {
        std::cout << pair.first << " = " << pair.second << std::endl;
    }

    return 0;
}

```
```cpp
#include <gtest/gtest.h>
#include "Config.h" // Include the header for your Config class

class ConfigTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup any common test fixtures here if needed
    }
};

TEST_F(ConfigTest, TestLoad) {
    Config config;

    std::map<std::string, std::string> configMap;
    config.load("test_config.txt", "test_prefix.", configMap);

    // You can add assertions to check if the loaded configuration matches the expected values.
    // For example, assume "test_config.txt" contains "test_prefix.key1=value1" and "test_prefix.key2=value2".
    
    EXPECT_EQ(configMap["key1"], "value1");
    EXPECT_EQ(configMap["key2"], "value2");
}

TEST_F(ConfigTest, TestLoadNonExistentFile) {
    Config config;

    std::map<std::string, std::string> configMap;
    config.load("non_existent_file.txt", "prefix.", configMap);

    // Expect the map to be empty since the file does not exist
    EXPECT_TRUE(configMap.empty());
}

TEST_F(ConfigTest, TestLoadEmptyFile) {
    Config config;

    std::map<std::string, std::string> configMap;
    config.load("empty_config.txt", "prefix.", configMap);

    // Expect the map to be empty since the file is empty
    EXPECT_TRUE(configMap.empty());
}

TEST_F(ConfigTest, TestLoadWithComments) {
    Config config;

    std::map<std::string, std::string> configMap;
    config.load("config_with_comments.txt", "prefix.", configMap);

    // Expect the map to contain key-value pairs without comments
    EXPECT_EQ(configMap["key1"], "value1");
    EXPECT_EQ(configMap["key2"], "value2");
    // Commented out key should not be present
    EXPECT_EQ(configMap.find("key3"), configMap.end());
}

TEST_F(ConfigTest, TestLoadDuplicateKeys) {
    Config config;

    std::map<std::string, std::string> configMap;
    config.load("config_with_duplicates.txt", "prefix.", configMap);

    // Expect the map to contain the last occurrence of each key
    EXPECT_EQ(configMap["key1"], "value3");
    EXPECT_EQ(configMap["key2"], "value2");
}

TEST_F(ConfigTest, TestLoadWithoutPrefix) {
    Config config;

    std::map<std::string, std::string> configMap;
    config.load("config_without_prefix.txt", "", configMap);

    // Expect the map to contain key-value pairs without a prefix
    EXPECT_EQ(configMap["key1"], "value1");
    EXPECT_EQ(configMap["key2"], "value2");
}

```
----------------------------------------------------------------------------------------------------------------

- map vs set vs vector vs pair

```cpp
#include <iostream>
#include <set>
#include<map>
#include<vector>
#include <string>
//using namespace std;

int main()
{
    // Simple comparison demo.
    //std::set<std::string> example = {"key1", "key2", "key3", "key4","key5"};

    std::map<std::string, std::string> m{{"key6", "val6"}, {"key7", "val7"}, {"key8", "val8"}};

//map
    
    //   std::cout << "key7 " << m.find("key7")->second << '\n';
    //   //std::cout<<""<<;
      
    //   //int k;
    //   std::string k;
    //   std::cout << typeid(k).name() << std::endl;
    //   std::cout << typeid(m.find("key6")->second).name() << std::endl;
  
       
    //   if (auto search = m.find("key6"); search != m.end())
    //   {
    //     std::cout<< search->first << ' ' << search->second << '\n';
    //   }
    //     else
    //     {
    //     std::cout << "Not found\n";
    //     }
        
        
//vector

    std::vector<std::string> key, value;
    for(std::map<std::string,std::string>::iterator it = m.begin(); it != m.end(); ++it) 
    {
        key.push_back(it->first);
        value.push_back(it->second);
        //std::cout << "Key: " << it->first << std::endl;
        //std::cout << "Value: " << it->second << std::endl;
    }

    for (auto i : key)
        std::cout << ' ' << i;
    std::cout << '\n';
    
    std::cout<<key[0]<<std::endl;
    std::cout<< key.at(0) << '\n';
    
    
 //set   
    std::set<std::string> keys;
     for(std::map<std::string,std::string>::iterator itr = m.begin(); itr != m.end(); ++itr) 
    {
        keys.insert(itr->first);
        std::cout << "Key: " << itr->first << std::endl;
        //std::cout << "Value: " << it->second << std::endl;
    }
    
    std::string lk = {"key6"};
    std::string str{"NULL"} ;
    if (auto search = keys.find(lk); search != keys.end()){
        std::cout << "Found " <<*search<< '\n';
        str=*search;
    }
    else{
        std::cout << "Not found\n";
    }
//   bool check;
//   if (char == key.at(0))
    
      // verifying the result
      
    std::cout <<str<<"==";
    std::cout <<key.at(0) <<"\n";
      
    if (str == key.at(0))
    {
        // printing success message if found
        std::cout << "Substring Found" << std::endl;
    }
    else
    {
        // else printing the error message
        std::cout << "Substring not Found" << std::endl;
    }
    
    
    
    //std::cout<<keys[0]<<std::endl;
    //std::cout<< keys.at(0) << '\n';
    // if (key.at(0) == "key6")
    // {
    //     std::cout<<"found it"
    // }
        
        
    //  for (auto i : key){    
    // bool isFound = key.find("key") != string::npos;

    // // verifying the result
    // if (isFound)
    // {
    //     // printing success message if found
    //     cout << "Substring Found" << endl;
    // }
    // else
    // {
    //     // else printing the error message
    //     cout << "Substring not Found" << endl;
    // }   
    //  }    
    
    // if (std::find(key.begin(), key.end(), "k") != key.end()) {
    //     std::cout << "Element found";
    // }
    // else {
    //     std::cout << "Element not found";
    // }
    
    // size_t size=key.size();
    // std::cout << size;
    // std::string my_str= "k";
    
    // for ( int i = 0; i < size; i++ )
    // {
    //     if (strcmp(my_str, key[i]) == 0 )
    //         {
    //         std::cout << "Element found";
    //         }
    //      else 
    //          {
    //      std::cout << "Element not found";
    //         }   
        
    // }    
        
        
}   
        
    
    //test m["key6"]=10;


 
//   auto p = m.equal_range("key6");
    
//     for (auto& q = p.first; q != p.second; ++q)
//         std::cout << "m[" << q->first << "] = " << q->second << '\n';
    
    
//     //std::set<std::string>::iterator it2 = m.find("key6");
//     std::string it2 = m.find("key6");
//     std::cout<<*it2<<std::endl; 
    //std::string expectedkey{NULL};
    
    // std::cout <<expectedkey<<std::endl;

    // std::map<char,int>::iterator it;
    
     //std::set<std::string>::iterator it2;
    // Check if key1 present
    // std::set<std::string>::iterator it2 = m.equal_range("key6");
    // std::cout<<*it2<<std::endl;   
        

    // if (auto search = example.find(3); search != example.end())
    //     std::cout << "Found " << (*search) << '\n';
    // else
    //     std::cout << "Not found\n";
    
    
// std::set< std::string >::iterator itr = example.find("key3");
//     if (itr != example.end()) 
//     {
//   // do something with *it
//   std::cout<<"found it!"<<itr[0]<<std::endl;
//     }

// std::set<std::string> keys;
// for (auto iter = example.begin(); iter!=example.end();++iter)
// {
    
   
//     if (*iter=="key2")
//     {
//       //std::cout<<*iter<<std::endl;
//       keys.insert(*iter);  
//     }
    
//     if (*iter=="key4")
//     {
//       //std::cout<<*iter<<std::endl;
//       keys.insert(*iter);  
//     }
// }


// for (auto iter2 = keys.begin(); iter2!=keys.end();++iter2)
// {
//       std::cout<<*iter2<<std::endl;
    
// }

//}

----------------------------------------------------------------------------------------------------------------
 ```cpp
#include <iostream>
#include <string>
#include <set>

// Define a callback class for testing
class Callback {
public:
    void add(const std::string& key) {
        std::cout << "Callback received key: " << key << std::endl;
    }
};

class Config {
public:
    using CallbackType = Callback; // Assuming Callback is the callback type

    void subscribe(CallbackType& callback) {
        std::set<std::string> Keys = {"key1", "key2", "key3", "key4", "key5"};

        for (const std::string& key : Keys) {
            callback.add(key);
        }

        callback.add("keys");
    }
};

int main() {
    Config config;
    Callback callback;

    // Subscribe to the config and trigger the callback
    config.subscribe(callback);

    return 0;
}

```
```cpp
#include <gtest/gtest.h>
#include "config.h"  // Include your config class header here
#include "callback.h"  // Include the header for your callback type here

// Define a mock Callback class for testing
class MockCallback : public Callback {
public:
    void add(const std::string& key) {
        keysReceived.push_back(key);
    }

    const std::vector<std::string>& getKeysReceived() const {
        return keysReceived;
    }

private:
    std::vector<std::string> keysReceived;
};

TEST(ConfigSubscribeTest, CallbackReceivesExpectedKeys) {
    Config config;  // Create an instance of the config class

    // Create a mocked Callback object for testing
    MockCallback mockCallback;

    // Subscribe to the config and trigger the subscribe function
    config.subscribe(mockCallback);

    // Check if the Callback received the expected keys
    const std::vector<std::string>& keysReceived = mockCallback.getKeysReceived();
    const std::vector<std::string> expectedKeys = {"key1", "key2", "key3", "key4", "key5"};
    EXPECT_EQ(keysReceived, expectedKeys);

    // Check if the Callback received the string "keys"
    ASSERT_FALSE(keysReceived.empty());
    EXPECT_EQ(keysReceived.back(), "keys");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

```
```cpp
#include <gtest/gtest.h>
#include "config.h"  // Include your config class header here

TEST(ConfigSubscribeTest, CallbackFunctionIsCalled) {
    Config config;  // Create an instance of the config class

    // Define a callback function that we can track if it's called
    bool callbackCalled = false;
    Config::CallbackType callback = [&callbackCalled](void, std::string) {
        callbackCalled = true;
    };

    // Subscribe and trigger the callback
    config.subscribe(callback);

    // Check if the callback was called
    EXPECT_TRUE(callbackCalled);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


#include <gtest/gtest.h>
#include "config.h"  // Include your config class header here
#include "callback.h"  // Include the header for your callback type here

// Mocked callback class for testing
class MockCallback {
public:
    void add(const std::string& message) {
        // Simulate adding a message to the callback
        messages.push_back(message);
    }

    const std::vector<std::string>& getMessages() const {
        return messages;
    }

private:
    std::vector<std::string> messages;
};

TEST(ConfigSubscribeTest, CallbackFunctionAddsMessage) {
    Config config;  // Create an instance of the config class

    // Create a mocked callback object for testing
    MockCallback mockCallback;

    // Subscribe and trigger the subscribe function
    config.subscribe(mockCallback);

    // Check if the message was added to the callback
    const std::vector<std::string>& messages = mockCallback.getMessages();
    ASSERT_EQ(messages.size(), 1);
    EXPECT_EQ(messages[0], "message");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


#include <iostream>
#include <set>
#include <gtest/gtest.h>

bool CompareStringSets(const std::set<std::string>& set1, const std::set<std::string>& set2) {
    return set1 == set2;
}

TEST(StringSetComparison, SetsAreEqual) {
    std::set<std::string> set1 = {"apple", "banana", "cherry"};
    std::set<std::string> set2 = {"banana", "cherry", "apple"};
    
    EXPECT_TRUE(CompareStringSets(set1, set2));
}

TEST(StringSetComparison, SetsAreNotEqual) {
    std::set<std::string> set1 = {"apple", "banana", "cherry"};
    std::set<std::string> set2 = {"banana", "cherry", "date"};
    
    EXPECT_FALSE(CompareStringSets(set1, set2));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

```
```cpp
#include <iostream>
#include <set>
#include <string>

int main() {
    // Create a std::set of strings
    std::set<std::string> keys = {"key1", "key2", "key3", "key4", "key5"};

    // Define the character to check for
    char characterToCheck = '2';

    // Flag to indicate if the character exists
    bool characterExists = false;

    // Iterate through the strings in the set and check for the character
    for (const std::string& key : keys) {
        if (key.find(characterToCheck) != std::string::npos) {
            characterExists = true;
            break; // Exit the loop as soon as the character is found
        }
    }

    if (characterExists) {
        std::cout << "The character '" << characterToCheck << "' exists in at least one of the strings." << std::endl;
    } else {
        std::cout << "The character '" << characterToCheck << "' does not exist in any of the strings." << std::endl;
    }

    return 0;
}

```


```cpp
void config::subscribe(callback<void,std::string>::ClassType callback)

/*This code defines a function called subscribe that takes a callback object as an argument. The callback object is a function that takes a string as an argument and returns void. The function subscribe adds the callback object to a set of callback objects. */

std::set<std::string> Keys = {"key1", "key2", "key3", "key4","key5"};
for(std::set<std::string>::iterator itr = Keys.begin(); itr != Keys.end(); ++itr) 
{
    Callback -> callback(*itr);
}


config myConfig;
callback myCallback;

myConfig.subscribe(myCallback);

myCallback("Hello, world!");



#include <iostream>
#include <set>
#include <functional>

using namespace std;

class config {
public:
    void subscribe(callback<void, std::string>::ClassType callback) {
        callback_objects_.insert(callback);
    }

    void notify(const std::string& key) {
        for (const callback<void, std::string>::ClassType& callback : callback_objects_) {
            callback(key);
        }
    }

private:
    set<callback<void, std::string>::ClassType> callback_objects_;
};

void callback1(const std::string& key) {
    cout << "Callback 1 received key: " << key << endl;
}

void callback2(const std::string& key) {
    cout << "Callback 2 received key: " << key << endl;
}

int main() {
    config myConfig;

    callback<void, std::string>::ClassType callback1_lambda = [](const std::string& key) {
        cout << "Callback 1 lambda received key: " << key << endl;
    };

    myConfig.subscribe(callback1);
    myConfig.subscribe(callback2);
    myConfig.subscribe(callback1_lambda);

    myConfig.notify("key1");
    myConfig.notify("key2");

    return 0;
}

```
- flip bits
```cpp
#include <iostream>
#include <cstring>

class EndianFlipper {
public:
    virtual void flip(void* data, size_t size) {
        // Ensure data is not null and size is valid
        if (data == nullptr || size == 0) {
            std::cerr << "Invalid arguments for flip function." << std::endl;
            return;
        }

        char* bytes = static_cast<char*>(data);

        // Swap the bytes
        for (size_t i = 0; i < size / 2; ++i) {
            char temp = bytes[i];
            bytes[i] = bytes[size - 1 - i];
            bytes[size - 1 - i] = temp;
        }
    }
};

int main() {
    EndianFlipper flipper;

    int value = 123456789;

    std::cout << "Original value: " << value << std::endl;

    flipper.flip(&value, sizeof(value));

    std::cout << "Flipped value: " << value << std::endl;

    return 0;
}


#include <gtest/gtest.h>

class EndianFlipper {
public:
    virtual void flip(void* data, size_t size) {
        // Implementation of flip function
    }
};

TEST(EndianFlipperTest, FlipInteger) {
    EndianFlipper flipper;

    // Original integer value
    int value = 123456789;

    // Make a copy of the original value
    int originalValue = value;

    // Flip the endianess
    flipper.flip(&value, sizeof(value));

    // Check if the value has been flipped
    EXPECT_NE(originalValue, value);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```
about OPEN DIS

## DIS PDU in C++

DIS PDU (Distributed Interactive Simulation Protocol Data Unit) refers to the message format used in DIS simulations to exchange information between entities. If you're working with DIS in C++, there are a few resources and options available:

**Open-DIS-CPP:**

* A popular open-source library implementing the IEEE 1278.1 DIS protocol in C++.
* Provides classes and functions for creating, sending, receiving, and parsing DIS PDUs.
* Supports both DIS v6 and v7.
* GitHub repository: [https://github.com/open-dis/open-dis-cpp](https://github.com/open-dis/open-dis-cpp)
* Documentation: [https://github.com/open-dis/open-dis-cpp](https://github.com/open-dis/open-dis-cpp)

**Other Libraries:**

* **JDISLib:** [https://sourceforge.net/directory/?q=java](https://sourceforge.net/directory/?q=java) (Java library, but could be useful for understanding PDU structure)
* **EDIS:** [https://open-dis.sourceforge.net/DIS.html](https://open-dis.sourceforge.net/DIS.html) (commercial library)

**Resources:**

* **DIS Data Dictionary:** [https://ieeexplore.ieee.org/iel1/3700/10849/00499701.pdf](https://ieeexplore.ieee.org/iel1/3700/10849/00499701.pdf)
* **Tutorials:**
    * [https://github.com/open-dis/dis-tutorial](https://github.com/open-dis/dis-tutorial)
    * [https://sourceforge.net/p/kdis/wiki/Sending_a_Entity_State_PDU_Tutorial/](https://sourceforge.net/p/kdis/wiki/Sending_a_Entity_State_PDU_Tutorial/)

* What type of DIS PDU are you interested in? (Entity State, Fire, etc.)
* What tasks do you need to perform with DIS PDUs? (Creating, sending, receiving, parsing)
* Do you have any specific library or framework preferences?

It looks like you might be referring to the Distributed Interactive Simulation (DIS) protocol in the context of C++..

If you are interested in implementing DIS in C++, you may want to use a library that provides support for the DIS protocol. One such library is the Open-DIS library.

To use Open-DIS in C++, you can follow these general steps:

1. **Download Open-DIS:**
   Visit the Open-DIS GitHub repository and download or clone the source code: [Open-DIS GitHub](https://github.com/open-dis/open-dis)

2. **Build the Library:**
   Follow the instructions provided in the repository to build the Open-DIS library. This typically involves using a build system like CMake. Make sure to satisfy any dependencies mentioned in the documentation.

3. **Integrate with Your Project:**
   Once the library is built, you can integrate it into your C++ project. This involves linking against the Open-DIS library and including the necessary headers.

4. **Write Code Using Open-DIS:**
   Refer to the Open-DIS documentation and examples to understand how to use the library in your code. You will likely need to set up a DIS entity, manage communication, and handle the various data types used in the DIS protocol.

Here is a simple example using Open-DIS:

```cpp
#include <dis6/DISCpp.h>

int main() {
    // Initialize Open-DIS
    DIS::Initialize();

    // Create a DIS entity
    DIS::EntityStatePdu entityPdu;
    // Set up the entity data...

    // Send or receive DIS messages as needed

    // Shutdown Open-DIS when done
    DIS::Shutdown();

    return 0;
}
```

Remember that the specifics of using Open-DIS may depend on the version of the library you're using, so be sure to refer to the documentation provided with the library.


## Sending and Receiving a Simple DIS Entity State PDU in C++

This example demonstrates the basic steps for sending and receiving a DIS Entity State PDU in C++ using the Open-DIS-CPP library. It will also showcase setting entity properties and handling timestamps.

**Requirements:**

* Open-DIS-CPP library: [https://github.com/open-dis/open-dis-cpp](https://github.com/open-dis/open-dis-cpp): [https://github.com/open-dis/open-dis-cpp](https://github.com/open-dis/open-dis-cpp)
* DIS network connection (e.g., DIS server or another entity)

**Code:**

```cpp
#include <open-dis/entity.h>
#include <open-dis/simulation.h>

int main() {
  // Initialize Open-DIS-CPP
  open_dis::init();

  // Create a Simulation object
  open_dis::Simulation simulation;

  // Create an EntityState PDU
  open_dis::EntityStatePDU entityStatePdu;

  // Set entity properties
  entityStatePdu.getEntityID() = 1; // Unique ID for this entity
  entityStatePdu.getEntityLocation().setX(100.0); // X coordinate
  entityStatePdu.getEntityLocation().setY(200.0); // Y coordinate
  entityStatePdu.getLinearVelocity().setX(5.0); // X velocity

  // Set timestamp
  entityStatePdu.setTimestamp(open_dis::clock_type::now());

  // Send the PDU
  simulation.sendPdu(entityStatePdu);

  // Receive a PDU (example with blocking receive)
  open_dis::PDU receivedPdu;
  simulation.receivePdu(receivedPdu);

  // Check if received PDU is an EntityState PDU
  if (receivedPdu.getType() == open_dis::EntityType::ENTITY_STATE) {
    // Cast received PDU to EntityStatePDU
    open_dis::EntityStatePDU& receivedEntityStatePdu = static_cast<open_dis::EntityStatePDU&>(receivedPdu);

    // Print received entity properties
    std::cout << "Received Entity ID: " << receivedEntityStatePdu.getEntityID() << std::endl;
    std::cout << "Received Location (X, Y): " << receivedEntityStatePdu.getEntityLocation().getX() << ", "
              << receivedEntityStatePdu.getEntityLocation().getY() << std::endl;

    // Get and handle timestamp
    open_dis::clock_type receivedTimestamp = receivedEntityStatePdu.getTimestamp();
    std::cout << "Received Timestamp: " << receivedTimestamp << std::endl;
  }

  // Cleanup
  open_dis::fini();

  return 0;
}
```

**Explanation:**

* The code includes libraries for entity and simulation management.
* It creates an `EntityStatePDU` object and sets relevant properties like entity ID, location, and velocity.
* The timestamp is set using `open_dis::clock_type::now()`.
* The PDU is sent through the simulation object.
* A blocking receive call waits for a PDU and checks if it's an `EntityStatePDU`.
* If it's a matching PDU, the received properties and timestamp are printed.
* Finally, Open-DIS-CPP is cleaned up.

This is a basic example, and you can extend it further by:

* Using different PDU types and functionalities.
* Implementing non-blocking communication with event handlers.
* Handling specific entity properties and timestamp calculations based on your needs.

Remember to adjust the code and libraries based on your specific DIS environment and desired functionalities.


## DIS PDU Sending and Receiving with Entity Properties and Timestamps in C++

Here's a simplified example demonstrating sending and receiving a DIS Entity State PDU, setting entity properties, and handling timestamps in C++ using Open-DIS-CPP:

**1. Include necessary libraries:**

```cpp
#include <open-dis/open-dis.h>
#include <chrono>
```

**2. Define entity properties:**

```cpp
// Entity properties
int entityID = 1234;
ENTITY_TYPE entityType = PLATFORM_TYPE;
double x = 100.0;
double y = 200.0;
double z = 30.0;
double orientation = 0.0;
```

**3. Create and populate Entity State PDU:**

```cpp
// Create Entity State PDU
EntityStatePDU pdu;

// Set entity properties
pdu.exerciseID = 1;
pdu.entityID = entityID;
pdu.entityType = entityType;
pdu.simulationTime = std::chrono::system_clock::now().time_since_epoch().count(); // Get current time in DIS timestamp format
pdu.position.x = x;
pdu.position.y = y;
pdu.position.z = z;
pdu.orientation = orientation;

// Additional properties (optional)
// ...
```

**4. Send Entity State PDU:**

```cpp
// Create DIS network communication object
DISNetworkManager networkManager;

// Connect to DIS network (replace with your network configuration)
networkManager.connect("127.0.0.1", 3000);

// Send the PDU
networkManager.sendPDU(pdu);

// Disconnect from DIS network
networkManager.disconnect();
```

**5. Receive and process Entity State PDU:**

```cpp
// Receive PDU from network (replace with your receive logic)
EntityStatePDU receivedPDU = networkManager.receivePDU();

// Check if received PDU is an Entity State PDU
if (receivedPDU.pduType == PDU_ENTITY_STATE) {
  // Extract entity properties
  int receivedEntityID = receivedPDU.entityID;
  ENTITY_TYPE receivedEntityType = receivedPDU.entityType;
  double receivedX = receivedPDU.position.x;
  double receivedY = receivedPDU.position.y;
  double receivedZ = receivedPDU.position.z;
  double receivedOrientation = receivedPDU.orientation;

  // Process received information (e.g., update entity state)
  // ...
}
```

**Note:** This is a simplified example and may require further modifications depending on your specific needs and network configuration. Open-DIS-CPP provides extensive documentation and functionalities for more advanced DIS interactions.

**Additional points:**

* You can use Open-DIS-CPP functions to set and retrieve various entity properties within the PDU.
* The `simulationTime` field requires a specific format derived from the system clock.
* Error handling and network management are not covered in this basic example.

I hope this provides a basic understanding of sending and receiving DIS PDUs, setting entity properties, and handling timestamps in C++ using Open-DIS-CPP. Feel free to ask if you have any further questions or need more specific guidance based on your project requirements.



## DIS PDU Sending and Receiving with Entity Properties and Timestamps in C++

This example demonstrates sending and receiving a basic DIS Entity State PDU in C++ using Open-DIS-CPP. It sets simple entity properties and handles timestamps.

**Requirements:**

* Open-DIS-CPP library installed
* Basic understanding of DIS concepts and PDU structure

**Code:**

```cpp
#include <iostream>
#include <vector>

#include <opendis/entity/entity.h>
#include <opendis/pdu/entitystate.h>

using namespace opendis;

int main() {
  // Create an Entity object
  Entity entity(EntityType::PLATFORM, 1234);

  // Set some entity properties
  entity.setPosition(Vector3D(100, 200, 300));
  entity.setOrientation(EulerAngles(0, 45, 90));
  entity.setLinearVelocity(Vector3D(5, -10, 2));

  // Create an EntityState PDU
  EntityStatePDU pdu;

  // Set entity ID and timestamp
  pdu.setEntityId(entity.getEntityId());
  pdu.setTimestamp(time(nullptr));

  // Set entity properties in PDU fields
  pdu.setPosition(entity.getPosition());
  pdu.setOrientation(entity.getOrientation());
  pdu.setLinearVelocity(entity.getLinearVelocity());

  // Send the PDU (replace "network_interface" with your actual interface)
  pdu.send("network_interface");

  // Receiving PDU (omitted for brevity, see Open-DIS-CPP docs)

  return 0;
}
```

**Explanation:**

1. We create an `Entity` object with a specific type and ID.
2. We set some basic properties like position, orientation, and velocity.
3. We create an `EntityStatePDU` object.
4. We set the PDU's entity ID and timestamp.
5. We set the PDU's fields with the corresponding entity properties.
6. We send the PDU through a network interface (replace with your actual interface).

**Receiving PDU:**

Receiving and parsing a PDU is similar but involves receiving data from the network, creating a PDU object from the received data, and accessing its fields to extract entity information and timestamps. Refer to Open-DIS-CPP documentation for detailed receiving and parsing instructions.

**Note:** This is a simplified example and doesn't cover all aspects of DIS PDUs. Consult Open-DIS-CPP documentation and DIS specifications for more comprehensive information and advanced functionalities.

I hope this example provides a basic understanding of sending and receiving DIS PDUs with entity properties and timestamps in C++. Feel free to ask if you have any further questions or need clarification on specific parts.


unit test 

## DIS PDU Sending and Receiving with Entity Properties and Timestamps in C++

This example demonstrates sending and receiving a basic DIS Entity State PDU in C++ using Open-DIS-CPP. It sets simple entity properties and handles timestamps.

**Requirements:**

* Open-DIS-CPP library installed
* Basic understanding of DIS concepts and PDU structure

**Code:**

```cpp
#include <iostream>
#include <vector>

#include <opendis/entity/entity.h>
#include <opendis/pdu/entitystate.h>

using namespace opendis;

int main() {
  // Create an Entity object
  Entity entity(EntityType::PLATFORM, 1234);

  // Set some entity properties
  entity.setPosition(Vector3D(100, 200, 300));
  entity.setOrientation(EulerAngles(0, 45, 90));
  entity.setLinearVelocity(Vector3D(5, -10, 2));

  // Create an EntityState PDU
  EntityStatePDU pdu;

  // Set entity ID and timestamp
  pdu.setEntityId(entity.getEntityId());
  pdu.setTimestamp(time(nullptr));

  // Set entity properties in PDU fields
  pdu.setPosition(entity.getPosition());
  pdu.setOrientation(entity.getOrientation());
  pdu.setLinearVelocity(entity.getLinearVelocity());

  // Send the PDU (replace "network_interface" with your actual interface)
  pdu.send("network_interface");

  // Receiving PDU (omitted for brevity, see Open-DIS-CPP docs)

  return 0;
}
```

**Explanation:**

1. We create an `Entity` object with a specific type and ID.
2. We set some basic properties like position, orientation, and velocity.
3. We create an `EntityStatePDU` object.
4. We set the PDU's entity ID and timestamp.
5. We set the PDU's fields with the corresponding entity properties.
6. We send the PDU through a network interface (replace with your actual interface).

**Receiving PDU:**

Receiving and parsing a PDU is similar but involves receiving data from the network, creating a PDU object from the received data, and accessing its fields to extract entity information and timestamps. Refer to Open-DIS-CPP documentation for detailed receiving and parsing instructions.

**Note:** This is a simplified example and doesn't cover all aspects of DIS PDUs. Consult Open-DIS-CPP documentation and DIS specifications for more comprehensive information and advanced functionalities.

I hope this example provides a basic understanding of sending and receiving DIS PDUs with entity properties and timestamps in C++. Feel free to ask if you have any further questions or need clarification on specific parts.

## Unit GTest test_F for Sending and Receiving DIS PDUs

Here's an example of a `test_F` unit test using Google Test for the previous C++ code demonstrating sending and receiving DIS PDUs:

```cpp
#include "gtest/gtest.h"
#include "open-dis/open-dis.h"

class DISPDUTest : public ::testing::Test {
protected:
  DISNetworkManager networkManager;
  EntityStatePDU sentPDU;
  EntityStatePDU receivedPDU;

  virtual void SetUp() override {
    // Define entity properties
    sentPDU.exerciseID = 1;
    sentPDU.entityID = 1234;
    sentPDU.entityType = PLATFORM_TYPE;
    sentPDU.simulationTime = std::chrono::system_clock::now().time_since_epoch().count();
    sentPDU.position.x = 100.0;
    sentPDU.position.y = 200.0;
    sentPDU.position.z = 30.0;
    sentPDU.orientation = 0.0;

    // Connect to DIS network (replace with your network configuration)
    networkManager.connect("127.0.0.1", 3000);
  }

  virtual void TearDown() override {
    // Disconnect from DIS network
    networkManager.disconnect();
  }
};

TEST_F(DISPDUTest, SendAndReceiveEntityStatePDU) {
  // Send Entity State PDU
  networkManager.sendPDU(sentPDU);

  // Receive PDU from network
  receivedPDU = networkManager.receivePDU();

  // Verify received PDU is an Entity State PDU
  EXPECT_EQ(receivedPDU.pduType, PDU_ENTITY_STATE);

  // Verify received entity properties match sent properties
  EXPECT_EQ(receivedPDU.exerciseID, sentPDU.exerciseID);
  EXPECT_EQ(receivedPDU.entityID, sentPDU.entityID);
  EXPECT_EQ(receivedPDU.entityType, sentPDU.entityType);
  EXPECT_EQ(receivedPDU.position.x, sentPDU.position.x);
  EXPECT_EQ(receivedPDU.position.y, sentPDU.position.y);
  EXPECT_EQ(receivedPDU.position.z, sentPDU.position.z);
  EXPECT_EQ(receivedPDU.orientation, sentPDU.orientation);

  // Additional tests for specific properties or functionalities (optional)
  // ...
}
```

**Explanation:**

* This test defines a `DISPDUTest` fixture class that inherits from `::testing::Test`.
* The `SetUp` method sets up the test environment by creating DIS network manager and defining the Entity State PDU to be sent.
* The `TearDown` method disconnects from the DIS network after the test finishes.
* The `SendAndReceiveEntityStatePDU` test case sends the PDU, receives a PDU from the network, and verifies several properties:
    * PDU type is `PDU_ENTITY_STATE`
    * Received entity properties match the sent properties
* You can extend this test further by verifying additional properties or functionalities relevant to your specific use case.

**Note:**

* This is a basic example and may need adjustments depending on your implementation and network configuration.
* Make sure to include the necessary header files for Open-DIS-CPP and Google Test.
* Use appropriate assertions and error handling for robust testing.

By following these guidelines and adapting the test case to your specific needs, you can create effective unit tests for your DIS PDU sending and receiving functionalities in C++.

Unfortunately, writing unit tests for the example provided requires further context about the specific implementation details of your functions and classes. However, I can provide a general template for unit tests using GTest based on the above code:

**1. Define Test Fixture:**

```cpp
class DISPDUTest : public ::testing::Test {
public:
  DISNetworkManager networkManager;
  EntityStatePDU pdu;

  // ... Additional setup members and methods
};
```

**2. Test Sending Entity State PDU:**

```cpp
TEST_F(DISPDUTest, SendEntityStatePDU) {
  // Mock network connection (replace with your actual connection logic)
  EXPECT_CALL(networkManager, connect("127.0.0.1", 3000)).WillOnce(testing::Return(true));

  // Set entity properties
  pdu.exerciseID = 1;
  pdu.entityID = 1234;
  pdu.entityType = PLATFORM_TYPE;
  pdu.simulationTime = std::chrono::system_clock::now().time_since_epoch().count();
  pdu.position.x = 100.0;
  pdu.position.y = 200.0;
  pdu.position.z = 300.0;
  pdu.orientation = 0.0;

  // Send PDU
  EXPECT_TRUE(networkManager.sendPDU(pdu));

  // Verify network call (optional)
  // ...

  // Disconnect from network (optional)
  networkManager.disconnect();
}
```

**3. Test Receiving and Processing Entity State PDU:**

```cpp
TEST_F(DISPDUTest, ReceiveEntityStatePDU) {
  // Mock network receive (replace with your actual receive logic)
  pdu.exerciseID = 2;
  pdu.entityID = 5678;
  pdu.entityType = TACTICAL_VEHICLE_TYPE;
  pdu.simulationTime = 10000;
  pdu.position.x = 200.0;
  pdu.position.y = 300.0;
  pdu.position.z = 400.0;
  pdu.orientation = 90.0;
  networkManager.receivePDU(pdu);

  // Receive PDU
  EntityStatePDU receivedPDU = networkManager.receivePDU();

  // Verify received PDU properties
  EXPECT_EQ(receivedPDU.exerciseID, 2);
  EXPECT_EQ(receivedPDU.entityID, 5678);
  EXPECT_EQ(receivedPDU.entityType, TACTICAL_VEHICLE_TYPE);
  // ... Verify other properties

  // Process received information (test your processing logic here)
  // ...
}
```

**Remember to:**

* Replace the mocked network connection and receive logic with your actual implementation.
* Add additional tests for different scenarios and functionalities.
* Adapt the test cases to your specific data structures and function names.

This is just a basic example, and you'll need to adjust it based on your specific code and testing needs. I hope it gives you a starting point for writing your unit tests!

```cpp
#include <dis6/DISCpp.h>

int main() {
    // Initialize Open-DIS
    DIS::Initialize();

    // Create a DIS entity
    DIS::EntityStatePdu entityPdu;
    // Set up the entity data...

    // Send or receive DIS messages as needed

    // Shutdown Open-DIS when done
    DIS::Shutdown();

    return 0;
}
```

```cpp
#include <iostream>

// Example DIS enums (This is a simplified example)
enum EntityType {
    PLATFORM = 1,
    MUNITION = 2,
    LIFE_FORM = 3,
    SENSOR = 4
};

enum EntityState {
    ALIVE = 1,
    DESTROYED = 2,
    DAMAGED = 3
};

// Function to print the entity state based on the enum
void printEntityState(EntityState state) {
    switch (state) {
        case ALIVE:
            std::cout << "Entity is alive.\n";
            break;
        case DESTROYED:
            std::cout << "Entity has been destroyed.\n";
            break;
        case DAMAGED:
            std::cout << "Entity is damaged.\n";
            break;
        default:
            std::cout << "Unknown entity state.\n";
    }
}

int main() {
    // Example usage
    EntityType entityType = PLATFORM;
    EntityState entityState = ALIVE;

    std::cout << "Entity type: " << entityType << "\n";
    printEntityState(entityState);

    return 0;
}
```
Certainly! Below is an example of how you might write a Google Test (gtest) test case for the functions and enums mentioned in the previous example. For simplicity, I'm assuming that you have a header file (`dis_functions.h`) where you define your functions and enums, and a source file (`dis_functions.cpp`) where you implement those functions.

Here's the header file (`dis_functions.h`):

```cpp
// dis_functions.h

#ifndef DIS_FUNCTIONS_H
#define DIS_FUNCTIONS_H

#include <cstdint>

// Example DIS enums (This is a simplified example)
enum EntityType {
    PLATFORM = 1,
    MUNITION = 2,
    LIFE_FORM = 3,
    SENSOR = 4
};

enum EntityState {
    ALIVE = 1,
    DESTROYED = 2,
    DAMAGED = 3
};

// Function to print the entity state based on the enum
void printEntityState(EntityState state);

#endif // DIS_FUNCTIONS_H
```

And the source file (`dis_functions.cpp`):

```cpp
// dis_functions.cpp

#include "dis_functions.h"
#include <iostream>

void printEntityState(EntityState state) {
    switch (state) {
        case ALIVE:
            std::cout << "Entity is alive.\n";
            break;
        case DESTROYED:
            std::cout << "Entity has been destroyed.\n";
            break;
        case DAMAGED:
            std::cout << "Entity is damaged.\n";
            break;
        default:
            std::cout << "Unknown entity state.\n";
    }
}
```

Now, let's write the Google Test (`gtest`) test case (`test_dis_functions.cpp`):

```cpp
// test_dis_functions.cpp

#include "gtest/gtest.h"
#include "dis_functions.h"

TEST(DISFunctionsTest, PrintEntityState) {
    // Test case for printEntityState function

    // Test ALIVE state
    testing::internal::CaptureStdout(); // Redirect cout for testing
    printEntityState(ALIVE);
    std::string output_alive = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_alive, "Entity is alive.\n");

    // Test DESTROYED state
    testing::internal::CaptureStdout();
    printEntityState(DESTROYED);
    std::string output_destroyed = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_destroyed, "Entity has been destroyed.\n");

    // Test DAMAGED state
    testing::internal::CaptureStdout();
    printEntityState(DAMAGED);
    std::string output_damaged = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_damaged, "Entity is damaged.\n");

    // Test unknown state
    testing::internal::CaptureStdout();
    printEntityState(static_cast<EntityState>(42)); // 42 is an arbitrary unknown value
    std::string output_unknown = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_unknown, "Unknown entity state.\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

In this test case, we use the `TEST` macro to define a test case named `DISFunctionsTest` and a test named `PrintEntityState`. Inside the test, we call the `printEntityState` function with different states and use the `EXPECT_EQ` macro to check if the output matches the expected strings.

Remember to compile and link the test file with the Google Test framework. The specifics may vary based on your build system. If you are using CMake, you might In C++, when you declare a static data member pointer, you are creating a single variable that is shared among all instances of the class. A static data member belongs to the class itself rather than to instances of the class. Here's an example to illustrate:

```cpp
#include <iostream>

class MyClass {
public:
    // Static data member pointer
    static int* staticPointer;

    // Member function to use the static pointer
    void printStaticPointerValue() {
        std::cout << "Static pointer value: " << *staticPointer << std::endl;
    }
};

// Definition of the static pointer (outside the class)
int* MyClass::staticPointer = nullptr;

int main() {
    // Creating instances of MyClass
    MyClass obj1, obj2;

    // Assigning values to the static pointer
    MyClass::staticPointer = new int(42);

    // Accessing the static pointer through instances
    obj1.printStaticPointerValue();  // Output: Static pointer value: 42
    obj2.printStaticPointerValue();  // Output: Static pointer value: 42

    // Cleanup
    delete MyClass::staticPointer;

    return 0;
}
```

In this example:

- `staticPointer` is a static data member of the `MyClass` class, and it is a pointer to an integer.
- In the `main` function, we create two instances of `MyClass` (obj1 and obj2).
- We assign a value to the static pointer by accessing it through the class name (`MyClass::staticPointer`).
- We then use instances of the class to access and print the value of the static pointer. Note that the static pointer is shared among all instances.
- Finally, we delete the memory allocated for the integer pointed to by the static pointer.

It's important to manage the memory properly when using static pointers, just as with regular pointers, to avoid memory leaks. Additionally, be cautious with the use of static data members, as they are shared across all instances and can have implications for the design and behavior of your class.create a `CMakeLists.txt` file to build the tests.

To unit test the code provided earlier, you can use a testing framework such as Google Test (gtest). Below is an example of how you can write a unit test for the `MyClass` class and its static data member pointer using Google Test.

```cpp
#include "gtest/gtest.h"
#include "YourClassHeader.h"  // Replace with the actual header file name

TEST(MyClassTest, StaticPointerTest) {
    // Create an instance of MyClass
    MyClass obj;

    // Set the value of the static pointer
    MyClass::staticPointer = new int(42);

    // Test the printStaticPointerValue function
    testing::internal::CaptureStdout(); // Redirect cout for testing
    obj.printStaticPointerValue();
    std::string output = testing::internal::GetCapturedStdout();
    
    // Check if the output matches the expected string
    EXPECT_EQ(output, "Static pointer value: 42\n");

    // Cleanup
    delete MyClass::staticPointer;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

In this example:

- The `TEST` macro defines a test case named `MyClassTest` and a test named `StaticPointerTest`.
- In the test, an instance of `MyClass` is created.
- The value of the static pointer (`MyClass::staticPointer`) is set to a dynamically allocated integer.
- The `printStaticPointerValue` function is called, and the standard output (cout) is captured for testing.
- The `EXPECT_EQ` macro is used to check if the captured output matches the expected string (`"Static pointer value: 42\n"`).
- Finally, the allocated memory is cleaned up.

Ensure that you replace `"YourClassHeader.h"` with the actual header file name where the `MyClass` class is declared.

Compile and link this test file along with your main code and the Google Test framework. Run the executable to execute the tests. If you are using CMake, you would typically configure your `CMakeLists.txt` file to include the necessary dependencies for Google Test and link against the appropriate libraries.

-----------------------------------------------------------------------------------------------------------

The term ".NET" typically refers to the Microsoft .NET framework, which is a set of technologies and tools for building and running Windows applications and web services. The .NET framework supports multiple programming languages, and developers can use languages like C# or Visual Basic.NET to build applications that run on the .NET runtime.

If you are working in C++, you may not be directly using the .NET framework. However, there are scenarios where C++ and .NET technologies can be integrated. Here are a couple of ways C++ and .NET can be related:

1. **Managed C++ (C++/CLI):**
   - Managed C++ (also known as C++/CLI, Common Language Infrastructure) is a set of language extensions for C++ that allows developers to write code that targets the .NET runtime. This enables the use of .NET features and libraries in C++ code.
   - Managed C++ code can interact with other .NET languages like C# or Visual Basic.NET. It allows developers to take advantage of both native C++ features and .NET capabilities.

2. **Interoperability with C++ and .NET:**
   - C++ code can be integrated with .NET code through interoperability mechanisms. For example, you can use Platform Invocation Services (P/Invoke) to call functions from a native C++ DLL in a .NET application, or you can use COM Interop to expose C++ classes to .NET.
   - This allows developers to leverage existing C++ codebases within .NET applications or vice versa.

Here's a brief example of using C++/CLI to create a managed class that can be used by a .NET application:

```cpp
// Native C++ code
#include <iostream>

class NativeClass {
public:
    void NativeMethod() {
        std::cout << "Native method called.\n";
    }
};

// Managed C++/CLI code
#using <mscorlib.dll>

using namespace System;

public ref class ManagedClass {
private:
    NativeClass* nativeInstance;

public:
    ManagedClass() {
        nativeInstance = new NativeClass();
    }

    ~ManagedClass() {
        delete nativeInstance;
    }

    void ManagedMethod() {
        Console::WriteLine("Managed method called.");
        nativeInstance->NativeMethod();
    }
};
```

In this example, the `NativeClass` is a native C++ class, and the `ManagedClass` is a managed C++/CLI class that interacts with the native class. The managed class can be used in a C# or other .NET languages.

Remember that the choice to use C++ with .NET depends on the specific requirements of your project and the advantages each technology brings to the table.


To establish a TCP connection from a C++ program to a .NET server, you can use the Winsock library in C++ for the networking part. The following example demonstrates a simple TCP client in C++ that connects to a .NET TCP server. The server, in this case, could be implemented in any language, including C#.

Here's a C++ example for a TCP client:

```cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <Winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return EXIT_FAILURE;
    }

    // Create a socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket: " << WSAGetLastError() << "\n";
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Connect to the server
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Server port number
    inet_pton(AF_INET, "127.0.0.1", &(serverAddr.sin_addr));

    if (connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Connect failed with error: " << WSAGetLastError() << "\n";
        closesocket(clientSocket);
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Send data to the server
    const char* message = "Hello, .NET Server!";
    if (send(clientSocket, message, strlen(message), 0) == SOCKET_ERROR) {
        std::cerr << "Send failed with error: " << WSAGetLastError() << "\n";
    } else {
        std::cout << "Message sent to .NET server.\n";
    }

    // Cleanup
    closesocket(clientSocket);
    WSACleanup();

    return EXIT_SUCCESS;
}
```

In this example, the client connects to a server running on the local machine (`127.0.0.1`) on port 12345. You should replace these values with the actual IP address and port number of your .NET server.

Please note that for this C++ client to communicate with a .NET server, the server should be implemented to handle incoming TCP connections and messages. The server could be developed in C# using the TcpListener and TcpClient classes or in any other .NET-compatible language. The key is to have the server logic that can handle incoming connections and process data sent by the client.


To create a simple TCP client-server connection in C++, you can use the `<iostream>`, `<cstring>`, `<cstdlib>`, and `<Winsock2.h>` headers. Note that this example is for Windows, and you need to link against the `ws2_32` library.

Here's a basic example of a TCP client and server using Winsock in C++:

### Server (TCP Server)

```cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <Winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return EXIT_FAILURE;
    }

    // Create a socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket: " << WSAGetLastError() << "\n";
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Bind the socket
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(12345); // Port number

    if (bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed with error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed with error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return EXIT_FAILURE;
    }

    std::cout << "Server listening on port 12345...\n";

    // Accept a connection
    SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Accept failed with error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Communication with the client
    char buffer[1024];
    std::memset(buffer, 0, sizeof(buffer));

    if (recv(clientSocket, buffer, sizeof(buffer), 0) == SOCKET_ERROR) {
        std::cerr << "Recv failed with error: " << WSAGetLastError() << "\n";
    } else {
        std::cout << "Received from client: " << buffer << "\n";
    }

    // Cleanup
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return EXIT_SUCCESS;
}
```

### Client (TCP Client)

```cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <Winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return EXIT_FAILURE;
    }

    // Create a socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket: " << WSAGetLastError() << "\n";
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Connect to the server
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Server port number
    inet_pton(AF_INET, "127.0.0.1", &(serverAddr.sin_addr));

    if (connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Connect failed with error: " << WSAGetLastError() << "\n";
        closesocket(clientSocket);
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Send data to the server
    const char* message = "Hello, Server!";
    if (send(clientSocket, message, strlen(message), 0) == SOCKET_ERROR) {
        std::cerr << "Send failed with error: " << WSAGetLastError() << "\n";
    } else {
        std::cout << "Message sent to server.\n";
    }

    // Cleanup
    closesocket(clientSocket);
    WSACleanup();

    return EXIT_SUCCESS;
}
```

This example demonstrates a basic TCP client-server interaction. The server listens on port 12345, accepts a connection from a client, and receives a message from the client. The client connects to the server, sends a message, and then closes the connection. Note that error handling is minimal in this example for simplicity; in a production environment, you would want to handle errors more robustly.



---------------


 **Here's a C++ example demonstrating how to connect to a .NET server using TCP:**

**1. Include necessary headers:**

```c++
#include <iostream>
#include <string>
#include <winsock2.h>  // Include Windows socket library
#pragma comment(lib, "ws2_32.lib")  // Link with ws2_32.lib
```

**2. Initialize Winsock:**

```c++
WSADATA wsaData;
if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    std::cerr << "WSAStartup failed." << std::endl;
    return 1;
}
```

**3. Create a TCP socket:**

```c++
SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
if (sock == INVALID_SOCKET) {
    std::cerr << "socket failed." << std::endl;
    WSACleanup();
    return 1;
}
```

**4. Specify server address and port:**

```c++
sockaddr_in serverAddr;
serverAddr.sin_family = AF_INET;
serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Replace with server IP address
serverAddr.sin_port = htons(8080);  // Replace with server port
```

**5. Connect to the server:**

```c++
if (connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr)) != 0) {
    std::cerr << "connect failed." << std::endl;
    closesocket(sock);
    WSACleanup();
    return 1;
}
```

**6. Send and receive data:**

```c++
std::string message = "Hello from C++ client!";
if (send(sock, message.c_str(), message.length(), 0) == SOCKET_ERROR) {
    std::cerr << "send failed." << std::endl;
    closesocket(sock);
    WSACleanup();
    return 1;
}

char buffer[1024];
int bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
if (bytesReceived > 0) {
    std::cout << "Received from server: " << std::string(buffer, 0, bytesReceived) << std::endl;
} else {
    std::cerr << "recv failed." << std::endl;
}
```

**7. Close the socket and cleanup:**

```c++
closesocket(sock);
WSACleanup();
```

**Remember:**

- Replace placeholders with the actual server IP address and port.
- Handle errors appropriately in a production environment.
- This example assumes a compatible .NET server is listening on the specified port.

If you're encountering issues with setting the pthread priority using `pthread_setschedparam`, it could be due to various reasons. Here are some potential solutions and things to check:

1. **Ensure Sufficient Privileges**:
   - Setting thread priorities might require elevated privileges. Make sure your program has the necessary permissions to set thread priorities. On Linux systems, this typically requires running the program with root privileges or being a member of the appropriate user group (e.g., `sudo` or `root`).

2. **Check Error Handling**:
   - After calling `pthread_setschedparam`, always check the return value and `errno` to determine the cause of failure. `errno` can provide additional information about the error condition.

3. **Verify Thread Policy Compatibility**:
   - Ensure that the thread scheduling policy (`SCHED_FIFO`, `SCHED_RR`, or `SCHED_OTHER`) is compatible with setting thread priorities. Not all policies support priority settings. `SCHED_FIFO` and `SCHED_RR` typically support setting priorities, while `SCHED_OTHER` might not.

4. **Check Thread Priority Limits**:
   - Verify that the priority value you are trying to set falls within the allowable range for the specified policy. Each policy has its own range of allowable priority values. Use `sched_get_priority_min` and `sched_get_priority_max` to retrieve the minimum and maximum priority values for a given policy.

5. **Verify Thread Priority Inheritance**:
   - On some systems, setting thread priorities might be restricted or disabled due to security or resource allocation considerations. Check the system configuration to ensure that thread priority manipulation is allowed.

6. **Consider Real-Time Scheduling Policies**:
   - If your application requires deterministic or real-time behavior, consider using real-time scheduling policies (`SCHED_FIFO` or `SCHED_RR`) instead of the default `SCHED_OTHER` policy.

Here's an example of how to set thread priority using `pthread_setschedparam` with error handling:

```c
#include <pthread.h>
#include <stdio.h>
#include <errno.h>

int main() {
    pthread_t thread;
    struct sched_param param;
    
    // Set thread priority to 90
    param.sched_priority = 90;
    
    // Attempt to set thread priority
    if (pthread_setschedparam(thread, SCHED_FIFO, &param) != 0) {
        perror("pthread_setschedparam");
        return 1;
    }
    
    printf("Thread priority set successfully.\n");
    return 0;
}
```

Ensure that you replace `pthread_t thread;` with the actual thread identifier of the thread you want to modify. Additionally, consider using real-time scheduling policies (`SCHED_FIFO` or `SCHED_RR`) if your application requires deterministic behavior.


```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip> // Include for std::fixed and std::setprecision

struct SatelliteData {
    std::string name;
    std::string line1;
    std::string line2;
    std::string epoch;
    double inclination;
    std::string satelliteNumber;
    std::string internationalDesignator;
    //std::string epochTime;
    double firstTimeDerivativeMeanMotion;
    double secondTimeDerivativeMeanMotion;
    double bstarDragTerm;
    std::string ephemerisType;
    int elementSetNumber;
    std::string checksum;
};

int numOfSatellite(std::vector<SatelliteData> &satellites){
    return  satellites.size();
}


std::vector<SatelliteData> parseTLEFile(const std::string& filename) {
    std::vector<SatelliteData> satellites;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return satellites;
    }


    std::string line;
    SatelliteData currentSatellite;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }
         // Ensure line length is sufficient
        if (line.size() < 33) {
            std::cerr << "Error: Line too short in file: " << filename << std::endl;
            continue;
        }
        if (line[0] == '1') {
            currentSatellite.line1 = line;
        } else if (line[0] == '2') {
            currentSatellite.line2 = line;
            // Parse Line 2 to extract relevant information
            
            std::istringstream iss(line.substr(8, 8)); // Extract inclination
            iss >> currentSatellite.inclination;
            
                // Extract satellite number
            currentSatellite.satelliteNumber = line.substr(2, 5);

            // Extract international designator
            currentSatellite.internationalDesignator = line.substr(9, 8);

            // Extract epoch time
            currentSatellite.epoch = line.substr(18, 14);

            // Extract first time derivative of mean motion
            currentSatellite.firstTimeDerivativeMeanMotion = std::stod(line.substr(33, 10));

            // Extract second time derivative of mean motion
            currentSatellite.secondTimeDerivativeMeanMotion = std::stod(line.substr(44, 8));

            // Extract BSTAR drag term
            currentSatellite.bstarDragTerm = std::stod(line.substr(53, 8));

            // Extract ephemeris type
            currentSatellite.ephemerisType = line.substr(62, 1);

            // Extract element set number
            currentSatellite.elementSetNumber = std::stoi(line.substr(64, 4));

            // Extract checksum
            currentSatellite.checksum = line.substr(68, 1);

            // Add current satellite data to the vector
            satellites.push_back(currentSatellite);
            currentSatellite = SatelliteData(); // Reset for next satellite

        } else {
            currentSatellite.name += line;
        }
    }

    file.close();
    return satellites;
}
void exportToCSV(const std::vector<SatelliteData>& satellites, const std::string& filename) {
    int counter=1;
    
    std::ofstream csvFile(filename);
    std::ofstream file(filename, std::ios::trunc);

    if (!csvFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Write header
    csvFile << "ID,SatelliteNumber,InternationalDesignator,EpochTime,FirstTimeDerivativeMeanMotion,"
            << "SecondTimeDerivativeMeanMotion,BStarDragTerm,EphemerisType,ElementSetNumber,Checksum\n";

    // Write data
    for (const auto& satellite : satellites) {
        csvFile <<counter++ <<","<<satellite.satelliteNumber << "," << satellite.internationalDesignator << ","
                << satellite.epoch << "," << satellite.firstTimeDerivativeMeanMotion << ","
                << satellite.secondTimeDerivativeMeanMotion << "," << satellite.bstarDragTerm << ","
                << satellite.ephemerisType << "," << satellite.elementSetNumber << ","
                << satellite.checksum << "\n";
    }

    csvFile.close();
}
int main() {
    std::vector<SatelliteData> satellites = parseTLEFile("satellite_data.tle");

    // // Print parsed data
    // for (const auto& satellite : satellites) {
    //     std::cout << "Name: " << satellite.name << std::endl;
    //     std::cout << "Line 1: " << satellite.line1 << std::endl;
    //     std::cout << "Line 2: " << satellite.line2 << std::endl;
    //     std::cout << std::endl;
    // }

    std::cout<<"Num of Sat: "<<numOfSatellite(satellites)<<std::endl;

    // Export to CSV
    exportToCSV(satellites, "satellite_data.csv");

    std::cout << "CSV file exported successfully." << std::endl;

    // Print parsed data
    // for (size_t i = 0; i < satellites.size(); ++i) {
    //     std::cout << "Satellite " << i+1 << ":" << std::endl;
    //     std::cout << "Name: " << satellites[i].name << std::endl;
    //     std::cout << "Epoch: " << satellites[i].epoch << std::endl;
    //     std::cout << "Inclination: " << std::fixed << std::setprecision(2) << satellites[i].inclination << " degrees" << std::endl;
    //     std::cout << std::endl;
    // }

    return 0;
}
```
```cpp
#include <iostream>
#include <vector>

// Define an event structure
struct Event {
    int type;
    std::string message;
};

// Define an event router class
class EventRouter {
public:
    void publish(const Event& event) {
        // Publish the event to all subscribed listeners
        for(auto& listener : listeners) {
            listener(event);
        }
    }

    void subscribe(std::function<void(const Event&)> listener) {
        // Add listener to the list of subscribers
        listeners.push_back(listener);
    }

private:
    std::vector<std::function<void(const Event&)>> listeners;
};

int main() {
    // Create an instance of the event router
    EventRouter router;

    // Subscribe a listener
    router.subscribe([](const Event& event) {
        std::cout << "Listener 1 received event type: " << event.type << ", message: " << event.message << std::endl;
    });

    // Subscribe another listener
    router.subscribe([](const Event& event) {
        std::cout << "Listener 2 received event type: " << event.type << ", message: " << event.message << std::endl;
    });

    // Publish an event
    Event event;
    event.type = 1;
    event.message = "Hello, world!";
    router.publish(event);

    return 0;
}
```

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <functional>

// Define an event structure
struct Event {
    int type;
    std::string message;
};

// Define an event router class
class EventRouter {
public:
    void publish(const Event& event) {
        // Publish the event to all subscribed listeners
        for(auto& listener : listeners) {
            listener(event);
        }
    }

    void subscribe(std::function<void(const Event&)> listener) {
        // Add listener to the list of subscribers
        listeners.push_back(listener);
    }

private:
    std::vector<std::function<void(const Event&)>> listeners;
};

// Function to read TLE file and publish elements as events
void readAndPublishTLE(const std::string& filename, EventRouter& router) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    int lineCount = 0;
    while (std::getline(file, line)) {
        lineCount++;
        if (lineCount % 3 == 1) {
            // First line of TLE data (Line 1)
            Event event;
            event.type = 1; // You can define event types as per your requirements
            event.message = line;
            router.publish(event);
        } else if (lineCount % 3 == 2) {
            // Second line of TLE data (Line 2)
            Event event;
            event.type = 2; // You can define event types as per your requirements
            event.message = line;
            router.publish(event);
        }
        // Ignoring third line as it's not needed for basic TLE data
    }

    file.close();
}

int main() {
    // Create an instance of the event router
    EventRouter router;

    // Subscribe a listener to handle TLE Line 1 events
    router.subscribe([](const Event& event) {
        std::cout << "Listener for TLE Line 1 received: " << event.message << std::endl;
    });

    // Subscribe another listener to handle TLE Line 2 events
    router.subscribe([](const Event& event) {
        std::cout << "Listener for TLE Line 2 received: " << event.message << std::endl;
    });

    // Read TLE file and publish elements as events
    readAndPublishTLE("example.tle", router);

    return 0;
}

```

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <functional>

// Define an event structure
struct Event {
    int type;
    std::string message;
};

// Define an event router class
class EventRouter {
public:
    void publish(const Event& event) {
        // Publish the event to all subscribed listeners
        for(auto& listener : listeners) {
            listener(event);
        }
    }

    void subscribe(std::function<void(const Event&)> listener) {
        // Add listener to the list of subscribers
        listeners.push_back(listener);
    }

private:
    std::vector<std::function<void(const Event&)>> listeners;
};

// Function to read TLE file and publish elements as events
void readAndPublishTLE(const std::string& filename, EventRouter& router) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    int lineCount = 0;
    while (std::getline(file, line)) {
        lineCount++;
        if (lineCount % 3 == 1) {
            // First line of TLE data (Line 1)
            Event event;
            event.type = 1; // You can define event types as per your requirements
            event.message = line;
            router.publish(event);
        }
    }

    // Publish event to signal the end of loaded TLE
    Event endEvent;
    endEvent.type = 2; // You can define a different event type for the end event
    endEvent.message = "End of TLE file";
    router.publish(endEvent);
}

// Example listener function
void eventListener(const Event& event) {
    std::cout << "Received event type: " << event.type << ", message: " << event.message << std::endl;
}

int main() {
    // Create an instance of the event router
    EventRouter router;

    // Subscribe a listener
    router.subscribe(eventListener);

    // Read and publish TLE data
    readAndPublishTLE("tle_file.txt", router);

    return 0;
}


```
```cpp 
#include <iostream>
#include <string>
#include <cstring>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;


// Define DIS PDU structure
struct DisPdu {
    int pduType;
    int entityId;
    // Add more fields as needed...
    bool acknowledge;
    bool stop;
    bool start;
    bool resume;
    bool pause;
};

// Example function to send a DIS PDU over UDP
void sendDisPdu(const DisPdu& pdu, udp::socket& socket, const udp::endpoint& endpoint) {
    boost::system::error_code ignored_error;
    socket.send_to(boost::asio::buffer(&pdu, sizeof(pdu)), endpoint, 0, ignored_error);
}

// Example function to receive a DIS PDU over UDP
void receiveDisPdu(udp::socket& socket) {
    DisPdu pdu;
    udp::endpoint sender_endpoint;
    boost::system::error_code error;

    size_t len = socket.receive_from(boost::asio::buffer(&pdu, sizeof(pdu)), sender_endpoint, 0, error);
    if (error && error != boost::asio::error::message_size) {
        throw boost::system::system_error(error);
    }

    // Process received DIS PDU
    // For example:
    std::cout << "Received DIS PDU from " << sender_endpoint << std::endl;
    std::cout << "PDU type: " << pdu.pduType << std::endl;
    // Handle other fields as needed...
}

int main() {
    try {
        boost::asio::io_context io_context;

        // Create a UDP socket
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 12345));

        // Example endpoint (replace with actual destination endpoint)
        udp::endpoint remote_endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 12345);

        // Create a DIS PDU
        DisPdu pdu;
        pdu.pduType = 1;
        pdu.entityId = 123;
        pdu.acknowledge = false;
        pdu.stop = false;
        pdu.start = true;
        pdu.resume = false;
        pdu.pause = false;

        // Send the DIS PDU
        sendDisPdu(pdu, socket, remote_endpoint);

        // Receive DIS PDUs
        receiveDisPdu(socket);

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}





// // Function to send a DIS PDU over UDP
// void sendDisPdu(const DisPdu& pdu, const char* destinationIp, int destinationPort) {
//     int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//     if (sock < 0) {
//         std::cerr << "Error creating socket" << std::endl;
//         return;
//     }

//     struct sockaddr_in destAddr;
//     memset(&destAddr, 0, sizeof(destAddr));
//     destAddr.sin_family = AF_INET;
//     destAddr.sin_port = htons(destinationPort);
//     inet_pton(AF_INET, destinationIp, &destAddr.sin_addr);

//     sendto(sock, &pdu, sizeof(pdu), 0, (struct sockaddr*)&destAddr, sizeof(destAddr));
//     close(sock);
// }

// // Function to receive a DIS PDU over UDP
// void receiveDisPdu(int listenPort) {
//     int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//     if (sock < 0) {
//         std::cerr << "Error creating socket" << std::endl;
//         return;
//     }

//     struct sockaddr_in listenAddr;
//     memset(&listenAddr, 0, sizeof(listenAddr));
//     listenAddr.sin_family = AF_INET;
//     listenAddr.sin_addr.s_addr = htonl(INADDR_ANY);
//     listenAddr.sin_port = htons(listenPort);

//     if (bind(sock, (struct sockaddr*)&listenAddr, sizeof(listenAddr)) < 0) {
//         std::cerr << "Error binding socket" << std::endl;
//         close(sock);
//         return;
//     }

//     DisPdu pdu;
//     struct sockaddr_in clientAddr;
//     socklen_t clientAddrLen = sizeof(clientAddr);
//     recvfrom(sock, &pdu, sizeof(pdu), 0, (struct sockaddr*)&clientAddr, &clientAddrLen);

//     std::cout << "Received PDU - Type: " << pdu.pduType << ", Entity ID: " << pdu.entityId << std::endl;

//     close(sock);
// }

// // Function to send an acknowledgment PDU
// void sendAcknowledge(int ackType, const char* destinationIp, int destinationPort) {
//     DisPdu pdu;
//     pdu.pduType = ackType;
//     pdu.entityId = 0; // Set entity ID to 0 for acknowledgment PDUs

//     sendDisPdu(pdu, destinationIp, destinationPort);
// }

// int main() {
//     // Example usage: Sending and receiving DIS PDUs
//     DisPdu pdu;
//     pdu.pduType = 1; // Example PDU type
//     pdu.entityId = 123; // Example entity ID

//     // Send the DIS PDU
//     sendDisPdu(pdu, "127.0.0.1", 12345);

//     // Receive the DIS PDU
//     receiveDisPdu(12345);

//     // Send acknowledgment PDUs for start, stop, resume, and pause commands
//     sendAcknowledge(10, "127.0.0.1", 12345); // Acknowledge for start command
//     sendAcknowledge(20, "127.0.0.1", 12345); // Acknowledge for stop command
//     sendAcknowledge(30, "127.0.0.1", 12345); // Acknowledge for resume command
//     sendAcknowledge(40, "127.0.0.1", 12345); // Acknowledge for pause command

//     return 0;
// }
```
Open DIS (Distributed Interactive Simulation) is an open-source protocol standard for real-time distributed simulation. It defines a set of rules and formats for exchanging data between simulation entities in a distributed environment. Open DIS is widely used in military training simulations, gaming, and other applications where multiple simulations need to interact with each other over a network.

A Protocol Data Unit (PDU) in the context of DIS is a unit of data that is exchanged between simulation entities. Each PDU contains specific information about the state or action of a simulation entity, such as its position, orientation, velocity, and other relevant data.

To parse a DIS PDU, you need to understand the structure and format of the PDU according to the DIS specification. The DIS specification defines various types of PDUs, each with its own structure and data fields. Typically, you would need to:

1. Identify the type of PDU you are dealing with.
2. Extract the data fields from the PDU according to the structure defined in the DIS specification.
3. Interpret the data fields to reconstruct the state or action represented by the PDU.

Parsing a DIS PDU involves reading the binary data representing the PDU and interpreting it according to the DIS specification. You would need to implement code to extract and interpret each field of the PDU, taking into account the data types and byte order specified in the DIS standard.

There are libraries available that can assist with parsing DIS PDUs, such as the Open-DIS library, which provides tools for encoding, decoding, and manipulating DIS PDUs in various programming languages. Using such libraries can simplify the process of working with DIS PDUs and ensure compatibility with the DIS standard.
```cpp
#include <iostream>
#include <DIS/OpenDIS.h>

int main() {
    // Example DIS PDU data (in bytes)
    std::vector<unsigned char> pduData = {
        // Add your PDU data here...
    };

    // Create a PDU factory
    DIS::PduFactory pduFactory;

    try {
        // Decode the PDU
        DIS::Pdu* pdu = pduFactory.createPdu(pduData);
        if (pdu != nullptr) {
            // Print PDU information
            std::cout << "PDU type: " << pdu->getPduType() << std::endl;
            std::cout << "PDU size: " << pdu->getPduSize() << " bytes" << std::endl;

            // Example: Print entity ID if it's available
            if (pdu->getPduType() == DIS::PDU_ENTITY_STATE) {
                DIS::EntityStatePdu* entityStatePdu = dynamic_cast<DIS::EntityStatePdu*>(pdu);
                if (entityStatePdu != nullptr) {
                    std::cout << "Entity ID: " << entityStatePdu->getEntityID() << std::endl;
                }
            }

            // Clean up
            delete pdu;
        } else {
            std::cerr << "Failed to decode PDU" << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

```
using chrono
```cpp
#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <stdexcept>

class Timer {
public:
    Timer() : running_(false), total_elapsed_time_millisec(0) {}

    void start() {
        if (!running_) {
            start_time_millisec = std::chrono::high_resolution_clock::now();
            running_ = true;
        } else {
            throw std::logic_error("Timer is already running");
        }
    }

    void stop() {
        if (running_) {
            auto end_time_millisec = std::chrono::high_resolution_clock::now();
            auto elapsed_time_millisec = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_millisec - start_time_millisec).count();
            total_elapsed_time_millisec += elapsed_time_millisec;
            running_ = false;
        } else {
            throw std::logic_error("Timer is not running");
        }
    }

    double duration() const {
        if (running_) {
            auto current_time = std::chrono::high_resolution_clock::now();
            auto elapsed_time_millisec = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time_millisec).count();
            return total_elapsed_time_millisec + elapsed_time_millisec;
        } else {
            return total_elapsed_time_millisec;
        }
    }

 std::time_t currentTimestamp() const {
         return std::chrono::system_clock::to_time_t(std::chrono::high_resolution_clock::now());
    }

      std::chrono::milliseconds::rep currentTimestampMilliseconds() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    }

    std::chrono::microseconds::rep currentTimestampMicroseconds() const {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    }

private:
    bool running_;
    long long total_elapsed_time_millisec; // Total elapsed time in milliseconds
    std::chrono::high_resolution_clock::time_point start_time_millisec;
};

#endif // TIMER_HPP


int main() {

    Timer timer_benchmark;
    timer_benchmark.start();
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::time_t timestamp_time_t=timer_benchmark.currentTimestamp();
    std::cout << "Current timestamp: " << std::put_time(std::localtime(&timestamp_time_t), "%Y-%m-%d %H:%M:%S") << std::endl;

    timer_benchmark.stop();
    double elapsed_data = timer_benchmark.duration();
    std::cout<<"elapsed time in seconds: "<<elapsed_data<<'\n'; 


    int64_t milliseconds = timer_benchmark.currentTimestampMilliseconds();
    int64_t microseconds = timer_benchmark.currentTimestampMicroseconds();

    // Display milliseconds and microseconds
    std::cout << "Current timestamp in milliseconds: " << milliseconds << std::endl;
    std::cout << "Current timestamp in microseconds: " << microseconds << std::endl;

}
//in seconds
// #ifndef TIMER_HPP
// #define TIMER_HPP

// #include <chrono>
// #include <stdexcept>

// class Timer {
// public:
//     Timer() : running_(false), total_elapsed_time_(0) {}

//     void start() {
//         if (!running_) {
//             start_time_ = std::chrono::high_resolution_clock::now();
//             running_ = true;
//         } else {
//             throw std::logic_error("Timer is already running");
//         }
//     }

//     void stop() {
//         if (running_) {
//             auto end_time = std::chrono::high_resolution_clock::now();
//             double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time_).count();
//             total_elapsed_time_ += elapsed_seconds;
//             running_ = false;
//         } else {
//             throw std::logic_error("Timer is not running");
//         }
//     }

//     double elapsed_seconds() const {
//         if (running_) {
//             auto current_time = std::chrono::high_resolution_clock::now();
//             double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(current_time - start_time_).count();
//             return total_elapsed_time_ + elapsed_seconds;
//         } else {
//             return total_elapsed_time_;
//         }
//     }

// private:
//     bool running_;
//     double total_elapsed_time_; // Total elapsed time in seconds
//     std::chrono::high_resolution_clock::time_point start_time_;
// };

// #endif // TIMER_HPP

```
```cpp
std::string Timestamp::filename(const char* file) const {
    std::string filename = file;
    size_t found = filename.find_last_of("/\\");
    if (found != std::string::npos) {
        return filename.substr(found + 1);
    }
    return filename;
}

std::string Timestamp::directory(const char* file) const {
    std::string filename = file;
    size_t found = filename.find_last_of("/\\");
    if (found != std::string::npos) {
        return filename.substr(0, found);
    }
    return filename;
}

int Timestamp::lineNumber(int line) const {
    return line;
}


std::string Timestamp::serializeToString() const {
    // Serialize timestamp, filename, directory, and line number into a string
    std::stringstream ss;
    ss << "Timestamp: " << currentTimestampInMicroseconds() << ", "
       << "Filename: " << filename(__FILE__) << ", "
       << "Directory: " << directory(__FILE__) << ", "
       << "Line number: " << lineNumber(__LINE__);
    return ss.str();
}
```
```python
import subprocess
import sys

def install_and_import(package):
    """Check if a package is installed, and install it if not."""
    try:
# This line tries to import the specified package using the __import__ function.
# __import__ is a built-in function that allows dynamic importing of modules. If the module is 
# already installed, this line will successfully import it and the function will proceed without error.
        __import__(package)
# If the package is not installed, an ImportError is raised.
# The except block catches this error and uses the subprocess module to run the pip install command.
# subprocess.check_call runs the command provided in the list [sys.executable, '-m', 'pip', 'install', package].
# sys.executable gives the path to the current Python interpreter.
# -m pip install runs the pip module as a script to install the specified package.
    except ImportError:
        subprocess.check_call([sys.executable, '-m', 'pip', 'install', package])
# The finally block runs regardless of whether an error occurred or not.
# It ensures the package is imported into the current global namespace using globals().
# globals() returns a dictionary representing the current global symbol table, and adding an entry to this dictionary effectively imports the module into the global namespace.
# This means you can use the package as if it was imported normally at the top of the script.
    finally:
        globals()[package] = __import__(package)


import pandas as pd
import matplotlib.pyplot as plt
from datetime import datetime

def read_csv(file_path):
    """Read the CSV file into a DataFrame."""
    return pd.read_csv(file_path)

def calculate_duration(df):
    """Calculate the duration from start to finish in seconds."""
    df['duration'] = df['end_time'] - df['start_time']
    return df

def epoch_to_human(epoch):
    """Convert epoch time to human-readable format."""
    return datetime.fromtimestamp(epoch).strftime('%Y-%m-%d %H:%M:%S')

def add_human_readable_times(df):
    """Add human-readable start and end times to the DataFrame."""
    df['start_time_human'] = df['start_time'].apply(epoch_to_human)
    df['end_time_human'] = df['end_time'].apply(epoch_to_human)
    return df

def total_duration(df):
    """Calculate the total duration for all records."""
    return df['duration'].sum()

def longest_duration_record(df):
    """Find the record with the longest duration."""
    return df.loc[df['duration'].idxmax()]

def average_duration(df):
    """Calculate the average duration."""
    return df['duration'].mean()

def plot_histogram(df):
    """Plot a histogram of the durations."""
    plt.figure(figsize=(10, 6))
    plt.hist(df['duration'], bins=30, edgecolor='k', alpha=0.7)
    plt.title('Histogram of Durations')
    plt.xlabel('Duration (seconds)')
    plt.ylabel('Frequency')
    plt.show()

def plot_duration_by_user(df):
    """Plot a bar chart of the total duration by user."""
    user_duration = df.groupby('user_id')['duration'].sum()
    user_duration.plot(kind='bar', figsize=(12, 7), color='skyblue')
    plt.title('Total Duration by User')
    plt.xlabel('User ID')
    plt.ylabel('Total Duration (seconds)')
    plt.xticks(rotation=45)
    plt.show()

def plot_time_series(df):
    """Plot a time series of the events."""
    df['start_time_human'] = pd.to_datetime(df['start_time_human'])
    df.set_index('start_time_human', inplace=True)
    df['duration'].plot(figsize=(15, 8))
    plt.title('Time Series of Durations')
    plt.xlabel('Time')
    plt.ylabel('Duration (seconds)')
    plt.show()

def save_to_csv(df, output_file_path):
    """Save the DataFrame to a CSV file."""
    df.to_csv(output_file_path, index=False)

def main(file_path, output_file_path):
    # Read the CSV file
    df = read_csv(file_path)
    
    # Calculate duration and add human-readable times
    df = calculate_duration(df)
    df = add_human_readable_times(df)
    
    # Calculate additional statistics
    total_dur = total_duration(df)
    max_dur_record = longest_duration_record(df)
    avg_dur = average_duration(df)
    
    # Print the results
    print(f'Total duration (in seconds) for all records: {total_dur}')
    print(f'Record with the longest duration:\n{max_dur_record}')
    print(f'Average duration (in seconds): {avg_dur}')
    
    # Save the results to a new CSV file
    save_to_csv(df, output_file_path)
    print(f'Results saved to {output_file_path}')
    
    # Plot the statistics
    plot_histogram(df)
    plot_duration_by_user(df)
    plot_time_series(df)

# Replace 'your_file.csv' and 'output_with_durations.csv' with the actual file paths
file_path = 'satellite_data.csv'
output_file_path = 'output_with_durations.csv'
# Ensure required packages are installed
#install_and_import('pandas')
#install_and_import('matplotlib')
main(file_path, output_file_path)

```

To plot the CSV data using Python, you can use libraries such as `pandas` for data manipulation and `matplotlib` for plotting. Below is an example script to read the CSV file generated by your C++ program and plot the data.

First, ensure you have the necessary Python libraries installed:

```sh
pip install pandas matplotlib
```

Here is the Python script to plot the data:

```python
import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
filename = "vehicle_data.csv"
data = pd.read_csv(filename)

# Convert the timestamp from microseconds to seconds for readability
data['Timestamp (seconds)'] = data['Timestamp (microseconds)'] / 1e6

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(data['Timestamp (seconds)'], data['Vehicle Count'], marker='o')

# Add labels and title
plt.xlabel('Timestamp (seconds)')
plt.ylabel('Vehicle Count')
plt.title('Vehicle Count Over Time')
plt.grid(True)

# Show the plot
plt.show()
```

### Explanation:

1. **Import Libraries**:
   ```python
   import pandas as pd
   import matplotlib.pyplot as plt
   ```
   We import `pandas` for reading and manipulating the CSV file and `matplotlib.pyplot` for plotting.

2. **Read the CSV File**:
   ```python
   filename = "vehicle_data.csv"
   data = pd.read_csv(filename)
   ```
   Use `pandas` to read the CSV file into a DataFrame.

3. **Convert Timestamp**:
   ```python
   data['Timestamp (seconds)'] = data['Timestamp (microseconds)'] / 1e6
   ```
   Convert the timestamp from microseconds to seconds for better readability in the plot.

4. **Plot the Data**:
   ```python
   plt.figure(figsize=(10, 6))
   plt.plot(data['Timestamp (seconds)'], data['Vehicle Count'], marker='o')
   ```
   Create a plot with `Timestamp (seconds)` on the x-axis and `Vehicle Count` on the y-axis. The `marker='o'` adds markers at each data point.

5. **Add Labels and Title**:
   ```python
   plt.xlabel('Timestamp (seconds)')
   plt.ylabel('Vehicle Count')
   plt.title('Vehicle Count Over Time')
   plt.grid(True)
   ```
   Add labels to the x-axis and y-axis, a title to the plot, and enable the grid for better readability.

6. **Show the Plot**:
   ```python
   plt.show()
   ```
   Display the plot.

You can save this script as `plot_vehicle_data.py` and run it to visualize the data collected by your C++ program.




```cpp
#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <random>
#include <thread>
#include <signal.h> // For signal handling
#include <vector>

// Define a struct to hold timestamp and vehicle count
struct VehicleData {
    uint64_t timestamp;
    int vehicle_count;
};

// Function to get the current timestamp in microseconds
uint64_t getTimestampNow() {
    using namespace std::chrono;
    auto now = high_resolution_clock::now();
    return duration_cast<microseconds>(now.time_since_epoch()).count();
}

// Function to generate a random number within a specified range
int generateRandomVehicleCount(int min, int max) {
    std::random_device rd;  // Seed the random number generator
    std::mt19937 gen(rd());  // Create a Mersenne Twister engine
    std::uniform_int_distribution<> dis(min, max);  // Define the range
    return dis(gen);
}

// Function to export vehicle data to CSV file
void exportToCsv(const std::vector<VehicleData>& data, const std::string& filename) {
    std::ofstream csvFile(filename);
    if (!csvFile.is_open()) {
        std::cerr << "Error opening CSV file: " << filename << std::endl;
        return;
    }

    // Write header row (optional)
    csvFile << "Timestamp (microseconds),Vehicle Count" << std::endl;

    for (const auto& entry : data) {
        csvFile << entry.timestamp << "," << entry.vehicle_count << std::endl;
    }

    std::cout << "Vehicle data exported to " << filename << std::endl;
}

bool running = true; // Flag to control loop termination
std::vector<VehicleData> vehicleDataCollection; // Collection to store vehicle data

void handle_SIGINT(int sig) {
    running = false;
    std::cout << "\nTerminating program...\n";

    // Export collected data to CSV before exiting
    exportToCsv(vehicleDataCollection, "vehicle_data.csv");  // Adjust filename as needed
    std::exit(0);  // Ensure the program terminates
}

int main() {
    // Set initial vehicle count (adjust as needed)
    int current_vehicle_count = 0;
    const int min_vehicle_increase = 1; // Minimum increase per loop
    const int max_vehicle_increase = 5; // Maximum increase per loop

    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, handle_SIGINT);

    // Main loop to capture timestamps and vehicle counts
    while (running) {
        // Get current timestamp
        uint64_t timestamp = getTimestampNow();

        // Generate random increase for vehicle count
        current_vehicle_count += generateRandomVehicleCount(min_vehicle_increase, max_vehicle_increase);

        // Create vehicle data object
        VehicleData data = {timestamp, current_vehicle_count};

        // Add data to collection
        vehicleDataCollection.push_back(data);

        // Brief pause to simulate real-time processing (adjust as needed)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // 100 milliseconds
    }

    return 0;
}
```

```python
import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
filename = "vehicle_data.csv"
data = pd.read_csv(filename)

# Convert the timestamp from microseconds to seconds for readability
data['Timestamp (seconds)'] = data['Timestamp (microseconds)'] / 1e6

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(data['Timestamp (seconds)'], data['Vehicle Count'], marker='o')

# Add labels and title
plt.xlabel('Timestamp (seconds)')
plt.ylabel('Vehicle Count')
plt.title('Vehicle Count Over Time')
plt.grid(True)

# Save the plot to a file
plt.savefig('vehicle_data_plot.png')

# Optionally, print a message to inform the user
print("Plot saved as 'vehicle_data_plot.png'")

```
```python
import pandas as pd
import matplotlib.pyplot as plt

# Load the data from the CSV file
filename = "vehicle_data.csv"
data = pd.read_csv(filename)

# Handle the scientific notation in timestamps
data['Timestamp (microseconds)'] = data['Timestamp (microseconds)'].apply(lambda x: int(float(x)))

# Convert the timestamp from microseconds to seconds for readability
data['Timestamp (seconds)'] = data['Timestamp (microseconds)'] / 1e6

# Group by 'Vehicle Number' and calculate the average timestamp for each vehicle
average_time_per_vehicle = data.groupby('Vehicle Number')['Timestamp (seconds)'].mean().reset_index()

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(average_time_per_vehicle['Vehicle Number'], average_time_per_vehicle['Timestamp (seconds)'], marker='o', linestyle='-', color='b')

# Add labels and title
plt.xlabel('Vehicle Number')
plt.ylabel('Average Timestamp (seconds)')
plt.title('Average Time Each Vehicle was Observed')
plt.grid(True)

# Save the plot to a file
plot_filename = 'average_time_per_vehicle_plot.png'
plt.savefig(plot_filename)
print(f"Plot saved as '{plot_filename}'")

# Show the plot (optional)
# plt.show()  # Uncomment this line if you want to display the plot interactively

```
```cpp
Certainly! I'll separate the implementation into header (.hpp) and source (.cpp) files for better organization and compilation efficiency. Here's the separated structure:

1. BenchmarkCommon.hpp
```cpp
#ifndef BENCHMARK_COMMON_HPP
#define BENCHMARK_COMMON_HPP

#include <string>

class BenchmarkCommon {
public:
    virtual void BenchmarkData(int datapoint, const char* data, int size) = 0;
    virtual void SaveToCSV(const std::string& filename) = 0;
    virtual ~BenchmarkCommon() = default;
};

#endif // BENCHMARK_COMMON_HPP
```

2. BenchmarkCommonFactory.hpp
```cpp
#ifndef BENCHMARK_COMMON_FACTORY_HPP
#define BENCHMARK_COMMON_FACTORY_HPP

#include <memory>
#include "BenchmarkCommon.hpp"

class BenchmarkCommonFactory {
public:
    virtual std::unique_ptr<BenchmarkCommon> createDataLogger() = 0;
    virtual ~BenchmarkCommonFactory() = default;
};

#endif // BENCHMARK_COMMON_FACTORY_HPP
```

3. DataLogger.hpp
```cpp
#ifndef DATA_LOGGER_HPP
#define DATA_LOGGER_HPP

#include "BenchmarkCommon.hpp"
#include <vector>
#include <chrono>

class DataLogger : public BenchmarkCommon {
private:
    struct LogEntry {
        std::chrono::system_clock::time_point timestamp;
        int datapoint;
        std::string data;
    };
    std::vector<LogEntry> log_buffer;

public:
    void BenchmarkData(int datapoint, const char* data, int size) override;
    void SaveToCSV(const std::string& filename) override;
};

#endif // DATA_LOGGER_HPP
```

4. DataLogger.cpp
```cpp
#include "DataLogger.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

void DataLogger::BenchmarkData(int datapoint, const char* data, int size) {
    std::string hex_data;
    hex_data.reserve(size * 2);
    for (int i = 0; i < size; ++i) {
        char hex[3];
        snprintf(hex, sizeof(hex), "%02x", static_cast<unsigned char>(data[i]));
        hex_data.append(hex);
    }

    log_buffer.push_back({std::chrono::system_clock::now(), datapoint, hex_data});
}

void DataLogger::SaveToCSV(const std::string& filename) {
    std::ofstream csv_file(filename);
    if (!csv_file.is_open()) {
        std::cerr << "Failed to open CSV file for writing." << std::endl;
        return;
    }

    csv_file << "Timestamp,Datapoint,Data\n";

    for (const auto& entry : log_buffer) {
        auto timestamp = std::chrono::system_clock::to_time_t(entry.timestamp);
        csv_file << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %H:%M:%S") << ","
                 << entry.datapoint << ","
                 << entry.data << "\n";
    }

    csv_file.close();
    std::cout << "CSV file saved: " << filename << std::endl;
}
```

5. DataLoggerFactory.hpp
```cpp
#ifndef DATA_LOGGER_FACTORY_HPP
#define DATA_LOGGER_FACTORY_HPP

#include "BenchmarkCommonFactory.hpp"

class DataLoggerFactory : public BenchmarkCommonFactory {
public:
    std::unique_ptr<BenchmarkCommon> createDataLogger() override;
};

#endif // DATA_LOGGER_FACTORY_HPP
```

6. DataLoggerFactory.cpp
```cpp
#include "DataLoggerFactory.hpp"
#include "DataLogger.hpp"

std::unique_ptr<BenchmarkCommon> DataLoggerFactory::createDataLogger() {
    return std::make_unique<DataLogger>();
}
```

7. main.cpp
```cpp
#include "DataLoggerFactory.hpp"
#include <iostream>

int main() {
    // Create factory
    std::unique_ptr<BenchmarkCommonFactory> factory = std::make_unique<DataLoggerFactory>();

    // Create DataLogger using factory
    std::unique_ptr<BenchmarkCommon> logger = factory->createDataLogger();

    // Use the logger
    for (int i = 0; i < 10; ++i) {
        int data = i * i;
        logger->BenchmarkData(i, reinterpret_cast<const char*>(&data), sizeof(data));
    }

    // Save logged data to CSV
    logger->SaveToCSV("benchmark_results.csv");

    return 0;
}
```

This separation allows for better organization of the code and enables separate compilation of different parts of the program. It also makes it easier to maintain and extend the codebase in the future.

To compile this program, you would typically create a Makefile or use a build system like CMake. Here's a simple Makefile example:

```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = main.cpp DataLogger.cpp DataLoggerFactory.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = benchmark_program

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)
```

You can compile the program by running `make` in the directory containing these files.

```


<div hidden>
```
@startuml
enum TimestampConfigType {
    LOG_TOOL
    STATISTICS
    MEMORY_ONLY
    NOOL
}

class TimestampConfig {
    -type: TimestampConfigType
    +getType(): TimestampConfigType
    +setType(TimestampConfigType)
}

interface ClockIF {
    +nsSinceEpoch(): unsigned long long
}

class ClockChrono {
    +nsSinceEpoch(): unsigned long long
}

interface TimestampInterface {
    +tic()
    +tac()
    +stamp()
    +getTime(): unsigned long long
}

class TimestampMemOnly {
    -m_clock: unique_ptr<ClockIF>
    -m_start: unsigned long long
    -m_end: unsigned long long
    -m_time: unsigned long long
    +TimestampMemOnly(unique_ptr<ClockIF>)
    +tic()
    +tac()
    +stamp()
    +getTime(): unsigned long long
}

class OutputHandler {
    -vec: vector<pair<unique_ptr<TimestampInterface>, int>>
    -configType: TimestampConfigType
    -OutputHandler(TimestampConfigType)
    +~OutputHandler()
    +{static} getInstance(TimestampConfigType): OutputHandler*
    +recordData(unique_ptr<TimestampInterface>, int)
    +getConfigType(): TimestampConfigType
}

class TimestampFactory {
    +{static} stamp(OutputHandler*): unique_ptr<TimestampInterface>
}

ClockIF <|-- ClockChrono
TimestampInterface <|-- TimestampMemOnly
TimestampMemOnly o-- ClockIF
OutputHandler o-- TimestampInterface
TimestampFactory ..> OutputHandler
TimestampFactory ..> TimestampInterface
@enduml

```
</div>

![](firstDiagram.svg)

```

```cpp
/**
 * @file timestamp_system.cpp
 * @brief Implements a flexible timestamp recording system.
 */

#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
#include <memory>
#include <thread>

/**
 * @enum TimestampConfigType
 * @brief Defines different types of timestamp configurations.
 */
enum TimestampConfigType {
    LOG_TOOL,    ///< Logging tool configuration
    STATISTICS,  ///< Statistics configuration
    MEMORY_ONLY, ///< Memory-only configuration
    NOOL,        ///< No operation configuration
};

/**
 * @class TimestampConfig
 * @brief Represents a timestamp configuration.
 */
class TimestampConfig {
public:
    /**
     * @brief Get the type of the timestamp configuration.
     * @return The type of the timestamp configuration.
     */
    TimestampConfigType getType() const;

    /**
     * @brief Set the type of the timestamp configuration.
     * @param t The type to set.
     */
    void setType(TimestampConfigType t);

private:
    TimestampConfigType type; ///< The type of the timestamp configuration
};

/**
 * @class ClockIF
 * @brief Interface for clock implementations.
 */
class ClockIF {
public:
    /**
     * @brief Get the number of nanoseconds since epoch.
     * @return The number of nanoseconds since epoch.
     */
    virtual unsigned long long nsSinceEpoch() = 0;
    virtual ~ClockIF() = default;
};

/**
 * @class ClockChrono
 * @brief Implements ClockIF using std::chrono.
 */
class ClockChrono : public ClockIF {
public:
    ClockChrono() = default;
    ~ClockChrono() = default;
    unsigned long long nsSinceEpoch() override;
};

/**
 * @class TimestampInterface
 * @brief Interface for timestamp implementations.
 */
class TimestampInterface {
public:
    virtual void tic() = 0;
    virtual void tac() = 0;
    virtual void stamp() = 0;
    /**
     * @brief Get the recorded time.
     * @return The recorded time in nanoseconds.
     */
    virtual unsigned long long getTime() const = 0;
    virtual ~TimestampInterface() = default;
};

/**
 * @class TimestampNull
 * @brief Implements TimestampInterface for memory-only operations.
 */
class TimestampNull : public TimestampInterface {
public:
    /**
     * @brief Construct a new TimestampNull object.
     * @param clock A unique pointer to a ClockIF implementation.
     */
    TimestampNull(std::unique_ptr<ClockIF> clock);
    ~TimestampNull() = default;

    void tic() override;
    void tac() override;
    void stamp() override;
    unsigned long long getTime() const override;

private:
    std::unique_ptr<ClockIF> m_clock;
    unsigned long long m_start = 0;
    unsigned long long m_end = 0;
    unsigned long long m_time = 0;
};

/**
 * @class OutputHandler
 * @brief Manages the recording and output of timestamps.
 */
class OutputHandler {
private:
    std::vector<std::pair<std::unique_ptr<TimestampInterface>, int>> vec;
    TimestampConfigType configType;

    OutputHandler(TimestampConfigType type);
    OutputHandler(const OutputHandler&) = delete;
    OutputHandler& operator=(const OutputHandler&) = delete;

public:
    ~OutputHandler();

    /**
     * @brief Get the singleton instance of OutputHandler.
     * @param type The type of timestamp configuration to use.
     * @return A pointer to the OutputHandler instance.
     */
    static OutputHandler* getInstance(TimestampConfigType type);

    /**
     * @brief Record timestamp data.
     * @param stamp A unique pointer to a TimestampInterface implementation.
     * @param id An identifier for the timestamp.
     */
    void recordData(std::unique_ptr<TimestampInterface> stamp, int id);

    /**
     * @brief Get the current timestamp configuration type.
     * @return The current timestamp configuration type.
     */
    TimestampConfigType getConfigType() const;
};

/**
 * @class TimestampFactory
 * @brief Factory class for creating TimestampInterface instances.
 */
class TimestampFactory {
public:
    /**
     * @brief Create a TimestampInterface instance based on the configuration.
     * @param config A pointer to the OutputHandler containing the configuration.
     * @return A unique pointer to a TimestampInterface implementation.
     */
    static std::unique_ptr<TimestampInterface> stamp(OutputHandler* config);
};

/**
 * @brief Main function demonstrating the usage of the timestamp system.
 * @return 0 on successful execution.
 */
int main();



//#################################
// #include <fstream>
// #include <iostream>
// #include <chrono>
// #include <vector>
// #include <memory>
// #include <thread>

// enum TimestampConfigType {
//     LOG_TOOL,
//     STATISTICS,
//     MEMORY_ONLY,
//     NOOL,
// };

// class TimestampConfig {
// public:
//     TimestampConfigType getType() const {
//         return type;
//     }
//     void setType(TimestampConfigType t) {
//         type = t;
//     }
// private:
//     TimestampConfigType type;
// };

// class ClockIF {
// public:
//     virtual unsigned long long nsSinceEpoch() = 0;
//     virtual ~ClockIF() = default;
// };

// class ClockChrono : public ClockIF {
// public:
//     ClockChrono() = default;
//     ~ClockChrono() = default;
//     unsigned long long nsSinceEpoch() override {
//         const auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
//         return std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();
//     }
// };

// class TimestampInterface {
// public:
//     virtual void tic() = 0;
//     virtual void tac() = 0;
//     virtual void stamp() = 0;
//     virtual unsigned long long getTime() const = 0;
//     virtual ~TimestampInterface() = default;
// };

// class TimestampNull : public TimestampInterface {
// public:
//     TimestampNull(std::unique_ptr<ClockIF> clock) : m_clock(std::move(clock)) {
//         stamp(); // Initialize m_time when created
//     }
//     ~TimestampNull() = default;

//     void tic() override {
//         m_start = m_clock->nsSinceEpoch();
//     }

//     void tac() override {
//         m_end = m_clock->nsSinceEpoch();
//     }

//     void stamp() override {
//         m_time = m_clock->nsSinceEpoch();
//     }

//     unsigned long long getTime() const override {
//         return m_time;
//     }

// private:
//     std::unique_ptr<ClockIF> m_clock;
//     unsigned long long m_start = 0;
//     unsigned long long m_end = 0;
//     unsigned long long m_time = 0;
// };

// class OutputHandler {
// private:
//     std::vector<std::pair<std::unique_ptr<TimestampInterface>, int>> vec;
//     TimestampConfigType configType;

//     OutputHandler(TimestampConfigType type) : configType(type) {}
//     OutputHandler(const OutputHandler&) = delete;
//     OutputHandler& operator=(const OutputHandler&) = delete;

// public:
//     ~OutputHandler() {
//         std::ofstream file("example.csv", std::ios::trunc);
//         file <<"ID,Timestamp"<<std::endl;
//         for (const auto& [stamp, id] : vec) {
//             file<< id << ", " << stamp->getTime() << std::endl;
//         }
//     }

//     static OutputHandler* getInstance(TimestampConfigType type) {
//         static OutputHandler instance(type);
//         return &instance;
//     }

//     void recordData(std::unique_ptr<TimestampInterface> stamp, int id) {
//         stamp->stamp(); // Ensure we have the latest time
//         vec.emplace_back(std::move(stamp), id);
//     }

//     TimestampConfigType getConfigType() const {
//         return configType;
//     }
// };


// class TimestampFactory {
// public:
//     static std::unique_ptr<TimestampInterface> stamp(OutputHandler* config) {
//         // Assuming we can get the TimestampConfigType from OutputHandler
//         TimestampConfigType type = config->getConfigType();
//         switch(type) {
//             case TimestampConfigType::MEMORY_ONLY:
//                 return std::make_unique<TimestampNull>(std::make_unique<ClockChrono>());
//             case TimestampConfigType::LOG_TOOL:
//             case TimestampConfigType::STATISTICS:
//             case TimestampConfigType::NOOL:
//             default:
//                 return nullptr; // Or throw an exception
//         }
//     }
// };


// int main() {
//     OutputHandler* config = OutputHandler::getInstance(TimestampConfigType::MEMORY_ONLY);
    
//     int id = 1; // Example ID

//     auto stamp = TimestampFactory::stamp(config);
//     config->recordData(std::move(stamp), id);

//     //for (int i = 0; i <= 5; i++) {
//         // Simulate a 5 second loop
//         std::this_thread::sleep_for(std::chrono::seconds(6));
//     //}

//     id = 2; // New ID for the second timestamp
//     stamp = TimestampFactory::stamp(config);
//     config->recordData(std::move(stamp), id);

//     // OutputHandler will be automatically destroyed at the end of the program,
//     // which will trigger the recording of all stored timestamps to the file.

//     return 0;
// }
```

```cpp
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
#include <memory>
#include <thread>

enum TimestampConfigType {
    LOG_TOOL,
    STATISTICS,
    MEMORY_ONLY,
    NOOL,
};

class TimestampConfig {
public:
    TimestampConfigType getType() const {
        return type;
    }
    void setType(TimestampConfigType t) {
        type = t;
    }
private:
    TimestampConfigType type;
};

class ClockIF {
public:
    virtual unsigned long long nsSinceEpoch() = 0;
    virtual ~ClockIF() = default;
};

class ClockChrono : public ClockIF {
public:
    ClockChrono() = default;
    ~ClockChrono() = default;
    unsigned long long nsSinceEpoch() override {
        const auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();
    }
};

class TimestampInterface {
public:
    virtual void tic() = 0;
    virtual void tac() = 0;
    virtual void stamp() = 0;
    virtual unsigned long long getTime() const = 0;
    virtual ~TimestampInterface() = default;
};

class TimestampMemOnly : public TimestampInterface {
public:
    TimestampMemOnly(std::unique_ptr<ClockIF> clock) : m_clock(std::move(clock)) {
        stamp(); // Initialize m_time when created
    }
    ~TimestampMemOnly() = default;

    void tic() override {
        m_start = m_clock->nsSinceEpoch();
    }

    void tac() override {
        m_end = m_clock->nsSinceEpoch();
    }

    void stamp() override {
        m_time = m_clock->nsSinceEpoch();
    }

    unsigned long long getTime() const override {
        return m_time;
    }

private:
    std::unique_ptr<ClockIF> m_clock;
    unsigned long long m_start = 0;
    unsigned long long m_end = 0;
    unsigned long long m_time = 0;
};

class OutputHandler {
private:
    std::vector<std::pair<std::unique_ptr<TimestampInterface>, int>> vec;
    TimestampConfigType configType;

    OutputHandler(TimestampConfigType type) : configType(type) {}
    OutputHandler(const OutputHandler&) = delete;
    OutputHandler& operator=(const OutputHandler&) = delete;

public:
    ~OutputHandler() {
        std::ofstream file("example.csv", std::ios::trunc);
        file <<"ID,Timestamp"<<std::endl;
        for (const auto& [stamp, id] : vec) {
            file<< id << ", " << stamp->getTime() << std::endl;
        }
    }

    static OutputHandler* getInstance(TimestampConfigType type) {
        static OutputHandler instance(type);
        return &instance;
    }

    void recordData(std::unique_ptr<TimestampInterface> stamp, int id) {
        stamp->stamp(); // Ensure we have the latest time
        vec.emplace_back(std::move(stamp), id);
    }

    TimestampConfigType getConfigType() const {
        return configType;
    }
};


class TimestampFactory {
public:
    static std::unique_ptr<TimestampInterface> stamp(OutputHandler* config) {
        // Assuming we can get the TimestampConfigType from OutputHandler
        TimestampConfigType type = config->getConfigType();
        switch(type) {
            case TimestampConfigType::MEMORY_ONLY:
                return std::make_unique<TimestampMemOnly>(std::make_unique<ClockChrono>());
            case TimestampConfigType::LOG_TOOL:
            case TimestampConfigType::STATISTICS:
            case TimestampConfigType::NOOL:
            default:
                return nullptr; // Or throw an exception
        }
    }
};


int main() {
    OutputHandler* config = OutputHandler::getInstance(TimestampConfigType::MEMORY_ONLY);
    
    int id = 1; // Example ID

    auto stamp = TimestampFactory::stamp(config);
    config->recordData(std::move(stamp), id);

    //for (int i = 0; i <= 5; i++) {
        // Simulate a 5 second loop
        std::this_thread::sleep_for(std::chrono::seconds(6));
    //}

    id = 2; // New ID for the second timestamp
    stamp = TimestampFactory::stamp(config);
    config->recordData(std::move(stamp), id);

    // OutputHandler will be automatically destroyed at the end of the program,
    // which will trigger the recording of all stored timestamps to the file.

    return 0;
}
```




