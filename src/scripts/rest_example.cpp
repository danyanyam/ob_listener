#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "ftx/rest/futures.hpp"

using json = nlohmann::json;

void save_data_file(std::string fname, json &file)
{
    std::ofstream myfile;
    myfile.open(fname);
    myfile << file.dump(4);
}

int main(int argc, char const *argv[])
{
    ftx::Futures futures;

    json result = futures.list_all_futures();
    save_data_file("futures.json", result);

    // auto markets = client.list_markets();
    // save_data_file("markets.json", markets);

    // auto ob = client.get_orderbook("BTC-PERP", 3);
    // save_data_file("orderbook.json", ob);

    // std::cout << markets["result"];

    // auto acct = client.get_account_info();
    // std::cout << acct << "\n\n";

    // auto ord = client.place_order("BTC-PERP", "buy", 10, 0.01);
    // std::cout << ord << "\n\n";
}
