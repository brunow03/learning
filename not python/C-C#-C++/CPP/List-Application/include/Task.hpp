#include <string>
#include <vector>

struct Task
{
	std::string description;
	bool done;
};

void SaveTasksToFile(const std::vector<Task>& tasks, const std::string& fileName);
std::vector<Task> LoadTaskFromFile(const std::string& fileName);