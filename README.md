#项目引导（QDaoDaoLiang）

>  平时由于项目需要，需要用到各种非原生Qt有的特性，这些特性有时需要重复劳动，有的可能毫无头绪，所以萌生根据实际需要进行>抽象封装从而实现一套实用的组件库。QDaoDaoLiang的由来为本人网名，但愿组件库在发展的过程中会逐渐健壮，逐渐实用，本库遵循MI>T开源协议，Enjoy it~
    
******

##开发环境构建说明

1. 开发是在Windows下开发的项目
2. 项目使用的DevKit为：Qt4.8.4(MSVC)+ Microsoft Visual C++ Compiler 9.0 + QCreator 2.7.0
3. 文档使用MarkDown语言编写,编辑器使用MdCharm(感谢原作者提供方便的工具)

******
##项目结构说明
![项目结构说明](./doc/项目结构说明/项目结构说明.png)
******

##项目进度
1. 完成可移动的弹出框基础文件，可用来实现类似QQ新闻的右下角弹出和消失的效果；
2. 完成自定义QLabel,在文字前方4个像素的位置画出红色星号，可用来实现表单的必填项的提示；
3. 完成程序单例的集成；
4. 完成程序崩溃的跟踪两套方案(minidump和基于google的breakpoint的crashdump)

******

##项目开发计划
1. 开发适用于程序注册机制的验证库和注册机
2. 集成ECharts实现JS图表与C++交互的数据展示库
3. 实现对常规样式的控件皮肤封装
4. 嵌入Python进行数据交互，实现Python和C++库转换调用的中间库

******

![enjoy](./imagesBed/icon_thumbs-o-up.png)

******
