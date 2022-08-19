#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <tuple>

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
    out << pers.lastName << "\t" << pers.firstName << "\t";
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
        std::string ln;
        while (std::getline(file, ln)){
            std::pair<Person, PhoneNumber> buff;

            book.push_back(buff);
        }
        //не разобрался с раскладыванием строки

    }
    
    friend std::ostream& operator<< (std::ostream& out, const PhoneBook& phBook);

    void SortByName (){ 
        std::sort(book.begin(), book.end(), 
            [] (const std::pair<Person, PhoneNumber> p1, const std::pair<Person, PhoneNumber> p2) 
                -> bool {return p1.first < p2.first;});   
    }

    void SortByPhone (){ 
        std::sort(book.begin(), book.end(), 
            [] (const std::pair<Person, PhoneNumber> p1, const std::pair<Person, PhoneNumber> p2) 
                -> bool {return p1.second < p2.second;}); 
    }

    std::string GetPhoneNumber (std::string lookingLastName){
        std::string outStr;
        std::stringstream number;
        size_t counter { 0 };

        for (size_t i = 0; i < book.size(); i++)
        {
            if (book[i].first.lastName == lookingLastName){
                number << book[i].second << " ";
                counter++;
            }
        }
        if (counter == 0) {
            outStr = "not found";
        } else if (counter > 1) {
            outStr = "found more than 1 ";
        }
        number >> outStr;
        return outStr;
    }

    void ChangePhoneNumber (Person person, PhoneNumber phNumber){
        for (size_t i = 0; i < book.size(); i++)
        {
            if (book[i].first == person){
                book[i].second = phNumber;
                break;
            }
        }
    };

};

std::ostream& operator<< (std::ostream& out, const PhoneBook& phBook){
    for (size_t i = 0; i < phBook.book.size(); i++)
    {
        out << phBook.book[i].first << "\t";
        out << phBook.book[i].second << "\n";      
    }
    return out;
}

int main (){

    return 0;
}