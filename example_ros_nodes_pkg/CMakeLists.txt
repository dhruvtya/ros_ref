cmake_minimum_required(VERSION 3.0.2)
project(example_ros_nodes_pkg)

add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  dynamic_reconfigure
  example_ros_library
)

add_message_files(
  DIRECTORY msg
  FILES
  ExMsg.msg
)


add_service_files(
  DIRECTORY srv
  FILES
  ExSrv.srv
)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )


generate_messages(
  DEPENDENCIES
  std_msgs
)


generate_dynamic_reconfigure_options(
  cfg/exDynamicReconf.cfg
)


catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES example_ros_pkg_1
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

#############
## Install ##
#############


# catkin_install_python(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )


add_executable(ex_rosnode_cpp_node src/ex_rosnode_cpp_node.cpp src/ex_rosnode_cpp.cpp)
target_link_libraries(ex_rosnode_cpp_node ${catkin_LIBRARIES})
add_dependencies(ex_rosnode_cpp_node example_ros_nodes_pkg_generate_messages_cpp example_ros_nodes_pkg_gencfg)

