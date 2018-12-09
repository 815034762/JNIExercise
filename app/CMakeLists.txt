# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

#设置生成的so动态库最后输出的路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

# 查找所有源码 并拼接到路径列表
#aux_source_directory(${CMAKE_HOME_DIRECTORY}/src/main/cpp SRC_LIST)
#aux_source_directory(${CMAKE_HOME_DIRECTORY}/src/main/cpp CORE_SRC_LIST)
#list(APPEND SRC_LIST ${CORE_SRC_LIST})

set(SRC_LISTS ${CMAKE_HOME_DIRECTORY}/src/main/cpp)

file(GLOB_RECURSE SRC_LIST ${SRC_LISTS}/*.cpp)

#将指定的源文件生成链接文件
add_library(JniDemo SHARED ${SRC_LIST})

#把第三库使用到的头文件包含进去
 include_directories( src/main/cpp/include/jsoncpp
                      src/main/cpp/include/curl
                      src/main/cpp)

#引用外部库文件用 IMPORTED关键字
add_library(curl STATIC IMPORTED)
#指定外部库文件的路径
set_target_properties(curl
  PROPERTIES IMPORTED_LOCATION
  ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libcurl.a)

#言归正传，那么要添加第三方的xx.a链接库呢？
#通常我们把第三方提供的h文件夹，放在cpp的include里面。
#这是规范，不是必须。而xxx.a库放在src/main/jniLibs/armeabi目录下。
#依赖第三方库
add_library(jsoncpp STATIC IMPORTED)
set_target_properties(jsoncpp
  PROPERTIES IMPORTED_LOCATION
  ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libjsoncpp.a)


#该指令的主要作用就是将指定的源文件生成链接文件，然后添加到工程中去。
#add_library( # Sets the name of the library.
#            JniDemo
# Sets the library as a shared library.
#             SHARED
# Provides a relative path to your source file(s).
#             src/main/cpp/native-lib.cpp
#             src/main/cpp/second.cpp
#             )


# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

#将库文件引入工程
target_link_libraries( # Specifies the target library.
                       JniDemo

                       jsoncpp
                       curl
                       ${log-lib} )