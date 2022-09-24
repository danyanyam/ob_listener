#include "ftx/rest/futures.hpp"

namespace ftx
{
    json Futures::list_all_futures()
    {
        auto result = get("futures");
        return json::parse(result.body());
    }
    json Futures::get_future(std::string future_name)
    {
        auto result = get("futures/" + future_name);
        return json::parse(result.body());
    }
    json Futures::get_future_stats(std::string future_name)
    {
        auto result = get("futures/" + future_name + "/stats");
        return json::parse(result.body());
    }
    json Futures::get_index_weights(std::string future_name)
    {
        auto result = get("indexes/" + future_name + "/weights");
        return json::parse(result.body());
    }
    json Futures::get_expired_futures()
    {
        auto result = get("expired_futures");
        return json::parse(result.body());
    }
}