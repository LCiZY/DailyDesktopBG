# DailyDesktopBG

每日桌面背景

## 功能

每天第一次开机自动更换桌面背景图(指定文件夹内的背景图，通过启动参数指定)

## 用法

```shell
DailyDesktopBG.exe 背景图片文件夹路径
```

## 用法(开机自启)

1. 编写vbs脚本

```vbscript
Set ws = CreateObject("Wscript.Shell")
ws.run "cmd /c DailyDesktopBG.exe C:\Users\LC\Pictures\bg", vbhide
```

2. 将exe与vbs置于统一目录下
3. 创建vbs的快捷方式，丢到`C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp`目录里

