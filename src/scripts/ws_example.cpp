#include "ftx/ws/client.hpp"
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

void on_update(json j)
{
  std::string str = j.get<std::string>();
  j = json::parse(str);
  std::cout << j << "\n";
}

int main()
{
  ftx::WSClient client;
  
  client.subscribe_orderbook("ETH-PERP");
  client.on_message(on_update);
  client.connect();
}