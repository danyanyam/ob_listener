#pragma once

#include "ftx/util/http.hpp"
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

namespace ftx
{
    /*
    performs API calls inline with arguments
    that exchange uses
    */
    class RESTClient
    {
    public:
        RESTClient();

        /*
        Returns current state of futures market.

        Covers all types of futures on FTX: perpetual,
        expiring, and MOVE. Examples for each type are BTC-PERP,
        BTC-0626, and BTC-MOVE-1005. For futures that expired in 2019,
        prepend a 2019 to the date, like so: BTC-20190628.
        */
        json list_futures();

        /*
        As before, but returns fields for specific asset:

        ask, bid, change1h, change24h, description, enabled
        expired, expiry, index, last, lowerBound, mark,
        name, perpetual, postOnly, priceIncrement, sizeIncrement
        underlying, upperBound, type
        */
        json list_futures(const std::string future);

        /*
            Example return
                "success": true,
                "result": {
                    "volume": 1000.23,
                    "nextFundingRate": 0.00025,
                    "nextFundingTime": "2019-03-29T03:00:00+00:00",
                    "expirationPrice": 3992.1,
                    "predictedExpirationPrice": 3993.6,
                    "strikePrice": 8182.35,
                    "openInterest": 21124.583
                }
        */
        json get_future_stats(const std::string future);
        json list_markets();
        json get_orderbook(const std::string market, int depth = 100);
        json get_trades(const std::string market);
        json get_account_info();
        json get_open_orders();
        json place_order(const std::string market,
                         const std::string side,
                         double price,
                         double size,
                         bool ioc = false,
                         bool post_only = false,
                         bool reduce_only = false);

        // Market order overload
        json place_order(const std::string market,
                         const std::string side,
                         double size,
                         bool ioc = false,
                         bool post_only = false,
                         bool reduce_only = false);

        json cancel_order(const std::string order_id);
        json get_fills();
        json get_balances();
        json get_deposit_address(const std::string ticker);

    private:
        util::HTTPSession http_client;
        const std::string uri = "ftx.com";
        const std::string api_key = "";
        const std::string api_secret = "";
        const std::string subaccount_name = "";
    };

}