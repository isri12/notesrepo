Study Links Topics
- [singelton] (https://www.codeproject.com/Articles/987473/Unit-Testing-a-Singleton-in-Cplusplus)
- 

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

