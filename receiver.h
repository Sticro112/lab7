#ifndef RECEIVER_H
#define RECEIVER_H
#include <iostream>
#include <vector>
#include <string>

struct receiver_data
{
    double working_frequency;
    double sensitivity;
    std::string modulation_type;
};



class Radioreceiver {
    private:
    std::vector<receiver_data> receivers;
    static const size_t  SIZE_Struct = 3;

     void error() const {
        std::cout << "Error!!\n";
    }

    bool validate_wf(double wf) const {
        return (wf > 0);
    }
    bool validate_st(double st) const {
        return (st > 0);
    }
    bool validate_mt(std::string& mt) const {
        return (!mt.empty());
    }
    public:
    Radioreceiver(){}

    void input();
    void display();
    void add(double freq, double sens, const std::string &mt);
    void insert(size_t index, double freq, double sens, const std::string& mt);
    void remove(size_t index);
    void exchange(size_t i, size_t j);
    void clear();

    ~Radioreceiver() {}
};

#endif
