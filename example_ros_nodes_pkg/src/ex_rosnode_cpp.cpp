#include <example_ros_nodes_pkg/ex_rosnode_cpp.hpp>

// Constructor
exampleClass1::exampleClass1(ros::NodeHandle* nodehandle):n_(*nodehandle){
    name_ = "ex_rosnode_cpp";

    exGetParams();

    dynamic_reconfigure_callback_ = boost::bind(&exampleClass1::dynamicReconfigureCallBack, this, _1, _2);
    dynamic_reconf_server_.setCallback(dynamic_reconfigure_callback_);

    exSetup();
}

void exampleClass1::exGetParams(){
    // Example of loading ROS Params
    if(n_.hasParam("/ex_integer_parameter")){
        n_.getParam("/ex_integer_parameter",ex_param_int_);
    }
    else{
        ROS_WARN("[%s] No param 'Integer' found, using default", name_.c_str());
    }
    
    n_.getParam("/ex_string_parameter",ex_param_str_);
    n_.getParam("/ex_vector_parameter",ex_param_vec_);
    n_.getParam("/ex_dyn_parameter_1",ex_dynamic_param_1_);
    n_.getParam("/ex_dyn_parameter_2",ex_dynamic_param_2_);
}

void exampleClass1::exSetup(){
    ex_service_ = n_.advertiseService("/example_service", &exampleClass1::exServiceHandle, this);
    ex_sub_ = n_.subscribe("/example_topic_for_sub", 10, &exampleClass1::exSubscriberCallBack, this);
    ex_pub_ = n_.advertise<example_ros_nodes_pkg::ExMsg>("/example_topic_for_pub", 1);
}

bool exampleClass1::exServiceHandle(example_ros_nodes_pkg::ExSrv::Request &req ,example_ros_nodes_pkg::ExSrv::Response &res ){
    // Example of a Service Server
    ROS_INFO("[%s] Service - Received input number '%.2f'", name_.c_str(), req.input_num);
    std::vector<double> for_external_header {req.input_num * 2, double(ex_param_int_), ex_param_vec_.back(), ex_dynamic_param_1_};
    res.output_num = exHeaderFunction(for_external_header);
    return true;
}

void exampleClass1::exSubscriberCallBack(const std_msgs::String::ConstPtr& msg){
    // Example of a Subscriber
    ROS_INFO("[%s] Subscriber - Got string '%s', parameter string '%s'", name_.c_str(), msg->data.c_str(), ex_param_str_.c_str());

    // Will call publisher everytime subscriber receives message
    exPublisherHandle(msg->data.c_str());
}

void exampleClass1::exPublisherHandle(std::string in_str){
    // Example of a Publisher
    ROS_INFO("[%s] Publisher - Data about string %s", name_.c_str(), in_str.c_str());

    example_ros_nodes_pkg::ExMsg message_to_publish;
    message_to_publish.input_string = in_str;
    message_to_publish.string_len = in_str.size();
    message_to_publish.first_letter = in_str.front();
    message_to_publish.last_letter = in_str.back();

    ex_pub_.publish(message_to_publish);
}

void exampleClass1::dynamicReconfigureCallBack(example_ros_nodes_pkg::exDynamicReconfConfig &config, uint32_t level){
    ROS_INFO("[%s] Dynamic reconfigure : %f, %s",name_.c_str(), config.ex_dyn_parameter_1 ,config.ex_dyn_parameter_2?"True":"False");

    ex_dynamic_param_1_ = config.ex_dyn_parameter_1;
    ex_dynamic_param_2_ = config.ex_dyn_parameter_2;
}