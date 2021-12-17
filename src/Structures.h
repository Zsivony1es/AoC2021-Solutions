//
// Created by Peter Ivony on 17.12.21.
//

#ifndef ADVENTOFCODE_STRUCTURES_H
#define ADVENTOFCODE_STRUCTURES_H

#import <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#define NC "\e[0m"
#define RED "\e[0;31m"

class Structures {
public:

    struct Octopus{
        bool flashed = false;
        size_t energy;
        Octopus(size_t e){this->energy = e;}
        Octopus()=default;
    };
    struct Node{
        std::string val;
        std::vector<Node*> conns;
        size_t visited = 0;
        bool isLarge;
        Node(std::string val);
        static uint64_t count_routes1(Node& node);
        static uint64_t count_routes2(Node& node, const std::string& twice_name);
    };
    struct TableElement{
        bool called;
        int val;
    };

    static constexpr size_t TABLE_SIZE = 5;
    struct BingoTable{
        TableElement table[TABLE_SIZE][TABLE_SIZE];
        BingoTable(std::vector<int> contents);
        //Sets called member of TableElement true if number was called
        void numberCalled(int num);
        bool checkBingo();
        int sum_of_not_called();
        std::string to_string();
        bool operator==(BingoTable ro);
    };

    struct Point{
        int x = 0, y = 0;
        Point() = default;
        Point(int x,int y);
        Point(const Point& p);
        [[nodiscard]] std::string to_string() const;
        bool operator==(const Point& p) const;
        friend std::ostream& operator<<(std::ostream& os, const Structures::Point& p);
    };
    struct Line{
        Structures::Point begin, end;
        Line(const Structures::Point& begin, const Structures::Point& end);
        Line(int x1, int y1, int x2, int y2);
        [[nodiscard]] std::vector<Structures::Point> getAllPoints() const;
        friend std::ostream& operator<<(std::ostream& os, const Line& l);
    };



};


#endif //ADVENTOFCODE_STRUCTURES_H
