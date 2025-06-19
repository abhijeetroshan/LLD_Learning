#pragma once
#include <string>
class User {
public:
    std::string id, name, phone;
    User(std::string i, std::string n, std::string p) : id(i), name(n), phone(p) {}
};
