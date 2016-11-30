#ifndef	MAP_RIMULDAR_H
#define MAP_RIMULDAR_H


#include <vector>
#include "map_class.h"

void LoadRimuldar();

// This header file contains the map info for Rimuldar
cMap cMapRimuldar;

void LoadRimuldar()
{
    // Map Dimensions
    cMapRimuldar.nMapWidth   = 58;
    cMapRimuldar.nMapHeight  = 86;


    cMapRimuldar.nMapLayout.resize(cMapRimuldar.nMapHeight, std::vector<int>(cMapRimuldar.nMapWidth, 0));

    // Map Declarations
    cMapRimuldar.nMapLayout = {
        // 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48  49  50  51  52  53  54  55  56  57
    	{ 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  3,  3,  3,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  3,  5,  5,  5,  9,  9,  9,  4,  4,  3,  3,  3,  3,  3,  3,  3,  3,  5,  5,  5,  5,  3,  3,  3,  3,  3,  3,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  3, 14,  3,  3,  1, 44,  9,  4,  3,  3,  3,  3,  3,  4,  4,  4,  3,  3,  3,  4,  5,  5,  5,  5,  3,  3,  3,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  5,  3,  3, 44,  9,  9,  3,  3,  3,  3,  1,  1,  1,  1,  1,  1,  1,  1,  4,  4,  3,  3,  5,  5,  5,  5,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  4,  9, 44,  9,  9,  9,  3,  4,  3,  3,  1,  3,  4,  3,  1,  6,  6,  1,  3,  3,  3,  3,  3,  4,  4,  5,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  4,  9,  9,  9,  9,  9,  3,  3,  2,  2,  1,  2,  2,  2,  1,  2,  2,  1,  3,  3,  2,  2,  2,  2,  2,  5,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  9,  9,  9,  9,  9,  3,  3,  2,  1,  1,  1,  2,  1,  1,  1,  2,  1,  3,  3,  2,  1,  1,  1,  2,  5,  5,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  9,  9,  9,  9,  9,  3,  3,  2,  1,  1,  1,  2,  1,  1,  1,  2,  1,  4,  3,  2,  2, 11,  2,  2,  6,  5,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  3,  3,  3,  3,  3,  3,  3,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  2,  6,  5,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  3,  3,  3,  3,  3,  5,  5,  4,  3,  3,  3,  3,  3,  4,  3,  3,  1,  3, 12,  2,  1,  1,  1,  2,  6,  5,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  4,  3,  5,  5,  5,  5,  5,  5,  3,  3,  3,  1,  1,  1,  1,  1,  1,  1,  3,  2,  1,  1,  1,  2,  6,  5,  5,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  6,  3,  5,  5,  4,  4,  4,  5,  5,  3,  4,  1,  1,  1,  1,  1,  1,  1,  1,  3,  2,  2,  2,  2,  2,  4,  3,  5,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  6,  5,  5,  4,  3,  3,  4,  5,  3,  3,  1,  1,  1,  3,  3,  3,  3,  1,  1,  3,  3,  3,  3,  4,  4,  4,  4,  5,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  6,  6,  6,  4,  3,  4,  5,  5,  3,  1,  1,  1,  3,  3,  4,  3,  3,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 14,  1, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  6,  5,  5,  4,  4,  5,  5,  3,  3,  1,  1,  3,  3,  4,  4,  3,  3,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 14,  1, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  6,  3,  5,  5,  5,  5,  3,  3,  3,  1,  1,  3,  4,  4,  3,  2, 13,  1,  3,  3,  4,  4,  3,  3,  4,  4,  4,  5,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  4,  3,  3,  3,  3,  4,  3,  3,  1,  1,  3,  3,  4,  2,  2,  2,  1,  2,  2,  2,  2,  2,  2,  2,  4,  3,  5,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  3,  3,  3,  3,  4,  4,  4,  3,  1,  1,  3,  4,  4,  2,  1, 11,  1,  2,  1,  1,  2,  1,  1,  2,  3,  5,  5,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  9,  9,  9,  9,  9,  9,  9,  9,  1,  1,  9,  3,  4,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  2,  3,  5,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  9,  9,  9,  9,  9,  9,  9,  9, 44, 44,  9,  3,  3,  2,  1,  1,  1,  1,  1,  1,  2,  1,  1,  2,  4,  5,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  3,  4,  2,  2,  1,  2,  2,  2, 10,  2,  2,  2,  2,  4,  5,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  3,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  3,  6,  2,  1,  1,  1,  2,  1,  1,  2,  1,  1,  2,  5,  5,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  4,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  3,  6,  2,  1,  1,  1,  2,  1,  1, 10,  1,  1,  2,  5,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  4,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  3,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  5,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },    
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  5,  5,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  4,  6,  6,  6,  6,  4,  3,  3,  4,  4,  5,  5,  5,  5,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  3,  5,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  4,  4,  3,  3,  4,  3,  3,  5,  5,  5,  5,  3,  3,  3,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  3,  5,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  4,  4,  4,  4,  5,  5,  5,  5,  3,  3,  3,  3,  3,  3,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  3,  3,  3,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 45,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 45,  1,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  1,  1,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2, 11,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  1,  1,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  2,  2,  2,  2,  2, 45, 45,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  1,  1,  1,  1,  2,  1,  1,  1,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  1,  1,  2,  1,  1,  1,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  1, 11,  1,  1,  1,  1,  2,  2,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  1,  1,  2,  1,  1,  1,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  1,  1,  1,  1,  2,  1,  1,  1,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
        {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 }
    };

    ////////////////
    // Chest data //
    ////////////////

    cMapRimuldar.nChests =  1;

    // fields corespond to:
    // 0 = nItemType
    // 1 = nGoldMin
    // 2 = nGoldMax
    // 3 = nPositionY
    // 4 = nPositionX
    cMap::CHEST sTempChestList[] = {
        { true, cnItemWings,  0,  0, 30, 38 }
    };
    memcpy( cMapRimuldar.sChestList, sTempChestList, sizeof(sTempChestList));

    ////////////////
    // Actor data //
    ////////////////

    cMapRimuldar.nActors =  0;

    // fields corespond to:
    // 0 = Does the actor actually exist
    // 1 = nCostume
    // 2 = nInitialPositionY
    // 3 = nInitialPositionX
    // 4 = nMovementPattern
    // 5 = bIsMerchant
    // 6 = nConversation
    cMap::ACTOR sTempActorList[] = {};
    memcpy( cMapRimuldar.sActorList, sTempActorList, sizeof(sTempActorList));

    cMapRimuldar.nStairs = 0;

    // Values corespond to:
    // nStairOriginY
    // nStairOriginX
    // nStairDestinationY
    // nStairDestinationX
    // *nStairDestinationMap

    cMap::STAIRS sTempStairList[] = {};
    memcpy( cMapRimuldar.sStairList, sTempStairList, sizeof(sTempStairList));

    cMapRimuldar.bInCave = false;
}

#endif // MAP_RIMULDAR_H