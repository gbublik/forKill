#include <iostream>
#include "httplib.h"
#include <fstream>
#include <string>

std::string readFile(const char* path) {
    if (std::ifstream file(path); file.is_open()) {
        std::ostringstream ss;
        ss << file.rdbuf();
        file.close();
        return ss.str();
    } else {
        std::cerr << "Unable to open file" << std::endl;
        exit(1);
    }
}

int main() {
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request &req, httplib::Response &res) {
      res.set_content(readFile("../AuthorizationRequest.html"), "text/html; charset=UTF-8");
    });

    svr.listen("127.0.0.1", 8080);
    return 0;
}