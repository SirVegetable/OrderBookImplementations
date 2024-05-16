#pragma once

#include "tradeinfo.h"

class Trade
{
    public: 
        Trade(const TradeInfo& bidTrade, const TradeInfo& askTrade): bid_trade(bidTrade), ask_trade(ask_trade)
        {}


    private:
        TradeInfo bid_trade; 
        TradeInfo ask_trade; 

};
using Trades = std::vector<Trades>; 