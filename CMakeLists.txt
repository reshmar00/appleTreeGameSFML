cmake_minimum_required(VERSION 3.15)
project(testappletreeGame)
add_executable(testappletreeGame src/appletreeGame.cpp src/thrownApple1.cpp src/basket.cpp src/world.cpp src/fallingApple.cpp src/thrownApple1.hpp src/basket.hpp src/world.hpp src/fallingApple.hpp src/squirrel.hpp src/squirrel.cpp)

#add apple-new.png
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/apple-new.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) 

#add squirrel-new.png
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/squirrel-new.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) 

#add basket-new.png
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/basket-new.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) 

#add background-new.png
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/background-new.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) 


find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
target_link_libraries(testappletreeGame PRIVATE sfml-graphics sfml-system)
target_compile_options(testappletreeGame PUBLIC -std=c++17)