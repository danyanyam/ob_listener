#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "ftx/util/session.hpp"

using json = nlohmann::json;

namespace ftx
{
    class Futures : public FTXSession
    {
    public:
        // https://docs.ftx.com/#futures
        json list_all_futures();
        //  https://docs.ftx.com/#get_future
        json get_future(std::string future_name);
        //  https://docs.ftx.com/#get_future
        json get_future_stats(std::string future_name);
        //  https://docs.ftx.com/#get-index-weights
        json get_index_weights(std::string index_name);
        //  https://docs.ftx.com/#get-index-weights
        json get_expired_futures();
        //  https://docs.ftx.com/#get-historical-index
        json get_historical_index(std::string market_name, int resolution,
                                  int start_time, int end_time);
    };

}