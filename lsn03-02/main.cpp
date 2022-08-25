#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::string m_name;
    std::chrono::time_point<clock_t> m_beg;
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now()-m_beg).count();
    }
public:
    Timer() : m_beg(clock_t::now()) { }
    Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }
    void start(std::string name) {
        m_name = name;
        m_beg = clock_t::now();
    }
    void print() const {
        std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
    }
};


template <typename T>
void Swap (T** a, T** b){
    T* c;
    c = *a;
    *a = *b;
    *b = c;
}

template <typename T>
void SortPointers (std::vector<T**> vec){
    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec.size() - 1; j++)
        {
            if(**vec[j] < **vec[j+1])
                Swap (&vec[j], &vec[j+1]);
        }        
    }
}

/* недоделано :(
bool foo(char ch){
    return ch == 'a';
}

int vowelСount_CIF_FOR (std::string txt, const std::vector<char>& vowelList){
    unsigned int count { 0 };
    for (size_t i = 0; i < vowelList.size(); i++)
    {
        count = std::count_if(txt.begin(), txt.end(), foo);
    }
    return count;
}
*/

int vowelСount_FOR_FIND (std::string txt, const std::vector<std::string>& vowelList){
    unsigned int count { 0 };
    for (size_t i = 0; i < vowelList.size(); i++)
    {
        for (size_t j = 0; j < txt.size(); j++)
        {
            int pos { 0 };
            pos = txt.find(vowelList[i], j);
            if (pos >= 0 ){
                count ++;
                j = pos + 1;
            } 
        }       
    }
    return count;
}

int vowelСount_FOR_FOR (std::string txt, const std::vector<char>& vowelList){
    unsigned int count { 0 };
    for (size_t i = 0; i < vowelList.size(); i++)
    {
        for (size_t j = 0; j < txt.size(); j++)
        {
            if (txt[j] == vowelList[i])
                count++;
        }
    }
    return count;
}

int main(){
    std::string txt = "Mother uhet";
    //использую английскийб тк не понял как запихнуть русские char
    std::vector<char> vowelListChar {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    std::vector<std::string> vowelListStr {"A" "E", "I", "O", "U", "a", "e", "i", "o", "u"};

//    std::cout << vowelСount_CIF_FIND(txt, vowelListStr) << std::endl; 
    std::cout << vowelСount_FOR_FOR(txt, vowelListChar) << std::endl;
    std::cout << vowelСount_FOR_FIND(txt, vowelListStr) << std::endl;

    return 0;
}