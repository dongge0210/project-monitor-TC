#include "LibreHardwareMonitorBridge.h"
#include <msclr/marshal_cppstd.h>
#include <utility>
#using "LibreHardwareMonitorLib.dll"

using namespace LibreHardwareMonitor::Hardware;
using namespace System;
using namespace System::Collections::Generic;
using namespace msclr::interop;

ref class SensorMonitor {
private:
    static Computer^ computer = gcnew Computer();

public:
    static void Initialize() {
        computer->IsCpuEnabled = true;
        computer->IsGpuEnabled = true;
        computer->Open();
    }

    static List<Tuple<String^, float>^>^ GetTemperatures() {
        auto results = gcnew System::Collections::Generic::List<Tuple<System::String^, float>^>();
        for each (auto hardware in computer->Hardware) {
            hardware->Update();
            for each (auto sensor in hardware->Sensors) {
                if (sensor->SensorType == SensorType::Temperature && sensor->Value.HasValue) {
                    results->Add(gcnew Tuple<String^, float>(sensor->Name, static_cast<float>(sensor->Value.Value)));
                }
            }
        }
        return results;
    }
};

void LibreHardwareMonitorBridge::Initialize() {
    SensorMonitor::Initialize();
}

std::vector<std::pair<std::string, float>> LibreHardwareMonitorBridge::GetTemperatures() {
    auto cliResults = SensorMonitor::GetTemperatures();
    std::vector<std::pair<std::string, float>> results;
    for each (Tuple<String^, float>^ entry in cliResults) {
        std::string name = marshal_as<std::string>(entry->Item1);
        results.emplace_back(name, entry->Item2);
    }
    return results;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              