#include <example_ros_nodes_pkg/ex_rosnode_cpp.hpp>

int main(int argc, char * argv[]){
    ros::init(argc, argv, "ex_rosnode_cpp_node");

    ros::NodeHandle n;

    exampleClass1 example_class_1_object(&n);

    ros::spin();

    return 0;
}