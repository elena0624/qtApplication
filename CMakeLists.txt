cmake_minimum_required(VERSION 3.5)
project(MyQtApp)

# set path
# set(CMAKE_PREFIX_PATH "D:/Qt")
# set(CMAKE_PREFIX_PATH "D:\\Qt\\6.2.4\\wasm_32\\lib\\cmake")
set(CMAKE_PREFIX_PATH "D:\\Qt\\6.2.4\\mingw_64")

# set C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find QT package
find_package(Qt6 COMPONENTS Widgets REQUIRED)
message(STATUS "Qt6Widgets_INCLUDE_DIRS: ${Qt6Widgets_INCLUDE_DIRS}")
# include QT package
include_directories(${Qt6Widgets_INCLUDE_DIRS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# add source file
set(SOURCES
    main.cpp
    MainWindow.cpp
    MainWindow.ui
)

# add header file
set(HEADERS
    MainWindow.h
)

add_executable(MyQtApp ${SOURCES} ${HEADERS})

# link QT
target_link_libraries(MyQtApp Qt6::Widgets)

# windeployqt
# add_custom_command(TARGET MyQtApp POST_BUILD
#     # COMMAND ${CMAKE_COMMAND} -E env PATH=%PATH%;"D:\\Qt\\6.2.4\\mingw_64\\bin"
#     # COMMAND windeployqt --no-translations $<TARGET_FILE:MyQtApp>
#     COMMAND "D:\\Qt\\6.2.4\\mingw_64\\bin\\windeployqt.exe" 

# )

add_custom_command(TARGET MyQtApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E env "PATH=${PATH}" "D:\\Qt\\6.2.4\\mingw_64\\bin\\windeployqt.exe" $<TARGET_FILE:MyQtApp>
)

