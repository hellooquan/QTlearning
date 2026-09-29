cmake_minimum_required(VERSION 3.19)
project(signal-slot-arg LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(signal-slot-arg
    main.cpp
    mywidget.h mywidget.cpp

)

target_link_libraries(signal-slot-arg
    PRIVATE
        Qt::Core
)

install(TARGETS signal-slot-arg
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
