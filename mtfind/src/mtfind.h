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
	mtfind();
	mtfind(std::string path, std::string pattern);
	~mtfind();
	

private:
	std::mutex s_mutex;
	std::vector<std::future<void>> futures;

private:
	void getLine(std::ifstream& file);

public:
	std::string path;
	std::string pattern;
	std::vector<Line> finded;
	size_t row = 1;
	
public:
	void find();
};