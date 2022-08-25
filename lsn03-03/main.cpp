#include <iostream>
#include <list>
#include <array>
#include <iterator>

#define SZ 3

void averageInList(std::list<double>& list){
    double number { 0 };
    for (auto i : list)
        number += i;
    number /= list.size();
    list.push_back(number);
}

class Matrix {
private:
    std::array <std::array <int, SZ>, SZ> arr;
public:
    Matrix () {};
    Matrix (std::array <std::array <int, SZ>, SZ> _arr) {
        for (size_t i = 0; i < SZ; i++)
            for (size_t j = 0; j < SZ; j++)
                arr[i][j] = _arr[i][j];
    };
    ~Matrix () {};

    double determinant(){
        double result { 0 };
        result = arr[0][0]*arr[1][1]*arr[2][2] + arr[2][0]*arr[0][1]*arr[1][2] + 
                arr[1][0]*arr[2][1]*arr[0][2] - arr[2][0]*arr[1][1]*arr[0][2] -
                arr[1][0]*arr[0][1]*arr[2][2] - arr[0][0]*arr[1][2]*arr[2][1];
        return result;
    };

    friend std::ostream& operator<< (std::ostream& out, const Matrix& mat);
};

std::ostream& operator<< (std::ostream& out, const Matrix& mat){
    for (size_t i = 0; i < SZ; i++){
        for (size_t j = 0; j < SZ; j++)
            out << mat.arr[i][j] << " ";
        out << std::endl;
    }
    return out;
}

template <typename T>
class MyIterator {
private:
    T* current;

public:
    MyIterator (T* it) : current (it){};
    
    MyIterator& operator= (MyIterator income){
        current = income.current;
        return *this;
    }
 
    MyIterator& operator++ (){
        ++current;
        return *this;
    }

    MyIterator& operator++ (int noOne){
        current++;
        return *this;
    }

    MyIterator& operator-- (){
        --current;
        return *this;
    }

    MyIterator& operator-- (int noOne){
        current--;
        return *this;
    }

    bool operator< (MyIterator income){
        return current < income.current;
    }

    bool operator> (MyIterator income){
        return current < income.current;
    }

    MyIterator& operator* (){        
        return *current;
    }
};

int main (){
    std::list<double> lst {4.12, 5.5, 3.67};
    averageInList(lst);
    for (auto i : lst)
        std::cout << i << " " << std::endl;

    std::array <std::array <int, SZ>, SZ> 
        arr = {{{2, 3, 4}, {5, 2, 1}, {6, 8, 9}}};
    Matrix m = arr;
    std::cout << std::endl << "for matrix:" << std::endl << m
                << "determinant is: " << m.determinant() << std::endl;
    
    std::array <int, SZ> test = {5, 6, 69};
    MyIterator it = test.begin();
    int i { 0 };
    for (; it < test.end(); it++){
        std::cout << i++;
    }
    
    return 0;
}