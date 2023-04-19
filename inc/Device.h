#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Device {
protected:
    std::string DeviceName;
public:
    explicit Device(const std::string& deviceName) : DeviceName(deviceName) {}

    void poll() const {
        std::cout << DeviceName << std::endl;
    }
};



class Counter : public Device {
public:
    explicit Counter(const std::string& deviceName) : Device(deviceName) {}
};

class DiscreteSignals : public Device {
public:
    explicit DiscreteSignals(const std::string& deviceName) : Device(deviceName) {}
};

class Heating : public Device {
public:
    explicit Heating(const std::string& deviceName) : Device(deviceName) {}
};



class Mercury final : public Counter {
public:
    explicit Mercury(const std::string& deviceName) : Counter(deviceName) {}
};

class Neva final : public Counter {
public:
    explicit Neva(const std::string& deviceName) : Counter(deviceName) {}
};

class Energo final : public Counter {
public:
    explicit Energo(const std::string& deviceName) : Counter(deviceName) {}
};



class RealLab final : public DiscreteSignals {
public:
    explicit RealLab(const std::string& deviceName) : DiscreteSignals(deviceName) {}
};

class DeviceElectro final : public DiscreteSignals {
public:
    explicit DeviceElectro(const std::string& deviceName) : DiscreteSignals(deviceName) {}
};

class ServiceEnergy final : public DiscreteSignals {
public:
    explicit ServiceEnergy(const std::string& deviceName) : DiscreteSignals(deviceName) {}
};



class Ouman : public Heating {
public:
    explicit Ouman(const std::string& deviceName) : Heating(deviceName) {}
};

class Owen : public Heating {
public:
    explicit Owen(const std::string& deviceName) : Heating(deviceName) {}
};

Device* deviceFabric(const std::string& deviceName) { // создание объекта устройства 
    Device* currentDevice;
    switch (static_cast<int>((unsigned char)deviceName[0])) { // проверка первого символа названий приборов
    case (204):
        currentDevice = new Mercury(deviceName);
        break;
    case (205):
        currentDevice = new Neva(deviceName);
        break;
    case (221):
        if (236 == static_cast<int>((unsigned char)deviceName[6])) {
            currentDevice = new Energo(deviceName);
        }
        else {
            currentDevice = new ServiceEnergy(deviceName);
        }
        break;
    case (82):
        currentDevice = new RealLab(deviceName);
        break;
    case (207):
        currentDevice = new DeviceElectro(deviceName);
        break;
    case (79):
        currentDevice = new Ouman(deviceName);
        break;
    case (206):
        currentDevice = new Owen(deviceName);
        break;
    default:
        currentDevice = nullptr;
    }
    return currentDevice;
}

class SmartHomeSystem {
private:
    std::vector<Device*> devices;
public:
    SmartHomeSystem() {}

    ~SmartHomeSystem() {
        for (auto device : devices) {
            delete device;
        }
    }

    void addDevice(Device* device) {
        devices.push_back(device);
    }

    void poll() const {
        for (auto device : devices) {
            device->poll();
        }
    }

    void readConfigFromFile(const std::string& filename) {       
        std::cout << "Name of Devices: " << "\n\n";
        std::ifstream config(filename);
        std::string deviceName;
        while (std::getline(config, deviceName)) {
            Device* device = deviceFabric(deviceName);
            if (device != nullptr) {
                addDevice(device);
            }
            else {
                std::cout << "Ошибка в названии прибора " << deviceName << std::endl;
            }
        }
    }
};