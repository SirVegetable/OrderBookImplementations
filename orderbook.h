#include <map> 
#include "utils.h"
#include "order.h"
#include "trade.h"
#include "modifyorder.h"

class OrderBook
{
    public:
        OrderBook(); 
        ~OrderBook(); 
        OrderBook(const OrderBook& )= delete;
        void operator=(const OrderBook&) = delete; 
        OrderBook(OrderBook&&) = delete; 
        void operator=(OrderBook&&) = delete; 

        Trades add_order(OrderPtr order);
        Trades modify_order(OrderModify order);
        void cancel_order(OrderID order_id);  

    private:
        struct OrderEntry
        {
            OrderPtr order_object{nullptr}; 
            OrderPtrs::iterator order_location; 
        }; 
        std::map<OrderPrice,OrderPtrs, std::greater<OrderPrice>> bids;
        std::map<OrderPrice,OrderPtrs, std::less<OrderPrice>> asks;
        std::unordered_map<OrderID,OrderEntry> orders;
        bool can_match(Side side, OrderPrice price); 
        bool can_complete_fill(Side side, OrderPrice price, OrderQuantity quantity);
        Trades match_orders(); 


};
