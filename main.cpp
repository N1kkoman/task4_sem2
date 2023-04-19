#include <iostream>
#include "inc/Device.h"
#include <fstream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");

    SmartHomeSystem system;

    system.readConfigFromFile("devices.txt");
    system.poll();
    return 0;
}