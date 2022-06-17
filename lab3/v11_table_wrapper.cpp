#pragma once

#include "table.cpp"
#include <string>
#include <vector>
#include <sstream>

Table table({"#", "x", "f(x)", "|f(x)|/m"});

void addRowTable(int n, double x, double fx, double fxm) {
	std::ostringstream ss1, ss2, ss3;
	ss1 << x;
	ss2 << fx;
	ss3 << fxm;
    std::vector<std::string> row{
		std::to_string(n),
		ss1.str(),
		ss2.str(),
		ss3.str()
	};
	table.addRow(row);
}

void writeTable() {
	table.write();
}
