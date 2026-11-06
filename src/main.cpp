#include "environment.h"
#include "exception.h"
#include "file_reader.h"
#include <print>
#define TEST_FILE "test.bms"

#include <iostream>

int main(int argc, char *argv[]) {
    try {
        using namespace NakuyaMaster;
        Environment environment{get_binary_path().parent_path()};
        FileReader file{};

        file.open(TEST_FILE);

        while (!file.is_end())
            std::cout << file.read_line() << std::endl;

    } catch (const NakuyaMaster::Exception &err) {
        std::println(std::cerr, "System Exception: {}", err.what());
    } catch (const std::exception &err) {
        std::println(std::cerr, "Standard Exception: {}", err.what());
    } catch (...) {
        std::println(std::cerr, "Unknown Exception caught in main!");
    }

    return 0;
}
