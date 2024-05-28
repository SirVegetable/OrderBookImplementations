
#include "orderbook.h"
#include <algorithm> 
#include <unordered_map>
#include <iterator> 

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

Trades OrderBook::match_orders()
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

            trades.push_back(Trade{TradeInfo{bid->get_order_id(), bid->get_price(), quantity_to_be_filled}
                , TradeInfo{ask->get_order_id(), ask->get_price(), quantity_to_be_filled}}); 

        }

    }
    if(!bids.empty())
    {
        auto& [_,bids_] = *bids.begin(); 
        auto& order = bids_.front();
        if(order->get_order_type() == OrderType::FillAndKill)
        {
            cancel_order(order->get_order_id()); 
        }
    }
    if(!asks.empty())
    {
        auto& [_,asks_] = *asks.begin();
        auto& order = asks_.front(); 
        if(order->get_order_type() == OrderType::FillOrKill)
        {
            cancel_order(order->get_order_id()); 
        }
    }
    return trades; 
}





Trades OrderBook::add_order(OrderPtr order)
{
    OrderPtrs::iterator order_iterator; 
    if(orders.contains(order->get_order_id()))
    {
        return { }; 
    }
    if(order->get_side() == Side::Buy)
    {   
        auto& orders = bids[order->get_price()]; 
        orders.push_back(order);
        order_iterator = std::next(orders.begin(), orders.size()); 

    }
}

void OrderBook::cancel_order(OrderID order_id)
{

}

Trades OrderBook::modify_order(OrderModify order)
{

}
