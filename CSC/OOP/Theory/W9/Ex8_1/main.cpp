#include "lib.h"

int main() {
	FS fs;
	Disk* disk1 = new Disk("Disk1", 10000);
	Folder* folder1 = new Folder("Folder1");
	File* file1 = new File("File1.txt", 2000, "text");
	File* file2 = new File("File2.bin", 3000, "binary");
	Shortcut* shortcut1 = new Shortcut("Shortcut1", file1);

	Disk* disk2 = new Disk("Disk2", 6000, 1000);
	Folder* folder2 = new Folder("Folder2");
	File* file3 = new File("File3.txt", 1499.5, "text");
	File* file4 = new File("File4.bin", 2499.2, "binary");
	Shortcut* shortcut2 = new Shortcut("Shortcut2", folder1);
	Folder* folder3 = new Folder("Folder3");

	folder1->addComponent(file1);
	folder1->addComponent(file2);
	folder1->addComponent(shortcut1);
	disk1->addComponent(folder1);

	folder2->addComponent(file3);
	folder2->addComponent(file4);
	folder3->addComponent(shortcut2);
	folder2->addComponent(folder3);
	disk2->addComponent(folder2);

	fs.addDisk(disk1);
	fs.addDisk(disk2);

	fs.showDisks();

	return 0;
}