#include <iostream>

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

int main() {
    httplib::Client cli("https://www.donationalerts.com");

    // Добавляем заголовок Authorization
    const httplib::Headers headers = {
        {"Authorization", "Bearer your_access_token_here"}
    };

    if (auto res = cli.Get("/api/v1/alerts/donations", headers); res && res->status == 200) {
        std::cout << "Ответ сервера:\n" << res->body << std::endl;
    } else {
        std::cerr << "Ошибка запроса! Код: " << (res ? res->status : 0) << std::endl;
    }

    return 0;
}