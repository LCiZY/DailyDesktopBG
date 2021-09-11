#include<iostream>
#include<windows.h>
#include<vector>
#include<string>
#include<io.h>
#include<time.h>
#include<iostream>

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )   // 隐藏控制台界面

/*得到文件夹内的文件*/
void getFiles(std::string path, std::vector<std::string>& files)
{
	//文件句柄  
	long   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				files.push_back(fileinfo.name);
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

std::string replaceAndCheckSpalshes(std::string path) {
	int length = path.size();
	if (path.back() != '/' && path.back() != '\\') {
		length++;
	}
	char* p = new char[length + 1];
	for (int i = 0; i < path.size(); i++) {
		char c = path.at(i);
		if (c == '\\') {
			p[i] = '/';
		}
		else {
			p[i] = c;
		}
	}
	if(length > path.size())
		p[path.size()] = '/';
	p[length] = '\0';
	return std::string(p);
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return -1;
	}

	std::vector<std::string> bgs;

	getFiles(argv[1], bgs);
	//std::cout << "dir:" << argv[1] << "\n";

	//for (int i = 0; i < bgs.size(); i++){
	//	std::cout << "img." << i << ":" << bgs[i] << "\n";
	//}
	if (bgs.size() == 0){
		return -2;
	}
	int index = (time(0) / 86400) % bgs.size();
	std::string strPath = replaceAndCheckSpalshes(std::string(argv[1]));
	const char* path = strPath.append(bgs[index]).c_str();
	//std::cout << "choose:" << path << "\n";

	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (PVOID)path, SPIF_SENDCHANGE); 
	return 0;
}