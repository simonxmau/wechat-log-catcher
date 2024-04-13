//
// Created by Simon Mau on 4/14/24.
//

#include "wechat_cloud_log_hook.h"
#include "wechat_common.h"
#include "utils/hook_utils.h"
#include "pch.h"
#include "wechat_offset.h"

DWORD jsApiCallAddr = WechatCommon::GetWechatWinBaseAddr() + wechat_offset::WX_APPLET_JS_API_CALL_ADDR;
DWORD jsApiCall = WechatCommon::GetWechatWinBaseAddr() + wechat_offset::WX_APPLET_JS_API_CALL;
DWORD jsApiCallNextAddr = WechatCommon::GetWechatWinBaseAddr() + wechat_offset::WX_APPLET_JS_API_CALL_NEXT_ADDR;

DWORD jsApiHookResponseAddr = WechatCommon::GetWechatWinBaseAddr() + wechat_offset::WX_APPLET_JS_API_CALL_RESPONSE_ADDR;
DWORD jsApiHookResponseCall = WechatCommon::GetWechatWinBaseAddr() + wechat_offset::WX_APPLET_JS_API_CALL_RESPONSE;
DWORD jsApiHookResponseNextAddr =
        WechatCommon::GetWechatWinBaseAddr() + wechat_offset::WX_APPLET_JS_API_CALL_RESPONSE_NEXT_ADDR;


void printRequestLog(DWORD appid, DWORD apiName, DWORD data) {
    spdlog::info("{}: appid={}, apiName={}, data={}",
                 WechatCloudLogHook::REQUEST_HOOK_NAME, (CHAR *) appid, (CHAR *) apiName, (CHAR *) data);
}

void printResponseLog(DWORD data) {
    spdlog::info("{}: data={}",
                 WechatCloudLogHook::RESPONSE_HOOK_NAME, (CHAR * ) * ((DWORD *) data));
}

void __declspec(naked) __stdcall JsApiCallRequest() {
    __asm {
            call jsApiCall
            push dword ptr ss :[ebp - 0x64]
            push dword ptr ss :[ebp - 0x6c]
            push dword ptr ss :[ebp - 0x70]
            call printRequestLog
            jmp jsApiCallNextAddr
    }
}

void __declspec(naked) __stdcall JsApiCallResponse() {
    __asm {
            call jsApiHookResponseCall
            push eax
            call printResponseLog
            add esp, 0x4
            jmp jsApiHookResponseNextAddr
    }
}

void WechatCloudLogHook::install() {
    HookUtils::HookAnyAddress(REQUEST_HOOK_NAME, jsApiCallAddr, JsApiCallRequest);
    HookUtils::HookAnyAddress(RESPONSE_HOOK_NAME, jsApiHookResponseAddr, JsApiCallResponse);
}