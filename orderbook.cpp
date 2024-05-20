
#include "orderbook.h"
#include <algorithm> 

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

            OrderQuantity quantity_to_be_filled = std::min(bid->get_remaining_fill_quantity(),ask->get_remaining_fill_quantity()); 

            bid->fill_order(quantity_to_be_filled); 
            ask->fill_order(quantity_to_be_filled);

            if(bid->check_if_filled())
            {
                bids_.pop_front();
                orders.erase(bid_price); 

            }
            if(ask->check_if_filled())
            {
                asks_.pop_front(); 
                orders.erase(ask_price); 
            }
            if(bids_.empty())
            {
                bids.erase(bid_price); 
            }
            if(asks_.empty())
            {
                asks.erase(ask_price); 
            }

            trades.push_back(Trade{TradeInfo{bid->get_order_id(), bid->get_price(), quantity}
                , TradeInfo{ask->get_order_id(), ask->get_price(), quantity}}); 

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
