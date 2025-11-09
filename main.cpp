#include "receiver.h"
#include <iostream>

int main() {
    Radioreceiver radio;
    radio.input();
    radio.display();
    radio.add(450, 340, "FM");
    radio.display();
    radio.insert(2, 777, 400, "WI");
    radio.display();
    radio.remove(1);
    radio.display();
    radio.exchange(0, 1);
    radio.display();
    radio.clear();
    radio.display();

    return 0;
}
