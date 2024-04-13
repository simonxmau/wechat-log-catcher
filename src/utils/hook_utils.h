//
// Created by Simon Mau on 4/13/24.
//

#ifndef WECHAT_CLOUD_CATCHER_HOOK_UTILS_H
#define WECHAT_CLOUD_CATCHER_HOOK_UTILS_H

#include "../pch.h"

class HookUtils {

public:

    /**
    * Hook 任意地址
    *
    * @param name  hook 名称
    * @param dwHookAddress  需要 Hook 的地址
    * @param jmpAddress  跳转地址
    */
    static void HookAnyAddress(std::string name, DWORD dwHookAddress, LPVOID jmpAddress);

};


#endif //WECHAT_CLOUD_CATCHER_HOOK_UTILS_H
