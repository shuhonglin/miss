#pragma once
#include<string>
#include<iostream>

class Book {
private:
    std::string name;
    std::string isbn;

public:
    Book();
    Book(const std::string &name, const std::string &isbn);
    ~Book();

    void printBook();
};