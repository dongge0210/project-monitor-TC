﻿#include "NetworkAdapter.h"
#include "Logger.h"
#include <comutil.h>
#include <sstream>

NetworkAdapter::NetworkAdapter(WmiManager& manager) : wmiManager(manager) {
    if (wmiManager.IsInitialized()) {
        QueryAdapterInfo();
    }
    else {
        Logger::Error("WMI未初始化，无法获取网络信息");
    }
}

void NetworkAdapter::QueryAdapterInfo() {
    IEnumWbemClassObject* pEnumerator = nullptr;
    HRESULT hres = wmiManager.GetWmiService()->ExecQuery(
        bstr_t("WQL"),
        bstr_t("SELECT * FROM Win32_NetworkAdapter WHERE NetConnectionStatus = 2"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        nullptr,
        &pEnumerator
    );

    if (FAILED(hres)) {
        Logger::Error("网络适配器查询失败: HRESULT=0x" + std::to_string(hres));
        return;
    }

    ULONG uReturn = 0;
    IWbemClassObject* pclsObj = nullptr;
    while (pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn) == S_OK) {
        AdapterInfo info;

        // 获取适配器名称
        VARIANT vtName;
        VariantInit(&vtName);
        if (SUCCEEDED(pclsObj->Get(L"Description", 0, &vtName, 0, 0)) && vtName.vt == VT_BSTR) {
            info.name = vtName.bstrVal;
        }
        VariantClear(&vtName);

        // 过滤虚拟适配器
        if (info.name.find(L"Hyper-V") != std::wstring::npos ||
            info.name.find(L"Virtual") != std::wstring::npos) {
            pclsObj->Release();
            continue;
        }

        // 获取MAC地址
        VARIANT vtMac;
        VariantInit(&vtMac);
        if (SUCCEEDED(pclsObj->Get(L"MACAddress", 0, &vtMac, 0, 0)) && vtMac.vt == VT_BSTR) {
            info.mac = vtMac.bstrVal;
        }
        VariantClear(&vtMac);

        // 获取IP地址
        VARIANT vtIP;
        VariantInit(&vtIP);
        if (SUCCEEDED(pclsObj->Get(L"IPAddress", 0, &vtIP, 0, 0)) && vtIP.vt == (VT_ARRAY | VT_BSTR)) {
            SAFEARRAY* psa = vtIP.parray;
            BSTR* pbstr;
            SafeArrayAccessData(psa, (void**)&pbstr);
            info.ip = *pbstr;  // 取第一个IP地址
            SafeArrayUnaccessData(psa);
        }
        VariantClear(&vtIP);

        adapters.push_back(info);
        pclsObj->Release();
    }

    pEnumerator->Release();
}

const std::vector<NetworkAdapter::AdapterInfo>& NetworkAdapter::GetAdapters() const {
    return adapters;
}