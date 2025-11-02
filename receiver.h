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
    static const size_t  SIZE_Struct = 4;
    std::vector<receiver_data> receivers;

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

    ~Radioreceiver() {}
};

#endif
