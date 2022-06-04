cmake_minimum_required(VERSION 3.0.2)
project(example_ros_plugins_pkg)

add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  pluginlib
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES example_ros_pkg_2
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(
  ex_plugins src/plugins/ex_plugin_1.cpp src/plugins/ex_plugin_2.cpp
)

add_executable(ex_plugin_loader src/ex_plugin_loader.cpp)
target_link_libraries(ex_plugin_loader ${catkin_LIBRARIES})
