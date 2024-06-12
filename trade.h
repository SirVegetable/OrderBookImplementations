#pragma once

#include "tradeinfo.h"

class Trade
{
    public: 
        Trade(const TradeInfo& bidTrade, const TradeInfo& askTrade): bid_trade(bidTrade), ask_trade(askTrade)
        {}

        const TradeInfo& get_bid_trade() const
        {
            return bid_trade; 
        }
        const TradeInfo& get_ask_trade() const
        {
            return ask_trade; 
        }
    private:
        TradeInfo bid_trade; 
        TradeInfo ask_trade; 

};
using Trades = std::vector<Trade>; 