//
// Created by Simon Mau on 4/13/24.
//

#include "hook_utils.h"
#include "../pch.h"

void HookUtils::HookAnyAddress(std::string name, DWORD dwHookAddress, LPVOID jmpAddress) {
    spdlog::info("HookAnyAddress: name={}, hookAddress={}, jmpAddress={}", name, dwHookAddress, jmpAddress);

    //组装跳转数据

    BYTE jmpCode[5] = {0};
    jmpCode[0] = 0xE9;

    //计算偏移

    *(DWORD * ) & jmpCode[1] = (DWORD) jmpAddress - dwHookAddress - 5;

    //保存以前属性用于还原

    DWORD oldProperty = 0;

    // 因为要往代码段写入数据，又因为代码段是不可写的，所以需要修改属性

    VirtualProtect((LPVOID) dwHookAddress, 5, PAGE_EXECUTE_READWRITE, &oldProperty);

    //写入自己的代码

    memcpy((void *) dwHookAddress, jmpCode, 5);

    // 执行完了操作之后需要进行还原

    VirtualProtect((LPVOID) dwHookAddress, 5, oldProperty, &oldProperty);
}