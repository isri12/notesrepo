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

