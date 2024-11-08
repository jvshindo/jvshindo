
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

# Find packages only once
if(NOT TARGET Crypto++)
    find_package(Crypto++ REQUIRED)
endif()

if(NOT TARGET PugiXML)
    find_package(PugiXML REQUIRED)
endif()

if(NOT TARGET Lua)
    find_package(Lua REQUIRED)
endif()

if(NOT TARGET MySQL)
    find_package(MySQL REQUIRED)
endif()

find_package(Threads)
find_package(Boost 1.53.0 COMPONENTS system filesystem REQUIRED)

# Define executable target before linking libraries
include(src/CMakeLists.txt)
add_executable(yurOTS ${yurOTS_SRC})

# Include directories and link libraries only once
if(NOT TARGET yurOTS)
    include_directories(${MYSQL_INCLUDE_DIR} ${LUA_INCLUDE_DIR} ${Boost_INCLUDE_DIRS} ${PUGIXML_INCLUDE_DIR})
    target_link_libraries(yurOTS ${MYSQL_CLIENT_LIBS} ${LUA_LIBRARIES} ${Boost_LIBRARIES} ${Boost_FILESYSTEM_LIBRARIES} ${PUGIXML_LIBRARIES} ${CRYPTOPP_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
endif()

# Set properties for cotire
set_target_properties(yurOTS PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/otpch.h")
set_target_properties(yurOTS PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)

cotire(yurOTS)
