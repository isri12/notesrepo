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


