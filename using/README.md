# Yaml

## 1.Yaml介绍

​    YAML（YAML Ain't Markup Language）是一种人类可读的数据序列化格式。它的设计目标是使数据在文件中以一种可读性高、易于理解和编辑的方式进行表示。YAML 被广泛用于配置文件、数据交换、配置管理和许多其他领域

## 2.Yaml的特点

1. **可读性高**: YAML 使用缩进和简洁的语法来表示数据结构，这使得 YAML 文件非常容易阅读和编写，也适合用于配置文件，因为它不需要太多的标记符号

2. **层次结构**: YAML 支持层次结构，通过缩进的方式表示对象之间的关系。这使得它可以用来表示复杂的数据结构，如嵌套的字典或列表

3. **支持多种数据类型**: YAML 支持表示字符串、数字、布尔值、日期时间以及更复杂的数据类型，如列表和字典

4. **自我描述性**: YAML 文件通常包含有关数据的描述性信息，这有助于人们理解数据的含义

5. **可扩展性**: YAML 支持用户定义的数据类型和标签，这意味着你可以根据需要扩展 YAML 的语义

6. **跨平台性**: YAML 是一种平台无关的格式，可以在不同的编程语言和操作系统之间进行解析和生成

   ```yaml
   # 这是一个 YAML 示例文件
   name: John Doe
   age: 30
   email: john@example.com
   is_student: false
   favorite_colors:
     - Red
     - Blue
     - Green
   address:
     street: 123 Main St
     city: Anytown
     zip_code: 12345
   ```

## 3.Yaml如何被编程读取

### C++

1. 安装YAML-CPP库：首先，确保你已经安装了YAML-CPP库。你可以通过下载源代码并编译，或者使用包管理器（如vcpkg或Conda）来安装

2. 包含必要的头文件：在你的C++代码中包含YAML-CPP的头文件

   ```c++
   #include "yaml-cpp/yaml.h"
   ```

3. 打开和读取YAML文件：使用YAML-CPP来打开和读取YAML文件

   ```c++
   YAML::Node config = YAML::LoadFile("config.yaml");
   //这会将YAML文件 "config.yaml" 中的内容加载到一个YAML::Node对象中。你可以替换 "config.yaml" 为你实际的YAML文件路径
   ```

4. 访问YAML数据：现在你可以通过节点对象来访问YAML文件中的数据。节点对象允许你按照YAML文件的层次结构来访问数据

   ```C++
   std::string name = config["name"].as<std::string>();
   int age = config["age"].as<int>();
   std::string email = config["email"].as<std::string>();
   ```

5. 处理复杂的YAML结构：如果YAML文件包含嵌套的结构（如列表和字典），你可以使用节点对象来访问这些数据

   ```c++
   std::vector<std::string> favoriteColors = config["favorite_colors"].as<std::vector<std::string>>();
   std::string street = config["address"]["street"].as<std::string>();
   std::string city = config["address"]["city"].as<std::string>();
   int zipCode = config["address"]["zip_code"].as<int>();
   ```

6. 错误处理：在读取YAML文件时，务必进行错误处理以处理可能的异常情况，例如文件不存在或格式不正确。

   ```c++
   try {
       YAML::Node config = YAML::LoadFile("config.yaml");
       // 访问YAML数据...
   } catch (const YAML::Exception& e) {
       std::cerr << "YAML parsing error: " << e.what() << std::endl;
       // 处理错误...
   }
   ```

### python

1. 安装PyYAML库：首先，确保你已经安装了PyYAML库。你可以使用pip来安装它

   ```shell
   pip install pyyaml
   ```

2. 导入PyYAML模块：在Python代码中导入PyYAML模块

   ```python
   import yaml
   ```

3. 打开和读取YAML文件：使用PyYAML来打开和读取YAML文件

   ```python
   with open("config.yaml", "r") as yaml_file:
       data = yaml.safe_load(yaml_file)
       ##这会将YAML文件 "config.yaml" 中的内容加载到一个Python字典或列表中，具体取决于文件的结构。你可以替换 "config.yaml" 为你实际的YAML文件路径
   ```

4. 访问YAML数据：现在你可以通过Python字典或列表来访问YAML文件中的数据

   ```python
   name = data["name"]
   age = data["age"]
   email = data["email"]
   ```

5. 处理复杂的YAML结构：如果YAML文件包含嵌套的结构（如列表和字典），你可以使用Python的数据访问方法来访问这些数据

   ```python
   favorite_colors = data["favorite_colors"]
   street = data["address"]["street"]
   city = data["address"]["city"]
   zip_code = data["address"]["zip_code"]
   ```

6. 错误处理：在读取YAML文件时，务必进行错误处理以处理可能的异常情况，例如文件不存在或格式不正确

   ```python
   try:
       with open("config.yaml", "r") as yaml_file:
           data = yaml.safe_load(yaml_file)
       # 访问YAML数据...
   except FileNotFoundError:
       print("YAML file not found.")
   except yaml.YAMLError as e:
       print("YAML parsing error:", e)
       # 处理错误...
   ```

   

# 模板类

1. 示例

   ```c++
   //模板类（Template class）是C++中的一种特殊类型的类，它允许你编写通用的类定义，其中某些类型（通常是数据类型）可以在使用该类时进行参数化。模板类的主要目的是为了实现通用性和代码重用
   
   
   template<typename T>
   class MyTemplateClass {
   public:
       MyTemplateClass(T value) : data(value) {}
   
       T getValue() {
           return data;
       }
   
   private:
       T data;
   };
   
   int main() {
       // 实例化模板类并传入不同的数据类型
       MyTemplateClass<int> intObject(42);
       MyTemplateClass<double> doubleObject(3.14);
       MyTemplateClass<std::string> stringObject("Hello, World!");
   
       // 使用模板类的实例
       int intValue = intObject.getValue();
       double doubleValue = doubleObject.getValue();
       std::string stringValue = stringObject.getValue();
   
       // 输出结果
       std::cout << "Integer Value: " << intValue << std::endl;
       std::cout << "Double Value: " << doubleValue << std::endl;
       std::cout << "String Value: " << stringValue << std::endl;
   
       return 0;
   }
   /*
   在这个示例中，我们定义了一个名为 MyTemplateClass 的模板类，它包含一个数据成员 data，并具有一个用于返回数据成员值的成员函数 getValue()。模板类使用 <typename T> 来声明模板参数 T，这个参数表示模板类可以接受不同的数据类型。
   
   在 main() 函数中，我们实例化了三个不同类型的 MyTemplateClass 对象：一个整数对象，一个双精度浮点数对象，和一个字符串对象。然后，我们分别使用它们的 getValue() 方法来获取不同类型的数据，并输出结果。
   
   这个示例演示了模板类的通用性，它可以在不同的数据类型上工作，从而提高了代码的重用性和灵活性。模板类在STL（标准模板库）中广泛使用，例如，容器类（如std::vector和std::list）和算法函数（如std::sort）都使用了模板类的概念
   */
   ```

   

2. 使用模板类实现两数之和

   ```c++
   #include <iostream>
   
   template <typename T>
   T add(T a, T b) {
       return a + b;
   }
   
   int main() {
       int num1 = 5;
       int num2 = 7;
       
       double doubleNum1 = 3.14;
       double doubleNum2 = 2.71;
       
       // 使用模板函数计算两个整数之和
       int sum1 = add(num1, num2);
       
       // 使用模板函数计算两个双精度浮点数之和
       double sum2 = add(doubleNum1, doubleNum2);
       
       std::cout << "Sum of integers: " << sum1 << std::endl;
       std::cout << "Sum of doubles: " << sum2 << std::endl;
       
       return 0;
   }
   /*
   在上述示例中，我们定义了一个通用的模板函数 add，它可以接受不同类型的参数 a 和 b。在 main 函数中，我们分别使用整数和双精度浮点数调用了 add 函数，并将其返回的结果打印出来。
   
   这个模板函数 add 在不同数据类型上都可以工作，并返回正确的和。这是C++模板的强大之处，它使得你可以编写通用的函数，无需为每种数据类型编写不同的版本
   */
   ```

   