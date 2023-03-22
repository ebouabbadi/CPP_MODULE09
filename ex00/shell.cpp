#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    string input;
    vector<string> args;

    while (true) {
        cout << "$ ";
        getline(cin, input);

        // Split input into arguments
        args.clear();
        size_t pos = 0;
        while ((pos = input.find(' ')) != string::npos) {
            args.push_back(input.substr(0, pos));
            input.erase(0, pos + 1);
        }
        args.push_back(input);

        // Convert arguments to char* array for execvp
        char* argv[args.size() + 1];
        for (int i = 0; i < args.size(); i++) {
            argv[i] = &args[i][0];
        }
        argv[args.size()] = NULL;

        // Fork and execute command
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execvp(argv[0], argv);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Forking error
            cerr << "Forking error" << endl;
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL);
        }
    }

    return 0;
}