#include <iostream>
#include <chrono>
#include <string>
#include <cstring>

int main(int argc, char *argv[])
{
    char cmd[256];

    if (argc == 2)
    {
        // input
        std::string filename(argv[1]);

        // last dot index
        size_t lastdot = filename.find_last_of(".");
        if (lastdot == std::string::npos)
        {
            std::cerr << "No extension found in the filename\n\n";
            return 1;
        }

        // seperating extension
        std::string extension = filename.substr(lastdot);
        std::string rawname = filename.substr(0, lastdot);
        char cmd[256];

        // compiling c/cpp file
        if (extension == ".c")
        {
            sprintf(cmd, "gcc %s.c -o output/%s.exe", rawname.c_str(), rawname.c_str());
        }
        else if (extension == ".cpp")
        {
            sprintf(cmd, "g++ %s.cpp -o output/%s.exe", rawname.c_str(), rawname.c_str());
        }
        else
        {
            std::cerr << "Invalid extension\n\n";
            return 1;
        }

        system(cmd);

        sprintf(cmd, "./output/%s.exe", rawname.c_str());

        // executing compiled code with calculating total time
        auto start = std::chrono::high_resolution_clock::now();
        system(cmd);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = end - start;
        std::cout << "\n\nTime to execute: " << diff.count() << " s\n";
    }
    else if (argc > 2)
    {
        std::cerr << "Too many arguments\n\n";
        return 1;
    }
    else
    {
        std::cerr << "At least 1 argument expected\n\n";
        return 1;
    }

    return 0;
}
