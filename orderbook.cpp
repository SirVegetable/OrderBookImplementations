#include "orderbook.h"

OrderBook::OrderBook()
{

}

OrderBook::~OrderBook()
{

}

bool OrderBook::can_match(Side side, OrderPrice price)
{

}

bool OrderBook::can_complete_fill(Side side, OrderPrice price, OrderQuantity quantity)
{
    
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
