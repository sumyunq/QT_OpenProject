cmake_minimum_required(VERSION 3.19)
project(Servers LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools Network Svg SvgWidgets DataVisualization PrintSupport Multimedia MultimediaWidgets)

qt_standard_project_setup()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTORCC ON)   #参考: https://doc.qt.io/qt-6.8/zh/resources.html
set(CMAKE_AUTOUIC ON)   #开启自动处理 ui 文件
# 为所有 C++ 目标添加 -O2 优化
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/resources/WBLIU.rc")

# add_subdirectory(3rdparty/QXlsx)
add_subdirectory(3rdparty/QXlsx-master/QXlsx)

qt_add_executable(Servers
    WIN32 MACOSX_BUNDLE
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
    src/NetWorkModule/NetWorkAssistant.h src/NetWorkModule/NetWorkAssistant.cpp
    src/Tools/JsonHelper.h src/Tools/JsonHelper.cpp
    src/DataStruct/HighAltitudeDataSturct.h src/DataStruct/HighAltitudeDataSturct.cpp
    src/Tools/GlobalTools.cpp src/Tools/GlobalTools.h
    res.qrc
    src/Widgets/CastsWeather.cpp src/Widgets/CastsWeather.h src/Widgets/CastsWeather.ui
    src/Tools/FileHelper.h src/Tools/FileHelper.cpp
    src/ProtocolModule/GB26875ServerProtoco1.h src/ProtocolModule/GB26875ServerProtoco1.cpp
    src/NetWorkModule/LocalTCPServer.h src/NetWorkModule/LocalTCPServer.cpp
    src/NetWorkModule/LocalTCPClient.h src/NetWorkModule/LocalTCPClient.cpp
    src/Widgets/Configuration.h src/Widgets/Configuration.cpp src/Widgets/Configuration.ui
    src/RemoteFireProtectionModule/FireAlarmDevice.h src/RemoteFireProtectionModule/FireAlarmDevice.cpp src/RemoteFireProtectionModule/FireAlarmDevice.ui
    src/qcustomplot/qcustomplot.cpp src/qcustomplot/qcustomplot.h
    ${app_icon_resource_windows}
    src/Tools/ConfigManager.h src/Tools/ConfigManager.cpp
    src/Widgets/GB26875ServerMode.h src/Widgets/GB26875ServerMode.cpp src/Widgets/GB26875ServerMode.ui
    src/Widgets/GB26875ClientMode.h src/Widgets/GB26875ClientMode.cpp src/Widgets/GB26875ClientMode.ui

)

qt_add_translations(
    TARGETS Servers
    TS_FILES Servers_zh_CN.ts
)

target_include_directories(Servers PRIVATE
    src/qcustomplot          # 让编译器能找到 qcustomplot.h
)

target_link_libraries(Servers
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::Network
        Qt6::Svg
        Qt6::SvgWidgets
        Qt6::DataVisualization
        Qt6::PrintSupport
        QXlsx::QXlsx
        Qt6::Multimedia
        Qt6::MultimediaWidgets
)

include(GNUInstallDirs)

install(TARGETS Servers
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)


qt_generate_deploy_app_script(
    TARGET Servers
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
