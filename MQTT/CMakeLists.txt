cmake_minimum_required(VERSION 3.19)
project(111 LANGUAGES CXX)
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Network)
qt_standard_project_setup()
#当前 Qt Kit 未安装 QtMqtt，因此把最终项目里的 QMQTT 源码放进本工程，方便独立构建。
set(QMQTT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/qmqtt")
if(NOT EXISTS "${QMQTT_SOURCE_DIR}/CMakeLists.txt")
message(FATAL_ERROR "未找到 QMQTT 源码：${QMQTT_SOURCE_DIR}")
endif()
#静态链接 QMQTT，运行 Day06 时不需要额外复制 qmqtt.dll
set(qmqtt_SHARED OFF CACHE BOOL "Build QMQTT as a static library" FORCE)
add_subdirectory("${QMQTT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/qmqtt-build")
qt_add_executable(111
WIN32 MACOSX_BUNDLE
main.cpp
mainwindow.cpp
mainwindow.h
mainwindow.ui
)
target_link_libraries(111
PRIVATE
Qt::Core
Qt::Widgets
Qt6::Network
qmqtt
)
target_compile_definitions(111 PRIVATE MQTT_PROJECT_INCLUDE_SRC)
set_target_properties(111 PROPERTIES WIN32_EXECUTABLE TRUE)