#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

//using namespace std;

struct Person {
    std::string lastName;
    std::string firstName;
    std::optional<std::string> fathersName;

    friend std::ostream& operator<< (std::ostream& out, const Person& pers);
    friend bool operator< (const Person& p1, const Person& p2);
    friend bool operator== (const Person& p1, const Person& p2);
};

std::ostream& operator<< (std::ostream& out, const Person& pers){
    out << pers.lastName << " " << pers.firstName << " ";
    if (pers.fathersName)
        out << *pers.fathersName;
    return out;
}

bool operator< (const Person& p1, const Person& p2){
    return std::tie(p1.lastName, p1.firstName, *p1.fathersName) < 
            std::tie(p2.lastName, p2.firstName, *p2.fathersName);
}

bool operator== (const Person& p1, const Person& p2){
    return std::tie(p1.lastName, p1.firstName, *p1.fathersName) == 
            std::tie(p2.lastName, p2.firstName, *p2.fathersName);
}

struct PhoneNumber{
    int countryCode;
    int cityCode;
    std::string number;
    std::optional<int> addNumber;

    friend std::ostream& operator<< (std::ostream& out, const PhoneNumber& ph);
    friend bool operator< (const PhoneNumber& pn1, const PhoneNumber& pn2);
    friend bool operator== (const PhoneNumber& pn1, const PhoneNumber& pn2);
};

std::ostream& operator<< (std::ostream& out, const PhoneNumber& pn){
    out << "+" << pn.countryCode << "(" << pn.cityCode << ")" << pn.number;
    if (pn.addNumber)
        out << " " << *pn.addNumber;
    return out;
}

bool operator< (const PhoneNumber& pn1, const PhoneNumber& pn2){
    return std::tie(pn1.countryCode, pn1.cityCode, pn1.number, pn1.addNumber) <
            std::tie(pn2.countryCode, pn2.cityCode, pn2.number, pn2.addNumber);
}

bool operator== (const PhoneNumber& pn1, const PhoneNumber& pn2){
    return std::tie(pn1.countryCode, pn1.cityCode, pn1.number, pn1.addNumber) ==
            std::tie(pn2.countryCode, pn2.cityCode, pn2.number, pn2.addNumber);
}

class PhoneBook {
private:
    std::vector<std::pair<Person, PhoneNumber>> book;
public:
    PhoneBook (std::ifstream& file){
        
        
        book[0].first.fathersName;
    }
};

int main (){

    return 0;
}