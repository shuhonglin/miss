#include "book.h"

// price(xxx)用于在构造函数执行前初始化成员变量, 对于常量成员及引用成员必须使用该方法初始化
Book::Book() : price(0) {}
Book::Book(const std::string &name, const std::string &isbn, const int p) : price(p)
{
    this->name = name;
    this->isbn = isbn;
}

Book::Book(const Book &b) : price(b.price)
{
    this->isbn = b.isbn;
    this->name = b.name;
}
Book::~Book()
{
    std::cout << "book destructure" << std::endl;
}

void Book::printBook() const
{
    std::cout << "isbn: " << this->isbn << ", name: " << this->name << std::endl;
}

Book &Book::operator=(const Book &b)
{
    if (this == &b)
    {
        return *this;
    }
    this->name = b.name;
    this->isbn = b.isbn;
    return *this;
}

Book::operator int() const
{
    return this->price;
}

void ChineseBook::printBook() const
{
    Book::printBook();
    std::cout << "type: " << this->type << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Book &b)
{
    os << "name: " << b.name << ", isbn: " << b.isbn;
    return os;
}
