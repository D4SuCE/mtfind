#include "mtfind.h"

mtfind::mtfind()
{
}

mtfind::mtfind(std::string path, std::string pattern)
	: path(path), pattern(pattern)
{
}

mtfind::~mtfind()
{
	futures.clear();
}



void mtfind::getLine(std::ifstream& file)
{
	std::lock_guard<std::mutex> lock(s_mutex);
	std::string line;
	std::getline(file, line);
	for (auto it = line.find(pattern); it != std::string::npos; it = line.find(pattern, ++it))
	{
		size_t i = it, j = it + pattern.size() - 1;

		while (line[i] != ' ' && i != 0)
		{
			i--;
		}
		while (line[j] != ' ' && line[j] != '\0')
		{
			j++;
		}
		finded.push_back({ row, (i > 0 ? i + 2 : i), line.substr((line[i] == ' ' ? i + 1 : i), j - i) });
	}
	row++;
}

void mtfind::find()
{
	pattern = pattern.substr(1);
	std::ifstream file(path);
	if (!file.is_open())
	{
		std::cout << "No such file!" << std::endl;
		exit(-3);
	}

	while (file.good())
	{
		futures.push_back(std::async(std::launch::async, &mtfind::getLine, this, ref(file)));
	}

	file.close();

	std::cout << finded.size() << std::endl;

	for (auto line : finded)
	{
		std::cout << line.row << " " << line.column << " " << line.str << std::endl;
	}
}