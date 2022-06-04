#ifndef EX_PLUGIN_1_H_
#define EX_PLUGIN_1_H_
#include <example_ros_plugins_pkg/plugins/ex_plugin_base.h>

namespace ex_plugins
{
  class pluginFirstClass : public ex_plugin_base::pluginBaseClass
  {
    public:
      pluginFirstClass(){}

      void initialize(int plugin_num_int)
      {
        plugin_num_int_ = plugin_num_int;
      }

      std::string pluginName()
      {
        return "The first (No. 1) example plugin";
      }

    private:
      int plugin_num_int_;
  };
};

#endif