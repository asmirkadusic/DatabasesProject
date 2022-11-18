#include <memory>
#include <rethinkdb.h>
#include <iostream>
#include <string>

namespace R = RethinkDB;

int main(){
	std::unique_ptr<R::Connection> conn = R::connect("localhost", 28015);
	std::string name{"firstTable"};
	R::Cursor cursor = R::db('test').table_create(name).run(*conn);
	if (conn) {
		std::cout << "Connection exsists" << std::endl;
	}	
}
