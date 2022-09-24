#include "ftx/util/session.hpp"

namespace ftx
{
    FTXSession::FTXSession()
    {
        http_client.configure(uri, api_key, api_secret, subaccount_name);
    }
    http::response<http::string_body> FTXSession::get(const std::string target)
    {
        return http_client.get(target);
    }
    http::response<http::string_body> FTXSession::delete_(
        const std::string target)
    {
        return http_client.delete_(target);
    }
    http::response<http::string_body> FTXSession::post(
        const std::string target,
        const std::string payload)
    {
        return http_client.post(target, payload);
    }
}