//
// Created by Simon Mau on 4/9/24.
//

#include "global_context.h"
#include "pch.h"
#include "wechat_app_log_hook.h"
#include "wechat_cloud_log_hook.h"

GlobalContext::~GlobalContext() {

}

DWORD WINAPI DllRun(HMODULE hModule) {
    spdlog::debug("DllRun");
    WechatAppLogHook::install();
    WechatCloudLogHook::install();
    return 0;
}

void GlobalContext::initialize(HMODULE module) {
    state = GlobalContextState::INITIALIZING;

    module_ = module;

    // log
    log.emplace();
    log->Initialize();

    // env
    const char* envPath = getenv("WECHAT_LOG_CATCHER_OUTPUT_PATH");
    if (envPath == nullptr) {
        envPath = ".";
    }
    std::string logFile = fmt::format("{}/daily.log", envPath);
    spdlog::info("WECHAT_LOG_CATCHER_OUTPUT_PATH: {}", logFile);

    HANDLE mThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)DllRun, module, NULL, 0);
    if (mThread != 0) {
        CloseHandle(mThread);
    }

    state = GlobalContextState::INITIALIZED;
}

void GlobalContext::finally() {

}
