#ifndef EX_PLUGIN_2_H_
#define EX_PLUGIN_2_H_
#include <example_ros_plugins_pkg/plugins/ex_plugin_base.h>

namespace ex_plugins
{
  class pluginSecondClass : public ex_plugin_base::pluginBaseClass
  {
    public:
      pluginSecondClass(){}

      void initialize(int plugin_num_int)
      {
        plugin_num_int_ = plugin_num_int;
      }

      std::string pluginName()
      {
        return "The second (No. 2) example plugin";
      }

    private:
      int plugin_num_int_;
  };
};

#endif