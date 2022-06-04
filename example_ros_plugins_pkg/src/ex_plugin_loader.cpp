#include <pluginlib/class_loader.h>
#include <example_ros_plugins_pkg/plugins/ex_plugin_base.h>

int main(int argc, char** argv)
{
  pluginlib::ClassLoader<ex_plugin_base::pluginBaseClass> ex_plugin_loader("example_ros_plugins_pkg", "ex_plugin_base::pluginBaseClass");

  try
  {
    boost::shared_ptr<ex_plugin_base::pluginBaseClass> first_plugin = ex_plugin_loader.createInstance("ex_plugins::pluginFirstClass");
    first_plugin->initialize(1);

    boost::shared_ptr<ex_plugin_base::pluginBaseClass> second_plugin = ex_plugin_loader.createInstance("ex_plugins::pluginSecondClass");
    second_plugin->initialize(2);

    ROS_INFO("First plugin called: %s", first_plugin->pluginName().c_str());
    ROS_INFO("Second plugin called: %s", second_plugin->pluginName().c_str());
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load for some reason. Error: %s", ex.what());
  }

  return 0;
}