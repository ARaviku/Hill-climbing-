#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>

#include "climber.h"

bool operator==(Coordinate const &c1, Coordinate const &c2)
{
    return (c1.x == c2.x) && (c1.y == c2.y);
}

bool operator<(Coordinate const &c1, Coordinate const &c2)
{
    if (c1.x == c2.x)
    {
        return c1.y < c2.y;
    }
    return c1.x < c2.x;
}

Coordinate operator+(Coordinate const &c1, Coordinate const &c2)
{
    return {c1.x + c2.x, c1.y + c2.y};
}

void read_input(std::map<Coordinate, int> &m, Coordinate &start, std::string const &infilename)
{
    std::ifstream infile(infilename);
    if (!infile.good())
    {
        std::cerr << "No such file " << infilename << '\n';
        throw std::runtime_error("No such file!");
    }

    infile >> start.x;
    infile >> start.y;
    infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // move to next line

    int x_idx = 0;
    int y_idx = 0;
    std::string line;
    while (std::getline(infile, line))
    {
        std::stringstream ssline(line);
        int val;
        while (ssline >> val)
        {
            m[{x_idx, y_idx}] = val;
            x_idx++;
        }
        x_idx = 0;
        y_idx++;
    }
}

void climber_algorithm(std::map<Coordinate, int> const &m, Coordinate const &start, std::string const &outfilename)
{
    std::ofstream outfile(outfilename);
    std::cout << "height at start: " << m.at(start) << std::endl;

    Coordinate current_xy = start;
    int current_height = m.at(start);
    Coordinate n1, n2, n3, n4;
    n1.x = 1;
    n1.y = 0;
    n2.x = -1;
    n2.y = 0;
    n3.x = 0;
    n3.y = 1;
    n4.x = 0;
    n4.y = -1;

    std::vector<Coordinate> offsets{
        // --- Your code here
        n1, n2, n3, n4
        // ---
    };

    while (true)
    {
        outfile << current_xy.x << " " << current_xy.y << " " << current_height << std::endl;
        Coordinate next;
        int height_next = current_height;
        std::vector<Coordinate> next_v;
        
        for (int i = 0; i < offsets.size(); i++)
        {
            next = current_xy + offsets[i];
            if (m.count(next) != 0)
            {
                next_v.push_back(next);
            }
        }

        std::vector<int> height_vec;
        for (int i = 0; i < next_v.size(); i++)
        {
            height_vec.push_back(m.at(next_v[i]));
        }

        for (int i = 0; i < height_vec.size(); i++)
        {
            if (current_height < height_vec[i])
            {
                if (height_vec[i] - current_height <= 2)
                {
                    if(height_next < height_vec[i]){
                        height_next = height_vec[i];
                        next = next_v[i];
                    }

                }
            }
        }
        if (current_height == height_next)
        {
            break;
        }

        current_xy = next;
        current_height = height_next;

        // ---
    }

    std::cout << "location at end: " << current_xy.x << " " << current_xy.y << std::endl;
    std::cout << "height at end: " << current_height << std::endl;
}
