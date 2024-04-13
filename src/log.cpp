//
// Created by Simon Mau on 4/10/24.
//

#include "log.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
// #include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>



Log::Log() {}

Log::~Log() {}

void Log::Initialize() {
    // console
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    // daly_file
    auto daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("d:/logs/wechat-cloud-catcher/daily.log", 0, 0); // logs/daily_YYYY-MM-DD.log

    auto logger = std::make_shared<spdlog::logger>("default", spdlog::sinks_init_list{console_sink, daily_sink});
    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::debug);

    // console_sink->set_level(spdlog::level::debug);
    // console_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");
    // auto file_sink = spdlog::rotating_logger_mt("my_logger", "logs/app.log", 1024 * 1024 * 10, 3);
    // auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/app.log", true);
    // file_sink->set_level(spdlog::level::debug);
    // file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");
    // daily_sink->set_level(spdlog::level::debug);
    // spdlog::set_pattern("%Y-%m-%d %H:%M:%S [%l] [%t] - <%s>|<%#>|<%!>,%v");
    // spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%l] [%s:%#] %v");
    // spdlog::set_pattern("[%H:%M:%S %z] [%^%L%$] [thread %t] %v");

    // auto max_size = 1048576 * 100;
    // auto max_files = 3;
    // auto logger = spdlog::rotating_logger_mt("app", "logs/app.log", max_size, max_files);
    // spdlog::set_default_logger(logger);
    // spdlog::set_level(spdlog::level::debug);
}