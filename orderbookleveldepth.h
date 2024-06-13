#pragma once

#include "booklevel.h"

class BookDepth
{
    public:
        using Book_Level_Depth = std::vector<LevelDepth>; 
        BookDepth(const Book_Level_Depth& asks, const Book_Level_Depth& bids) : _asks{asks},_bids{bids}
        {}
        ~BookDepth()
        {}
        const Book_Level_Depth& get_asks() const {return _asks;}; 
        const Book_Level_Depth& get_buys() const {return _bids;}; 

    private: 
        Book_Level_Depth _asks;
        Book_Level_Depth _bids; 

}; 