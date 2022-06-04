#ifndef EX_ROSNODE_1
#define EX_ROSNODE_1

#include <ros/ros.h>
#include <string>
#include <std_msgs/Int64.h>
#include <std_msgs/String.h>
#include <example_ros_nodes_pkg/ExSrv.h>
#include <example_ros_nodes_pkg/ExMsg.h>
#include <dynamic_reconfigure/server.h>
#include <example_ros_nodes_pkg/exDynamicReconfConfig.h>
#include "example_ros_library/ex_ros_lib_header.hpp"

class exampleClass1{
    private:
    // ROS Params
    int ex_param_int_ = 0;
    std::string ex_param_str_ = "defaultString";
    std::vector<double> ex_param_vec_ {0.0};
    double ex_dynamic_param_1_ = 0.0;
    bool ex_dynamic_param_2_ = false;

    // Variables
    std::string name_;
    int ex_var_int_;
    std::vector<float> ex_var_vec_;

    public:
    ros::NodeHandle n_;

    ros::ServiceServer ex_service_;
    ros::Subscriber ex_sub_;
    ros::Publisher ex_pub_;

    exampleClass1(ros::NodeHandle* nodehandle);

    dynamic_reconfigure::Server<example_ros_nodes_pkg::exDynamicReconfConfig> dynamic_reconf_server_;
    dynamic_reconfigure::Server<example_ros_nodes_pkg::exDynamicReconfConfig>::CallbackType dynamic_reconfigure_callback_;

    void exGetParams();
    void dynamicReconfigureCallBack(example_ros_nodes_pkg::exDynamicReconfConfig&, uint32_t );
    void exSetup();
    bool exServiceHandle(example_ros_nodes_pkg::ExSrv::Request& ,example_ros_nodes_pkg::ExSrv::Response& );
    void exSubscriberCallBack(const std_msgs::String::ConstPtr&);
    void exPublisherHandle(std::string);
};

#endif
