#include "receiver.h"
#include <iostream>
#include <string>
#include <vector>


void Radioreceiver::input() {
    for (size_t i = 0; i < SIZE_Struct; ++i) {
        receivers.push_back(receiver_data());

        std::cout << "Working frequency: " ;
        std::cin >> receivers[i].working_frequency;
        
        std::cout << "Sensitivity: ";
        std::cin >> receivers[i].sensitivity;
        
        std::cout << "Type of modulation: ";
        std::cin >> receivers[i].modulation_type;

        if (!validate_wf(receivers[i].working_frequency)) {
            error();
        
            receivers[i].working_frequency = 404.0;
        }
        else if (!validate_st(receivers[i].sensitivity))
        {
            error();
            receivers[i].sensitivity = 404.0;
        }
        else if (!validate_mt(receivers[i].modulation_type))
        {
            error();
            receivers[i].modulation_type = "ERROR";
        }
        
    }
}

 void Radioreceiver::display() {
        for (size_t n = 0; n < receivers.size(); ++n) {
            
            std::cout << "Working frequency: " << receivers[n].working_frequency
                      << " Sensitivity: " << receivers[n].sensitivity
                      << " Modulation: " << receivers[n].modulation_type << std::endl;
           
        }
        std::cout << "  " << std::endl;
    }

void Radioreceiver::add(double freq, double sens, const std::string& mt) {
        receivers.emplace_back(receiver_data{freq, sens, mt});
    }

void Radioreceiver::insert(size_t index, double freq, double sens, const std::string& mt) {
        if (index > receivers.size()) {
            std::cerr << "Error: invalid index.\n";
            return;
        }
        receivers[index].working_frequency = freq;
        receivers[index].sensitivity = sens;
        receivers[index].modulation_type = mt;
    }

void Radioreceiver::remove(size_t index) {
        if (index >= receivers.size()) {
            std::cerr << "Error: index out of range.\n";
            return;
        }
        receivers.erase(receivers.begin() + index);
    }

 void Radioreceiver::exchange(size_t i, size_t j) {
        if (i >= receivers.size() || j >= receivers.size()) {
            std::cerr << "Error: index out of range.\n";
            return;
        }
        std::swap(receivers[i], receivers[j]);
    }

void Radioreceiver::clear() {
     receivers.clear();
}
