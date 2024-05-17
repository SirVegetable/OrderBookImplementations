#include <map> 
#include "utils.h"
#include "order.h"

class OrderBook
{
    public: 
    private:
        struct OrderEntry
        {
            OrderPtr order_object{nullptr}; 
            OrderPtrs::iterator order_location; 
        }; 
        std::map<OrderPrice,OrderPtrs, std::greater<OrderPrice>> bids;
        std::map<OrderPrice,OrderPtrs, std::less<OrderPrice>> asks;
        std::unordered_map<OrderID,OrderEntry> orders;
        
        

};
