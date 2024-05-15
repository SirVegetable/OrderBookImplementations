#include "utils.h"

class Order{
    public:
        Order() 
        {}
        ~Order()
        {}
        
        OrderID get_order_id(); 

        Side get_side();

        OrderPrice get_price(); 

        OrderType get_order_type(); 

        OrderQuantity get_initial_quantity(); 

        OrderQuantity get_remaining_fill_quantity; 

        void fill_order(); 



    

    private:
        Side _side;
        OrderPrice order_price; 
        OrderQuantity order_quantity;
        OrderID order_id;
        OrderType order_type; 




}; 