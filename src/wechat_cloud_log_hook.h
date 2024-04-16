//
// Created by Simon Mau on 4/14/24.
//

#ifndef WECHAT_LOG_CATCHER_WECHAT_CLOUD_LOG_HOOK_H
#define WECHAT_LOG_CATCHER_WECHAT_CLOUD_LOG_HOOK_H


class WechatCloudLogHook {

public:

    static constexpr const char *REQUEST_HOOK_NAME = "wechat_cloud_log.request";

    static constexpr const char *RESPONSE_HOOK_NAME = "wechat_cloud_log.response";

    static void install();

};


#endif //WECHAT_LOG_CATCHER_WECHAT_CLOUD_LOG_HOOK_H
