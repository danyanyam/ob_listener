#include "ftx/ws/client.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include "logger/logger.hpp"

using json = nlohmann::json;

void on_update(json j)
{
  std::string str = j.get<std::string>();
  j = json::parse(str);
  std::cout << j << "\n";
}

int main()
{
  auto client = ftx::WSClient();
  auto logger = Logger(
      "FTX", /* logger_name */
      true   /* to_file */
  );
 
  logger.info("Started collecting data");
  client.subscribe_orderbook("ETH-PERP");
  client.on_message(on_update);
  client.connect();
  logger.info("Ended collecting data");
}