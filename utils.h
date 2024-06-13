#pragma once 

#include <vector>

// Define the Trade Side
enum class Side
{
    Buy, Sell
}; 

// Defining the basic types for the Order
using OrderPrice = std::int32_t;
using OrderQuantity = std::int32_t; 
using OrderID = std::int64_t; 

// Define the Types of Orders that the Book will have

enum class OrderType
{   
    GoodTillCancel, Market, GoodForDay, FillOrKill, FillAndKill

}; 

