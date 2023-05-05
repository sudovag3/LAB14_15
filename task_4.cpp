#include <iostream>
#include <exception>

void myTerminateHandler() {
    std::cerr << "An uncaught exception occurred. Calling a custom handler std::terminate()." << std::endl;
    std::abort();
}

int main() {
    std::set_terminate(myTerminateHandler);

    try {
        throw std::runtime_error("Example of Exception");
    } catch (const std::logic_error& e) {
        std::cout << "n uncaught exception std::logic_error" << std::endl;
    }

    return 0;
}
