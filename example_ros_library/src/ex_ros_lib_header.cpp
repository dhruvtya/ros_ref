#include "example_ros_library/ex_ros_lib_header.hpp"

double exHeaderFunction(std::vector<double> input_numbers){
    ROS_INFO("Example external header function called");
    double return_val = 0;
    for(auto number:input_numbers){
        return_val += number;
    }
    return return_val;
}