//
// Created by Simon Mau on 4/13/24.
//

#include "wechat_common.h"
#include "pch.h"

DWORD wechatWinAddr = 0;

DWORD WechatCommon::GetWechatWinBaseAddr() {
    if (wechatWinAddr == 0) {
        HMODULE winAddress = LoadLibraryW(L"WeChatWin.dll");
        wechatWinAddr = (DWORD) winAddress;
    }
    return wechatWinAddr;
}
