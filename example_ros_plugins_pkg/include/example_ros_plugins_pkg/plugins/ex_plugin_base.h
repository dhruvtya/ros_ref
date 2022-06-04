#ifndef EX_PLUGIN_BASE_H_
#define EX_PLUGIN_BASE_H_

namespace ex_plugin_base
{
  class pluginBaseClass
  {
    public:
      virtual void initialize(int plugin_num_int) = 0;
      virtual std::string pluginName() = 0;

      virtual ~pluginBaseClass(){}

    protected:
      pluginBaseClass(){}
  };
};
#endif