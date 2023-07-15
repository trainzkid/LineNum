#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <format>
#include <sstream>

namespace LineNum {
	void linenum(std::istream &in,std::ostream &out) {
		std::string line;
		signed short int lineCount=1;
		signed short int NROFF_LINE_LIMIT = 66;

		while(std::getline(in,line)) {
			out<<std::format("{:2}:",lineCount++)<<line<<std::endl;
			if(lineCount>NROFF_LINE_LIMIT)
				lineCount-=NROFF_LINE_LIMIT;
		}
	}
}

int main(int arg_count,char* arg_array[]) {
	const std::vector<std::string> args(arg_array,arg_array+arg_count);

	if(args.size()<=1)
		LineNum::linenum(std::cin,std::cout);
	else {
		for(std::vector<std::string>::const_iterator i=args.begin()+1;i!=args.end();++i) {
			const std::string arg = *i;
			std::fstream file(arg,std::ios::in);

			if(!file.is_open())
				std::cerr<<"Failed to open "<<arg<<std::endl;
			else
				LineNum::linenum(file,std::cout);

		}
	}

	return 0;
}