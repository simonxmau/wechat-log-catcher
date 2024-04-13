//
// Created by Simon Mau on 4/13/24.
//

#ifndef WECHAT_CLOUD_CATCHER_WECHAT_APP_LOG_HOOK__H
#define WECHAT_CLOUD_CATCHER_WECHAT_APP_LOG_HOOK__H

#include "pch.h"

class WechatAppLogHook {

public:

    static constexpr const char *HOOK_NAME = "wechat_app_log";

    static void install();

};


#endif //WECHAT_CLOUD_CATCHER_WECHAT_APP_LOG_HOOK__H
