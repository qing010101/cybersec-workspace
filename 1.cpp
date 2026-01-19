#include <iostream>
#include <string>
using namespace std;

// 抽象类 Animal
class Animal {
protected:       // name 和 age 子类可以访问
    string name;
    int age;
public:
    Animal(string n, int a) : name(n), age(a) {} // 构造函数
    virtual void speak() = 0;  // 纯虚函数，必须被子类重写
    virtual ~Animal() {}        // 虚析构，保证多态删除安全
};

// Dog 继承 Animal
class Dog : public Animal {
public:
    Dog(string n, int a) : Animal(n, a) {}  // 调用父类构造函数
    void speak() override {                 // 重写父类的纯虚函数
        cout << name << ": 汪汪" << endl;
    }
};

// Cat 继承 Animal
class Cat : public Animal {
public:
    Cat(string n, int a) : Animal(n, a) {}
    void speak() override {
        cout << name << ": 喵喵" << endl;
    }
};

int main() {
    // 用父类指针管理子类对象
    Animal* a1 = new Dog("旺财", 3);
    Animal* a2 = new Cat("咪咪", 2);

    a1->speak();  // 输出: 旺财: 汪汪
    a2->speak();  // 输出: 咪咪: 喵喵

    delete a1;    // 安全释放
    delete a2;

    return 0;
}
