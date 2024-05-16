#pragma once
#include "utils.h"
#include "order.h"

class OrderModify{

    public:
    OrderModify(OrderID id, Side side, OrderPrice price, OrderQuantity quantity) : m_order_id(id), m_side(side), m_order_price(price), m_order_quantity()
    {}
    ~OrderModify()
    {}

    OrderID get_id_to_modify() const
    {
        return m_order_id; 
    }
    OrderPrice get_price_to_modify() const
    {
        return m_order_price; 
    } 
    OrderQuantity get_quantity_to_modify() const
    {
        return m_order_quantity; 
    }
    Side get_side_to_modify() const
    {
        return m_side; 
    }


    private: 
        OrderPrice m_order_price; 
        OrderID m_order_id; 
        OrderQuantity m_order_quantity;
        Side m_side; 



}; 