#pragma once
#include <iostream>
#include <vector>
#include <string>

class Table {
public:
    std::vector<std::string> headers;
    std::vector<std::vector<std::string>> rows;

    Table(std::vector<std::string> headers): headers(headers) {}

    void addRow(std::vector<std::string> columns) {
	rows.push_back(columns);
    }

    void write() {
        int lengths[headers.size()];
	std::vector<std::string> headCells;
	for (int i = 0; i < headers.size(); i++) {
		lengths[i] = 0;
		for (int j = 0; j < rows.size(); j++) {
			int len = rows[j][i].length();
			if (len > lengths[i]) {
				lengths[i] = len;
			}
		}
		std::string cell = createCell(headers[i], lengths[i]);
		if (lengths[i] < cell.length()) {
			lengths[i] = cell.length();
		}
		headCells.push_back(cell);	
	}
        std::string header = createTableRow(headCells);
        std::string rowSeparator = std::string(header.length(), '-');
        writeRow(header, rowSeparator);

        for (const auto &row : rows) {
            std::vector<std::string> cells;
            for (int i = 0; i < row.size(); ++i) {
                cells.push_back(createCell(row[i], lengths[i]));
            }
            std::string rowTable = createTableRow(cells);
            writeRow(rowTable, rowSeparator);
        }

    }

private:
    void writeRow(std::string& row, const std::string& separator) {
        std::cout << row << "\n";
        std::cout << separator << "\n";
    }

    std::string createTableRow(const std::vector<std::string>& strings) {
        std::string sep = " | ";
        std::string result;
        for (const auto &item : strings) {
            result += sep;
            result += item;
        }
        return result.substr(sep.size());
    }

    std::string createCell(std::string value, int& minLength) {
        int diff = minLength - value.length();
	int first = diff / 2;
        if (diff > 0) {
            return std::string (first, ' ') + value + std::string (diff - first, ' ');
        }
        return value;
    }

};


