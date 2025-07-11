#include "lib.h"

CItem::CItem() {
	_name = "";
	_isReadOnly = false;
	_isHidden = false;
}

string CItem::GetName() {
	return _name;
}

bool CItem::IsHidden() {
	return _isHidden;
}

// CFILE
CFile::CFile(const string& name, double size) {
	_name = name;
	_size = size;
	_isReadOnly = false;
	_isHidden = false;
}

void CFile::PrintHelper(bool isPrintHiddenItems, int level) {
	if (isPrintHiddenItems || !_isHidden) {
		for (int i = 0; i < level; ++i) cout << "\t";
		cout << "File: " << _name << " (" << _size << " bytes)"
			<< " [Read-Only: " << (_isReadOnly ? "Yes" : "No")
			<< ", Hidden: " << (_isHidden ? "Yes" : "No") << "]" << endl;
	}
}

CItem* CFile::RemoveByName(const string& name) {
	if (_name == name) {
		return this;
	}
	return nullptr;
}

CItem* CFile::FindByName(const string& name) {
	if (_name == name) {
		return this;
	}
	return nullptr;
}

double CFile::GetSize() {
	return _size;
}

// CFOLDER
CFolder::CFolder(const string& name) {
	_name = name;
	_isReadOnly = false;
	_isHidden = false;
}

CFolder::~CFolder() {
	//
}

void CFolder::PrintHelper(bool isPrintHiddenItems, int level) {
	if (isPrintHiddenItems || !_isHidden) {
		for (int i = 0; i < level; ++i) cout << "\t";

		cout << "Folder: " << _name << " (" << GetSize() << " bytes)"
			<< " [Read-Only: " << (_isReadOnly ? "Yes" : "No")
			<< ", Hidden: " << (_isHidden ? "Yes" : "No") << "]" << endl;
		
		for (int i = 0; i < _items.size(); ++i) {
			_items[i]->PrintHelper(isPrintHiddenItems, level + 1);
		}
	}
}

CItem* CFolder::RemoveByName(const string& name) {
	for (int i = 0; i < _items.size(); i++) {
		if (_items[i]->GetName() == name) {
			CItem* item = _items[i];
			_items.erase(_items.begin() + i);
			return item;
		}

		CItem* removedItem = _items[i]->RemoveByName(name);
		if (removedItem != nullptr) {
			return removedItem;
		}
	}
	return nullptr;
}

CItem* CFolder::FindByName(const string& name) {
	for (int i = 0; i < _items.size(); i++) {
		if (_items[i]->GetName() == name) {
			return _items[i];
		}
		CItem* foundItem = _items[i]->FindByName(name);
		if (foundItem != nullptr) {
			return foundItem;
		}
	}
	return nullptr;
}

void CFolder::Add(CItem* item) {
	_items.push_back(item);
}

void CFolder::SetHidden(bool isHidden, bool isApplyToChildren) {
	_isHidden = isHidden;
	if (isApplyToChildren) {
		for (int i = 0; i < _items.size(); i++) {
			_items[i]->SetHidden(isHidden, true);
		}
	}
}

double CFolder::GetSize() {
	double totalSize = 0;
	for (int i = 0; i < _items.size(); i++) {
		totalSize += _items[i]->GetSize();
	}
	return totalSize;
}