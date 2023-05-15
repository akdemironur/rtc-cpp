cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)

# Edit project name
project(rtc-cpp VERSION 0.1)

include(CTest)
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.2 # or a different version
)

FetchContent_MakeAvailable(Catch2)

include_directories (${CMAKE_SOURCE_DIR}/include)

add_library             ( RTCCommon lib/RTCCommon.cpp )
target_link_libraries   ( RTCCommon )
add_library             ( RTCTuple lib/RTCTuple.cpp )
target_link_libraries   ( RTCTuple RTCCommon)

add_executable( RTCTuple_test tests/RTCTuple_test.cpp )
target_link_libraries( RTCTuple_test PRIVATE Catch2::Catch2WithMain RTCTuple )
add_test( NAME RTCTuple_test COMMAND RTCTuple_test )

add_executable          ( RTC src/RTC.cpp )
target_link_libraries   ( RTC RTCTuple )