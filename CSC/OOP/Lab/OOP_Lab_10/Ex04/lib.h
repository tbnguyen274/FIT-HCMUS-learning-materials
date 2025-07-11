#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CItem {
protected:
	string _name;
	bool _isReadOnly;
	bool _isHidden;

public:
	CItem();
	virtual ~CItem() {}
	virtual void PrintHelper(bool isPrintHiddenItems, int level) = 0;
	void Print(bool isPrintHiddenItems) {
		PrintHelper(isPrintHiddenItems, 0);
	}

	virtual CItem* RemoveByName(const string& name) = 0;
	virtual CItem* FindByName(const string& name) = 0;

	virtual void SetHidden(bool isHidden, bool isApplyToChildren) {
		_isHidden = isHidden;
	}

	void SetReadOnly(bool isReadOnly) {
		_isReadOnly = isReadOnly;
	}

	string GetName();
	bool IsHidden();

	virtual double GetSize() = 0;
};

class CFile : public CItem {
private:
	double _size;

public:
	CFile(const string& name, double size);
	~CFile() {};
	void PrintHelper(bool isPrintHiddenItems, int level) override;
	CItem* RemoveByName(const string& name) override;
	CItem* FindByName(const string& name) override;
	double GetSize() override;
};

class CFolder : public CItem {
private:
	vector<CItem*> _items;

public:
	CFolder(const string& name);
	~CFolder();
	void PrintHelper(bool isPrintHiddenItems, int level) override;
	CItem* RemoveByName(const string& name) override;
	CItem* FindByName(const string& name) override;
	void Add(CItem* item);
	void SetHidden(bool isHidden, bool isApplyToChildren) override;
	double GetSize() override;
};