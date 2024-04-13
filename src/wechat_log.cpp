//
// Created by Simon Mau on 4/13/24.
//

#include "wechat_log.h"
#include "wechat_common.h"
#include "utils/hook_utils.h"
#include "pch.h"

DWORD dwHookLogAddr = WechatCommon::GetWechatWinBaseAddr() + 0x79192DA9 - 0x78200000;
DWORD dwLogCallAddr = WechatCommon::GetWechatWinBaseAddr() + 0x7A313080 - 0x78200000;
DWORD dwHookLogJumpAddr = dwHookLogAddr + 5;

void PrintLog(DWORD a1, DWORD a2) {
    DWORD *ptr = (DWORD *) a1;
    DWORD type = *ptr;
    DWORD className = *(ptr + 1);
    DWORD filename = *(ptr + 2);
    DWORD functionName = *(ptr + 3);
    DWORD size = *(ptr + 4);

    spdlog::info("WeChatLog: type={}, className={}, filename={}, functionName={}, size={}, msg={}", type, (CHAR*)className,
                 (CHAR*)filename, (CHAR*)functionName, size, (CHAR*)a2);
}
// 1. call original code
// 2. call my code
// 3. back to original code

void __declspec(naked) __stdcall WeChatLogHook() {
    __asm {
        call dwLogCallAddr

        call PrintLog

        jmp dwHookLogJumpAddr
    }
}

void WechatLog::InstallHook() {
    HookUtils::HookAnyAddress("wechat_log", dwHookLogAddr, WeChatLogHook);
}
