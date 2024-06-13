#pragma once

#include "utils.h"
#include <memory> 
#include <list> 
#include <format> 


class Order{
    public:
        
        Order(OrderType _ordertype, Side side, OrderID id, OrderPrice price, OrderQuantity quantity) : 
            order_type(_ordertype),_side(side), order_id(id),order_price(price), order_quantity(quantity), remaining_order_quantity(quantity)
        {}
        ~Order()
        {}

        OrderID get_order_id() const
        {
            return order_id; 
        } 

        Side get_side() const 
        {
            return _side; 
        }

        OrderPrice get_price() const
        {
            return order_price; 
        }

        OrderType get_order_type() const
        {
            return order_type; 
        }

        OrderQuantity get_initial_quantity() const
        {
            return order_quantity; 
        }

        OrderQuantity get_remaining_fill_quantity() const
        {
            return remaining_order_quantity; 
        }
        
        OrderQuantity get_filled_quantity()
        {
            return order_quantity - remaining_order_quantity; 
        }

        bool check_if_filled() const
        {
            return get_remaining_fill_quantity() == 0; 
        }

        void fill_order(OrderQuantity quanity)
        {   
            if(quanity > get_remaining_fill_quantity())
            {
                throw std::logic_error(std::format("order ({}) cannot be filled for more than its remaining quantity", get_order_id())); 
            }
            remaining_order_quantity -= quanity; 
        }
    

    private:
        Side _side;
        OrderPrice order_price; 
        OrderQuantity order_quantity;
        OrderID order_id;
        OrderType order_type;
        OrderQuantity remaining_order_quantity; 

}; 

    using OrderPtr = std::shared_ptr<Order>;
    using OrderPtrs = std::list<OrderPtr>;


