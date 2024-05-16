#include "utils.h"

class Order{
    public:
        Order(Side side, OrderID id, OrderPrice price, OrderQuantity quantity, OrderQuantity remaining) : 
            _side(side), order_id(id), order_quantity(quantity), remaining_order_quanity(remaining)
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
            return remaining_order_quanity; 
        }
        
        OrderQuantity get_filled_quanity()
        {
            return order_quantity - remaining_order_quanity; 
        }

        void fill_order()
        {
            
        }
    

    private:
        Side _side;
        OrderPrice order_price; 
        OrderQuantity order_quantity;
        OrderID order_id;
        OrderType order_type;
        OrderQuantity remaining_order_quanity; 

}; 