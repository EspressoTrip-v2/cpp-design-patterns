#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// SINGLE RESPONSIBILITY PRINCIPLE
// A class should have one, and only one, reason to change.
struct Journal
{
	std::string m_title;
	std::vector<std::string> m_entries;
	explicit Journal(const std::string& title) :m_title{ title } {};

	void addEntry(const std::string& entry)
	{
		static int count{ 1 };
		m_entries.push_back(boost::lexical_cast<std::string>(count++) + " : " + entry);
	}
};

struct PersistenceManager
{
	static void save(const Journal& j, const std::string& filename)
	{
		std::ofstream fs{ filename, std::ios::app };
		if (!fs.is_open())return;
		for (auto& e : j.m_entries)
		{
			fs << e << std::endl;
		}
		fs.close();
		std::cout << "File created" << std::endl;
	}
};

int main() {
	Journal myJournal{ "Juan's Journal" };
	myJournal.addEntry("Had a difficult day");
	myJournal.addEntry("Learning C+ is hard");
	myJournal.addEntry("I feel like a moron");

	PersistenceManager::save(myJournal, "journal.txt");
	return 0;
}