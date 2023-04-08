#pragma once

#include <iostream>

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