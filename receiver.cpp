#include "receiver.h"
#include <iostream>
#include <string>
#include <vector>


void Radioreceiver::input() {
    for (size_t i = 0; i < SIZE_Struct; ++i) {

        std::cout << "Working frequency: ";
        std::cin >> receivers[i].working_frequency;
        
        std::cout << " Sensitivity: ";
        std::cin >> receivers[i].sensitivity;
        
        std::cout << " Type of modulation: ";
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
        for (size_t n = 0; n < SIZE_Struct; ++n) {
            
            std::cout << "Working frequency: " << receivers[n].working_frequency
                      << " Sensitivity: " << receivers[n].sensitivity
                      << " Modulation: " << receivers[n].modulation_type << std::endl;
           
        }
    }
