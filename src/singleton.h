//
// Created by Simon Mau on 4/9/24.
//

#ifndef WECHAT_LOG_CATCHER_SINGLETON_H
#define WECHAT_LOG_CATCHER_SINGLETON_H

template <typename T>
class Singleton {
protected:
    Singleton() {}
    ~Singleton() {}

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

public:
    static T& GetInstance() {
        static T instance{};
        return instance;
    }
};

#endif //WECHAT_LOG_CATCHER_SINGLETON_H
