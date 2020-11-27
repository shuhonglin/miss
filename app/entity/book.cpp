#include "book.h"

Book::Book() {}
Book::Book(const std::string &name, const std::string &isbn)
{
    this->name = name;
    this->isbn = isbn;
}
Book::~Book() {}

void Book::printBook()
{
    std::cout << "isbn: " << this->isbn << ", name: " << this->name << std::endl;
}