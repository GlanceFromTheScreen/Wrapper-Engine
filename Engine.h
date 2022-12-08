#ifndef MAIN_CPP_ENGINE_H
#define MAIN_CPP_ENGINE_H
#include "Wrapper.h"

class Engine {
private:
    std::map<std::string, Wrapper*> commands;
    int correct_exe(Wrapper* w, std::map<std::string, int> const& param_map);

public:
    void register_command(Wrapper* w, std::string const& command_name);
    int execute(std::string const& command_name, std::map<std::string, int> const& param_map);

    Engine() = default;
};
#endif
