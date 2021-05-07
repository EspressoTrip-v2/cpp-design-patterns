#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// INTERFACE SEGREGATION PRINCIPLE
// Simplify interface to only necessary methods for the job
using namespace std;
using namespace boost;

// Non Compliant
/*
struct Document;
struct IMachine
{
	virtual ~IMachine() = default;

	virtual void print(Document& d) = 0;
	virtual void scan(Document& d) = 0;
	virtual void fax(Document& d) = 0;
};

struct MFP : IMachine
{
	virtual void print(Document& d) override
	{
	};
	virtual void scan(Document& d) override
	{
	};
	virtual void fax(Document& d) override
	{
	};
};

struct Scanner :IMachine
{
	virtual void print(Document& d) override
	{
	};
	virtual void scan(Document& d) override
	{
		// Only using this
	};
	virtual void fax(Document& d) override
	{
	};
};
*/

// Compliant
struct Document;

struct IPrint
{
	virtual void print(Document& d) = 0;
	virtual ~IPrint() = default;
};

struct IScan
{
	virtual void scan(Document& d) = 0;
	virtual ~IScan() = default;
};

struct IFax
{
	virtual void fax(Document& d) = 0;
	virtual ~IFax() = default;
};

// If you want to make a Printer
struct IPrinter : IPrint
{
	virtual void print(Document& d) override
	{
		// Print code
	}
};

// If you want to make a printer and scanner create a new interface class
struct IPrintScan : IPrint, IScan {};

struct IMachine : IPrintScan
{
	virtual void print(Document& d) override
	{
		// Print Code
	}

	virtual void scan(Document& d) override
	{
		// Scan Code
	}
};

int main()
{
	return 0;
}