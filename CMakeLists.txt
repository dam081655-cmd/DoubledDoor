cmake_minimum_required(VERSION 3.22)

project(DoubleDoorSync LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(MOD_ID "double_door_sync" CACHE STRING "LeviLauncher mod package directory name")
set(MOD_NAME "Double Door Sync" CACHE STRING "LeviLauncher mod display name")
set(MOD_AUTHOR "dam081655-cmd" CACHE STRING "LeviLauncher mod author")
set(MOD_VERSION "0.1.0" CACHE STRING "LeviLauncher mod version")
set(MOD_LIBRARY_NAME "double_door_sync" CACHE STRING "Native library name without lib prefix or .so suffix")
set(MOD_MINECRAFT_VERSIONS "[\"1.26.*\"]" CACHE STRING "Raw JSON array for manifest minecraft_versions")
set(MOD_ICON "" CACHE STRING "Optional package-relative icon path, such as icon.png")
