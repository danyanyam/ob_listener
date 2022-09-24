#pragma once
#include "ftx/util/http.hpp"
#include <string>

namespace ftx
{
    class FTXSession
    {
    protected:
        util::HTTPSession http_client;
        const std::string uri = "ftx.com";
        const std::string api_key = "";
        const std::string api_secret = "";
        const std::string subaccount_name = "";
        http::response<http::string_body> get(const std::string target);
        http::response<http::string_body> post(const std::string target,
                                               const std::string payload);
        http::response<http::string_body> delete_(const std::string target);

    public:
        FTXSession();
    };
}