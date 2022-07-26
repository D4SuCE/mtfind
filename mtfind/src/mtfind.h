#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <future>
#include <mutex>

struct Line
{
	size_t row;
	size_t column;
	std::string str;
};

class mtfind
{
public:
	std::string path;
	std::string pattern;
	std::vector<Line> finded;
	size_t row = 1;

private:
	std::vector<std::future<void>> futures;

public:
	mtfind();
	mtfind(std::string path, std::string pattern);
	~mtfind();	
	void find();
};