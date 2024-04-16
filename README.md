# wechat-log-catcher

## 项目介绍

[wechat-log-catcher](https://github.com/simonxmau/wechat-cloud-catcher) 是一款使用 `C++` 语言编写的 `Windows` 微信日志收集器，用于收集微信的运行日志、小程序云函数请求和响应日志，方便开发者查看微信的运行情况。

**支持日志类型：**

1. 微信运行日志: `wechat_app_log`
2. 微信小程序云函数调用日志: `wechat_cloud_log`

**支持版本：**

1. Windows-x86_3.9.7.28

## 工作原理

1. 对打印日志相关函数进行 `Hook`，并输出到配置的目录文件。

## 使用

1. 下载 `wlc.dll`
2. 使用注入工具，注入到 `wechat.exe` 进程中，如果出现自动卸载，那么请使用 `管理员` 权限运行微信。
3. 配置日志保存目录

通过环境变量进行配置（如果为空，那么会保存到 `wechat.exe` 目录下）
- `WECHAT_LOG_CATCHER_OUTPUT_PATH`: 为目录，用于指定日志输出路径，日志将会按天（`daily_2024-04-16.log`）输出到该目录。

## 日志类型

#### type: wechat_app_log

应用日志

```
[2024-04-16 15:35:33.785] [default] [info] wechat_app_log: type=2, className=MMPC_finder_entry, filename=D:\Tools\agent\workspace\MicroMsgWindowsV397\MicroMsgWin\02_manager\FinderFeedMgr.
cpp, functionName=FinderFeedMgr::IsPluginEnabled, size=132, msg=finder entry xlab switch : 0

[2024-04-16 15:35:33.785] [default] [info] wechat_app_log: type=2, className=MMPC_finder_entry, filename=D:\Tools\agent\workspace\MicroMsgWindowsV397\MicroMsgWin\02_manager\FinderFeedMgr.
cpp, functionName=FinderFeedMgr::IsPluginEnabled, size=139, msg=finder timeline entry : 1
```

##### type: wechat_cloud_log

云函数日志

```
[2024-04-16 15:37:12.543] [default] [info] wechat_cloud_log.request: appid=wx21c7506e98a2fe75, apiName=login, data={"login_type":1,"version_type":1}

[2024-04-16 15:01:59.300] [default] [info] wechat_cloud_log.response: data={"app_id":"wx938b41d0d7e8def0","code":"0f31OD1w34TgA23tK63w3nCkMo21OD1a","err_msg":"ok","err_no":0,"isSuccess":t
rue,"task_id":1176}
```

## 重新编译

克隆项目后，需要对子模块进行初始化：

```shell
git submodule init
git submodule update
```