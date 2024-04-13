//
// Created by Simon Mau on 4/9/24.
//

#include "global_context.h"
#include "pch.h"
#include "wechat_log.h"

GlobalContext::~GlobalContext() {

}

DWORD WINAPI DllRun(HMODULE hModule) {
    spdlog::debug("DllRun");
    WechatLog::InstallHook();
    return 0;
}

void GlobalContext::initialize(HMODULE module) {
    state = GlobalContextState::INITIALIZING;

    module_ = module;

    // log
    log.emplace();
    log->Initialize();

    HANDLE mThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)DllRun, module, NULL, 0);
    if (mThread != 0) {
        CloseHandle(mThread);
    }

    state = GlobalContextState::INITIALIZED;
}

void GlobalContext::finally() {

}
