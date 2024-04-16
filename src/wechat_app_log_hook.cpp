//
// Created by Simon Mau on 4/13/24.
//

#include "wechat_app_log_hook.h"
#include "wechat_common.h"
#include "utils/hook_utils.h"
#include "pch.h"

DWORD dwHookAppLogAddr = WechatCommon::GetWechatWinBaseAddr() + 0x79192DA9 - 0x78200000; // 0xF92DA9
DWORD dwAppLogCallAddr = WechatCommon::GetWechatWinBaseAddr() + 0x7A313080 - 0x78200000;
DWORD dwHookAppLogJumpAddr = dwHookAppLogAddr + 5;

void printLog(DWORD a1, DWORD a2) {
    DWORD *ptr = (DWORD *) a1;
    DWORD type = *ptr;
    DWORD className = *(ptr + 1);
    DWORD filename = *(ptr + 2);
    DWORD functionName = *(ptr + 3);
    DWORD size = *(ptr + 4);

    spdlog::info("{}: type={}, className={}, filename={}, functionName={}, size={}, msg={}",
                 WechatAppLogHook::HOOK_NAME, type, (CHAR *) className, (CHAR *) filename,
                 (CHAR *) functionName, size, (CHAR *) a2);
}

void __declspec(naked) __stdcall _wechatAppLogHook() {
    __asm {
        // 1. call original code
        call dwAppLogCallAddr

        // 2. call my code
        call printLog

        // 3. back to original code
        jmp dwHookAppLogJumpAddr
    }
}

void WechatAppLogHook::install() {
    HookUtils::HookAnyAddress(HOOK_NAME, dwHookAppLogAddr, _wechatAppLogHook);
}
