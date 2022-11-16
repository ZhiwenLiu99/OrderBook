#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "messageHandler.hpp"

using namespace std;

int getColNum(const string line) {
    int col_num = 0;
    for(auto c : line) {
        if(c==',') {
            ++col_num;
        }
    }
    return col_num;
}

int main(int argc, const char * argv[]) {
    messageData inMsg;
    std::ifstream tickStream("../OrderBook_data/tickdata_order_600xxx_20220225.csv");
    std::ofstream log("log.txt", std::ios::out);
    
    string line, cell;
    std::getline(tickStream, line);  // read the first line (which is the column names)
    int rowID = 0, colID = 0, MAX_COL_ID = getColNum(line);

    // tick-level message stream starts to get read here
    while(std::getline(tickStream, line) && rowID<=10) {
        cout << "Message row no." << rowID << ":\n" << line << endl; // For test purposes
        std::stringstream linestream(line);
        colID = 0;
        while(std::getline(linestream, cell, ',') && colID<=MAX_COL_ID) {
            cout << cell << ", ";
            colID++;
        }
        cout<<endl<<endl;
        rowID++;
    }
    cout << "Program finished!\n";
    return 0;
}