#pragma once
#include <string>
#include <iostream>

class Book
{
private:
    std::string name;
    std::string isbn;
    const int price;

public:
    Book();
    Book(const std::string &name, const std::string &isbn, const int p);
    Book(const Book & b); //复制构造函数
    virtual ~Book(); // 析构函数应当声明为虚函数

    virtual void printBook() const;

    friend std::ostream & operator<<(std::ostream &os, const Book &b);

    Book & operator=(const Book &b);

    operator int() const;
};

class ChineseBook : public Book 
{

private:
    int type;

public:

    void printBook() const;

    ChineseBook(const std::string &name, const std::string &isbn, const int p):Book(name, isbn, p),type(1)
    {
    };
    ChineseBook(const Book & b):Book(b),type(1)
    {

    }; //复制构造函数

    ~ChineseBook()
    {
        std::cout<<"chinese book destructure"<<std::endl;
    };
};