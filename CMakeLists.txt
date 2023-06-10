cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
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

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra -ffast-math")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")

include_directories (${CMAKE_SOURCE_DIR}/include)

add_library             ( RTCCommon lib/RTCCommon.cpp )
target_link_libraries   ( RTCCommon )
add_library             ( RTCTuple lib/RTCTuple.cpp )
target_link_libraries   ( RTCTuple RTCCommon )
add_library             ( RTCMatrix lib/RTCMatrix.cpp )
target_link_libraries   ( RTCMatrix RTCCommon RTCTuple)
add_library             ( RTCTick lib/RTCTick.cpp )
target_link_libraries   ( RTCTick RTCTuple )
add_library             ( RTCColor lib/RTCColor.cpp )
target_link_libraries   ( RTCColor RTCTuple )
add_library             ( RTCCanvas lib/RTCCanvas.cpp )
target_link_libraries   ( RTCCanvas RTCColor )
add_library             ( RTCTransformations lib/RTCTransformations.cpp )
target_link_libraries   ( RTCTransformations RTCMatrix )
add_library             ( RTCRay lib/RTCRay.cpp )
target_link_libraries   ( RTCRay RTCTuple RTCMatrix RTCTransformations )
add_library             ( RTCShape lib/RTCShape.cpp )
target_link_libraries   ( RTCShape RTCTuple RTCRay RTCMaterial )
add_library             ( RTCLight lib/RTCLight.cpp )
target_link_libraries   ( RTCLight RTCTuple RTCColor )
add_library             ( RTCMaterial lib/RTCMaterial.cpp )
target_link_libraries   ( RTCMaterial RTCColor )
add_library             ( RTCWorld lib/RTCWorld.cpp )
target_link_libraries   ( RTCWorld )

add_executable( RTCTuple_test tests/RTCTuple_test.cpp )
target_link_libraries( RTCTuple_test PRIVATE Catch2::Catch2WithMain RTCTuple )
add_test( NAME RTCTuple_test COMMAND RTCTuple_test )

add_executable( RTCLight_test tests/RTCLight_test.cpp )
target_link_libraries( RTCLight_test PRIVATE Catch2::Catch2WithMain RTCLight RTCMaterial )
add_test( NAME RTCLight_test COMMAND RTCLight_test )

add_executable( RTCMaterial_test tests/RTCMaterial_test.cpp )
target_link_libraries( RTCMaterial_test PRIVATE Catch2::Catch2WithMain RTCMaterial RTCLight )
add_test( NAME RTCMaterial_test COMMAND RTCMaterial_test )

add_executable( RTCTransformations_test tests/RTCTransformations_test.cpp )
target_link_libraries( RTCTransformations_test PRIVATE Catch2::Catch2WithMain RTCTransformations )
add_test( NAME RTCTransformations_test COMMAND RTCTransformations_test )

add_executable( RTCColor_test tests/RTCColor_test.cpp )
target_link_libraries( RTCColor_test PRIVATE Catch2::Catch2WithMain RTCColor)
add_test( NAME RTCColor_test COMMAND RTCColor_test )

add_executable( RTCRay_test tests/RTCRay_test.cpp )
target_link_libraries( RTCRay_test PRIVATE Catch2::Catch2WithMain RTCRay RTCShape )
add_test( NAME RTCRay_test COMMAND RTCRay_test )

add_executable( RTCSphere_test tests/RTCSphere_test.cpp )
target_link_libraries( RTCSphere_test PRIVATE Catch2::Catch2WithMain RTCRay RTCShape )
add_test( NAME RTCSphere_test COMMAND RTCSphere_test )

add_executable( RTCCanvas_test tests/RTCCanvas_test.cpp )
target_link_libraries( RTCCanvas_test PRIVATE Catch2::Catch2WithMain RTCCanvas RTCColor)
add_test( NAME RTCCanvas_test COMMAND RTCCanvas_test )

add_executable( RTCMatrix_test tests/RTCMatrix_test.cpp )
target_link_libraries( RTCMatrix_test PRIVATE Catch2::Catch2WithMain RTCMatrix )
add_test( NAME RTCMatrix_test COMMAND RTCMatrix_test )

add_executable( RTCWorld_test tests/RTCWorld_test.cpp )
target_link_libraries( RTCWorld_test PRIVATE Catch2::Catch2WithMain RTCWorld )
add_test( NAME RTCWorld_test COMMAND RTCWorld_test )

add_executable          ( RTC src/RTC.cpp )
target_link_libraries   ( RTC  RTCColor RTCCanvas RTCTick RTCTransformations RTCRay RTCShape RTCLight RTCMaterial )
