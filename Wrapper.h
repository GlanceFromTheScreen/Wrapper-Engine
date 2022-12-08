#ifndef MAIN_CPP_WRAPPER_H
#define MAIN_CPP_WRAPPER_H
#include <iostream>
#include <functional>
#include <vector>
#include <map>
#include <exception>

class Wrapper
{
friend class Engine;
private:
    std::map<std::string, int> params;
    template<class T, class ...Args, size_t ...I>
    int call_fun(T* instance, int(T::*f)(Args...), std::vector<int> const& par, std::index_sequence<I...>) {
        return (instance->*f)(par[I]...);
    }

public:
    std::function<int(std::vector<int>)> func;
    template<class T, class ...Args>
    Wrapper(T* instance, int(T::*f)(Args...), std::vector<std::pair<std::string, int>> const& param_map) {
        for(auto& item: param_map) {
            auto fnd = params.find(item.first);
            if(fnd == params.end()) {
                params.insert(item);
            }
            else {
                throw std::runtime_error("WRAPPER: SAME KEYS ARE GIVEN");
            }
        }
        func = [instance, f, this] (std::vector<int> const& par) -> int {
            return call_fun(instance, f, par, std::make_index_sequence<sizeof...(Args)>{});
        };
    }

    Wrapper() = delete;
};

#endif
