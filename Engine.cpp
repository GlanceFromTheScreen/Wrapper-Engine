#include "Engine.h"

void Engine::register_command(Wrapper* w, std::string const& command_name) {
    if(commands.empty()) {
        commands.insert({command_name, w});
    }
    else {
        for(auto& item: commands) {
            auto fnd = commands.find(command_name);
            if(fnd == commands.end()) {
                commands.insert({command_name, w});
                break;
            }
            else {
                throw std::runtime_error("ENGINE: TRY TO REGISTER COMMANDS WITH THE SAME NAMES");
            }
        }
    }
}

int Engine::execute(std::string const& command_name, std::map<std::string, int> const& param_map) {
    for(auto& it: commands) {
        if(it.first == command_name) {
            return correct_exe(it.second, param_map);
        }
    }
    throw std::runtime_error("ENGINE: COMMAND IS NOT FOUND");
}

int Engine::correct_exe(Wrapper* w, std::map<std::string, int> const& param_map) {
    std::vector<int> res_v;
    for(auto& item: w->params) {
        auto fnd = param_map.find(item.first);  //  find by key
        if(fnd != param_map.end()) {
            res_v.emplace_back(fnd->second);
        }
        else {
            // set default arg
            res_v.emplace_back(item.second);
        }
    }
    return w->func(res_v);
}