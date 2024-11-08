
cmake_minimum_required(VERSION 3.5)

# Define CMake policy to suppress Boost policy warning
cmake_policy(SET CMP0167 NEW)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(yurOTS)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(cotire)

add_compile_options(-pipe -fvisibility=hidden)

if (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-fno-strict-aliasing)
endif()

include(FindCXX11)

# Find packages.
find_package(Crypto++ REQUIRED)
find_package(PugiXML REQUIRED)
find_package(Lua REQUIRED)  # Use only Lua, no LuaJIT
find_package(MySQL REQUIRED)
find_package(Threads)

find_package(Boost 1.53.0 COMPONENTS system filesystem REQUIRED)

# Define the executable before linking libraries
include(src/CMakeLists.txt)
add_executable(yurOTS ${yurOTS_SRC})

# Include necessary directories and link libraries once
include_directories(${MYSQL_INCLUDE_DIR} ${LUA_INCLUDE_DIR} ${Boost_INCLUDE_DIRS} ${PUGIXML_INCLUDE_DIR})
target_link_libraries(yurOTS ${MYSQL_CLIENT_LIBS} ${LUA_LIBRARIES} ${Boost_LIBRARIES} ${Boost_FILESYSTEM_LIBRARIES} ${PUGIXML_LIBRARIES} ${CRYPTOPP_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})

# Debugging messages for MySQL setup confirmation
message(STATUS "MySQL Include dir: ${MYSQL_INCLUDE_DIR}")
message(STATUS "MySQL client libraries: ${MYSQL_CLIENT_LIBS}")

set_target_properties(yurOTS PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/otpch.h")
set_target_properties(yurOTS PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)

cotire(yurOTS)
