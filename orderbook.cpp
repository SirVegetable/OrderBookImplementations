
#include "orderbook.h"

OrderBook::OrderBook()
{

}

OrderBook::~OrderBook()
{

}

bool OrderBook::can_match(Side side, OrderPrice price)
{
    if(side == Side::Sell)
    {
        if(asks.empty())
        {
            return false; 
        }
        const auto& [best_ask,_] = *bids.begin(); 
        return price >= best_ask; 

    }
    if(side == Side::Buy)
    {
        if(asks.empty())
        {
            return false; 
        }
        const auto& [best_bid, _] = *asks.begin(); 
        return best_bid;
    }

}

bool OrderBook::can_complete_fill(Side side, OrderPrice price, OrderQuantity quantity)
{
    Trades trades; 
    trades.reserve(orders.size()); 
    
    while(1)
    {
        if(bids.empty() || asks.empty())
        {
            break; 
        }
        auto& [bid_price,bids_] = *bids.begin(); 
        auto& [ask_price, asks_] = *asks.begin();

        if(bid_price < ask_price)
        {
            break; 
        }
        while(bids_.size(), asks_.size())
        {
            auto bid = bids_.front(); 
            auto ask = asks_.front(); 

        }

    }
    
}


Trades OrderBook::match_orders()
{
    
}





Trades OrderBook::add_order(OrderPtr order)
{

}

void OrderBook::cancel_order(OrderID order_id)
{

}

Trades OrderBook::modify_order(OrderModify order)
{

}
