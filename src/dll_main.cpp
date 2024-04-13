//
// Created by Simon Mau on 4/12/24.
//
#include "global_context.h"
#include "pch.h"



BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            spdlog::debug("DLL_PROCESS_ATTACH");
            GlobalContext::GetInstance().initialize(hModule);
            break;
        case DLL_THREAD_ATTACH:
            spdlog::debug("DLL_PROCESS_ATTACH");
        case DLL_THREAD_DETACH:
            spdlog::debug("DLL_THREAD_DETACH");
        case DLL_PROCESS_DETACH:
            spdlog::debug("DLL_PROCESS_DETACH");
            GlobalContext::GetInstance().finally();
            break;
    }
    return TRUE;
}