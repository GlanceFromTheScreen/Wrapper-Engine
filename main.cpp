#include "Wrapper.h"
#include "Engine.h"

class Subject {
public:
    Subject() = default;

    int f3(int x, int y) {
        std::cout << "Subject " << x << " " << y << std::endl;
        return 0;
    }
};

class OneMoreSubject {
public:
    OneMoreSubject() = default;

    int f3(int x, int y, int z) {
        std::cout << "OneMoreSubject " << x << " " << y << " " << z << std::endl;
        return 0;
    }
};

int main() {

    Subject subj;
    Wrapper wrapper(&subj,&Subject::f3, {{"arg1",1}, {"arg2", 2}});
    Engine engine;
    engine.register_command(&wrapper, "command1");
    engine.execute("command1", {{"arg1",6}, {"arg2", 7}});

    OneMoreSubject subj2;
    Wrapper wrapper2(&subj2, &OneMoreSubject::f3, {{"_1",0}, {"_2", 0}, {"_3", 0}});
    Engine engine2;
    engine2.register_command(&wrapper2, "cmd");
    engine2.register_command(&wrapper2, "cmd2");
    engine2.execute("cmd2", {{"_1",1}, {"_2", 2}});

    return 0;
}
