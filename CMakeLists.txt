cmake_minimum_required(VERSION 3.10)

project(libraybox)

find_package(raylib 4.2.0 REQUIRED)
find_package(box2d REQUIRED)

SET(SOURCE
  RayRectangle.cpp
  RayCircle.cpp
  RayLine.cpp
  RayChain.cpp
  RayPolygonRegular.cpp
  RayPolygonIrregular.cpp
  RayBoxRectangle.cpp
  main.cpp
  )

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} box2d)
