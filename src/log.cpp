//
// Created by Simon Mau on 4/10/24.
//

#include "log.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

Log::Log() {}

Log::~Log() {}

void Log::Initialize() {

    const char* envPath = getenv("WECHAT_LOG_CATCHER_OUTPUT_PATH");
    if (envPath == nullptr) {
        envPath = ".";
    }
    std::string logFile = fmt::format("{}/daily.log", envPath);

    // console
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    // daly_file
    auto daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(logFile, 0, 0); // logs/daily_YYYY-MM-DD.log

    auto logger = std::make_shared<spdlog::logger>("default", spdlog::sinks_init_list{console_sink, daily_sink});
    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::debug);
}