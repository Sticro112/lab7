#include "receiver.h"
#include <iostream>
#include <string>
#include <vector>


void Radioreceiver::input() {
    for (size_t i = 0; i < SIZE_Struct; ++i) {

        std::cout << "Working frequency: ";
        std::cin >> receivers[i][0].working_frequency;
        
        std::cout << " Sensitivity: ";
        std::cin >> receivers[i][1].sensitivity;
        
        std::cout << " Type of modulation: ";
        std::cin >> receivers[i][2].modulation_type;

        if (!validate_wf(receivers[i][0].working_frequency)) {
            error();
        
            receivers[i][0].working_frequency = 404.0;
        }
        else if (!validate_st(receivers[i][1].sensitivity))
        {
            error();
            receivers[i][1].sensitivity = 404.0;
        }
        else if (!validate_mt(receivers[i][2].modulation_type))
        {
            error();
            receivers[i][2].modulation_type = "ERROR";
        }
        
    }
}

 void Radioreceiver::display() {
        for (size_t n = 0; n < SIZE_Struct; ++n) {
            
            std::cout << "Working frequency: " << receivers[n][0].working_frequency
                      << " Sensitivity: " << receivers[n][1].sensitivity
                      << " Modulation: " << receivers[n][2].modulation_type << std::endl;
           
        }
    }