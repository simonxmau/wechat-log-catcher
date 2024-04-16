//
// Created by Simon Mau on 4/9/24.
//

#ifndef WECHAT_LOG_CATCHER_GLOBAL_CONTEXT_H
#define WECHAT_LOG_CATCHER_GLOBAL_CONTEXT_H

#include "singleton.h"
#include "log.h"
#include "pch.h"

enum class GlobalContextState { NOT_INITIALIZED, INITIALIZING, INITIALIZED };

class GlobalContext: public Singleton<GlobalContext>  {

    friend class Singleton<GlobalContext>;

    ~GlobalContext();

public:

    std::optional<Log> log;

    GlobalContextState state = GlobalContextState::NOT_INITIALIZED;

    void initialize(HMODULE module);

    void finally();

private:

    HMODULE module_;

};


#endif //WECHAT_LOG_CATCHER_GLOBAL_CONTEXT_H
